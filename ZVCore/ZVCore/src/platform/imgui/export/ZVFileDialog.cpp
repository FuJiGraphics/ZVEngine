#include "ZVFileDialog.h"

namespace ZVLab {

	CzvFileDialog::CzvFileDialog(const std::string& label, const EzvFileDialogType& type)
		: m_strLabel(label)
		, m_eType(type)
		, m_strOpenLabel("Open a files")
		, m_strSaveLabel("Save a file")
		, m_bIsDone(false)
		, m_bMultiSelectMode(false)
	{/*Empty*/}

	CzvFileDialog::~CzvFileDialog()
	{/*Empty*/}

	std::string CzvFileDialog::GetLabel() const
	{
		return (m_strLabel);
	}

	bool CzvFileDialog::IsDone() const
	{
		return (m_bIsDone);
	}

	void CzvFileDialog::SetOpenLabel(const std::string& label)
	{
		m_strOpenLabel = label;
	}

	void CzvFileDialog::SetSaveLabel(const std::string& label)
	{
		m_strSaveLabel = label;
	}

	void CzvFileDialog::SetMultiSelectMode(bool enabled)
	{
		m_bMultiSelectMode = enabled;
	}

	bool CzvFileDialog::Open(const std::string& filter, const std::string& startingDir)
	{
		bool result = false;
		auto& fd = ifd::FileDialog::Instance();
		result = fd.Open(m_strLabel, m_strOpenLabel, filter, m_bMultiSelectMode, startingDir);
		return (result);
	}

	bool CzvFileDialog::Save(const std::string& filter, const std::string& startingDir)
	{
		bool result = false;
		auto& fd = ifd::FileDialog::Instance();
		result = fd.Save(m_strLabel, m_strOpenLabel, filter, startingDir);
		return (result);
	}

	bool CzvFileDialog::GetOpenFilePaths(std::string* out)
	{
		DZVLog_Failed(out, "FAILED: std::string* out is Null!");
		bool result = false;
		if (result = ifd::FileDialog::Instance().IsDone(m_strLabel))
		{
			if (ifd::FileDialog::Instance().HasResult()) 
			{
				if (out != nullptr)
					*out = ifd::FileDialog::Instance().GetResult().u8string();
				else
					out = nullptr;
			}
			ifd::FileDialog::Instance().Close();
		}
		return (result);
	}

	bool CzvFileDialog::GetSaveFilePaths(std::string* out)
	{
		DZVLog_Failed(out, "FAILED: std::string* out is Null!");
		bool result = false;
		if (result = ifd::FileDialog::Instance().IsDone(m_strLabel))
		{
			if (ifd::FileDialog::Instance().HasResult())
			{
				if (out != nullptr)
					*out = ifd::FileDialog::Instance().GetResult().u8string();
				else
					out = nullptr;
			}
			ifd::FileDialog::Instance().Close();
		}
		return (result);
	}

} // namespace ZVLab