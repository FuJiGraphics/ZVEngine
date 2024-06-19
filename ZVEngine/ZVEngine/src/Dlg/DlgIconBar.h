#pragma once

#include "ZVCore.h"
#include "GUI_Liberator.h"

using namespace ZVLab;

class CDlgIconBar final : public ZVLab::CzvLayer
{
	//// Member Variables
private:
	TzvDialogInfo	m_tDialogInfo;

	//// Member Functions
public:
	CDlgIconBar();

	virtual void OnAttach() override;
	virtual void OnGUI() override;
};
