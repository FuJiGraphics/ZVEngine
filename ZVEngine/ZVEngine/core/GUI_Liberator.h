#pragma once

#pragma region LayerGenerator
#include "ZVCore.h"
#include "ZVapp.h"
#include <vector>

std::vector<ZVLab::CZVlayer*>	g_GenerateLayerList;
ZVLab::CZVsystem*				g_pApplication = nullptr;

// export defines
#define GENERATE_LAYER(layer)\
class ClassGenerate##layer\
{\
public:\
	ClassGenerate##layer(){\
		g_GenerateLayerList.push_back(new(##layer));\
	}\
};\
inline ClassGenerate##layer CLASSGENERATE##layer;

#define DESTROY_LAYER(layer) { ZVLab::CZVsystem::DetachLayer(layer); }
#pragma endregion

// GUI Headers
#include "GUI.h"

