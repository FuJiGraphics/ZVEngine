#ifndef __ZV_ZVIMGUI_H__
#define __ZV_ZVIMGUI_H__
#pragma once

#include "../../core/Core.h"
#include "../../core/ZVwindow.h"


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
		static void End();
		static void ShowDemo();
	};

} // namespace ZVLab

#endif /*__ZV_ZVIMGUI_H__*/
