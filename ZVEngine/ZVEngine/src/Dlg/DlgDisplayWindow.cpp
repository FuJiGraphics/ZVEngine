#include "DlgDisplayWindow.h"

void CDlgDisplayWindow::OnAttach()
{
	m_strLabel = ZV_Setting::g_strLabelDisplayWindow;
	m_tDialogInfo.SetMenuBar(true);
};

void CDlgDisplayWindow::OnGUI()
{
	DProfile_StartRecord(m_strLabel);
	CzvDialog dialog(m_strLabel, m_tDialogInfo);
	
	dialog.Image
	(
		m_cImage, 
		{ ZV_Setting::g_iDisplaySizeW, ZV_Setting::g_iDisplaySizeH }
	);

	if (ImGui::BeginMenu("File"))
	{
		CzvMenuItem item_open("Image Open..");
		if (item_open.Bind(KeyMaps::KEY_LEFT_CONTROL + KeyMaps::KEY_O))
		{
			FZLOG_INFO("Message: {0}", item_open.GetLabel().c_str());
			ifd::FileDialog::Instance().Open("TextureOpenDialog", "Open a texture", "Image file (*.png;*.jpg;*.jpeg;*.bmp;){.png,.jpg,.jpeg,.bmp},.*", true);
		}
		CzvMenuItem item_save("Image Save");
		if (item_save.Bind(KeyMaps::KEY_LEFT_CONTROL + KeyMaps::KEY_S))
		{
			FZLOG_INFO("Message: {0}", item_save.GetLabel().c_str());
			ifd::FileDialog::Instance().Save("TextureSaveDialog", "Save a texture", "Image file (*.png;*.jpg;*.jpeg;*.bmp;){.png,.jpg,.jpeg,.bmp},.*");
		}
		ImGui::EndMenu();
	}

	if (ifd::FileDialog::Instance().IsDone("TextureOpenDialog"))
	{
		if (ifd::FileDialog::Instance().HasResult()) {
			std::string res = ifd::FileDialog::Instance().GetResult().u8string();
			m_cImage.Load(res);
		}
		ifd::FileDialog::Instance().Close();
	}
	if (ifd::FileDialog::Instance().IsDone("TextureSaveDialog"))
	{
		if (ifd::FileDialog::Instance().HasResult()) {
			std::string res = ifd::FileDialog::Instance().GetResult().u8string();
			m_cImage.Save(res, EzvImageFormat::ePNG);
		}
		ifd::FileDialog::Instance().Close();
	}
	DProfile_EndRecord;
};

void CDlgDisplayWindow::OnMainMenuBar()
{
}
