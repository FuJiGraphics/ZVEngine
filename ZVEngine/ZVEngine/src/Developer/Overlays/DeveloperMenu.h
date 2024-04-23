#pragma once

#include "ZVCore.h"
#include "GUI_Liberator.h"

using namespace ZVLab;

class DeveloperMenu: public ZVLab::CZVlayer
{
public:
	virtual void OnMainMenuBar()
	{
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Open..", "Ctrl+O")) {}
			if (ImGui::MenuItem("Save", "Ctrl+S")) {}
			if (ImGui::MenuItem("Close", "Ctrl+W")) {}
			ImGui::EndMenu();
		}
	}
};

GENERATE_LAYER(DeveloperMenu);
