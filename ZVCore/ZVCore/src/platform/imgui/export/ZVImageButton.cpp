#include "ZVImageButton.h"

namespace ZVLab {

// constructors, destructors
	CzvImageButton::CzvImageButton()
		: CzvButton(DBindLabelNumbering("ImageButton", CzvButton::GetButtonCount()))
		, m_spTexIdle(nullptr)
		, m_spTexClick(nullptr)
		, m_optPosition()
		, m_optWeight({ 1.0f, 1.0f })
		, m_optRectMin()
		, m_optRectMax()
		, m_bIsClicked(false)
	{/*Empty*/}

	CzvImageButton::CzvImageButton(const std::string& label)
		: CzvButton(label)
		, m_spTexIdle(nullptr)
		, m_spTexClick(nullptr)
		, m_optPosition()
		, m_optWeight({ 1.0f, 1.0f })
		, m_optRectMin()
		, m_optRectMax()
		, m_bIsClicked(false)
	{/*Empty*/}

	CzvImageButton::CzvImageButton(const std::string& label, const ImVec2& position)
		: CzvButton(label)
		, m_spTexIdle(nullptr)
		, m_spTexClick(nullptr)
		, m_optPosition(position)
		, m_optWeight({ 1.0f, 1.0f })
		, m_optRectMin()
		, m_optRectMax()
		, m_bIsClicked(false)
	{/*Empty*/}

	CzvImageButton::CzvImageButton(const ImVec2& position)
		: CzvButton(DBindLabelNumbering("ImageButton", CzvButton::GetButtonCount()))
		, m_spTexIdle(nullptr)
		, m_spTexClick(nullptr)
		, m_optPosition(position)
		, m_optWeight({ 1.0f, 1.0f })
		, m_optRectMin()
		, m_optRectMax()
		, m_bIsClicked(false)
	{/*Empty*/}

	CzvImageButton::~CzvImageButton()
	{
		m_spTexIdle.reset();
		m_spTexClick.reset();
	}

// Setter
	void CzvImageButton::SetTexture(const Shared<CzvTexture>& idle, 
									const Shared<CzvTexture>& click)
	{
		DZVLog_Failed(idle, "FAILED: idle texture is null!!");
		DZVLog_Failed(click, "FAILED: click texture is null!!");
		m_spTexIdle = idle;
		m_spTexClick = click;
	}

	void CzvImageButton::SetTexture(const std::string& idle_path, 
									const std::string& click_path)
	{
		m_spTexIdle = CzvTexture::Create(idle_path);
		if (click_path.size() > 0)
			m_spTexClick = CzvTexture::Create(click_path);
	}

// others
	bool CzvImageButton::IsHovered(const ImVec2& pos)
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

// overrides
	bool CzvImageButton::Bind()
	{
		if (m_spTexIdle == nullptr)
		{
			DZVLog_Failed(false, "FAILED: ImageButton is empty!!");
			return (false);
		}

		bool result = false;
		
		// 클릭 시 m_TexClick ID 설정
		auto& tex = (m_bIsClicked) ? m_spTexClick : m_spTexIdle;
		auto targetID = (void*)(intptr_t)tex->GetID();
		float width = static_cast<float>(tex->GetWidth()) * m_optWeight->x;
		float height = static_cast<float>(tex->GetHeight()) * m_optWeight->y;

		if (m_optPosition.has_value()) // 위치 설정 시
			ImGui::Image(targetID, { width, height }, { m_optPosition->x, m_optPosition->y });
		else
			ImGui::Image(targetID, { width, height }); 

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

	bool CzvImageButton::Bind(const CzvHotKey& keyMap, CzvDialog& targetFocusDialog)
	{
		if (m_spTexIdle == nullptr)
		{
			DZVLog_Failed(false, "FAILED: ImageButton is empty!!");
			return (false);
		}

		bool result = false;

		// 클릭 시 m_TexClick ID 설정
		auto& tex = (m_bIsClicked) ? m_spTexClick : m_spTexIdle;
		auto targetID = (void*)(intptr_t)tex->GetID();
		float width = static_cast<float>(tex->GetWidth()) * m_optWeight->x;
		float height = static_cast<float>(tex->GetHeight()) * m_optWeight->y;

		if (m_optPosition.has_value()) // 위치 설정 시
			ImGui::Image(targetID, { width, height }, { m_optPosition->x, m_optPosition->y });
		else
			ImGui::Image(targetID, { width, height });

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
				if (targetFocusDialog.IsWindowFocused())
				{
					result = keyMap.IsPressed();
					if (result)
						m_bIsClicked = true;
				}
			}
		}

		if (ImGui::IsMouseReleased(0) == true)
		{
			m_bIsClicked = false;
		}

		return (result);
	}

} // namespace ZVLab
