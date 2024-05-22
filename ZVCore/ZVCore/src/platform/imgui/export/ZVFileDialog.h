#ifndef __ZV_ZV_FILEDIALOG_H__
#define __ZV_ZV_FILEDIALOG_H__
#pragma once

#include "../../../core/Core.h"

namespace ZVLab {

	enum class EzvFileDialogType
	{
		eType_Common,
		eType_Windows,
	};

	class ZV_API CzvFileDialog
	{
	//// Member Variables
	private:
		std::string			m_strLabel;
		EzvFileDialogType	m_eType;
		std::string			m_strOpenLabel;
		std::string			m_strSaveLabel;
		bool				m_bIsDone;
		bool				m_bMultiSelectMode;

	//// Member Functions
	public:
		// Constructor, Destructor
		CzvFileDialog(const std::string& label, const EzvFileDialogType& type = EzvFileDialogType::eType_Common);
		~CzvFileDialog();

		// Getter
		inline std::string	GetLabel() const;
		bool				IsDone() const;

		// Setter
		void	SetOpenLabel(const std::string& label);
		void	SetSaveLabel(const std::string& label);
		void	SetMultiSelectMode(bool enabled);

		// Others
		bool		Open(const std::string& filter, const std::string& startingDir = "");
		bool		Save(const std::string& filter, const std::string& startingDir = "");
		bool		GetOpenFilePaths(std::string* out);
		bool		GetSaveFilePaths(std::string* out);
	};

} // namespace ZVLab
#endif /*__ZV_ZV_FILEDIALOG_H__*/
