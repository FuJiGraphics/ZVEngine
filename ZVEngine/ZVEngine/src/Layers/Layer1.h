#pragma once
#include "ZVCore.h"
#include "GUI_Liberator.h"
#include "imgui/extensions/ImCoolbar.h"

using namespace ZVLab;

class Layer1 : public ZVLab::CZVlayer
{
private:
	CZVImageButton	m_b1;
	CZVTexture		m_Tex;

public:
	virtual void OnAttach() override
	{
		m_b1.SetTexture("D:\\Dev\\ZVLab\\ZVEngine\\image3.jpg");
		m_Tex.Load("D:\\Dev\\ZVLab\\ZVEngine\\image3.jpg");
	}

	virtual void OnGUI() override
	{

		ImGui::DockSpaceOverViewport();

		auto ShowCoolBarButton = [](const std::string& label, CZVTexture& tex) -> bool
		{
			float w = ImGui::GetCoolBarItemWidth();

			// Display transparent image and check if clicked
			ImGui::Image((void*)(intptr_t)tex.GetID(), { w, w });
			bool clicked = ImGui::IsItemHovered() && ImGui::IsMouseClicked(0);

			return clicked;
		};


		std::vector<std::string> buttonLabels{ "A", "B", "C", "D", "E", "F" };

		ImGui::ImCoolBarConfig coolBarConfig;
		coolBarConfig.anchor = ImVec2(0.9f, 0.07f); // position in the window (ratio of window size)
		if (ImGui::BeginCoolBar("##CoolBarMain", ImCoolBarFlags_Horizontal, coolBarConfig))
		{
			for (const std::string& label : buttonLabels)
			{
				if (ImGui::CoolBarItem())
				{
					if (ShowCoolBarButton(label, m_Tex))
						printf("Clicked %s\n", label.c_str());
				}
			}
			ImGui::EndCoolBar();
		}

		ImGui::NewLine(); ImGui::NewLine();



		CZVDialog dialog1("Dialog 1");
		m_b1.IsClicked();
	}
};

GENERATE_LAYER(Layer1)