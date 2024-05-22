#pragma once

#include "ZVCore.h"
#include "GUI_Liberator.h"

using namespace ZVLab;

class CDlgSidebarLeft final : public ZVLab::CzvLayer
{
//// Member Variables
private:
	TzvDialogInfo m_infoDialog;

//// Member Functions
public:
	CDlgSidebarLeft();
	virtual void OnAttach() override;
	virtual void OnGUI() override;

};