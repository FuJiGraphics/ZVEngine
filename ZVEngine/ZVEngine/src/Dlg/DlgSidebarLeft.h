#pragma once

#include "ZVCore.h"
#include "GUI_Liberator.h"
#include "imgui/extensions/im_mvision/immvision.h"

using namespace ZVLab;

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include "opencv2/world.hpp"
#include <opencv2/opencv.hpp>

class CDlgSidebarLeft final : public ZVLab::CzvLayer
{
private:
	TzvDialogInfo info1;
	CzvButton button1;
	CzvButton button2;
public:

	CDlgSidebarLeft()
		: button1("button")
		, button2("button2")
	{
		info1.SetMenuBar(true);
	}
	virtual void OnAttach() 
	{
	};
	 
	virtual void OnGUI()
	{
		DProfile_StartRecord("Sidebar1");
		CzvDialog dialog1("Sidebar1", info1);
		CzvMenuItem item("item", "Custom HotKey");

		CzvToggleButton toggle("toggle");
		toggle.Bind();

		if (ImGui::BeginMenu("asd"))
		{
			if (item.Bind(KeyMaps::KEY_SPACE + KeyMaps::KEY_B, true))
			{
				FZLOG_INFO("item");
			}
			ImGui::EndMenu();
		}
		
		CzvImage image;
		DProfile_EndRecord;
	};

	virtual void OnMainMenuBar() 
	{
	};

};

GENERATE_OVERLAY(CDlgSidebarLeft);