#include "ZVsystem.h"
#include "ZVwindow.h"
#include "ZVTimer.h"

namespace ZVLab {

	bool CzvSystem::s_bIsRunApplication = true;

	void CzvSystem::ExitApp()
	{
		s_bIsRunApplication = false;
	}

	CzvSystem::CzvSystem()
		: m_bInitialized(false)
		, m_bActivateResize(false)
		, m_upWindow(nullptr)
		, m_upLayerBuffer(nullptr)
	{}

	CzvSystem::~CzvSystem()
	{
		this->Shutdown();
	}

	void CzvSystem::Initialize(const TzvApplicationSpecification& spec)
	{
		DZVLog_Failed((spec.uiWidth > 0), "FAILED: Window width size must be greater than 0. \"{0}\"", spec.uiWidth);
		DZVLog_Failed((spec.uiHeight > 0), "FAILED: Window height size must be greater than 0. \"{0}\"", spec.uiHeight);
		m_bInitialized = true;
		// Generated a Window
		m_upWindow = CzvWindow::Create(spec.strName, spec.uiWidth, spec.uiHeight);
		m_upWindow->Initialize();
		// Generated a LayerBuffer
		m_upLayerBuffer = CzvLayerBuffer::Create();
		// Init ImGui
		CzvImguiManager::Initialize(m_upWindow, true);
		// Set Callback
		m_upWindow->SetEventCallback(DBindEventFunction(CzvSystem::OnEvent));


		// TODO: 폰트 기능 리팩토링 및 수정 필요
		// Set Font
		// CzvImguiManager::UploadFont("..\\..\\Resources\\Fonts\\OpenSans_Condensed-Regular.ttf", "OpenSans-Regular", 20);

		// Graphic icon
		ImGuiIO& io = ImGui::GetIO();
		io.Fonts->AddFontDefault();

		// test dialog
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
			GLuint texID = (GLuint)tex;
			glDeleteTextures(1, &texID);
		};

	}

	void CzvSystem::Shutdown()
	{
		// Destroyed window
		m_upWindow->Shutdown();
		// Destroyed a LayerBuffer
		m_upLayerBuffer->Shutdown();
		// Destroyed ImGui
		CzvImguiManager::Shutdown();
		// off flag
		m_bInitialized = false;
	}

	void CzvSystem::Run()
	{
		DZVLog_Failed(m_bInitialized, "FAILED: CzvSystem is not initialized!");

		while (s_bIsRunApplication != false)
		{
			m_upWindow->PollEvents();
			if (s_bIsRunApplication == false)
			{ // 윈도우 종료시 루프 X
				break;
			}

			if (m_bActivateResize)
			{ // 윈도우 사이즈를 변경중일 때는 루프 X
				this->PauseWindowResize(&m_bActivateResize);
			}

			{ //Set a Refresh Rate
				for (auto& layer : *m_upLayerBuffer)
				{
					layer->OnUpdate(0.0);
				}
			}

			CzvImguiManager::Begin(m_upWindow);
			// ImFont* font = CzvImguiManager::GetFont("OpenSans-Regular");
			// ImGui::PushFont(font);
			{ // ImGui_Layer
				if (CzvImguiManager::BeginMainMenu())
				{
					for (auto& layer : *m_upLayerBuffer)
					{
						layer->OnMainMenuBar();
					}
					CzvImguiManager::EndMainMenu();
				}
				if (s_bIsRunApplication == false)
				{
					break;
				}

				for (auto& layer : *m_upLayerBuffer)
				{
					layer->OnGUI();
				}
				if (s_bIsRunApplication == false)
				{
					CzvImguiManager::End();
					break;
				}
				// CZVimguiManager::ShowDemo();
			}

			// ImGui::PopFont();
			DProfile_Execute
				CzvImguiManager::End();

			m_upWindow->Clear();
		}
	}

	void CzvSystem::AttachLayer(CzvLayer* layer)
	{
		DZVLog_Failed(layer, "FAILED: Layer pointer is NULL!");
		m_upLayerBuffer->InsertLayer(layer);
	}

	void CzvSystem::DetachLayer(CzvLayer* layer)
	{
		DZVLog_Failed(layer, "FAILED: Layer pointer is NULL!");
		m_upLayerBuffer->RemoveLayer(layer);
	}

	void CzvSystem::AttachOverlay(CzvLayer* layer)
	{
		DZVLog_Failed(layer, "FAILED: Layer pointer is NULL!");
		m_upLayerBuffer->InsertOverlay(layer);
	}

	void CzvSystem::DetachOverlay(CzvLayer* layer)
	{
		DZVLog_Failed(layer, "FAILED: Layer pointer is NULL!");
		m_upLayerBuffer->RemoveOverlay(layer);
	}

	void CzvSystem::OnEvent(CzvEvent& event)
	{
		CZVeventDispatcher ed(event);
		switch (event.GetEventType())
		{
		case EzvEventType::WindowResize:
			ed.Dispatch<CzvWindowResizeEvent>(DBindEventFunction(ZVLab::CzvSystem::WindowResize));
			return;
		case EzvEventType::WindowClose:
			ed.Dispatch<CzvWindowCloseEvent>(DBindEventFunction(ZVLab::CzvSystem::WindowClose));
			return;
		}

		{ // toss Event
			for (auto& layer : *m_upLayerBuffer)
			{
				layer->OnEvent(event);
				if (event.bHandled)
					return;
			}
		}
	}

	ZVbool CzvSystem::WindowResize(CzvWindowResizeEvent& event)
	{
		m_bActivateResize = true;
		return (true);
	}

	ZVbool CzvSystem::WindowClose(CzvWindowCloseEvent& event)
	{
		CzvSystem::ExitApp();
		return (true);
	}

	void CzvSystem::PauseWindowResize(ZVbool* flags)
	{
		m_upWindow->Clear();
		(*flags) = false;
	}


} // namespace ZVLab
