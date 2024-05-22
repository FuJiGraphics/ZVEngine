#pragma once

#include "ZVCore.h"
#include "GUI_Liberator.h"

using namespace ZVLab;

class CDlgClassification final : public ZVLab::CzvLayer
{
//// Member Variables
private:
	std::string		m_strLabel;
	TzvDialogInfo	m_tDialogInfo;
	int				m_iTotal;
	int				m_iClassified;
	int				m_iIndex;

//// Member Functions
public:
	virtual void OnAttach() override;
	virtual void OnGUI() override;
};
