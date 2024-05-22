#ifndef __ZV_ZVKEYEVENT_H__
#define __ZV_ZVKEYEVENT_H__
#pragma once

#include "ZVEvent.h"

#include <sstream>

namespace ZVLab {

	class ZV_API CzvKeyEvent : public CzvEvent
	{
	protected:
		ZVint m_iKeyCode;

	protected:
		CzvKeyEvent(ZVint keycode)
			: m_iKeyCode(keycode) {}

	public:
		inline int GetKeyCode() const { return (m_iKeyCode); }

		DEventClassCategory(ezvEventCategory_Keyboard | ezvEventCategory_Input)
	};

	class ZV_API CzvKeyPressedEvent final : public CzvKeyEvent
	{
	private:
		ZVuint m_uiRepeatCount;

	public:
		CzvKeyPressedEvent(ZVint keycode, ZVuint repeatCount = 0)
			: CzvKeyEvent(keycode), m_uiRepeatCount(repeatCount) {}

		inline ZVuint GetRepeatCount() const { return (m_uiRepeatCount); }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_iKeyCode << " (" << m_uiRepeatCount << " repeats)";
			return (ss.str());
		}

		DEventClassType(KeyPressed)
	};

	class ZV_API CzvKeyReleasedEvent final : public CzvKeyEvent
	{
	public:
		CzvKeyReleasedEvent(ZVint keycode)
			: CzvKeyEvent(keycode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_iKeyCode;
			return (ss.str());
		}

		DEventClassType(KeyReleased)
	};


	class ZV_API CzvKeyTypedEvent final : public CzvKeyEvent
	{
	public:
		CzvKeyTypedEvent(ZVint keycode)
			: CzvKeyEvent(keycode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyTypedEvent: " << m_iKeyCode;
			return (ss.str());
		}

		DEventClassType(KeyTyped)
	};
} // namepsace ZVLab

#endif /*__ZV_ZVKEYEVENT_H__*/
