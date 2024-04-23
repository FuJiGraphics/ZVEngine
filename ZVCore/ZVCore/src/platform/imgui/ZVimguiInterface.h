#ifndef __ZV_ZVIMGUIINTERFACE_H__
#define __ZV_ZVIMGUIINTERFACE_H__
#pragma once

#include <string>
#include "core/Core.h"

namespace ZVLab {

	class ZV_API CZVimguiInterface
	{
	public: // Menu
		static bool BeginMenu(const char* label);
		static bool MenuItem(const char* label, const char* shortcut = NULL, bool selected = false, bool enabled = true);
		static void EndMenu();

	public: // Dialog
		static bool Begin(const char* label);
		static void End();

	public: // Buttons
		static bool Button(const char* label, float w, float h);
		static bool Button(const char* label, float w, float h, float x, float y);

		// static bool ImageButton()
	};


} // namespace ZVLab


#endif