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
		for(const auto& cmd : m_KeyMap.GetCommandList())
		{
			if (io.KeysDown[cmd] == false)
				return (false);
		}
		return (true);
	}

	std::ostream& CzvHotKey::operator<<(std::ostream& os)
	{
		os << this->GetKeyString();
		return (os);
	}

} // namespace ZVLab