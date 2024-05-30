#include "Environment.h"
#include "DlgDisplayWindow.h"

CDlgDisplayWindow::CDlgDisplayWindow()
	: CzvLayer("CDlgDisplayWindow")
	, m_cImage()
	, m_tDialogInfo()
	, m_FileDialog("DisplayFileDialog")
{
}

void CDlgDisplayWindow::OnAttach()
{
	m_tDialogInfo.SetMenuBar(true);
	
	// Setup File Dialog
	m_FileDialog.SetMultiSelectMode(true);
	m_FileDialog.SetOpenLabel("Open a Images");
	m_FileDialog.SetSaveLabel("Save a Image");
};

void CDlgDisplayWindow::OnGUI()
{
	DProfile_StartRecord("Display FileDialog...");
	// Dialog »ý¼º
	CzvDialog dialog(ZV_Setting::g_strLabelDisplayWindow, m_tDialogInfo);
	
	// Display Image
	const float iw = ZV_Setting::g_iDisplaySizeW;
	const float ih = ZV_Setting::g_iDisplaySizeH;
	dialog.Image(m_cImage, ImVec2(iw, ih));

	// Get image file path with a CzvFileDialog
	static bool bOpen = false;
	static bool bSave = false;
	
	if (ImGui::BeginMenu("File"))
	{
		std::string path;
		CzvMenuItem item_open("Image Open..");
		if (item_open.Bind(KeyMaps::KEY_LEFT_CONTROL + KeyMaps::KEY_O))
		{
			bOpen = true;
			m_FileDialog.Open("Open file (*.png;*.jpg;*.jpeg;*.bmp;){.png,.jpg,.jpeg,.bmp},.*");
		}
		CzvMenuItem item_save("Image Save");
		if (item_save.Bind(KeyMaps::KEY_LEFT_CONTROL + KeyMaps::KEY_S))
		{
			bSave = true;
			m_FileDialog.Save("Save file (*.png;*.jpg;*.jpeg;*.bmp;){.png,.jpg,.jpeg,.bmp},.*");
		}
		ImGui::EndMenu();
	}

	// Open & Save Image Files
	std::string path_open, path_save;
	if (bOpen && m_FileDialog.GetOpenFilePaths(&path_open))
	{
		bOpen = false;
		m_cImage.Load(path_open);
	}
	if (bSave && m_FileDialog.GetOpenFilePaths(&path_save))
	{
		bSave = false;
		m_cImage.Save(path_save);
	}
	
	if (DZVLog_Failed(false, "asdasfa {0}", 1))
	{
		FZLOG_INFO("false");
	}
	DProfile_EndRecord;
}

void CDlgDisplayWindow::Display(const std::string& path, int w, int h)
{
	m_cImage.Load(path);
	ZV_Setting::g_iDisplaySizeW = w;
	ZV_Setting::g_iDisplaySizeH = h;
}
;

GENERATE_LAYER(CDlgDisplayWindow);