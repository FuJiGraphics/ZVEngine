#ifndef __ZV_TABLE_H__
#define __ZV_TABLE_H__
#pragma once

#include "../../../core/Core.h"
#include "ZVGuiConfig.h"
#include "ZVTableHeader.h"

namespace ZVLab {
	
	struct TzvTableCoord
	{
		int x = 0;
		int y = 0;
	};

	class ZV_API CzvTable
	{
	//// Member Variables
	private:
		// Table Info
		std::string					m_strLabel;
		ImVec2						m_ivSize;
		float						m_fInnerWidth;
		TzvTableInfo				m_tOptions;
		// Table Data
		std::vector<CzvTableHeader>	m_vHeaderList;
		CzvTableHeader				m_czvIndexList;

	//// Member Functions
	public:
		// Constructor, Destructors
		CzvTable(const std::string& label, const TzvTableInfo& info = TzvTableInfo());
		CzvTable(const std::string& label, const ImVec2& size, const TzvTableInfo& info = TzvTableInfo());
		~CzvTable();

		// Getter
		std::string			GetLabel() const;
		unsigned int		GetRowSize() const;
		unsigned int		GetColSize() const;
		TzvTableCoord		GetSelectAllIndex() const;
		int					GetSelectYaxisIndex() const;

		// Setter
		void				SetLabel(const std::string& label);
		void				SetOptions(const TzvTableInfo& options);
		void				SetIndexLabel(const std::string& label);
		void				SetSelectable(bool enabled, const TzvSelectableInfo& info = TzvSelectableInfo());
		void				SetHeaders(const std::initializer_list<std::string>& header_labels);
		void				AddHeader(const std::string& header_label, const TzvTableHeaderInfo& options = TzvTableHeaderInfo());
		
		// Others
		void				Bind();
		void				Clear();

		// Operator
		CzvTableHeader&	operator[](const std::string& str);
		CzvTableHeader& operator[](int index);

	};

} // namespace ZVLab

#endif /*__ZV_TABLE_H__*/
