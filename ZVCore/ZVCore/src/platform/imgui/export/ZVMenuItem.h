#ifndef __ZV_MENUITEM_H__
#define __ZV_MENUITEM_H__
#pragma once

#include "../../../core/Core.h"
#include "ZVKeyMap.h"
#include "ZVHotKey.h"

namespace ZVLab {

	class ZV_API CzvMenuItem
	{
	//// Member Variables
	private:
		std::string		m_strLabel;
		std::string		m_strShortCut;
		CzvHotKey		m_HotKey;
		bool			m_bSelected;
		bool			m_bEnabled;

	//// Member Functions
	public:
		CzvMenuItem(const std::string& label, const std::string& shortcut);
		~CzvMenuItem() = default;

		void	SetHotKey(const CzvKeyMap& keycodes);

		bool	Bind();

	};

} // namespace ZVLab

#endif