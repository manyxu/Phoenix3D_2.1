package phoenix3d.px2.unity;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;

import org.apache.http.HttpEntity;
import org.apache.http.HttpResponse;
import org.apache.http.client.HttpClient;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.DefaultHttpClient;
import org.json.JSONObject;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.xml.sax.SAXException;

import android.util.Log;
import phoenix3d.px2.library.PX2Activity;
import phoenix3d.px2.thirdplatform.PX2TPMetaData;
import phoenix3d.px2.unity.PX2NetworkManager.DownloadProcess;

public class PX2TPVersion 
{
	private String mLibVersionCode;
	private String mLibUpdateURL;
	private String mVersionStr;
	private int mMain = 0;
	private int mLib = 0;
	private int mRes = 0;
	private boolean mIsAPKNeedUpdate = false;
	private boolean mIsLibSONeedUpdate = false;
	private boolean mIsResNeedUpdate = false;
	
	public PX2TPVersion ()
	{
		mIsAPKNeedUpdate = false;
		mIsLibSONeedUpdate = false;
		mIsResNeedUpdate = false;
	}
	
	// 1 本地 2更新 3更新零时
	public String LoadVersion (int type)
	{
		String versionStr = "";
		String VER = "Version";
		
		DocumentBuilderFactory docFactory = DocumentBuilderFactory.newInstance();  
		DocumentBuilder docBuilder;		
		Document doc = null;
		InputStream inStream = null;
		try 
		{
			docBuilder = docFactory.newDocumentBuilder();

			if (1 == type) 
			{
				inStream = PX2Activity.TheActivity.getResources().getAssets().open("Data/version.xml");

				doc = docBuilder.parse(inStream);

				// 根
				Element rootEle = doc.getDocumentElement();
				
				// name
				String name = rootEle.getNodeName();
				if (name.equals(VER))
				{					
					// value
					versionStr = rootEle.getAttribute("value");	
				}
			} 
			else
			{	
				String filename = "";
				
				if (2 == type)
					filename = PX2Activity.TheActivity.VersionFilenameJ;
				else if (3 == type)
					filename = PX2Activity.TheActivity.VersionFilenameTempJ;
				
				File file = new File(filename);
				if (file.exists()) 
				{
					doc = docBuilder.parse(file);
					
					// 根
					Element rootEle = doc.getDocumentElement();

					// name
					String name = rootEle.getNodeName();
					if (name.equals(VER))
					{
						// value
						versionStr = rootEle.getAttribute("value");	
					}
				}
			}
	    }
	    catch (ParserConfigurationException e1) 
	    {  
	    	e1.printStackTrace();  
	    }
	    catch (IOException e) 
	    {  
	    	e.printStackTrace();  
	    } 
	    catch (SAXException e)
	    {  
	    	e.printStackTrace();  
	    } 
	    
	    return versionStr;
	}
	
	public boolean LoadUpdateVersionXML ()
	{
		String versionStr;
		
		String localVersionStr = LoadVersion(1);	
		Log.w("phoenix3d.px2", "localVersionStr:" + localVersionStr);
		 
		String updateVersionStr = LoadVersion(2);
		Log.w("phoenix3d.px2", "updateVersionStr:" + localVersionStr);
		
		if (updateVersionStr!=null && updateVersionStr!="")
		{
			versionStr = updateVersionStr;
		}
		else
		{
			versionStr = localVersionStr;
		}
		Log.w("phoenix3d.px2", "versionStr:" + versionStr);		
		String versionArray[] = versionStr.split("\\.");
		int versionAPK = 0;
		int versionLib = 0;
		int versionRes = 0;
		Log.w("phoenix3d.px2", "versionArray arrayLength:" + versionArray.length);		
		if (3 == versionArray.length)
		{
			versionAPK = Integer.parseInt(versionArray[0]);
			versionLib = Integer.parseInt(versionArray[1]);
			versionRes = Integer.parseInt(versionArray[2]);
		}
	    
	    // 下载最新的
		if (DownloadFile(PX2TPMetaData.URL_Version, PX2Activity.TheActivity.VersionDir, PX2Activity.TheActivity.VersionFilenameTempJ, null))
		{
			String updateVersion_TempJStr = LoadVersion(3);
			Log.w("phoenix3d.px2", "updateVersion_TempJStr:" + updateVersion_TempJStr);
			String updateVersionArray[] = updateVersion_TempJStr.split("\\.");
			int updateVersionAPK = 0;
			int updateVersionLib = 0;
			int updateVersionRes = 0;
			Log.w("phoenix3d.px2", "updateVersionArray arrayLength:" + updateVersionArray.length);
			if (3 == updateVersionArray.length)
			{
				updateVersionAPK = Integer.parseInt(updateVersionArray[0]);
				updateVersionLib = Integer.parseInt(updateVersionArray[1]);
				updateVersionRes = Integer.parseInt(updateVersionArray[2]);
			}
			
			if (updateVersionAPK > versionAPK)
			{
				mIsAPKNeedUpdate = true;
			}
			else
			{
				mIsAPKNeedUpdate = false;
			}
			Log.w("phoenix3d.px2", "IsAPKNeedUpdate:" + mIsAPKNeedUpdate);			
			
			if (updateVersionLib > versionLib)
			{
				mIsLibSONeedUpdate = true;
			}
			else
			{
				mIsLibSONeedUpdate = false;
			}
			Log.w("phoenix3d.px2", "ISLibSONeedUpdate:" + mIsLibSONeedUpdate);

			if (updateVersionRes > versionRes)
			{
				mIsResNeedUpdate = true;
			}
			else
			{
				mIsResNeedUpdate = false;
			}
			Log.w("phoenix3d.px2", "IsResNeedUpdate:" + mIsResNeedUpdate);
			
			return true;
		}		
		
		return false;
	}

	public boolean IsAPKNeedUpdate ()
	{
		return mIsAPKNeedUpdate;
	}
	
	public boolean IsLibSONeedUpdate ()
	{
		return mIsLibSONeedUpdate;
	}	
	
	public boolean IsResNeedUpdate ()
	{
		return mIsResNeedUpdate;
	}
	
	static public boolean DownloadFile (final String url, String dir, String filename, DownloadProcess callback)
	{
		boolean bRet = false;
		HttpClient client = new DefaultHttpClient();
		HttpGet get = new HttpGet(url);
		HttpResponse response;
		try 
		{
			response = client.execute(get);
			HttpEntity entity = response.getEntity();
			long length = entity.getContentLength();
			InputStream in = entity.getContent();
			FileOutputStream fileOutputStream = null;
			if (in != null) 
			{
				File file = new File(filename);

				if (!file.exists()) 
				{
					new File(dir).mkdir();
					file.createNewFile();
				}
				fileOutputStream = new FileOutputStream(file);
				byte[] b = new byte[4 * 1024];
				int charb = -1;
				int count = 0;
				while ((charb = in.read(b)) != -1) 
				{
					fileOutputStream.write(b, 0, charb);
					count += charb;
					double progress = ((double) count / (double) length) * 100;
					
					if (null != callback)
						callback.process(progress);
				}
			}
			
			fileOutputStream.flush();
			if (fileOutputStream != null)
			{
				fileOutputStream.close();
			}
			
			bRet = true;
		} 
		catch (Exception e)
		{
			e.printStackTrace();
		}
		
		return bRet;
	}
}
