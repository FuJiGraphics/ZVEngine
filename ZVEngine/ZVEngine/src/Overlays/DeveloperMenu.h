#pragma once

#include "ZVCore.h"
#include "GUI_Liberator.h"

using namespace ZVLab;

class Menu : public ZVLab::CZVlayer
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
		CZVButton button("Test", 80.0f, 80.0f);
		if (button.IsClicked())
		{
			FZLOG_INFO("Test 메뉴바 클릭!");
		}
	}
};

GENERATE_LAYER(Menu);
