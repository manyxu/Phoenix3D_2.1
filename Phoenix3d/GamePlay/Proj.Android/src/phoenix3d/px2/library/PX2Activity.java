package phoenix3d.px2.library;

import java.io.File;
import java.util.List;

import android.app.Activity;
import android.app.ActivityManager;
import android.app.AlertDialog;
import android.app.Dialog;
import android.app.ActivityManager.RunningAppProcessInfo;
import android.app.AlertDialog.Builder;
import android.content.Context;
import android.content.DialogInterface;
import android.content.SharedPreferences;
import android.content.pm.ApplicationInfo;
import android.content.pm.ConfigurationInfo;
import android.content.pm.PackageManager;
import android.content.pm.PackageManager.NameNotFoundException;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.os.PowerManager;
import android.os.PowerManager.WakeLock;
import android.util.Log;
import android.view.View;
import android.view.ViewGroup;
import android.view.Window;
import android.view.WindowManager;
import android.widget.FrameLayout;
import android.content.pm.ActivityInfo;
import android.content.res.AssetFileDescriptor;
import android.content.res.Configuration;
import phoenix3d.px2.library.PX2GLView;
import phoenix3d.px2.gameplay.PX2GamePlayActivity;
import phoenix3d.px2.gameplay.xymz91.*;
import phoenix3d.px2.library.PX2Natives;
import phoenix3d.px2.library.PX2SoundSystem;
import phoenix3d.px2.library.PX2EditText;
import phoenix3d.px2.thirdplatform.PX2TP;
import phoenix3d.px2.thirdplatform.PX2TPFactory;
import phoenix3d.px2.thirdplatform.PX2TPMetaData;
import phoenix3d.px2.thirdplatform.PX2TPNatives;
import phoenix3d.px2.unity.PX2TPVersion;

public class PX2Activity extends Activity
{	
	 static public PX2Activity TheActivity;
	 public PX2GLView mGLView = null;
	 public PX2UpdateLayout mLibSOUpdateView = null;
	 private static String mPackageName;
	 private static PX2SoundSystem mSoundSystem;
	 public static String LibSOFilename = "";
	 public static String LibSODir = "";
	 public static String VersionFilenameJ = "";	 
	 public static String VersionFilenameTempJ = "";	
	 public static String VersionDir = "";
	
	 protected void onCreate(Bundle savedInstanceState) 
	 {
		 TheActivity = this;		
		 
		 super.onCreate(savedInstanceState);
		 
		 mSoundSystem = new PX2SoundSystem(this);
		 
		 // set so paths
		 String packageName = getApplication().getPackageName();
		 PackageManager packMgr = getApplication().getPackageManager();
		 ApplicationInfo info = null;
		 try
		 {
			 info = packMgr.getApplicationInfo(packageName, MODE_WORLD_WRITEABLE);
		 }
		 catch (NameNotFoundException e)
		 {
			 e.printStackTrace();
		 }

		LibSODir = info.dataDir;
		LibSOFilename = info.dataDir + "/libPX2GamePlayJNI.so";
		VersionDir = info.dataDir;
		VersionFilenameJ = info.dataDir + "/version_j.xml";
		VersionFilenameTempJ = info.dataDir + "/version_Temp_j.xml";        
	 } 	    

