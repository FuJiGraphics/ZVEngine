#include "ZVsystem.h"
#include "ZVwindow.h"

namespace ZVLab {

	CZVsystem::CZVsystem(const TApplicationSpecification& spec)
		: m_bIsRun(false)
		, m_bInitialized(false)
		, m_bActivateResize(false)
		, m_upWindow(nullptr)
		, m_upLayerBuffer(nullptr)
	{
		this->Initialize(spec);
	}

	CZVsystem::~CZVsystem()
	{
		this->Shutdown();
	}

	void CZVsystem::Initialize(const TApplicationSpecification& spec)
	{
		ZVLOG_FAILED(spec.Width > 0, "FAILED: Window width size must be greater than 0. \"{0}\"", spec.Width);
		ZVLOG_FAILED(spec.Height > 0, "FAILED: Window height size must be greater than 0. \"{0}\"", spec.Height);
		m_bInitialized = true;
		// Generated a Window
		m_upWindow = CZVwindow::Create(spec.Name, spec.Width, spec.Height);
		m_upWindow->Initialize();
		// Generated a LayerBuffer
		m_upLayerBuffer = CZVlayerBuffer::Create();
		// Init ImGui
		CZVimguiManager::Initialize(m_upWindow);
		// Set Callback
		m_upWindow->SetEventCallback(BIND_EVENT_FUNC(CZVsystem::OnEvent));
	}

	void CZVsystem::Shutdown()
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

	void CZVsystem::Run()
	{
		ZVLOG_FAILED(m_bInitialized, "FAILED: CZVsystem is not initialized!");

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

			{ // ImGui_Layer
				CZVimguiManager::Begin(m_upWindow);
				for (auto& layer : *m_upLayerBuffer)
				{
					layer->OnGuiRender();
				}
				CZVimguiManager::ShowDemo();
				CZVimguiManager::End(m_upWindow);
			}

			m_upWindow->Clear();
		}
	}

	void CZVsystem::AttachLayer(CZVlayer* layer)
	{
		ZVLOG_FAILED(layer, "FAILED: Layer pointer is NULL!");
		m_upLayerBuffer->InsertLayer(layer);
	}

	void CZVsystem::DetachLayer(CZVlayer* layer)
	{
		ZVLOG_FAILED(layer, "FAILED: Layer pointer is NULL!");
		m_upLayerBuffer->RemoveLayer(layer);
	}

	void CZVsystem::OnEvent(CZVevent& event)
	{
		CZVeventDispatcher ed(event);
		switch (event.GetEventType())
		{
			case EventType::WindowResize:
				ed.Dispatch<CZVwindowResizeEvent>(BIND_EVENT_FUNC(ZVLab::CZVsystem::WindowResize));
				return;
			case EventType::WindowClose:
				ed.Dispatch<CZVwindowCloseEvent>(BIND_EVENT_FUNC(ZVLab::CZVsystem::WindowClose));
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

	ZVbool CZVsystem::WindowResize(CZVwindowResizeEvent& event)
	{
		m_bActivateResize = true;
		return (true);
	}

	ZVbool CZVsystem::WindowClose(CZVwindowCloseEvent& event)
	{
		m_bIsRun = false;
		return (true);
	}

	void CZVsystem::PauseWindowResize(ZVbool* flags)
	{
		m_upWindow->Clear();
		(*flags) = false;
	}


} // namespace ZVLab
