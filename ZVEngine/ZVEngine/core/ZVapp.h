#ifndef __ZV_ZVAPPLICATION_H__
#define __ZV_ZVAPPLICATION_H__
#pragma once

#include "ZVCore.h"
#include "GUI_Liberator.h"

static void GenerateLayers(CZVsystem* app)
{
	for (auto& layer : g_GenerateLayerList)
	{
		app->AttachLayer(layer);
	}
}


class CZVapp : public ZVLab::CZVsystem
{
public:
	CZVapp(const TApplicationSpecification& spec)
		: CZVsystem(spec)
	{
		GenerateLayers(this);
	}

	virtual ~CZVapp() {}
};

#endif /*__ZV_ZVAPPLICATION_H__*/
