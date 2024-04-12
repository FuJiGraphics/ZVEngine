#pragma once

#include "FZLib/Helpers/LogHelper.h"

#ifdef ZV_PLATFORM_WINDOWS
	#ifdef _DEBUG
		#include <windows.h>
		#define	ZV_DEBUG_BREAK DebugBreak();
	#else
		#define	ZV_DEBUG_BREAK
	#endif
#else
	#error "Did not found platform!";
#endif

#define ZVLOG_FAILED(boolean, ...)\
		FZLOG_FAILED(boolean, __VA_ARGS__);\
		if(!boolean) ZV_DEBUG_BREAK;
	
