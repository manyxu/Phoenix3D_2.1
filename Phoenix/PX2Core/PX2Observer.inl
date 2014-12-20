/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Observer.inl
*
*/

//----------------------------------------------------------------------------
template <class C, class N>
Observer<C, N>::Observer(C& object, Callback method)
	:
mObject(&object), 
mCallback(method)
{
}
//----------------------------------------------------------------------------
template <class C, class N>
Observer<C, N>::Observer(const Observer& observer)
	:
AbstractObserver(observer),
mObject(observer.mObject),
mCallback(observer.mCallback)
{
}
//----------------------------------------------------------------------------
template <class C, class N>
Observer<C, N>::~Observer()
{
}
//----------------------------------------------------------------------------
template <class C, class N>
Observer<C, N>& Observer<C, N>::operator = (const Observer& observer)
{
	if (&observer != this)
	{
		mObject = observer.mObject;
		mCallback  = observer.mCallback;
	}
	return *this;
}
//----------------------------------------------------------------------------
template <class C, class N>
void Observer<C, N>::Notify(Notification* nf) const
{
	ScopedCS cs(&mMutex);

	if (mObject)
	{
		N* castNf = dynamic_cast<N*>(nf);
		if (castNf)
		{
			(mObject->*mCallback)(castNf);
		}
	}
}
//----------------------------------------------------------------------------
template <class C, class N>
bool Observer<C, N>::Equals(const AbstractObserver& abstractObserver) const
{
	const Observer* pObs = dynamic_cast<const Observer*>(&abstractObserver);
	return pObs && pObs->mObject == mObject && pObs->mCallback == mCallback;
}
//----------------------------------------------------------------------------
template <class C, class N>
bool Observer<C, N>::Accepts(Notification* nf) const
{
	return dynamic_cast<N*>(nf) != 0;
}
//----------------------------------------------------------------------------
template <class C, class N>
AbstractObserver* Observer<C, N>::Clone() const
{
	return new Observer(*this);
}
//----------------------------------------------------------------------------
template <class C, class N>
void Observer<C, N>::Disable()
{
	ScopedCS cs(&mMutex);
	mObject = 0;
}
//----------------------------------------------------------------------------