/*
*
* ÎÄ¼þÃû³Æ	£º	PX2InputPre.hpp
*
*/

#ifndef PX2INPUTPRE_HPP
#define PX2INPUTPRE_HPP

#include "PX2CorePre.hpp"

#if defined(_WIN32) || defined(WIN32)

#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>

#ifdef PX2_WIN32_XINPUT_SUPPORT
#include <XInput.h>
#endif

#define KEYBOARD_DX_BUFFERSIZE 17
#define MOUSE_DX_BUFFERSIZE 128
#define JOYSTICK_DX_BUFFERSIZE 129

#endif

#endif