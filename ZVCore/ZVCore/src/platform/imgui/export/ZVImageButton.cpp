#include "ZVImageButton.h"

namespace ZVLab {
	CZVImageButton::CZVImageButton(const std::string& label)
		: CZVButton(label, 0, 0)
		, m_TexIdle(nullptr)
		, m_TexClick(nullptr)
		, m_Weight(1.0f, 1.0f)
		, m_IsSetRect(false)
		, m_IsClicked(false)
	{/*Empty*/}

	CZVImageButton::CZVImageButton(float posX, float posY, const std::string& label)
		: CZVButton(label, 0, 0, posX, posY)
		, m_TexIdle(nullptr)
		, m_TexClick(nullptr)
		, m_Weight(1.0f, 1.0f)
		, m_IsSetRect(false)
		, m_IsClicked(false)
	{/*Empty*/}

	void CZVImageButton::SetTexture(const Shared<CZVTexture>& idle, 
									const Shared<CZVTexture>& click)
	{
		ZVLOG_FAILED(idle, "FAILED: idle texture is null!!");
		ZVLOG_FAILED(click, "FAILED: click texture is null!!");
		m_TexIdle = idle;
		m_TexClick = click;
	}

	void CZVImageButton::SetTexture(const std::string& idle_path, 
									const std::string& click_path)
	{
		m_TexIdle = CZVTexture::Create(idle_path);
		if (click_path.size() > 0)
			m_TexClick = CZVTexture::Create(click_path);
	}

	bool CZVImageButton::IsHovered(const ImVec2& pos)
	{
		unsigned char result = 0x01;
		if (m_IsSetRect)
		{
			result &= (pos.x >= m_RectMin.x) ? 0x01 : 0x00;
			result &= (pos.x <= m_RectMax.x) ? 0x01 : 0x00;
			result &= (pos.y >= m_RectMin.y) ? 0x01 : 0x00;
			result &= (pos.y <= m_RectMax.y) ? 0x01 : 0x00;
		}
		return (static_cast<bool>(result));
	}

	bool CZVImageButton::Bind()
	{
		if (m_TexIdle == nullptr)
		{
			ZVLOG_FAILED(false, "FAILED: ImageButton is empty!!");
			return (false);
		}

		bool result = false;
		
		// 클릭 시 m_TexClick ID 설정
		auto& tex = (m_IsClicked) ? m_TexClick : m_TexIdle;
		auto targetID = (void*)(intptr_t)tex->GetID();
		float width = static_cast<float>(tex->GetWidth()) * m_Weight.x;
		float height = static_cast<float>(tex->GetHeight()) * m_Weight.y;
		float posX = this->GetPosX();
		float posY = this->GetPosY();

		if (this->IsSetupPos()) // 위치 설정 시
			ImGui::Image(targetID, { width, height }, { posX, posY });
		else
			ImGui::Image(targetID, { width, height }); 

		m_IsSetRect = true;
		m_RectMin = ImGui::GetItemRectMin();
		m_RectMax = ImGui::GetItemRectMax();

		if (this->IsHovered(ImGui::GetMousePos()) == true)
		{
			// 마우스 누르는 상태
			if (ImGui::IsMouseClicked(0)) // 0은 왼쪽 버튼 의미 TODO: 매크로 생성 필요
			{
				m_IsClicked = true;
				result = true;
			}
		}

		if (ImGui::IsMouseReleased(0) == true)
		{
			m_IsClicked = false;
		}

		return (result);
	}

} // namespace ZVLab
