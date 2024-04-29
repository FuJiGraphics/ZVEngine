#include "ZVCore.h"
#include "EntryPoint.h"
#include "ZVapp.h"
#include "GUI_Liberator.h"

namespace ZVLab {

	CzvSystem* CreateApplication(TzvApplicationCommandLineArgs args)
	{
		TzvApplicationSpecification spec;
		spec.strName = "ZVEngine";
		spec.uiWidth = 1280;
		spec.uiHeight = 720;
		spec.strWorkingDirectory = "../ZVEngine";
		spec.strCommandLineArgs = args;

		CzvSystem* app = new CZVapp(spec);
		g_pApplication = app;
		return (g_pApplication);
	}


} // namespace ZVLab