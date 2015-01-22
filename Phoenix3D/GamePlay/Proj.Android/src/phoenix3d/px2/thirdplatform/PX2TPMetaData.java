package phoenix3d.px2.thirdplatform;

import android.content.Context;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.content.pm.PackageManager.NameNotFoundException;
import android.os.Bundle;

public class PX2TPMetaData 
{
	public static boolean IsDebug;
	public static boolean IsTest;
	public static String TPName;
	public static String GameName;
	public static String URL_LibSO;
	public static String URL_Version;
	
	public final static String _ISDEBUG = "isdebug";
	public final static String _ISTEST= "istest";
	public final static String _TPNAME = "tpname";
	public final static String _GAMENAME = "gamename";	
	public final static String _URL_LIBSO = "url_libso";
	public final static String _URL_VERSION = "url_version";
	public final static String _URL_LIBSO_TEST = "url_libso_test";
	public final static String _URL_VERSION_TEST = "url_version_test";
	
	public static void Initlize (Context ctx)
	{	
		IsDebug = (GetMetaData(ctx, _ISDEBUG)=="true");
		IsTest = (GetMetaData(ctx, _ISTEST)=="true");
		TPName = GetMetaData(ctx, _TPNAME);
		GameName = GetMetaData(ctx, _GAMENAME);
		
		if (!IsTest)
		{
			URL_LibSO = GetMetaData(ctx, _URL_LIBSO);
			URL_Version = GetMetaData(ctx, _URL_VERSION);
		}
		else
		{
			URL_LibSO = GetMetaData(ctx, _URL_LIBSO_TEST);
			URL_Version = GetMetaData(ctx, _URL_VERSION_TEST);	
		}
	}
	
	public static String GetMetaData (Context ctx, String key)
	{
		ApplicationInfo ai;
		try 
		{
			ai = ctx.getPackageManager().getApplicationInfo(ctx.getPackageName(), 
					PackageManager.GET_META_DATA);

			Bundle bundle = ai.metaData;
			Object obj = bundle.get(key);
			String source = String.valueOf(obj);

			return source;
		}
		catch (NameNotFoundException e) 
		{
			e.printStackTrace();
		}

		return "";
	}
}
