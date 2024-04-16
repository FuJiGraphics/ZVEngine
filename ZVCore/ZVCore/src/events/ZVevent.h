#ifndef __ZV_ZVEVENT_H__
#define __ZV_ZVEVENT_H__
#pragma once

#include "../core/Core.h"

#include <string>
#include <functional>

namespace ZVLab {

#define BIT(x) ( 1 << x )
#define BIND_EVENT_FUNC(x) std::bind( &x, this, std::placeholders::_1 )
#define BIND_NOARGS_FUNC(x) std::bind( &x, this )

	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication	= BIT(0),
		EventCategoryInput			= BIT(1),
		EventCategoryKeyboard		= BIT(2),
		EventCategoryMouse			= BIT(3),
		EventCategoryMouseButton	= BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return (EventType::##type); }\
							   virtual EventType GetEventType() const override { return (GetStaticType()); }\
							   virtual const char* GetName() const override { return (#type); }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return (category); }

	class ZV_API CZVevent
	{
		friend class CZVeventDispatcher;
	public:
		ZVbool bHandled = false;

	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return (GetName()); }

		inline ZVbool IsInCategory(EventCategory category)
		{
			return (GetCategoryFlags() & category);
		}
	};

	class CZVeventDispatcher
	{
		template<typename T>
		using EventFn = std::function<ZVbool(T&)>;

	private:
		CZVevent& m_Event;

	public:
		CZVeventDispatcher(CZVevent& event)
			: m_Event(event)
		{/*Empty*/}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.bHandled = func(*(T*)&m_Event);
				return (true);
			}
			return (false);
		}
	};

	inline std::ostream& operator<<(std::ostream& os, const CZVevent& e)
	{
		return (os << e.ToString());
	}


} // namespace ZVLab

#endif /*__ZV_ZVEVENT_H__*/
