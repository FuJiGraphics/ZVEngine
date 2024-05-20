#include "ZVImguiManager.h"
#include "ZVImguiTheme.h"
//imgui
#include <stdio.h>

void StyleColorsSpectrum() {
	ImGuiStyle* style = &ImGui::GetStyle();
	style->GrabRounding = 4.0f;


}

void glfw_error_callback(int error, const char * description) {

}

namespace ZVLab {

	bool CzvImguiManager::s_bEnabledImplot = false;
	bool CzvImguiManager::s_bEnableOverviewDockspace = true;
	std::unordered_map<std::string, ImFont*> CzvImguiManager::s_mapFonts;

	void CzvImguiManager::Initialize(const Unique<CzvWindow>& window, UsageExtensionsFlags flags)
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

		// ImFileDialog requires you to set the CreateTexture and DeleteTexture
		ifd::FileDialog::Instance().CreateTexture = [](uint8_t* data, int w, int h, char fmt) -> void* {
			GLuint tex;

			glGenTextures(1, &tex);
			glBindTexture(GL_TEXTURE_2D, tex);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, (fmt == 0) ? GL_BGRA : GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, 0);

			return (void*)tex;
		};
		ifd::FileDialog::Instance().DeleteTexture = [](void* tex) {
			GLuint texID = (GLuint)((uintptr_t)tex);
			glDeleteTextures(1, &texID);
		};
	}

	void CzvImguiManager::Shutdown()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		if (s_bEnabledImplot)
			ImPlot::DestroyContext();
		ImGui::DestroyContext();
	}

	void CzvImguiManager::Begin(const Unique<CzvWindow>& window)
	{
		if (!glfwWindowShouldClose(window->GetNativeWindow()))
		{
			// Start the Dear ImGui frame
			ImGui_ImplOpenGL3_NewFrame();
			ImGui_ImplGlfw_NewFrame();
			ImGui::NewFrame();
			if (s_bEnableOverviewDockspace)
			{
				ImGui::DockSpaceOverViewport((const ImGuiViewport*)0);
			}
		}
	}

	void CzvImguiManager::End()
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

	bool CzvImguiManager::BeginMainMenu()
	{
		return (ImGui::BeginMainMenuBar());
	}

	void CzvImguiManager::EndMainMenu()
	{
		ImGui::EndMainMenuBar();
	}

	void ZVLab::CzvImguiManager::ShowDemo()
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

	void CzvImguiManager::SetOverviewDockspace(bool enabled, const TzvDockspaceInfo& options)
	{
		s_bEnableOverviewDockspace = enabled;
	}

	void CzvImguiManager::SetDockspace(const CzvDialog& dialog, const ImVec2& size, const TzvDockspaceInfo& options)
	{
		std::string dialogLabel = dialog.GetLabel();
		auto id = ImGui::GetID(dialogLabel.c_str());
		ImGui::DockSpace(id, size, options.GetOptions());
	}

	void CzvImguiManager::SetDockspaceOptionForNextDialog(ImGuiDockNodeFlags options)
	{
		ImGuiWindowClass window_class;
		window_class.DockNodeFlagsOverrideSet = options;
		ImGui::SetNextWindowClass(&window_class);
	}

	bool CzvImguiManager::UploadFont(const std::string& path, const std::string& fontName, float size_pixels, ImFontConfig* config, const ImWchar* glyph_ranges)
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

	ImFont* CzvImguiManager::GetFont(const std::string& fontName)
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
