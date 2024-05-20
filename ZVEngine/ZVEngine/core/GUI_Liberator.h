#pragma once

#pragma region LayerGenerator
#include "ZVCore.h"
#include "ZVapp.h"
#include <vector>

// export defines
#define GENERATE_LAYER(layer)\
class ClassGenerate##layer\
{\
public:\
	ClassGenerate##layer(){\
		CzvApp::GetInstance()->AttachLayer(new ##(layer));\
	}\
};\
inline ClassGenerate##layer CLASSGENERATE##layer;
#define GENERATE_OVERLAY(layer)\
class ClassGenerate##layer\
{\
public:\
	ClassGenerate##layer(){\
		CzvApp::GetInstance()->AttachOverlay(new ##(layer));\
	}\
};\
inline ClassGenerate##layer CLASSGENERATE##layer;

#define DESTROY_LAYER(layer) { ZVLab::CzvSystem::DetachLayer(layer); }
#pragma endregion

// GUI Headers
#include "GUI.h"

