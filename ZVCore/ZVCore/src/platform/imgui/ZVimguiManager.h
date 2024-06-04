#ifndef __ZV_ZVIMGUI_H__
#define __ZV_ZVIMGUI_H__
#pragma once

#include "../../core/Core.h"
#include "../../core/ZVwindow.h"
#include "export/ZVGuiConfig.h"
#include "export/ZVDialog.h"

static void glfw_error_callback(int error, const char* description);

namespace ZVLab {

	// forwards
	class CzvWindow;

	class ZV_API CzvImguiManager
	{
		enum EzvUsageExtensions
		{
			eUsageActivateImPlot = (1 << 0),
		};
		using UsageExtensionsFlags = int;

	//// Member Variables
	private:
		static bool						s_bEnabledImplot;
		static bool						s_bEnableOverviewDockspace;
		static unsigned long			s_ulItemStackIDs;
		static std::unordered_map<std::string, ImFont*> s_mapFonts;

	//// Member Functions
	public:
		static void				Initialize(const Unique<CzvWindow>& window, UsageExtensionsFlags flags);
		static void				Shutdown();
		static void				Begin(const Unique<CzvWindow>& window);
		static void				End();
		static bool				BeginMainMenu();
		static void				EndMainMenu();
		static void				ShowDemo();
		static void				SetOverviewDockspace(bool enabled, const TzvDockspaceInfo& options = TzvDockspaceInfo());
		static void				SetDockspace(const CzvDialog& dialog, const ImVec2& size = { 0, 0 }, const TzvDockspaceInfo& options = TzvDockspaceInfo());
		static void				SetDockspaceOptionForNextDialog(ImGuiDockNodeFlags options = 0);
		static bool				UploadFont(const std::string& path, const std::string& fontName, float size_pixels, ImFontConfig* config = nullptr, const ImWchar* glyph_ranges = nullptr);
		static ImFont*			GetFont(const std::string& fontName);
		static void				PushID();
		static void				PopID();
		static void				BeginGroupPanel(const char* name, const ImVec2& size);
		static void				EndGroupPanel();


	};

} // namespace ZVLab

#endif /*__ZV_ZVIMGUI_H__*/
