package org.appplay.lib;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.opengl.GLSurfaceView;
import android.util.Log;

class AppPlayRenderer implements GLSurfaceView.Renderer
{
    private AppPlayBaseActivity mActivity;
	private int mWidth;
	private int mHeight;

    public AppPlayRenderer(AppPlayBaseActivity activity)
    {
        mActivity = activity;
    }

    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config)
    { 
    	Log.d("appplay.lib", "begin - surface created, navtiveInit.");
    	
    	AppPlayNatives.nativeInit(mWidth, mHeight); 
    	
    	Log.d("appplay.lib", "end - nativeInit.");
    }

    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height) 
    {
    	// GLES20.glViewport(0, 0, width, height);
    } 

    @Override
    public void onDrawFrame(GL10 gl)
    {
    	// draw
    	AppPlayNatives.nativeOdle();   	
    }
    
    // -- funcions implemented ourself -- 
    
	public void SetSize(int w, int h)
    {
    	this.mWidth = w;
    	this.mHeight = h;
    }
    
}