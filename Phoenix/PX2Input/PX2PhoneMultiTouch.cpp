/*
*
* ÎÄ¼þÃû³Æ	£º	PX2PhoneMultiTouch.cpp
*
*/

#include "PX2PhoneMultiTouch.hpp"
#include "PX2PhoneInputManager.hpp"
using namespace PX2;

#ifdef __MARMALADE__
#include "s3e.h"

struct CTouch
{
    int32 x; // position x
    int32 y; // position y
    bool active; // is touch active (currently down)
    int32 id; // touch's unique identifier
};
#define MAX_TOUCHES 10
CTouch g_Touches[MAX_TOUCHES];
bool g_UseMultiTouch = false;


CTouch* GetTouch(int32 id)
{
    CTouch* pInActive = NULL;

    for (uint32 i = 0; i < MAX_TOUCHES; i++)
    {
        if (id == g_Touches[i].id)
            return &g_Touches[i];
        if (!g_Touches[i].active)
            pInActive = &g_Touches[i];
    }

    //Return first inactive touch
    if (pInActive)
    {
        pInActive->id = id;
        return pInActive;
    }

    //No more touches, give up.
    return NULL;
}

static void SendListenerEvent(PhoneMultiTouch *touchmgr, MultiTouchEventType type, int id, int x, int y)
{
	Sizef size = InputManager::GetSingleton().GetSize();
	if(touchmgr == 0) return;

	MultiTouchListener *listener = touchmgr->GetEventCallback();
	if(listener)
	{
		MultiTouchState tstate;
		tstate.ID = id;
		tstate.TouchTypes = type;
		tstate.X.Absoulate = x;
		tstate.X.IsAbsoulateOnly = true;
		tstate.Y.Absoulate = size.Height - y;
		tstate.Y.IsAbsoulateOnly = true;

		if(type == MTET_PRESSED) listener->TouchPressed(MultiTouchEvent(NULL,tstate));
		else if(type == MTET_RELEASED) listener->TouchReleased(MultiTouchEvent(NULL,tstate));
		else if(type == MTET_MOVED) listener->TouchMoved(MultiTouchEvent(NULL,tstate));
	}
}

void MultiTouchButtonCB(s3ePointerTouchEvent* event, PhoneMultiTouch *touchmgr)
{
    CTouch* touch = GetTouch(event->m_TouchID);
    if (touch)
    {
        touch->active = event->m_Pressed != 0;
        touch->x = event->m_x;
        touch->y = event->m_y;

		SendListenerEvent(touchmgr, event->m_Pressed?MTET_PRESSED:MTET_RELEASED, event->m_TouchID, event->m_x, event->m_y);
    }
}

void MultiTouchMotionCB(s3ePointerTouchMotionEvent* event, PhoneMultiTouch *touchmgr)
{
    CTouch* touch = GetTouch(event->m_TouchID);
    if (touch)
    {
        touch->x = event->m_x;
        touch->y = event->m_y;

		SendListenerEvent(touchmgr, MTET_MOVED, event->m_TouchID, event->m_x, event->m_y);
	}
}

void SingleTouchButtonCB(s3ePointerEvent* event, PhoneMultiTouch *touchmgr)
{
    g_Touches[0].active = event->m_Pressed != 0;
    g_Touches[0].x = event->m_x;
    g_Touches[0].y = event->m_y;

	SendListenerEvent(touchmgr, event->m_Pressed?MTET_PRESSED:MTET_RELEASED, 0, event->m_x, event->m_y);
}

void SingleTouchMotionCB(s3ePointerMotionEvent* event, PhoneMultiTouch *touchmgr)
{
    g_Touches[0].x = event->m_x;
    g_Touches[0].y = event->m_y;

	SendListenerEvent(touchmgr, MTET_MOVED, 0, event->m_x, event->m_y);
}

static void InitTouch(PhoneMultiTouch *touchmgr)
{
	g_UseMultiTouch = s3ePointerGetInt(S3E_POINTER_MULTI_TOUCH_AVAILABLE) ? true : false;

	if(g_UseMultiTouch)
	{
        s3ePointerRegister(S3E_POINTER_TOUCH_EVENT, (s3eCallback)MultiTouchButtonCB, touchmgr);
        s3ePointerRegister(S3E_POINTER_TOUCH_MOTION_EVENT, (s3eCallback)MultiTouchMotionCB, touchmgr);
	}
	else
	{
        s3ePointerRegister(S3E_POINTER_BUTTON_EVENT, (s3eCallback)SingleTouchButtonCB, touchmgr);
        s3ePointerRegister(S3E_POINTER_MOTION_EVENT, (s3eCallback)SingleTouchMotionCB, touchmgr);
	}
}

static void ReleaseTouch()
{
    if (g_UseMultiTouch)
    {
        s3ePointerUnRegister(S3E_POINTER_TOUCH_EVENT, (s3eCallback)MultiTouchButtonCB);
        s3ePointerUnRegister(S3E_POINTER_TOUCH_MOTION_EVENT, (s3eCallback)MultiTouchMotionCB);
    }
    else
    {
        s3ePointerUnRegister(S3E_POINTER_BUTTON_EVENT, (s3eCallback)SingleTouchButtonCB);
        s3ePointerUnRegister(S3E_POINTER_MOTION_EVENT, (s3eCallback)SingleTouchMotionCB);
    }
}

#else
static void InitTouch(PhoneMultiTouch *touchmgr)
{
}
static void ReleaseTouch()
{
}
#endif

//----------------------------------------------------------------------------
PhoneMultiTouch::PhoneMultiTouch (InputManager* creator, bool buffered)
	:
MultiTouch(creator->GetInputSystemName(), buffered, 0, creator)
{
	static_cast<PhoneInputManager*>(mCreator)->SetMultiTouchUsed(true);
	InitTouch(this);
}
//----------------------------------------------------------------------------
PhoneMultiTouch::~PhoneMultiTouch ()
{
	ReleaseTouch();
	static_cast<PhoneInputManager*>(mCreator)->SetMultiTouchUsed(false);
}
//----------------------------------------------------------------------------
void PhoneMultiTouch::Initialize()
{
}
//----------------------------------------------------------------------------
void PhoneMultiTouch::Capture()
{
}
//----------------------------------------------------------------------------