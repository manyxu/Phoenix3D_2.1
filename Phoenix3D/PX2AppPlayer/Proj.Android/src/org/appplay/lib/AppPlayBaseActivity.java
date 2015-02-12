package org.appplay.lib;

import java.io.File;
import java.util.List;

import org.appplay.ap.R;
import org.appplay.platformsdk.PlatformSDKNatives;
import org.appplay.platformsdk.PlatformSDK;
import org.appplay.platformsdk.PlatformSDKCreater;

import android.app.Activity;
import android.app.ActivityManager;
import android.app.AlertDialog;
import android.app.Dialog;
import android.app.ActivityManager.RunningAppProcessInfo;
import android.content.Context;
import android.content.DialogInterface;
import android.content.pm.ApplicationInfo;
import android.content.pm.ConfigurationInfo;
import android.content.pm.PackageManager;
import android.content.pm.PackageManager.NameNotFoundException;
import android.os.Bundle;
import android.util.Log;
import android.view.KeyEvent;
import android.view.View;
import android.view.ViewGroup;
import android.widget.FrameLayout;

public class AppPlayBaseActivity extends Activity
{
	// Activtiy
	public static AppPlayBaseActivity sTheActivity;

	// LibSO
	public static String sLibSO_Filename = "";
	public static String sLibSO_Dir = "";
	private static String sLibSO_Name="libAppPlayJNI";

	// Vsersion
	public static String sVersion_Dir = "";
	public static String sVersion_Filename = "";
	public static String sVersion_Filename_Temp = "";

	// Siews
	public AppPlayUpdateLayout mUpdateView = null;
	public AppPlayGLView TheGLView = null;

	private static String msPackageName; // use static to support export
	private boolean mIsAppForeground = true;

	@Override
	protected void onCreate(Bundle savedInstanceState)
	{
		sTheActivity = this;

		super.onCreate(savedInstanceState);

		String packageName = getApplication().getPackageName();
		PackageManager packMgr = getApplication().getPackageManager();
		ApplicationInfo info = null;
		try
		{
			info = packMgr
					.getApplicationInfo(packageName, MODE_WORLD_WRITEABLE);
		} catch (NameNotFoundException e)
		{
			e.printStackTrace();
		}

		sLibSO_Dir = info.dataDir;
		sLibSO_Filename = info.dataDir + "/" + sLibSO_Name + ".so";
		sVersion_Dir = info.dataDir;

		sVersion_Filename = info.dataDir + "/version.xml";
		sVersion_Filename_Temp = info.dataDir + "/version_Temp.xml";
		
        Log.d("appplay.ap", "begin - AppPlayActivity::onCreate"); 
        
        AppPlayMetaData.Initlize(getApplicationContext());
		
		if (AppPlayMetaData.sIsNettable)
			PlatformSDK.sThePlatformSDK = PlatformSDKCreater.Create(this);
		else
			Show_GLView();
		
		 Log.d("appplay.ap", "end - AppPlayActivity::onCreate"); 
	}

	@Override
	protected void onStop()
	{
		super.onStop();

		if (!_IsAppOnForeground())
		{
			mIsAppForeground = false;
		}
	}

	@Override
	protected void onPause()
	{
		Log.d("appplay.lib", "AppPlayBaseActivity::onPause");

		super.onPause();

		if (null != TheGLView)
			TheGLView.onPause();
	}

	@Override
	protected void onResume()
	{
		super.onResume();

		if (!mIsAppForeground)
		{
			if (null != PlatformSDK.sThePlatformSDK)
				PlatformSDK.sThePlatformSDK.OnResume();

			mIsAppForeground = true;
		}

		if (null != TheGLView)
			TheGLView.onResume();
	}

	@Override
	public void onDestroy()
	{
		super.onDestroy();

		if (null != TheGLView)
			TheGLView.Destory();

		if (null != PlatformSDK.sThePlatformSDK)
			PlatformSDK.sThePlatformSDK.Term();

	}

	@Override
	public boolean onKeyDown(int keyCode, KeyEvent event)
	{
		if (keyCode == KeyEvent.KEYCODE_BACK)
		{
			if (null != PlatformSDK.sThePlatformSDK)
			{
				PlatformSDK.sThePlatformSDK.OnExist();

				return true;
			}
		}

		return super.onKeyDown(keyCode, event);
	}

	// -- internal functions implemented ourself --

	private boolean _IsOpenGLES20Valied()
	{
		ActivityManager am = (ActivityManager) getSystemService(Context.ACTIVITY_SERVICE);
		ConfigurationInfo info = am.getDeviceConfigurationInfo();

		return (info.reqGlEsVersion >= 0x20000);
	}

