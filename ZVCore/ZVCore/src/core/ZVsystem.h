#ifndef __ZV_ZVSYSTEM_H__
#define __ZV_ZVSYSTEM_H__
#pragma once

#include "Core.h"
#include "ZVLayerBuffer.h"

// imgui
#include "../platform/imgui/ZVimguiManager.h"
#include "../platform/imgui/export/ZVProfiler.h"

// events
#include "../events/ZVevent.h"
#include "../events/ZVappEvent.h"
#include "../events/ZVkeyEvent.h"
#include "../events/ZVmouseEvent.h"

int main(int argc, char** argv);

namespace ZVLab {

	// forwards
	class CzvWindow;

	class ZV_API CzvSystem
	{
	protected:
		using Super = ZVLab::CzvSystem;

	private:
		static bool				s_bIsRunApplication;
		ZVbool					m_bInitialized;
		ZVbool					m_bActivateResize;
		Unique<CzvWindow>		m_upWindow;
		Unique<CzvLayerBuffer>	m_upLayerBuffer;

	public:
		static void ExitApp();

	public:
		CzvSystem();
		virtual ~CzvSystem();

	public:
		void Initialize(const TzvApplicationSpecification& spec);
		void Shutdown();

	public:
		void Run();

		void AttachLayer(CzvLayer* layer);
		void DetachLayer(CzvLayer* layer);
		void OnEvent(CzvEvent& event);

	private:
		ZVbool WindowResize(CzvWindowResizeEvent& event);
		ZVbool WindowClose(CzvWindowCloseEvent& event);

	private:
		void PauseWindowResize(ZVbool* flags);
	};

	// ZVEngine에서 정의해야 하는 엔트리 포인트입니다.
	CzvSystem* CreateApplication(TzvApplicationCommandLineArgs args);

} // namespace ZVLab

#endif  /* __ZV_ZVSYSTEM_H__ */