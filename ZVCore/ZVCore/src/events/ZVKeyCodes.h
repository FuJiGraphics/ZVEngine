#pragma once

#ifdef ZV_PLATFORM_WINDOWS
namespace ZVLab { 
// From glfw3.h
	enum EzvKeyCodes {
		ezvKeyCodes_NONE			  = 0					  ,
		ezvKeyCodes_SPACE             = GLFW_KEY_SPACE        ,
		ezvKeyCodes_APOSTROPHE        = GLFW_KEY_APOSTROPHE   ,  /* ' */
		ezvKeyCodes_COMMA             = GLFW_KEY_COMMA        ,  /* , */
		ezvKeyCodes_MINUS             = GLFW_KEY_MINUS        ,  /* - */
		ezvKeyCodes_PERIOD            = GLFW_KEY_PERIOD       ,  /* . */
		ezvKeyCodes_SLASH             = GLFW_KEY_SLASH        ,  /* / */
		ezvKeyCodes_0                 = GLFW_KEY_0            ,
		ezvKeyCodes_1                 = GLFW_KEY_1            ,
		ezvKeyCodes_2                 = GLFW_KEY_2            ,
		ezvKeyCodes_3                 = GLFW_KEY_3            ,
		ezvKeyCodes_4                 = GLFW_KEY_4            ,
		ezvKeyCodes_5                 = GLFW_KEY_5            ,
		ezvKeyCodes_6                 = GLFW_KEY_6            ,
		ezvKeyCodes_7                 = GLFW_KEY_7            ,
		ezvKeyCodes_8                 = GLFW_KEY_8            ,
		ezvKeyCodes_9                 = GLFW_KEY_9            ,
		ezvKeyCodes_SEMICOLON         = GLFW_KEY_SEMICOLON    ,  /* ; */
		ezvKeyCodes_EQUAL             = GLFW_KEY_EQUAL        ,  /* = */
		ezvKeyCodes_A                 = GLFW_KEY_A            ,
		ezvKeyCodes_B                 = GLFW_KEY_B            ,
		ezvKeyCodes_C                 = GLFW_KEY_C            ,
		ezvKeyCodes_D                 = GLFW_KEY_D            ,
		ezvKeyCodes_E                 = GLFW_KEY_E            ,
		ezvKeyCodes_F                 = GLFW_KEY_F            ,
		ezvKeyCodes_G                 = GLFW_KEY_G            ,
		ezvKeyCodes_H                 = GLFW_KEY_H            ,
		ezvKeyCodes_I                 = GLFW_KEY_I            ,
		ezvKeyCodes_J                 = GLFW_KEY_J            ,
		ezvKeyCodes_K                 = GLFW_KEY_K            ,
		ezvKeyCodes_L                 = GLFW_KEY_L            ,
		ezvKeyCodes_M                 = GLFW_KEY_M            ,
		ezvKeyCodes_N                 = GLFW_KEY_N            ,
		ezvKeyCodes_O                 = GLFW_KEY_O            ,
		ezvKeyCodes_P                 = GLFW_KEY_P            ,
		ezvKeyCodes_Q                 = GLFW_KEY_Q            ,
		ezvKeyCodes_R                 = GLFW_KEY_R            ,
		ezvKeyCodes_S                 = GLFW_KEY_S            ,
		ezvKeyCodes_T                 = GLFW_KEY_T            ,
		ezvKeyCodes_U                 = GLFW_KEY_U            ,
		ezvKeyCodes_V                 = GLFW_KEY_V            ,
		ezvKeyCodes_W                 = GLFW_KEY_W            ,
		ezvKeyCodes_X                 = GLFW_KEY_X            ,
		ezvKeyCodes_Y                 = GLFW_KEY_Y            ,
		ezvKeyCodes_Z                 = GLFW_KEY_Z            ,
		ezvKeyCodes_LEFT_BRACKET      = GLFW_KEY_LEFT_BRACKET ,  /* [ */
		ezvKeyCodes_BACKSLASH         = GLFW_KEY_BACKSLASH    ,  /* \ */
		ezvKeyCodes_RIGHT_BRACKET     = GLFW_KEY_RIGHT_BRACKET,  /* ] */
		ezvKeyCodes_GRAVE_ACCENT      = GLFW_KEY_GRAVE_ACCENT ,  /* ` */
		ezvKeyCodes_WORLD_1           = GLFW_KEY_WORLD_1      , /* non-US #1 */
		ezvKeyCodes_WORLD_2           = GLFW_KEY_WORLD_2      , /* non-US #2 */

