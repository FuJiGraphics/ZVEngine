#include "ZVDialog.h"
#include "../ZVimguiManager.h"

namespace ZVLab {

	bool		CzvDialog::s_bFirstInit = true;
	std::string CzvDialog::s_strCurrDialog;

	CzvDialog::CzvDialog(const std::string& label, const TzvDialogInfo& options)
		: m_strLabel(label)
		, m_tPosition()
		, m_tSize()
		, m_bIsUnFolded(true)
		, m_tOptions(options)
	{
		ZVLOG_FAILED(label.size(), "FAILED: Label length must be greater than or equal to 0.");
		this->Synchronization();
	}

	CzvDialog::CzvDialog(const std::string& label,
						 const ImVec2& position,
						 const ImVec2& size,
						 const TzvDialogInfo& options)
		: m_strLabel(label)
		, m_tPosition(position)
		, m_tSize(size)
		, m_bIsUnFolded(true)
		, m_tOptions(options)
	{
		ZVLOG_FAILED(label.size(), "FAILED: Label length must be greater than or equal to 0.");
		this->Synchronization();
	}

	CzvDialog::~CzvDialog()
	{
		if (s_strCurrDialog == m_strLabel)
		{
			// Release a dialog
			s_bFirstInit = true;
			ImGui::End();
			s_strCurrDialog.clear();
		}
	}

	bool CzvDialog::IsFolded() const
	{
		return (!m_bIsUnFolded);
	}

	bool CzvDialog::IsUnFolded() const
	{
		return (m_bIsUnFolded);
	}

	bool CzvDialog::Button(const std::string& name, float w, float h)
	{
		if (this->Synchronization())
		{
			CZVButton button(name, w, h);
			return (button.Bind());
		}
		return (false);
	}

	bool CzvDialog::Button(const std::string& name, float w, float h, float posX, float posY)
	{
		if (this->Synchronization())
		{
			CZVButton button(name, w, h, posX, posY);
			return (button.Bind());
		}
		return (false);
	}

	bool CzvDialog::Button(CZVButton& button)
	{
		if (this->Synchronization())
		{
			return (button.Bind());
		}
		return (false);
	}

	bool CzvDialog::Synchronization()
	{
		if (s_strCurrDialog != m_strLabel || s_bFirstInit)
		{
			if (s_bFirstInit)
				s_bFirstInit = false;
			else
			{
				ImGui::End();
			}
			s_strCurrDialog = m_strLabel;
			return (m_bIsUnFolded = ImGui::Begin(m_strLabel.c_str(), NULL, m_tOptions.GetOptions()));
		}
		return (m_bIsUnFolded);
	}

} // namespace ZVLab

