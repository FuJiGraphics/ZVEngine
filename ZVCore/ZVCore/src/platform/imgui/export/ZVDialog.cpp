#include "ZVDialog.h"
#include "ZVImage.h"
#include "ZVButton.h"
#include "ZVImageButton.h"
#include "ZVToggleButton.h"
#include "ZVComboBox.h"
#include "../ZVimguiManager.h"

namespace { /// statics
	static bool						s_bFirstEntryScope = true;
	static ZVLab::CzvDialog*		s_pCurrDialog = nullptr;
	static unsigned int				s_unDialogCount = 0;
	static std::optional<ImVec2>	s_optPrevItemPos;
#define	DRegistRuntimeDialog(ptr)	(s_pCurrDialog = ptr);
#define	DUnRegistRuntimeDialog()	(s_pCurrDialog = nullptr);
#define	DIsCurrentRegistDialog(ptr)	(s_pCurrDialog == ptr)
#define DRegistStaticItemPos(pos)	(s_optPrevItemPos = pos);
#define DUnRegistStaticItemPos		if(DIsRegistedStaticItemPos){ ImGui::SetCursorPos(*s_optPrevItemPos); s_optPrevItemPos.reset(); }
#define DIsRegistedStaticItemPos	(s_optPrevItemPos.has_value())
#define DGetStaticItemPos			(*s_optPrevItemPos)
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
	void CzvDialog::Text(const char* fmt, ...)
	{
		bool result;
		this->Synchronization();
		va_list args;
		va_start(args, fmt);
		if (m_tOptions.IsActivated(ezvDialogFlags_MenuBar) && this->IsUnFolded())
		{
			m_MenuBar.UnBind();
			ImGui::TextV(fmt, args);
			m_MenuBar.Bind();
		}
		else
		{
			ImGui::TextV(fmt, args);
		}
		va_end(args);
		DUnRegistStaticItemPos
	}

	bool CzvDialog::Button(const std::string& label)
	{
		bool result = false;
		CzvButton button(label);
		result = this->Binding(&button);
		return (result);
	}

	bool CzvDialog::Button(const std::string& label, const ImVec2& size)
	{
		bool result = false;
		CzvButton button(label, size);
		result = this->Binding(&button);
		return (result);
	}

	bool CzvDialog::Button(const std::string& label, const ImVec2& size, const ImVec2& position)
	{
		bool result = false;
		CzvButton button(label, size, position);
		result = this->Binding(&button);
		return (result);
	}

	bool CzvDialog::Button(CzvButton& button)
	{
		bool result = false;
		result = this->Binding(&button);
		return (result);
	}

	bool CzvDialog::ToggleButton()
	{
		bool result = false;
		CzvToggleButton button;
		result = this->Binding(&button);
		return (result);
	}

	bool CzvDialog::ToggleButton(const std::string& label)
	{
		bool result = false;
		CzvToggleButton button(label);
		result = this->Binding(&button);
		return (result);
	}

	bool CzvDialog::ToggleButton(const std::string& label, const ImVec2& size)
	{
		bool result = false;
		CzvToggleButton button(label, size);
		result = this->Binding(&button);
		return (result);
	}

	bool CzvDialog::ToggleButton(const std::string& label, const ImVec2& size, const ImVec2& position)
	{
		bool result = false;
		CzvToggleButton button(label, size, position);
		result = this->Binding(&button);
		return (result);
	}

	bool CzvDialog::ToggleButton(CzvToggleButton& button)
	{
		bool result = false;
		result = this->Binding(&button);
		return (result);
	}

	bool CzvDialog::ImageButton(CzvImageButton& button)
	{
		bool result = false;
		result = this->Binding(&button);
		return (result);
	}

	void CzvDialog::Image(const CzvImage& image, const ImVec2& size)
	{
		this->Synchronization();
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
		DUnRegistStaticItemPos
	}

	bool CzvDialog::MenuItem(const std::string& label)
	{
		DUnRegistStaticItemPos
		bool result = false;
		this->Synchronization();
		if (m_tOptions.IsActivated(ezvDialogFlags_MenuBar) && this->IsUnFolded())
			result = ImGui::MenuItem(label.c_str());
		return (result);
	}

	std::string CzvDialog::ComboBox(const std::string& label, 
									const Args<const char*>& item_list, 
									const TzvComboBoxInfo& options)
	{
		std::string select_item;
		CzvComboBox combo(label, options);
		combo.SetItems(item_list);
		this->Synchronization();
		if (m_tOptions.IsActivated(ezvDialogFlags_MenuBar) && this->IsUnFolded())
		{
			m_MenuBar.UnBind();
			select_item = combo.Bind();
			m_MenuBar.Bind();
		}
		else
		{
			select_item = combo.Bind();
		}
		DUnRegistStaticItemPos
		return (select_item);
	}

	void CzvDialog::SetNextPos(const ImVec2& pos)
	{
		this->Synchronization();
		if (m_tOptions.IsActivated(ezvDialogFlags_MenuBar) && this->IsUnFolded())
			m_MenuBar.UnBind();
		auto& prevPos = ImGui::GetCursorPos();
		DRegistStaticItemPos(prevPos);
		ImGui::SetCursorPos(pos);
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

	bool CzvDialog::Binding(CzvButton* target)
	{
		bool result = false;
		this->Synchronization();
		if (m_tOptions.IsActivated(ezvDialogFlags_MenuBar) && this->IsUnFolded())
		{
			m_MenuBar.UnBind();
			result = target->Bind();
			m_MenuBar.Bind();
		}
		else
		{
			result = target->Bind();
		}
		DUnRegistStaticItemPos
		return (result);
	}

} // namespace ZVLab

