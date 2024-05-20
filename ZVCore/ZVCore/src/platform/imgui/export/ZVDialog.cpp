#include "ZVDialog.h"
#include "../ZVimguiManager.h"

namespace { /// statics
	static bool					s_bFirstEntryScope = true;
	static ZVLab::CzvDialog*	s_pCurrDialog = nullptr;
	static unsigned int			s_unDialogCount = 0;
#define	DRegistRuntimeDialog(ptr)	(s_pCurrDialog = ptr);
#define	DUnRegistRuntimeDialog()	(s_pCurrDialog = nullptr);
#define	DIsCurrentRegistDialog(ptr)	(s_pCurrDialog == ptr)
}

namespace ZVLab {
//----------------------------------------------------
// Dialog
//----------------------------------------------------
	// constructors, destructors
	CzvDialog::CzvDialog(const std::string& label)
		: m_strLabel(label)
		, m_optSize()
		, m_optPosition()
		, m_bIsUnFolded(false)
		, m_MenuBar(label)
		, m_tOptions()
		, m_tDockspaceOptions()
	{
		DZVLog_Failed(label.size(), "FAILED: Label length must be than or equal to 0.");
		this->Synchronization();
		s_unDialogCount++;
		DZVLog_Failed((s_unDialogCount > 0), 
					 "FAILED: Unexpected Error! Dialog Count is not greater than 0 \"s_nuiDialogCount = {0}\"", 
					 s_unDialogCount);
	}

	CzvDialog::CzvDialog(const std::string& label, const TzvDialogInfo& options)
		: m_strLabel(label)
		, m_optSize()
		, m_optPosition()
		, m_bIsUnFolded(false)
		, m_MenuBar(label)
		, m_tOptions(options)
		, m_tDockspaceOptions()
	{
		DZVLog_Failed(label.size(), "FAILED: Label length must be greater than or equal to 0.");
		this->Synchronization();
		s_unDialogCount++;
		DZVLog_Failed((s_unDialogCount > 0),
					 "FAILED: Unexpected Error! Dialog Count is not greater than 0 \"s_nuiDialogCount = {0}\"",
					 s_unDialogCount);
	}

	CzvDialog::CzvDialog(const std::string& label, const ImVec2& size)
		: m_strLabel(label)
		, m_optSize(size)
		, m_optPosition()
		, m_bIsUnFolded(false)
		, m_MenuBar(label)
		, m_tOptions()
		, m_tDockspaceOptions()
	{
		DZVLog_Failed(label.size(), "FAILED: Label length must be greater than or equal to 0.");
		this->Synchronization();
		s_unDialogCount++;
		DZVLog_Failed((s_unDialogCount > 0),
					 "FAILED: Unexpected Error! Dialog Count is not greater than 0 \"s_nuiDialogCount = {0}\"",
					 s_unDialogCount);
	}

	CzvDialog::CzvDialog(const std::string& label, const ImVec2& size, const TzvDialogInfo& options)
		: m_strLabel(label)
		, m_optSize(size)
		, m_optPosition()
		, m_bIsUnFolded(false)
		, m_MenuBar(label)
		, m_tOptions(options)
		, m_tDockspaceOptions()
	{
		DZVLog_Failed(label.size(), "FAILED: Label length must be greater than or equal to 0.");
		this->Synchronization();
		s_unDialogCount++;
		DZVLog_Failed((s_unDialogCount > 0),
					 "FAILED: Unexpected Error! Dialog Count is not greater than 0 \"s_nuiDialogCount = {0}\"",
					 s_unDialogCount);
	}

	CzvDialog::CzvDialog(const std::string& label, const ImVec2& size, const ImVec2& position)
		: m_strLabel(label)
		, m_optSize(size)
		, m_optPosition(position)
		, m_bIsUnFolded(false)
		, m_MenuBar(label)
		, m_tOptions()
		, m_tDockspaceOptions()
	{
		DZVLog_Failed(label.size(), "FAILED: Label length must be greater than or equal to 0.");
		this->Synchronization();
		s_unDialogCount++;
		DZVLog_Failed((s_unDialogCount > 0),
					 "FAILED: Unexpected Error! Dialog Count is not greater than 0 \"s_nuiDialogCount = {0}\"",
					 s_unDialogCount);
	}

