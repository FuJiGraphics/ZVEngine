#ifdef ZV_PLATFORM_WINDOWS
	#ifndef __ZV_ZVWINDOW_WINDOWS_H__
	#define __ZV_ZVWINDOW_WINDOWS_H__
	#pragma once

#include "core/ZVwindow.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace ZVLab {

	class ZV_API CZVwindow_Windows final : public CzvWindow
	{
	private: // members
		bool				m_bInitialized;
		std::string			m_strWindowName;
		ZVuint				m_uiWidth;
		ZVuint				m_uiHeight;
		GLFWwindow*			m_pGlfwWindow;
		TzvWindowChunk		m_tData;

	public: // contructor and destructor
		CZVwindow_Windows(const std::string& name, ZVuint width, ZVuint height);
		virtual ~CZVwindow_Windows();

	public: // overrides
		virtual GLFWwindow*		GetNativeWindow() const final;
		virtual ZVuint			GetWidth() const final;
		virtual ZVuint			GetHeight() const final;
		virtual void			SetEventCallback(const EventCallbackFn& callback) final;
		virtual void			Initialize() final;
		virtual void			Shutdown() final;
		virtual void			PollEvents() final;
		virtual void			Clear() final;

	private:
		void InitEventCallback();
		void UpdateSwapChain();
		void UpdateViewport();
		void ClearScreen();
	};


} // namespace ZVLab

	#endif /*__ZV_ZVWINDOW_WINDOWS_H__*/
#endif /*ZV_PLATFORM_WINDOWS*/
