package phoenix3d.px2.unity;

import android.content.Context;
import android.util.AttributeSet;
import android.view.View;

public interface PX2TPViewBase<T> 
{
	public void InitAttr(Context context, AttributeSet attrs);

	public void InitLayout();

	public void InitView();

	public void SetOnViewChangedListener (ViewChangedListener listener);

	public void ChangeView(View view);

	public interface ViewChangedListener
	{
		void Changed(View view);
	}
}