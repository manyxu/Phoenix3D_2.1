package phoenix3d.px2.thirdplatform.p91;

import java.util.UUID;

import android.app.Activity;
import android.app.ProgressDialog;
import android.content.Intent;
import android.util.Log;
import android.widget.Toast;

import com.nd.commplatform.NdCallbackListener;
import com.nd.commplatform.NdCommplatform;
import com.nd.commplatform.NdErrorCode;
import com.nd.commplatform.NdMiscCallbackListener;
import com.nd.commplatform.OnInitCompleteListener;
import com.nd.commplatform.NdPageCallbackListener.OnExitCompleteListener;
import com.nd.commplatform.NdPageCallbackListener.OnPauseCompleteListener;
import com.nd.commplatform.entry.NdAppInfo;
import com.nd.commplatform.entry.NdBuyInfo;
import com.nd.commplatform.entry.NdLoginStatus;
import com.nd.commplatform.gc.widget.NdToolBar;
import com.nd.commplatform.gc.widget.NdToolBarPlace;

import phoenix3d.px2.library.PX2Activity;
import phoenix3d.px2.thirdplatform.*;
import phoenix3d.px2.thirdplatform.p91.*;

public class PX2TP_91 extends PX2TP 
{
	public String uid;
	public final static int Nd91_OT_LOGIN = 0;
	public final static int Nd91_OT_GUESTLOGIN = 1;
	public final static int Nd91_OT_GUESTREGIST = 2;
	public final static int Nd91_OT_RECHARGE = 3;
	public final static int Nd91_OT_SYNPAY = 4;
	public final static int Nd91_OT_ASYNPAY = 5;
	public final static int Nd91_OT_CUSTOMVIRTUALRECHARGE = 6;
	public final static int Nd91_OT_VIRSTOREPLATFORMUI = 7;
	public final static int Nd91_OT_PURCHASEDGOODS = 8;
	public final static int Nd91_OT_VIRTUALBALANCE = 9;
	private NdToolBar mNDToolBar = null; 
	private OnInitCompleteListener mOnInitCompleteListener = null;
	
	public PX2TP_91 (Activity activity)
	{
		super(activity);		
	
		_InitTP_91 ();
	}
	
	public void InitGame ()
	{
		mNDToolBar = NdToolBar.create(TheTPActivity, NdToolBarPlace.NdToolBarRightMid); 
		mNDToolBar.show();
		
		PX2Activity.TheActivity.ShowLibSOUpdateView();
	}
	
	private void _InitTP_91 ()
	{	
		Log.d("phoenix3d.px2", "begin _InitTP_91");
		
		if (PX2TPMetaData.IsDebug)
		{	
			Log.d("phoenix3d.px2", "91 is debug mode");
			
		//	NdCommp  latform.getInstance().ndSetDebugMode(0);// 璁剧疆璋冭瘯妯″紡
		}
		NdCommplatform.getInstance().ndSetScreenOrientation(NdCommplatform.SCREEN_ORIENTATION_PORTRAIT);
		
		NdAppInfo appInfo = new NdAppInfo();
		appInfo.setCtx(TheTPActivity);		
		appInfo.setAppId(PX2TPConstant_91.APPID_91Bean);// 搴旂敤ID
		appInfo.setAppKey(PX2TPConstant_91.APPKEY_91Bean);// 搴旂敤Key
		
		appInfo.setNdVersionCheckStatus(NdAppInfo.ND_VERSION_CHECK_LEVEL_NORMAL); // 鐗堟湰妫�煡澶辫触鍒欎笉鑳借繘鍏ユ父鎴�榛樿鍙栧�涓篘dVersionCheckLevelStrict
		// ND_VERSION_CHECK_LEVEL_STRICT
		mOnInitCompleteListener = new OnInitCompleteListener() 
		{
			@Override
			protected void onComplete (int ndFlag)
			{
				switch (ndFlag) 
				{
				case OnInitCompleteListener.FLAG_NORMAL: // 姝ｅ父鍒濆鍖�
					
					Log.d("phoenix3d.px2", "91 init ok");
					InitGame();
					
					break;
				case OnInitCompleteListener.FLAG_FORCE_CLOSE: // 寮哄埗閫�嚭娓告垙
					break;					
				default:
					break;
				}
			}

		};
		NdCommplatform.getInstance().ndInit(TheTPActivity, appInfo, mOnInitCompleteListener);
	}
	
	public void Term ()
	{
		if (mOnInitCompleteListener != null)
			mOnInitCompleteListener.destroy();
		
		if (mNDToolBar != null)
			mNDToolBar.recycle();
	}
	
	public void OnResume ()
	{
		NdCommplatform.getInstance().ndPause(new OnPauseCompleteListener(PX2Activity.TheActivity)
		{
			@Override
			public void onComplete() 
			{
				// empty
			}
			
		});
	}
	
	public void OnExist ()
	{
		NdCommplatform.getInstance().ndExit(
				new OnExitCompleteListener(PX2Activity.TheActivity)
				{
					@Override
					public void onComplete() 
					{
						PX2Activity.TheActivity.MyExit();
					}
			
		});		
	}
	public void OnLogoutExist ()
	{
		NdCommplatform.getInstance().ndExit(
				new OnExitCompleteListener(PX2Activity.TheActivity)
				{
					@Override
					public void onComplete() 
					{
						NdCommplatform.getInstance().ndLogout(NdCommplatform.LOGOUT_TO_RESET_AUTO_LOGIN_CONFIG, PX2Activity.TheActivity);
						PX2Activity.TheActivity.MyExit();
					}			
		});		
	}
	
