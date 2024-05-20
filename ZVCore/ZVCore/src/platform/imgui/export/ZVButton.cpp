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

	bool CzvButton::Bind(const CzvHotKey& keyMap, CzvDialog& targetFocusDialog)
	{
		bool result = false;
		// Set Position
		if (m_optPosition.has_value())
			ImGui::SetCursorPos(m_optPosition.value());

		if (m_optSize.has_value()) // Bind size
			result = ImGui::Button(m_strButtonLabel.c_str(), m_optSize.value());
		else // UnBind size
			result = ImGui::Button(m_strButtonLabel.c_str());

		if (result == false)
		{
			if (targetFocusDialog.IsWindowFocused())
			{
				result = keyMap.IsPressed();
			}
		}

		if (result && m_fpCallbackFn != nullptr)
		{  // 이벤트 콜백 등록시 호출 되는 함수
			m_fpCallbackFn();
		}
		return (result);
	}

} // namespace ZVLab