	 public void ShowGLView ()
	 { 	 
		 runOnUiThread(new Runnable()
		 {
			 public void run()
			 {				 
				 // load libs
				 File file = new File(LibSOFilename);
				 if (file.exists()) 
				 {
					 Log.d("phoenix3d.px2", "PX2Activity::System.load so");
					 
					 System.load(LibSOFilename);
				 }
				 else 
				 {
					 Log.d("phoenix3d.px2", "PX2Activity:: System.loadLibrary");
					 
					 try 
					 {
						 System.loadLibrary("PX2GamePlayJNI");
					 }
					 catch (UnsatisfiedLinkError ulink)
					 {   
						//Log.i("HVnative====","Can not load library");
						//ulink.printStackTrace();  
					 }  
				 }
				 
				 Log.d("phoenix3d.px2", "PX2Activity:: System.loadLibrary Suc!");
				 
				 // package name
				 String packageName = getApplication().getPackageName();
				 SetPX2PackageName(packageName);	
				 
				 // 设置平台为
				 PX2TPNatives.SetPX2ThirdPlatform(PX2TPFactory.Current_tp_name);
				 
				 // FrameLayout
				 ViewGroup.LayoutParams framelayout_params = new ViewGroup.LayoutParams(ViewGroup.LayoutParams.FILL_PARENT, ViewGroup.LayoutParams.FILL_PARENT);		
				 FrameLayout framelayout = new FrameLayout(PX2Activity.TheActivity);		
				 framelayout.setLayoutParams(framelayout_params);
					
				 // PX2EditText layout
				 ViewGroup.LayoutParams edittext_layout_params = new ViewGroup.LayoutParams(ViewGroup.LayoutParams.FILL_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT);
				 PX2EditText edittext = new PX2EditText(PX2Activity.TheActivity);
				 edittext.setLayoutParams(edittext_layout_params);

				 // ...add to FrameLayout
				 framelayout.addView(edittext);
				    
				 // view
				 if (DetectOpenGLES20())
				 {
					 mGLView = new PX2GLView(PX2Activity.TheActivity);
				 }
				 else 
				 {
					 Log.d("phoenix3d.px2", "Don't support gles2.0");
					 finish();
				 }  	    
				    
				 framelayout.addView(mGLView);

				 mGLView.SetTextField(edittext);
				 
				 // Set framelayout as the content view
				 setContentView(framelayout);
				 
				 // hide soupdateview
				 mLibSOUpdateView.setVisibility(View.GONE);
			}
		});
	}	 

	public void ShowLibSOUpdateView ()
	{
		runOnUiThread(new Runnable() 
		{
			public void run() 
			{
				mLibSOUpdateView = new PX2UpdateLayout(PX2Activity.TheActivity, R.layout.splash);
				
				setContentView(mLibSOUpdateView);

				mLibSOUpdateView.CheckVersion();
			}
		});
	}
	
	public void DoNoNetDialog() 
	{
		Dialog alertDialog = new AlertDialog.Builder(this). 
                setTitle("注意"). 
                setMessage("您的网络已经断开，请连接！"). 
        		setPositiveButton("确定", new DialogInterface.OnClickListener()
        		{
        			public void onClick(DialogInterface dialog, int which)
        			{
        				dialog.dismiss();
        			}
        		}).
                create(); 
        alertDialog.show(); 
	}
	
	public void DoConnectResServerFailedDialog() 
	{
		Dialog alertDialog = new AlertDialog.Builder(this). 
                setTitle("注意"). 
                setMessage("连接服务器失败！"). 
        		setPositiveButton("确定", new DialogInterface.OnClickListener()
        		{
        			public void onClick(DialogInterface dialog, int which)
        			{
        				dialog.dismiss();
        			}
        		}).
                create(); 
        alertDialog.show(); 
	}
	
	public void DoAPKDialog ()
	{
		Dialog alertDialog = new AlertDialog.Builder(this). 
                setTitle("注意"). 
                setMessage("安装包已有新版本,请下载安装."). 
        		setPositiveButton("确定", new DialogInterface.OnClickListener()
        		{
        			public void onClick(DialogInterface dialog, int which)
        			{
        				dialog.dismiss();
        				((PX2GamePlayActivity)TheActivity).MyExit();
        			}
        		}).
                create(); 
        alertDialog.show(); 
	}
	
