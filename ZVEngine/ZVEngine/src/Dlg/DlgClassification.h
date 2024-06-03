#pragma once

#include "ZVCore.h"
#include "GUI_Liberator.h"

using namespace ZVLab;

class CDlgClassification final : public ZVLab::CzvLayer
{
//// Member Variables
private:
	TzvDialogInfo		m_tDialogInfo;
	TzvTableInfo		m_tClassTableInfo;
	TzvSelectableInfo	m_tSelectableInfo;
	CzvTable			m_ClassTable;
	int					m_iTotal;
	int					m_iClassified;
	int					m_iIndex;

//// Member Functions
public:
	CDlgClassification();

	virtual void OnAttach() override;
	virtual void OnGUI() override;
};
