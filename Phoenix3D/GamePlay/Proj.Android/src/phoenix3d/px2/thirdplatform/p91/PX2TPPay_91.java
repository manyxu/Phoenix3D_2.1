package phoenix3d.px2.thirdplatform.p91;

import phoenix3d.px2.library.PX2Activity;
import phoenix3d.px2.thirdplatform.PX2TP;
import android.app.Activity;
import android.util.Log;
import android.widget.Toast;

import com.nd.commplatform.NdCallbackListener;
import com.nd.commplatform.NdCommplatform;
import com.nd.commplatform.NdErrorCode;
import com.nd.commplatform.NdMiscCallbackListener;
import com.nd.commplatform.entry.NdAppInfo;
import com.nd.commplatform.entry.NdBuyInfo;
import com.nd.commplatform.entry.NdLoginStatus;
import com.nd.commplatform.entry.NdPayResultInfo;

import phoenix3d.px2.thirdplatform.*;

public class PX2TPPay_91
{
	private static PX2TPPay_91 Instance = null;
	private NdBuyInfo mBuyInfo = null;
	
	public static PX2TPPay_91 Instance ()
	{
		if (null == Instance)
			Instance = new PX2TPPay_91();
		
		return Instance;
	}
	
	private PX2TPPay_91 ()
	{
	}	
	
	public void SynPay (final NdBuyInfo buyinfo)
	{
		mBuyInfo = buyinfo;
	
		if (!CheckBuyInfoValied())
			return;
		
		int error = NdCommplatform.getInstance().ndUniPay(mBuyInfo, PX2Activity.TheActivity,
				new NdMiscCallbackListener.OnPayProcessListener() 
				{
					public void finishPayProcess (int code)
					{
						String serial = mBuyInfo.getSerial();
						
						if (code == NdErrorCode.ND_COM_PLATFORM_SUCCESS) 
						{
							PX2TPNatives.OnPaySuc(serial, true);
						} 
						else if (code == NdErrorCode.ND_COM_PLATFORM_ERROR_PAY_FAILURE)
						{
							PX2TPNatives.OnPayFailed(serial, true);
						}
						else if (code == NdErrorCode.ND_COM_PLATFORM_ERROR_PAY_CANCEL) 
						{
							PX2TPNatives.OnPayCancel(serial, true);
						}
					}
				}
				);
		
		if (0 != error)
		{
			Toast.makeText(PX2Activity.TheActivity, "您输入的商品信息格式不正确", Toast.LENGTH_SHORT).show();
			PX2TPNatives.OnPayError(mBuyInfo.getSerial(), error, true);
		}
	}
	
