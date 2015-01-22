package phoenix3d.px2.library;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.URI;
import java.util.Timer;
import java.util.TimerTask;

import org.apache.http.HttpEntity;
import org.apache.http.HttpResponse;
import org.apache.http.client.HttpClient;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.util.VersionInfo;

import phoenix3d.px2.gameplay.PX2GamePlayActivity;
import phoenix3d.px2.gameplay.xymz91.*;
import phoenix3d.px2.thirdplatform.PX2TP;
import phoenix3d.px2.thirdplatform.PX2TPMetaData;
import phoenix3d.px2.unity.PX2NetworkManager;
import phoenix3d.px2.unity.PX2TPVersion;
import android.content.Context;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.content.pm.PackageManager.NameNotFoundException;
import android.os.Environment;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.LinearLayout;
import android.widget.ProgressBar;
import android.widget.TextView;

public class PX2UpdateLayout extends LinearLayout 
{
	public View mRootView;
	private LayoutInflater mLayoutInflater;
	protected float mClientVersion = 0.0f;
	PX2Activity mPX2Activity;	
	private TextView mTitle;
	private ProgressBar mProgress;
	protected static final int SHOWCHECKING = 1;
	protected static final int SHOWUPDATING = 2;
	protected static final int PROCESS = 3;
	protected static final int HIDE = 4;	
	
	public PX2UpdateLayout(Context context, int layoutId) 
	{
		super(context);
		
		mPX2Activity = (PX2Activity)context;		
		
		mLayoutInflater = ((LayoutInflater) getContext().getSystemService("layout_inflater"));
		mRootView = mLayoutInflater.inflate(layoutId, this, true);		
		mTitle = (TextView) mRootView.findViewById(R.id.PX2DownloadTitle);
		mProgress = (ProgressBar) mRootView.findViewById(R.id.PX2UpdateProgressBar);
	}
	
	Handler mHandler = new Handler() 
	{
		public void handleMessage(Message msg)
		{
			switch (msg.what) 
			{
			case SHOWCHECKING:
				ShowChecking();
				break;
			case SHOWUPDATING:
				ShowUpdating();
				break;
			case PROCESS:
				Process(msg.arg1);
				break;
			case HIDE:
				Hide();
				break;
			default:
				break;
			}
		};
	};
	
	private void ShowChecking() 
	{
		mPX2Activity.runOnUiThread(new Runnable() {
			public void run() 
			{
				mTitle.setVisibility(View.VISIBLE);
				mTitle.setText("检测版本...");
				invalidate();
			}
		});

	}

	private void ShowUpdating() 
	{
		mPX2Activity.runOnUiThread(new Runnable()
		{
			public void run() 
			{				
				mTitle.setVisibility(View.VISIBLE);
				mProgress.setVisibility(View.VISIBLE);
				mTitle.setText("更新核心程序...");
				invalidate();
			}
		});
	}

	private void Hide()
	{
		mPX2Activity.runOnUiThread(new Runnable() 
		{
			public void run() 
			{	
				mTitle.setVisibility(View.GONE);
				mProgress.setVisibility(View.GONE);
				invalidate();
			}
		});
	}

	public void Process(final double process) 
	{
		mPX2Activity.runOnUiThread(new Runnable() 
		{
			public void run() 
			{			
				mProgress.setProgress((int) process);
				mTitle.setText("更新核心程序..." + (int)process + "%");
				invalidate();
			}
		});
	}

	public void CheckVersion () 
	{
		if (!PX2NetworkManager.IsNetConnected(mPX2Activity))
		{
			mPX2Activity.DoNoNetDialog();
		}
		
		Message msg = new Message();
		msg.what = SHOWCHECKING;
		mHandler.dispatchMessage(msg);

		PX2TPVersion version = new PX2TPVersion();
		boolean loadRet = version.LoadUpdateVersionXML();
		
		if (!loadRet)
		{
			mPX2Activity.DoConnectResServerFailedDialog();
		}
		
		if (!version.IsAPKNeedUpdate())
		{ // apk版本一致,判断是否要更新libso
			
			if (version.IsLibSONeedUpdate() || version.IsResNeedUpdate())
			{
				if (!PX2NetworkManager.IsWifiConnected(mPX2Activity))
				{
					mPX2Activity.DoNoWifiDialog();
				}
			}
			
			if (version.IsLibSONeedUpdate()) 
			{				
				TimerTask task = new TimerTask() 
				{				
					public void run() 
					{
						Message msg = new Message();
						msg.what = SHOWUPDATING;
						mHandler.dispatchMessage(msg);
						
						try
						{
							HttpClient client = new DefaultHttpClient();
							HttpGet get = new HttpGet(new URI(PX2TPMetaData.URL_LibSO));
							HttpResponse response;
							try 
							{
								response = client.execute(get);
								HttpEntity entity = response.getEntity();
								long length = entity.getContentLength();
								InputStream is = entity.getContent();
								FileOutputStream fileOutputStream = null;
								if (is != null) 
								{
									File file = new File(mPX2Activity.LibSOFilename);
									if (!file.exists()) 
									{
										new File(mPX2Activity.LibSODir).mkdir();
										
										file.createNewFile();
									}
									
									fileOutputStream = new FileOutputStream(file);
									byte[] b = new byte[4 * 1024];
									int charb = -1;
									int count = 0;
									while ((charb = is.read(b)) != -1) 
									{
										fileOutputStream.write(b, 0, charb);
										count += charb;
										double progress = ((double) count / (double) length) * 100.0;

										msg = new Message();
										msg.what = PROCESS;
										msg.arg1 = (int) progress;
										mHandler.dispatchMessage(msg);
									}
								}
								
								fileOutputStream.flush();
								if (fileOutputStream != null) 
								{
									fileOutputStream.close();
								}
							} 
							catch (Exception e) 
							{
								e.printStackTrace();
							}	
						}
						catch (Exception e)
						{
							e.printStackTrace();
						}

						PX2TPVersion.DownloadFile(PX2TPMetaData.URL_Version, PX2Activity.TheActivity.VersionDir, PX2Activity.TheActivity.VersionFilenameJ, null);
						mPX2Activity.ShowGLView();
					}
				};
				
				Timer timer = new Timer();
				timer.schedule(task, 100);		
			}
			else
			{
				mPX2Activity.ShowGLView();
			}
		}
		else
		{
			// apk版本不一致直接退出
			(PX2GamePlayActivity.TheActivity).DoAPKDialog();
		}
	}
}
