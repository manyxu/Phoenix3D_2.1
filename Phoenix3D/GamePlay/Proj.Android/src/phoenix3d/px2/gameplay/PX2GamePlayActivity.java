package phoenix3d.px2.gameplay;

// px2
import com.umeng.analytics.MobclickAgent;

import phoenix3d.px2.library.PX2Activity;
import phoenix3d.px2.library.PX2EditText;
import phoenix3d.px2.library.PX2GLView;
// px2 third platform
import phoenix3d.px2.thirdplatform.*;
import android.app.ActivityManager;
import android.app.Dialog;
import android.app.ProgressDialog;
import android.content.Context;
// android
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.pm.ActivityInfo;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.content.pm.PackageManager.NameNotFoundException;
import android.os.Bundle;
import android.os.PowerManager;
import android.os.PowerManager.WakeLock;
import android.util.Log;
import android.view.KeyEvent;
import android.view.View;
import android.view.ViewGroup;
import android.view.Window;
import android.view.WindowManager;
import android.widget.EditText;
import android.widget.FrameLayout;
import android.app.AlertDialog;
import android.app.AlertDialog.Builder;
import android.content.DialogInterface;

public class PX2GamePlayActivity extends PX2Activity
{	
	public FrameLayout TheFramelayout;
	public String StaticLibPath = "";
	public String StaticLibDir = "";
	public FrameLayout framelayout;
	private boolean mIsAppForeground = true;
	private PowerManager powerManager = null; 
	private WakeLock wakeLock = null;
	
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) 
    {    	
		// super create     	
        super.onCreate(savedInstanceState);       
        
		 this.powerManager = (PowerManager)this.getSystemService(Context.POWER_SERVICE);
		 this.wakeLock = this.powerManager.newWakeLock(PowerManager.FULL_WAKE_LOCK, "My Lock");
        
        Log.w("phoenix3d.px2", "PX2GamePlayActivity::onCreate");        
        
        _ThridPlatformInit();
    }
    
	 
	private void _ThridPlatformInit ()
	{
		Log.w("phoenix3d.px2", "ThridPlatformInit");  
		
		// PX2 third platform
		PX2TPMetaData.Initlize(getApplicationContext());
		PX2TP.Instance = PX2TPFactory.Factory(this);  		 
	} 
    
    @Override
    protected void onStop ()
    {
    	super.onStop();
    	
    	if (!IsAppOnForeground()) // 杩涘叆鍚庡彴
    	{
    		mIsAppForeground = false;
    	}
    }
    
    @Override
	protected void onPause() 
    {  
    	Log.d("phoenix3d.px2", "PX2GamePlayActivity::onPause");
		 
	    super.onPause();
	    
	    // umeng
	   // MobclickAgent.onPause(this);
	    
	    if (null!=mGLView)
	    	 mGLView.onPause();
	     
	    if (null!=wakeLock)
	    	wakeLock.release(); 
    }

	 @Override
	 protected void onResume() 
	 {	 
		 super.onResume();

		 if (!mIsAppForeground) // 浠庡悗鍙板垏鎹㈠埌鍓嶅彴
		 {
			 PX2TP.Instance.OnResume(); // 鏆傚仠椤甸潰
			 
			 mIsAppForeground = true;
		 }
		 
		 // umeng
		// MobclickAgent.onResume(this);
		 
		 if (null!=mGLView)
			 mGLView.onResume();
		 
		 if (null!=wakeLock)
			 wakeLock.acquire(); 
	 }
	 
	 @Override
	 public void onDestroy() 
	 {
	     super.onDestroy();
	    
	     if (null!=mGLView)
	    	 mGLView.OnDestory(); 
	     
	     PX2TP.Instance.Term();
	    
	 }	 
	 
	@Override
	public boolean onKeyDown (int keyCode, KeyEvent event)
	{
		if (keyCode == KeyEvent.KEYCODE_BACK)
		{
			PX2TP.Instance.OnExist();
			
			return true;
		}
		
		return super.onKeyDown(keyCode, event);
	}
		
	// PX2 third platform
	
	public static void ThirdPlatformLogin ()
	{
		((PX2GamePlayActivity)(TheActivity))._ThirdPlatformLogin1();
	}
	
	public void _ThirdPlatformLogin1 ()
	{
		 this.runOnUiThread(new Runnable()
		 {
			 public void run ()
			 {
				 PX2TP.Instance.Login();
			 }
		 });
	}
	
	public static void ThirdPlatformLogout ()
	{
		((PX2GamePlayActivity)(TheActivity)).DoLogoutExitDlg();
	}	
	
	public static void SynPay (
			 final String productID,
			 final String productName,
			 final float productPrice,
			 final float productOrginalPrice,
			 final int count,
			 final String payDescription)
	{	
		((PX2GamePlayActivity)(TheActivity))._SynPay( 
				productID, productName, 
				productPrice, productOrginalPrice, count, payDescription);
	}
	 
	 public void _SynPay (
			 final String productID,
			 final String productName,
			 final float productPrice,
			 final float productOrginalPrice,
			 final int count,
			 final String payDescription)
	 {	 
		 this.runOnUiThread(new Runnable()
		 {
			 public void run ()
			 {
				 PX2TP.Instance.SynPay(productID, productName,
						 productPrice, productOrginalPrice, count, payDescription);
			}
		});
	}

	public static void ASynPay(final String productID,
			final String productName, final float productPrice,
			final float productOrginalPrice, final int count,
			final String payDescription) 
	{
		((PX2GamePlayActivity) (TheActivity))._ASynPay(productID,
				productName, productPrice, productOrginalPrice, count,
				payDescription);
	}

	public void _ASynPay(final String productID,
			final String productName, final float productPrice,
			final float productOrginalPrice, final int count,
			final String payDescription)
	{	
		this.runOnUiThread(new Runnable()
		{
			public void run() 
			{
				PX2TP.Instance.ASynPay(productID, productName, productPrice,
						productOrginalPrice, count, payDescription);
			}
		}); 
	}
	
	
	public void DoLogoutExitDlg ()
	{//  
		this.runOnUiThread(new Runnable()
		{
			public void run() 
			{
				PX2TP.Instance.OnLogoutExist();
				
				/*Dialog alertDialog = new AlertDialog.Builder(TheActivity). 
		                setTitle("娉ㄦ剰"). 
		                setMessage("鏄惁纭畾娉ㄩ攢甯愬彿锛岄�鍑烘父鎴忥紵"). 
		        		setPositiveButton("纭畾", new DialogInterface.OnClickListener()
		        		{
		        			public void onClick(DialogInterface dialog, int which)
		        			{
		        				PX2TP.Instance.Logout();
		        				
		        				((PX2GamePlayActivity)TheActivity).MyExit();
		        			}
		        		}).
		        		setNegativeButton("鍙栨秷", new DialogInterface.OnClickListener()
		        		{
		        			public void onClick(DialogInterface dialog, int which)
		        			{
		        				dialog.dismiss();
		        			}
		        		}).
		                create(); 
		        alertDialog.show(); */
			}
		});
	}	    
}