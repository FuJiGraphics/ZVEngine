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

	void CzvProfiler_internal::Render()
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

		CzvButton button(m_strLabel.c_str());
		if (button.Bind())
		{
			m_bOpen = true;
		}
	}

} // namespace ZVLab