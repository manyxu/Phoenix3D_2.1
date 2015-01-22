package phoenix3d.px2.library;

import phoenix3d.px2.library.PX2GLView;
import android.content.Context;
import android.util.AttributeSet;
import android.view.KeyEvent;
import android.widget.EditText;

public class PX2EditText extends EditText
{
	private PX2GLView mView;

	public PX2EditText (Context context) 
	{
		super(context);
	}
	
	public PX2EditText (Context context, AttributeSet attrs) 
	{
		super(context, attrs);
	}
	
	public PX2EditText (Context context, AttributeSet attrs, int defStyle) 
	{
		super(context, attrs, defStyle);
	}
	
	public void SetMainView (PX2GLView view) 
	{
		mView = view;
	}

	@Override
	public boolean onKeyDown (int keyCode, KeyEvent event) 
	{
		super.onKeyDown(keyCode, event);
		
		/* Let GlSurfaceView get focus if back key is input. */
		if (keyCode == KeyEvent.KEYCODE_BACK) 
		{
			mView.requestFocus();
		}
		
		return true;
	}
}
