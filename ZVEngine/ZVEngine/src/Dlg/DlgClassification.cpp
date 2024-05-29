#include "DlgClassification.h"
#include "DlgParameterSetup.h"

CDlgClassification::CDlgClassification()
	: CzvLayer("CDlgClassification")
{
}

void CDlgClassification::OnAttach()
{
	m_iTotal = 0;
	m_iClassified = 0;
	m_iIndex = 0;
};

void CDlgClassification::OnGUI()
{
	DProfile_StartRecord("Classification");
	CzvDialog dlg("Classification", m_tDialogInfo);
	{
		DzvUI_Bullet_Text("Total: %d", m_iTotal);
		DzvUI_Bullet_Text("Classified: %d", m_iClassified);
		DzvUI_Bullet_Text("Index: %d", m_iIndex);
	}

	std::string result;

	TzvComboBoxInfo comboInfo;
	comboInfo.SetHeightSmall(true);
	comboInfo.SetWidthFitPreview(true);
	result = dlg.ComboBox("Separate", { "AAA", "BBB" }, comboInfo); DzvUI_SameLine
	result = dlg.ComboBox("index", { "ALL", "0", "1" }, comboInfo);

	CzvImguiManager::SetDockspace(dlg);
	/*-----------------------------------------------------------------*/
	auto pParamSetupLayer = (CDlgParameterSetup*)CzvApp::GetInstance()->GetLayer("CDlgParameterSetup");

	// Generate Dialog, table
	CzvTable table1("Table");
	table1.SetHeaders({ "ID", "Name", "Class" });
	table1["ID"].AddItem("Hello %d", 20);

	TzvTableInfo info_table2;
	info_table2.SetResizable(true);
	info_table2.SetSizingFixedSame(true);
	info_table2.SetHighlightHoveredColumn(true);
	info_table2.SetBorders(true);
	info_table2.SetArrangeIndexed(true);
	info_table2.SetReorderable(true);
	info_table2.SetSizingFixedFit(true);
	info_table2.SetNoHostExtendX(true);

	CzvTable table2("table_sorting", info_table2);
	TzvSelectableInfo sel_info;
	sel_info.SetSpanAllColumns(true);
	sel_info.SetAllowOverlap(true);
	sel_info.SetAllowItemOverlap(true);
	table2.SetSelectable(true, sel_info);
	table2.SetHeaders({ "Name", "Class" });

	auto& vImagePaths = pParamSetupLayer->GetImagePaths();
	auto& tParamChunk = pParamSetupLayer->GetParamChunk();
	table2["Name"].AddItem(vImagePaths);

	CzvDialog dlg_table1("Table1");
	dlg_table1.Table(table1);
	CzvDialog dlg_table2("Table2");
	dlg_table2.Table(table2);

	if (!vImagePaths.empty())
	{
		int iSel = table2.GetSelectYaxisIndex();
		std::string strPath = table2["Name"][iSel].GetLabel();
		auto layer = (CDlgDisplayWindow*)CzvApp::GetInstance()->GetLayer("CDlgDisplayWindow");
		char cCheckBackSlash = *(tParamChunk.strLoadingPath.end() - 1);
		if (cCheckBackSlash != '\\')
			tParamChunk.strLoadingPath.push_back('\\');
		layer->Display(tParamChunk.strLoadingPath + strPath, 500, 500);
	}

	m_iTotal = vImagePaths.size();
	m_iIndex = vImagePaths.size();
	m_iClassified = 0;

	DProfile_EndRecord;
};

GENERATE_LAYER(CDlgClassification);