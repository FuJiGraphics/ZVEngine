#ifndef __ZV_ZVIMGUI_H__
#define __ZV_ZVIMGUI_H__
#pragma once

#include "ZVCore.h"

static void glfw_error_callback(int error, const char* description);

namespace ZVLab {

	class ZV_API CZVimguiManager
	{
		enum EzvUsageExtensions
		{
			eUsageActivateImPlot = (1 << 0),
		};
		using UsageExtensionsFlags = int;

	public:
		static void Initialize(HWND hwnd, int w, int h, UsageExtensionsFlags flags);
		static void Shutdown();
		static void Begin();
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
		static bool s_bEnabledImplot;
		static bool s_bEnableOverviewDockspace;
		static std::unordered_map<std::string, ImFont*> s_mapFonts;
		static GLFWwindow* pWindow;
	};

} // namespace ZVLab

#endif /*__ZV_ZVIMGUI_H__*/
