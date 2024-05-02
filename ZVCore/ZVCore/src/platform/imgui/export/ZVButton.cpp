#include "ZVButton.h"

namespace ZVLab {

/// static variable
	unsigned int CzvButton::s_nuiButtonCount = 0;

// Constructors, Destructors
	CzvButton::CzvButton(const std::string& label)
		: m_strButtonLabel(label)
		, m_optSize()
		, m_optPosition()
		, m_fpCallbackFn(nullptr)
	{
		s_nuiButtonCount++;
		DZVLog_Failed((s_nuiButtonCount > 0),
					 "FAILED: Unexpected Error! Button Count is not greater than 0 \"s_nuiButtonCount = {0}\"",
					 s_nuiButtonCount);
	}

	CzvButton::CzvButton(const std::string& label, const ImVec2& size)
		: m_strButtonLabel(label)
		, m_optSize(size)
		, m_optPosition()
		, m_fpCallbackFn(nullptr)
	{
		s_nuiButtonCount++;
		DZVLog_Failed((s_nuiButtonCount > 0),
					 "FAILED: Unexpected Error! Button Count is not greater than 0 \"s_nuiButtonCount = {0}\"",
					 s_nuiButtonCount);
	}

	CzvButton::CzvButton(const std::string& label, const ImVec2& size, const ImVec2& position)
		: m_strButtonLabel(label)
		, m_optSize(size)
		, m_optPosition(position)
		, m_fpCallbackFn(nullptr)
	{
		s_nuiButtonCount++;
		DZVLog_Failed((s_nuiButtonCount > 0),
					 "FAILED: Unexpected Error! Button Count is not greater than 0 \"s_nuiButtonCount = {0}\"",
					 s_nuiButtonCount);
	}

	CzvButton::~CzvButton()
	{
		s_nuiButtonCount--;
		DZVLog_Failed((s_nuiButtonCount >= 0), 
					 "FAILED: Unexpected Error! Button Count is less than 0 \"s_nuiButtonCount = {0}\"", 
					 s_nuiButtonCount);
	}

// Others
	bool CzvButton::Bind()
	{
		bool result = false;
		// Set Position
		if (m_optPosition.has_value())
			ImGui::SetCursorPos(m_optPosition.value());

		if (m_optSize.has_value()) // Bind size
			result = ImGui::Button(m_strButtonLabel.c_str(), m_optSize.value());
		else // UnBind size
			result = ImGui::Button(m_strButtonLabel.c_str());

		if (result && m_fpCallbackFn != nullptr)
		{  // 이벤트 콜백 등록시 호출 되는 함수
			m_fpCallbackFn();
		}
		return (result);
	}

	void ToggleButton(const char * str_id, bool * v)
	{
		ImVec2 p = ImGui::GetCursorScreenPos();
		ImDrawList* draw_list = ImGui::GetWindowDrawList();

		float height = ImGui::GetFrameHeight();
		float width = height * 1.55f;
		float radius = height * 0.50f;

		if (ImGui::InvisibleButton(str_id, ImVec2(width, height)))
			*v = !*v;
		ImU32 col_bg;
		if (ImGui::IsItemHovered())
			col_bg = *v ? IM_COL32(145 + 20, 211, 68 + 20, 255) : IM_COL32(218 - 20, 218 - 20, 218 - 20, 255);
		else
			col_bg = *v ? IM_COL32(145, 211, 68, 255) : IM_COL32(218, 218, 218, 255);

		draw_list->AddRectFilled(p, ImVec2(p.x + width, p.y + height), col_bg, height * 0.5f);
		draw_list->AddCircleFilled(ImVec2(*v ? (p.x + width - radius) : (p.x + radius), p.y + radius), radius - 1.5f, IM_COL32(255, 255, 255, 255));
	}

} // namespace ZVLab
