#include "ZVKeyMap.h"

namespace ZVLab {

	CzvKeyMap::CzvKeyMap(EzvKeyCodes keycodes)
		: m_eKeyType(keycodes)
		, m_CommandList()
	{
		if (keycodes != ezvKeyCodes_NONE)
			m_CommandList.push_back(keycodes);
	}

	std::string CzvKeyMap::GetKeyString() const
	{
		if (m_CommandList.empty())
			return ("NONE");

		std::string command;
		for (auto cmd : m_CommandList)
		{
			command += sZVKeyCode2String(cmd);
			command += "+";
		}
		command.erase(command.end() - 1);
		return (command);
	}

	CzvKeyMap& CzvKeyMap::operator=(const CzvKeyMap& keymap)
	{
		m_CommandList = keymap.GetCommandList();
		return (*this);
	}

	CzvKeyMap CzvKeyMap::operator+(const CzvKeyMap& keymap) const
	{
		CzvKeyMap new_keymap;
		auto& new_list = new_keymap.GetCommandList();
		for (auto& cmd : m_CommandList)
			new_list.push_back(cmd);
		for (auto& cmd : keymap.GetCommandList())
			new_list.push_back(cmd);
		return (new_keymap);
	}

	CzvKeyMap CzvKeyMap::operator+(const CzvKeyMap& keymap)
	{
		CzvKeyMap new_keymap;
		auto& new_list = new_keymap.GetCommandList();
		for (auto& cmd : m_CommandList)
			new_list.push_back(cmd);
		for (auto& cmd : keymap.GetCommandList())
			new_list.push_back(cmd);
		return (new_keymap);
	}

	std::ostream& CzvKeyMap::operator<<(std::ostream& os)
	{
		os << this->GetKeyString();
		return (os);
	}

	const CzvKeyMap	KeyMaps::KEY_NONE(ezvKeyCodes_NONE);
	const CzvKeyMap	KeyMaps::KEY_SPACE(ezvKeyCodes_SPACE);
	const CzvKeyMap	KeyMaps::KEY_APOSTROPHE(ezvKeyCodes_APOSTROPHE);
	const CzvKeyMap	KeyMaps::KEY_COMMA(ezvKeyCodes_COMMA);
	const CzvKeyMap	KeyMaps::KEY_MINUS(ezvKeyCodes_MINUS);
	const CzvKeyMap	KeyMaps::KEY_PERIOD(ezvKeyCodes_PERIOD);
	const CzvKeyMap	KeyMaps::KEY_SLASH(ezvKeyCodes_SLASH);
	const CzvKeyMap	KeyMaps::KEY_0(ezvKeyCodes_0);
	const CzvKeyMap	KeyMaps::KEY_1(ezvKeyCodes_1);
	const CzvKeyMap	KeyMaps::KEY_2(ezvKeyCodes_2);
	const CzvKeyMap	KeyMaps::KEY_3(ezvKeyCodes_3);
	const CzvKeyMap	KeyMaps::KEY_4(ezvKeyCodes_4);
	const CzvKeyMap	KeyMaps::KEY_5(ezvKeyCodes_5);
	const CzvKeyMap	KeyMaps::KEY_6(ezvKeyCodes_6);
	const CzvKeyMap	KeyMaps::KEY_7(ezvKeyCodes_7);
	const CzvKeyMap	KeyMaps::KEY_8(ezvKeyCodes_8);
	const CzvKeyMap	KeyMaps::KEY_9(ezvKeyCodes_9);
	const CzvKeyMap	KeyMaps::KEY_SEMICOLON(ezvKeyCodes_SEMICOLON);
	const CzvKeyMap	KeyMaps::KEY_EQUAL(ezvKeyCodes_EQUAL);
	const CzvKeyMap	KeyMaps::KEY_A(ezvKeyCodes_A);
	const CzvKeyMap	KeyMaps::KEY_B(ezvKeyCodes_B);
	const CzvKeyMap	KeyMaps::KEY_C(ezvKeyCodes_C);
	const CzvKeyMap	KeyMaps::KEY_D(ezvKeyCodes_D);
	const CzvKeyMap	KeyMaps::KEY_E(ezvKeyCodes_E);
	const CzvKeyMap	KeyMaps::KEY_F(ezvKeyCodes_F);
	const CzvKeyMap	KeyMaps::KEY_G(ezvKeyCodes_G);
	const CzvKeyMap	KeyMaps::KEY_H(ezvKeyCodes_H);
	const CzvKeyMap	KeyMaps::KEY_I(ezvKeyCodes_I);
	const CzvKeyMap	KeyMaps::KEY_J(ezvKeyCodes_J);
	const CzvKeyMap	KeyMaps::KEY_K(ezvKeyCodes_K);
	const CzvKeyMap	KeyMaps::KEY_L(ezvKeyCodes_L);
	const CzvKeyMap	KeyMaps::KEY_M(ezvKeyCodes_M);
	const CzvKeyMap	KeyMaps::KEY_N(ezvKeyCodes_N);
	const CzvKeyMap	KeyMaps::KEY_O(ezvKeyCodes_O);
	const CzvKeyMap	KeyMaps::KEY_P(ezvKeyCodes_P);
	const CzvKeyMap	KeyMaps::KEY_Q(ezvKeyCodes_Q);
	const CzvKeyMap	KeyMaps::KEY_R(ezvKeyCodes_R);
	const CzvKeyMap	KeyMaps::KEY_S(ezvKeyCodes_S);
	const CzvKeyMap	KeyMaps::KEY_T(ezvKeyCodes_T);
	const CzvKeyMap	KeyMaps::KEY_U(ezvKeyCodes_U);
	const CzvKeyMap	KeyMaps::KEY_V(ezvKeyCodes_V);
	const CzvKeyMap	KeyMaps::KEY_W(ezvKeyCodes_W);
	const CzvKeyMap	KeyMaps::KEY_X(ezvKeyCodes_X);
	const CzvKeyMap	KeyMaps::KEY_Y(ezvKeyCodes_Y);
	const CzvKeyMap	KeyMaps::KEY_Z(ezvKeyCodes_Z);
	const CzvKeyMap	KeyMaps::KEY_LEFT_BRACKET(ezvKeyCodes_LEFT_BRACKET);
	const CzvKeyMap	KeyMaps::KEY_BACKSLASH(ezvKeyCodes_BACKSLASH);
	const CzvKeyMap	KeyMaps::KEY_RIGHT_BRACKET(ezvKeyCodes_RIGHT_BRACKET);
	const CzvKeyMap	KeyMaps::KEY_GRAVE_ACCENT(ezvKeyCodes_GRAVE_ACCENT);
	const CzvKeyMap	KeyMaps::KEY_WORLD_1(ezvKeyCodes_WORLD_1);
	const CzvKeyMap	KeyMaps::KEY_WORLD_2(ezvKeyCodes_WORLD_2);

