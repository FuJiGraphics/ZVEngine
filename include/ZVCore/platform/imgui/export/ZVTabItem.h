#ifndef __ZV_ZVTABITEM_H__
#define __ZV_ZVTABITEM_H__
#pragma once

#include "../../../core/Core.h"
#include "ZVGuiConfig.h"
#include <string>

namespace ZVLab {
	//----------------------------------------------------
	// Tab Item
	//----------------------------------------------------
	struct TzvTabItemChunk
	{
		std::string				Label;
		TzvTabItemInfo			tOptions;
		bool					IsUnFolded;
	};

	class ZV_API CzvTabItem
	{
	private:
		bool Synchronization();

	protected: /// using 
		using FuncEventCallback = std::function<void(void)>;

		//// Member Variables
	private:
		TzvTabItemChunk			m_tData;
		std::function<void()>	m_fpCallbackFn;

	public: // Constructors, Destructors
		CzvTabItem(const std::string& label, const TzvTabItemInfo& options = TzvTabItemInfo());
		virtual ~CzvTabItem();

	public: // inline Getter
		inline std::string	GetLabel() const { return (m_tData.Label); }

	public: // inline Setter
		inline void			SetLabel(const std::string& label) { m_tData.Label = label; }
		inline void			SetCallbackFunc(FuncEventCallback fn) { m_fpCallbackFn = fn; }

	public: // others
		virtual bool		Bind();
	};

} // namesapce ZVLab
#endif /*__ZV_ZVTABITEM_H__*/

