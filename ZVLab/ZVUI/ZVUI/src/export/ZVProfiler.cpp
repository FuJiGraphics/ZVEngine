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
		
		if (ImPlot::BeginPlot("PlotRender"))
		{
			for (const auto& profiler : s_ProfilerLists)
			{
				profiler.second->PlotRender();
			}
			ImPlot::EndPlot();
		}

		CzvTabBar tab_TableRender("Profiler");
		for (const auto& profiler : s_ProfilerLists)
		{
			profiler.second->TableRender();
		}

		//static ImPlotColormap Liars = -1;
		//if (Liars == -1) {
		//	static const ImU32 Liars_Data[6] = { 4282515870, 4282609140, 4287357182, 4294630301, 4294945280, 4294921472 };
		//	Liars = ImPlot::AddColormap("Liars", Liars_Data, 6);
		//}

		//static std::vector<const char*> tempname = { "name1", "name2", "name3" };
		//static std::vector<float> tempData1 = { 1.0f, -0.5, 3.0f };
		//static std::vector<float> tempData2 = { 2.0f, -3.5, 1.0f };
		//static std::vector<float> tempData3 = { 5.0f, -2.5, 2.0f };
		//static std::vector<float> tempArray;
		//tempArray.push_back(tempData1[0]); tempArray.push_back(tempData1[1]); tempArray.push_back(tempData1[2]);
		//tempArray.push_back(tempData2[0]); tempArray.push_back(tempData2[1]); tempArray.push_back(tempData2[2]);
		//tempArray.push_back(tempData3[0]); tempArray.push_back(tempData3[1]); tempArray.push_back(tempData3[2]);
		//static bool diverging = true;
		//ImGui::Checkbox("Diverging", &diverging);
		//ImPlot::PushColormap(Liars);
		//if (ImPlot::BeginPlot("PolitiFact: Who Lies More?", ImVec2(-1, 400), ImPlotFlags_NoMouseText)) {
		//	ImPlot::SetupLegend(ImPlotLocation_South, ImPlotLegendFlags_Outside | ImPlotLegendFlags_Horizontal);
		//	ImPlot::SetupAxes(NULL, NULL, ImPlotAxisFlags_AutoFit | ImPlotAxisFlags_NoDecorations, ImPlotAxisFlags_AutoFit | ImPlotAxisFlags_Invert);
		//	ImPlot::SetupAxisTicks(ImAxis_Y1, 0, 19, tempname.size(), tempname.data(), false);
		//	if (diverging)
		//		ImPlot::PlotBarGroups(tempname.data(), tempArray.data(), 3, 3, 0.75, 0, ImPlotBarGroupsFlags_Stacked | ImPlotBarGroupsFlags_Horizontal);
		//	else
		//		ImPlot::PlotBarGroups(tempname.data(), tempArray.data(), 3, 3, 0.75, 0, ImPlotBarGroupsFlags_Stacked | ImPlotBarGroupsFlags_Horizontal);
		//	ImPlot::EndPlot();
		//}
		//ImPlot::PopColormap();
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