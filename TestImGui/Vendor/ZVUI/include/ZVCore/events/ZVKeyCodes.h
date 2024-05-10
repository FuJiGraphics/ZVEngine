#pragma once

#ifdef ZV_PLATFORM_WINDOWS

namespace ZVLab { 

// From glfw3.h
	enum EzvKeyCodes {
		ezvKeyCodes_SPACE             = (unsigned int)32,
		ezvKeyCodes_APOSTROPHE        = (unsigned int)39,  /* ' */
		ezvKeyCodes_COMMA             = (unsigned int)44,  /* , */
		ezvKeyCodes_MINUS             = (unsigned int)45,  /* - */
		ezvKeyCodes_PERIOD            = (unsigned int)46,  /* . */
		ezvKeyCodes_SLASH             = (unsigned int)47,  /* / */
		ezvKeyCodes_0                 = (unsigned int)48,
		ezvKeyCodes_1                 = (unsigned int)49,
		ezvKeyCodes_2                 = (unsigned int)50,
		ezvKeyCodes_3                 = (unsigned int)51,
		ezvKeyCodes_4                 = (unsigned int)52,
		ezvKeyCodes_5                 = (unsigned int)53,
		ezvKeyCodes_6                 = (unsigned int)54,
		ezvKeyCodes_7                 = (unsigned int)55,
		ezvKeyCodes_8                 = (unsigned int)56,
		ezvKeyCodes_9                 = (unsigned int)57,
		ezvKeyCodes_SEMICOLON         = (unsigned int)59,  /* ; */
		ezvKeyCodes_EQUAL             = (unsigned int)61,  /* = */
		ezvKeyCodes_A                 = (unsigned int)65,
		ezvKeyCodes_B                 = (unsigned int)66,
		ezvKeyCodes_C                 = (unsigned int)67,
		ezvKeyCodes_D                 = (unsigned int)68,
		ezvKeyCodes_E                 = (unsigned int)69,
		ezvKeyCodes_F                 = (unsigned int)70,
		ezvKeyCodes_G                 = (unsigned int)71,
		ezvKeyCodes_H                 = (unsigned int)72,
		ezvKeyCodes_I                 = (unsigned int)73,
		ezvKeyCodes_J                 = (unsigned int)74,
		ezvKeyCodes_K                 = (unsigned int)75,
		ezvKeyCodes_L                 = (unsigned int)76,
		ezvKeyCodes_M                 = (unsigned int)77,
		ezvKeyCodes_N                 = (unsigned int)78,
		ezvKeyCodes_O                 = (unsigned int)79,
		ezvKeyCodes_P                 = (unsigned int)80,
		ezvKeyCodes_Q                 = (unsigned int)81,
		ezvKeyCodes_R                 = (unsigned int)82,
		ezvKeyCodes_S                 = (unsigned int)83,
		ezvKeyCodes_T                 = (unsigned int)84,
		ezvKeyCodes_U                 = (unsigned int)85,
		ezvKeyCodes_V                 = (unsigned int)86,
		ezvKeyCodes_W                 = (unsigned int)87,
		ezvKeyCodes_X                 = (unsigned int)88,
		ezvKeyCodes_Y                 = (unsigned int)89,
		ezvKeyCodes_Z                 = (unsigned int)90,
		ezvKeyCodes_LEFT_BRACKET      = (unsigned int)91,  /* [ */
		ezvKeyCodes_BACKSLASH         = (unsigned int)92,  /* \ */
		ezvKeyCodes_RIGHT_BRACKET     = (unsigned int)93,  /* ] */
		ezvKeyCodes_GRAVE_ACCENT      = (unsigned int)96,  /* ` */
		ezvKeyCodes_WORLD_1           = (unsigned int)161, /* non-US #1 */
		ezvKeyCodes_WORLD_2           = (unsigned int)162, /* non-US #2 */

