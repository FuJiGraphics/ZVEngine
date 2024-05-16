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
		bool			m_bIsActivated;

	//// Member Functions
	public:
		// Constructor, Destructor
		CzvMenuBar(const std::string& label);
		~CzvMenuBar();

		// Getter
		inline bool	IsActivated() const { return (m_bIsActivated); }

		// Others
		bool		Bind();
		void		UnBind();

	private:
		bool		Synchronization();
		void		Release();
	};

} // namespace ZVLab

#endif /*__ZV_MENUBAR_H__*/
