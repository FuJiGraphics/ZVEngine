#ifndef __ZV_ENTRYPOINT_H__
#define __ZV_ENTRYPOINT_H__
#pragma once
#include "ZVCore.h"

	#ifdef ZV_PLATFORM_WINDOWS
extern ZVLab::Unique<ZVLab::CzvSystem>& ZVLab::CreateApplication(TzvApplicationCommandLineArgs args);

int main(int argc, char** argv)
{
	auto& pApp = ZVLab::CreateApplication({ argc, argv });

	pApp->Run();

	return (0);
}
	#endif /* ZV_PLATFORM_WINDOWS */

#endif /* __ZV_ENTRYPONT_H__ */
