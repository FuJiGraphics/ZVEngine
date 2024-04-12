#ifndef __ZV_ZVKEYEVENT_H__
#define __ZV_ZVKEYEVENT_H__
#pragma once

#include "ZVevent.h"

#include <sstream>

namespace ZVLab {

	class ZV_API CZVkeyEvent : public CZVevent
	{
	protected:
		ZVint m_iKeyCode;

	protected:
		CZVkeyEvent(ZVint keycode)
			: m_iKeyCode(keycode) {}

	public:
		inline int GetKeyCode() const { return (m_iKeyCode); }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	};

	class ZV_API CZVkeyPressedEvent final : public CZVkeyEvent
	{
	private:
		ZVuint m_uiRepeatCount;

	public:
		CZVkeyPressedEvent(ZVint keycode, ZVuint repeatCount = 0)
			: CZVkeyEvent(keycode), m_uiRepeatCount(repeatCount) {}

		inline ZVuint GetRepeatCount() const { return (m_uiRepeatCount); }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_iKeyCode << " (" << m_uiRepeatCount << " repeats)";
			return (ss.str());
		}

		EVENT_CLASS_TYPE(KeyPressed)
	};

	class ZV_API CZVkeyReleasedEvent final : public CZVkeyEvent
	{
	public:
		CZVkeyReleasedEvent(ZVint keycode)
			: CZVkeyEvent(keycode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_iKeyCode;
			return (ss.str());
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};


	class ZV_API CZVkeyTypedEvent final : public CZVkeyEvent
	{
	public:
		CZVkeyTypedEvent(ZVint keycode)
			: CZVkeyEvent(keycode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyTypedEvent: " << m_iKeyCode;
			return (ss.str());
		}

		EVENT_CLASS_TYPE(KeyTyped)
	};
} // namepsace ZVLab

#endif /*__ZV_ZVKEYEVENT_H__*/
