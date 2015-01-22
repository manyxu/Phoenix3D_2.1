package phoenix3d.px2.thirdplatform;

import phoenix3d.px2.gameplay.PX2GamePlayActivity;
import phoenix3d.px2.thirdplatform.*;
import android.util.Log;

public class PX2TPNatives 
{
	public static PX2GamePlayActivity sMainActivity;
	
	public static void ThirdPlatformLogin ()
	{
		sMainActivity.ThirdPlatformLogin();
	}
	
	public static String GetPayPlatform ()
	{
		return PX2TP.Instance.PaySource;
	}
	
	public static String GetPlatformSource ()
	{
		return PX2TP.Instance.Source;
	}
	
	public static String GetHostName ()
	{
		return PX2TP.Instance.PayHostName;
	}
	
	public static native void SetPX2ThirdPlatform (String thirdName);
	public static native void OnLoginSuc (int apiID, String loginUin, String sessionID, String nickname);	
	public static native void OnLoginCancel ();	
	public static native void OnLoginFailed ();
	public static native void OnGuestOfficialSuc ();
	
	public static native void OnPaySuc (String serial, boolean isSyn);
	public static native void OnPayCancel (String serial, boolean isSyn);
	public static native void OnPayFailed (String serial, boolean isSyn);
	public static native void OnPaySMSSent (String serial, boolean isSyn);
	public static native void OnPayRequestSubmitted (String serial, boolean isSyn);
	public static native void OnPayError (String serial, int error, boolean isSyn);
	
}
