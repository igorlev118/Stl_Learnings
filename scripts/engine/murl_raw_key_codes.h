// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_RAW_KEY_CODES_H__
#define __MURL_RAW_KEY_CODES_H__

#include "murl_enum.h"

namespace Murl
{
    /**
     * @addtogroup MurlDeviceEnumerations
     * @{
     */

    /**
     * @brief The raw-key codes enumeration.
     */
    enum RawKeyCode
    {
        /** @brief No key. */
        RAWKEY_NONE             = 0x00,

        /** @brief The key ESCAPE. */
        RAWKEY_ESCAPE           = 0x01,
        /** @brief The key 1. */
        RAWKEY_1                = 0x02,
        /** @brief The key 2. */
        RAWKEY_2                = 0x03,
        /** @brief The key 3. */
        RAWKEY_3                = 0x04,
        /** @brief The key 4. */
        RAWKEY_4                = 0x05,
        /** @brief The key 5. */
        RAWKEY_5                = 0x06,
        /** @brief The key 6. */
        RAWKEY_6                = 0x07,
        /** @brief The key 7. */
        RAWKEY_7                = 0x08,
        /** @brief The key 8. */
        RAWKEY_8                = 0x09,
        /** @brief The key 9. */
        RAWKEY_9                = 0x0A,
        /** @brief The key 0. */
        RAWKEY_0                = 0x0B,
        /** @brief The key MINUS. */
        RAWKEY_MINUS            = 0x0C,
        /** @brief The key EQUALS. */
        RAWKEY_EQUALS           = 0x0D,
        /** @brief The key BACKSPACE. */
        RAWKEY_BACKSPACE        = 0x0E,

        /** @brief The key TAB. */
        RAWKEY_TAB              = 0x0F,
        /** @brief The key Q. */
        RAWKEY_Q                = 0x10,
        /** @brief The key W. */
        RAWKEY_W                = 0x11,
        /** @brief The key E. */
        RAWKEY_E                = 0x12,
        /** @brief The key R. */
        RAWKEY_R                = 0x13,
        /** @brief The key T. */
        RAWKEY_T                = 0x14,
        /** @brief The key Y. */
        RAWKEY_Y                = 0x15,
        /** @brief The key U. */
        RAWKEY_U                = 0x16,
        /** @brief The key I. */
        RAWKEY_I                = 0x17,
        /** @brief The key O. */
        RAWKEY_O                = 0x18,
        /** @brief The key P. */
        RAWKEY_P                = 0x19,
        /** @brief The key LEFT_BRACKET. */
        RAWKEY_LEFT_BRACKET     = 0x1A,
        /** @brief The key RIGHT_BRACKET. */
        RAWKEY_RIGHT_BRACKET    = 0x1B,
        /** @brief The key RETURN. */
        RAWKEY_RETURN           = 0x1C,

        /** @brief The key LEFT_CONTROL. */
        RAWKEY_LEFT_CONTROL     = 0x1D,
        /** @brief The key A. */
        RAWKEY_A                = 0x1E,
        /** @brief The key S. */
        RAWKEY_S                = 0x1F,
        /** @brief The key D. */
        RAWKEY_D                = 0x20,
        /** @brief The key F. */
        RAWKEY_F                = 0x21,
        /** @brief The key G. */
        RAWKEY_G                = 0x22,
        /** @brief The key H. */
        RAWKEY_H                = 0x23,
        /** @brief The key J. */
        RAWKEY_J                = 0x24,
        /** @brief The key K. */
        RAWKEY_K                = 0x25,
        /** @brief The key L. */
        RAWKEY_L                = 0x26,
        /** @brief The key SEMICOLON. */
        RAWKEY_SEMICOLON        = 0x27,
        /** @brief The key APOSTROPHE. */
        RAWKEY_APOSTROPHE       = 0x28,
        /** @brief The key ACCENT_GRAVE. */
        RAWKEY_ACCENT_GRAVE     = 0x29,

