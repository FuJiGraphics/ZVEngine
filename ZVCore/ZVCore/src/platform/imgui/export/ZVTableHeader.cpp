#include "ZVTableHeader.h"

namespace ZVLab {

	CzvTableHeader::CzvTableHeader(const std::string& label, const TzvTableHeaderInfo& options)
		: m_strLabel(label)
		, m_vItems()
		, m_tOptions(options)
		, m_tSelInfo()
		, m_bIsSelMode(false)
		, m_iSelectItem(0)
	{/*Empty*/}

	CzvTableHeader::~CzvTableHeader()
	{/*Empty*/}

	inline int CzvTableHeader::GetSelectIndex() const
	{
		if (this->IsSelectableMode())
			return (m_iSelectItem);
		else
			return (-1);
	}

	inline bool CzvTableHeader::IsSelectableMode() const
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

	void CzvTableHeader::AddItem(const std::vector<std::string>& vItems)
	{
		if (vItems.empty())
			return;

		for (const auto& item : vItems)
		{
			m_vItems.push_back({ item });
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

	inline void CzvTableHeader::SetLabel(const std::string& label)
	{
		m_strLabel = label;
	}

	inline void CzvTableHeader::SetOptions(const TzvTableHeaderInfo& options)
	{
		m_tOptions = options;
	}

	inline void CzvTableHeader::SetItem(const std::initializer_list<std::string>& item_labels)
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
			m_iSelectItem = false;
	}

	void CzvTableHeader::Bind()
	{
		ImGui::TableSetupColumn(m_strLabel.c_str(), m_tOptions.GetOptions());
	}

	void CzvTableHeader::ItemBind(int index)
	{
		ImGui::TableNextColumn();
		if (this->HasValue())
		{
			if (m_bIsSelMode)
			{
				if (ImGui::Selectable(m_vItems.at(index).GetLabel(), index == m_iSelectItem, m_tSelInfo.GetOptions()))
				{
					m_iSelectItem = index;
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
		ImGui::Text(strText.c_str());
	}

} // namespace ZVLab
