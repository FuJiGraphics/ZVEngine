#include <string>
#include <vector>
#include <filesystem>
#include "DlgParameterSetup.h"

void CDlgParameterSetup::OnAttach()
{
	// Dialog Info

	m_FileDialog.SetFileDialogLabel("ParameterSetupFileDialog");
	m_FileDialog.SetOpenLabel("Loading Path");
	m_FileDialog.SetSaveLabel("Saving Path");
	m_tParamChunk.strLoadingPath = "asdasf";
	m_tParamChunk.strSavingPath = " ";
}

void CDlgParameterSetup::OnGUI()
{
	DProfile_StartRecord("Parameter Setup Logic...");
	CzvDialog dialog("ParameterSetup");

	// Render
	TzvComboBoxInfo combo_info;
	DzvUI_Bullet dialog.Text("Loading Path");
	dialog.ComboBox(" ", { m_tParamChunk.strLoadingPath.c_str() }, combo_info);
	DzvUI_Bullet dialog.Text("Saving Path");
	dialog.ComboBox(" ", { m_tParamChunk.strSavingPath.c_str() }, combo_info);


	static TzvParametersChunk tmp_param;
	// Update
	dialog.InputText("input", &tmp_param.strLoadingPath);


	
	/*-----------------------------------------------------------------*/

	CzvImguiManager::SetDockspace(dialog, { 500, 500 });

	// Options
	static ImGuiTableFlags flags =
		ImGuiTableFlags_Resizable | ImGuiTableFlags_Reorderable | ImGuiTableFlags_Hideable | ImGuiTableFlags_Sortable | ImGuiTableFlags_SortMulti
		| ImGuiTableFlags_RowBg | ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersV | ImGuiTableFlags_NoBordersInBody
		| ImGuiTableFlags_ScrollY;

	TzvDialogInfo info_table1;
	info_table1.SetDocsNoTabBar(true);
	CzvDialog dlg_table1("Table1", info_table1);
	CzvTable table1("Table");
	table1.SetHeaders({ "ID", "Name", "Class" });
	table1["ID"].AddItem("Hello %d", 20);
	table1.Bind();


	TzvDialogInfo info_table2;
	info_table2.SetDocsNoTabBar(true);
	CzvDialog dlg_table2("Table2", info_table2);
	if (ImGui::BeginTable("table_sorting", 4, flags, ImVec2(0.0f, 200), 0.0f))
	{
		ImGui::TableSetupColumn("ID", ImGuiTableColumnFlags_DefaultSort | ImGuiTableColumnFlags_WidthFixed, 0.0f, 20);
		ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthFixed, 0.0f, 20);
		ImGui::TableSetupColumn("Class", ImGuiTableColumnFlags_PreferSortDescending | ImGuiTableColumnFlags_WidthStretch, 0.0f, 20);
		ImGui::TableSetupScrollFreeze(0, 1); // Make row always visible
		ImGui::TableHeadersRow();

		for (int row = 0; row < 4; row++)
		{
			ImGui::TableNextRow();
			// ImGui::TableNextColumn();
			// ImGui::Text("%d", row);
			// ImGui::TableNextColumn();
			// ImGui::Text("Some contents");
			// ImGui::TableNextColumn();
			// ImGui::Text("123.456");

			for (int column = 0; column < 3; column++)
			{
				ImGui::TableSetColumnIndex(column);
				ImGui::Text("Hello %d,%d", column, row);
			}
		}

		ImGui::EndTable();
	}
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
			//printf("%s\n", dir_iter->path().filename().generic_string().c_str());
			imageList.push_back(dir_iter->path().filename().generic_string());
		}
	}
	return (imageList);
}

GENERATE_LAYER(CDlgParameterSetup)