#ifndef __ZV_CORE_H__
#define __ZV_CORE_H__
#pragma once

// standard
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <optional>
#include <map>
// headers
#include "DataTypes.h"
#include "FZLib/Helpers/LogHelper.h"
#include "ZVAssert.h"
#include "ZVMemory.h"
// imgui
#include "imgui/imgui.h"
#include "imgui/extensions/implot/implot.h"
#include "glad/glad.h"
#include "imgui/backends/imgui_impl_opengl3.h"
// glfw
#include "GLFW/glfw3.h"
#include "imgui/backends/imgui_impl_glfw.h"
// win32   
#if (DZVEngine_Usage == DZVEngine_Usage_WIN32_OpenGL)
	#include "imgui/backends/imgui_impl_win32.h"
#endif

#ifdef ZV_USAGE_DLL
	#ifdef ZV_EXPORT_DLL
		#define ZV_API	__declspec(export)
	#else
		#define ZV_API	__declspec(import)
	#endif
#else
	#define ZV_API
#endif

struct ZV_API TzvApplicationCommandLineArgs
{
	int	iCount = 0;
	char** ppcArgs = nullptr;

	const char* operator[](int index) const
	{
		FZLOG_DEBUG(index < iCount);
		return ppcArgs[index];
	}
};

struct ZV_API TzvApplicationSpecification
{
	std::string strName = "ZVEngine App";
	unsigned int uiWidth = 1280;
	unsigned int uiHeight = 720;
	std::string strWorkingDirectory;
	TzvApplicationCommandLineArgs strCommandLineArgs;
};

#define DBindMemberCallback(fn, address) std::bind(&fn, address)
#define DBindCallback(fn) std::bind(&fn)

#endif /* __ZV_CORE_H__ */
