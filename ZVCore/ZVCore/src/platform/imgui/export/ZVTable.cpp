#include "ZVTable.h"

namespace ZVLab {

	CzvTable::CzvTable(const std::string& label, const TzvTableInfo& info)
		: m_strLabel(label)
		, m_ivSize(0.0f, 0.0f)
		, m_fInnerWidth(0.0f)
		, m_tOptions(info)
		, m_vHeaderList()
	{/*Empty*/}

	CzvTable::CzvTable(const std::string& label, const ImVec2& size, const TzvTableInfo& info)
		: m_strLabel(label)
		, m_ivSize(size)
		, m_fInnerWidth(0.0f)
		, m_tOptions(info)
		, m_vHeaderList()
	{/*Empty*/}

	CzvTable::~CzvTable()
	{

	}

	inline std::string CzvTable::GetLabel() const
	{
		return (m_strLabel);
	}

	inline unsigned int CzvTable::GetRowSize() const
	{
		unsigned int max_row = 0;
		unsigned int curr_row = 0;
		for (const auto& header : m_vHeaderList)
		{
			curr_row = header.GetSize();
			if (curr_row > max_row)
				max_row = curr_row;
		}
		return (max_row);
	}

	inline unsigned int CzvTable::GetColSize() const
	{
		return (m_vHeaderList.size());
	}

	void CzvTable::SetHeaders(const std::initializer_list<std::string>& header_labels)
	{
		m_vHeaderList.clear();
		for (const auto& label : header_labels)
		{
			m_vHeaderList.push_back(label);
		}
	}

	void CzvTable::AddHeader(const std::string& header_label, const TzvTableHeaderInfo& options)
	{
		m_vHeaderList.push_back({header_label, options});
	}

	inline void CzvTable::SetLabel(const std::string& label)
	{
		m_strLabel = label;
	}

	void CzvTable::Bind()
	{
		if (ImGui::BeginTable(m_strLabel.c_str(), m_vHeaderList.size(), 
							  m_tOptions.GetOptions(), m_ivSize, m_fInnerWidth))
		{
			// Draw Headers
			if (!m_vHeaderList.empty())
			{
				for (auto& header : m_vHeaderList)
				{
					header.Bind();
				}
				ImGui::TableSetupScrollFreeze(0, 1);
				ImGui::TableHeadersRow(); 
				// Draw table items
				int row = this->GetRowSize();
				int col = this->GetColSize();
				for (int y = 0; y < row; ++y)
				{
					ImGui::TableNextRow();
					for (int x = 0; x < col; ++x)
					{
						auto& header = m_vHeaderList[x];
						auto& item = header.GetItem(y);
						item.Bind();
					}
				}
			}
			ImGui::EndTable();
		}
	}

	CzvTableHeader&	CzvTable::operator[](const std::string& str)
	{
		for (auto& header : m_vHeaderList)
		{
			if (header.GetLabel() == str)
			{
				return (header);
			}
		}
		this->AddHeader(str);
		return (m_vHeaderList[m_vHeaderList.size() - 1]);
	}


} // namespace ZVLab