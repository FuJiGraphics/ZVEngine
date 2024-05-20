#include "ZVHotKey.h"

namespace ZVLab {

	CzvHotKey::CzvHotKey()
		: m_KeyMap()
	{/*Empty*/}

	CzvHotKey::CzvHotKey(const CzvKeyMap& keymap)
		: m_KeyMap(keymap)
	{/**/}

	std::string CzvHotKey::GetKeyString() const
	{
		return (m_KeyMap.GetKeyString());
	}

	bool CzvHotKey::IsPressed() const
	{
		auto io = ImGui::GetIO();
		if (ImGui::IsWindowFocused())
		{

		}

		return false;
	}

	std::ostream& CzvHotKey::operator<<(std::ostream& os)
	{
		os << this->GetKeyString();
		return (os);
	}

} // namespace ZVLab