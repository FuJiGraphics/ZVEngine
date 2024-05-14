#pragma once

#include "ZVCore.h"
#include "GUI_Liberator.h"
#include "Environment.h"

using namespace ZVLab;

class CDlgDisplayWindow final : public ZVLab::CzvLayer
{
	//// Member Variables
private:
	std::string		m_strLabel;
	CzvImage		m_cImage;

	//// Member Functions
public:
	virtual void OnAttach();
	virtual void OnGUI();
	virtual void OnMainMenuBar();
};

GENERATE_LAYER(CDlgDisplayWindow);