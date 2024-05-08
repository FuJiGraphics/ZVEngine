#pragma once

#ifndef __ZV_PROFILER_H__
#define __ZV_PROFILER_H__
#pragma once

#include "../../../core/Core.h"
#include "../../../core/ZVTimer.h"
#include "ZVTabItem.h"
#include <typeinfo>

namespace ZVLab {

	class ZV_API TzvTimeStep;

//----------------------------------------------------
// Profiler
//----------------------------------------------------
	class ZV_API CzvProfiler
	{
	public:
		static Shared<CzvProfiler>		Create(const std::string& label);
		static Shared<CzvProfiler>&		GetProfiler(const std::string& label);
		static void						RenderProfilers();
		static void						ActivateProfiler(bool enabled);
		static bool						EnabledProfiler();

	public:
		virtual void Submit(const TzvTimeStep& data) = 0;
		virtual void PlotRender() = 0;
		virtual void TableRender() = 0;
	};

//----------------------------------------------------
// Time Step
//----------------------------------------------------
	struct ZV_API TzvTimeStep
	{
		std::string		Label;
		float			ElapsedTime;
	};

//----------------------------------------------------
// Interface Defines
//----------------------------------------------------
#define DProfile_StartRecord(label){\
		CzvTimer timer;\
		TzvTimeStep rec{label, 0.0f};

#define DProfile_EndRecord \
if(CzvProfiler::EnabledProfiler()){\
	rec.ElapsedTime = timer.Elapsed(EzvTimerUnit::eTimeUnit_Milliseconds); \
	CzvProfiler::GetProfiler(std::string(typeid(*this).name()) + std::string("::") + std::string(__func__))->Submit(rec);\
}}

#define DProfile_Activate(boolean)	CzvProfiler::ActivateProfiler(boolean);
#define DProfile_Execute \
if(CzvProfiler::EnabledProfiler()){\
	CzvProfiler::RenderProfilers();}

} // namespace ZVLab
#endif /*__ZV_PROFILER_H__*/
