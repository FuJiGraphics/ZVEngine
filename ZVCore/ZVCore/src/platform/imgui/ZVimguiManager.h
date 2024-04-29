#ifndef __ZV_ZVIMGUI_H__
#define __ZV_ZVIMGUI_H__
#pragma once

#include "../../core/Core.h"
#include "../../core/ZVwindow.h"


static void glfw_error_callback(int error, const char* description);

namespace ZVLab {

	// forwards
	class CzvWindow;

	class ZV_API CZVimguiManager
	{
	public:
		static void Initialize(const Unique<CzvWindow>& window);
		static void Shutdown();
		static void Begin(const Unique<CzvWindow>& window);
		static void End();
		static bool BeginMainMenu();
		static void EndMainMenu();
		static void ShowDemo();
		static void SetOverviewDockspace(bool enable);
		static bool EnabledOverviewDockspace();

	public:
		static bool UploadFont(const std::string& path, const std::string& fontName, float size_pixels, ImFontConfig* config = nullptr, const ImWchar* glyph_ranges = nullptr);
		static ImFont* GetFont(const std::string& fontName);

	private:
		static bool s_bEnableOverviewDockspace;
		static std::unordered_map<std::string, ImFont*> s_mapFonts;
	};

} // namespace ZVLab

#endif /*__ZV_ZVIMGUI_H__*/
