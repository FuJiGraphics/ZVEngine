#ifndef __ZV_MENUBAR_H__
#define __ZV_MENUBAR_H__
#pragma once

#include "../../../core/Core.h"

namespace ZVLab {

	class ZV_API CzvMenuBar
	{
	//// Member Variables
	private:
		std::string		m_strLabel;

	private:
		bool	Synchronization();
	public:
		CzvMenuBar(const std::string& label);
		~CzvMenuBar();

	};

} // namespace ZVLab

#endif /*__ZV_MENUBAR_H__*/
