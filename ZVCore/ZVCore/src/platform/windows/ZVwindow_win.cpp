#ifdef ZV_PLATFORM_WINDOWS

#include "ZVwindow_win.h"
// events
#include "events/ZVevent.h"
#include "events/ZVappEvent.h"
#include "events/ZVkeyEvent.h"
#include "events/ZVmouseEvent.h"

namespace ZVLab {

	CZVwindow_Windows::CZVwindow_Windows(const std::string& name, ZVuint width, ZVuint height)
		: m_bInitialized(false)
		, m_strWindowName(name)
		, m_uiWidth(width)
		, m_uiHeight(height)
		, m_pGlfwWindow(nullptr)
	{/*Empty*/}

	CZVwindow_Windows::~CZVwindow_Windows()
	{
		this->Shutdown();
	}

	GLFWwindow* CZVwindow_Windows::GetNativeWindow() const
	{
		return (m_pGlfwWindow);
	}

	ZVuint CZVwindow_Windows::GetWidth() const
	{
		return (m_uiWidth);
	}

	ZVuint CZVwindow_Windows::GetHeight() const
	{
		return (m_uiHeight);
	}

	void CZVwindow_Windows::SetEventCallback(const EventCallbackFn& callback)
	{
		m_tData.cbCallback = callback;
	}

	void CZVwindow_Windows::Initialize()
	{
		if (!m_bInitialized)
		{
			m_bInitialized = true;
			ZVLOG_FAILED(glfwInit(), "FAILED: Failed to initialized a glfw!");

			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

			m_pGlfwWindow = glfwCreateWindow(static_cast<int>(m_uiWidth),
											 static_cast<int>(m_uiHeight),
											 m_strWindowName.c_str(),
											 NULL, NULL);
			ZVLOG_FAILED(m_pGlfwWindow, "FAILED: Failed to created a glfwWindow!");

			glfwMakeContextCurrent(m_pGlfwWindow);
			if (!gladLoadGL()) {
				fprintf(stderr, "Failed to initialize GLAD\n");
			}

			// Set Chunk
			m_tData.strTitle = m_strWindowName;
			m_tData.uiWidth = m_uiWidth;
			m_tData.uiHeight = m_uiHeight;
			glfwSetWindowUserPointer(m_pGlfwWindow, &m_tData);

			// init callback system
			this->InitEventCallback();

			glfwSwapInterval(1);
		}
	}

	void CZVwindow_Windows::Shutdown()
	{
		if (m_bInitialized)
		{
			m_bInitialized = false;
			glfwDestroyWindow(m_pGlfwWindow);
			glfwTerminate();
		}
	}

	void CZVwindow_Windows::PollEvents()
	{
		ZVLOG_FAILED(m_bInitialized, "FAILED: Initialization hasn't been completed yet.");\
		glfwPollEvents();

	}

	void CZVwindow_Windows::Clear()
	{
		ZVLOG_FAILED(m_bInitialized, "FAILED: Initialization hasn't been completed yet."); \
		this->UpdateSwapChain();
		this->UpdateViewport();
		this->ClearScreen();
	}

