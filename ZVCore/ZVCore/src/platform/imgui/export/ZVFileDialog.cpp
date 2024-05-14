#include "ZVFileDialog.h"

namespace ZVLab {

	CzvFileDialog::CzvFileDialog(const std::string& label, const EzvFileDialogType& type)
		: m_strLabel(label)
		, m_eType(type)
	{/*Empty*/}

	CzvFileDialog::~CzvFileDialog()
	{/*Empty*/}

	bool CzvFileDialog::Open(const std::string& label, 
							 const std::string& filter, 
							 bool isMultiselect, 
							 const std::string& startingDir)
	{
		return (ifd::FileDialog::Instance().Open(m_strLabel, label, filter, isMultiselect, startingDir));
	}

	bool CzvFileDialog::Save(const std::string& label, const std::string& filter, const std::string& startingDir)
	{
		return (ifd::FileDialog::Instance().Save(m_strLabel, label, filter, startingDir));
	}

} // namespace ZVLab