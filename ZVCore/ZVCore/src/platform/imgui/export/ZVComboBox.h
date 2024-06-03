#ifndef __ZV_COMBOBOX_H__
#define	__ZV_COMBOBOX_H__
#pragma once

#include "../../../core/Core.h"
#include "ZVGuiConfig.h"

namespace ZVLab {

//----------------------------------------------------
// ComboBox
//----------------------------------------------------
	class ZV_API CzvComboBox
	{
	//// Member Variables
	private:
		std::string					m_strLabel;
		TzvComboBoxInfo				m_tOptions;
		std::vector<const char*>	m_vItemList;

	//// Member Functions
	public:
		// Constructor, Destructors
		CzvComboBox(const std::string& label = "##", const TzvComboBoxInfo& info = TzvComboBoxInfo());
		CzvComboBox(const std::vector<const char*>& item_list, const TzvComboBoxInfo& info = TzvComboBoxInfo());
		CzvComboBox(const std::vector<std::string>& item_list, const TzvComboBoxInfo& info = TzvComboBoxInfo());
		CzvComboBox(const Args<const char *>& item_list, const TzvComboBoxInfo& info = TzvComboBoxInfo());
		~CzvComboBox();

		// Getter
		std::string		GetLabel() const;
		int				GetSize() const;

		// Setter
		void			AddItems(const char* item);
		void			AddItems(const std::string& item);
		void			SetItems(const std::vector<const char*>& item_list);
		void			SetItems(const std::vector<std::string>& item_list);
		void			SetItems(const Args<const char *>& item_list);
		
		// Others
		std::string		Bind();

		std::string		operator[](int index);
		std::string		operator[](int index) const;
	};

} // namespace ZVLab

#endif /*__ZV_COMBOBOX_H__*/
