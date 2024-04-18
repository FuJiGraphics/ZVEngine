#include "ZVMenu.h"
#include "../ZVimguiInterface.h"

namespace ZVLab {

	bool			CZVMenu::s_bOpenedMainMenu = false;
	bool			CZVMenu::s_bOpenedMenu = false;
	bool			CZVMenu::s_FirstInitMenu = true;
	unsigned int	CZVMenu::s_MenuCount = 0;
	std::string		CZVMenu::s_currMenu;
	

	CZVMenu::CZVMenu(const std::string& name)
	{
		this->Synchronization();
		++s_MenuCount;
	}

	CZVMenu::~CZVMenu()
	{
		if (s_MenuCount == 1 && s_bOpenedMainMenu)
		{
			s_bOpenedMainMenu = false;
		}
		if (s_bOpenedMenu)
		{
			CZVimguiInterface::EndMenu(); 
			s_bOpenedMenu = false;
			s_currMenu.clear(); 
			s_FirstInitMenu = true;
		}
		--s_MenuCount;
	}

	bool CZVMenu::MenuItem(const std::string& label, const char * shortcut, bool selected, bool enabled)
	{
		if (this->Synchronization())
		{
			if (OpenedMenu(label))
			{
				return (CZVimguiInterface::MenuItem(label.c_str(), shortcut, selected, enabled));
			}
		}
		return (false);
	}

	bool CZVMenu::Synchronization()
	{
		if (s_MenuCount == 0)
		{
		}
		return (s_bOpenedMainMenu);
	}

	bool CZVMenu::OpenedMenu(const std::string& label)
	{
		if (s_FirstInitMenu)
		{
			s_bOpenedMenu = CZVimguiInterface::BeginMenu(label.c_str());
			if (s_bOpenedMenu)
			{
				s_currMenu = label;
				s_FirstInitMenu = false;
			}
		}
		else if (s_bOpenedMenu && s_currMenu != label)
		{
			CZVimguiInterface::EndMenu();
			s_currMenu = label;
			s_bOpenedMenu = CZVimguiInterface::BeginMenu(label.c_str());
		}
		return (s_bOpenedMenu);
	}

} // namespace ZVLab