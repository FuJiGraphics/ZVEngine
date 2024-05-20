#include "ZVHotKey.h"

namespace ZVLab {

	CzvHotKey::CzvHotKey()
		: m_KeyMap()
	{/*Empty*/}

	CzvHotKey::CzvHotKey(const CzvKeyMap& keymap)
		: m_KeyMap(keymap)
	{/**/}

	CzvHotKey::CzvHotKey(const CzvHotKey& src)
	{
		m_KeyMap = src.GetKeyMap();
	}

	CzvKeyMap CzvHotKey::GetKeyMap() const
	{
		return (m_KeyMap);
	}

	std::string CzvHotKey::GetKeyString() const
	{
		return (m_KeyMap.GetKeyString());
	}

	bool CzvHotKey::IsPressed(bool IsRepeatPressedMode) const
	{
		static bool IsKeyDown = false;

		auto io = ImGui::GetIO();
		for(const auto& cmd : m_KeyMap.GetCommandList())
		{
			if (io.KeysDown[cmd] == false)
			{
				IsKeyDown = false;
				return (false);
			}
		}

		if (IsKeyDown == true && !IsRepeatPressedMode)
		{
			return (false);
		}

		IsKeyDown = true;
		return (true);
	}

	std::ostream& CzvHotKey::operator<<(std::ostream& os)
	{
		os << this->GetKeyString();
		return (os);
	}

} // namespace ZVLab