	private void _SetPackageName(String packageName)
	{
		msPackageName = packageName;
		Log.d("appplay.ap", "PackageName:" + msPackageName);

		String apkFilePath = "";
		ApplicationInfo appInfo = null;
		PackageManager packMgmr = getApplication().getPackageManager();
		try
		{
			appInfo = packMgmr.getApplicationInfo(packageName, 0);
		} catch (NameNotFoundException e)
		{
			e.printStackTrace();
			throw new RuntimeException("Unable to locate assets, aborting...");
		}
		apkFilePath = appInfo.sourceDir;
		Log.d("appplay.ap", "ResourcePath:" + apkFilePath);

		// set apkPath
		AppPlayNatives.nativeSetResourcePath(apkFilePath);

		// set
		if (AppPlayMetaData.sIsTest)
		{
			AppPlayNatives.nativeSetDataUpdateServerType("ResourceServerTest");
		}
	}

	private boolean _IsAppOnForeground()
	{
		ActivityManager activityManager = (ActivityManager) getApplicationContext()
				.getSystemService(Context.ACTIVITY_SERVICE);
		String packageName = getApplicationContext().getPackageName();
		List<RunningAppProcessInfo> appProcesses = activityManager
				.getRunningAppProcesses();
		if (appProcesses == null)
			return false;
		for (RunningAppProcessInfo appProcess : appProcesses)
		{
			if (appProcess.processName.equals(packageName)
					&& appProcess.importance == RunningAppProcessInfo.IMPORTANCE_FOREGROUND)
			{
				return true;
			}
		}
		return false;
	}

	// -- gen functions can be called implemented ourself --

	// show a updateview to load LibSO from server
	public void Show_UpdateView()
	{
		runOnUiThread(new Runnable()
		{
			public void run()
			{
				mUpdateView = new AppPlayUpdateLayout(
						AppPlayBaseActivity.sTheActivity,
						R.layout.appplayupdateview);

				setContentView(mUpdateView);

				mUpdateView.CheckVersion();
			}
		});
	}

	// updated ok, let's show our opengles view
	public void Show_GLView()
	{
		runOnUiThread(new Runnable()
		{
			public void run()
			{
				File file = new File(sLibSO_Filename);
				if (file.exists())
				{ // a updated so, load it from a update dir

					Log.d("appplay.ap", "begin - load sLibSO(from dir).");

					System.load(sLibSO_Filename);

					Log.d("appplay.lib", "end - load sLibSO(form dir).");
				} else
				{ // load so packaged with the first apk

					Log.d("appplay.lib", "begin - load so(form init packaged).");

					try
					{
						System.loadLibrary(sLibSO_Name);
					}
					catch (UnsatisfiedLinkError ulink)
					{
					}

					Log.d("appplay.lib", "end - load so(form init packaged).");
				}

				Log.d("appplay.lib", "ok - load so.");

				// package name
				String packageName = getApplication().getPackageName();
				_SetPackageName(packageName);

				// set platformsdk
				PlatformSDKNatives
						.SetPlatformSDK(PlatformSDKCreater.sSDK_CurrentName);

				// -- begin FrameLayout --

				ViewGroup.LayoutParams framelayout_params = new ViewGroup.LayoutParams(
						ViewGroup.LayoutParams.FILL_PARENT,
						ViewGroup.LayoutParams.FILL_PARENT);

				FrameLayout framelayout = new FrameLayout(
						AppPlayBaseActivity.sTheActivity);
				framelayout.setLayoutParams(framelayout_params);

				// PX2EditText layout
				ViewGroup.LayoutParams edittext_layout_params = new ViewGroup.LayoutParams(
						ViewGroup.LayoutParams.FILL_PARENT,
						ViewGroup.LayoutParams.WRAP_CONTENT);
				AppPlayEditText edittext = new AppPlayEditText(
						AppPlayBaseActivity.sTheActivity);
				edittext.setLayoutParams(edittext_layout_params);

				// ...add to FrameLayout
				framelayout.addView(edittext);

				// view
				if (_IsOpenGLES20Valied())
				{
					TheGLView = new AppPlayGLView(
							AppPlayBaseActivity.sTheActivity);
				} else
				{
					Log.d("appplay.lib", "info - Don't support gles2.0");
					finish();
				}

				framelayout.addView(TheGLView);

				TheGLView.SetEditText(edittext);

				// Set framelayout as the content view
				setContentView(framelayout);

				// -- end FrameLayout --

				// hide soupdateview
				if (null != mUpdateView)
					mUpdateView.setVisibility(View.GONE);
			}
		});
	}