	void CZVwindow_Windows::InitEventCallback()
	{
		glfwSetWindowSizeCallback(m_pGlfwWindow,
								  [](GLFWwindow* window, ZVint width, ZVint height)
		{
			ZVLOG_FAILED(window, "FAILED: Failed to created a glfwWindow!");
			TzvWindowChunk& data = *(TzvWindowChunk*)glfwGetWindowUserPointer(window);
			data.uiWidth = static_cast<ZVuint>(width);
			data.uiHeight = static_cast<ZVuint>(height);

			CzvWindowResizeEvent event{ width, height };
			data.cbCallback(event);
		});

		glfwSetWindowCloseCallback(m_pGlfwWindow,
								   [](GLFWwindow* window) {
			ZVLOG_FAILED(window, "FAILED: Failed to created a glfwWindow!");
			TzvWindowChunk& data = *(TzvWindowChunk*)glfwGetWindowUserPointer(window);
			CzvWindowCloseEvent event;
			data.cbCallback(event);
		});

		glfwSetCursorPosCallback(m_pGlfwWindow,
								 [](GLFWwindow* window, ZVdouble xpos, ZVdouble ypos) {
			ZVLOG_FAILED(window, "FAILED: Failed to created a glfwWindow!");
			TzvWindowChunk& data = *(TzvWindowChunk*)glfwGetWindowUserPointer(window);
			CzvMouseMovedEvent event((ZVfloat)xpos, (ZVfloat)ypos);
			data.cbCallback(event);
		});

		glfwSetMouseButtonCallback(m_pGlfwWindow,
								   [](GLFWwindow* window, ZVint button, ZVint action, ZVint mods) {
			ZVLOG_FAILED(window, "FAILED: Failed to created a glfwWindow!");
			TzvWindowChunk& data = *(TzvWindowChunk*)glfwGetWindowUserPointer(window);
			switch (action)
			{
				case GLFW_PRESS: {
					CzvMouseButtonPressedEvent mbpEvent(button);
					data.cbCallback(mbpEvent);
				} break;
				case GLFW_RELEASE: {
					CzvMouseButtonReleasedEvent mbrEvent(button);
					data.cbCallback(mbrEvent);
				} break;
			}
		});

		glfwSetScrollCallback(m_pGlfwWindow,
							  [](GLFWwindow* window, ZVdouble xoffset, ZVdouble yoffset)
		{
			ZVLOG_FAILED(window, "FAILED: Failed to created a glfwWindow!");
			TzvWindowChunk& data = *(TzvWindowChunk*)glfwGetWindowUserPointer(window);
			CzvMouseScrolledEvent event((ZVfloat)xoffset, (ZVfloat)yoffset);
			data.cbCallback(event);
		});

		glfwSetKeyCallback(m_pGlfwWindow,
						   [](GLFWwindow* window, ZVint key, ZVint scancode, ZVint action, ZVint mods)
		{
			ZVLOG_FAILED(window, "FAILED: Failed to created a glfwWindow!");
			TzvWindowChunk& data = *(TzvWindowChunk*)glfwGetWindowUserPointer(window);
			static ZVuint repeatCount = 0;
			CzvKeyReleasedEvent releasedEvent(key);
			CzvKeyPressedEvent pressedEvent(key, (ZVuint)repeatCount);
			switch (action)
			{
			case GLFW_RELEASE:
			{
				repeatCount = 0;
				data.cbCallback(releasedEvent);
				return;
			} break;

			case GLFW_PRESS: [[fallthrough]];
			case GLFW_REPEAT:
			{
				++repeatCount;
				data.cbCallback(pressedEvent);
				return;
			} break;
			}
		});

		glfwSetCharCallback(m_pGlfwWindow,
							[](GLFWwindow* window, ZVuint key)
		{
			ZVLOG_FAILED(window, "FAILED: Failed to created a glfwWindow!");
			TzvWindowChunk& data = *(TzvWindowChunk*)glfwGetWindowUserPointer(window);
			CzvKeyTypedEvent pressedEvent(key);
			data.cbCallback(pressedEvent);
		});
	}

	void CZVwindow_Windows::UpdateSwapChain()
	{
		ZVLOG_FAILED(m_bInitialized, "FAILED: Initialization hasn't been completed yet.");
		glfwSwapBuffers(m_pGlfwWindow);
	}

	void CZVwindow_Windows::UpdateViewport()
	{
		ZVLOG_FAILED(m_bInitialized, "FAILED: Initialization hasn't been completed yet.");
		int w, h;
		glfwGetFramebufferSize(m_pGlfwWindow, &w, &h);
		m_uiWidth = static_cast<ZVuint>(w);
		m_uiHeight = static_cast<ZVuint>(h);
		glViewport(0, 0, m_uiWidth, m_uiHeight);
	}

	void CZVwindow_Windows::ClearScreen()
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}

} // namespace ZVLab

#endif /*ZV_PLATFORM_WINDOWS*/