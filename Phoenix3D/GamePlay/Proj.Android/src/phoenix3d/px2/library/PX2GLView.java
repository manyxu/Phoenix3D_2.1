package phoenix3d.px2.library;

import javax.microedition.khronos.egl.EGL10;
import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.egl.EGLContext;
import javax.microedition.khronos.egl.EGLDisplay;

import android.opengl.GLSurfaceView;
import android.os.Handler;
import android.os.Message;
import android.text.Editable;
import android.text.TextWatcher;
import android.content.Context;
import android.graphics.PixelFormat;
import android.opengl.GLSurfaceView;
import android.os.Handler;
import android.os.Message;
import android.util.AttributeSet;
import android.util.Log;
import android.view.KeyEvent;
import android.view.MotionEvent;
import android.view.inputmethod.InputMethodManager;
import android.widget.TextView;
import android.widget.TextView.OnEditorActionListener;

import phoenix3d.px2.library.PX2Natives;
import phoenix3d.px2.library.PX2Activity;
import phoenix3d.px2.library.PX2Renderer;
import phoenix3d.px2.library.PX2EditText;
import phoenix3d.px2.library.PX2TextInputWraper;

public class PX2GLView extends GLSurfaceView
{
    private final static int HANDLER_OPEN_IME_KEYBOARD = 2;
    private final static int HANDLER_CLOSE_IME_KEYBOARD = 3;
    
    private static Handler msHandler;
    
    private static PX2GLView msInstanceView;
    private static PX2TextInputWraper msTextInputWraper;
    
    private PX2Renderer mRenderer;
    private PX2EditText mEditText;
	
    public PX2GLView(PX2Activity activity)
    {
        super(activity);
        
        setEGLContextClientVersion(2);        
        setEGLConfigChooser(8, 8, 8, 8, 24, 8);
        
        mRenderer = new PX2Renderer(activity);        
        setRenderer(mRenderer);
        
        InitView();
        
        Log.d("phoenix3d.px2", "PX2GLView::PX2GLView");
    }    
    
	protected void InitView()
	{
		setFocusableInTouchMode(true);

		msInstanceView = this;
		msTextInputWraper = new PX2TextInputWraper(this);

		msHandler = new Handler()
		{
			@Override
			public void handleMessage(final Message msg) 
			{
				switch (msg.what) {
					case HANDLER_OPEN_IME_KEYBOARD:					
						
						if (null != PX2GLView.this.mEditText && PX2GLView.this.mEditText.requestFocus()) 
						{
							PX2GLView.this.mEditText.removeTextChangedListener(PX2GLView.msTextInputWraper);
							PX2GLView.this.mEditText.setText("");
							final String text = (String) msg.obj;
							PX2GLView.this.mEditText.append(text);
							PX2GLView.msTextInputWraper.SetOriginText(text);
							PX2GLView.this.mEditText.addTextChangedListener(PX2GLView.msTextInputWraper);
							final InputMethodManager imm = (InputMethodManager) PX2GLView.msInstanceView.getContext().getSystemService(Context.INPUT_METHOD_SERVICE);
							imm.showSoftInput(PX2GLView.this.mEditText, 0);
						}
						break;

					case HANDLER_CLOSE_IME_KEYBOARD:
						
						Log.d("phoenix3d.px2", "close keyboard");
						
						if (null != PX2GLView.this.mEditText) 
						{
							PX2GLView.this.mEditText.removeTextChangedListener(PX2GLView.msTextInputWraper);
							final InputMethodManager imm = (InputMethodManager) PX2GLView.msInstanceView.getContext().getSystemService(Context.INPUT_METHOD_SERVICE);
							imm.hideSoftInputFromWindow(PX2GLView.this.mEditText.getWindowToken(), 0);
							PX2GLView.this.requestFocus();
						}
						break;
				}
			}
		};
	}  
   
    @Override
    protected void onSizeChanged(int w, int h, int oldw, int oldh)
    {
    	mRenderer.SetScreenWidthAndHeight(w, h);    	
    	Log.d("phoenix3d.px2", "PX2Renderer::onSizeChanged");
    }
    
    @Override
    public void onPause()
    {
    	queueEvent(new Runnable() {

            public void run() {
            	PX2Natives.nativeOnPause();
            }
        });
    	
    	super.onPause();
    }
    
    @Override
    public void onResume(){
    	
    	super.onResume();
    	
    	queueEvent(new Runnable() {

            public void run() {  
            	PX2Natives.nativeOnResume();
            }
        });
    }
    
    // impl myself
    public void OnDestory ()
    {   	
    	queueEvent(new Runnable() {
    		
            public void run() 
            {  
            	//PX2Natives.nativeOnTerm();
            }
        });
    }    

