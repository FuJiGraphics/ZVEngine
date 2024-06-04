#include "ZVTable.h"

namespace ZVLab {

	CzvTable::CzvTable(const std::string& label, const TzvTableInfo& info)
		: m_strLabel(label)
		, m_ivSize(0.0f, 0.0f)
		, m_fInnerWidth(0.0f)
		, m_tOptions(info)
		, m_vHeaderList()
		, m_czvIndexList("ID")
	{/*Empty*/}

	CzvTable::CzvTable(const std::string& label, const ImVec2& size, const TzvTableInfo& info)
		: m_strLabel(label)
		, m_ivSize(size)
		, m_fInnerWidth(0.0f)
		, m_tOptions(info)
		, m_vHeaderList()
		, m_czvIndexList("ID")
	{/*Empty*/}

	CzvTable::~CzvTable()
	{

	}

	std::string CzvTable::GetLabel() const
	{
		return (m_strLabel);
	}

	unsigned int CzvTable::GetRowSize() const
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

	unsigned int CzvTable::GetColSize() const
	{
		return (m_vHeaderList.size());
	}

	TzvTableCoord CzvTable::GetSelectAllIndex() const
	{
		TzvTableCoord coord;

		if (m_czvIndexList.IsSelectableMode())
		{
			int ySel = m_czvIndexList.GetSelectIndex();
			if (ySel > -1)
			{
				coord.x = 0;
				coord.y = ySel;
			}
		}
		else 
		{
			for (int i = 0; i < m_vHeaderList.size(); ++i)
			{
				if (m_vHeaderList[i].IsSelectableMode())
				{
					int ySel = m_vHeaderList[i].GetSelectIndex();
					if (ySel > -1)
					{
						coord.x = i;
						coord.y = ySel;
						break;
					} // if
				} // if
			} // for
		} // else
		return (coord);
	}

	int CzvTable::GetSelectYaxisIndex() const
	{
		int ySel;
		if (m_czvIndexList.IsSelectableMode())
		{
			ySel = m_czvIndexList.GetSelectIndex();
			if (ySel > -1)
				return (ySel);
		}
		else 
		{
			for (int i = 0; i < m_vHeaderList.size(); ++i)
			{
				if (m_vHeaderList[i].IsSelectableMode())
				{
					int ySel = m_vHeaderList[i].GetSelectIndex();
					if (ySel > -1)
						return (ySel);
				} // if
			} // for
		} // else

		return (-1);
	}

	void CzvTable::SetHeaders(const std::initializer_list<CzvTableHeader>& header_labels)
	{
		m_vHeaderList.clear();
		for (const auto& header : header_labels)
		{
			m_vHeaderList.push_back({ header });
		}
	}

	void CzvTable::AddHeader(const std::string& header_label, const TzvTableHeaderInfo& options)
	{
		m_vHeaderList.push_back({header_label, options});
	}

	void CzvTable::SetLabel(const std::string& label)
	{
		m_strLabel = label;
	}

	void CzvTable::SetOptions(const TzvTableInfo& options)
	{
		m_tOptions = options;
	}

	void CzvTable::SetIndexLabel(const std::string& label)
	{
		m_czvIndexList.SetLabel(label);
	}

	void CzvTable::SetSelectable(bool enabled, const TzvSelectableInfo& info)
	{
		if (info.IsEmpty())
		{
			TzvSelectableInfo tzvDefInfo;
			tzvDefInfo.SetSpanAllColumns(true);
			tzvDefInfo.SetAllowOverlap(true);
			m_czvIndexList.SetSelectable(enabled, tzvDefInfo);
		}
		else
		{
			m_czvIndexList.SetSelectable(enabled, info);
		}
	}

	void CzvTable::Bind()
	{
		bool bIndexedMode = m_tOptions.IsActivated(EzvTableOptions::ezvTableFlags_ArrangeIndexed);
		int iColSize = m_vHeaderList.size() + ((bIndexedMode) ? 1 : 0);
		if (iColSize && ImGui::BeginTable(m_strLabel.c_str(),
							  iColSize,
							  m_tOptions.GetOptions(), m_ivSize, m_fInnerWidth))
		{
			// Draw Headers
			if (!m_vHeaderList.empty())
			{
				if (bIndexedMode)
				{
					m_czvIndexList.Bind();
				}
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
					if (bIndexedMode)
					{
						m_czvIndexList.AddItem(std::to_string(y).c_str());
						m_czvIndexList.ItemBind(y);
					}
					for (int x = 0; x < iColSize - 1; ++x)
					{
						auto& header = m_vHeaderList[x];
						header.ItemBind(y);
					}
				}
				m_czvIndexList.Clear();
			}
			ImGui::EndTable();
		}
	}

	void CzvTable::Clear()
	{
		m_vHeaderList.clear();
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

	CzvTableHeader& CzvTable::operator[](int index)
	{
		return (m_vHeaderList[index]);
	}

} // namespace ZVLab