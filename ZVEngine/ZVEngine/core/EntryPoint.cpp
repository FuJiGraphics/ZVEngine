#include "ZVCore.h"
#include "EntryPoint.h"
#include "ZVapp.h"
#include "GUI_Liberator.h"

namespace ZVLab {

	CZVsystem* CreateApplication(TApplicationCommandLineArgs args)
	{
		TApplicationSpecification spec;
		spec.Name = "ZVEngine";
		spec.Width = 1280;
		spec.Height = 720;
		spec.WorkingDirectory = "../ZVEngine";
		spec.CommandLineArgs = args;

		CZVsystem* app = new CZVapp(spec);
		g_pApplication = app;
		return (g_pApplication);
	}


} // namespace ZVLab