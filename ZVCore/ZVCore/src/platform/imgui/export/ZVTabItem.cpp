#include "ZVTabItem.h"

namespace ZVLab {

	namespace { /// static variable
		static bool						s_bFirstEntryScope = true;
		static ZVLab::TzvTabItemChunk	s_CurrTabItemData;
		static unsigned int				s_nuiItemCount = 0;
	}
	// Constructors, Destructors
	CzvTabItem::CzvTabItem(const std::string& label, const TzvTabItemInfo& options)
		: m_tData{ label, options, false }
		, m_fpCallbackFn(nullptr)
	{
		FZLOG_INFO("START ITEM = {0}", label);
		DZVLog_Failed(label.size(), "FAILED: Label length must be than or equal to 0.");
		s_nuiItemCount++;
		DZVLog_Failed((s_nuiItemCount > 0),
					  "FAILED: Unexpected Error! Tab Item Count is not greater than 0 \"s_nuiDialogCount = {0}\"",
					  s_nuiItemCount);
	}

	CzvTabItem::~CzvTabItem()
	{
		FZLOG_INFO("END ITEM = {0}", m_tData.Label);
		if (s_CurrTabItemData.Label == m_tData.Label && m_tData.IsUnFolded )
		{
			// Release a tab bar
			s_bFirstEntryScope = true;
			ImGui::EndTabItem();
			s_CurrTabItemData.Label.clear();
		}
		s_nuiItemCount--;
		DZVLog_Failed((s_nuiItemCount >= 0),
					  "FAILED: Unexpected Error! Tab Item Count is less than 0 \"s_nuiButtonCount = {0}\"",
					  s_nuiItemCount);
	}

	// Others
	bool CzvTabItem::Bind()
	{
		bool result = false;
		result = this->Synchronization();

		if (result && m_fpCallbackFn != nullptr)
		{  // 이벤트 콜백 등록시 호출 되는 함수
			m_fpCallbackFn();
		}
		return (result);
	}


	bool CzvTabItem::Synchronization()
	{
		if (s_CurrTabItemData.Label != m_tData.Label || s_bFirstEntryScope)
		{
			if (s_bFirstEntryScope)
				s_bFirstEntryScope = false;
			else if (s_CurrTabItemData.IsUnFolded)
				ImGui::EndTabItem();

			m_tData.IsUnFolded = ImGui::BeginTabItem(m_tData.Label.c_str(), NULL, m_tData.tOptions.GetOptions());
			s_CurrTabItemData.Label = m_tData.Label;
			s_CurrTabItemData.IsUnFolded = m_tData.IsUnFolded;
		}
		return (m_tData.IsUnFolded);
	}

} // namespace ZVLab