	/* Function keys */
	const CzvKeyMap	KeyMaps::KEY_ESCAPE(ezvKeyCodes_ESCAPE);
	const CzvKeyMap	KeyMaps::KEY_ENTER(ezvKeyCodes_ENTER);
	const CzvKeyMap	KeyMaps::KEY_TAB(ezvKeyCodes_TAB);
	const CzvKeyMap	KeyMaps::KEY_BACKSPACE(ezvKeyCodes_BACKSPACE);
	const CzvKeyMap	KeyMaps::KEY_INSERT(ezvKeyCodes_INSERT);
	const CzvKeyMap	KeyMaps::KEY_DELETE(ezvKeyCodes_DELETE);
	const CzvKeyMap	KeyMaps::KEY_RIGHT(ezvKeyCodes_RIGHT);
	const CzvKeyMap	KeyMaps::KEY_LEFT(ezvKeyCodes_LEFT);
	const CzvKeyMap	KeyMaps::KEY_DOWN(ezvKeyCodes_DOWN);
	const CzvKeyMap	KeyMaps::KEY_UP(ezvKeyCodes_UP);
	const CzvKeyMap	KeyMaps::KEY_PAGE_UP(ezvKeyCodes_PAGE_UP);
	const CzvKeyMap	KeyMaps::KEY_PAGE_DOWN(ezvKeyCodes_PAGE_DOWN);
	const CzvKeyMap	KeyMaps::KEY_HOME(ezvKeyCodes_HOME);
	const CzvKeyMap	KeyMaps::KEY_END(ezvKeyCodes_END);
	const CzvKeyMap	KeyMaps::KEY_CAPS_LOCK(ezvKeyCodes_CAPS_LOCK);
	const CzvKeyMap	KeyMaps::KEY_SCROLL_LOCK(ezvKeyCodes_SCROLL_LOCK);
	const CzvKeyMap	KeyMaps::KEY_NUM_LOCK(ezvKeyCodes_NUM_LOCK);
	const CzvKeyMap	KeyMaps::KEY_PRINT_SCREEN(ezvKeyCodes_PRINT_SCREEN);
	const CzvKeyMap	KeyMaps::KEY_PAUSE(ezvKeyCodes_PAUSE);
	const CzvKeyMap	KeyMaps::KEY_F1(ezvKeyCodes_F1);
	const CzvKeyMap	KeyMaps::KEY_F2(ezvKeyCodes_F2);
	const CzvKeyMap	KeyMaps::KEY_F3(ezvKeyCodes_F3);
	const CzvKeyMap	KeyMaps::KEY_F4(ezvKeyCodes_F4);
	const CzvKeyMap	KeyMaps::KEY_F5(ezvKeyCodes_F5);
	const CzvKeyMap	KeyMaps::KEY_F6(ezvKeyCodes_F6);
	const CzvKeyMap	KeyMaps::KEY_F7(ezvKeyCodes_F7);
	const CzvKeyMap	KeyMaps::KEY_F8(ezvKeyCodes_F8);
	const CzvKeyMap	KeyMaps::KEY_F9(ezvKeyCodes_F9);
	const CzvKeyMap	KeyMaps::KEY_F10(ezvKeyCodes_F10);
	const CzvKeyMap	KeyMaps::KEY_F11(ezvKeyCodes_F11);
	const CzvKeyMap	KeyMaps::KEY_F12(ezvKeyCodes_F12);
	const CzvKeyMap	KeyMaps::KEY_F13(ezvKeyCodes_F13);
	const CzvKeyMap	KeyMaps::KEY_F14(ezvKeyCodes_F14);
	const CzvKeyMap	KeyMaps::KEY_F15(ezvKeyCodes_F15);
	const CzvKeyMap	KeyMaps::KEY_F16(ezvKeyCodes_F16);
	const CzvKeyMap	KeyMaps::KEY_F17(ezvKeyCodes_F17);
	const CzvKeyMap	KeyMaps::KEY_F18(ezvKeyCodes_F18);
	const CzvKeyMap	KeyMaps::KEY_F19(ezvKeyCodes_F19);
	const CzvKeyMap	KeyMaps::KEY_F20(ezvKeyCodes_F20);
	const CzvKeyMap	KeyMaps::KEY_F21(ezvKeyCodes_F21);
	const CzvKeyMap	KeyMaps::KEY_F22(ezvKeyCodes_F22);
	const CzvKeyMap	KeyMaps::KEY_F23(ezvKeyCodes_F23);
	const CzvKeyMap	KeyMaps::KEY_F24(ezvKeyCodes_F24);
	const CzvKeyMap	KeyMaps::KEY_F25(ezvKeyCodes_F25);
	const CzvKeyMap	KeyMaps::KEY_KP_0(ezvKeyCodes_KP_0);
	const CzvKeyMap	KeyMaps::KEY_KP_1(ezvKeyCodes_KP_1);
	const CzvKeyMap	KeyMaps::KEY_KP_2(ezvKeyCodes_KP_2);
	const CzvKeyMap	KeyMaps::KEY_KP_3(ezvKeyCodes_KP_3);
	const CzvKeyMap	KeyMaps::KEY_KP_4(ezvKeyCodes_KP_4);
	const CzvKeyMap	KeyMaps::KEY_KP_5(ezvKeyCodes_KP_5);
	const CzvKeyMap	KeyMaps::KEY_KP_6(ezvKeyCodes_KP_6);
	const CzvKeyMap	KeyMaps::KEY_KP_7(ezvKeyCodes_KP_7);
	const CzvKeyMap	KeyMaps::KEY_KP_8(ezvKeyCodes_KP_8);
	const CzvKeyMap	KeyMaps::KEY_KP_9(ezvKeyCodes_KP_9);
	const CzvKeyMap	KeyMaps::KEY_KP_DECIMAL(ezvKeyCodes_KP_DECIMAL);
	const CzvKeyMap	KeyMaps::KEY_KP_DIVIDE(ezvKeyCodes_KP_DIVIDE);
	const CzvKeyMap	KeyMaps::KEY_KP_MULTIPLY(ezvKeyCodes_KP_MULTIPLY);
	const CzvKeyMap	KeyMaps::KEY_KP_SUBTRACT(ezvKeyCodes_KP_SUBTRACT);
	const CzvKeyMap	KeyMaps::KEY_KP_ADD(ezvKeyCodes_KP_ADD);
	const CzvKeyMap	KeyMaps::KEY_KP_ENTER(ezvKeyCodes_KP_ENTER);
	const CzvKeyMap	KeyMaps::KEY_KP_EQUAL(ezvKeyCodes_KP_EQUAL);
	const CzvKeyMap	KeyMaps::KEY_LEFT_SHIFT(ezvKeyCodes_LEFT_SHIFT);
	const CzvKeyMap	KeyMaps::KEY_LEFT_CONTROL(ezvKeyCodes_LEFT_CONTROL);
	const CzvKeyMap	KeyMaps::KEY_LEFT_ALT(ezvKeyCodes_LEFT_ALT);
	const CzvKeyMap	KeyMaps::KEY_LEFT_SUPER(ezvKeyCodes_LEFT_SUPER);
	const CzvKeyMap	KeyMaps::KEY_RIGHT_SHIFT(ezvKeyCodes_RIGHT_SHIFT);
	const CzvKeyMap	KeyMaps::KEY_RIGHT_CONTROL(ezvKeyCodes_RIGHT_CONTROL);
	const CzvKeyMap	KeyMaps::KEY_RIGHT_ALT(ezvKeyCodes_RIGHT_ALT);
	const CzvKeyMap	KeyMaps::KEY_RIGHT_SUPER(ezvKeyCodes_RIGHT_SUPER);
	const CzvKeyMap	KeyMaps::KEY_MENU(ezvKeyCodes_MENU);
} // namespace ZVLab