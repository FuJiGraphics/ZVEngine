#include <string>
#include <vector>
#include <filesystem>
#include "DlgParameterSetup.h"
#include "DlgDisplayWindow.h"

CDlgParameterSetup::CDlgParameterSetup()
	: CzvLayer("CDlgParameterSetup")
{
}

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
		m_tParamChunk.strLoadingPath = tmp_param.strLoadingPath;
		m_tParamChunk.strSavingPath = tmp_param.strSavingPath;
	}
	DProfile_EndRecord
}

std::vector<std::string>& CDlgParameterSetup::GetImagePaths()
{
	return (m_vLoadPaths);
}

TzvParametersChunk& CDlgParameterSetup::GetParamChunk()
{
	return (m_tParamChunk);
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