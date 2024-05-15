#include "ZVCore.h"
#include "EntryPoint.h"
#include "ZVapp.h"

namespace ZVLab {

	ZVLab::Unique<ZVLab::CzvSystem>& CreateApplication(TzvApplicationCommandLineArgs args)
	{
		return (CzvApp::GetInstance());
	}

} // namespace ZVLab