	public void GuestLogin ()
	{	
		NdCommplatform.getInstance().ndLoginEx(PX2Activity.TheActivity,
				new NdMiscCallbackListener.OnLoginProcessListener() 
				{
					@Override
					public void finishLoginProcess(int code) 
					{
						OnLoginResult(code);
					}
				});
	}

	public void Login()
	{
		NdCommplatform.getInstance().ndLogin(PX2Activity.TheActivity, 
				new NdMiscCallbackListener.OnLoginProcessListener()
				{
					public void finishLoginProcess (int code)
					{
						OnLoginResult(code);
					}			
				});
	}
	
	public boolean IsLogin ()
	{
		return NdCommplatform.getInstance().isLogined();
	}
	
	private void OnLoginResult (int code)
	{
		String tip = "";

		if (code == NdErrorCode.ND_COM_PLATFORM_SUCCESS) 
		{			
			if (NdCommplatform.getInstance().ndGetLoginStatus() == NdLoginStatus.AccountLogin) 
			{// 璐﹀彿鐧诲綍		
				tip = "璐﹀彿鐧诲綍鎴愬姛";
			}
			else if (NdCommplatform.getInstance().ndGetLoginStatus() == NdLoginStatus.GuestLogin)
			{// 娓稿鐧诲綍				
				tip = "娓稿鐧诲綍鎴愬姛";
			}			
			
			String uid = NdCommplatform.getInstance().getLoginUin();
			String sessionID = NdCommplatform.getInstance().getSessionId();							
			String nickname = NdCommplatform.getInstance().getLoginNickName();			
			PX2TPNatives.OnLoginSuc(PX2TPConstant_91.APPID_91Bean, uid, sessionID, nickname);
			
			if (mNDToolBar != null)
			{
				//mNDToolBar.show();
			}

		} else if (code == NdErrorCode.ND_COM_PLATFORM_ERROR_CANCEL) 
		{
			tip = "鍙栨秷璐﹀彿鐧诲綍";
			
			PX2TPNatives.OnLoginCancel();			
		} 
		else if (code == NdErrorCode.ND_COM_GUEST_OFFICIAL_SUCCESS) 
		{
			tip = "娓稿杞鎴愬姛";
			
			if (NdCommplatform.getInstance().ndGetLoginStatus() == NdLoginStatus.GuestLogin)
			{
				PX2TPNatives.OnGuestOfficialSuc();
			}
			else
			{
				PX2TPNatives.OnLoginFailed();
			}
		} 
		else 
		{
			tip = "鐧诲綍澶辫触锛岄敊璇唬鐮侊細" + code;
			
			PX2TPNatives.OnLoginFailed();
		}
	}
	
	public void Logout ()
	{
		NdCommplatform.getInstance().ndLogout(NdCommplatform.LOGOUT_TO_RESET_AUTO_LOGIN_CONFIG, PX2Activity.TheActivity);

		Toast.makeText(PX2Activity.TheActivity, "閫�嚭鐧诲綍", Toast.LENGTH_SHORT).show();
	}
	
	public void SynPay (String productID,
			String productName,
			float productPrice,
			float productOrginalPrice,
			int count,
			String payDescription)
	{
		if (!NdCommplatform.getInstance().isLogined())
		{
			NdCommplatform.getInstance().ndLogin(PX2Activity.TheActivity,
					new NdMiscCallbackListener.OnLoginProcessListener()
					{
						public void finishLoginProcess(int code) 
						{
							OnLoginResult(code);
						}
					});

		}
		else
		{
			NdBuyInfo ndbuyinfo = new NdBuyInfo();
			String serial = MakeSerial();		
			ndbuyinfo.setSerial(serial);
			ndbuyinfo.setProductId(productID);
			ndbuyinfo.setProductName(productName);
			ndbuyinfo.setProductPrice(productPrice);
			ndbuyinfo.setProductOrginalPrice(productOrginalPrice);
			ndbuyinfo.setCount(count);
			ndbuyinfo.setPayDescription(payDescription);
			
			PX2TPPay_91.Instance().SynPay(ndbuyinfo);
		}
	}
	
	public void ASynPay (String productID,
			String productName,
			float productPrice,
			float productOrginalPrice,
			int count,
			String payDescription)
	{
		if (!NdCommplatform.getInstance().isLogined())
		{
			NdCommplatform.getInstance().ndLogin(PX2Activity.TheActivity,
					new NdMiscCallbackListener.OnLoginProcessListener()
					{
						public void finishLoginProcess(int code) 
						{
							OnLoginResult(code);
						}
					});

		}
		else
		{
			NdBuyInfo ndbuyinfo = new NdBuyInfo();
			String serial = MakeSerial();
			ndbuyinfo.setSerial(serial);
			ndbuyinfo.setProductId(productID);
			ndbuyinfo.setProductName(productName);
			ndbuyinfo.setProductPrice(productPrice);
			ndbuyinfo.setProductOrginalPrice(productOrginalPrice);
			ndbuyinfo.setCount(count);
			ndbuyinfo.setPayDescription(payDescription);
			
			PX2TPPay_91.Instance().ASynPay(ndbuyinfo);
		}
	}
};