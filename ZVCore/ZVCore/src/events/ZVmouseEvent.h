#ifndef __ZV_MOUSEEVENT_H__
#define __ZV_MOUSEEVENT_H__
#pragma once

#include "ZVevent.h"

#include <sstream>

namespace ZVLab {

	class ZV_API CZVmouseMovedEvent final : public CZVevent
	{
	private:
		ZVfloat m_fMouseX, m_fMouseY;

	public:
		CZVmouseMovedEvent(ZVfloat x, ZVfloat y)
			: m_fMouseX(x), m_fMouseY(y) {}

		inline ZVfloat GetX() const { return (m_fMouseX); }
		inline ZVfloat GetY() const { return (m_fMouseY); }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_fMouseX << ", " << m_fMouseY;
			return (ss.str());
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	};

	class ZV_API CZVmouseScrolledEvent final : public CZVevent
	{
	private:
		ZVfloat m_fXOffset, m_fYOffset;

	public:
		CZVmouseScrolledEvent(ZVfloat xOffset, ZVfloat yOffset)
			: m_fXOffset(xOffset), m_fYOffset(yOffset) {}

		inline ZVfloat GetXOffset() const { return (m_fXOffset); }
		inline ZVfloat GetYOffset() const { return (m_fYOffset); }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
			return (ss.str());
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	};

	class ZV_API CZVmouseButtonEvent : public CZVevent
	{
	protected:
		ZVint m_iButton;

	protected:
		CZVmouseButtonEvent(ZVint button)
			: m_iButton(button) {}

	public:
		inline ZVint GetMouseButton() const { return (m_iButton); }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	};

	class ZV_API CZVmouseButtonPressedEvent final : public CZVmouseButtonEvent
	{
	public:
		CZVmouseButtonPressedEvent(ZVint button)
			: CZVmouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_iButton;
			return (ss.str());
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class ZV_API CZVmouseButtonReleasedEvent final : public CZVmouseButtonEvent
	{
	public:
		CZVmouseButtonReleasedEvent(ZVint button)
			: CZVmouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_iButton;
			return (ss.str());
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};

} // namespace Normal

#endif /*__ZV_MOUSEEVENT_H__*/
