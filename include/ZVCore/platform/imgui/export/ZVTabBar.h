#ifndef __ZV_TAB_BAR_H__
#define __ZV_TAB_BAR_H__
#pragma once

#include "../../../core/Core.h"
#include "ZVGuiConfig.h"
#include "ZVTabItem.h"

namespace ZVLab {
	//----------------------------------------------------
	// Tab bar
	//----------------------------------------------------
	struct TzvTabBarChunk
	{
		std::string				Label;
		TzvTabBarInfo			tOptions;
		bool					IsUnFolded;
	};

	class ZV_API CzvTabBar
	{
		//// Member Variables
	private:
		TzvTabBarChunk	m_tData;

		//// Member functions
	public:
		CzvTabBar(const std::string& label, const TzvTabBarInfo& info = TzvTabBarInfo());
		virtual ~CzvTabBar();

		bool TabItem(const std::string& label);
		bool TabItem(const std::string& label, const TzvTabItemInfo& option);
		bool TabItem(CzvTabItem& item);

	private:
		bool Synchronization();
	};

} // namespace ZVLab
#endif /*__ZV_TAB_BAR_H__*/
