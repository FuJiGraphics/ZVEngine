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

// opencv
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/types_c.h"

// imgui
#include "imgui/imgui.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "imgui/backends/imgui_impl_opengl3.h"
#include "imgui/backends/imgui_impl_glfw.h"
#include "imgui/extensions/im_plot/implot.h"
#include "imgui/extensions/im_file_dialog/ImFileDialog.h"



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
