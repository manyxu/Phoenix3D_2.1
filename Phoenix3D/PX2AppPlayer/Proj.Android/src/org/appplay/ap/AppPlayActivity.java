package org.appplay.ap;

import java.util.List;

import org.appplay.ap.util.SystemUiHider;
import org.appplay.lib.AppPlayBaseActivity;

import android.annotation.TargetApi;
import android.app.Activity;
import android.app.ActivityManager;
import android.app.ActivityManager.RunningAppProcessInfo;
import android.content.Context;
import android.os.Build;
import android.os.Bundle;
import android.os.Handler;
import android.os.PowerManager;
import android.os.PowerManager.WakeLock;
import android.util.Log;
import android.view.MotionEvent;
import android.view.View;

public class AppPlayActivity extends AppPlayBaseActivity
{
	// power
	private PowerManager powerManager = null; 
	private WakeLock wakeLock = null;
	
    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
		// super create     	
        super.onCreate(savedInstanceState);       
        
		this.powerManager = (PowerManager)this.getSystemService(Context.POWER_SERVICE);
		this.wakeLock = this.powerManager.newWakeLock(PowerManager.FULL_WAKE_LOCK, "My Lock");
    }
    
    @Override
	protected void onPause() 
    {  
    	Log.d("appplay.ap", "AppPlayActivity::onPause");
		 
	    super.onPause();
	     
	    if (null!=wakeLock)
	    	wakeLock.release(); 
    }

	 @Override
	 protected void onResume() 
	 {	 
		 super.onResume();

		 if (null!=wakeLock)
			 wakeLock.acquire(); 
	 }
    
}
