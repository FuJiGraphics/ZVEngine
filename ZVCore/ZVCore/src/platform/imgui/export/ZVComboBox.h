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
		CzvComboBox(const std::string& label, const TzvComboBoxInfo& info = TzvComboBoxInfo());
		~CzvComboBox();

		// Getter
		void	SetItems(const std::initializer_list<const char*>& item_list);
		
		// Others
		std::string	Bind();

		// inline
		inline std::string	GetLabel() const { return (m_strLabel); }
	};

} // namespace ZVLab

#endif /*__ZV_COMBOBOX_H__*/
