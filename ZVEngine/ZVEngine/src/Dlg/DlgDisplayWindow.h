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
	CzvFileDialog	m_FileDialog;

//// Member Functions
public:
	CDlgDisplayWindow();
	virtual void OnAttach() override;
	virtual void OnGUI() override;
};
