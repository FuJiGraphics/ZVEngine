#include "ZVDialog.h"
#include "../ZVimguiInterface.h"

namespace ZVLab {

	bool		CZVDialog::s_FirstInit = true;
	std::string CZVDialog::s_currDialog;

	CZVDialog::CZVDialog(const std::string& name)
		: m_DialogName(name)
	{
		this->Synchronization();
	}

	CZVDialog::~CZVDialog()
	{
		if (s_currDialog == m_DialogName)
		{
			s_FirstInit = true;
			CZVimguiInterface::End();
		}
	}

	bool CZVDialog::Button(const std::string& name, float w, float h)
	{
		this->Synchronization();
		return (CZVimguiInterface::Button(name.c_str(), w, h));
	}

	bool CZVDialog::Button(const std::string& name, float w, float h, float posX, float posY)
	{
		this->Synchronization();
		return (CZVimguiInterface::Button(name.c_str(), w, h, posX, posY));
	}

	void CZVDialog::Synchronization()
	{
		if (s_currDialog != m_DialogName || s_FirstInit)
		{
			if (s_FirstInit)
				s_FirstInit = false;
			else
				CZVimguiInterface::End(); 
			s_currDialog = m_DialogName;
			CZVimguiInterface::Begin(m_DialogName);
		}
	}

} // namespace ZVLab

