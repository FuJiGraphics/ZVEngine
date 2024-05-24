#include "ZVTableHeader.h"

namespace ZVLab {

	CzvTableHeader::CzvTableHeader(const std::string& label, const TzvTableHeaderInfo& options)
		: m_strLabel(label)
		, m_tOptions(options)
	{/*Empty*/}

	CzvTableHeader::~CzvTableHeader()
	{/*Empty*/}

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

	void CzvTableHeader::Bind()
	{
		ImGui::TableSetupColumn(m_strLabel.c_str(), m_tOptions.GetOptions());
	}

	TzvItem CzvTableHeader::operator[](unsigned int index)
	{
		if (index < m_vItems.size())
			return (m_vItems[index]);
		else
			return (TzvItem());
	}

	TzvItem::TzvItem(const std::string& text)
		: strText(text)
	{/*Empty*/}

	void TzvItem::Bind()
	{
		ImGui::TableNextColumn();
		ImGui::Text(strText.c_str());
	}

} // namespace ZVLab
