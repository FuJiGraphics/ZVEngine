#ifndef __ZV_MENUITEM_H__
#define __ZV_MENUITEM_H__
#pragma once

#include "../../../core/Core.h"

namespace ZVLab {

	// forwards
	class ZV_API CzvDialog;
	class ZV_API CzvHotKey;

	class ZV_API CzvMenuItem
	{
	//// Member Variables
	private:
		std::string					m_strLabel;
		std::string					m_strShortCut;
		bool						m_bSelected;
		bool						m_bEnabled;

	//// Member Functions
	public:
		CzvMenuItem(const std::string& label, const std::string& shortcut = "");
		~CzvMenuItem() = default;

		// Others
		bool	Bind();
		bool	Bind(const CzvHotKey& keyMap, CzvDialog& targetFocusDialog, bool isOverwriteShortcut = true);
	};

} // namespace ZVLab

#endif