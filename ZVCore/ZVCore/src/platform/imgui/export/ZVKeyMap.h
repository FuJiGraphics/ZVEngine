
#ifndef __ZV_KEYMAP_H__
#define __ZV_KEYMAP_H__
#pragma once

#include "../../../core/Core.h"
#include "../../../events/ZVKeyCodes.h"
#include <list>

namespace ZVLab {

	class ZV_API CzvKeyMap
	{
	//// Member Variables
	private:
		EzvKeyCodes				m_eKeyType;
		std::list<EzvKeyCodes>	m_CommandList;

	//// Member Functions
	public:
		// Constructor, Destructor
		CzvKeyMap(EzvKeyCodes keycodes = ezvKeyCodes_NONE);
		~CzvKeyMap() = default;

		// Getter
		std::string		GetKeyString() const;

		// Inline functions
		inline const EzvKeyCodes				GetKeyType() const		{ return (m_eKeyType); }
		inline std::list<EzvKeyCodes>&			GetCommandList()		{ return (m_CommandList); }
		inline const std::list<EzvKeyCodes>&	GetCommandList() const	{ return (m_CommandList); }

		// Operators
		CzvKeyMap&		operator= (const CzvKeyMap& keymap);
		CzvKeyMap		operator+ (const CzvKeyMap& keymap) const;
		CzvKeyMap		operator+ (const CzvKeyMap& keymap);
		std::ostream&	operator<<(std::ostream& os);
	};

	struct KeyMaps
	{
		static const CzvKeyMap
			KEY_NONE, KEY_SPACE, KEY_APOSTROPHE, KEY_COMMA, KEY_MINUS, KEY_PERIOD, KEY_SLASH,
			// Number Pad
			KEY_0, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9,
			KEY_SEMICOLON, KEY_EQUAL,
			// Alphabets
			KEY_A, KEY_B, KEY_C, KEY_D, KEY_E, KEY_F, KEY_G, KEY_H, KEY_I, KEY_J, KEY_K, KEY_L, KEY_M, KEY_N, KEY_O, KEY_P, KEY_Q,
			KEY_R, KEY_S, KEY_T, KEY_U, KEY_V, KEY_W, KEY_X, KEY_Y, KEY_Z, KEY_LEFT_BRACKET, KEY_BACKSLASH, KEY_RIGHT_BRACKET,
			KEY_GRAVE_ACCENT, KEY_WORLD_1, KEY_WORLD_2,
			// Function keys
			KEY_ESCAPE, KEY_ENTER, KEY_TAB, KEY_BACKSPACE, KEY_INSERT, KEY_DELETE, KEY_RIGHT, KEY_LEFT,
			KEY_DOWN, KEY_UP, KEY_PAGE_UP, KEY_PAGE_DOWN, KEY_HOME, KEY_END, KEY_CAPS_LOCK, KEY_SCROLL_LOCK,
			KEY_NUM_LOCK, KEY_PRINT_SCREEN, KEY_PAUSE,
			KEY_F1, KEY_F2, KEY_F3, KEY_F4, KEY_F5, KEY_F6, KEY_F7, KEY_F8, KEY_F9, KEY_F10, KEY_F11, KEY_F12,
			KEY_F13, KEY_F14, KEY_F15, KEY_F16, KEY_F17, KEY_F18, KEY_F19, KEY_F20, KEY_F21, KEY_F22, KEY_F23, KEY_F24,
			KEY_F25, KEY_KP_0, KEY_KP_1, KEY_KP_2, KEY_KP_3, KEY_KP_4, KEY_KP_5, KEY_KP_6, KEY_KP_7, KEY_KP_8, KEY_KP_9,
			KEY_KP_DECIMAL, KEY_KP_DIVIDE, KEY_KP_MULTIPLY, KEY_KP_SUBTRACT, KEY_KP_ADD, KEY_KP_ENTER, KEY_KP_EQUAL,
			KEY_LEFT_SHIFT, KEY_LEFT_CONTROL, KEY_LEFT_ALT, KEY_LEFT_SUPER,
			KEY_RIGHT_SHIFT, KEY_RIGHT_CONTROL, KEY_RIGHT_ALT, KEY_RIGHT_SUPER, KEY_MENU;
	}; // namespace KeyMaps

} // namespace ZVLab

#endif