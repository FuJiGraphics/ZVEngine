#include "ZVCore.h"
#include "EntryPoint.h"
#include "ZVapp.h"

namespace ZVLab {

	CZVsystem* CreateApplication(TApplicationCommandLineArgs args)
	{
		TApplicationSpecification spec;
		spec.Name = "ZVEngine";
		spec.Width = 1280;
		spec.Height = 720;
		spec.WorkingDirectory = "../ZVEngine";
		spec.CommandLineArgs = args;

		return (new CZVapp(spec));
	}

} // namespace ZVLab