#include "DlgIconBar.h"
#include "DlgClassification.h"

CDlgIconBar::CDlgIconBar()
	: CzvLayer("CDlgIconBar")
{/*Empty*/}

void CDlgIconBar::OnAttach()
{
	m_tDialogInfo.SetDocsNoTabBar(true);
}

void CDlgIconBar::OnGUI()
{
	CzvDialog dialog("CDlgIconBar", m_tDialogInfo);

	auto pParamClassifiLayer = (CDlgClassification*)CzvApp::GetInstance()->GetLayer("CDlgClassification");
	auto& filesTable = pParamClassifiLayer->GetFileTable();
	auto& classTable = pParamClassifiLayer->GetClassTable();
	if (dialog.IconButton(ICON_FA_HOME, ImVec2(5.0f, 20.0f), 25.0f))
	{
		filesTable.Table.ResetSelectableIndex();
		classTable.Table.ResetSelectableIndex();
	}
}

GENERATE_LAYER(CDlgIconBar);