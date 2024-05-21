#include "ZVComboBox.h"

namespace { /// statics
	static bool							s_bFirstEntryScope = true;
	static ZVLab::CzvComboBox*			s_pCurrComboBox = nullptr;
	static unsigned int					s_unComboBoxCount = 0;
#define	DRegistRuntimeComboBox(ptr)		(s_pCurrComboBox = ptr);
#define	DUnRegistRuntimeComboBox()		(s_pCurrComboBox = nullptr);
#define	DIsCurrentRegistComboBox(ptr)	(s_pCurrComboBox == ptr)
}


namespace ZVLab {
	
	CzvComboBox::CzvComboBox(const std::string& label, const TzvComboBoxInfo& info)
		: m_strLabel(label)
		, m_tOptions(info)
	{
	}

	CzvComboBox::~CzvComboBox()
	{

	}

	bool CzvComboBox::Synchronization()
	{
		bool result = false;
		if (!DIsCurrentRegistComboBox(this) || s_bFirstEntryScope)
		{
			if (s_bFirstEntryScope)
				s_bFirstEntryScope = false;
			else
			{
				ImGui::End();
				DUnRegistRuntimeComboBox();
			}

			// 현재 Dialog 정보 등록
			DRegistRuntimeComboBox(this);
			result = ImGui::Begin(m_strLabel.c_str(), NULL, m_tOptions.GetOptions());
		}
		return (result);
	}

} // namespace ZVLab
