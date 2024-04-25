#include "ZVButton.h"

namespace ZVLab {
	CZVButton::CZVButton(const std::string& label, float width, float height)
		: m_strButtonLabel(label)
		, m_fWidth(width), m_fHeight(height)
		, m_fPosX(-999.f), m_fPosY(-999.f)
		, m_bSetupPos(false)
		, m_fpCallbackFn(nullptr)
	{/*Empty*/}

	CZVButton::CZVButton(const std::string & label, float width, float height, float posX, float posY)
		: m_strButtonLabel(label)
		, m_fWidth(width), m_fHeight(height)
		, m_fPosX(posX), m_fPosY(posY)
		, m_bSetupPos(true)
		, m_fpCallbackFn(nullptr)
	{/*Empty*/}

	bool CZVButton::Bind()
	{
		bool result = false;
		if (m_bSetupPos)
		{
			ImGui::SetCursorPos({ m_fPosX, m_fPosY });
		}
		result = ImGui::Button(m_strButtonLabel.c_str(), { m_fWidth, m_fHeight });
		if (result && m_fpCallbackFn != nullptr)
		{  // 이벤트 콜백 등록시 호출 되는 함수
			m_fpCallbackFn();
		}
		return (result);
	}

} // namespace ZVLab
