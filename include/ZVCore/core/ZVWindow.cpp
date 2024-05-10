#include "ZVwindow.h"

#ifdef ZV_PLATFORM_WINDOWS
	#include "platform/windows/ZVwindow_win.h"
#elif ZV_PLATFORM_LINUX
	#include "platform/linux/ZVwindow_linux.h"
#else
	#error "ERROR: did not found platform!"
#endif

namespace ZVLab {

	Unique<CzvWindow> CzvWindow::Create(const std::string& name, ZVuint width, ZVuint height)
	{
#ifdef ZV_PLATFORM_WINDOWS
		return (CreateUnique<CZVwindow_Windows>(name, width, height));
#elif ZV_PLATFORM_LINUX
		return (CreateUnique<CZVwindow_Linux>(name, width, height));
#else
	#error "ERROR: did not found platform!"
#endif
	}

}
