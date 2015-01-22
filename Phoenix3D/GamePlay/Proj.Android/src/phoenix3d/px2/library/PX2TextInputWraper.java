package phoenix3d.px2.library;

import android.content.Context;
import android.text.Editable;
import android.text.TextWatcher;
import android.util.Log;
import android.view.KeyEvent;
import android.view.inputmethod.InputMethodManager;
import android.widget.TextView;
import android.widget.TextView.OnEditorActionListener;

class PX2TextInputWraper implements TextWatcher, OnEditorActionListener
{
	private static final Boolean debug = false;
	private void LogD (String msg)
	{
		if (debug)
			Log.d("PX2TextInputWraper", msg);
	}
	
	private PX2GLView mMainView;
	private String mText;
	private String mOriginText;
	
	private Boolean IsFullScreenEdit ()
	{
		InputMethodManager imm = (InputMethodManager)mMainView.GetTextField().getContext().getSystemService(Context.INPUT_METHOD_SERVICE);
		return imm.isFullscreenMode();
	}
	
	public PX2TextInputWraper (PX2GLView view)
	{
		mMainView = view;
	}
	
	public void SetOriginText (String text)
	{
		mOriginText = text;
	}
	
	@Override
	public void afterTextChanged (Editable s)
	{
		if (IsFullScreenEdit())
			return;
		
		LogD("AfterTextChanged:" + s);
		
		int numModified = s.length() - mText.length();
		
		if (numModified > 0)
		{
			final String insertText = s.subSequence(mText.length(), s.length()).toString();
			
			mMainView.InsertText(insertText);
			
			LogD("InsertText(" + insertText +")");
		}
		else
		{
			for (; numModified<0; ++numModified)
			{
				mMainView.DeleteBackward();
				
				LogD("DeleteBackward");
			}
		}
		
		mText = s.toString();
	}
	
	@Override
	public void beforeTextChanged (CharSequence s, int start, int count, int after)
	{
		LogD("BeforeTextChanged(" + s + ")start:" + start + ",count:" + ",after:" + after);
		mText = s.toString();
	}
	
	@Override
	public void onTextChanged (CharSequence s, int start, int before, int count)
	{		
	}
	
	@Override
	public boolean onEditorAction (TextView v, int actionId, KeyEvent event)
	{
		if (mMainView.GetTextField()==v && IsFullScreenEdit())
		{
			// user press the action button, delete all old text and insert new text
			for (int i=mOriginText.length(); i>0; --i)
			{			
				mMainView.DeleteBackward();
				LogD("DeleteBackward");
			}
			
			String text = v.getText().toString();
			
			if (0 == text.compareTo(""))
			{
				text = "\n";
			}
			
			if ('\n' != text.charAt(text.length()-1))
			{
				text += '\n';
			}
			
			final String insertText = text;
			
			mMainView.InsertText(insertText);

			LogD("InsertText(" + insertText + ")");
		}
		
		return false;
	}
}