	/* Function keys */
		ezvKeyCodes_ESCAPE            = GLFW_KEY_ESCAPE       ,
		ezvKeyCodes_ENTER             = GLFW_KEY_ENTER        ,
		ezvKeyCodes_TAB               = GLFW_KEY_TAB          ,
		ezvKeyCodes_BACKSPACE         = GLFW_KEY_BACKSPACE    ,
		ezvKeyCodes_INSERT            = GLFW_KEY_INSERT       ,
		ezvKeyCodes_DELETE            = GLFW_KEY_DELETE       ,
		ezvKeyCodes_RIGHT             = GLFW_KEY_RIGHT        ,
		ezvKeyCodes_LEFT              = GLFW_KEY_LEFT         ,
		ezvKeyCodes_DOWN              = GLFW_KEY_DOWN         ,
		ezvKeyCodes_UP                = GLFW_KEY_UP           ,
		ezvKeyCodes_PAGE_UP           = GLFW_KEY_PAGE_UP      ,
		ezvKeyCodes_PAGE_DOWN         = GLFW_KEY_PAGE_DOWN    ,
		ezvKeyCodes_HOME              = GLFW_KEY_HOME         ,
		ezvKeyCodes_END               = GLFW_KEY_END          ,
		ezvKeyCodes_CAPS_LOCK         = GLFW_KEY_CAPS_LOCK    ,
		ezvKeyCodes_SCROLL_LOCK       = GLFW_KEY_SCROLL_LOCK  ,
		ezvKeyCodes_NUM_LOCK          = GLFW_KEY_NUM_LOCK     ,
		ezvKeyCodes_PRINT_SCREEN      = GLFW_KEY_PRINT_SCREEN ,
		ezvKeyCodes_PAUSE             = GLFW_KEY_PAUSE        ,
		ezvKeyCodes_F1                = GLFW_KEY_F1           ,
		ezvKeyCodes_F2                = GLFW_KEY_F2           ,
		ezvKeyCodes_F3                = GLFW_KEY_F3           ,
		ezvKeyCodes_F4                = GLFW_KEY_F4           ,
		ezvKeyCodes_F5                = GLFW_KEY_F5           ,
		ezvKeyCodes_F6                = GLFW_KEY_F6           ,
		ezvKeyCodes_F7                = GLFW_KEY_F7           ,
		ezvKeyCodes_F8                = GLFW_KEY_F8           ,
		ezvKeyCodes_F9                = GLFW_KEY_F9           ,
		ezvKeyCodes_F10               = GLFW_KEY_F10          ,
		ezvKeyCodes_F11               = GLFW_KEY_F11          ,
		ezvKeyCodes_F12               = GLFW_KEY_F12          ,
		ezvKeyCodes_F13               = GLFW_KEY_F13          ,
		ezvKeyCodes_F14               = GLFW_KEY_F14          ,
		ezvKeyCodes_F15               = GLFW_KEY_F15          ,
		ezvKeyCodes_F16               = GLFW_KEY_F16          ,
		ezvKeyCodes_F17               = GLFW_KEY_F17          ,
		ezvKeyCodes_F18               = GLFW_KEY_F18          ,
		ezvKeyCodes_F19               = GLFW_KEY_F19          ,
		ezvKeyCodes_F20               = GLFW_KEY_F20          ,
		ezvKeyCodes_F21               = GLFW_KEY_F21          ,
		ezvKeyCodes_F22               = GLFW_KEY_F22          ,
		ezvKeyCodes_F23               = GLFW_KEY_F23          ,
		ezvKeyCodes_F24               = GLFW_KEY_F24          ,
		ezvKeyCodes_F25               = GLFW_KEY_F25          ,
		ezvKeyCodes_KP_0              = GLFW_KEY_KP_0         ,
		ezvKeyCodes_KP_1              = GLFW_KEY_KP_1         ,
		ezvKeyCodes_KP_2              = GLFW_KEY_KP_2         ,
		ezvKeyCodes_KP_3              = GLFW_KEY_KP_3         ,
		ezvKeyCodes_KP_4              = GLFW_KEY_KP_4         ,
		ezvKeyCodes_KP_5              = GLFW_KEY_KP_5         ,
		ezvKeyCodes_KP_6              = GLFW_KEY_KP_6         ,
		ezvKeyCodes_KP_7              = GLFW_KEY_KP_7         ,
		ezvKeyCodes_KP_8              = GLFW_KEY_KP_8         ,
		ezvKeyCodes_KP_9              = GLFW_KEY_KP_9         ,
		ezvKeyCodes_KP_DECIMAL        = GLFW_KEY_KP_DECIMAL   ,
		ezvKeyCodes_KP_DIVIDE         = GLFW_KEY_KP_DIVIDE    ,
		ezvKeyCodes_KP_MULTIPLY       = GLFW_KEY_KP_MULTIPLY  ,
		ezvKeyCodes_KP_SUBTRACT       = GLFW_KEY_KP_SUBTRACT  ,
		ezvKeyCodes_KP_ADD            = GLFW_KEY_KP_ADD       ,
		ezvKeyCodes_KP_ENTER          = GLFW_KEY_KP_ENTER     ,
		ezvKeyCodes_KP_EQUAL          = GLFW_KEY_KP_EQUAL     ,
		ezvKeyCodes_LEFT_SHIFT        = GLFW_KEY_LEFT_SHIFT   ,
		ezvKeyCodes_LEFT_CONTROL      = GLFW_KEY_LEFT_CONTROL ,
		ezvKeyCodes_LEFT_ALT          = GLFW_KEY_LEFT_ALT     ,
		ezvKeyCodes_LEFT_SUPER        = GLFW_KEY_LEFT_SUPER   ,
		ezvKeyCodes_RIGHT_SHIFT       = GLFW_KEY_RIGHT_SHIFT  ,
		ezvKeyCodes_RIGHT_CONTROL     = GLFW_KEY_RIGHT_CONTROL,
		ezvKeyCodes_RIGHT_ALT         = GLFW_KEY_RIGHT_ALT    ,
		ezvKeyCodes_RIGHT_SUPER       = GLFW_KEY_RIGHT_SUPER  ,
		ezvKeyCodes_MENU              = GLFW_KEY_MENU         ,
	}; // enum EzvKeyCodes

