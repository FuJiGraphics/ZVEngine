#ifndef __ZV_ZVDIALOG_H__
#define __ZV_ZVDIALOG_H__
#pragma once

#include "../../../core/Core.h"
#include "ZVButton.h"

namespace ZVLab {

	class ZV_API CZVDialog
	{
	public:
		CZVDialog(const std::string& name);
		~CZVDialog();

	public: // interface
		bool Folded() const;
		bool UnFolded() const;

		bool Button(const std::string& name, float w, float h);
		bool Button(const std::string& name, float w, float h, float posX, float posY);
		bool Button(const CZVButton& button);

	public:
		inline std::string GetLabel() const { return (m_DialogLabel); }

	private:
		bool Synchronization();

	private:
		std::string	m_DialogLabel;
		bool		m_isUnFolded;
		
	private:
		static bool		   s_FirstInit;
		static std::string s_currDialog;
	};

} // namespace ZVLab

#endif /*__ZV_ZVDIALOG_H__*/
