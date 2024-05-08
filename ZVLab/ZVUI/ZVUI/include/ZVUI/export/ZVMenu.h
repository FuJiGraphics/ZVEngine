#ifndef __ZV_ZVWINDOWMENU_H__
#define __ZV_ZVWINDOWMENU_H__
#pragma once

#include "../ZVCore.h"

namespace ZVLab {

	class ZV_API CZVMenu
	{
	public:
		CZVMenu(const std::string& name);
		~CZVMenu();

	public: // interface
		bool MenuItem(const std::string& label, const char* shortcut = NULL, bool selected = false, bool enabled = true);

	public:
		inline std::string GetName() const { return (m_MainMenuName); }

	private:
		bool Synchronization();
		bool OpenedMenu(const std::string& label);

	private:
		std::string	m_MainMenuName;

	private:
		static bool				s_bOpenedMainMenu;
		static bool				s_bOpenedMenu;
		static bool				s_FirstInitMenu;
		static unsigned int		s_MenuCount;
		static std::string		s_CurrMainMenu;
		static std::string		s_currMenu;
	};

} // namespace ZVLab

#endif /*__ZV_ZVWINDOWMENU_H__*/
