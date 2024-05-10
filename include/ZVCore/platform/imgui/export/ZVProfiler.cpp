#include "ZVProfiler.h"
#include "../ZVProfiler_internal.h"
#include "ZVDialog.h"
#include "ZVTabBar.h"

namespace ZVLab {
	
	//// static variables
	static bool	s_ActivatedProfiler = true;
	static std::map<std::string, Shared<CzvProfiler>> s_ProfilerLists;

	Shared<CzvProfiler> CzvProfiler::Create(const std::string& label)
	{
		return (CreateShared<CzvProfiler_internal>(label));
	}

	Shared<CzvProfiler>& CzvProfiler::GetProfiler(const std::string& label)
	{
		Shared<CzvProfiler> profiler = CreateShared<CzvProfiler_internal>(label);
		s_ProfilerLists.insert({ label, profiler });
		return (s_ProfilerLists[label]);
	}

	void CzvProfiler::RenderProfilers()
	{
		CzvDialog dialog("Profiler");

		CzvTabBar tabbar("Profiler");
		for (const auto& profiler : s_ProfilerLists)
		{
			if (tabbar.TabItem(profiler.first))
			{
				profiler.second->TableRender();
			}
		}
	}

	void CzvProfiler::ActivateProfiler(bool enabled)
	{
		s_ActivatedProfiler = enabled;
	}

	bool CzvProfiler::EnabledProfiler()
	{
		return (s_ActivatedProfiler);
	}


} // namespace ZVLab