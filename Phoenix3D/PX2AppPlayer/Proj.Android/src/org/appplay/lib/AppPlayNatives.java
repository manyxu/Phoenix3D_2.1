package org.appplay.lib;

public class AppPlayNatives
{
	public static native void nativeOdle ();
	public static native void nativeInit (int width, int height);
	public static native void nativeOnPause ();
	public static native void nativeOnResume ();
	public static native void nativeOnTerm ();
	public static native void nativeSetApkDataPath(String path);
	public static native void nativeSetDataUpdateServerType (String type);
	public static native void nativeSetDeviceIDStr(String deviceIDStr);
	
	public static native void nativeTouchPressed(int id, float x, float y);
	public static native void nativeTouchReleased(int id, float x, float y);
    public static native void nativeTouchMoved(int[] id, float[] x, float[] y);
    public static native void nativeTouchCancelled(int[] id, float[] x, float[] y);
    public static native boolean nativeKeyDown(int keyCode);
    
    public static native void nativeInsertText(String text);
    public static native void nativeDeleteBackward();
    public static native String nativeGetContentText();
}
