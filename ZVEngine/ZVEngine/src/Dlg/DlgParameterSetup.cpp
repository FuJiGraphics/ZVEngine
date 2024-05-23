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
	TzvDialogInfo dlg_table_info;
	dlg_table_info.SetDocsNoTabBar(true);
	CzvDialog dlg_table1("Table1", dlg_table_info);
	CzvTable table1("Table");
	table1.SetHeaders({ "ID", "Name", "Class" });
	table1["ID"].AddItem("Hello %d", 20);
	dlg_table1.Table(table1);

	TzvDialogInfo dlg_table_info2;
	dlg_table_info2.SetDocsNoTabBar(true);
	CzvDialog dlg_table2("Table2", dlg_table_info2 );
	CzvTable table2( "table_sorting" );
	TzvTableHeaderInfo info_ID, info_Name, info_Class;
	info_ID.SetDefaultSort( true );
	info_ID.SetWidthFixed( true );
	table2.AddHeader( "ID", info_ID );
	info_Name.SetWidthFixed( true );
	table2.AddHeader( "Name", info_Name );
	info_Class.SetPreferSortDescending( true );
	info_Class.SetWidthStretch( true );
	table2.AddHeader( "Class", info_Class );
	for ( int row = 0; row < 4; ++row )
	{
		for ( int col = 0; col < table2.GetColSize(); ++col )
		{
			table2[col].AddItem( "Hello %d %d", col, row );
		}
	}
	dlg_table2.Table( table2 );
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