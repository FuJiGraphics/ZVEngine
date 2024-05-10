#ifndef __ZV_ZVWINDOWRESIZEEVENT_H__
#define __ZV_ZVWINDOWRESIZEEVENT_H__
#pragma once

#include "ZVevent.h"

namespace ZVLab {

	class ZV_API CzvWindowResizeEvent final : public CzvEvent
	{
	private:
		ZVint m_iWidth, m_iHeight;
	public:
		CzvWindowResizeEvent(ZVint width, ZVint height)
			: m_iWidth(width), m_iHeight(height) {}

		inline ZVint GetWidth() const { return (m_iWidth); }
		inline ZVint GetHeight() const { return (m_iHeight); }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_iWidth << ", " << m_iHeight;
			return (ss.str());
		}

		DEventClassType(WindowResize)
		DEventClassCategory(ezvEventCategory_Application)
	};

	class ZV_API CzvWindowCloseEvent final : public CzvEvent
	{
	public:
		CzvWindowCloseEvent() {}

		DEventClassType(WindowClose)
		DEventClassCategory(ezvEventCategory_Application)
	};

	class ZV_API CzvAppTickEvent final : public CzvEvent
	{
	public:
		CzvAppTickEvent() {}

		DEventClassType(AppTick)
		DEventClassCategory(ezvEventCategory_Application)
	};

	class ZV_API CzvAppUpdateEvent final : public CzvEvent
	{
	public:
		CzvAppUpdateEvent() {}

		DEventClassType(AppUpdate)
		DEventClassCategory(ezvEventCategory_Application)
	};

	class ZV_API CzvAppRenderEvent final : public CzvEvent
	{
	public:
		CzvAppRenderEvent() {}

		DEventClassType(AppRender)
		DEventClassCategory(ezvEventCategory_Application)
	};


} // namespace ZVLab

#endif /*__ZV_ZVWINDOWRESIZEEVENT_H__*/
