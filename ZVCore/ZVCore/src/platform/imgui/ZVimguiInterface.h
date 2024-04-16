#ifndef __ZV_ZVIMGUIINTERFACE_H__
#define __ZV_ZVIMGUIINTERFACE_H__
#pragma once

#include <string>
#include "core/Core.h"

namespace ZVLab {

	class ZV_API CZVimguiInterface
	{
	public:
		static bool Begin(const std::string& name);
		static bool Button(const char* str, float w, float h);
		static bool Button(const char* str, float w, float h, float x, float y);
		static void End();
	};


} // namespace ZVLab


#endif