	public void DoNoWifiDialog ()
	{
		Dialog alertDialog = new AlertDialog.Builder(this). 
                setTitle("注意"). 
                setMessage("游戏需要更新，您处在3G网络环境下，确定进行更新？"). 
                setIcon(R.drawable.ic_launcher).
                setPositiveButton("确定", new DialogInterface.OnClickListener()
                {
        			public void onClick(DialogInterface dialog, int which)
        			{
        				dialog.dismiss();
        			}
                }).
                setNegativeButton("取消", new DialogInterface.OnClickListener()
        		{
        			public void onClick(DialogInterface dialog, int which)
        			{
        				dialog.dismiss();
        				((PX2GamePlayActivity)TheActivity).MyExit();
        			}
        		}).
                create(); 
        alertDialog.show(); 
	}
	
	public boolean IsAppOnForeground() 
	{
		ActivityManager activityManager = (ActivityManager) getApplicationContext()
				.getSystemService(Context.ACTIVITY_SERVICE);
		String packageName = getApplicationContext().getPackageName();
		List<RunningAppProcessInfo> appProcesses = activityManager.getRunningAppProcesses();
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
	
	public void MyExit ()
	{
		runOnUiThread(new Runnable() 
		{
			public void run() 
			{				
				android.os.Process.killProcess(android.os.Process.myPid());
			}
		});

	}
	 
	public static String GetPX2PackageName ()
	{
		 return mPackageName;
	}
	
	// called in PX2GamePalyActivity
	protected void SetPX2PackageName (String packageName)
	{
		 mPackageName = packageName;
		 Log.w("phoenix3d.px2", "PackageName:" + mPackageName);
		 
		 String apkFilePath = "";
		 
	     ApplicationInfo appInfo = null;
	     PackageManager packMgmr = getApplication().getPackageManager();
	     try
	     {
	    	 appInfo = packMgmr.getApplicationInfo(packageName, 0);
	     }
	     catch (NameNotFoundException e)
	     {
	    	 e.printStackTrace();
	    	 throw new RuntimeException("Unable to locate assets, aborting...");
	     }
	     
	     apkFilePath = appInfo.sourceDir;
	     Log.w("phoenix3d.px2", "ResourcePath:" + apkFilePath);
	     
	     // set apkPath
	     PX2Natives.nativeSetResourcePath(apkFilePath);
	     
	     // set
	     if (PX2TPMetaData.IsTest)
	     {
	    	 PX2Natives.nativeSetDataUpdateServerType("ResourceServerTest");
	     }
	}
	 
	private boolean DetectOpenGLES20() 
	{
		ActivityManager am = (ActivityManager) getSystemService(Context.ACTIVITY_SERVICE);
		ConfigurationInfo info = am.getDeviceConfigurationInfo();
		    
		return (info.reqGlEsVersion >= 0x20000);
	}
	
	// sound
	public static int PlaySound2D (String path, float volume, boolean isLoop)
	{		
		return mSoundSystem.PlaySound2D(path, volume, isLoop);
	}
	
	public static void SetSoundVolume(int soundID, float volume)
	{
		mSoundSystem.SetSoundVolume(soundID, volume);
	}
	
	public static void StopSound (int soundID)
	{
		mSoundSystem.StopSound(soundID);
	}
	
	public static void PauseSound (int soundID)
	{
		mSoundSystem.PauseSound(soundID);
	}
	
	public static void ResumeSound (int soundID)
	{
		mSoundSystem.ResumeSound(soundID);
	}
	
	public static int LoadSound (String path)
	{
		return mSoundSystem.LoadSound(path);
	}
	
	public static void UnloadSound (String path)
	{
		mSoundSystem.UnloadSound(path);
	}
	
	public static void PlayMusic (int channel, String path, float volume, boolean isLoop)
	{
		mSoundSystem.PlayMusic(channel, path, volume, isLoop);
	}
		
	public static void SetMusicVolume (int channel, float volume)
	{
		mSoundSystem.SetMusicVolume(channel, volume);
	}
	
	public static void StopMusic (int channel)
	{
		mSoundSystem.StopMusic(channel);
	}
}