        /** @brief The key LEFT_SHIFT. */
        RAWKEY_LEFT_SHIFT       = 0x2A,
        /** @brief The key BACKSLASH. */
        RAWKEY_BACKSLASH        = 0x2B,
        /** @brief The key Z. */
        RAWKEY_Z                = 0x2C,
        /** @brief The key X. */
        RAWKEY_X                = 0x2D,
        /** @brief The key C. */
        RAWKEY_C                = 0x2E,
        /** @brief The key V. */
        RAWKEY_V                = 0x2F,
        /** @brief The key B. */
        RAWKEY_B                = 0x30,
        /** @brief The key N. */
        RAWKEY_N                = 0x31,
        /** @brief The key M. */
        RAWKEY_M                = 0x32,
        /** @brief The key COMMA. */
        RAWKEY_COMMA            = 0x33,
        /** @brief The key PERIOD. */
        RAWKEY_PERIOD           = 0x34,
        /** @brief The key SLASH. */
        RAWKEY_SLASH            = 0x35,
        /** @brief The key RIGHT_SHIFT. */
        RAWKEY_RIGHT_SHIFT      = 0x36,

        /** @brief The key KEYPAD_MULTIPLY. */
        RAWKEY_KEYPAD_MULTIPLY  = 0x37,
        /** @brief The key LEFT_ALT. */
        RAWKEY_LEFT_ALT         = 0x38,
        /** @brief The key SPACE. */
        RAWKEY_SPACE            = 0x39,
        /** @brief The key CAPS_LOCK. */
        RAWKEY_CAPS_LOCK        = 0x3A,
        /** @brief The key F1. */
        RAWKEY_F1               = 0x3B,
        /** @brief The key F2. */
        RAWKEY_F2               = 0x3C,
        /** @brief The key F3. */
        RAWKEY_F3               = 0x3D,
        /** @brief The key F4. */
        RAWKEY_F4               = 0x3E,
        /** @brief The key F5. */
        RAWKEY_F5               = 0x3F,
        /** @brief The key F6. */
        RAWKEY_F6               = 0x40,
        /** @brief The key F7. */
        RAWKEY_F7               = 0x41,
        /** @brief The key F8. */
        RAWKEY_F8               = 0x42,
        /** @brief The key F9. */
        RAWKEY_F9               = 0x43,
        /** @brief The key F10. */
        RAWKEY_F10              = 0x44,

        /** @brief The key NUMLOCK on the keypad. */
        RAWKEY_KEYPAD_NUMLOCK   = 0x45,
        /** @brief The key SCROLL_LOCK. */
        RAWKEY_SCROLL_LOCK      = 0x46,
        /** @brief The key 7 on the keypad. */
        RAWKEY_KEYPAD_7         = 0x47,
        /** @brief The key 8 on the keypad. */
        RAWKEY_KEYPAD_8         = 0x48,
        /** @brief The key 9 on the keypad. */
        RAWKEY_KEYPAD_9         = 0x49,
        /** @brief The key - on the keypad. */
        RAWKEY_KEYPAD_MINUS     = 0x4A,
        /** @brief The key 4 on the keypad. */
        RAWKEY_KEYPAD_4         = 0x4B,
        /** @brief The key 5 on the keypad. */
        RAWKEY_KEYPAD_5         = 0x4C,
        /** @brief The key 6 on the keypad. */
        RAWKEY_KEYPAD_6         = 0x4D,
        /** @brief The key + on the keypad. */
        RAWKEY_KEYPAD_PLUS      = 0x4E,
        /** @brief The key 1 on the keypad. */
        RAWKEY_KEYPAD_1         = 0x4F,
        /** @brief The key 2 on the keypad. */
        RAWKEY_KEYPAD_2         = 0x50,
        /** @brief The key 3 on the keypad. */
        RAWKEY_KEYPAD_3         = 0x51,
        /** @brief The key 0 on the keypad. */
        RAWKEY_KEYPAD_0         = 0x52,
        /** @brief The key DECIMAL on the keypad. */
        RAWKEY_KEYPAD_DECIMAL   = 0x53,

        /** @brief The key RT 102-key. */
        RAWKEY_RT_102           = 0x56,    // <> or \| on RT 102-key keyboard (Non-U.S.)
        /** @brief The key F11. */
        RAWKEY_F11              = 0x57,
        /** @brief The key F12. */
        RAWKEY_F12              = 0x58,

