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
		static std::vector<float> bar_data;
		static std::vector<float> bar_time;
		static std::vector<const char *> bar_str;

		static float t = 0;
		t += ImGui::GetIO().DeltaTime;
		static float history = 10.0f;
		ImGui::SliderFloat("History", &history, 1, 30, "%.1f s");
		static ImPlotAxisFlags flags = ImPlotAxisFlags_NoTickLabels;
		ImPlot::SetupAxes(NULL, NULL, flags, flags);
		ImPlot::SetupAxisLimits(ImAxis_X1, t - history, t, ImGuiCond_Always);
		ImPlot::SetupAxisLimits(ImAxis_Y1, 0, 1);
		ImPlot::SetNextFillStyle(IMPLOT_AUTO_COL, 0.5f);
		for (auto& profile : m_vDataList)
		{
			bar_data.push_back(profile->second);
			bar_time.push_back(ImGui::GetTime());
			bar_str.push_back(profile->first.c_str());
		}
		ImPlot::SetupAxes("x", "y");
		ImPlot::PlotLine(m_strLabel.c_str(), bar_time.data(), bar_data.data(), bar_time.size());
	}

	void CzvProfiler_internal::TableRender()
	{
		for (auto& profile : m_vDataList)
		{
			if (ImGui::BeginTabItem(m_strLabel.c_str(), &m_bOpen))
			{
				ImGui::Text(profile->first.c_str());
				ImGui::SameLine();
				ImGui::Text("\t %f", profile->second);
				ImGui::SameLine();
				ImGui::Text("ms");
				ImGui::EndTabItem();
			}
		}
	}

} // namespace ZVLab