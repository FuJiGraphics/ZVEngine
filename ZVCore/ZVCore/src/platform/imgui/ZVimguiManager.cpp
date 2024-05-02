#include "ZVimguiManager.h"
#include "ZVImguiTheme.h"
#include "fonts/IconsLucide.h"
//imgui
#include <stdio.h>

void StyleColorsSpectrum() {
	ImGuiStyle* style = &ImGui::GetStyle();
	style->GrabRounding = 4.0f;


}

void glfw_error_callback(int error, const char * description) {

}

namespace ZVLab {

	bool CZVimguiManager::s_bEnabledImplot = false;
	bool CZVimguiManager::s_bEnableOverviewDockspace = true;
	std::unordered_map<std::string, ImFont*> CZVimguiManager::s_mapFonts;

	void CZVimguiManager::Initialize(const Unique<CzvWindow>& window, UsageExtensionsFlags flags)
	{
		const char* glsl_version = "#version 130";

		// Setup Dear ImGui context
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		if (flags )
			ImPlot::CreateContext();
			
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // Enable Docking
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;       // Enable Multi-Viewport / Platform Windows
		// Setup Dear ImGui style
		// ImGui::StyleColorsDark();
		ImGui::StyleColorsLight();

		//ImGui::Spectrum::StyleColorsSpectrum();
		//io.Fonts->AddFontDefault();

		// Setup Platform/Renderer backends
		ImGui_ImplGlfw_InitForOpenGL(window->GetNativeWindow(), true);
		ImGui_ImplOpenGL3_Init(glsl_version);
	}

	void CZVimguiManager::Shutdown()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		if (s_bEnabledImplot)
			ImPlot::DestroyContext();
		ImGui::DestroyContext();
	}

	void CZVimguiManager::Begin(const Unique<CzvWindow>& window)
	{
		if (!glfwWindowShouldClose(window->GetNativeWindow()))
		{
			// Start the Dear ImGui frame
			ImGui_ImplOpenGL3_NewFrame();
			ImGui_ImplGlfw_NewFrame();
			ImGui::NewFrame();
			if (s_bEnableOverviewDockspace)
			{
				ImGui::DockSpaceOverViewport();
			}
		}
	}

	void CZVimguiManager::End()
	{
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			GLFWwindow* backup_current_context = glfwGetCurrentContext();
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
			glfwMakeContextCurrent(backup_current_context);
		}
	}

	bool CZVimguiManager::BeginMainMenu()
	{
		return (ImGui::BeginMainMenuBar());
	}

	void CZVimguiManager::EndMainMenu()
	{
		ImGui::EndMainMenuBar();
	}

	void ZVLab::CZVimguiManager::ShowDemo()
	{
		bool show_demo_window = true;
		bool show_another_window = true;
		ImGui::ShowDemoWindow(&show_demo_window);
		static float f = 0.0f;
		static int counter = 0;

		ImGuiIO& io = ImGui::GetIO(); (void)io;

		ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

		ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
		ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
		ImGui::Checkbox("Another Window", &show_another_window);

		ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f

		if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
			counter++;
		ImGui::SameLine();
		ImGui::Text("counter = %d", counter);

		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
		ImGui::End();

		ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
		ImGui::Text("Hello from another window!");
		if (ImGui::Button("Close Me"))
			show_another_window = false;
		ImGui::End();
	}

	void CZVimguiManager::SetOverviewDockspace(bool enable)
	{
		s_bEnableOverviewDockspace = enable;
	}

	bool CZVimguiManager::EnabledOverviewDockspace()
	{
		return (s_bEnableOverviewDockspace);
	}

	bool CZVimguiManager::UploadFont(const std::string& path, 
									 const std::string& fontName, 
									 float size_pixels, 
									 ImFontConfig* config,
									 const ImWchar* glyph_ranges)
	{
		if (s_mapFonts.find(fontName) != s_mapFonts.end())
		{
			DZVLog_Failed(false, "FAILED: Already uploaded font!");
			return (false);
		}
		auto io = ImGui::GetIO();

		ImFont* font = nullptr;
		if (config == nullptr && glyph_ranges == nullptr)
			font = io.Fonts->AddFontFromFileTTF(path.c_str(), size_pixels);
		else if (config != nullptr && glyph_ranges == nullptr)
			font = io.Fonts->AddFontFromFileTTF(path.c_str(), size_pixels, config);
		else if (config != nullptr && glyph_ranges != nullptr)
			font = io.Fonts->AddFontFromFileTTF(path.c_str(), size_pixels, config, glyph_ranges);

		if (font == nullptr)
		{
			DZVLog_Failed(font, "FAILED: Unexpected Error! font is null!!");
			return (false);
		}
		s_mapFonts.insert({ fontName, font });
		return (true);
	}

	ImFont* CZVimguiManager::GetFont(const std::string& fontName)
	{
		if (s_mapFonts.find(fontName) == s_mapFonts.end())
		{
			DZVLog_Failed(false, "FAILED: Did not found font!");
			return (false);
		}
		ImFont* font = s_mapFonts[fontName];
		DZVLog_Failed(font, "FAILED: ImFont* font is null!");
		return (font);
	}

} // namespace ZVLab