	CzvDialog::CzvDialog(const std::string& label, const ImVec2& size, const ImVec2& position, const TzvDialogInfo& options)
		: m_strLabel(label)
		, m_optSize(size)
		, m_optPosition(position)
		, m_bIsUnFolded(false)
		, m_MenuBar(label)
		, m_tOptions(options)
		, m_tDockspaceOptions()
	{
		DZVLog_Failed(label.size(), "FAILED: Label length must be greater than or equal to 0.");
		this->Synchronization();
		s_unDialogCount++;
		DZVLog_Failed((s_unDialogCount > 0),
					 "FAILED: Unexpected Error! Dialog Count is not greater than 0 \"s_nuiDialogCount = {0}\"",
					 s_unDialogCount);
	}

	CzvDialog::~CzvDialog()
	{
		if (DIsCurrentRegistDialog(this))
		{
			s_bFirstEntryScope = true;

			// Release a menubar
			if (m_tOptions.IsActivated(ezvDialogFlags_MenuBar) && m_bIsUnFolded)
				m_MenuBar.UnBind();

			// Release a dialog
			ImGui::End();
			DUnRegistRuntimeDialog();
		}
		s_unDialogCount--;
		DZVLog_Failed((s_unDialogCount >= 0),
					 "FAILED: Unexpected Error! Dialog Count is less than 0 \"s_nuiDialogCount = {0}\"",
					 s_unDialogCount);
	}

	bool CzvDialog::IsWindowFocused()
	{
		TzvWindowFocusedInfo info;
		return (this->IsWindowFocused(info));
	}

	bool CzvDialog::IsWindowFocused(const TzvWindowFocusedInfo& options)
	{
		bool result = false;
		if (this->Synchronization())
		{
			if (ImGui::IsWindowFocused(options.GetOptions()))
			{
				result = true;
			}
		}
		return (result);
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

	void CzvDialog::Image(const CzvImage& image, const ImVec2& size)
	{
		if (m_tOptions.IsActivated(ezvDialogFlags_MenuBar) && this->IsUnFolded())
		{
			m_MenuBar.UnBind();
			image.Bind(size);
			m_MenuBar.Bind();
		}
		else
		{
			image.Bind(size);
		}
	}

	bool CzvDialog::MenuItem(const std::string& label)
	{
		if (this->Synchronization())
		{
			if (m_tOptions.IsActivated(ezvDialogFlags_MenuBar))
				return (ImGui::MenuItem(label.c_str()));
		}
		return (false);
	}

	/// others
	bool CzvDialog::Synchronization()
	{
		bool result = false;
		if (!DIsCurrentRegistDialog(this) || s_bFirstEntryScope)
		{
			if (s_bFirstEntryScope)
				s_bFirstEntryScope = false;
			else
			{
				ImGui::End();
				DUnRegistRuntimeDialog();
			}

			if (m_optPosition.has_value())
			{
				ImGui::SetNextWindowPos(*m_optPosition, ImGuiCond_Once);
			}
			if (m_optSize.has_value())
			{
				ImGui::SetNextWindowSize(*m_optSize, ImGuiCond_Once);
			}

			// 현재 Dialog 정보 등록
			DRegistRuntimeDialog(this);
			CzvImguiManager::SetDockspaceOptionForNextDialog(m_tOptions.GetExtensionOptions());
			result = ImGui::Begin(m_strLabel.c_str(), NULL, m_tOptions.GetOptions());
			m_bIsUnFolded = !ImGui::IsWindowCollapsed();

			// Menubar 활성화
			if (m_tOptions.IsActivated(ezvDialogFlags_MenuBar) && m_bIsUnFolded)
				m_MenuBar.Bind();
		}
		return (result);
	}

} // namespace ZVLab

