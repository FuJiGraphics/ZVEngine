#ifndef __ZV_ZVAPPLICATION_H__
#define __ZV_ZVAPPLICATION_H__
#pragma once

#include "ZVCore.h"
#include "GUI_Liberator.h"

static void GenerateLayers(CzvSystem* app)
{
	for (auto& layer : g_GenerateLayerList)
	{
		app->AttachLayer(layer);
	}
}


class CZVapp : public ZVLab::CzvSystem
{
public:
	CZVapp(const TzvApplicationSpecification& spec)
		: CzvSystem(spec)
	{
		GenerateLayers(this);
	}

	virtual ~CZVapp() {}
};

#endif /*__ZV_ZVAPPLICATION_H__*/
