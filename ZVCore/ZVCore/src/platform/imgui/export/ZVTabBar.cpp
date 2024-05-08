#include "ZVTabBar.h"

namespace ZVLab {

	namespace { /// static variable
		static bool					s_bFirstEntryScope = true;
		static TzvTabBarChunk		s_CurrTabBarData;
		static unsigned int			s_unTabBarCount = 0;
	}

	CzvTabBar::CzvTabBar(const std::string& label, const TzvTabBarInfo& info)
		: m_tData{ label, info, false }
	{
		DZVLog_Failed(label.size(), "FAILED: Label length must be than or equal to 0.");
		this->Synchronization();
		s_unTabBarCount++;
		DZVLog_Failed((s_unTabBarCount > 0),
					  "FAILED: Unexpected Error! Tab Bar Count is not greater than 0 \"s_nuiDialogCount = {0}\"",
					  s_unTabBarCount);
	}

	CzvTabBar::~CzvTabBar()
	{
		if (s_CurrTabBarData.Label == m_tData.Label)
		{
			// Release a tab bar
			s_bFirstEntryScope = true;
			ImGui::EndTabBar();
			s_CurrTabBarData.Label.clear();
		}
		s_unTabBarCount--;
		DZVLog_Failed((s_unTabBarCount >= 0),
					  "FAILED: Unexpected Error! Tab Bar Count is less than 0 \"s_nuiDialogCount = {0}\"",
					  s_unTabBarCount);
	}

	bool CzvTabBar::TabItem(const std::string& label)
	{
		CzvTabItem item(label);
		return (item.Bind());
	}

	bool CzvTabBar::TabItem(const std::string& label, const TzvTabItemInfo& option)
	{
		CzvTabItem item(label, option);
		return (item.Bind());
	}

	bool CzvTabBar::TabItem(CzvTabItem& item)
	{
		return (item.Bind());
	}

	bool CzvTabBar::Synchronization()
	{
		if (s_CurrTabBarData.Label != m_tData.Label || s_bFirstEntryScope)
		{
			if (s_bFirstEntryScope)
				s_bFirstEntryScope = false;
			else
				ImGui::EndTabBar();

			s_CurrTabBarData.Label = m_tData.Label;
			s_CurrTabBarData.IsUnFolded = m_tData.IsUnFolded;
			s_CurrTabBarData.tOptions = m_tData.tOptions;
			return (m_tData.IsUnFolded = ImGui::BeginTabBar(m_tData.Label.c_str(), m_tData.tOptions.GetOptions()));
		}
		return (m_tData.IsUnFolded);
	}

} // namespace ZVLab