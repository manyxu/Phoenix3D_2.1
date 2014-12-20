/*
*
* ÎÄ¼þÃû³Æ	£º	PX2NObserver.inl
*
*/

//----------------------------------------------------------------------------
template <class C, class N>
NObserver<C, N>::NObserver(C& object, Callback method)
	: 
mObject(&object), 
mCallback(method)
{
}
//----------------------------------------------------------------------------
template <class C, class N>
NObserver<C, N>::NObserver(const NObserver& observer)
	:
AbstractObserver(observer),
mObject(observer.mObject), 
mCallback(observer.mCallback)
{
}
//----------------------------------------------------------------------------
template <class C, class N>
NObserver<C, N>::~NObserver()
{
}
//----------------------------------------------------------------------------
template <class C, class N>
NObserver& NObserver<C, N>::operator = (const NObserver& observer)
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
void NObserver<C, N>::Notify(Notification* nf) const
{
	ScopedCS cs (&mMutex);

	if (mObject)
	{
		N* castNf = dynamic_cast<N*>(nf);
		if (castNf)
		{
			NotificationPtr ptr(castNf, true);
			(mObject->*mCallback)(ptr);
		}
	}
}
//----------------------------------------------------------------------------
template <class C, class N>
bool NObserver<C, N>::Equals(const AbstractObserver& abstractObserver) const
{
	const NObserver* pObs = dynamic_cast<const NObserver*>(&abstractObserver);
	return pObs && pObs->mObject == mObject && pObs->mCallback == mCallback;
}
//----------------------------------------------------------------------------
template <class C, class N>
bool NObserver<C, N>::Accepts(Notification* nf) const
{
	return dynamic_cast<N*>(nf) != 0;
}
//----------------------------------------------------------------------------
template <class C, class N>
AbstractObserver* NObserver<C, N>::Clone() const
{
	return new NObserver(*this);
}
//----------------------------------------------------------------------------
template <class C, class N>
void NObserver<C, N>::Disable()
{
	ScopedCS cs(&mMutex);
	mObject = 0;
}
//----------------------------------------------------------------------------