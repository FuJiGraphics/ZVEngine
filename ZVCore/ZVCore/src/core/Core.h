#ifndef __ZV_CORE_H__
#define __ZV_CORE_H__
#pragma once

// headers
#include "DataTypes.h"
#include "FZLib/Helpers/LogHelper.h"
#include "ZVassert.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// imgui
#include "imgui.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "backends/imgui_impl_opengl3.h"
#include "backends/imgui_impl_glfw.h"

#ifdef ZV_USAGE_DLL
	#ifdef ZV_EXPORT_DLL
		#define ZV_API	__declspec(export)
	#else
		#define ZV_API	__declspec(import)
	#endif
#else
	#define ZV_API
#endif

namespace ZVLab {
	template<typename T>
	using Unique = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Unique<T> CreateUnique(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Shared = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Shared<T> CreateShared(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
} // namespace ZVLab

struct ZV_API TApplicationCommandLineArgs
{
	int Count = 0;
	char** Args = nullptr;

	const char* operator[](int index) const
	{
		FZLOG_DEBUG(index < Count);
		return Args[index];
	}
};

struct ZV_API TApplicationSpecification
{
	std::string Name = "ZVEngine App";
	unsigned int Width = 1280;
	unsigned int Height = 720;
	std::string WorkingDirectory;
	TApplicationCommandLineArgs CommandLineArgs;
};


#endif /* __ZV_CORE_H__ */
