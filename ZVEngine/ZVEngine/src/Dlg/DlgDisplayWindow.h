#pragma once

#include "ZVCore.h"
#include "GUI_Liberator.h"

using namespace ZVLab;

class CDlgDisplayWindow final : public ZVLab::CzvLayer
{
//// Member Variables
private:
	std::string		m_strLabel;
	CzvImage		m_cImage;
	TzvDialogInfo	m_tDialogInfo;

//// Member Functions
public:
	virtual void OnAttach() override;
	virtual void OnGUI() override;
};