	/* Function keys */
		ezvKeyCodes_ESCAPE            = (unsigned int)256,
		ezvKeyCodes_ENTER             = (unsigned int)257,
		ezvKeyCodes_TAB               = (unsigned int)258,
		ezvKeyCodes_BACKSPACE         = (unsigned int)259,
		ezvKeyCodes_INSERT            = (unsigned int)260,
		ezvKeyCodes_DELETE            = (unsigned int)261,
		ezvKeyCodes_RIGHT             = (unsigned int)262,
		ezvKeyCodes_LEFT              = (unsigned int)263,
		ezvKeyCodes_DOWN              = (unsigned int)264,
		ezvKeyCodes_UP                = (unsigned int)265,
		ezvKeyCodes_PAGE_UP           = (unsigned int)266,
		ezvKeyCodes_PAGE_DOWN         = (unsigned int)267,
		ezvKeyCodes_HOME              = (unsigned int)268,
		ezvKeyCodes_END               = (unsigned int)269,
		ezvKeyCodes_CAPS_LOCK         = (unsigned int)280,
		ezvKeyCodes_SCROLL_LOCK       = (unsigned int)281,
		ezvKeyCodes_NUM_LOCK          = (unsigned int)282,
		ezvKeyCodes_PRINT_SCREEN      = (unsigned int)283,
		ezvKeyCodes_PAUSE             = (unsigned int)284,
		ezvKeyCodes_F1                = (unsigned int)290,
		ezvKeyCodes_F2                = (unsigned int)291,
		ezvKeyCodes_F3                = (unsigned int)292,
		ezvKeyCodes_F4                = (unsigned int)293,
		ezvKeyCodes_F5                = (unsigned int)294,
		ezvKeyCodes_F6                = (unsigned int)295,
		ezvKeyCodes_F7                = (unsigned int)296,
		ezvKeyCodes_F8                = (unsigned int)297,
		ezvKeyCodes_F9                = (unsigned int)298,
		ezvKeyCodes_F10               = (unsigned int)299,
		ezvKeyCodes_F11               = (unsigned int)300,
		ezvKeyCodes_F12               = (unsigned int)301,
		ezvKeyCodes_F13               = (unsigned int)302,
		ezvKeyCodes_F14               = (unsigned int)303,
		ezvKeyCodes_F15               = (unsigned int)304,
		ezvKeyCodes_F16               = (unsigned int)305,
		ezvKeyCodes_F17               = (unsigned int)306,
		ezvKeyCodes_F18               = (unsigned int)307,
		ezvKeyCodes_F19               = (unsigned int)308,
		ezvKeyCodes_F20               = (unsigned int)309,
		ezvKeyCodes_F21               = (unsigned int)310,
		ezvKeyCodes_F22               = (unsigned int)311,
		ezvKeyCodes_F23               = (unsigned int)312,
		ezvKeyCodes_F24               = (unsigned int)313,
		ezvKeyCodes_F25               = (unsigned int)314,
		ezvKeyCodes_KP_0              = (unsigned int)320,
		ezvKeyCodes_KP_1              = (unsigned int)321,
		ezvKeyCodes_KP_2              = (unsigned int)322,
		ezvKeyCodes_KP_3              = (unsigned int)323,
		ezvKeyCodes_KP_4              = (unsigned int)324,
		ezvKeyCodes_KP_5              = (unsigned int)325,
		ezvKeyCodes_KP_6              = (unsigned int)326,
		ezvKeyCodes_KP_7              = (unsigned int)327,
		ezvKeyCodes_KP_8              = (unsigned int)328,
		ezvKeyCodes_KP_9              = (unsigned int)329,
		ezvKeyCodes_KP_DECIMAL        = (unsigned int)330,
		ezvKeyCodes_KP_DIVIDE         = (unsigned int)331,
		ezvKeyCodes_KP_MULTIPLY       = (unsigned int)332,
		ezvKeyCodes_KP_SUBTRACT       = (unsigned int)333,
		ezvKeyCodes_KP_ADD            = (unsigned int)334,
		ezvKeyCodes_KP_ENTER          = (unsigned int)335,
		ezvKeyCodes_KP_EQUAL          = (unsigned int)336,
		ezvKeyCodes_LEFT_SHIFT        = (unsigned int)340,
		ezvKeyCodes_LEFT_CONTROL      = (unsigned int)341,
		ezvKeyCodes_LEFT_ALT          = (unsigned int)342,
		ezvKeyCodes_LEFT_SUPER        = (unsigned int)343,
		ezvKeyCodes_RIGHT_SHIFT       = (unsigned int)344,
		ezvKeyCodes_RIGHT_CONTROL     = (unsigned int)345,
		ezvKeyCodes_RIGHT_ALT         = (unsigned int)346,
		ezvKeyCodes_RIGHT_SUPER       = (unsigned int)347,
		ezvKeyCodes_MENU              = (unsigned int)348,
	}; // enum EzvKeyCodes
} // namespace ZVLab

#endif /*ZV_PLATFORM_WINDOWS*/
