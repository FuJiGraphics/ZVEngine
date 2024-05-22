#ifndef __ZV_MOUSEEVENT_H__
#define __ZV_MOUSEEVENT_H__
#pragma once

#include "ZVEvent.h"

#include <sstream>

namespace ZVLab {

	class ZV_API CzvMouseMovedEvent final : public CzvEvent
	{
	private:
		ZVfloat m_fMouseX, m_fMouseY;

	public:
		CzvMouseMovedEvent(ZVfloat x, ZVfloat y)
			: m_fMouseX(x), m_fMouseY(y) {}

		inline ZVfloat GetX() const { return (m_fMouseX); }
		inline ZVfloat GetY() const { return (m_fMouseY); }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_fMouseX << ", " << m_fMouseY;
			return (ss.str());
		}

		DEventClassType(MouseMoved)
		DEventClassCategory(ezvEventCategory_Mouse | ezvEventCategory_Input)
	};

	class ZV_API CzvMouseScrolledEvent final : public CzvEvent
	{
	private:
		ZVfloat m_fXOffset, m_fYOffset;

	public:
		CzvMouseScrolledEvent(ZVfloat xOffset, ZVfloat yOffset)
			: m_fXOffset(xOffset), m_fYOffset(yOffset) {}

		inline ZVfloat GetXOffset() const { return (m_fXOffset); }
		inline ZVfloat GetYOffset() const { return (m_fYOffset); }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
			return (ss.str());
		}

		DEventClassType(MouseScrolled)
		DEventClassCategory(ezvEventCategory_Mouse | ezvEventCategory_Input)
	};

	class ZV_API CzvMouseButtonEvent : public CzvEvent
	{
	protected:
		ZVint m_iButton;

	protected:
		CzvMouseButtonEvent(ZVint button)
			: m_iButton(button) {}

	public:
		inline ZVint GetMouseButton() const { return (m_iButton); }

		DEventClassCategory(ezvEventCategory_Mouse | ezvEventCategory_Input)
	};

	class ZV_API CzvMouseButtonPressedEvent final : public CzvMouseButtonEvent
	{
	public:
		CzvMouseButtonPressedEvent(ZVint button)
			: CzvMouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_iButton;
			return (ss.str());
		}

		DEventClassType(MouseButtonPressed)
	};

	class ZV_API CzvMouseButtonReleasedEvent final : public CzvMouseButtonEvent
	{
	public:
		CzvMouseButtonReleasedEvent(ZVint button)
			: CzvMouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_iButton;
			return (ss.str());
		}

		DEventClassType(MouseButtonReleased)
	};

} // namespace Normal

#endif /*__ZV_MOUSEEVENT_H__*/
