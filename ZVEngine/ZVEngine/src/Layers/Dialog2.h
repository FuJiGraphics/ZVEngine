#pragma once

#include "ZVCore.h"
#include "GUI_Liberator.h"

using namespace ZVLab;

class Dialog2 : public ZVLab::CZVlayer
{
public:
	virtual void OnGuiRender()
	{
		CZVDialog dialog2("Dialog 2");
		dialog2.Button("button1", 80.0f, 80.0f);
		dialog2.Button("button2", 80.0f, 80.0f);
		dialog2.Button("button3", 80.0f, 80.0f);
		dialog2.Button("button4", 80.0f, 80.0f);
		dialog2.Button("button5", 80.0f, 80.0f, 100.0f, 80.0f);
		CZVDialog dialog3("Dialog 3");
		if (dialog3.Button("Button Type 1", 80.0f, 80.0f))
		{
			FZLOG_INFO("Button type 1");
		}
		dialog2.Button("button", 80.0f, 80.0f);
		dialog2.Button("button", 80.0f, 80.0f);
		dialog2.Button("button", 80.0f, 80.0f);
	}
};

GENERATE_LAYER(Dialog2);
