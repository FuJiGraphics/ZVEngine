#pragma once

#include "ZVCore.h"
#include "GUI_Liberator.h"

using namespace ZVLab;

class DeveloperMenu: public ZVLab::CzvLayer
{
public:
	virtual void OnMainMenuBar()
	{
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Open..", "Ctrl+O")) 
			{
				ifd::FileDialog::Instance().Open("TextureOpenDialog", "Open a texture", "Image file (*.png;*.jpg;*.jpeg;*.bmp;*.tga){.png,.jpg,.jpeg,.bmp,.tga},.*");
			}
			if (ImGui::MenuItem("Save", "Ctrl+S")) 
			{
			
			}
			if (ImGui::MenuItem("Close", "Ctrl+W")) 
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
				CZVimguiManager::SetOverviewDockspace(flags);
			}
			ImGui::EndMenu();
		}
	}
};

GENERATE_LAYER(DeveloperMenu);
