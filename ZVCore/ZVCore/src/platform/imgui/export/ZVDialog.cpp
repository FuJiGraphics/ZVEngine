#include "ZVDialog.h"
#include "../ZVimguiInterface.h"

namespace ZVLab {

	bool		CZVDialog::s_FirstInit = true;
	std::string CZVDialog::s_currDialog;

	CZVDialog::CZVDialog(const std::string& label)
		: m_DialogLabel(label)
		, m_isUnFolded(true)
	{
		ZVLOG_FAILED(label.size(), "FAILED: Label length must be greater than or equal to 0.");
		this->Synchronization();
	}

	CZVDialog::~CZVDialog()
	{
		if (s_currDialog == m_DialogLabel)
		{
			s_FirstInit = true;
			CZVimguiInterface::End();
			s_currDialog.clear();
		}
	}

	bool CZVDialog::Folded() const
	{
		return (!m_isUnFolded);
	}

	bool CZVDialog::UnFolded() const
	{
		return (m_isUnFolded);
	}

	bool CZVDialog::Button(const std::string& name, float w, float h)
	{
		if (this->Synchronization())
		{
			CZVButton button(name, w, h);
			return (button.IsClicked());
		}
		return (false);
	}

	bool CZVDialog::Button(const std::string& name, float w, float h, float posX, float posY)
	{
		if (this->Synchronization())
		{
			CZVButton button(name, w, h, posX, posY);
			return (button.IsClicked());
		}
		return (false);
	}

	bool CZVDialog::Button(const CZVButton& button)
	{
		if (this->Synchronization())
		{
			return (button.IsClicked());
		}
		return (false);
	}

	bool CZVDialog::Synchronization()
	{
		if (s_currDialog != m_DialogLabel || s_FirstInit)
		{
			if (s_FirstInit)
				s_FirstInit = false;
			else
				CZVimguiInterface::End(); 
			s_currDialog = m_DialogLabel;
			return (m_isUnFolded = CZVimguiInterface::Begin(m_DialogLabel.c_str()));
		}
		return (m_isUnFolded);
	}

} // namespace ZVLab

