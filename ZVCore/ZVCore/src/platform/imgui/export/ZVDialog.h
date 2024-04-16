#ifndef __ZV_ZVDIALOG_H__
#define __ZV_ZVDIALOG_H__
#pragma once

#include "../../../core/Core.h"

namespace ZVLab {

	class ZV_API CZVDialog
	{
		friend class CZVGui;
		
	public:
		CZVDialog(const std::string& name);
		~CZVDialog();

	public: // interface
		bool Button(const std::string& name, float w, float h);
		bool Button(const std::string& name, float w, float h, float posX, float posY);

	public:
		inline std::string GetName() const { return (m_DialogName); }

	private:
		void Synchronization();

	private:
		std::string	m_DialogName;
		
	private:
		static bool		   s_FirstInit;
		static std::string s_currDialog;
	};

} // namespace ZVLab

#endif /*__ZV_ZVDIALOG_H__*/
