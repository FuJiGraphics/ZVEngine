#include "ZVimguiInterface.h"

namespace ZVLab {

	bool CZVimguiInterface::Begin(const std::string& name)
	{
		return (ImGui::Begin(name.c_str()));
	}

	bool CZVimguiInterface::Button(const char* str, float w, float h)
	{
		return (ImGui::Button(str, { w, h }));
	}

	bool CZVimguiInterface::Button(const char * str, float w, float h, float x, float y)
	{
		ImGui::SetCursorPos({ x, y });
		return (CZVimguiInterface::Button(str, w, h));
	}

	void CZVimguiInterface::End()
	{
		ImGui::End();
	}

} // namespace ZVLab
