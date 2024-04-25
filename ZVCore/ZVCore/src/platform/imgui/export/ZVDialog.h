#ifndef __ZV_ZVDIALOG_H__
#define __ZV_ZVDIALOG_H__
#pragma once

#include "../../../core/Core.h"
#include "ZVGuiConfig.h"
#include "ZVButton.h"

namespace ZVLab {

	class ZV_API CzvDialog
	{
	private:
		static bool			s_bFirstInit;
		static std::string	s_strCurrDialog;

	private:
		std::string		m_strLabel;
		ImVec2			m_tPosition;
		ImVec2			m_tSize;
		bool			m_bIsUnFolded;
		TzvDialogInfo	m_tOptions;

	public:
		CzvDialog(const std::string& label, const TzvDialogInfo& options = TzvDialogInfo());
		CzvDialog(const std::string& label,
				  const ImVec2& position, 
				  const ImVec2& size = ImVec2(),
				  const TzvDialogInfo& options = TzvDialogInfo());
		~CzvDialog();

	public: // interface
		bool IsFolded() const;
		bool IsUnFolded() const;

		bool Button(const std::string& name, float w, float h);
		bool Button(const std::string& name, float w, float h, float posX, float posY);
		bool Button(CZVButton& button);

	public:
		inline std::string GetLabel() const { return (m_strLabel); }

	private:
		bool Synchronization();

	};

} // namespace ZVLab

#endif /*__ZV_ZVDIALOG_H__*/
