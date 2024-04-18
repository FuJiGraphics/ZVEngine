#include "ZVButton.h"
#include "../ZVimguiInterface.h"

namespace ZVLab {
	CZVButton::CZVButton(const std::string& label, float width, float height)
		: m_strButtonLabel(label)
		, m_fWidth(width), m_fHeight(height)
		, m_fPosX(-999.f), m_fPosY(-999.f)
		, m_bSetupPos(false)
	{/*Empty*/}

	CZVButton::CZVButton(const std::string & label, float width, float height, float posX, float posY)
		: m_strButtonLabel(label)
		, m_fWidth(width), m_fHeight(height)
		, m_fPosX(posX), m_fPosY(posY)
		, m_bSetupPos(true)
	{/*Empty*/}

	bool CZVButton::IsClicked() const
	{
		if (m_bSetupPos)
			return (CZVimguiInterface::Button(m_strButtonLabel.c_str(), m_fWidth, m_fHeight, m_fPosX, m_fPosY));
		else
			return (CZVimguiInterface::Button(m_strButtonLabel.c_str(), m_fWidth, m_fHeight));
	}

} // namespace ZVLab
