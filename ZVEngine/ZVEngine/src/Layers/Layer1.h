#pragma once
#include "ZVCore.h"
#include "GUI_Liberator.h"

using namespace ZVLab;

class Layer1 : public ZVLab::CZVlayer
{
public:
	virtual void OnGuiRender() override
	{
		CZVDialog dialog1("Dialog 1");
		dialog1.Button("button1", 80.0f, 80.0f);
		dialog1.Button("button2", 80.0f, 80.0f);
		dialog1.Button("button3", 80.0f, 80.0f);
		dialog1.Button("button4", 80.0f, 80.0f);
		dialog1.Button("button5", 80.0f, 80.0f, 100.0f, 80.0f);
		CZVDialog dialog2("Dialog 2");
		if (dialog2.Button("Button 6", 80.0f, 80.0f))
		{
			FZLOG_INFO("Button type 1");
		}
		dialog1.Button("button", 80.0f, 80.0f);
		dialog1.Button("button", 80.0f, 80.0f);
		dialog1.Button("button", 80.0f, 80.0f);
		
	}



};

GENERATE_LAYER(Layer1)