#pragma once

// standard
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <optional>
#include <map>

// headers
#include "FZLib/Helpers/LogHelper.h"
#include "ZVAssert.h"
#include "ZVMemory.h"

// imgui
#include "imgui/imgui.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "imgui/backends/imgui_impl_opengl3.h"
#include "imgui/backends/imgui_impl_glfw.h"
#define		GLFW_EXPOSE_NATIVE_WIN32
#include	"GLFW/glfw3native.h"
#include "imgui/extensions/implot/implot.h"

#ifdef ZV_USAGE_DLL
#ifdef ZV_EXPORT_DLL
#define ZV_API	__declspec(export)
#else
#define ZV_API	__declspec(import)
#endif
#else
#define ZV_API
#endif
