#ifndef __ZV_ZVWINDOW_H__
#define __ZV_ZVWINDOW_H__
#pragma once

#include "Core.h"
#include "../events/ZVevent.h"

// Forwards
struct GLFWwindow;

namespace ZVLab {

	class ZV_API CzvWindow
	{
	public:
		using EventCallbackFn = std::function<void(CzvEvent&)>;

		struct TzvWindowChunk {
			std::string			strTitle;
			ZVuint				uiWidth;
			ZVuint				uiHeight;
			bool				bVSync;
			EventCallbackFn		cbCallback;
		};

	public:
		static Unique<CzvWindow> Create(const std::string& name, ZVuint width, ZVuint height);

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
