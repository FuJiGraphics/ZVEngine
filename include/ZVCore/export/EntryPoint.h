#ifndef __ZV_ENTRYPOINT_H__
#define __ZV_ENTRYPOINT_H__
#pragma once
#include "ZVCore.h"

	#ifdef ZV_PLATFORM_WINDOWS
extern ZVLab::CzvSystem* ZVLab::CreateApplication(const TzvApplicationSpecification&  spec);

	#endif /* ZV_PLATFORM_WINDOWS */

#endif /* __ZV_ENTRYPONT_H__ */
