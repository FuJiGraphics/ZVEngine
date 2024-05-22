#ifndef __ZV_ZVEVENT_H__
#define __ZV_ZVEVENT_H__
#pragma once

#include "../core/Core.h"

#include <string>
#include <functional>

namespace ZVLab {

#define DBit(x) ( 1 << x )
#define DBindEventFunction(x) std::bind( &x, this, std::placeholders::_1 )
#define DBindNoArgsEventFunction(x) std::bind( &x, this )

	enum class EzvEventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EzvEventCategory
	{
		ezvEventCategory_None = 0,
		ezvEventCategory_Application	= DBit(0),
		ezvEventCategory_Input			= DBit(1),
		ezvEventCategory_Keyboard		= DBit(2),
		ezvEventCategory_Mouse			= DBit(3),
		ezvEventCategory_MouseButton	= DBit(4)
	};

#define DEventClassType(type) static EzvEventType GetStaticType() { return (EzvEventType::##type); }\
							   virtual EzvEventType GetEventType() const override { return (GetStaticType()); }\
							   virtual const char* GetName() const override { return (#type); }

#define DEventClassCategory(category) virtual int GetCategoryFlags() const override { return (category); }

	class ZV_API CzvEvent
	{
		friend class CzvEventDispatcher;
	public:
		ZVbool bHandled = false;

	public:
		virtual EzvEventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return (GetName()); }

		inline ZVbool IsInCategory(EzvEventCategory category)
		{
			return (GetCategoryFlags() & category);
		}
	};

	class CzvEventDispatcher
	{
		template<typename T>
		using EventFn = std::function<ZVbool(T&)>;

	private:
		CzvEvent& m_Event;

	public:
		CzvEventDispatcher(CzvEvent& event)
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

	inline std::ostream& operator<<(std::ostream& os, const CzvEvent& e)
	{
		return (os << e.ToString());
	}


} // namespace ZVLab

#endif /*__ZV_ZVEVENT_H__*/
