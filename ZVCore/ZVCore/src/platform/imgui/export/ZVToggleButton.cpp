#include "ZVToggleButton.h"

//// static variables
namespace {
	static std::map<std::string, bool>	s_mToggleStatusMap;
	static bool sRegistToggleStatus(const std::string& key)
	{
		bool result = false;
		auto& f = s_mToggleStatusMap.find(key);
		if (f == s_mToggleStatusMap.end())
		{
			s_mToggleStatusMap.insert({ key, false });
			result = true;
		}
		return (result);
	}
	static bool& sGetToggleStatus(const std::string& key)
	{
		auto& f = s_mToggleStatusMap.find(key);
		if (f == s_mToggleStatusMap.end())
			::sRegistToggleStatus(key);
		return (s_mToggleStatusMap[key]);
	}
	static bool sReleaseToggleStatus(const std::string& key)
	{
		bool result = false;
		auto& f = s_mToggleStatusMap.find(key);
		if (f != s_mToggleStatusMap.end())
		{
			s_mToggleStatusMap.erase(key);
			result = true;
		}
		return (result);
	}
}

namespace ZVLab {
	CzvToggleButton::CzvToggleButton()
		: CzvButton(DBindLabelNumbering("ToggleButton", CzvButton::GetButtonCount()))
	{
		::sRegistToggleStatus(m_strButtonLabel);
	}

	CzvToggleButton::CzvToggleButton(const std::string& label)
		: CzvButton(label)
	{
		::sRegistToggleStatus(label);
	}

	CzvToggleButton::CzvToggleButton(const std::string& label, const ImVec2& size)
		: CzvButton(label, size)
	{
		::sRegistToggleStatus(label);
	}

	CzvToggleButton::CzvToggleButton(const std::string& label, const ImVec2& size, const ImVec2& position)
		: CzvButton(label, size, position)
	{
		::sRegistToggleStatus(label);
	}

	bool CzvToggleButton::GetStatus() const
	{
		return (::sGetToggleStatus(m_strButtonLabel));
	}

	void CzvToggleButton::Release()
	{
		::sGetToggleStatus(m_strButtonLabel);
	}

	bool CzvToggleButton::Bind()
	{
		bool& bRefActivated = sGetToggleStatus(m_strButtonLabel);

		// Set Position
		ImVec2 prevCursorPos = ImGui::GetCursorPos();
		if (m_optPosition.has_value())
		{
			ImGui::SetCursorPos(m_optPosition.value());
		}
		ImVec2 p = ImGui::GetCursorScreenPos();
		ImDrawList* draw_list = ImGui::GetWindowDrawList();

		float height = ImGui::GetFrameHeight() * ((m_optSize.has_value()) ? m_optSize->y : 1.0f);
		float width = height * 1.55f * ((m_optSize.has_value()) ? m_optSize->x : 1.0f);
		float radius = height * 0.50f;

		if (ImGui::InvisibleButton(m_strButtonLabel.c_str(), ImVec2(width, height)))
			bRefActivated = (bRefActivated) ? false : true;

		ImU32 col_bg;
		if (ImGui::IsItemHovered())
			col_bg = (bRefActivated) ? IM_COL32(145 + 20, 211, 68 + 20, 255) : IM_COL32(218 - 20, 218 - 20, 218 - 20, 255);
		else
			col_bg = (bRefActivated) ? IM_COL32(145, 211, 68, 255) : IM_COL32(218, 218, 218, 255);

		draw_list->AddRectFilled(p, ImVec2(p.x + width, p.y + height), col_bg, height * 0.5f);
		draw_list->AddCircleFilled(ImVec2((bRefActivated) ? (p.x + width - radius) : (p.x + radius), p.y + radius), radius - 1.5f, IM_COL32(255, 255, 255, 255));

		// Called Callback Function
		if (bRefActivated && m_fpCallbackFn != nullptr)
		{
			m_fpCallbackFn();
		}

		// Rollback Position
		if (m_optPosition.has_value())
		{
			ImGui::SetCursorPos(prevCursorPos);
			prevCursorPos = ImGui::GetCursorPos();
		}
		return (bRefActivated);
	}

}
