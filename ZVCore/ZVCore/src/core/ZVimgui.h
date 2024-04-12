#ifndef __ZV_ZVIMGUI_H__
#define __ZV_ZVIMGUI_H__
#pragma once

#include "Core.h"
#include "ZVwindow.h"


static void glfw_error_callback(int error, const char* description);

namespace ZVLab {

	// forwards
	class CZVwindow;

	class ZV_API CZVimguiManager
	{
	public:
		static void Initialize(const Unique<CZVwindow>& window);
		static void Shutdown();
		static void Begin(const Unique<CZVwindow>& window);
		static void End(const Unique<CZVwindow>& window);
		static void ShowDemo();
	};

} // namespace ZVLab

#endif /*__ZV_ZVIMGUI_H__*/
