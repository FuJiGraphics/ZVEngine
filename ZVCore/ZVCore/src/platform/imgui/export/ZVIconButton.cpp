#include "ZVIconButton.h"
#include "ZVFont.h"
#include "ZVHotKey.h"

namespace ZVLab {
	CzvIconButton::CzvIconButton(const std::string& icon, float size)
		: CzvButton(icon)
		, m_optPosition()
		, m_optRectMin()
		, m_optRectMax()
		, m_optWeight(size)
		, m_bIsClicked(false)
	{
	}

	CzvIconButton::~CzvIconButton()
	{
	}

	bool CzvIconButton::IsHovered(const ImVec2& pos)
	{
		unsigned char result = 0x01;
		if (m_optRectMin.has_value() && m_optRectMax.has_value())
		{
			result &= (pos.x >= m_optRectMin->x) ? 0x01 : 0x00;
			result &= (pos.x <= m_optRectMax->x) ? 0x01 : 0x00;
			result &= (pos.y >= m_optRectMin->y) ? 0x01 : 0x00;
			result &= (pos.y <= m_optRectMax->y) ? 0x01 : 0x00;
		}
		return (static_cast<bool>(result));
	}

	bool CzvIconButton::Bind()
	{
		bool result = false;

		float w = *m_optWeight;

		CzvImguiManager::PushID();
		auto& refFont = CzvFont::GetInstance();
		auto icon = refFont.GetIcon(w);
		icon.Begin();
		ImGui::Text(m_strButtonLabel.c_str());
		CzvImguiManager::PopID();

		m_optRectMin = ImGui::GetItemRectMin(); 
		m_optRectMax = ImGui::GetItemRectMax();

		if (this->IsHovered(ImGui::GetMousePos()) == true)
		{
			// 마우스 누르는 상태
			if (ImGui::IsMouseClicked(0)) // 0은 왼쪽 버튼 의미 TODO: 매크로 생성 필요
			{
				m_bIsClicked = true;
				result = true;
				if (m_fpCallbackFn != nullptr)
				{
					m_fpCallbackFn();
				}
			}
		}

		if (ImGui::IsMouseReleased(0) == true)
		{
			m_bIsClicked = false;
		}

		return (result);
	}

	bool CzvIconButton::Bind(const CzvHotKey& keyMap)
	{
		bool result = false;

		float w = *m_optWeight;

		CzvImguiManager::PushID();
		ImGui::Text(m_strButtonLabel.c_str());
		CzvImguiManager::PopID();

		m_optRectMin = ImGui::GetItemRectMin();
		m_optRectMax = ImGui::GetItemRectMax();

		if (this->IsHovered(ImGui::GetMousePos()) == true)
		{
			// 마우스 누르는 상태
			if (ImGui::IsMouseClicked(0)) // 0은 왼쪽 버튼 의미 TODO: 매크로 생성 필요
			{
				m_bIsClicked = true;
				result = true;
				if (m_fpCallbackFn != nullptr)
				{
					m_fpCallbackFn();
				}
			}
			// 마우스 누르는 상태가 아닐 때
			else
			{ // 핫키 입력 체크
				result = keyMap.IsPressed();
				if (result)
					m_bIsClicked = true;
			}
		}

		if (ImGui::IsMouseReleased(0) == true)
		{
			m_bIsClicked = false;
		}

		return (result);
	}

} // namespace ZVLab