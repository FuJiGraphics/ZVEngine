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
	CzvImage image;

public:
	virtual void OnAttach() 
	{

	};
	 
	virtual void OnGUI() 
	{
		static bool first = true;
		TzvDialogInfo info;
		info.SetNoDocking(false);
		CzvDialog dlgDialog("Sidebar", info);
	};

	virtual void OnMainMenuBar() 
	{
	};

};

GENERATE_LAYER(CDlgSidebarLeft);