        /** @brief The key FUNCTION (fn on Mac or context menu on PC).*/
        RAWKEY_FUNCTION         = 0x59,    // fn (Mac) or context menu (PC)

        /** @brief The key F13. */
        RAWKEY_F13              = 0x64,    //                     (NEC PC98)
        /** @brief The key F14. */
        RAWKEY_F14              = 0x65,    //                     (NEC PC98)
        /** @brief The key F15. */
        RAWKEY_F15              = 0x66,    //                     (NEC PC98)
        /** @brief The key F16. */
        RAWKEY_F16              = 0x67,
        /** @brief The key F17. */
        RAWKEY_F17              = 0x68,
        /** @brief The key F18. */
        RAWKEY_F18              = 0x69,
        /** @brief The key F19. */
        RAWKEY_F19              = 0x6a,
        /** @brief The key F20. */
        RAWKEY_F20              = 0x6b,
        /** @brief The key F21. */
        RAWKEY_F21              = 0x6c,
        /** @brief The key F22. */
        RAWKEY_F22              = 0x6d,
        /** @brief The key F23. */
        RAWKEY_F23              = 0x6e,
        /** @brief The key F24. */
        RAWKEY_F24              = 0x6f,

        /** @brief The key KANA (Japanese Keyboard). */
        RAWKEY_KANA             = 0x70,    // (Japanese keyboard)
        /** @brief The key C1 (? on Brazilian keyboard). */
        RAWKEY_ABNT_C1          = 0x73,    // /? on Brazilian keyboard
        /** @brief The key CONVERT (Japanese Keyboard). */
        RAWKEY_CONVERT          = 0x79,    // (Japanese keyboard)
        /** @brief The key NOCONVERT (Japanese Keyboard). */
        RAWKEY_NOCONVERT        = 0x7B,    // (Japanese keyboard)
        /** @brief The key YEN (Japanese Keyboard). */
        RAWKEY_YEN              = 0x7D,    // (Japanese keyboard)
        /** @brief The key C2 (. on Brazilian keyboard). */
        RAWKEY_ABNT_C2          = 0x7E,    // Numpad . on Brazilian keyboard
        /** @brief The key EQUALS on numeric keypad. */
        RAWKEY_KEYPAD_EQUALS    = 0x8D,    // = on numeric keypad (NEC PC98)
        /** @brief The key PREVIOUS_TRACK (RAWKEY_CIRCUMFLEX on Japanese keyboard). */
        RAWKEY_PREV_TRACK       = 0x90,    // Previous Track (RAWKEY_CIRCUMFLEX on Japanese keyboard)
        /** @brief The key AT. */
        RAWKEY_AT               = 0x91,    //                     (NEC PC98)
        /** @brief The key COLON. */
        RAWKEY_COLON            = 0x92,    //                     (NEC PC98)
        /** @brief The key UNDERLINE. */
        RAWKEY_UNDERLINE        = 0x93,    //                     (NEC PC98)
        /** @brief The key KANJI (Japanese Keyboard). */
        RAWKEY_KANJI            = 0x94,    // (Japanese keyboard)
        /** @brief The key STOP. */
        RAWKEY_STOP             = 0x95,    //                     (NEC PC98)
        /** @brief The key AX (Japan AX). */
        RAWKEY_AX               = 0x96,    //                     (Japan AX)
        /** @brief The key UNLABELED (J3100). */
        RAWKEY_UNLABELED        = 0x97,    //                        (J3100)

