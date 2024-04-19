#include "ZVButton.h"
#include "../ZVimguiInterface.h"

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

	bool CZVButton::IsClicked() const
	{
		bool result = false;
		if (m_bSetupPos)
			result = CZVimguiInterface::Button(m_strButtonLabel.c_str(), m_fWidth, m_fHeight, m_fPosX, m_fPosY);
		else
			result = CZVimguiInterface::Button(m_strButtonLabel.c_str(), m_fWidth, m_fHeight);
		if (result && m_fpCallbackFn != nullptr)
		{  // �̺�Ʈ �ݹ� ��Ͻ� ȣ�� �Ǵ� �Լ�
			m_fpCallbackFn();
		}
		return (false);
	}

} // namespace ZVLab