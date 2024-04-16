#include "ZVCore.h"
#include "EntryPoint.h"
#include "ZVapp.h"
#include "GUI_Liberator.h"

namespace ZVLab {

	static void GenerateLayers(CZVsystem* app)
	{
		for (auto& layer : g_GenerateLayerList)
		{
			app->AttachLayer(layer);
		}
	}
	
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
		GenerateLayers(app);
		return (app);
	}


} // namespace ZVLab