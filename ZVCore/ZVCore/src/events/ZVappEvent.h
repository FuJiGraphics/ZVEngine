#ifndef __ZV_ZVWINDOWRESIZEEVENT_H__
#define __ZV_ZVWINDOWRESIZEEVENT_H__
#pragma once

#include "ZVevent.h"

namespace ZVLab {

	class ZV_API CZVwindowResizeEvent final : public CZVevent
	{
	private:
		ZVint m_iWidth, m_iHeight;
	public:
		CZVwindowResizeEvent(ZVint width, ZVint height)
			: m_iWidth(width), m_iHeight(height) {}

		inline ZVint GetWidth() const { return (m_iWidth); }
		inline ZVint GetHeight() const { return (m_iHeight); }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_iWidth << ", " << m_iHeight;
			return (ss.str());
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class ZV_API CZVwindowCloseEvent final : public CZVevent
	{
	public:
		CZVwindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class ZV_API CZVappTickEvent final : public CZVevent
	{
	public:
		CZVappTickEvent() {}

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class ZV_API CZVappUpdateEvent final : public CZVevent
	{
	public:
		CZVappUpdateEvent() {}

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class ZV_API CZVappRenderEvent final : public CZVevent
	{
	public:
		CZVappRenderEvent() {}

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};


} // namespace ZVLab

#endif /*__ZV_ZVWINDOWRESIZEEVENT_H__*/
