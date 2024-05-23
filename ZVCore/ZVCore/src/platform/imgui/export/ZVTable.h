#ifndef __ZV_TABLE_H__
#define __ZV_TABLE_H__
#pragma once

#include "../../../core/Core.h"
#include "ZVGuiConfig.h"
#include "ZVTableHeader.h"

namespace ZVLab {

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

	//// Member Functions
	public:
		// Constructor, Destructors
		CzvTable(const std::string& label, const TzvTableInfo& info = TzvTableInfo());
		CzvTable(const std::string& label, const ImVec2& size, const TzvTableInfo& info = TzvTableInfo());
		~CzvTable();

		// Getter
		inline std::string	GetLabel() const;
		inline unsigned int	GetRowSize() const;
		inline unsigned int	GetColSize() const;

		// Setter
		inline void			SetLabel(const std::string& label);
		void				SetHeaders(const std::initializer_list<std::string>& header_labels);
		void				AddHeader(const std::string& header_label, const TzvTableHeaderInfo& options = TzvTableHeaderInfo());

		// Others
		void				Bind();
		void				Clear();

		// Operator
		CzvTableHeader&	operator[](const std::string& str);
		CzvTableHeader& operator[]( unsigned int index );

	};

} // namespace ZVLab

#endif /*__ZV_TABLE_H__*/
