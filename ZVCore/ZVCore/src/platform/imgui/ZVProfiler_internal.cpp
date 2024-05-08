#include "ZVProfiler_internal.h"
#include "export/ZVDialog.h"

namespace ZVLab {
	CzvProfiler_internal::CzvProfiler_internal(const std::string& label)
		: m_strLabel(label)
		, m_bOpen(true)
	{
	}

	CzvProfiler_internal::~CzvProfiler_internal()
	{
		m_mData.clear();
		m_vDataList.clear();
	}

	void CzvProfiler_internal::Submit(const TzvTimeStep& data)
	{
		if (m_mData.find(data.Label) == m_mData.end())
		{
			m_mData.insert({ data.Label, {data.Label, data.ElapsedTime} });
			m_vDataList.push_back(&m_mData[data.Label]);
		}
		else // 데이터 발견 시
		{
			float currElapTime = data.ElapsedTime;
			float prevElapTime = m_mData[data.Label].second;
			if (currElapTime != prevElapTime)
			{
				m_mData[data.Label].second = currElapTime;
			}
		}
	}

	void CzvProfiler_internal::PlotRender()
	{
		//for (auto& profile : m_vDataList)
		//{
		//	bar_data.push_back(profile->second);
		//	bar_time.push_back(ImGui::GetTime());
		//	bar_str.push_back(profile->first.c_str());
		//}
		//ImPlot::PlotLine(m_strLabel.c_str(), bar_time.data(), bar_data.data(), bar_time.size());

		static ImS8  data[30] = { 83, 67, 23, 89, 83, 78, 91, 82, 85, 90,  // midterm
						 80, 62, 56, 99, 55, 78, 88, 78, 90, 100, // final
						 80, 69, 52, 92, 72, 78, 75, 76, 89, 95 }; // course

		static const char*  ilabels[] = { "Midterm Exam","Final Exam","Course Grade" };
		static const char*  glabels[] = { "S1","S2","S3","S4","S5","S6","S7","S8","S9","S10" };
		static const double positions[] = { 0,1,2,3,4,5,6,7,8,9 };

		static int items = 3;
		static int groups = 10;
		static float size = 0.67f;

		static ImPlotBarGroupsFlags flags = 0;
		static bool horz = false;

		ImGui::CheckboxFlags("Stacked", (unsigned int*)&flags, ImPlotBarGroupsFlags_Stacked);
		ImGui::SameLine();
		ImGui::Checkbox("Horizontal", &horz);

		ImGui::SliderInt("Items", &items, 1, 3);
		ImGui::SliderFloat("Size", &size, 0, 1);

		ImPlot::SetupLegend(ImPlotLocation_East, ImPlotLegendFlags_Outside);
		if (horz) {
			ImPlot::SetupAxes("Score", "Student", ImPlotAxisFlags_AutoFit, ImPlotAxisFlags_AutoFit);
			ImPlot::SetupAxisTicks(ImAxis_Y1, positions, groups, glabels);
			ImPlot::PlotBarGroups(ilabels, data, items, groups, size, 0, flags | ImPlotBarGroupsFlags_Horizontal);
		}
		else {
			ImPlot::SetupAxes("Student", "Score", ImPlotAxisFlags_AutoFit, ImPlotAxisFlags_AutoFit);
			ImPlot::SetupAxisTicks(ImAxis_X1, positions, groups, glabels);
			ImPlot::PlotBarGroups(ilabels, data, items, groups, size, 0, flags);
		}
	}

	void CzvProfiler_internal::TableRender()
	{
		CzvTabItem tabItem(m_strLabel.c_str());
		if (tabItem.Bind())
		{
			for (auto& profile : m_vDataList)
			{
				ImGui::Text(profile->first.c_str());
				ImGui::SameLine();
				ImGui::Text("\t %f", profile->second);
				ImGui::SameLine();
				ImGui::Text("ms");
			}
		}
	}


} // namespace ZVLab