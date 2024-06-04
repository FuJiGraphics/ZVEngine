#include "DlgClassification.h"
#include "DlgParameterSetup.h"

CDlgClassification::CDlgClassification()
	: CzvLayer("CDlgClassification")
	, m_tDialogInfo()
	, m_tFilesTable{ "CDlgClassification_FilesTable" }
	, m_tClassTable{ "CDlgClassification_ClassTable" }
	, m_iTotal(0)
	, m_iClassified(0)
	, m_iIndex(0)
{/*Empty*/}

void CDlgClassification::OnAttach()
{
	// Set Files Table
	m_tFilesTable.tTableInfo.SetResizable(true);
	m_tFilesTable.tTableInfo.SetSizingFixedSame(true);
	m_tFilesTable.tTableInfo.SetHighlightHoveredColumn(true);
	m_tFilesTable.tTableInfo.SetBorders(true);
	m_tFilesTable.tTableInfo.SetArrangeIndexed(true);
	m_tFilesTable.tTableInfo.SetReorderable(true);
	m_tFilesTable.tTableInfo.SetSizingFixedFit(true);
	m_tFilesTable.tTableInfo.SetNoHostExtendX(true);
	m_tFilesTable.tSelectableInfo.SetAllowOverlap(true);
	m_tFilesTable.Table.SetOptions(m_tFilesTable.tTableInfo);
	m_tFilesTable.Table.SetSelectable(true, m_tFilesTable.tSelectableInfo);
	m_tFilesTable.Table.SetHeaders({
			{ "Name", m_tFilesTable.tSelectableInfo }, 
			{"Class", m_tFilesTable.tSelectableInfo }
		});

	// Set Class Table
	m_tClassTable.tTableInfo.SetResizable(true);
	m_tClassTable.tTableInfo.SetSizingFixedSame(true);
	m_tClassTable.tTableInfo.SetHighlightHoveredColumn(true);
	m_tClassTable.tTableInfo.SetBorders(true);
	m_tClassTable.tTableInfo.SetArrangeIndexed(true);
	m_tClassTable.tTableInfo.SetReorderable(true);
	m_tClassTable.tTableInfo.SetSizingFixedFit(true);
	m_tClassTable.tTableInfo.SetNoHostExtendX(true);
	m_tClassTable.tSelectableInfo.SetAllowOverlap(true);
	m_tClassTable.Table.SetOptions(m_tClassTable.tTableInfo);
	m_tClassTable.Table.SetHeaders({
			{ "Class",   m_tClassTable.tSelectableInfo },
			{ "Hot Key", m_tClassTable.tSelectableInfo },
			{ "Count",   m_tClassTable.tSelectableInfo }
		});

	// Data Count Info
	m_iTotal = 0;
	m_iClassified = 0;
	m_iIndex = 0;
};

void CDlgClassification::OnGUI()
{
	DProfile_StartRecord("Classification");
	CzvDialog dlg("Classification", m_tDialogInfo);

	// Generate Dockspace
	CzvImguiManager::SetDockspace(dlg);
	auto pParamSetupLayer = (CDlgParameterSetup*)CzvApp::GetInstance()->GetLayer("CDlgParameterSetup");

	// Render Files Table
	TzvDialogInfo dlg_FilesTable_info;
	dlg_FilesTable_info.SetDocsNoTabBar(true);
	auto& filesTable = m_tFilesTable.Table;
	CzvDialog dlg_FilesTable(filesTable.GetLabel(), dlg_FilesTable_info);
	{
		// Render Status
		float fPanel_w = static_cast<float>(dlg_FilesTable.GetWidth()) - 30.0f;
		CzvImguiManager::BeginGroupPanel("Status", { fPanel_w, 25 });
		DzvUI_Bullet_Text("Total: %d", m_iTotal);
		DzvUI_Bullet_Text("Classified: %d", m_iClassified);
		DzvUI_Bullet_Text("Index: %d", m_iIndex);
		std::string result;
		TzvComboBoxInfo comboInfo;
		comboInfo.SetHeightSmall(true);
		comboInfo.SetWidthFitPreview(true);
		std::vector<const char*> comboSet_separate{ "AAA", "BBB" };
		std::vector<const char*> comboSet_index{ "ALL", "0", "1" };
		CzvComboBox box(comboSet_index);
			CzvImguiManager::BeginGroupPanel("Search", { fPanel_w, 40 });
				dlg_FilesTable.SetNextPos(ImVec2(30, 100));
				result = dlg_FilesTable.ComboBox("Separate", comboSet_separate, comboInfo);
				dlg_FilesTable.SetNextPos(ImVec2(150, 100));
				result = dlg_FilesTable.ComboBox("index", comboSet_index, comboInfo);
			CzvImguiManager::EndGroupPanel();
		CzvImguiManager::EndGroupPanel();

		// Render Table
		auto& vImagePaths = pParamSetupLayer->GetImagePaths();
		auto& tParamChunk = pParamSetupLayer->GetParamChunk();
		filesTable["Name"].SetItem(vImagePaths);
		filesTable["Class"].SetItem({ box });
		dlg_FilesTable.SetNextPos(ImVec2(8, 140));
		dlg_FilesTable.Table(filesTable);
		// 경로 백슬래시 체크 후 없을 경우 붙여주는 로직
		if (!vImagePaths.empty())
		{
			int iSel = filesTable.GetSelectYaxisIndex();
			std::string strPath = filesTable["Name"][iSel].GetLabel();
			auto layer = (CDlgDisplayWindow*)CzvApp::GetInstance()->GetLayer("CDlgDisplayWindow");
			char cCheckBackSlash = *(tParamChunk.strLoadingPath.end() - 1);
			if (cCheckBackSlash != '\\')
				tParamChunk.strLoadingPath.push_back('\\');
			layer->Display(tParamChunk.strLoadingPath + strPath, 500, 500);
		}
		m_iTotal = vImagePaths.size();
		m_iIndex = vImagePaths.size();
	}

	// Render Class Table
	TzvDialogInfo dlg_ClassTable_info;
	dlg_ClassTable_info.SetDocsNoTabBar(true);
	auto& classTable = m_tClassTable.Table;
	CzvDialog dlg_classTable(classTable.GetLabel(), dlg_ClassTable_info);
	{
		// Render Control
		float fPanel_w = static_cast<float>(dlg_classTable.GetWidth()) - 30.0f;
		CzvImguiManager::BeginGroupPanel("Control", { fPanel_w, 20 });
			static std::string strInputText;
			TzvInputTextInfo info;
			dlg_classTable.SetNextPos(ImVec2(20, 40));
			dlg_classTable.InputText("Class Name", &strInputText, {100, 20});
		CzvImguiManager::EndGroupPanel();
		dlg_classTable.Table(classTable);
	}
	DProfile_EndRecord;
}

GENERATE_LAYER(CDlgClassification);