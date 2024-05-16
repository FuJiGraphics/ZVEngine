#include "ZVDialog.h"
#include "../ZVimguiManager.h"

namespace ZVLab {

	namespace { /// statics
		static bool					s_bFirstEntryScope = true;
		static TzvDialogChunk*		s_pCurrDialogData = nullptr;
		static unsigned int			s_unDialogCount = 0;
		static void s_RegistDialogChunk(TzvDialogChunk* data)
		{
			DZVLog_Failed(data, "FAILED: Unexpected Error! data is Null!!");
			s_pCurrDialogData = data;
		}
		static void s_UnRegistDialogChunk()
		{
			s_pCurrDialogData = nullptr;
		}
		static bool s_IsCheckCurrentRegistDialog(const TzvDialogChunk& data)
		{
			return (s_pCurrDialogData == &data);
		}
	}

//----------------------------------------------------
// Dialog
//----------------------------------------------------
	// constructors, destructors
	CzvDialog::CzvDialog(const std::string& label)
		: m_tData{ label, {}, {}, true, false, {} }
	{
		DZVLog_Failed(label.size(), "FAILED: Label length must be than or equal to 0.");
		this->Synchronization();
		s_unDialogCount++;
		DZVLog_Failed((s_unDialogCount > 0), 
					 "FAILED: Unexpected Error! Dialog Count is not greater than 0 \"s_nuiDialogCount = {0}\"", 
					 s_unDialogCount);
	}

	CzvDialog::CzvDialog(const std::string& label, const TzvDialogInfo& options)
		: m_tData{ label, {}, {}, true, false, options }
	{
		DZVLog_Failed(label.size(), "FAILED: Label length must be greater than or equal to 0.");
		this->Synchronization();
		s_unDialogCount++;
		DZVLog_Failed((s_unDialogCount > 0),
					 "FAILED: Unexpected Error! Dialog Count is not greater than 0 \"s_nuiDialogCount = {0}\"",
					 s_unDialogCount);
	}

	CzvDialog::CzvDialog(const std::string& label, const ImVec2& size)
		: m_tData{ label, size, {}, true, false, {} }
	{
		DZVLog_Failed(label.size(), "FAILED: Label length must be greater than or equal to 0.");
		this->Synchronization();
		s_unDialogCount++;
		DZVLog_Failed((s_unDialogCount > 0),
					 "FAILED: Unexpected Error! Dialog Count is not greater than 0 \"s_nuiDialogCount = {0}\"",
					 s_unDialogCount);
	}

	CzvDialog::CzvDialog(const std::string& label, const ImVec2& size, const TzvDialogInfo& options)
		: m_tData{ label, size, {}, true, false, options }
	{
		DZVLog_Failed(label.size(), "FAILED: Label length must be greater than or equal to 0.");
		this->Synchronization();
		s_unDialogCount++;
		DZVLog_Failed((s_unDialogCount > 0),
					 "FAILED: Unexpected Error! Dialog Count is not greater than 0 \"s_nuiDialogCount = {0}\"",
					 s_unDialogCount);
	}

	CzvDialog::CzvDialog(const std::string& label, const ImVec2& size, const ImVec2& position)
		: m_tData{ label, size, position, true, false, {} }
	{
		DZVLog_Failed(label.size(), "FAILED: Label length must be greater than or equal to 0.");
		this->Synchronization();
		s_unDialogCount++;
		DZVLog_Failed((s_unDialogCount > 0),
					 "FAILED: Unexpected Error! Dialog Count is not greater than 0 \"s_nuiDialogCount = {0}\"",
					 s_unDialogCount);
	}

	CzvDialog::CzvDialog(const std::string& label, const ImVec2& size, const ImVec2& position, const TzvDialogInfo& options)
		: m_tData{ label, size, position, true, false, options }
	{
		DZVLog_Failed(label.size(), "FAILED: Label length must be greater than or equal to 0.");
		this->Synchronization();
		s_unDialogCount++;
		DZVLog_Failed((s_unDialogCount > 0),
					 "FAILED: Unexpected Error! Dialog Count is not greater than 0 \"s_nuiDialogCount = {0}\"",
					 s_unDialogCount);
	}

	CzvDialog::CzvDialog(const TzvDialogChunk& data)
		: m_tData{data.strLabel, data.optSize, data.optPosition, data.bIsUnFolded, data.bIsOpenedMenubar, data.tOptions}
	{ /*Empty*/ }

	CzvDialog::~CzvDialog()
	{
		if (s_IsCheckCurrentRegistDialog(m_tData))
		{
			s_bFirstEntryScope = true;
			// end scope menubar
			this->EndMenubar(s_pCurrDialogData);
			
			// 항상 Dialog의 마지막 부분에 ImGui::End()를 해야한다.
			// Release a dialog
			if (m_tData.bIsUnFolded)
				ImGui::End();
			s_UnRegistDialogChunk();
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
		if (s_IsCheckCurrentRegistDialog(m_tData) || s_bFirstEntryScope)
		{
			if (s_bFirstEntryScope)
				s_bFirstEntryScope = false;
			else
			{
				ImGui::End();
				// 기존 Dialog Menubar 활성화 여부 확인 및 종료
				this->EndMenubar(s_pCurrDialogData);
			}
			if (m_tData.optPosition.has_value())
			{
				ImGui::SetNextWindowPos(*m_tData.optPosition, ImGuiCond_Once);
			}
			if (m_tData.optSize.has_value())
			{
				ImGui::SetNextWindowSize(*m_tData.optSize, ImGuiCond_Once);
			}

			// 현재 Dialog 정보 등록
			s_RegistDialogChunk(&m_tData);
			m_tData.bIsUnFolded = ImGui::Begin(m_tData.strLabel.c_str(), NULL, m_tData.tOptions.GetOptions());

			// Menubar 활성화
			this->BeginMenubar(&m_tData);
		}
		return (m_tData.bIsUnFolded);
	}

	void CzvDialog::BeginMenubar(TzvDialogChunk* data)
	{
		DZVLog_Failed(data, "FAILED: Unexpected Error! data is Null!!");
		if (data->tOptions.IsActivated(EzvDialogOptions::ezvDialogFlags_MenuBar) 
			&& data->bIsUnFolded)
			data->bIsOpenedMenubar = ImGui::BeginMenuBar();
	}

	void CzvDialog::EndMenubar(TzvDialogChunk* data)
	{
		DZVLog_Failed(data, "FAILED: Unexpected Error! data is Null!!");
		if ( data->bIsUnFolded
			&& data->tOptions.IsActivated(EzvDialogOptions::ezvDialogFlags_MenuBar)
			&& data->bIsOpenedMenubar)
		{
			ImGui::EndMenuBar();
			data->bIsOpenedMenubar = false;
		}
	}

} // namespace ZVLab

