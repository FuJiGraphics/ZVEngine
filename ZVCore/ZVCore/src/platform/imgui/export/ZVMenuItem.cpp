#include "ZVMenuItem.h"

namespace ZVLab {

	CzvMenuItem::CzvMenuItem(const std::string& label, const std::string& shortcut)
		: m_strLabel(label)
		, m_strShortCut(shortcut)
	{
	}

	void CzvMenuItem::SetHotKey(const CzvKeyMap& keycodes)
	{
		auto& io = ImGui::GetIO();
		
		FZLOG_INFO("HotKey = {0}", keycodes.GetKeyString());
	}

	bool CzvMenuItem::Bind()
	{
		//auto& io = ImGui::GetIO();
		//if (ImGui::IsWindowFocused() && io.KeysDown[ZVKEY])
		//{
		//}

		return (ImGui::MenuItem(m_strLabel.c_str()));
	}

} 
