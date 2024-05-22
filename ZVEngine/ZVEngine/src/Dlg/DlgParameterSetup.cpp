#include <string>
#include <vector>
#include <filesystem>
#include "DlgParameterSetup.h"

void CDlgParameterSetup::OnAttach()
{
	m_FileDialog.SetFileDialogLabel("ParameterSetupFileDialog");
	m_FileDialog.SetOpenLabel("Loading Path");
	m_FileDialog.SetSaveLabel("Saving Path");
	m_tParamChunk.strLoadingPath = " ";
	m_tParamChunk.strSavingPath = " ";
}

void CDlgParameterSetup::OnGUI()
{
	DProfile_StartRecord("Parameter Setup Logic...");

	CzvDialog dialog("ParameterSetup");
	TzvParametersChunk tmp_param;
	// Update
	static char buf[64];
	ImGui::InputText("Hello", buf, IM_ARRAYSIZE(buf));

	// Render
	TzvComboBoxInfo combo_info;
	DzvUI_Bullet dialog.Text("Loading Path");
	dialog.ComboBox(" ", { m_tParamChunk.strLoadingPath.c_str() }, combo_info);
	DzvUI_Bullet dialog.Text("Saving Path");
	dialog.ComboBox("  ", { m_tParamChunk.strSavingPath.c_str() }, combo_info);

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