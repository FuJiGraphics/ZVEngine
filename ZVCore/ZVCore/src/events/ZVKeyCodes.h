#pragma once

#ifdef ZV_PLATFORM_WINDOWS

// From glfw3.h
#define ZV_KEY_SPACE              (unsigned int)32
#define ZV_KEY_APOSTROPHE         (unsigned int)39  /* ' */
#define ZV_KEY_COMMA              (unsigned int)44  /* , */
#define ZV_KEY_MINUS              (unsigned int)45  /* - */
#define ZV_KEY_PERIOD             (unsigned int)46  /* . */
#define ZV_KEY_SLASH              (unsigned int)47  /* / */
#define ZV_KEY_0                  (unsigned int)48
#define ZV_KEY_1                  (unsigned int)49
#define ZV_KEY_2                  (unsigned int)50
#define ZV_KEY_3                  (unsigned int)51
#define ZV_KEY_4                  (unsigned int)52
#define ZV_KEY_5                  (unsigned int)53
#define ZV_KEY_6                  (unsigned int)54
#define ZV_KEY_7                  (unsigned int)55
#define ZV_KEY_8                  (unsigned int)56
#define ZV_KEY_9                  (unsigned int)57
#define ZV_KEY_SEMICOLON          (unsigned int)59  /* ; */
#define ZV_KEY_EQUAL              (unsigned int)61  /* = */
#define ZV_KEY_A                  (unsigned int)65
#define ZV_KEY_B                  (unsigned int)66
#define ZV_KEY_C                  (unsigned int)67
#define ZV_KEY_D                  (unsigned int)68
#define ZV_KEY_E                  (unsigned int)69
#define ZV_KEY_F                  (unsigned int)70
#define ZV_KEY_G                  (unsigned int)71
#define ZV_KEY_H                  (unsigned int)72
#define ZV_KEY_I                  (unsigned int)73
#define ZV_KEY_J                  (unsigned int)74
#define ZV_KEY_K                  (unsigned int)75
#define ZV_KEY_L                  (unsigned int)76
#define ZV_KEY_M                  (unsigned int)77
#define ZV_KEY_N                  (unsigned int)78
#define ZV_KEY_O                  (unsigned int)79
#define ZV_KEY_P                  (unsigned int)80
#define ZV_KEY_Q                  (unsigned int)81
#define ZV_KEY_R                  (unsigned int)82
#define ZV_KEY_S                  (unsigned int)83
#define ZV_KEY_T                  (unsigned int)84
#define ZV_KEY_U                  (unsigned int)85
#define ZV_KEY_V                  (unsigned int)86
#define ZV_KEY_W                  (unsigned int)87
#define ZV_KEY_X                  (unsigned int)88
#define ZV_KEY_Y                  (unsigned int)89
#define ZV_KEY_Z                  (unsigned int)90
#define ZV_KEY_LEFT_BRACKET       (unsigned int)91  /* [ */
#define ZV_KEY_BACKSLASH          (unsigned int)92  /* \ */
#define ZV_KEY_RIGHT_BRACKET      (unsigned int)93  /* ] */
#define ZV_KEY_GRAVE_ACCENT       (unsigned int)96  /* ` */
#define ZV_KEY_WORLD_1            (unsigned int)161 /* non-US #1 */
#define ZV_KEY_WORLD_2            (unsigned int)162 /* non-US #2 */

	/* Function keys */