	static std::string sZVKeyCode2String(const EzvKeyCodes& keycode)
	{
		switch (keycode)
		{
			case	ezvKeyCodes_NONE			: return ("None");
			case	ezvKeyCodes_SPACE			: return ("Space");
			case	ezvKeyCodes_APOSTROPHE		: return ("Apostrophe");
			case	ezvKeyCodes_COMMA			: return ("Comma");
			case	ezvKeyCodes_MINUS			: return ("Minus");
			case	ezvKeyCodes_PERIOD			: return ("Period");
			case	ezvKeyCodes_SLASH			: return ("Slash");
			case	ezvKeyCodes_0				: return ("0");
			case	ezvKeyCodes_1				: return ("1");
			case	ezvKeyCodes_2				: return ("2");
			case	ezvKeyCodes_3				: return ("3");
			case	ezvKeyCodes_4				: return ("4");
			case	ezvKeyCodes_5				: return ("5");
			case	ezvKeyCodes_6				: return ("6");
			case	ezvKeyCodes_7				: return ("7");
			case	ezvKeyCodes_8				: return ("8");
			case	ezvKeyCodes_9				: return ("9");
			case	ezvKeyCodes_SEMICOLON		: return ("Semicolon");
			case	ezvKeyCodes_EQUAL			: return ("Equal");
			case	ezvKeyCodes_A				: return ("A");
			case	ezvKeyCodes_B				: return ("B");
			case	ezvKeyCodes_C				: return ("C");
			case	ezvKeyCodes_D				: return ("D");
			case	ezvKeyCodes_E				: return ("E");
			case	ezvKeyCodes_F				: return ("F");
			case	ezvKeyCodes_G				: return ("G");
			case	ezvKeyCodes_H				: return ("H");
			case	ezvKeyCodes_I				: return ("I");
			case	ezvKeyCodes_J				: return ("J");
			case	ezvKeyCodes_K				: return ("K");
			case	ezvKeyCodes_L				: return ("L");
			case	ezvKeyCodes_M				: return ("M");
			case	ezvKeyCodes_N				: return ("N");
			case	ezvKeyCodes_O				: return ("O");
			case	ezvKeyCodes_P				: return ("P");
			case	ezvKeyCodes_Q				: return ("Q");
			case	ezvKeyCodes_R				: return ("R");
			case	ezvKeyCodes_S				: return ("S");
			case	ezvKeyCodes_T				: return ("T");
			case	ezvKeyCodes_U				: return ("U");
			case	ezvKeyCodes_V				: return ("V");
			case	ezvKeyCodes_W				: return ("W");
			case	ezvKeyCodes_X				: return ("X");
			case	ezvKeyCodes_Y				: return ("Y");
			case	ezvKeyCodes_Z				: return ("Z");
			case	ezvKeyCodes_LEFT_BRACKET	: return ("(L)Bracket");
			case	ezvKeyCodes_BACKSLASH		: return ("Backslash");
			case	ezvKeyCodes_RIGHT_BRACKET	: return ("(R)Bracket");
			case	ezvKeyCodes_GRAVE_ACCENT	: return ("Grave Accent");
			case	ezvKeyCodes_WORLD_1			: return ("World 1");
			case	ezvKeyCodes_WORLD_2			: return ("World 2");
			case	ezvKeyCodes_ESCAPE			: return ("Escape");
			case	ezvKeyCodes_ENTER			: return ("Enter");
			case	ezvKeyCodes_TAB				: return ("Tab");
			case	ezvKeyCodes_BACKSPACE		: return ("Backspace");
			case	ezvKeyCodes_INSERT			: return ("Insert");
			case	ezvKeyCodes_DELETE			: return ("Delete");
			case	ezvKeyCodes_RIGHT			: return ("Right");
			case	ezvKeyCodes_LEFT			: return ("Left");
			case	ezvKeyCodes_DOWN			: return ("Down");
			case	ezvKeyCodes_UP				: return ("Up");
			case	ezvKeyCodes_PAGE_UP			: return ("Page Up");
			case	ezvKeyCodes_PAGE_DOWN		: return ("Page Down");
			case	ezvKeyCodes_HOME			: return ("Home");
			case	ezvKeyCodes_END				: return ("End");
			case	ezvKeyCodes_CAPS_LOCK		: return ("Caps Lock");
			case	ezvKeyCodes_SCROLL_LOCK		: return ("Scroll Lock");
			case	ezvKeyCodes_NUM_LOCK		: return ("Num Lock");
			case	ezvKeyCodes_PRINT_SCREEN	: return ("Print Screen");
			case	ezvKeyCodes_PAUSE			: return ("Pause");
			case	ezvKeyCodes_F1				: return ("F1");
			case	ezvKeyCodes_F2				: return ("F2");
			case	ezvKeyCodes_F3				: return ("F3");
			case	ezvKeyCodes_F4				: return ("F4");
			case	ezvKeyCodes_F5				: return ("F5");
			case	ezvKeyCodes_F6				: return ("F6");
			case	ezvKeyCodes_F7				: return ("F7");
			case	ezvKeyCodes_F8				: return ("F8");
			case	ezvKeyCodes_F9				: return ("F9");
			case	ezvKeyCodes_F10				: return ("F10");
			case	ezvKeyCodes_F11				: return ("F11");
			case	ezvKeyCodes_F12				: return ("F12");
			case	ezvKeyCodes_F13				: return ("F13");
			case	ezvKeyCodes_F14				: return ("F14");
			case	ezvKeyCodes_F15				: return ("F15");
			case	ezvKeyCodes_F16				: return ("F16");
			case	ezvKeyCodes_F17				: return ("F17");
			case	ezvKeyCodes_F18				: return ("F18");
			case	ezvKeyCodes_F19				: return ("F19");
			case	ezvKeyCodes_F20				: return ("F20");
			case	ezvKeyCodes_F21				: return ("F21");
			case	ezvKeyCodes_F22				: return ("F22");
			case	ezvKeyCodes_F23				: return ("F23");
			case	ezvKeyCodes_F24				: return ("F24");
			case	ezvKeyCodes_F25				: return ("F25");
			case	ezvKeyCodes_KP_0			: return ("KP_0");
			case	ezvKeyCodes_KP_1			: return ("KP_1");
			case	ezvKeyCodes_KP_2			: return ("KP_2");
			case	ezvKeyCodes_KP_3			: return ("KP_3");
			case	ezvKeyCodes_KP_4			: return ("KP_4");
			case	ezvKeyCodes_KP_5			: return ("KP_5");
			case	ezvKeyCodes_KP_6			: return ("KP_6");
			case	ezvKeyCodes_KP_7			: return ("KP_7");
			case	ezvKeyCodes_KP_8			: return ("KP_8");
			case	ezvKeyCodes_KP_9			: return ("KP_9");
			case	ezvKeyCodes_KP_DECIMAL		: return ("KP_Decimal");
			case	ezvKeyCodes_KP_DIVIDE		: return ("KP_Divide");
			case	ezvKeyCodes_KP_MULTIPLY		: return ("KP_Multiply");
			case	ezvKeyCodes_KP_SUBTRACT		: return ("KP_Subtract");
			case	ezvKeyCodes_KP_ADD			: return ("KP_Add");
			case	ezvKeyCodes_KP_ENTER		: return ("KP_Enter");
			case	ezvKeyCodes_KP_EQUAL		: return ("KP_Equal");
			case	ezvKeyCodes_LEFT_SHIFT		: return ("Shift");
			case	ezvKeyCodes_LEFT_CONTROL	: return ("Ctrl");
			case	ezvKeyCodes_LEFT_ALT		: return ("Alt");
			case	ezvKeyCodes_LEFT_SUPER		: return ("Super");
			case	ezvKeyCodes_RIGHT_SHIFT		: return ("Shift");
			case	ezvKeyCodes_RIGHT_CONTROL	: return ("Ctrl");
			case	ezvKeyCodes_RIGHT_ALT		: return ("Alt");
			case	ezvKeyCodes_RIGHT_SUPER		: return ("Super");
			case	ezvKeyCodes_MENU			: return ("Menu");
		}
	}

} // namespace ZVLab
#endif /*ZV_PLATFORM_WINDOWS*/
