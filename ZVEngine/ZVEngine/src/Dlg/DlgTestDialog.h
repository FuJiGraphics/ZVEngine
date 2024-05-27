#pragma once

#include "ZVCore.h"
#include "GUI_Liberator.h"

using namespace ZVLab;

class CDlgTestDialog final : public ZVLab::CzvLayer
{
	//// Member Variables
private:

	//// Member Functions
public:
	CDlgTestDialog();
	virtual void OnAttach() override;
	virtual void OnGUI() override;
};