#define ZV_KEY_ESCAPE             (unsigned int)256
#define ZV_KEY_ENTER              (unsigned int)257
#define ZV_KEY_TAB                (unsigned int)258
#define ZV_KEY_BACKSPACE          (unsigned int)259
#define ZV_KEY_INSERT             (unsigned int)260
#define ZV_KEY_DELETE             (unsigned int)261
#define ZV_KEY_RIGHT              (unsigned int)262
#define ZV_KEY_LEFT               (unsigned int)263
#define ZV_KEY_DOWN               (unsigned int)264
#define ZV_KEY_UP                 (unsigned int)265
#define ZV_KEY_PAGE_UP            (unsigned int)266
#define ZV_KEY_PAGE_DOWN          (unsigned int)267
#define ZV_KEY_HOME               (unsigned int)268
#define ZV_KEY_END                (unsigned int)269
#define ZV_KEY_CAPS_LOCK          (unsigned int)280
#define ZV_KEY_SCROLL_LOCK        (unsigned int)281
#define ZV_KEY_NUM_LOCK           (unsigned int)282
#define ZV_KEY_PRINT_SCREEN       (unsigned int)283
#define ZV_KEY_PAUSE              (unsigned int)284
#define ZV_KEY_F1                 (unsigned int)290
#define ZV_KEY_F2                 (unsigned int)291
#define ZV_KEY_F3                 (unsigned int)292
#define ZV_KEY_F4                 (unsigned int)293
#define ZV_KEY_F5                 (unsigned int)294
#define ZV_KEY_F6                 (unsigned int)295
#define ZV_KEY_F7                 (unsigned int)296
#define ZV_KEY_F8                 (unsigned int)297
#define ZV_KEY_F9                 (unsigned int)298
#define ZV_KEY_F10                (unsigned int)299
#define ZV_KEY_F11                (unsigned int)300
#define ZV_KEY_F12                (unsigned int)301
#define ZV_KEY_F13                (unsigned int)302
#define ZV_KEY_F14                (unsigned int)303
#define ZV_KEY_F15                (unsigned int)304
#define ZV_KEY_F16                (unsigned int)305
#define ZV_KEY_F17                (unsigned int)306
#define ZV_KEY_F18                (unsigned int)307
#define ZV_KEY_F19                (unsigned int)308
#define ZV_KEY_F20                (unsigned int)309
#define ZV_KEY_F21                (unsigned int)310
#define ZV_KEY_F22                (unsigned int)311
#define ZV_KEY_F23                (unsigned int)312
#define ZV_KEY_F24                (unsigned int)313
#define ZV_KEY_F25                (unsigned int)314
#define ZV_KEY_KP_0               (unsigned int)320
#define ZV_KEY_KP_1               (unsigned int)321
#define ZV_KEY_KP_2               (unsigned int)322
#define ZV_KEY_KP_3               (unsigned int)323
#define ZV_KEY_KP_4               (unsigned int)324
#define ZV_KEY_KP_5               (unsigned int)325
#define ZV_KEY_KP_6               (unsigned int)326
#define ZV_KEY_KP_7               (unsigned int)327
#define ZV_KEY_KP_8               (unsigned int)328
#define ZV_KEY_KP_9               (unsigned int)329
#define ZV_KEY_KP_DECIMAL         (unsigned int)330
#define ZV_KEY_KP_DIVIDE          (unsigned int)331
#define ZV_KEY_KP_MULTIPLY        (unsigned int)332
#define ZV_KEY_KP_SUBTRACT        (unsigned int)333
#define ZV_KEY_KP_ADD             (unsigned int)334
#define ZV_KEY_KP_ENTER           (unsigned int)335
#define ZV_KEY_KP_EQUAL           (unsigned int)336
#define ZV_KEY_LEFT_SHIFT         (unsigned int)340
#define ZV_KEY_LEFT_CONTROL       (unsigned int)341
#define ZV_KEY_LEFT_ALT           (unsigned int)342
#define ZV_KEY_LEFT_SUPER         (unsigned int)343
#define ZV_KEY_RIGHT_SHIFT        (unsigned int)344
#define ZV_KEY_RIGHT_CONTROL      (unsigned int)345
#define ZV_KEY_RIGHT_ALT          (unsigned int)346
#define ZV_KEY_RIGHT_SUPER        (unsigned int)347
#define ZV_KEY_MENU               (unsigned int)348

#endif /*ZV_PLATFORM_WINDOWS*/
