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
		const char*		GetLabel();
		const char*		GetLabel() const;
		void			Bind();
	};

	class ZV_API CzvTableHeader
	{
	//// Member Function
	private:
		std::string					m_strLabel;
		std::vector<TzvItem>		m_vItems;
		TzvTableHeaderInfo			m_tOptions;
		TzvSelectableInfo			m_tSelInfo;
		bool						m_bIsSelMode;
		int							m_iSelectItem;

	//// Member Functions
	public:
		// Constructor, Destructors
		CzvTableHeader(const std::string& label, const TzvTableHeaderInfo& options = TzvTableHeaderInfo());
		~CzvTableHeader();

		// Getter
		inline std::string		GetLabel() const { return (m_strLabel); }
		inline unsigned int		GetSize() const { return (m_vItems.size()); }
		/**
		 * @brief		���� ���õ� �ε����� ��ȯ�մϴ�.
		 * @details		���� ���̺� ���õ� �ε���(int)���� ��ȯ�մϴ�.
		 * - ���� ��, (int)-1�� ��ȯ�մϴ�.
		 * @return		int: ���� ���õ� �ε��� �� 
		 */
		inline int				GetSelectIndex() const;
		inline bool				IsSelectableMode() const;
		TzvItem					GetItem(unsigned int index) const;
		bool					HasValue() const;

		// Setter
		void					AddItem(const std::vector<std::string>& vItems);
		void					AddItem(const char* fmt, ...);
		inline void				SetLabel(const std::string& label);
		inline void				SetOptions(const TzvTableHeaderInfo& options);
		inline void				SetItem(const std::initializer_list<std::string>& item_labels);
		void					SetSelectable(bool enabled, const TzvSelectableInfo& info = TzvSelectableInfo());

		// Others
		void					Bind();
		void					ItemBind(int index);

		// Operator
		TzvItem					operator[](int index);
		TzvItem					operator[](int index) const;
	};

} // namespace ZVLab

#endif /*__ZV_TABLE_HEADER_H__*/