	public void ASynPay (final NdBuyInfo buyinfo) 
	{
		mBuyInfo = buyinfo;		
		
		if (!CheckBuyInfoValied())
			return;

		int error = NdCommplatform.getInstance().ndUniPayAsyn(mBuyInfo,
				PX2Activity.TheActivity,
				new NdMiscCallbackListener.OnPayProcessListener() 
				{
					String serial = mBuyInfo.getSerial();

					public void finishPayProcess(int code)
					{
						if (code == NdErrorCode.ND_COM_PLATFORM_SUCCESS) 
						{ // 购买成功，此时可向玩家发放道具
							Log.w("phoenix3d.px2", "PaySuc!");
							PX2TPNatives.OnPaySuc(serial, false);
							Toast.makeText(PX2Activity.TheActivity, "购买成功，服务器将发送物品", Toast.LENGTH_SHORT).show();
						} 
						else if (code == NdErrorCode.ND_COM_PLATFORM_ERROR_PAY_FAILURE)
						{ // 购买失败
							Log.w("phoenix3d.px2", "PayFailure!");
							PX2TPNatives.OnPayFailed(serial, false);
							Toast.makeText(PX2Activity.TheActivity, "购买失败", Toast.LENGTH_SHORT).show(); 
						}
						else if (code == NdErrorCode.ND_COM_PLATFORM_ERROR_PAY_CANCEL) 
						{ // 取消购买
							Log.w("phoenix3d.px2", "PayCancel!");
							PX2TPNatives.OnPayCancel(serial, false);
							Toast.makeText(PX2Activity.TheActivity, "取消购买", Toast.LENGTH_SHORT).show();							
						} 
						else if (code == NdErrorCode.ND_COM_PLATFORM_ERROR_PAY_ASYN_SMS_SENT)
						{
							// 此时用户账号余额不足，通过短信充值来购买道具，由于短信有时需要玩家回确认短信，
							// 所以开发者需要记下购买的订单号，以便向服务器查询玩家是否购买成功以便向玩家发放道具
							Log.w("phoenix3d.px2", "PayAsyn_SMS_Sent!");
							PX2TPNatives.OnPaySMSSent(serial, false);
							Toast.makeText(PX2Activity.TheActivity, "订单已提交，充值短信已发送", Toast.LENGTH_SHORT).show();
						} 
						else if (code == NdErrorCode.ND_COM_PLATFORM_ERROR_PAY_REQUEST_SUBMITTED)
						{
							// 此时用户账号余额不足，通过充值来购买道具，单此时还无法知道玩家此次购买是否成功，
							// 所以开发者需要记下购买的订单号，以便向服务器查询玩家是否购买成功以便向玩家发放道具
							Log.w("phoenix3d.px2", "PayResuestSub!");
							PX2TPNatives.OnPayRequestSubmitted(serial, false);
							Toast.makeText(PX2Activity.TheActivity, "订单已提交", Toast.LENGTH_SHORT).show();
						}
						else
						{
							Toast.makeText(PX2Activity.TheActivity, "购买失败" + code, Toast.LENGTH_SHORT).show(); 
						}

					}
				});
		
		if (0 != error)
		{
			Toast.makeText(PX2Activity.TheActivity, "您输入的商品信息格式不正确", Toast.LENGTH_SHORT).show();
			PX2TPNatives.OnPayError(mBuyInfo.getSerial(), error, false);
		}
	}
	
	public void CheckResult ()
	{
		String serial = mBuyInfo.getSerial();
		
		if (serial == null || serial.trim().equals("".trim())) 
		{
			return;
		}
		
		NdCallbackListener<NdPayResultInfo> callback = new NdCallbackListener<NdPayResultInfo>()
		{
			@Override
			public void callback(int responseCode, NdPayResultInfo t)
			{
				if (responseCode == NdErrorCode.ND_COM_PLATFORM_SUCCESS)
				{ // 查询成功
					if (t.isSuccess())
					{
						Toast.makeText(PX2Activity.TheActivity, "订单支付成功,商品名称为：" + t.getGoodsName(), Toast.LENGTH_SHORT).show();
					}
					else 
					{
						Toast.makeText(PX2Activity.TheActivity, "订单支付失败", Toast.LENGTH_SHORT).show();
					}
				}
				else if (responseCode == NdErrorCode.ND_COM_PLATFORM_ERROR_UNEXIST_ORDER) 
				{ // 无此订单
					Toast.makeText(PX2Activity.TheActivity, "无此订单", Toast.LENGTH_SHORT).show();
				} 
				else
				{
					Toast.makeText(PX2Activity.TheActivity, "查询失败，错误码：" + responseCode, Toast.LENGTH_SHORT).show();
				}
			}
		};		
		NdCommplatform.getInstance().ndSearchPayResultInfo(serial, PX2Activity.TheActivity, callback);
	}	
	
	public boolean CheckBuyInfoValied ()
	{
		if (null == mBuyInfo)
			return false;
		
		String serial = mBuyInfo.getSerial();
		double price = mBuyInfo.getProductPrice();
		int amount = mBuyInfo.getCount();
		
		if (null==serial || serial.trim().equals("".trim()))
		{
			Toast.makeText(PX2Activity.TheActivity, "订单号不能为空", Toast.LENGTH_SHORT).show();
			return false;
		}
		
		if (price < 0.01)
		{
			Toast.makeText(PX2Activity.TheActivity, "商品单价不能小于0.01个91豆", Toast.LENGTH_SHORT).show();
			return false;
		}
		
		if (amount < 1)
		{
			Toast.makeText(PX2Activity.TheActivity, "所购买的商品个数不能小于1", Toast.LENGTH_SHORT).show();
			return false;
		}
		
		double allPrice = price * amount;
		if (allPrice > 1000000)
		{
			Toast.makeText(PX2Activity.TheActivity, "单笔交易额不能大于1000000个91豆", Toast.LENGTH_SHORT).show();
			return false;
		}
		
		return true;
	}
}