	private String GetContentText()
	{
		return PX2Natives.nativeGetContentText();
	}
    
    public TextView GetTextField() 
    {
    	return mEditText;
    }
    
    public void SetTextField (PX2EditText view) 
    {
    	mEditText = view;
    	
    	if (null!=mEditText && null!=msTextInputWraper) 
    	{
    		mEditText.setOnEditorActionListener(msTextInputWraper);
    		mEditText.SetMainView(this);
    		this.requestFocus();
    	}
    }
    
    @Override
    public boolean onTouchEvent(final MotionEvent event) 
    {	
    	// these data are used in ACTION_MOVE and ACTION_CANCEL
    	final int pointerNumber = event.getPointerCount();
    	final int[] ids = new int[pointerNumber];
    	final float[] xs = new float[pointerNumber];
    	final float[] ys = new float[pointerNumber];

    	for (int i = 0; i < pointerNumber; i++) 
    	{
            ids[i] = event.getPointerId(i);
            xs[i] = event.getX(i);
            ys[i] = event.getY(i);
        }
        
        switch (event.getAction() & MotionEvent.ACTION_MASK)
        {
        case MotionEvent.ACTION_POINTER_DOWN:
        	final int indexPointerDown = event.getAction() >> MotionEvent.ACTION_POINTER_ID_SHIFT;
        	final int idPointerDown = event.getPointerId(indexPointerDown);
            final float xPointerDown = event.getX(indexPointerDown);
            final float yPointerDown = event.getY(indexPointerDown);

            queueEvent(new Runnable() {
                public void run() {
                	PX2Natives.nativeTouchPressed(idPointerDown, xPointerDown, yPointerDown);
                }
            });
            break;
            
        case MotionEvent.ACTION_DOWN:
        	// there are only one finger on the screen
        	final int idDown = event.getPointerId(0);
            final float xDown = xs[0];
            final float yDown = ys[0];
            
            queueEvent(new Runnable() {
                public void run() {
                	PX2Natives.nativeTouchPressed(idDown, xDown, yDown);
                }
            });
            break;

        case MotionEvent.ACTION_MOVE:
            queueEvent(new Runnable() {
                public void run() {
                	PX2Natives.nativeTouchMoved(ids, xs, ys);
                }
            });
            break;

        case MotionEvent.ACTION_POINTER_UP:
        	final int indexPointUp = event.getAction() >> MotionEvent.ACTION_POINTER_ID_SHIFT;
        	final int idPointerUp = event.getPointerId(indexPointUp);
            final float xPointerUp = event.getX(indexPointUp);
            final float yPointerUp = event.getY(indexPointUp);
            
            queueEvent(new Runnable() {
  
                public void run() {
                	PX2Natives.nativeTouchReleased(idPointerUp, xPointerUp, yPointerUp);
                }
            });
            break;
            
        case MotionEvent.ACTION_UP:  
        	final int idUp = event.getPointerId(0);
            final float xUp = xs[0];
            final float yUp = ys[0];
            
            queueEvent(new Runnable() {
                public void run() {
                	PX2Natives.nativeTouchReleased(idUp, xUp, yUp);
                }
            });
            break;

        case MotionEvent.ACTION_CANCEL:
            queueEvent(new Runnable() {
                public void run() {
                	PX2Natives.nativeTouchCancelled(ids, xs, ys);
                }
            });
            break;
        }
        return true;
    }
    
    @Override
    public boolean onKeyDown(int keyCode, KeyEvent event)
    {
    	final int kc = keyCode;
    /*	if (keyCode == KeyEvent.KEYCODE_BACK || keyCode == KeyEvent.KEYCODE_MENU)
    	{
    		queueEvent(new Runnable() {
	            public void run() {
	            	PX2Natives.nativeKeyDown(kc);
	            }
    		});
    		return true;
    	}*/
        return super.onKeyDown(keyCode, event);
    }    

	public static void OpenIMEKeyboard()
	{	
		final Message msg = new Message();
		msg.what = PX2GLView.HANDLER_OPEN_IME_KEYBOARD;
		msg.obj = PX2GLView.msInstanceView.GetContentText();
		PX2GLView.msHandler.sendMessage(msg);
	}

	public static void CloseIMEKeyboard() 
	{
		final Message msg = new Message();
		msg.what = PX2GLView.HANDLER_CLOSE_IME_KEYBOARD;
		PX2GLView.msHandler.sendMessage(msg);
	}
	
    public void InsertText(final String text) 
    {
        queueEvent(new Runnable() {

            public void run() {
                mRenderer.HandleInsertText(text);
            }
        });
    }
    
    public void DeleteBackward()
    {
        queueEvent(new Runnable()
        {

            public void run()
            {
                mRenderer.HandleDeleteBackward();
            }
        });
    }

}
