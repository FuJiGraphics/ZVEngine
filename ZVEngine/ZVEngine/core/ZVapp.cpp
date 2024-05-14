#include "ZVapp.h"

ZVLab::CzvSystem* CzvApp::s_pApp = nullptr;

ZVLab::CzvSystem* CzvApp::GetInstance()
{
	if (s_pApp == nullptr)
	{
		s_pApp = new CzvApp();
	}
	return (s_pApp);
}

CzvApp::CzvApp()
	: CzvSystem()
{
	TzvApplicationSpecification spec;
	spec.strName = "ZVEngine";
	spec.uiWidth = 1280;
	spec.uiHeight = 720;
	spec.strWorkingDirectory = "../ZVEngine";
	spec.strCommandLineArgs;
	this->Initialize(spec);
}
