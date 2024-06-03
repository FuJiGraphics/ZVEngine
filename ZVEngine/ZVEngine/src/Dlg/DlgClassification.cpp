#include "DlgClassification.h"
#include "DlgParameterSetup.h"

CDlgClassification::CDlgClassification()
	: CzvLayer("CDlgClassification")
	, m_tDialogInfo()
	, m_tClassTableInfo()
	, m_tSelectableInfo()
	, m_ClassTable("CDlgClassification_ClassTable")
	, m_iTotal(0)
	, m_iClassified(0)
	, m_iIndex(0)
{/*Empty*/}

void CDlgClassification::OnAttach()
{
	// Set Classification Table Info
	m_tClassTableInfo.SetResizable(true);
	m_tClassTableInfo.SetSizingFixedSame(true);
	m_tClassTableInfo.SetHighlightHoveredColumn(true);
	m_tClassTableInfo.SetBorders(true);
	m_tClassTableInfo.SetArrangeIndexed(true);
	m_tClassTableInfo.SetReorderable(true);
	m_tClassTableInfo.SetSizingFixedFit(true);
	m_tClassTableInfo.SetNoHostExtendX(true);
	// Set Classification Selectable info
	m_tSelectableInfo.SetSpanAllColumns(true);
	m_tSelectableInfo.SetAllowOverlap(true);
	m_tSelectableInfo.SetAllowItemOverlap(true);
	// Set ClassTable
	m_ClassTable.SetOptions(m_tClassTableInfo);
	m_ClassTable.SetSelectable(true, m_tSelectableInfo);
	m_ClassTable.SetHeaders({ "Name", "Class" });
	// Data Count Info
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
	std::vector<const char*> comboSet_separate{ "AAA", "BBB" };
	std::vector<const char*> comboSet_index{ "ALL", "0", "1" };
	CzvComboBox box(comboSet_index);
	result = dlg.ComboBox("Separate", comboSet_separate, comboInfo); DzvUI_SameLine
	result = dlg.ComboBox("index", comboSet_index, comboInfo);

	CzvImguiManager::SetDockspace(dlg);
	auto pParamSetupLayer = (CDlgParameterSetup*)CzvApp::GetInstance()->GetLayer("CDlgParameterSetup");

	// Generate Dialog, table
	auto& vImagePaths = pParamSetupLayer->GetImagePaths();
	auto& tParamChunk = pParamSetupLayer->GetParamChunk();
	m_ClassTable["Name"].SetItem(vImagePaths);
	m_ClassTable["Class"].SetItem(comboSet_index);

	TzvDialogInfo dlg_ClassTable_info;
	dlg_ClassTable_info.SetDocsNoTabBar(true);
	CzvDialog dlg_ClassTable(m_ClassTable.GetLabel(), dlg_ClassTable_info);
	dlg_ClassTable.Table(m_ClassTable);

	// 경로 백슬래시 체크 후 없을 경우 붙여주는 로직
	if (!vImagePaths.empty())
	{
		int iSel = m_ClassTable.GetSelectYaxisIndex();
		std::string strPath = m_ClassTable["Name"][iSel].GetLabel();
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