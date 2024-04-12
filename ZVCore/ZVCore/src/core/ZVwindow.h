#ifndef __ZV_ZVWINDOW_H__
#define __ZV_ZVWINDOW_H__
#pragma once

#include "Core.h"
#include "events/ZVevent.h"

// Forwards
class GLFWwindow;

namespace ZVLab {

	class ZV_API CZVwindow
	{
	public:
		using EventCallbackFn = std::function<void(CZVevent&)>;

		struct WindowChunk {
			std::string			Title;
			ZVuint				Width;
			ZVuint				Height;
			bool				VSync;
			EventCallbackFn		Callback;
		};

	public:
		static Unique<CZVwindow> Create(const std::string& name, ZVuint width, ZVuint height);

	public:
		virtual GLFWwindow*		GetNativeWindow() const = 0;
		virtual ZVuint			GetWidth() const = 0;
		virtual ZVuint			GetHeight() const = 0;
		virtual void			SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void			Initialize() = 0;
		virtual void			Shutdown() = 0;
		virtual void			PollEvents() = 0;
		virtual void			Clear() = 0;
	};

} // namespace ZVLab

#endif /*__ZV_ZVWINDOWS_H__*/
