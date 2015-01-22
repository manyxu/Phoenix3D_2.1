package phoenix3d.px2.thirdplatform;

import android.app.Activity;
import phoenix3d.px2.thirdplatform.*;
import phoenix3d.px2.thirdplatform.p91.*;

public class PX2TPFactory 
{
	public static String TP_NAME_UNKNOWN = "unknown";
	public static String TP_NAME_91 = "91";
	public static String TP_NAME_360 = "360";
	public static String Current_tp_name = "";
	
	public static PX2TP Factory (Activity activity)
	{
		Current_tp_name = PX2TPMetaData.TPName;
		
		return Factory(activity, Current_tp_name);
	}
	
	public static PX2TP Factory (Activity activity, String source)
	{
		if (TP_NAME_91.equals(source)) 
		{
			return new PX2TP_91(activity);
		}
		else if (TP_NAME_360.equals(source)) 
		{
			return null;
		}
		else 
		{
			return null;
		}
	}	
}