        /** @brief The key NEXT_TRACK. */
        RAWKEY_NEXT_TRACK       = 0x99,
        /** @brief The key KEYPAD_ENTER. */
        RAWKEY_KEYPAD_ENTER     = 0x9C,
        /** @brief The key RIGHT_CONTROL. */
        RAWKEY_RIGHT_CONTROL    = 0x9D,
        /** @brief The key MUTE. */
        RAWKEY_MUTE             = 0xA0,
        /** @brief The key CALCULATOR. */
        RAWKEY_CALCULATOR       = 0xA1,
        /** @brief The key PLAY_PAUSE. */
        RAWKEY_PLAY_PAUSE       = 0xA2,
        /** @brief The key MEDIA_STOP. */
        RAWKEY_MEDIA_STOP       = 0xA4,
        /** @brief The key VOLUME_DOWN. */
        RAWKEY_VOLUME_DOWN      = 0xAE,
        /** @brief The key VOLUME_UP. */
        RAWKEY_VOLUME_UP        = 0xB0,
        /** @brief The key WEB_HOME. */
        RAWKEY_WEB_HOME         = 0xB2,
        /** @brief The key COMMA on numeric keypad. */
        RAWKEY_KEYPAD_COMMA     = 0xB3,    // , on numeric keypad (NEC PC98)

        /** @brief The key DIVIDE on numeric keypad. */
        RAWKEY_KEYPAD_DIVIDE    = 0xB5,
        /** @brief The key PRINT_SCREEN. */
        RAWKEY_PRINT_SCREEN     = 0xB7,
        /** @brief The key RIGHT_ALT. */
        RAWKEY_RIGHT_ALT        = 0xB8,
        /** @brief The key PAUSE. */
        RAWKEY_PAUSE            = 0xC5,
        /** @brief The key HOME. */
        RAWKEY_HOME             = 0xC7,

        /** @brief The key UP_ARROW. */
        RAWKEY_UP_ARROW         = 0xC8,
        /** @brief The key PAGE_UP. */
        RAWKEY_PAGE_UP          = 0xC9,
        /** @brief The key LEFT_ARROW. */
        RAWKEY_LEFT_ARROW       = 0xCB,
        /** @brief The key RIGHT_ARROW. */
        RAWKEY_RIGHT_ARROW      = 0xCD,
        /** @brief The key END. */
        RAWKEY_END              = 0xCF,
        /** @brief The key DOWN_ARROW. */
        RAWKEY_DOWN_ARROW       = 0xD0,
        /** @brief The key PAGE_DOWN. */
        RAWKEY_PAGE_DOWN        = 0xD1,
        /** @brief The key INSERT. */
        RAWKEY_INSERT           = 0xD2,
        /** @brief The key DELETE. */
        RAWKEY_DELETE           = 0xD3,
        /** @brief The key LEFT_GUI. */
        RAWKEY_LEFT_GUI         = 0xDB,
        /** @brief The key RIGHT_GUI. */
        RAWKEY_RIGHT_GUI        = 0xDC,

        /** @brief The key APP_MENU. */
        RAWKEY_APP_MENU         = 0xDD,
        /** @brief The key SYSTEM_POWER. */
        RAWKEY_SYSTEM_POWER     = 0xDE,
        /** @brief The key SYSTEM_SLEEP. */
        RAWKEY_SYSTEM_SLEEP     = 0xDF,
        /** @brief The key SYSTEM_WAKE. */
        RAWKEY_SYSTEM_WAKE      = 0xE3,
        /** @brief The key WEB_SEARCH. */
        RAWKEY_WEB_SEARCH       = 0xE5,
        /** @brief The key WEB_FAVORITES. */
        RAWKEY_WEB_FAVORITES    = 0xE6,
        /** @brief The key WEB_REFRESH. */
        RAWKEY_WEB_REFRESH      = 0xE7,
        /** @brief The key WEB_STOP. */
        RAWKEY_WEB_STOP         = 0xE8,
        /** @brief The key WEB_FORWARD. */
        RAWKEY_WEB_FORWARD      = 0xE9,
        /** @brief The key WEB_BACK. */
        RAWKEY_WEB_BACK         = 0xEA,
        /** @brief The key MY_COMPUTER. */
        RAWKEY_MY_COMPUTER      = 0xEB,
        /** @brief The key MAIL. */
        RAWKEY_MAIL             = 0xEC,
        /** @brief The key MEDIA_SELECT. */
        RAWKEY_MEDIA_SELECT     = 0xED,

        NUM_RAWKEY_CODES
    };

    MURL_DECLARE_ENUM_ACCESSOR(RawKeyCode)

    /** @} */
}

#endif  // __MURL_RAW_KEY_CODES_H__
