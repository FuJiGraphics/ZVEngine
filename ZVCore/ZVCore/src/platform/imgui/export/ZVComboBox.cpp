#include "ZVComboBox.h"
#include "../ZVimguiManager.h"

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
	{/*Empty*/}

	CzvComboBox::CzvComboBox(const std::vector<std::string>& item_list,
							 const TzvComboBoxInfo& info)
		: m_strLabel("##")
		, m_tOptions(info)
		, m_vItemList()
	{
		this->SetItems(item_list);
	}

	CzvComboBox::CzvComboBox(const std::vector<const char*>& item_list, 
							 const TzvComboBoxInfo& info)
		: m_strLabel("##")
		, m_tOptions(info)
		, m_vItemList()
	{
		this->SetItems(item_list);
	}

	CzvComboBox::CzvComboBox(const Args<const char*>& item_list, 
							 const TzvComboBoxInfo& info)
		: m_strLabel("##")
		, m_tOptions(info)
		, m_vItemList()
	{
		this->SetItems(item_list);
	}

	CzvComboBox::~CzvComboBox()
	{
	}

	std::string CzvComboBox::GetLabel() const
	{
		return (m_strLabel);
	}

	int CzvComboBox::GetSize() const
	{
		return (m_vItemList.size());
	}

	void CzvComboBox::AddItems(const char* item)
	{
		if (DZVLog_Failed(item, "Item is null!! = {0}", item))
		{
			m_vItemList.push_back(item);
		}
	}

	void CzvComboBox::AddItems(const std::string& item)
	{
		m_vItemList.push_back(item.c_str());
	}

	void CzvComboBox::SetItems(const std::vector<const char*>& item_list)
	{
		if (item_list.size())
		{
			m_vItemList.clear();
			for (const auto& item : item_list)
			{
				m_vItemList.push_back(item);
			}
		}
	}

	void CzvComboBox::SetItems(const std::vector<std::string>& item_list)
	{
		if (item_list.size())
		{
			m_vItemList.clear();
			for (const auto& item : item_list)
			{
				m_vItemList.push_back(item.c_str());
			}
		}
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
			CzvImguiManager::PushID();
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
			CzvImguiManager::PopID();
		}
		return (resultItem);
	}

	std::string CzvComboBox::operator[](int index)
	{
		if (DZVLog_Failed((index >= 0 && index < this->GetSize()),
						  "List Out of range index! = {0}", index))
		{
			return (m_vItemList[index]);
		}
		return std::string();
	}

	std::string CzvComboBox::operator[](int index) const
	{
		if (DZVLog_Failed((index >= 0 && index < this->GetSize()),
						  "List Out of range index! = {0}", index))
		{
			return (m_vItemList[index]);
		}
		return std::string();
	}

} // namespace ZVLab
