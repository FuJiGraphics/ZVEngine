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

	dialog.Image
	(
		m_cImage, 
		{ ZV_Setting::g_iDisplaySizeW, ZV_Setting::g_iDisplaySizeH }
	);

	if (ImGui::BeginMenu("File"))
	{
		CzvMenuItem item("item", "A+SPACE");
		if (item.Bind(KeyMaps::KEY_SPACE + KeyMaps::KEY_A, dialog))
		{
			FZLOG_INFO("item click!");
		}
		ImGui::EndMenu();
	}

	DProfile_EndRecord;
};

void CDlgDisplayWindow::OnMainMenuBar()
{
}
