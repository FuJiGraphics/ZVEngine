#pragma once

#include "ZVCore.h"
#include "GUI_Liberator.h"

using namespace ZVLab;

struct TzvTableData
{
	CzvTable			Table;
	TzvTableInfo		tTableInfo;
	TzvSelectableInfo	tSelectableInfo;
};

class CDlgClassification final : public ZVLab::CzvLayer
{
//// Member Variables
private:
	TzvDialogInfo					m_tDialogInfo;
	TzvTableData					m_tFilesTable;
	TzvTableData					m_tClassTable;
	int								m_iTotal;
	int								m_iClassified;
	int								m_iIndex;

//// Member Functions
public:
	CDlgClassification();

	virtual void	OnAttach() override;
	virtual void	OnGUI() override;

	TzvTableData&	GetFileTable();
	TzvTableData&	GetClassTable();
};
