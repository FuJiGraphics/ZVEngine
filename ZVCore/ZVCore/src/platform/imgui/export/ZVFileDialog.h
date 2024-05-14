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

	class CzvFileDialog
	{
	//// Member Variables
	private:
		std::string			m_strLabel;
		EzvFileDialogType	m_eType;

	//// Member Functions
	public:
		// Constructor, Destructor
		CzvFileDialog(const std::string& label, const EzvFileDialogType& type = EzvFileDialogType::eType_Common);
		~CzvFileDialog();

		// others
		bool	Open(const std::string& label, const std::string& filter, bool isMultiselect = true, const std::string& startingDir = "");
		bool	Save(const std::string& label, const std::string& filter, const std::string& startingDir = "");

	};

} // namespace ZVLab
#endif /*__ZV_ZV_FILEDIALOG_H__*/