	public void Show_NoNetDlg()
	{
		Dialog alertDialog = new AlertDialog.Builder(this).setTitle("注意")
				.setMessage("您的网络已经断开，请连接！")
				.setPositiveButton("确定", new DialogInterface.OnClickListener()
				{
					public void onClick(DialogInterface dialog, int which)
					{
						dialog.dismiss();
					}
				}).create();
		alertDialog.show();
	}

	public void Show_NoWifiDialog()
	{
		Dialog alertDialog = new AlertDialog.Builder(this).setTitle("注意")
				.setMessage("游戏需要更新，您处在非wifi网络环境下，确定进行更新？")
				.setIcon(R.drawable.ic_launcher)
				.setPositiveButton("确定", new DialogInterface.OnClickListener()
				{
					public void onClick(DialogInterface dialog, int which)
					{
						dialog.dismiss();
					}
				})
				.setNegativeButton("取消", new DialogInterface.OnClickListener()
				{
					public void onClick(DialogInterface dialog, int which)
					{
						dialog.dismiss();
						((AppPlayBaseActivity) sTheActivity).MyExit();
					}
				}).create();
		alertDialog.show();
	}

	public void Show_ConnectResServerFailedDlg()
	{
		Dialog alertDialog = new AlertDialog.Builder(this).setTitle("注意")
				.setMessage("连接服务器失败！")
				.setPositiveButton("确定", new DialogInterface.OnClickListener()
				{
					public void onClick(DialogInterface dialog, int which)
					{
						dialog.dismiss();
					}
				}).create();
		alertDialog.show();
	}

	public void Show_HasNewAPKDlg()
	{
		Dialog alertDialog = new AlertDialog.Builder(this).setTitle("注意")
				.setMessage("安装包已有新版本,请下载安装.")
				.setPositiveButton("确定", new DialogInterface.OnClickListener()
				{
					public void onClick(DialogInterface dialog, int which)
					{
						dialog.dismiss();
						((AppPlayBaseActivity) sTheActivity).MyExit();
					}
				}).create();
		alertDialog.show();
	}

	public void MyExit()
	{
		runOnUiThread(new Runnable()
		{
			public void run()
			{
				android.os.Process.killProcess(android.os.Process.myPid());
			}
		});

	}
	
	public static String GetPackageName ()
	{
		 return msPackageName;
	}

	// platform sdk functions

	public static void ThirdPlatformLogin()
	{
		((AppPlayBaseActivity) (sTheActivity))._ThirdPlatformLogin1();
	}

	public void _ThirdPlatformLogin1()
	{
		this.runOnUiThread(new Runnable()
		{
			public void run()
			{
				if (null != PlatformSDK.sThePlatformSDK)
					PlatformSDK.sThePlatformSDK.Login();
			}
		});
	}

	public static void ThirdPlatformLogout()
	{
		((AppPlayBaseActivity) (sTheActivity))._Show_LogoutExitDlg();
	}

	public void _Show_LogoutExitDlg()
	{
		this.runOnUiThread(new Runnable()
		{
			public void run()
			{
				if (null != PlatformSDK.sThePlatformSDK)
					PlatformSDK.sThePlatformSDK.OnLogoutExist();
			}
		});
	}

	public static void SynPay(final String productID, final String productName,
			final float productPrice, final float productOrginalPrice,
			final int count, final String payDescription)
	{
		((AppPlayBaseActivity) (sTheActivity))._SynPay(productID, productName,
				productPrice, productOrginalPrice, count, payDescription);
	}

	public void _SynPay(final String productID, final String productName,
			final float productPrice, final float productOrginalPrice,
			final int count, final String payDescription)
	{
		this.runOnUiThread(new Runnable()
		{
			public void run()
			{
				if (null != PlatformSDK.sThePlatformSDK)
					PlatformSDK.sThePlatformSDK.SynPay(productID, productName,
							productPrice, productOrginalPrice, count,
							payDescription);
			}
		});
	}

	public static void ASynPay(final String productID,
			final String productName, final float productPrice,
			final float productOrginalPrice, final int count,
			final String payDescription)
	{
		((AppPlayBaseActivity) (sTheActivity))._ASynPay(productID, productName,
				productPrice, productOrginalPrice, count, payDescription);
	}

	public void _ASynPay(final String productID, final String productName,
			final float productPrice, final float productOrginalPrice,
			final int count, final String payDescription)
	{
		this.runOnUiThread(new Runnable()
		{
			public void run()
			{
				if (null != PlatformSDK.sThePlatformSDK)
					PlatformSDK.sThePlatformSDK.ASynPay(productID, productName,
							productPrice, productOrginalPrice, count,
							payDescription);
			}
		});
	}

}
