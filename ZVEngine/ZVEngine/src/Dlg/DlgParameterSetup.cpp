#include <string>
#include <vector>
#include <filesystem>
#include "DlgParameterSetup.h"

void CDlgParameterSetup::OnAttach()
{
	// Dialog Info
	m_LoadFileDialog.SetFileDialogLabel("ParameterSetup_LFD");
	m_LoadFileDialog.SetOpenLabel("Loading Path");
	m_SaveFileDialog.SetFileDialogLabel("ParameterSetup_SFD");
	m_SaveFileDialog.SetOpenLabel("Saving Path");
	m_tParamChunk.strLoadingPath = "asdasf";
	m_tParamChunk.strSavingPath = " ";
}

void CDlgParameterSetup::OnGUI()
{
	DProfile_StartRecord("Parameter Setup Logic...");
	CzvDialog dialog("ParameterSetup");

	static TzvParametersChunk tmp_param;
	DzvUI_Bullet dialog.Text("Loading Path");
	TzvInputTextInfo input_info;
	input_info.SetReadOnly(true);
	dialog.InputText("##input1", &tmp_param.strLoadingPath, input_info);
	DzvUI_SameLine if (dialog.Button("..."))
	{
		m_LoadFileDialog.OpenFolder("Open Folder");
	}
	DzvUI_Bullet dialog.Text("Saving Path");
	dialog.InputText("##input1", &tmp_param.strSavingPath, input_info);
	DzvUI_SameLine if (dialog.Button("..."))
	{
		m_SaveFileDialog.OpenFolder("Save Folder");
	}

	if (m_LoadFileDialog.GetOpenFilePaths(&tmp_param.strLoadingPath))
	{
		this->LoadImages(tmp_param.strLoadingPath);
	}
	if (m_SaveFileDialog.GetOpenFilePaths(&tmp_param.strSavingPath))
	{
		this->LoadImages(tmp_param.strSavingPath);
	}
	// Update
	if (dialog.Button("Save"))
	{
		m_vLoadPaths = this->LoadImages(tmp_param.strLoadingPath);
	}

	/*-----------------------------------------------------------------*/
	CzvImguiManager::SetDockspace(dialog, { 800, 500 });
	// Set Dialog Options
	TzvDialogInfo dlg_table_info, dlg_table_info2;
	dlg_table_info.SetDocsNoTabBar(true);
	dlg_table_info2.SetDocsNoTabBar(true);

	// Generate Dialog, table
	CzvDialog dlg_table1("Table1", dlg_table_info);
	CzvTable table1("Table");
	table1.SetHeaders({ "ID", "Name", "Class" });
	table1["ID"].AddItem("Hello %d", 20);
	dlg_table1.Table(table1);

	CzvDialog dlg_table2("Table2", dlg_table_info2 );

	TzvTableInfo info_table2;
	info_table2.SetResizable(true);
	info_table2.SetSizingFixedSame(true);
	info_table2.SetHighlightHoveredColumn(true);
	info_table2.SetBorders(true);
	CzvTable table2( "table_sorting", info_table2);
	TzvSelectableInfo sel_info;
	sel_info.SetSpanAllColumns(true);
	sel_info.SetAllowOverlap(true);
	table2.SetHeaders({"ID", "Name", "Class"});
	table2["ID"].SetSelectable(true, sel_info);
	table2["ID"].AddItem(m_vLoadPaths);
	table2["Name"].AddItem(m_vLoadPaths);
	table2.Bind();

	//// Set Header Info
	//TzvTableHeaderInfo info_ID, info_Name, info_Class;
	//info_ID.SetDefaultSort( true );
	//info_ID.SetWidthFixed( true );
	//table2.AddHeader( "ID", info_ID );
	//info_Name.SetDefaultHide(true);
	//table2.AddHeader( "Name", info_Name );
	//info_Class.SetPreferSortDescending( true );
	//info_Class.SetWidthStretch( true );
	//table2.AddHeader( "Class", info_Class );
	//table2["Name"].AddItem(m_vLoadPaths);
	//dlg_table2.Table( table2 );

	//int i = 0;
	//static int selectItem = 0;
	//if (ImGui::BeginTable("fasf", 3))
	//{
	//	CzvTableHeader h1("ID");
	//	CzvTableHeader h2("Name");
	//	CzvTableHeader h3("Class");
	//	h1.Bind();
	//	h2.Bind();
	//	h3.Bind();
	//	ImGui::TableSetupScrollFreeze(0, 1);
	//	ImGui::TableHeadersRow();
	//	for (auto iter = m_vLoadPaths.begin(); iter != m_vLoadPaths.end(); ++iter)
	//	{
	//		ImGui::TableNextRow();

	//		for (int j = 0; j < 3; ++j)
	//		{
	//			ImGui::TableSetColumnIndex(j);
	//			if (j == 0)
	//			{
	//				std::string itemid = "ID_ " + std::to_string(i);
	//				ImGuiSelectableFlags selectable_flags = ImGuiSelectableFlags_SpanAllColumns | ImGuiSelectableFlags_AllowOverlap;
	//				if (ImGui::Selectable(itemid.c_str(), i == selectItem, selectable_flags))
	//				{
	//					selectItem = i;
	//				}
	//			}
	//			else
	//				ImGui::Text(iter->c_str());
	//		}
	//		i++;
	//	}
	//	ImGui::EndTable(); 
	// }

	DProfile_EndRecord
}

std::vector<std::string> CDlgParameterSetup::LoadImages(const std::string& path)
{
	std::filesystem::path someDir(path);
	std::filesystem::directory_iterator end_iter;
	std::vector<std::string> vc;
	std::vector<std::string> imageList;

	for (std::filesystem::directory_iterator dir_iter(someDir); dir_iter != end_iter; ++dir_iter)
	{
		if (std::filesystem::is_regular_file(dir_iter->status()))
		{
			//printf("%s\n", dir_iter->path().filename() );
			if ((dir_iter->path().filename().generic_string().substr(dir_iter->path().filename().generic_string().length() - 3, 3) != "jpg")
				&& (dir_iter->path().filename().generic_string().substr(dir_iter->path().filename().generic_string().length() - 3, 3) != "png")
				&& (dir_iter->path().filename().generic_string().substr(dir_iter->path().filename().generic_string().length() - 3, 3) != "bmp"))
				continue;
			//printf("%s\n", dir_ite6r->path().filename().generic_string().c_str());
			imageList.push_back(dir_iter->path().filename().generic_string());
		}
	}
	return (imageList);
}

GENERATE_LAYER(CDlgParameterSetup)