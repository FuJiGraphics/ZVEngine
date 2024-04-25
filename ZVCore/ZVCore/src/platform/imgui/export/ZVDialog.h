#ifndef __ZV_ZVDIALOG_H__
#define __ZV_ZVDIALOG_H__
#pragma once

#include "../../../core/Core.h"
#include "ZVButton.h"

namespace ZVLab {

	struct ZV_API TDialogInfo
	{
	};

	class ZV_API CZVDialog
	{
	public:
		CZVDialog(const std::string& name);
		~CZVDialog();

	public: // interface
		bool IsFolded() const;
		bool IsUnFolded() const;

		bool Button(const std::string& name, float w, float h);
		bool Button(const std::string& name, float w, float h, float posX, float posY);
		bool Button(CZVButton& button);

	public:
		inline std::string GetLabel() const { return (m_DialogLabel); }

	private:
		bool Synchronization();

	private:
		std::string		m_DialogLabel;
		bool			m_isUnFolded;
		unsigned int	m_Width;
		unsigned int	m_Height;
		unsigned int	m_PosX;
		unsigned int	m_PosY;

	private:
		static bool		   s_FirstInit;
		static std::string s_currDialog;
	};

} // namespace ZVLab

#endif /*__ZV_ZVDIALOG_H__*/
