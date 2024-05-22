#include "Environment.h"
#include "DlgDisplayWindow.h"

CDlgDisplayWindow::CDlgDisplayWindow()
	: m_strLabel(ZV_Setting::g_strLabelDisplayWindow)
	, m_cImage()
	, m_tDialogInfo()
	, m_FileDialog("DisplayFileDialog")
{
}

void CDlgDisplayWindow::OnAttach()
{
	m_strLabel = ZV_Setting::g_strLabelDisplayWindow;
	m_tDialogInfo.SetMenuBar(true);
	
	// Setup File Dialog
	m_FileDialog.SetMultiSelectMode(true);
	m_FileDialog.SetOpenLabel("Open a Images");
	m_FileDialog.SetSaveLabel("Save a Image");
};

void CDlgDisplayWindow::OnGUI()
{
	DProfile_StartRecord("Display FileDialog...");
	CzvDialog dialog(m_strLabel, m_tDialogInfo);
	
	// Display Image
	const float iw = ZV_Setting::g_iDisplaySizeW;
	const float ih = ZV_Setting::g_iDisplaySizeH;
	dialog.Image(m_cImage, ImVec2(iw, ih));

	// Get image file path with a CzvFileDialog
	if (ImGui::BeginMenu("File"))
	{
		std::string path;
		CzvMenuItem item_open("Image Open..");
		if (item_open.Bind(KeyMaps::KEY_LEFT_CONTROL + KeyMaps::KEY_O))
		{
			m_FileDialog.Open("Image file (*.png;*.jpg;*.jpeg;*.bmp;){.png,.jpg,.jpeg,.bmp},.*");
		}
		CzvMenuItem item_save("Image Save");
		if (item_save.Bind(KeyMaps::KEY_LEFT_CONTROL + KeyMaps::KEY_S))
		{
			m_FileDialog.Save("Image file (*.png;*.jpg;*.jpeg;*.bmp;){.png,.jpg,.jpeg,.bmp},.*");
		}
		ImGui::EndMenu();
	}

	// Open & Save Image Files
	std::string path_open, path_save;
	if (m_FileDialog.GetOpenFilePaths(&path_open))
	{
		m_cImage.Load(path_open);
	}
	if (m_FileDialog.GetOpenFilePaths(&path_save))
	{
		m_cImage.Load(path_save);
	}
	DProfile_EndRecord;
};

GENERATE_LAYER(CDlgDisplayWindow);