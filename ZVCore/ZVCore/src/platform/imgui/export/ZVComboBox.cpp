#include "ZVComboBox.h"

namespace { /// statics
	static unsigned int	s_unComboBoxCount = 0;

	static std::map<std::string, std::pair<std::string, int>>
		s_mComboStatusMap;
	static bool sRegistComboBoxStatus(const std::string& key, const std::string& str, int index)
	{
		bool result = false;
		auto& f = s_mComboStatusMap.find(key);
		if (f == s_mComboStatusMap.end())
		{
			s_mComboStatusMap.insert({ key, {str, index} });
			result = true;
		}
		else // 찾았을 시
		{
			auto& targetItem = f->second;
			targetItem.first = str;
			targetItem.second = index;
		}
		return (result);
	}
	static std::pair<const char*, int> sGetComboBoxStatus(const std::string& key)
	{
		auto& f = s_mComboStatusMap.find(key);
		if (f == s_mComboStatusMap.end())
			::sRegistComboBoxStatus(key, "", 0);
		return (std::make_pair(s_mComboStatusMap[key].first.c_str(), s_mComboStatusMap[key].second));
	}
	static bool sReleaseComboBoxStatus(const std::string& key)
	{
		bool result = false;
		auto& f = s_mComboStatusMap.find(key);
		if (f != s_mComboStatusMap.end())
		{
			s_mComboStatusMap.erase(key);
			result = true;
		}
		return (result);
	}
}


namespace ZVLab {
	
	CzvComboBox::CzvComboBox(const std::string& label, const TzvComboBoxInfo& info)
		: m_strLabel(label)
		, m_tOptions(info)
		, m_vItemList()
	{
	}

	CzvComboBox::~CzvComboBox()
	{
	}

	void CzvComboBox::SetItems(const Args<const char *>& item_list)
	{
		m_vItemList.clear();
		m_vItemList.resize(item_list.size());
		m_vItemList = std::vector<const char*>(item_list);
	}

	std::string	CzvComboBox::Bind()
	{
		auto& currItemData = ::sGetComboBoxStatus(m_strLabel);
		std::string resultItem = m_vItemList[currItemData.second];
		if (m_vItemList.empty() == false)
		{
			int itemSize = m_vItemList.size();
			auto& currItemIndex = currItemData.second;
			if (ImGui::BeginCombo(m_strLabel.c_str(), m_vItemList[currItemIndex], m_tOptions.GetOptions()))
			{
				for (int i = 0; i < itemSize; ++i)
				{
					const bool is_selected = (currItemIndex == i);
					if (ImGui::Selectable(m_vItemList[i], is_selected))
					{
						sRegistComboBoxStatus(m_strLabel, m_vItemList[i], i);
						resultItem = m_vItemList[i];
					}
					// Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
					if (is_selected)
						ImGui::SetItemDefaultFocus();
				}
				ImGui::EndCombo();
			}
		}
		return (resultItem);
	}

} // namespace ZVLab
