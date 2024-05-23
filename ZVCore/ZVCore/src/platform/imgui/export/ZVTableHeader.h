#ifndef __ZV_TABLE_HEADER_H__
#define __ZV_TABLE_HEADER_H__
#pragma once

#include "../../../core/Core.h"
#include "ZVGuiConfig.h"

namespace ZVLab {

	struct ZV_API TzvItem
	{
	private:
		std::string	strText;

	public:
		TzvItem(const std::string& text = " ");
		void Bind();
	};

	class ZV_API CzvTableHeader
	{
	//// Member Function
	private:
		std::string					m_strLabel;
		std::vector<TzvItem>		m_vItems;
		TzvTableHeaderInfo			m_tOptions;

	//// Member Functions
	public:
		// Constructor, Destructors
		CzvTableHeader(const std::string& label, const TzvTableHeaderInfo& options = TzvTableHeaderInfo());
		~CzvTableHeader();

		// Getter
		inline std::string		GetLabel() const	{ return (m_strLabel); }
		inline unsigned int		GetSize() const		{ return (m_vItems.size()); }
		TzvItem					GetItem(unsigned int index) const;
		bool					HasValue() const;

		// Setter
		void					AddItem(const char* fmt, ...);
		inline void				SetLabel(const std::string& label);
		inline void				SetOptions(const TzvTableHeaderInfo& options);
		inline void				SetItem(const std::initializer_list<std::string>& item_labels);

		// Others
		void					Bind();

		// Operator
		TzvItem					operator[](unsigned int index);
	};

} // namespace ZVLab

#endif /*__ZV_TABLE_HEADER_H__*/
