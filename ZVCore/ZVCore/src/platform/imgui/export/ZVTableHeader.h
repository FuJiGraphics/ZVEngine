#ifndef __ZV_TABLE_HEADER_H__
#define __ZV_TABLE_HEADER_H__
#pragma once

#include "../../../core/Core.h"
#include "ZVGuiConfig.h"
#include "ZVComboBox.h"

namespace ZVLab {

	enum class EzvItemType
	{
		eText, eComboBox,
	};

	struct ZV_API TzvItem
	{
	private:
		std::string		strText;
		CzvComboBox		ComboBox;
		EzvItemType		eType;

	public:
		TzvItem(const std::string& text = " ");
		TzvItem(const CzvComboBox& comboItems);
		~TzvItem();
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
		static int					s_iSelectItem;

	//// Member Functions
	public:
		// Constructor, Destructors
		CzvTableHeader(const std::string& label, const TzvTableHeaderInfo& options = TzvTableHeaderInfo());
		CzvTableHeader(const std::string& label, const TzvSelectableInfo& sel_info);
		~CzvTableHeader();

		// Getter
		inline std::string		GetLabel() const { return (m_strLabel); }
		inline unsigned int		GetSize() const { return (m_vItems.size()); }
		/**
		 * @brief		현재 선택된 인덱스를 반환합니다.
		 * @details		현재 테이블에 선택된 인덱스(int)값을 반환합니다.
		 * - 실패 시, (int)-1를 반환합니다.
		 * @return		int: 현재 선택된 인덱스 값 
		 */
		int						GetSelectIndex() const;
		bool					IsSelectableMode() const;
		TzvItem					GetItem(unsigned int index) const;
		bool					HasValue() const;

		// Setter
		void					AddItem(const CzvComboBox& item);
		void					AddItem(const std::vector<std::string>& vItems);
		void					AddItem(const char* fmt, ...);
		void					SetLabel(const std::string& label);
		void					SetOptions(const TzvTableHeaderInfo& options);
		void					SetItem(const std::vector<CzvComboBox>& vItems);
		void					SetItem(const std::vector<std::string>& vItems);
		void					SetItem(const std::initializer_list<std::string>& item_labels);
		void					SetSelectable(bool enabled, const TzvSelectableInfo& info = TzvSelectableInfo());

		// Others
		void					Bind();
		void					ItemBind(int index);
		void					Clear();

		// Operator
		TzvItem					operator[](int index);
		TzvItem					operator[](int index) const;
	};

} // namespace ZVLab

#endif /*__ZV_TABLE_HEADER_H__*/
