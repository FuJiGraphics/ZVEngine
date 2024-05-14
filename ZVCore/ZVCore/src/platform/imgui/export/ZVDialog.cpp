#include "ZVDialog.h"
#include "../ZVimguiManager.h"

namespace ZVLab {
//----------------------------------------------------
// Static Variables
//----------------------------------------------------
	namespace { /// static variable
		static bool					s_bFirstEntryScope = true;
		static bool					s_bFirstEntryScopeChild = true;
		static TzvDialogChunk		s_CurrDialogData;
		static TzvDialogChunk		s_CurrDialogChildData;
		static unsigned int			s_unDialogCount = 0;
		static unsigned int			s_unDialogChildCount = 0;
	}


//----------------------------------------------------
// Dialog
//----------------------------------------------------
	// constructors, destructors
	CzvDialog::CzvDialog(const std::string& label)
		: m_tData{ label, {}, {}, true, {} }
	{
		DZVLog_Failed(label.size(), "FAILED: Label length must be than or equal to 0.");
		this->Synchronization();
		s_unDialogCount++;
		DZVLog_Failed((s_unDialogCount > 0), 
					 "FAILED: Unexpected Error! Dialog Count is not greater than 0 \"s_nuiDialogCount = {0}\"", 
					 s_unDialogCount);
	}

	CzvDialog::CzvDialog(const std::string& label, const TzvDialogInfo& options)
		: m_tData{ label, {}, {}, true, options }
	{
		DZVLog_Failed(label.size(), "FAILED: Label length must be greater than or equal to 0.");
		this->Synchronization();
		s_unDialogCount++;
		DZVLog_Failed((s_unDialogCount > 0),
					 "FAILED: Unexpected Error! Dialog Count is not greater than 0 \"s_nuiDialogCount = {0}\"",
					 s_unDialogCount);
	}

	CzvDialog::CzvDialog(const std::string& label, const ImVec2& size)
		: m_tData{ label, size, {}, true, {} }
	{
		DZVLog_Failed(label.size(), "FAILED: Label length must be greater than or equal to 0.");
		this->Synchronization();
		s_unDialogCount++;
		DZVLog_Failed((s_unDialogCount > 0),
					 "FAILED: Unexpected Error! Dialog Count is not greater than 0 \"s_nuiDialogCount = {0}\"",
					 s_unDialogCount);
	}

	CzvDialog::CzvDialog(const std::string& label, const ImVec2& size, const TzvDialogInfo& options)
		: m_tData{ label, size, {}, true, options }
	{
		DZVLog_Failed(label.size(), "FAILED: Label length must be greater than or equal to 0.");
		this->Synchronization();
		s_unDialogCount++;
		DZVLog_Failed((s_unDialogCount > 0),
					 "FAILED: Unexpected Error! Dialog Count is not greater than 0 \"s_nuiDialogCount = {0}\"",
					 s_unDialogCount);
	}

	CzvDialog::CzvDialog(const std::string& label, const ImVec2& size, const ImVec2& position)
		: m_tData{ label, size, position, true, {} }
	{
		DZVLog_Failed(label.size(), "FAILED: Label length must be greater than or equal to 0.");
		this->Synchronization();
		s_unDialogCount++;
		DZVLog_Failed((s_unDialogCount > 0),
					 "FAILED: Unexpected Error! Dialog Count is not greater than 0 \"s_nuiDialogCount = {0}\"",
					 s_unDialogCount);
	}

	CzvDialog::CzvDialog(const std::string& label, const ImVec2& size, const ImVec2& position, const TzvDialogInfo& options)
		: m_tData{ label, size, position, true, options }
	{
		DZVLog_Failed(label.size(), "FAILED: Label length must be greater than or equal to 0.");
		this->Synchronization();
		s_unDialogCount++;
		DZVLog_Failed((s_unDialogCount > 0),
					 "FAILED: Unexpected Error! Dialog Count is not greater than 0 \"s_nuiDialogCount = {0}\"",
					 s_unDialogCount);
	}

	CzvDialog::CzvDialog(const TzvDialogChunk& data)
		: m_tData{data.strLabel, data.optSize, data.optPosition, data.bIsUnFolded, data.tOptions}
	{ /*Empty*/ }

	CzvDialog::~CzvDialog()
	{
		if (s_CurrDialogData.strLabel == m_tData.strLabel)
		{
			// Release a dialog
			s_bFirstEntryScope = true;
			ImGui::End();
			s_CurrDialogData.strLabel.clear();
		}
		s_unDialogCount--;
		DZVLog_Failed((s_unDialogCount >= 0),
					 "FAILED: Unexpected Error! Dialog Count is less than 0 \"s_nuiDialogCount = {0}\"",
					 s_unDialogCount);
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
		if (s_CurrDialogData.strLabel != m_tData.strLabel || s_bFirstEntryScope)
		{
			if (s_bFirstEntryScope)
				s_bFirstEntryScope = false;
			else
				ImGui::End();

			if (m_tData.optPosition.has_value())
			{
				ImGui::SetNextWindowPos(*m_tData.optPosition, ImGuiCond_Once);
			}
			if (m_tData.optSize.has_value())
			{
				ImGui::SetNextWindowSize(*m_tData.optSize, ImGuiCond_Once);
			}
			s_CurrDialogData.strLabel = m_tData.strLabel;
			s_CurrDialogData.optSize = m_tData.optSize;
			s_CurrDialogData.optPosition = m_tData.optPosition;
			s_CurrDialogData.bIsUnFolded = m_tData.bIsUnFolded;
			s_CurrDialogData.tOptions = m_tData.tOptions;
			return (m_tData.bIsUnFolded = ImGui::Begin(m_tData.strLabel.c_str(), NULL, m_tData.tOptions.GetOptions()));
		}
		return (m_tData.bIsUnFolded);
	}


} // namespace ZVLab

