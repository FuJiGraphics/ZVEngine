#include "DlgClassification.h"
#include "DlgParameterSetup.h"

namespace {
	static bool s_RemoveAll(const std::string& path)
	{
		// std::filesystem::remove_all(path);
		return (true);
	}

	static bool s_Mkdir(const std::string& path)
	{
		if (path.empty())
			return (false);

		std::filesystem::path p(path);

		if (std::filesystem::is_directory(p))
			return (false);

		std::filesystem::create_directories(p);
		return (true);
	}
}

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
			{ "Class", m_tFilesTable.tSelectableInfo }
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

	// Get Path Params
	auto& vImagePaths = pParamSetupLayer->GetImagePaths();
	auto& tParamChunk = pParamSetupLayer->GetParamChunk();
	
	// Temp 
	static std::vector<std::string> s_vClassesTable;
	static std::vector<int>			s_vClassesCount;
	static std::string				s_prevNewPath;

	// 만약 새로운 폴더가 로딩될 경우 설정 초기화
	if (tParamChunk.bIsChanged)
	{
		tParamChunk.bIsChanged = false;
		m_tFilesTable.Table["Class"].Clear();
		m_tClassTable.Table.ResetSelectableIndex();
		s_vClassesTable.clear();
		s_vClassesCount.clear();
	}

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
			CzvImguiManager::BeginGroupPanel("Search", { fPanel_w, 40 });
				dlg_FilesTable.SetNextPos(ImVec2(30, 100));
				result = dlg_FilesTable.ComboBox("Separate", comboSet_separate, comboInfo);
				dlg_FilesTable.SetNextPos(ImVec2(150, 100));
				result = dlg_FilesTable.ComboBox("index", comboSet_index, comboInfo);
			CzvImguiManager::EndGroupPanel();
		CzvImguiManager::EndGroupPanel();

		// Render Table
		CzvHotKey key(KeyMaps::KEY_ENTER + KeyMaps::KEY_SPACE);
		if (key.IsPressed())
		{
			int file_yIndex = filesTable.GetSelectYaxisIndex();
			int class_yIndex = m_tClassTable.Table.GetSelectYaxisIndex();
			if (file_yIndex >= s_vClassesTable.size())
			{
				while (file_yIndex >= s_vClassesTable.size())
				{
					s_vClassesTable.push_back("");
				}
			}
			std::string newClassLabel = m_tClassTable.Table["Class"][class_yIndex].GetLabel();
			if (s_vClassesTable[file_yIndex] != newClassLabel)
			{
				s_vClassesTable[file_yIndex] = newClassLabel;
				filesTable["Class"].SetItem(s_vClassesTable);
			}
			filesTable.SetNextSelectableIndex();

			// Pull Param Setup
			s_RemoveAll(tParamChunk.strSavingPath);
			s_Mkdir(tParamChunk.strSavingPath);
			for (auto& item : m_tClassTable.Table["Class"])
			{
				std::string strItemLabel = item.GetLabel();
				if (tParamChunk.strSavingPath.size() > 1)
				{
					s_prevNewPath = tParamChunk.strSavingPath + "\\" + strItemLabel;
					s_Mkdir(s_prevNewPath);
				}
			}
			int i = 0;
			static std::vector<std::string> s_vPrevImagePaths;
			std::map<std::string, int> s_mIndexPool;

			for (auto& item : filesTable["Class"])
			{
				std::string classLabel = item.GetLabel();
				int index = 0;
				if (s_mIndexPool.find(classLabel) != s_mIndexPool.end())
				{
					index = s_mIndexPool[classLabel] + 1;
					s_mIndexPool[classLabel] = index;
				}
				else
				{
					s_mIndexPool.insert({ classLabel, 0 });
				}
				
				if (classLabel.size())
				{
					if (tParamChunk.strSavingPath.size())
					{
						std::string newPath = tParamChunk.strSavingPath + "\\" + classLabel;
						CzvImage image;
						image.Load(tParamChunk.strLoadingPath + *(vImagePaths.begin() + i));
						std::string newImportLabel = newPath + "\\" + classLabel + std::string("_") + std::to_string(index) + ".bmp";
						image.Save(newImportLabel);
					}
				}
				++i;
			}
		}

		filesTable["Name"].SetItem(vImagePaths);
		dlg_FilesTable.SetNextPos(ImVec2(8, 140));
		dlg_FilesTable.Table(filesTable);

		// 경로 백슬래시 체크 후 없을 경우 붙여주는 로직
		if (!vImagePaths.empty())
		{
			int iSel = filesTable.GetSelectYaxisIndex();
			std::string strPath = filesTable["Name"][iSel].GetLabel();
			if (strPath != " ")
			{
				auto layer = (CDlgDisplayWindow*)CzvApp::GetInstance()->GetLayer("CDlgDisplayWindow");
				char cCheckBackSlash = *(tParamChunk.strLoadingPath.end() - 1);
				if (cCheckBackSlash != '\\')
					tParamChunk.strLoadingPath.push_back('\\');
				layer->Display(tParamChunk.strLoadingPath + strPath, 500, 500);
			}
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
		CzvImguiManager::BeginGroupPanel("Control", { fPanel_w, 40 });
			static std::string strInputText;

			TzvInputTextInfo info;
			dlg_classTable.SetNextPos(ImVec2(20, 25));
			dlg_classTable.InputText("Class Name", &strInputText, {100, 20});
			dlg_classTable.SetNextPos(ImVec2(205, 25));

			if (dlg_classTable.Button(ICON_FA_PLUS))
			{
				if (!strInputText.empty())
				{
					if (classTable["Class"].Find(strInputText) == classTable["Class"].end())
					{
						classTable["Class"].AddItem(strInputText);
						strInputText.clear();
						classTable["Hot Key"].AddItem(std::to_string(m_tClassTable.Table.GetRowSize()));
					}
				}
			}

			dlg_classTable.SetNextPos(ImVec2(235, 25));
			if (dlg_classTable.Button(ICON_FA_MINUS))
			{
				strInputText.clear();
			}

		CzvImguiManager::EndGroupPanel();
		dlg_classTable.Table(classTable);
	}

	DProfile_EndRecord;
}

TzvTableData& CDlgClassification::GetFileTable()
{
	return (m_tFilesTable);
}

TzvTableData& CDlgClassification::GetClassTable()
{
	return (m_tClassTable);
}

GENERATE_LAYER(CDlgClassification);