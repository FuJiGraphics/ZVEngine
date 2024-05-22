#include "ZVWindowMenu.h"

void ZVWindowMenu::OnAttach()
{
}

void ZVWindowMenu::OnMainMenuBar()
{
	CzvMenuBar menubar("MainMenuBar");

	if (ImGui::BeginMenu("File"))
	{
		if (ImGui::MenuItem("Open..", "Ctrl+O"))
		{
			ifd::FileDialog::Instance().Open("TextureOpenDialog", "Open a texture", "Image file (*.png;*.jpg;*.jpeg;*.bmp;){.png,.jpg,.jpeg,.bmp},.*", true);
		}
		if (ImGui::MenuItem("Save", "Ctrl+S"))
		{
			ifd::FileDialog::Instance().Save("TextureSaveDialog", "Save a texture", "Image file (*.png;*.jpg;*.jpeg;*.bmp;){.png,.jpg,.jpeg,.bmp},.*");
		}
		if (ImGui::MenuItem("Close", "Ctrl+W"))
		{

		}
		ImGui::EndMenu();
	}

	if (ImGui::BeginMenu("Edit"))
	{
		if (ImGui::MenuItem("Setting ZScreen"))
		{

		}
		ImGui::EndMenu();
	}

	static bool flags = true;
	if (ImGui::BeginMenu("Options"))
	{
		if (ImGui::MenuItem("Enable Dockspace"))
		{
			if (flags)
				flags = false;
			else
				flags = true;
			CzvImguiManager::SetOverviewDockspace(flags);
		}
		ImGui::EndMenu();
	}
}

GENERATE_LAYER(ZVWindowMenu);