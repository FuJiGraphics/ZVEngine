#include "ZVsystem.h"
#include "ZVwindow.h"
#include "ZVTimer.h"

namespace ZVLab {

	CzvSystem::CzvSystem(const TzvApplicationSpecification& spec)
		: m_bIsRun(false)
		, m_bInitialized(false)
		, m_bActivateResize(false)
		, m_upWindow(nullptr)
		, m_upLayerBuffer(nullptr)
	{
		this->Initialize(spec);
	}

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
		CZVimguiManager::Initialize(m_upWindow, true);
		// Set Callback
		m_upWindow->SetEventCallback(DBindEventFunction(CzvSystem::OnEvent));


		// TODO: 폰트 기능 리팩토링 및 수정 필요
		// Set Font
		CZVimguiManager::UploadFont("..\\..\\Resources\\Fonts\\OpenSans_Condensed-Regular.ttf", "OpenSans-Regular", 20);

		// Graphic icon
		ImGuiIO& io = ImGui::GetIO();
		io.Fonts->AddFontDefault();
	}

	void CzvSystem::Shutdown()
	{
		// Destroyed window
		m_upWindow->Shutdown();
		// Destroyed a LayerBuffer
		m_upLayerBuffer->Shutdown();
		// Destroyed ImGui
		CZVimguiManager::Shutdown();
		// off flag
		m_bInitialized = false;
	}

	void CzvSystem::Run()
	{
		DZVLog_Failed(m_bInitialized, "FAILED: CzvSystem is not initialized!");

		m_bIsRun = true;
		while (m_bIsRun)
		{
			m_upWindow->PollEvents();
			if (m_bIsRun == false)
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
			
			CZVimguiManager::Begin(m_upWindow);
			ImFont* font = CZVimguiManager::GetFont("OpenSans-Regular");
			ImGui::PushFont(font);
			{ // ImGui_Layer
				DProfile_StartRecord("OnMainMenuBar")
				if (CZVimguiManager::BeginMainMenu())
				{
					for (auto& layer : *m_upLayerBuffer)
					{
						layer->OnMainMenuBar();
					}
					CZVimguiManager::EndMainMenu();
				}
				DProfile_EndRecord

				DProfile_StartRecord("OnGui")
				for (auto& layer : *m_upLayerBuffer)
				{
					layer->OnGUI();
				}
				// CZVimguiManager::ShowDemo();
				DProfile_EndRecord
			}
			ImGui::PopFont();
			DProfile_Execute
			CZVimguiManager::End();

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
		m_bIsRun = false;
		return (true);
	}

	void CzvSystem::PauseWindowResize(ZVbool* flags)
	{
		m_upWindow->Clear();
		(*flags) = false;
	}


} // namespace ZVLab
