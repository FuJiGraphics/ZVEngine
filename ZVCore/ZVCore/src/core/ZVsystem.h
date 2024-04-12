#ifndef __ZV_ZVSYSTEM_H__
#define __ZV_ZVSYSTEM_H__
#pragma once

#include "Core.h"
#include "ZVimgui.h"
#include "ZVlayerBuffer.h"

// events
#include "events/ZVevent.h"
#include "events/ZVappEvent.h"
#include "events/ZVkeyEvent.h"
#include "events/ZVmouseEvent.h"

int main(int argc, char** argv);

namespace ZVLab {
	// forwards
	class CZVwindow;

	class ZV_API CZVsystem
	{
	protected:
		using Super = ZVLab::CZVsystem;
	private:
		ZVbool					m_bIsRun;
		ZVbool					m_bInitialized;
		ZVbool					m_bActivateResize;
		Unique<CZVwindow>		m_upWindow;
		Unique<CZVlayerBuffer>	m_upLayerBuffer;
	
	public:
		CZVsystem(const TApplicationSpecification& spec);
		virtual ~CZVsystem();
		
	public:
		void Initialize(const TApplicationSpecification& spec);
		void Shutdown();

	public:
		void Run();

		void AttachLayer(CZVlayer* layer);
		void DetachLayer(CZVlayer* layer);
		void OnEvent(CZVevent& event);

	private:
		ZVbool WindowResize(CZVwindowResizeEvent& event);
		ZVbool WindowClose(CZVwindowCloseEvent& event);

	private:
		void PauseWindowResize(ZVbool* flags);
	};

	// ZVEngine에서 정의해야 하는 엔트리 포인트입니다.
	CZVsystem* CreateApplication(TApplicationCommandLineArgs args);

} // namespace ZVLab

#endif  /* __ZV_ZVSYSTEM_H__ */