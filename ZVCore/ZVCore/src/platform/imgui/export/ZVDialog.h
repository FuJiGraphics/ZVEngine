#ifndef __ZV_ZVDIALOG_H__
#define __ZV_ZVDIALOG_H__
#pragma once

#include "../../../core/Core.h"
#include "ZVGuiConfig.h"
#include "ZVButton.h"
#include <optional>

namespace ZVLab {

	class ZV_API CzvDialog
	{
	private: /// static member variables
		static bool				s_bFirstEntryScope;
		static std::string		s_strCurrDialog;
		static unsigned int		s_nuiDialogCount;

	private: /// member variables
		std::string				m_strLabel;
		std::optional<ImVec2>	m_optSize;
		std::optional<ImVec2>	m_optPosition;
		bool					m_bIsUnFolded;
		TzvDialogInfo			m_tOptions;

	public:  // Constructors, Destructors
		CzvDialog(const std::string& label);
		CzvDialog(const std::string& label, const TzvDialogInfo& options);
		CzvDialog(const std::string& label, const ImVec2& size);
		CzvDialog(const std::string& label, const ImVec2& size, const TzvDialogInfo& options);
		CzvDialog(const std::string& label, const ImVec2& size, const ImVec2& position);
		CzvDialog(const std::string& label, const ImVec2& size, const ImVec2& position, const TzvDialogInfo& options);
		virtual ~CzvDialog();

	public: // inline Getter
		inline std::string	GetLabel() const	{ return (m_strLabel); }
		inline bool			IsFolded() const	{ return (!m_bIsUnFolded); }
		inline bool			IsUnFolded() const	{ return (m_bIsUnFolded); }

	public: // interfaces
		bool Button(const std::string& label);
		bool Button(const std::string& label, const ImVec2& size);
		bool Button(const std::string& label, const ImVec2& size, const ImVec2& position);
		bool Button(CzvButton& button);

	private: /// Others
		bool Synchronization();
	};

} // namespace ZVLab

#endif /*__ZV_ZVDIALOG_H__*/
