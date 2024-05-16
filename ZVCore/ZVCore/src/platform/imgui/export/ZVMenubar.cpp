#include "ZVMenubar.h"

namespace { /// statics
	static bool							s_bFirstEntryScope = true;
	static ZVLab::CzvMenuBar*			s_pCurrActivateMenubar = nullptr;
#define DRegistMenuBar(ptr)				(s_pCurrActivateMenubar = ptr);
#define	DUnRegistMenuBar				(s_pCurrActivateMenubar = nullptr);
#define	DIsCurrentRegistMenuBar(ptr)	(s_pCurrActivateMenubar == ptr)
}

namespace ZVLab {

	CzvMenuBar::CzvMenuBar(const std::string& label)
		: m_strLabel(label)
		, m_bIsActivated(false)
	{/*Empty*/}

	CzvMenuBar::~CzvMenuBar()
	{
		this->Release();
	}

	bool CzvMenuBar::Bind()
	{
		return (this->Synchronization());
	}

	void CzvMenuBar::UnBind()
	{
		this->Release();
	}

	bool ZVLab::CzvMenuBar::Synchronization()
	{
		if (!DIsCurrentRegistMenuBar(this) || s_bFirstEntryScope)
		{
			if (s_bFirstEntryScope)
				s_bFirstEntryScope = false;
			else
			{
				if (s_pCurrActivateMenubar->IsActivated())
				{
					ImGui::EndMenuBar();
					DUnRegistMenuBar;
				}
			}
			// 현재 MenuBar 정보 등록
			DRegistMenuBar(this);
			m_bIsActivated = ImGui::BeginMenuBar();
		}
		return (m_bIsActivated);
	}

	void CzvMenuBar::Release()
	{
		if (DIsCurrentRegistMenuBar(this))
		{
			s_bFirstEntryScope = true;
			// Release a MenuBar
			if (m_bIsActivated)
			{
				ImGui::EndMenuBar();
			}
			DUnRegistMenuBar;
		}
	}
} // namespace ZVLab
