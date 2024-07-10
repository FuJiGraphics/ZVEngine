#include "ZVTableHeader.h"

namespace {
	static std::map<std::string, int>  s_mSelectIndexMap;
}

namespace ZVLab {


	CzvTableHeader::CzvTableHeader(const std::string& label, int& parentIndex, const TzvTableHeaderInfo& options)
		: m_strLabel(label)									
		, m_vItems()
		, m_tOptions(options)
		, m_tSelInfo()
		, m_bIsSelMode(false)
		, m_refParentIndex(parentIndex)
	{/*Empty*/}

	CzvTableHeader::CzvTableHeader(const std::string& label, int& parentIndex, const TzvSelectableInfo& sel_info)
		: m_strLabel(label)
		, m_vItems()
		, m_tOptions()
		, m_tSelInfo(sel_info)
		, m_bIsSelMode(true)
		, m_refParentIndex(parentIndex)
	{/*Empty*/}

	CzvTableHeader::~CzvTableHeader()
	{/*Empty*/}

	int CzvTableHeader::GetSelectIndex() const
	{
		if (this->IsSelectableMode())
			return (m_refParentIndex);
		else
			return (-1);
	}

	bool CzvTableHeader::IsSelectableMode() const
	{
		return (m_bIsSelMode);
	}

	TzvItem CzvTableHeader::GetItem(unsigned int index) const
	{
		if (index < m_vItems.size())
			return (m_vItems[index]);
		else
			return (TzvItem());
	}

	bool CzvTableHeader::HasValue() const
	{
		return (!m_vItems.empty());
	}

	//void CzvTableHeader::AddItem(const CzvComboBox& item)
	//{
	//	m_vItems.push_back({ item });
	//}

	void CzvTableHeader::AddItem(const std::string& str)
	{
		if (str.empty())
			return;

		m_vItems.push_back({ str.c_str() });
	}

	void CzvTableHeader::AddItem(const std::vector<std::string>& vItems)
	{
		if (vItems.empty())
			return;

		for (const auto& item : vItems)
		{
			m_vItems.push_back({ item.c_str() });
		}
	}

	void CzvTableHeader::AddItem(const char* fmt, ...)
	{
		va_list args;
		va_start(args, fmt);
		const char* text, *text_end;
		ImFormatStringToTempBufferV(&text, &text_end, fmt, args);
		m_vItems.push_back({ text });
		va_end(args);
	}

	void CzvTableHeader::SetLabel(const std::string& label)
	{
		m_strLabel = label;
	}

	void CzvTableHeader::SetOptions(const TzvTableHeaderInfo& options)
	{
		m_tOptions = options;
	}

	void CzvTableHeader::SetItem(const std::vector<CzvComboBox>& vItems)
	{
		m_vItems.clear();
		for (const auto& item : vItems)
		{
			m_vItems.push_back(item);
		}
	}

	void CzvTableHeader::SetItem(const std::vector<std::string>& vItems)
	{
		m_vItems.clear();
		for (const auto& item : vItems)
		{
			m_vItems.push_back({ item.c_str() });
		}
	}

	void CzvTableHeader::SetItem(const std::initializer_list<std::string>& item_labels)
	{
		m_vItems.clear();
		for (const auto& label : item_labels)
		{
			m_vItems.push_back({ label.c_str() });
		}
	}

	void CzvTableHeader::SetSelectable(bool enabled, const TzvSelectableInfo& info)
	{
		m_tSelInfo = info;
		m_bIsSelMode = enabled;
		if (m_bIsSelMode == false)
			m_refParentIndex = 0;
	}

	void CzvTableHeader::SetNextSelectableIndex(int maxSize)
	{
		if (m_refParentIndex + 1 >= maxSize)
		{
			m_refParentIndex = 0;
		}
		else
			m_refParentIndex++;
	}


	void CzvTableHeader::ResetSelectableIndex()
	{
		m_refParentIndex = 0;
	}

	void CzvTableHeader::Bind()
	{
		ImGui::TableSetupColumn(m_strLabel.c_str(), m_tOptions.GetOptions());
	}

	void CzvTableHeader::ItemBind(int index)
	{
		ImGui::TableNextColumn();
		
		// TODO: Table Item Popup ±â´É
		// ImGui::OpenPopupOnItemClick("test0", ImGuiPopupFlags_MouseButtonRight);
		if (this->HasValue() && index < m_vItems.size())
		{
			if (ImGui::BeginPopup("test0"))
			{
				ImGui::Text("Contents");
				ImGui::EndPopup();
			}
			if (m_bIsSelMode)
			{

				if (ImGui::Selectable(m_vItems.at(index).GetLabel(), 
									  index == m_refParentIndex, m_tSelInfo.GetOptions()))
				{
					m_refParentIndex = index;
				}
			}
			else
				m_vItems.at(index).Bind();
		}
		else
		{
			TzvItem().Bind();
		}
	}

	CzvTableHeader::iter CzvTableHeader::Find(const std::string& str)
	{
		int size = static_cast<int>(m_vItems.size());
		for (int i = 0; i < size; ++i)
		{
			auto iter = (m_vItems.begin() + i);
			if (iter->GetLabel() == str)
			{
				return (iter);
			}
		}
		return (m_vItems.end());
	}

	CzvTableHeader::iter CzvTableHeader::begin()
	{
		return (m_vItems.begin());
	}

	CzvTableHeader::iter CzvTableHeader::end()
	{
		return (m_vItems.end());
	}

	CzvTableHeader::const_iter CzvTableHeader::begin() const
	{
		return (m_vItems.begin());
	}

	CzvTableHeader::const_iter CzvTableHeader::end() const
	{
		return (m_vItems.end());
	}

	void CzvTableHeader::Clear()
	{
		m_vItems.clear();
	}

	TzvItem CzvTableHeader::operator[](int index)
	{
		if (index < m_vItems.size())
			return (m_vItems[index]);
		else
			return (TzvItem());
	}

	TzvItem CzvTableHeader::operator[](int index) const
	{
		if (index < m_vItems.size())
			return (m_vItems[index]);
		else
			return (TzvItem());
	}

	TzvItem::TzvItem(const std::string& text)
		: strText(text)
		, ComboBox()
		, eType(EzvItemType::eText)
	{/*Empty*/}

	TzvItem::TzvItem(const CzvComboBox& comboItems)
		: strText("##")
		, ComboBox()
		, eType(EzvItemType::eComboBox)
	{
		int size = comboItems.GetSize();
		std::vector<std::string> vTempItems;
		for (int i = 0; i < size; ++i)
		{
			vTempItems.push_back({ comboItems[i] });
		}
		ComboBox.SetItems(vTempItems);
	}

	TzvItem::~TzvItem()
	{/*Empty*/}

	const char* TzvItem::GetLabel()
	{
		return (strText.c_str());
	}

	const char* TzvItem::GetLabel() const
	{
		return (strText.c_str());
	}

	void TzvItem::Bind()
	{
		switch (this->eType)
		{
			case EzvItemType::eText:
				ImGui::Text(strText.c_str());
				return;
			case EzvItemType::eComboBox:
				TzvComboBoxInfo info;
				info.SetNoPreview(true);
				ComboBox.Bind(info, true);
				return;
		}
	}

} // namespace ZVLab
