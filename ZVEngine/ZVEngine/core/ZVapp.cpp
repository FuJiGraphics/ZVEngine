#include "ZVapp.h"

ZVLab::Unique<ZVLab::CzvSystem> CzvApp::s_upApp = nullptr;

ZVLab::Unique<ZVLab::CzvSystem>& CzvApp::GetInstance()
{
	if (s_upApp == nullptr)
	{
		s_upApp = ZVLab::CreateUnique<CzvApp>();
	}
	return (s_upApp);
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
