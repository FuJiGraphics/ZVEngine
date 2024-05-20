#include "ZVMenuItem.h"
#include "ZVDialog.h"
#include "ZVHotKey.h"

namespace ZVLab {

	CzvMenuItem::CzvMenuItem(const std::string& label, const std::string& shortcut)
		: m_strLabel(label)
		, m_strShortCut(shortcut)
	{
	}

	bool CzvMenuItem::Bind()
	{
		const char* shortcut = (m_strShortCut.empty()) ? nullptr : m_strShortCut.c_str();
		return (ImGui::MenuItem(m_strLabel.c_str(), shortcut));
	}

	bool CzvMenuItem::Bind(const CzvHotKey& keyMap, CzvDialog& targetFocusDialog, bool isOverwriteShortcut)
	{
		bool result = false;
		
		const char* shortcut = (m_strShortCut.empty()) ? nullptr : m_strShortCut.c_str();
		shortcut = (isOverwriteShortcut) ? keyMap.GetKeyString().c_str() : shortcut;
		result = ImGui::MenuItem(m_strLabel.c_str(), shortcut);
		if (result == false)
		{
			if (targetFocusDialog.IsWindowFocused())
			{
				result = keyMap.IsPressed();
			}
		}

		return (result);
	}

} 
