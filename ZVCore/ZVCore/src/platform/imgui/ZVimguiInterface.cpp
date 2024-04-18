#include "ZVimguiInterface.h"

namespace ZVLab {

	bool CZVimguiInterface::BeginMenu(const char* label)
	{
		ZVLOG_FAILED(label, "FAILED: const char* label is nullptr!");
		return (ImGui::BeginMenu(label));
	}
	bool CZVimguiInterface::MenuItem(const char* label, const char* shortcut, bool selected, bool enabled)
	{
		ZVLOG_FAILED(label, "FAILED: const char* label is nullptr!");
		return (ImGui::MenuItem(label, shortcut, selected, enabled));
	}
	void CZVimguiInterface::EndMenu()
	{
		ImGui::EndMenu();
	}

	bool CZVimguiInterface::Begin(const char* label)
	{
		ZVLOG_FAILED(label, "FAILED: const char* label is nullptr!");
		return (ImGui::Begin(label));
	}

	bool CZVimguiInterface::Button(const char* label, float w, float h)
	{
		ZVLOG_FAILED(label, "FAILED: const char* label is nullptr!");
		return (ImGui::Button(label, { w, h }));
	}

	bool CZVimguiInterface::Button(const char* label, float w, float h, float x, float y)
	{
		ZVLOG_FAILED(label, "FAILED: const char* label is nullptr!");
		ImGui::SetCursorPos({ x, y });
		return (CZVimguiInterface::Button(label, w, h));
	}

	void CZVimguiInterface::End()
	{
		ImGui::End();
	}

} // namespace ZVLab
