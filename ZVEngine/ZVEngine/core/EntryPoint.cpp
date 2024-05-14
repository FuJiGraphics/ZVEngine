#include "ZVCore.h"
#include "EntryPoint.h"
#include "ZVapp.h"

namespace ZVLab {

	CzvSystem* CreateApplication(TzvApplicationCommandLineArgs args)
	{
		return (CzvApp::GetInstance());
	}

} // namespace ZVLab