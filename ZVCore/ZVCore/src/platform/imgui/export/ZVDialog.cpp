#include "ZVDialog.h"
#include "../ZVimguiManager.h"

namespace ZVLab {

/// static variable
	bool			CzvDialog::s_bFirstEntryScope = true;
	std::string		CzvDialog::s_strCurrDialog;
	unsigned int	CzvDialog::s_nuiDialogCount = 0;

// constructors, destructors
	CzvDialog::CzvDialog(const std::string& label)
		: m_strLabel(label)
		, m_optSize()
		, m_optPosition()
		, m_bIsUnFolded(true)
		, m_tOptions()
	{
		ZVLOG_FAILED(label.size(), "FAILED: Label length must be than or equal to 0.");
		this->Synchronization();
		s_nuiDialogCount++;
		ZVLOG_FAILED((s_nuiDialogCount > 0), 
					 "FAILED: Unexpected Error! Dialog Count is not greater than 0 \"s_nuiDialogCount = {0}\"", 
					 s_nuiDialogCount);
	}

	CzvDialog::CzvDialog(const std::string& label, const TzvDialogInfo& options)
		: m_strLabel(label)
		, m_optSize()
		, m_optPosition()
		, m_bIsUnFolded(true)
		, m_tOptions(options)
	{
		ZVLOG_FAILED(label.size(), "FAILED: Label length must be greater than or equal to 0.");
		this->Synchronization();
		s_nuiDialogCount++;
		ZVLOG_FAILED((s_nuiDialogCount > 0),
					 "FAILED: Unexpected Error! Dialog Count is not greater than 0 \"s_nuiDialogCount = {0}\"",
					 s_nuiDialogCount);
	}

	CzvDialog::CzvDialog(const std::string& label, const ImVec2& size)
		: m_strLabel(label)
		, m_optSize(size)
		, m_optPosition()
		, m_bIsUnFolded(true)
		, m_tOptions()
	{
		ZVLOG_FAILED(label.size(), "FAILED: Label length must be greater than or equal to 0.");
		this->Synchronization();
		s_nuiDialogCount++;
		ZVLOG_FAILED((s_nuiDialogCount > 0),
					 "FAILED: Unexpected Error! Dialog Count is not greater than 0 \"s_nuiDialogCount = {0}\"",
					 s_nuiDialogCount);
	}

	CzvDialog::CzvDialog(const std::string& label, const ImVec2& size, const TzvDialogInfo& options)
		: m_strLabel(label)
		, m_optSize(size)
		, m_optPosition()
		, m_bIsUnFolded(true)
		, m_tOptions(options)
	{
		ZVLOG_FAILED(label.size(), "FAILED: Label length must be greater than or equal to 0.");
		this->Synchronization();
		s_nuiDialogCount++;
		ZVLOG_FAILED((s_nuiDialogCount > 0),
					 "FAILED: Unexpected Error! Dialog Count is not greater than 0 \"s_nuiDialogCount = {0}\"",
					 s_nuiDialogCount);
	}

	CzvDialog::CzvDialog(const std::string& label, const ImVec2& size, const ImVec2& position)
		: m_strLabel(label)
		, m_optSize(size)
		, m_optPosition(position)
		, m_bIsUnFolded(true)
		, m_tOptions()
	{
		ZVLOG_FAILED(label.size(), "FAILED: Label length must be greater than or equal to 0.");
		this->Synchronization();
		s_nuiDialogCount++;
		ZVLOG_FAILED((s_nuiDialogCount > 0),
					 "FAILED: Unexpected Error! Dialog Count is not greater than 0 \"s_nuiDialogCount = {0}\"",
					 s_nuiDialogCount);
	}

	CzvDialog::CzvDialog(const std::string& label, const ImVec2& size, const ImVec2& position, const TzvDialogInfo& options)
		: m_strLabel(label)
		, m_optSize(size)
		, m_optPosition(position)
		, m_bIsUnFolded(true)
		, m_tOptions(options)
	{
		ZVLOG_FAILED(label.size(), "FAILED: Label length must be greater than or equal to 0.");
		this->Synchronization();
		s_nuiDialogCount++;
		ZVLOG_FAILED((s_nuiDialogCount > 0),
					 "FAILED: Unexpected Error! Dialog Count is not greater than 0 \"s_nuiDialogCount = {0}\"",
					 s_nuiDialogCount);
	}

	CzvDialog::~CzvDialog()
	{
		if (s_strCurrDialog == m_strLabel)
		{
			// Release a dialog
			s_bFirstEntryScope = true;
			ImGui::End();
			s_strCurrDialog.clear();
		}
		s_nuiDialogCount--;
		ZVLOG_FAILED((s_nuiDialogCount >= 0),
					 "FAILED: Unexpected Error! Dialog Count is less than 0 \"s_nuiDialogCount = {0}\"",
					 s_nuiDialogCount);
	}

// interfaces
	bool CzvDialog::Button(const std::string& label)
	{
		if (this->Synchronization())
		{
			CzvButton button(label);
			return (button.Bind());
		}
		return (false);
	}

	bool CzvDialog::Button(const std::string& label, const ImVec2& size)
	{
		if (this->Synchronization())
		{
			CzvButton button(label, size);
			return (button.Bind());
		}
		return (false);
	}

	bool CzvDialog::Button(const std::string& label, const ImVec2& size, const ImVec2& position)
	{
		if (this->Synchronization())
		{
			CzvButton button(label, size, position);
			return (button.Bind());
		}
		return (false);
	}

	bool CzvDialog::Button(CzvButton& button)
	{
		if (this->Synchronization())
		{
			return (button.Bind());
		}
		return (false);
	}

/// others
	bool CzvDialog::Synchronization()
	{
		if (s_strCurrDialog != m_strLabel || s_bFirstEntryScope)
		{
			if (s_bFirstEntryScope)
				s_bFirstEntryScope = false;
			else
				ImGui::End();

			if (m_optPosition.has_value())
			{
				ImGui::SetNextWindowPos(*m_optPosition, ImGuiCond_Once);
			}
			if (m_optSize.has_value())
			{
				ImGui::SetNextWindowSize(*m_optSize, ImGuiCond_Once);
			}
			s_strCurrDialog = m_strLabel;
			return (m_bIsUnFolded = ImGui::Begin(m_strLabel.c_str(), NULL, m_tOptions.GetOptions()));
		}
		return (m_bIsUnFolded);
	}

} // namespace ZVLab

