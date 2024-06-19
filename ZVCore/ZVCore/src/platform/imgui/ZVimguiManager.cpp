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
	unsigned long CzvImguiManager::s_ulItemStackIDs = 0;

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
		ImGui::StyleColorsDark();
		// ImGui::StyleColorsLight();

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
		s_ulItemStackIDs = 0;
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
		s_ulItemStackIDs = 0;
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

	void CzvImguiManager::PushID()
	{
		ImGui::PushID(s_ulItemStackIDs);
		s_ulItemStackIDs++;
	}

	void CzvImguiManager::PopID()
	{
		ImGui::PopID();
	}

	// cf https://github.com/ocornut/imgui/issues/1496#issuecomment-655048353
	static ImVector<ImRect> s_GroupPanelLabelStack;
	void CzvImguiManager::BeginGroupPanel(const char* name, const ImVec2& size)
	{
		ImGui::BeginGroup();

		auto itemSpacing = ImGui::GetStyle().ItemSpacing;
		ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0.0f, 0.0f));
		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0.0f, 0.0f));

		auto frameHeight = ImGui::GetFrameHeight();
		ImGui::BeginGroup();

		ImVec2 effectiveSize = size;
		if (size.x < 0.0f)
			effectiveSize.x = ImGui::GetWindowWidth();
		else
			effectiveSize.x = size.x;

		ImGui::Dummy(ImVec2(effectiveSize.x, 0.0f));

		ImGui::Dummy(ImVec2(frameHeight * 0.5f, 0.0f));
		ImGui::SameLine(0.0f, 0.0f);
		ImGui::BeginGroup();
		ImGui::Dummy(ImVec2(frameHeight * 0.5f, 0.0f));
		ImGui::SameLine(0.0f, 0.0f);
		if (strlen(name) > 0)
			ImGui::TextUnformatted(name);

		auto labelMin = ImGui::GetItemRectMin();
		auto labelMax = ImGui::GetItemRectMax();
		ImGui::SameLine(0.0f, 0.0f);
		ImGui::Dummy(ImVec2(0.0, frameHeight + itemSpacing.y * (size.y > 0.0f) ? size.y : 1.0f));
		ImGui::BeginGroup();

		// ImGui::GetWindowDrawList()->AddRect(labelMin, labelMax, IM_COL32(255, 0, 255, 255));

		ImGui::PopStyleVar(2);

#if IMGUI_VERSION_NUM >= 17301
		ImGui::GetCurrentWindow()->ContentRegionRect.Max.x -= frameHeight * 0.5f;
		ImGui::GetCurrentWindow()->WorkRect.Max.x -= frameHeight * 0.5f;
		ImGui::GetCurrentWindow()->InnerRect.Max.x -= frameHeight * 0.5f;
#else
		ImGui::GetCurrentWindow()->ContentsRegionRect.Max.x -= frameHeight * 0.5f;
#endif
		ImGui::GetCurrentWindow()->Size.x -= frameHeight;

		auto itemWidth = ImGui::CalcItemWidth();
		ImGui::PushItemWidth(ImMax(0.0f, itemWidth - frameHeight));

		s_GroupPanelLabelStack.push_back(ImRect(labelMin, labelMax));
	}

	void CzvImguiManager::EndGroupPanel()
	{
		ImGui::PopItemWidth();

		auto itemSpacing = ImGui::GetStyle().ItemSpacing;

		ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0.0f, 0.0f));
		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0.0f, 0.0f));

		auto frameHeight = ImGui::GetFrameHeight();

		ImGui::EndGroup();

		//ImGui::GetWindowDrawList()->AddRectFilled(ImGui::GetItemRectMin(), ImGui::GetItemRectMax(), IM_COL32(0, 255, 0, 64), 4.0f);

		ImGui::EndGroup();

		ImGui::SameLine(0.0f, 0.0f);
		ImGui::Dummy(ImVec2(frameHeight * 0.5f, 0.0f));
		ImGui::Dummy(ImVec2(0.0, frameHeight - frameHeight * 0.5f - itemSpacing.y));

		ImGui::EndGroup();

		auto itemMin = ImGui::GetItemRectMin();
		auto itemMax = ImGui::GetItemRectMax();
		//ImGui::GetWindowDrawList()->AddRectFilled(itemMin, itemMax, IM_COL32(255, 0, 0, 64), 4.0f);

		auto labelRect = s_GroupPanelLabelStack.back();
		s_GroupPanelLabelStack.pop_back();

		ImVec2 halfFrame = ImVec2(frameHeight * 0.25f * 0.5f, frameHeight * 0.5f);
		ImRect frameRect = ImRect(ImVec2(itemMin.x + halfFrame.x, itemMin.y + halfFrame.y), ImVec2(itemMax.x - halfFrame.x, itemMax.y));
		labelRect.Min.x -= itemSpacing.x;
		labelRect.Max.x += itemSpacing.x;

		for (int i = 0; i < 4; ++i)
		{
			switch (i)
			{
				// left half-plane
			case 0: ImGui::PushClipRect(ImVec2(-FLT_MAX, -FLT_MAX), ImVec2(labelRect.Min.x, FLT_MAX), true); break;
				// right half-plane
			case 1: ImGui::PushClipRect(ImVec2(labelRect.Max.x, -FLT_MAX), ImVec2(FLT_MAX, FLT_MAX), true); break;
				// top
			case 2: ImGui::PushClipRect(ImVec2(labelRect.Min.x, -FLT_MAX), ImVec2(labelRect.Max.x, labelRect.Min.y), true); break;
				// bottom
			case 3: ImGui::PushClipRect(ImVec2(labelRect.Min.x, labelRect.Max.y), ImVec2(labelRect.Max.x, FLT_MAX), true); break;
			}

			ImGui::GetWindowDrawList()->AddRect(
				frameRect.Min, frameRect.Max,
				ImColor(ImGui::GetStyleColorVec4(ImGuiCol_Border)),
				halfFrame.x);

			ImGui::PopClipRect();
		}

		ImGui::PopStyleVar(2);

#if IMGUI_VERSION_NUM >= 17301
		ImGui::GetCurrentWindow()->ContentRegionRect.Max.x += frameHeight * 0.5f;
		ImGui::GetCurrentWindow()->WorkRect.Max.x += frameHeight * 0.5f;
		ImGui::GetCurrentWindow()->InnerRect.Max.x += frameHeight * 0.5f;
#else
		ImGui::GetCurrentWindow()->ContentsRegionRect.Max.x += frameHeight * 0.5f;
#endif
		ImGui::GetCurrentWindow()->Size.x += frameHeight;

		ImGui::Dummy(ImVec2(0.0f, 0.0f));

		ImGui::EndGroup();
	}


} // namespace ZVLab
