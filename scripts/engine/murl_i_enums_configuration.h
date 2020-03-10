// Copyright 2010-2015 Spraylight GmbH

#ifndef __MURL_I_ENUMS_CONFIGURATION_H__
#define __MURL_I_ENUMS_CONFIGURATION_H__

#include "murl_enum.h"

namespace Murl
{
    namespace IEnums
    {
        /**
         * @addtogroup MurlConfigurationEnumerations
         * @brief Configuration items enumerations.
         * @{
         */

        /**
         * @brief Ranges for groups.
         */
        enum GroupRanges
        {
            /// Group bit shift value.
            GROUP_SHIFT = 8,
            /// Group start value.
            GROUP_START = (1 << GROUP_SHIFT),
            /// Group mask value.
            GROUP_MASK  = (GROUP_START - 1),
        };

        /**
         * @brief Available (written) languages.
         */
        enum Language
        {
            /// The system default language
            MURL_DECLARE_ENUM_VALUE(LANGUAGE, DEFAULT)

            /// English language
            MURL_DECLARE_ENUM_VALUE(LANGUAGE, ENGLISH)
            /// German language
            MURL_DECLARE_ENUM_VALUE(LANGUAGE, GERMAN)
            /// French language
            MURL_DECLARE_ENUM_VALUE(LANGUAGE, FRENCH)
            /// Spanish language
            MURL_DECLARE_ENUM_VALUE(LANGUAGE, SPANISH)
            /// Italian language
            MURL_DECLARE_ENUM_VALUE(LANGUAGE, ITALIAN)
            /// Simplified Chinese language
            MURL_DECLARE_ENUM_VALUE(LANGUAGE, CHINESE)
            /// Korean language
            MURL_DECLARE_ENUM_VALUE(LANGUAGE, KOREAN)
            /// Japanese language
            MURL_DECLARE_ENUM_VALUE(LANGUAGE, JAPANESE)
            /// Russian language
            MURL_DECLARE_ENUM_VALUE(LANGUAGE, RUSSIAN)
            /// Portuguese language
            MURL_DECLARE_ENUM_VALUE(LANGUAGE, PORTUGUESE)

            NUM_LANGUAGES
        };
        MURL_DECLARE_ENUM_ACCESSOR(Language)

        /**
         * @brief Available target classes.
         * Target classes are divided into distinct groups. Checking class membership of
         * a given value can be done in the following way:
         * @code
         * IEnums::TargetClass x = ...;
         * if ((x >= IEnums::TARGET_CLASS_HANDHELD) && (x < IEnums::TARGET_CLASS_HANDHELD_LAST))
         * {
         *     // x is a member of the "HANDHELD" group
         * }
         * @endcode
         */
        enum TargetClass
        {
            /// The system default target device class
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TARGET_CLASS, DEFAULT, 0)

            /// Computer group
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TARGET_CLASS, COMPUTER, 1 * GROUP_START)
            /// Desktop computer
            MURL_DECLARE_ENUM_VALUE(TARGET_CLASS, COMPUTER_DESKTOP)
            /// Laptop computer
            MURL_DECLARE_ENUM_VALUE(TARGET_CLASS, COMPUTER_LAPTOP)
            /// Last target class in computer group
            MURL_DECLARE_ENUM_VALUE(TARGET_CLASS, COMPUTER_LAST)

            /// Handheld device group
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TARGET_CLASS, HANDHELD, 2 * GROUP_START)
            /// Tablet
            MURL_DECLARE_ENUM_VALUE(TARGET_CLASS, HANDHELD_TABLET)
            /// Smartphone
            MURL_DECLARE_ENUM_VALUE(TARGET_CLASS, HANDHELD_SMARTPHONE)
            /// Music player
            MURL_DECLARE_ENUM_VALUE(TARGET_CLASS, HANDHELD_MUSIC_PLAYER)
            /// Last target class in handheld group
            MURL_DECLARE_ENUM_VALUE(TARGET_CLASS, HANDHELD_LAST)

            /// Console group
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TARGET_CLASS, CONSOLE, 4 * GROUP_START)
            /// Generic console
            MURL_DECLARE_ENUM_VALUE(TARGET_CLASS, CONSOLE_GENERIC)
            /// Last target class in console group
            MURL_DECLARE_ENUM_VALUE(TARGET_CLASS, CONSOLE_LAST)
        };
        MURL_DECLARE_ENUM_ACCESSOR(TargetClass)

        /**
         * @brief Available target devices.
         * Target devices are divided into distinct groups. Checking class membership of
         * a given value can be done in the following way:
         * @code
         * IEnums::TargetDevice x = ...;
         * if ((x >= IEnums::TARGET_DEVICE_IPHONE) && (x < IEnums::TARGET_DEVICE_IPHONE_LAST))
         * {
         *     // x is a member of the "IPHONE" group
         * }
         * @endcode
         */
        enum TargetDevice
        {
            /// The system default target device
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TARGET_DEVICE, DEFAULT, 0)

            /// iPhone group
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TARGET_DEVICE, IPHONE, 1 * GROUP_START)
            /// 1st gen iPhone
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPHONE_1)
            /// iPhone 3G
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPHONE_3G)
            /// iPhone 3GS
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPHONE_3GS)
            /// iPhone 4
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPHONE_4)
            /// iPhone 4S
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPHONE_4S)
            /// iPhone 5
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPHONE_5)
            /// iPhone 5c
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPHONE_5C)
            /// iPhone 5s
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPHONE_5S)
            /// iPhone 6
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPHONE_6)
            /// iPhone 6 plus
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPHONE_6_PLUS)
            /// iPhone 6S
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPHONE_6S)
            /// iPhone 6S plus
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPHONE_6S_PLUS)
            /// iPhone SE
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPHONE_SE)
            /// iPhone 7
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPHONE_7)
            /// iPhone 7 plus
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPHONE_7_PLUS)
            /// iPhone 8
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPHONE_8)
            /// iPhone 8 plus
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPHONE_8_PLUS)
            /// iPhone X
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPHONE_X)
            /// iPhone XR
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPHONE_XR)
            /// iPhone XS
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPHONE_XS)
            /// iPhone XS Max
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPHONE_XS_MAX)
            /// Last target device in iPhone group
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPHONE_LAST)

            /// iPad group
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TARGET_DEVICE, IPAD, 2 * GROUP_START)
            /// 1st gen iPad
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPAD_1)
            /// 2nd gen iPad
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPAD_2)
            /// 3rd gen iPad
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPAD_3)
            /// 4th gen iPad
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPAD_4)
            /// 1st gen iPad Air
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPAD_AIR_1)
            /// 2nd gen iPad Air
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPAD_AIR_2)
            /// iPad mini 1st gen
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPAD_MINI_1)
            /// iPad mini 2nd gen
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPAD_MINI_2)
            /// iPad mini 3rd gen
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPAD_MINI_3)
            /// iPad mini 4th gen
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPAD_MINI_4)
            /// 1st gen iPad pro 12.9"
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPAD_PRO_12IN9_1)
            /// 1st gen iPad pro 9.7"
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPAD_PRO_9IN7_1)
            /// 5th gen iPad
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPAD_5)
            /// 2nd gen iPad pro 12.9"
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPAD_PRO_12IN9_2)
            /// 1st gen iPad pro 10.5"
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPAD_PRO_10IN5_1)
            /// 6th gen iPad
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPAD_6)
            /// 1st gen iPad pro 11.0"
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPAD_PRO_11IN0_1)
            /// 3rd gen iPad pro 12.9"
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPAD_PRO_12IN9_3)

            /// Last target device in iPad group
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPAD_LAST)

            /// iPod group
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TARGET_DEVICE, IPOD, 3 * GROUP_START)
            /// 1st gen iPod
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPOD_1G)
            /// 2nd gen iPod
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPOD_2G)
            /// 3rd gen iPod
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPOD_3G)
            /// 4th gen iPod
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPOD_4G)
            /// 5th gen iPod
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPOD_5G)
            /// 6th gen iPod
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPOD_6G)
            /// Last target device in iPod group
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, IPOD_LAST)

            /// AppleTv group
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TARGET_DEVICE, APPLETV, 4 * GROUP_START)
            /// 4th gen AppleTV
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, APPLETV_4)
            /// AppleTV 4K
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, APPLETV_4K)
            /// Last target device in iPod group
            MURL_DECLARE_ENUM_VALUE(TARGET_DEVICE, APPLETV_LAST)
        };
        MURL_DECLARE_ENUM_ACCESSOR(TargetDevice)

        /**
         * @brief Available target hosts.
         * Target hosts are divided into distinct groups. Checking group membership of
         * a given value can be done in the following way:
         * @code
         * IEnums::TargetHost x = ...;
         * if ((x >= IEnums::TARGET_HOST_BROWSER) && (x < IEnums::TARGET_HOST_BROWSER_LAST))
         * {
         *     // x is a member of the "BROWSER" group
         * }
         * @endcode
         */
        enum TargetHost
        {
            /// The system default target host
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TARGET_HOST, DEFAULT, 0)

            /// Native group
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TARGET_HOST, NATIVE, 1 * GROUP_START)
            /// Generic native host
            MURL_DECLARE_ENUM_VALUE(TARGET_HOST, NATIVE_GENERIC)
            /// Last target host in native group
            MURL_DECLARE_ENUM_VALUE(TARGET_HOST, NATIVE_LAST)

            /// Browser group
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TARGET_HOST, BROWSER, 2 * GROUP_START)
            /// Generic browser
            MURL_DECLARE_ENUM_VALUE(TARGET_HOST, BROWSER_GENERIC)
            /// Google Chrome
            MURL_DECLARE_ENUM_VALUE(TARGET_HOST, BROWSER_CHROME)
            /// Microsoft Edge
            MURL_DECLARE_ENUM_VALUE(TARGET_HOST, BROWSER_EDGE)
            /// Mozilla Firefox
            MURL_DECLARE_ENUM_VALUE(TARGET_HOST, BROWSER_FIREFOX)
            /// Microsoft Internet Explorer
            MURL_DECLARE_ENUM_VALUE(TARGET_HOST, BROWSER_IE)
            /// Opera
            MURL_DECLARE_ENUM_VALUE(TARGET_HOST, BROWSER_OPERA)
            /// Phantom
            MURL_DECLARE_ENUM_VALUE(TARGET_HOST, BROWSER_PHANTOM)
            /// Apple Safari
            MURL_DECLARE_ENUM_VALUE(TARGET_HOST, BROWSER_SAFARI)

            /// Last target host in browser group
            MURL_DECLARE_ENUM_VALUE(TARGET_HOST, BROWSER_LAST)
        };
        MURL_DECLARE_ENUM_ACCESSOR(TargetHost)

        /**
         * @brief Available operating systems.
         * Operating systems are divided into distinct groups. Checking class membership of
         * a given value can be done in the following way:
         * @code
         * IEnums::OperatingSystem x = ...;
         * if ((x >= IEnums::OPERATING_SYSTEM_WINDOWS) && (x < IEnums::OPERATING_SYSTEM_WINDOWS_LAST))
         * {
         *     // x is a member of the "WINDOWS" group
         * }
         * @endcode
         */
        enum OperatingSystem
        {
            /// The system default operating system
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(OPERATING_SYSTEM, DEFAULT, 0)

            /// Apple Mac OS X
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(OPERATING_SYSTEM, OSX, 1 * GROUP_START)
            /// Apple Mac OS X 10.5 (Leopard)
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, OSX_10_5)
            /// Apple Mac OS X 10.6 (Snow Leopard)
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, OSX_10_6)
            /// Apple Mac OS X 10.7 (Lion)
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, OSX_10_7)
            /// Apple Mac OS X 10.8 (Mountain Lion)
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, OSX_10_8)
            /// Apple Mac OS X 10.9 (Mavericks)
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, OSX_10_9)
            /// Apple Mac OS X 10.10 (Yosemite)
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, OSX_10_10)
            /// Apple Mac OS X 10.11 (El Capitan)
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, OSX_10_11)
            /// Apple Mac OS X 10.12 (Sierra)
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, OSX_10_12)
            /// Apple Mac OS X 10.13 (High Sierra)
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, OSX_10_13)
            /// Apple Mac OS X 10.14 (Mojave)
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, OSX_10_14)
            /// Last operating system in Apple Mac OS X group
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, OSX_LAST)
            /* TODO: Currently, an Enum can only have one literal name
             OPERATING_SYSTEM_OSX_LEOPARD                = OPERATING_SYSTEM_OSX_10_5,
             OPERATING_SYSTEM_OSX_SNOW_LEOPARD           = OPERATING_SYSTEM_OSX_10_6,
             OPERATING_SYSTEM_OSX_LION                   = OPERATING_SYSTEM_OSX_10_7,
             OPERATING_SYSTEM_OSX_MOUNTAIN_LION          = OPERATING_SYSTEM_OSX_10_8,
             OPERATING_SYSTEM_OSX_MAVERICKS              = OPERATING_SYSTEM_OSX_10_9,
             OPERATING_SYSTEM_OSX_YOSEMITE               = OPERATING_SYSTEM_OSX_10_10,
             OPERATING_SYSTEM_OSX_EL_CAPITAN             = OPERATING_SYSTEM_OSX_10_11,
             OPERATING_SYSTEM_OSX_SIERRA                 = OPERATING_SYSTEM_OSX_10_12,
             OPERATING_SYSTEM_OSX_HIGH_SIERRA            = OPERATING_SYSTEM_OSX_10_13,
             OPERATING_SYSTEM_OSX_MOJAVE                 = OPERATING_SYSTEM_OSX_10_14,
             */

            /// Apple iOS
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(OPERATING_SYSTEM, IOS, 2 * GROUP_START)
            /// Apple iOS 3.0
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, IOS_3_0)
            /// Apple iOS 3.1
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, IOS_3_1)
            /// Apple iOS 3.2
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, IOS_3_2)
            /// Apple iOS 4.0
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, IOS_4_0)
            /// Apple iOS 4.1
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, IOS_4_1)
            /// Apple iOS 4.2
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, IOS_4_2)
            /// Apple iOS 4.3
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, IOS_4_3)
            /// Apple iOS 5.0
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, IOS_5_0)
            /// Apple iOS 5.1
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, IOS_5_1)
            /// Apple iOS 5.2
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, IOS_5_2)
            /// Apple iOS 5.3
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, IOS_5_3)
            /// Apple iOS 6.0
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, IOS_6_0)
            /// Apple iOS 6.1
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, IOS_6_1)
            /// Apple iOS 7.0
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, IOS_7_0)
            /// Apple iOS 8.x
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, IOS_8_0)
            /// Apple iOS 9.x
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, IOS_9_0)
            /// Apple iOS 10.x
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, IOS_10_0)
            /// Apple iOS 11.x
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, IOS_11_0)
            /// Apple iOS 12.x
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, IOS_12_0)
            /// Last operating system in Apple iOS group
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, IOS_LAST)

            /// Microsoft Windows
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(OPERATING_SYSTEM, WINDOWS, 3 * GROUP_START)
            /// Microsoft Windows XP
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, WINDOWS_XP)
            /// Microsoft Windows Vista
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, WINDOWS_VISTA)
            /// Microsoft Windows 7
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, WINDOWS_7)
            /// Microsoft Windows 8
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, WINDOWS_8)
            /// Microsoft Windows 8.1
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, WINDOWS_8_1)
            /// Microsoft Windows 10
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, WINDOWS_10)
            /// Last operating system in Microsoft Windows group
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, WINDOWS_LAST)

            /// Google Android
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(OPERATING_SYSTEM, ANDROID, 4 * GROUP_START)
            /// Android 2.0 ("Eclair", API Level 5)
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, ANDROID_API_5)
            /// Android 2.0.1 ("Eclair", API Level 6)
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, ANDROID_API_6)
            /// Android 2.1 ("Eclair MR1", API Level 7)
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, ANDROID_API_7)
            /// Android 2.2 - 2.2.2 ("Froyo", API Level 8)
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, ANDROID_API_8)
            /// Android 2.3 - 2.3.2 ("Gingerbread", API Level 9)
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, ANDROID_API_9)
            /// Android 2.3.3 - 2.3.7 ("Gingerbread MR1", API Level 10)
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, ANDROID_API_10)
            /// Android 3.0 ("Honeycomb", API Level 11)
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, ANDROID_API_11)
            /// Android 3.1 ("Honeycomb MR1", API Level 12)
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, ANDROID_API_12)
            /// Android 3.2 - 3.2.1 ("Honeycomb MR2", API Level 13)
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, ANDROID_API_13)
            /// Android 4.0 - 4.0.2 ("Ice Cream Sandwich", API Level 14)
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, ANDROID_API_14)
            /// Android 4.0.3 - 4.0.4 ("Ice Cream Sandwich", API Level 15)
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, ANDROID_API_15)
            /// Android 4.1 - 4.1.2 ("Jelly Bean", API Level 16)
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, ANDROID_API_16)
            /// Android 4.2 - 4.2.2 ("Jelly Bean", API Level 17)
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, ANDROID_API_17)
            /// Android 4.3 - 4.3.1 ("Jelly Bean", API Level 18)
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, ANDROID_API_18)
            /// Android 4.4 - 4.4.4 ("KitKat", API Level 19)
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, ANDROID_API_19)
            /// Android 4.4W ("Android Wear", API Level 20)
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, ANDROID_API_20)
            /// Android 5.0 ("Lollipop", API Level 21)
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, ANDROID_API_21)
            /// Android 5.1 ("Lollipop", API Level 22)
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, ANDROID_API_22)
            /// Android 6.0 ("Marshmallow", API Level 23)
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, ANDROID_API_23)
            /// Android 7.0 ("Nougat", API Level 24)
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, ANDROID_API_24)
            /// Android 7.1 ("Nougat", API Level 25)
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, ANDROID_API_25)
            /// Android 8.0 ("Oreo", API Level 26)
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, ANDROID_API_26)
            /// Android 8.1 ("Oreo", API Level 27)
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, ANDROID_API_27)
            /// Android 9.0 ("Pie", API Level 28)
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, ANDROID_API_28)
            /// Android API Level 29
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, ANDROID_API_29)
            /// Android API Level 30
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, ANDROID_API_30)
            /// Android API Level 31
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, ANDROID_API_31)
            /// Android API Level 32
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, ANDROID_API_32)
            /// Android API Level 33
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, ANDROID_API_33)
            /// Android API Level 34
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, ANDROID_API_34)
            /// Android API Level 35
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, ANDROID_API_35)
            /// Android API Level 36
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, ANDROID_API_36)
            /// Android API Level 37
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, ANDROID_API_37)
            /// Android API Level 38
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, ANDROID_API_38)
            /// Android API Level 39
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, ANDROID_API_39)
            /// Android API Level 40
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, ANDROID_API_40)
            /// Last operating system in Google Android group
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, ANDROID_LAST)
            /* TODO: Currently, an Enum can only have one literal name
             OPERATING_SYSTEM_ANDROID_2_0                = OPERATING_SYSTEM_ANDROID_API_5,
             OPERATING_SYSTEM_ANDROID_2_0_1              = OPERATING_SYSTEM_ANDROID_API_6,
             OPERATING_SYSTEM_ANDROID_2_1                = OPERATING_SYSTEM_ANDROID_API_7,
             OPERATING_SYSTEM_ANDROID_2_2                = OPERATING_SYSTEM_ANDROID_API_8,
             OPERATING_SYSTEM_ANDROID_2_3                = OPERATING_SYSTEM_ANDROID_API_9,
             OPERATING_SYSTEM_ANDROID_2_3_3              = OPERATING_SYSTEM_ANDROID_API_10,
             OPERATING_SYSTEM_ANDROID_3_0                = OPERATING_SYSTEM_ANDROID_API_11,
             OPERATING_SYSTEM_ANDROID_3_1                = OPERATING_SYSTEM_ANDROID_API_12,
             OPERATING_SYSTEM_ANDROID_3_2                = OPERATING_SYSTEM_ANDROID_API_13,
             OPERATING_SYSTEM_ANDROID_4_0                = OPERATING_SYSTEM_ANDROID_API_14,
             OPERATING_SYSTEM_ANDROID_4_0_3              = OPERATING_SYSTEM_ANDROID_API_15,
             OPERATING_SYSTEM_ANDROID_4_1                = OPERATING_SYSTEM_ANDROID_API_16,
             OPERATING_SYSTEM_ANDROID_4_2                = OPERATING_SYSTEM_ANDROID_API_17,
             OPERATING_SYSTEM_ANDROID_4_3                = OPERATING_SYSTEM_ANDROID_API_18,
             OPERATING_SYSTEM_ANDROID_4_4                = OPERATING_SYSTEM_ANDROID_API_19,
             OPERATING_SYSTEM_ANDROID_4_4_W              = OPERATING_SYSTEM_ANDROID_API_20,
             OPERATING_SYSTEM_ANDROID_5_0                = OPERATING_SYSTEM_ANDROID_API_21,
             OPERATING_SYSTEM_ANDROID_5_1                = OPERATING_SYSTEM_ANDROID_API_22,
             OPERATING_SYSTEM_ANDROID_6_0                = OPERATING_SYSTEM_ANDROID_API_23,
             OPERATING_SYSTEM_ANDROID_7_0                = OPERATING_SYSTEM_ANDROID_API_24,
             OPERATING_SYSTEM_ANDROID_7_1                = OPERATING_SYSTEM_ANDROID_API_25,
             OPERATING_SYSTEM_ANDROID_8_0                = OPERATING_SYSTEM_ANDROID_API_26,
             OPERATING_SYSTEM_ANDROID_8_1                = OPERATING_SYSTEM_ANDROID_API_27,
             OPERATING_SYSTEM_ANDROID_9_0                = OPERATING_SYSTEM_ANDROID_API_28,

             OPERATING_SYSTEM_ANDROID_ECLAIR                 = OPERATING_SYSTEM_ANDROID_2_0,
             OPERATING_SYSTEM_ANDROID_ECLAIR_0_1             = OPERATING_SYSTEM_ANDROID_2_0_1,
             OPERATING_SYSTEM_ANDROID_ECLAIR_MR1             = OPERATING_SYSTEM_ANDROID_2_1,
             OPERATING_SYSTEM_ANDROID_FROYO                  = OPERATING_SYSTEM_ANDROID_2_2,
             OPERATING_SYSTEM_ANDROID_GINGERBREAD            = OPERATING_SYSTEM_ANDROID_2_3,
             OPERATING_SYSTEM_ANDROID_GINGERBREAD_MR1        = OPERATING_SYSTEM_ANDROID_2_3_3,
             OPERATING_SYSTEM_ANDROID_HONEYCOMB              = OPERATING_SYSTEM_ANDROID_3_0,
             OPERATING_SYSTEM_ANDROID_HONEYCOMB_MR1          = OPERATING_SYSTEM_ANDROID_3_1,
             OPERATING_SYSTEM_ANDROID_HONEYCOMB_MR2          = OPERATING_SYSTEM_ANDROID_3_2,
             OPERATING_SYSTEM_ANDROID_ICE_CREAM_SANDWICH     = OPERATING_SYSTEM_ANDROID_4_0,
             OPERATING_SYSTEM_ANDROID_ICE_CREAM_SANDWICH_MR1 = OPERATING_SYSTEM_ANDROID_4_0_3,
             OPERATING_SYSTEM_ANDROID_JELLY_BEAN             = OPERATING_SYSTEM_ANDROID_4_1,
             OPERATING_SYSTEM_ANDROID_JELLY_BEAN_MR1         = OPERATING_SYSTEM_ANDROID_4_2,
             OPERATING_SYSTEM_ANDROID_JELLY_BEAN_MR2         = OPERATING_SYSTEM_ANDROID_4_3,
             OPERATING_SYSTEM_ANDROID_KIT_KAT                = OPERATING_SYSTEM_ANDROID_4_4,
             OPERATING_SYSTEM_ANDROID_WEAR                   = OPERATING_SYSTEM_ANDROID_4_4_W,
             OPERATING_SYSTEM_ANDROID_LOLLIPOP               = OPERATING_SYSTEM_ANDROID_5_0,
             OPERATING_SYSTEM_ANDROID_LOLLIPOP_MR1           = OPERATING_SYSTEM_ANDROID_5_1,
             OPERATING_SYSTEM_ANDROID_MARSHMALLOW            = OPERATING_SYSTEM_ANDROID_6_0,
             OPERATING_SYSTEM_ANDROID_NOUGAT                 = OPERATING_SYSTEM_ANDROID_7_0,
             OPERATING_SYSTEM_ANDROID_NOUGAT_MR1             = OPERATING_SYSTEM_ANDROID_7_1,
             OPERATING_SYSTEM_ANDROID_OREO                   = OPERATING_SYSTEM_ANDROID_8_0,
             OPERATING_SYSTEM_ANDROID_OREO_MR1               = OPERATING_SYSTEM_ANDROID_8_1,
             OPERATING_SYSTEM_ANDROID_PIE                    = OPERATING_SYSTEM_ANDROID_9_0,
             */

            /// Linux
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(OPERATING_SYSTEM, LINUX, 5 * GROUP_START)
            /// Last operating system in Linux group
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, LINUX_LAST)

            /// Apple tvOS
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(OPERATING_SYSTEM, TVOS, 7 * GROUP_START)
            /// Apple tvOS 9.x
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, TVOS_9_0)
            /// Apple tvOS 10.x
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, TVOS_10_0)
            /// Apple tvOS 11.x
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, TVOS_11_0)
            /// Apple tvOS 12.x
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, TVOS_12_0)
            /// Last operating system in Apple iOS group
            MURL_DECLARE_ENUM_VALUE(OPERATING_SYSTEM, TVOS_LAST)
        };
        MURL_DECLARE_ENUM_ACCESSOR(OperatingSystem)

        /**
         * @brief Available GPUs.
         * GPUs are divided into distinct groups. Checking class membership of
         * a given value can be done in the following way:
         * @code
         * IEnums::Gpu x = ...;
         * if ((x >= IEnums::GPU_TEGRA) && (x < IEnums::GPU_TEGRA_LAST))
         * {
         *     // x is a member of the "TEGRA" group
         * }
         * @endcode
         */
        enum Gpu
        {
            /// The system default GPU
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(GPU, DEFAULT, 0)

            /// Generic group
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(GPU, GENERIC, 1 * GROUP_START)
            /// Last GPU in generic group
            MURL_DECLARE_ENUM_VALUE(GPU, GENERIC_LAST)

            /// Imagination Technologies PowerVR group
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(GPU, POWERVR, 2 * GROUP_START)
            /// PowerVR MBX (Series4)
            MURL_DECLARE_ENUM_VALUE(GPU, POWERVR_MBX)
            /// PowerVR SGX (Series5)
            MURL_DECLARE_ENUM_VALUE(GPU, POWERVR_SGX)
            /// PowerVR GX (Series6)
            MURL_DECLARE_ENUM_VALUE(GPU, POWERVR_GX)
            /// Last GPU in PowerVR group
            MURL_DECLARE_ENUM_VALUE(GPU, POWERVR_LAST)

            /// Adreno group
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(GPU, ADRENO, 3 * GROUP_START)
            /// Adreno 205
            MURL_DECLARE_ENUM_VALUE(GPU, ADRENO_205)
            /// Last GPU in Adreno group
            MURL_DECLARE_ENUM_VALUE(GPU, ADRENO_LAST)

            /// nVidia Tegra group
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(GPU, TEGRA , 4 * GROUP_START)
            /// Tegra 1
            MURL_DECLARE_ENUM_VALUE(GPU, TEGRA_1)
            /// Tegra 2
            MURL_DECLARE_ENUM_VALUE(GPU, TEGRA_2)
            /// Tegra 3
            MURL_DECLARE_ENUM_VALUE(GPU, TEGRA_3)
            /// Last GPU in Tegra group
            MURL_DECLARE_ENUM_VALUE(GPU, TEGRA_LAST)

            /// nVidia GeForce group
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(GPU, GEFORCE, 5 * GROUP_START)
            /// Last GPU in GeForce group
            MURL_DECLARE_ENUM_VALUE(GPU, GEFORCE_LAST)

            /// AMD Radeon group
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(GPU, RADEON, 6 * GROUP_START)
            /// Last GPU in Radeon group
            MURL_DECLARE_ENUM_VALUE(GPU, RADEON_LAST)
            
            /// Apple GPU group
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(GPU, APPLE, 7 * GROUP_START)
            /// Apple Custom GPU (triple-core)
            MURL_DECLARE_ENUM_VALUE(GPU, APPLE_3_CORE)
            /// Apple Custom GPU (quad-core)
            MURL_DECLARE_ENUM_VALUE(GPU, APPLE_4_CORE)
            /// Last GPU in Radeon group
            MURL_DECLARE_ENUM_VALUE(GPU, APPLE_LAST)
        };
        MURL_DECLARE_ENUM_ACCESSOR(Gpu)

        /**
         * @brief Available engine features
         */
        enum Feature
        {
            // === General ===
            FEATURE_GROUP_GENERAL = 0x100,

            /// Hardware-accelerated video decoding
            MURL_DECLARE_ENUM_VALUE(FEATURE, ACCELERATED_VIDEO_DECODING)
            /// Hardware-accelerated audio decoding
            MURL_DECLARE_ENUM_VALUE(FEATURE, ACCELERATED_AUDIO_DECODING)

            /// Separate blend functions for RGB color & alpha values
            MURL_DECLARE_ENUM_VALUE(FEATURE, SEPARATE_BLEND_FUNCTION)
            /// Separate blend equations for RGB color & alpha values
            MURL_DECLARE_ENUM_VALUE(FEATURE, SEPARATE_BLEND_EQUATION)

            /// Planar/semiplanar YUV format support for video streams.
            MURL_DECLARE_ENUM_VALUE(FEATURE, STREAM_FORMAT_YUV)

            /// Client-side buffer arrays.
            MURL_DECLARE_ENUM_VALUE(FEATURE, CLIENT_SIDE_ARRAYS)

            // === Index buffer related ===
            FEATURE_GROUP_INDEX_BUFFER = 0x200,

            /// Support for 8bit index buffers (never available on DirectX).
            MURL_DECLARE_ENUM_VALUE(FEATURE, INDEX_BUFFER_FORMAT_UINT8)
            /// Support for 16bit index buffers (always available).
            MURL_DECLARE_ENUM_VALUE(FEATURE, INDEX_BUFFER_FORMAT_UINT16)
            /// Support for 32bit index buffers.
            MURL_DECLARE_ENUM_VALUE(FEATURE, INDEX_BUFFER_FORMAT_UINT32)


            // === Texture related ===
            FEATURE_GROUP_TEXTURE = 0x300,

            /// Limited NPOT texture support, with only CLAMP_TO_EDGE and without mip-mapping
            MURL_DECLARE_ENUM_VALUE(FEATURE, LIMITED_NON_POWER_OF_TWO_TEXTURES)
            /// Full NPOT texture support, including all wrap modes and mip-mapping
            MURL_DECLARE_ENUM_VALUE(FEATURE, FULL_NON_POWER_OF_TWO_TEXTURES)

            /// 2D color textures.
            MURL_DECLARE_ENUM_VALUE(FEATURE, FLAT_COLOR_TEXTURES)
            /// 2D depth textures.
            MURL_DECLARE_ENUM_VALUE(FEATURE, FLAT_DEPTH_TEXTURES)
            /// 2D stencil textures.
            MURL_DECLARE_ENUM_VALUE(FEATURE, FLAT_STENCIL_TEXTURES)

            /// Cube map color textures.
            MURL_DECLARE_ENUM_VALUE(FEATURE, CUBE_MAP_COLOR_TEXTURES)
            /// Cube map depth textures.
            MURL_DECLARE_ENUM_VALUE(FEATURE, CUBE_MAP_DEPTH_TEXTURES)
            /// Cube map stencil textures.
            MURL_DECLARE_ENUM_VALUE(FEATURE, CUBE_MAP_STENCIL_TEXTURES)

            /// 3D color textures.
            MURL_DECLARE_ENUM_VALUE(FEATURE, VOLUME_COLOR_TEXTURES)
            /// 3D depth textures.
            MURL_DECLARE_ENUM_VALUE(FEATURE, VOLUME_DEPTH_TEXTURES)
            /// 3D stencil textures.
            MURL_DECLARE_ENUM_VALUE(FEATURE, VOLUME_STENCIL_TEXTURES)

            /// Anisotropic texture filtering.
            MURL_DECLARE_ENUM_VALUE(FEATURE, TEXTURE_FILTER_ANISOTROPIC)
            /// Linear filtering for half-float textures.
            MURL_DECLARE_ENUM_VALUE(FEATURE, TEXTURE_FILTER_HALF_FLOAT_LINEAR)
            /// Linear filtering for float textures.
            MURL_DECLARE_ENUM_VALUE(FEATURE, TEXTURE_FILTER_FLOAT_LINEAR)

            /// 2D color array textures.
            MURL_DECLARE_ENUM_VALUE(FEATURE, FLAT_ARRAY_COLOR_TEXTURES)
            /// 2D depth array textures.
            MURL_DECLARE_ENUM_VALUE(FEATURE, FLAT_ARRAY_DEPTH_TEXTURES)
            /// 2D stencil array textures.
            MURL_DECLARE_ENUM_VALUE(FEATURE, FLAT_ARRAY_STENCIL_TEXTURES)

            /// Cube map color array textures.
            MURL_DECLARE_ENUM_VALUE(FEATURE, CUBE_MAP_ARRAY_COLOR_TEXTURES)
            /// Cube map depth array textures.
            MURL_DECLARE_ENUM_VALUE(FEATURE, CUBE_MAP_ARRAY_DEPTH_TEXTURES)
            /// Cube map stencil array textures.
            MURL_DECLARE_ENUM_VALUE(FEATURE, CUBE_MAP_ARRAY_STENCIL_TEXTURES)

            /// 3D color array textures.
            MURL_DECLARE_ENUM_VALUE(FEATURE, VOLUME_ARRAY_COLOR_TEXTURES)
            /// 3D depth array textures.
            MURL_DECLARE_ENUM_VALUE(FEATURE, VOLUME_ARRAY_DEPTH_TEXTURES)
            /// 3D stencil array textures.
            MURL_DECLARE_ENUM_VALUE(FEATURE, VOLUME_ARRAY_STENCIL_TEXTURES)
            
            // === Frame buffer related ===
            FEATURE_GROUP_FRAMEBUFFER = 0x400,

            /// Limited NPOT frame buffer support, with only CLAMP_TO_EDGE and without mip-mapping
            MURL_DECLARE_ENUM_VALUE(FEATURE, LIMITED_NON_POWER_OF_TWO_FRAMEBUFFERS)
            /// Full NPOT frame buffer support, including all wrap modes and mip-mapping
            MURL_DECLARE_ENUM_VALUE(FEATURE, FULL_NON_POWER_OF_TWO_FRAMEBUFFERS)

            /// Support for rendering to a 2D color texture (always available).
            MURL_DECLARE_ENUM_VALUE(FEATURE, FRAMEBUFFER_FLAT_COLOR_TEXTURES)
            /// Support for rendering to a 2D depth texture.
            MURL_DECLARE_ENUM_VALUE(FEATURE, FRAMEBUFFER_FLAT_DEPTH_TEXTURES)
            /// Support for rendering to a 2D stencil texture.
            MURL_DECLARE_ENUM_VALUE(FEATURE, FRAMEBUFFER_FLAT_STENCIL_TEXTURES)

            /// Support for rendering to a cube map color texture (always available).
            MURL_DECLARE_ENUM_VALUE(FEATURE, FRAMEBUFFER_CUBE_MAP_COLOR_TEXTURES)
            /// Support for rendering to a cube map depth texture.
            MURL_DECLARE_ENUM_VALUE(FEATURE, FRAMEBUFFER_CUBE_MAP_DEPTH_TEXTURES)
            /// Support for rendering to a cube map stencil texture.
            MURL_DECLARE_ENUM_VALUE(FEATURE, FRAMEBUFFER_CUBE_MAP_STENCIL_TEXTURES)

            /// Support for rendering to a 3D color texture (always available).
            MURL_DECLARE_ENUM_VALUE(FEATURE, FRAMEBUFFER_VOLUME_COLOR_TEXTURES)
            /// Support for rendering to a 3D depth texture.
            MURL_DECLARE_ENUM_VALUE(FEATURE, FRAMEBUFFER_VOLUME_DEPTH_TEXTURES)
            /// Support for rendering to a 3D stencil texture.
            MURL_DECLARE_ENUM_VALUE(FEATURE, FRAMEBUFFER_VOLUME_STENCIL_TEXTURES)

            /// Mip-mapped frame buffer support.
            MURL_DECLARE_ENUM_VALUE(FEATURE, FRAMEBUFFER_MIP_MAPS)

            /// At most 1 framebuffer color texture target.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_FRAMEBUFFER_COLOR_TEXTURE_COUNT_1)
            /// At most 2 framebuffer color texture targets.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_FRAMEBUFFER_COLOR_TEXTURE_COUNT_2)
            /// At most 4 framebuffer color texture targets.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_FRAMEBUFFER_COLOR_TEXTURE_COUNT_4)
            /// At most 8 framebuffer color texture targets.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_FRAMEBUFFER_COLOR_TEXTURE_COUNT_8)
            /// At most 16 framebuffer color texture targets.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_FRAMEBUFFER_COLOR_TEXTURE_COUNT_16)

            /// Support for rendering to a 2D color array texture.
            MURL_DECLARE_ENUM_VALUE(FEATURE, FRAMEBUFFER_FLAT_ARRAY_COLOR_TEXTURES)
            /// Support for rendering to a 2D depth array texture.
            MURL_DECLARE_ENUM_VALUE(FEATURE, FRAMEBUFFER_FLAT_ARRAY_DEPTH_TEXTURES)
            /// Support for rendering to a 2D stencil array texture.
            MURL_DECLARE_ENUM_VALUE(FEATURE, FRAMEBUFFER_FLAT_ARRAY_STENCIL_TEXTURES)

            /// Support for rendering to a cube map color array texture.
            MURL_DECLARE_ENUM_VALUE(FEATURE, FRAMEBUFFER_CUBE_MAP_ARRAY_COLOR_TEXTURES)
            /// Support for rendering to a cube map depth array texture.
            MURL_DECLARE_ENUM_VALUE(FEATURE, FRAMEBUFFER_CUBE_MAP_ARRAY_DEPTH_TEXTURES)
            /// Support for rendering to a cube map stencil array texture.
            MURL_DECLARE_ENUM_VALUE(FEATURE, FRAMEBUFFER_CUBE_MAP_ARRAY_STENCIL_TEXTURES)

            /// Support for rendering to a 3D color array texture.
            MURL_DECLARE_ENUM_VALUE(FEATURE, FRAMEBUFFER_VOLUME_ARRAY_COLOR_TEXTURES)
            /// Support for rendering to a 3D depth array texture.
            MURL_DECLARE_ENUM_VALUE(FEATURE, FRAMEBUFFER_VOLUME_ARRAY_DEPTH_TEXTURES)
            /// Support for rendering to a 3D stencil array texture.
            MURL_DECLARE_ENUM_VALUE(FEATURE, FRAMEBUFFER_VOLUME_ARRAY_STENCIL_TEXTURES)
            
            // === Texture compression ===
            FEATURE_GROUP_TEXTURE_COMPRESSION = 0x500,

            /// PVR texture compression.
            MURL_DECLARE_ENUM_VALUE(FEATURE, TEXTURE_COMPRESSION_PVRTC)
            /// ETC1 texture compression.
            MURL_DECLARE_ENUM_VALUE(FEATURE, TEXTURE_COMPRESSION_ETC1)
            /// ETC2 texture compression.
            MURL_DECLARE_ENUM_VALUE(FEATURE, TEXTURE_COMPRESSION_ETC2)
            /// ASTC texture compression.
            MURL_DECLARE_ENUM_VALUE(FEATURE, TEXTURE_COMPRESSION_ASTC)
            /// BC1 (a.k.a. DXTC1) texture compression.
            MURL_DECLARE_ENUM_VALUE(FEATURE, TEXTURE_COMPRESSION_BC1)
            /// BC2 (a.k.a. DXTC3) texture compression.
            MURL_DECLARE_ENUM_VALUE(FEATURE, TEXTURE_COMPRESSION_BC2)
            /// BC3 (a.k.a. DXTC5) texture compression.
            MURL_DECLARE_ENUM_VALUE(FEATURE, TEXTURE_COMPRESSION_BC3)
            /// BC4 texture compression.
            MURL_DECLARE_ENUM_VALUE(FEATURE, TEXTURE_COMPRESSION_BC4)
            /// BC5 texture compression.
            MURL_DECLARE_ENUM_VALUE(FEATURE, TEXTURE_COMPRESSION_BC5)
            /// BC6 texture compression.
            MURL_DECLARE_ENUM_VALUE(FEATURE, TEXTURE_COMPRESSION_BC6)
            /// BC7 texture compression.
            MURL_DECLARE_ENUM_VALUE(FEATURE, TEXTURE_COMPRESSION_BC7)

            // === Pixel formats ===
            FEATURE_GROUP_PIXEL_FORMAT = 0x600,

            /// Availability of IEnums::PIXEL_FORMAT_L8.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_L8)
            /// Availability of IEnums::PIXEL_FORMAT_A8.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_A8)
            /// Availability of IEnums::PIXEL_FORMAT_L8_A8.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_L8_A8)
            /// Availability of IEnums::PIXEL_FORMAT_R8.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_R8)
            /// Availability of IEnums::PIXEL_FORMAT_R8_G8.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_R8_G8)
            /// Availability of IEnums::PIXEL_FORMAT_R8_G8_B8.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_R8_G8_B8)
            /// Availability of IEnums::PIXEL_FORMAT_R5_G6_B5.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_R5_G6_B5)
            /// Availability of IEnums::PIXEL_FORMAT_R8_G8_B8_A8.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_R8_G8_B8_A8)
            /// Availability of IEnums::PIXEL_FORMAT_B8_G8_R8_A8.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_B8_G8_R8_A8)
            /// Availability of IEnums::PIXEL_FORMAT_A8_B8_G8_R8.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_A8_B8_G8_R8)
            /// Availability of IEnums::PIXEL_FORMAT_A8_R8_G8_B8.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_A8_R8_G8_B8)
            /// Availability of IEnums::PIXEL_FORMAT_R5_G5_B5_A1.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_R5_G5_B5_A1)
            /// Availability of IEnums::PIXEL_FORMAT_R4_G4_B4_A4.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_R4_G4_B4_A4)

            /// Availability of IEnums::PIXEL_FORMAT_SL8.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_SL8)
            /// Availability of IEnums::PIXEL_FORMAT_SL8_A8.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_SL8_A8)
            /// Availability of IEnums::PIXEL_FORMAT_SR8.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_SR8)
            /// Availability of IEnums::PIXEL_FORMAT_SR8_SG8.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_SR8_SG8)
            /// Availability of IEnums::PIXEL_FORMAT_SR8_SG8_SB8.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_SR8_SG8_SB8)
            /// Availability of IEnums::PIXEL_FORMAT_SR8_SG8_SB8_A8.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_SR8_SG8_SB8_A8)

            /// Availability of IEnums::PIXEL_FORMAT_LF16.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_LF16)
            /// Availability of IEnums::PIXEL_FORMAT_AF16.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_AF16)
            /// Availability of IEnums::PIXEL_FORMAT_LF16_AF16.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_LF16_AF16)
            /// Availability of IEnums::PIXEL_FORMAT_RF16.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_RF16)
            /// Availability of IEnums::PIXEL_FORMAT_RF16_GF16.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_RF16_GF16)
            /// Availability of IEnums::PIXEL_FORMAT_RF16_GF16_BF16.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_RF16_GF16_BF16)
            /// Availability of IEnums::PIXEL_FORMAT_RF16_GF16_BF16_AF16.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_RF16_GF16_BF16_AF16)

            /// Availability of IEnums::PIXEL_FORMAT_LF32.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_LF32)
            /// Availability of IEnums::PIXEL_FORMAT_AF32.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_AF32)
            /// Availability of IEnums::PIXEL_FORMAT_LF32_AF32.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_LF32_AF32)
            /// Availability of IEnums::PIXEL_FORMAT_RF32.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_RF32)
            /// Availability of IEnums::PIXEL_FORMAT_RF32_GF32.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_RF32_GF32)
            /// Availability of IEnums::PIXEL_FORMAT_RF32_GF32_BF32.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_RF32_GF32_BF32)
            /// Availability of IEnums::PIXEL_FORMAT_RF32_GF32_BF32_AF32.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_RF32_GF32_BF32_AF32)

            /// Availability of IEnums::PIXEL_FORMAT_RF11_GF11_BF10.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_RF11_GF11_BF10)

            /// Availability of IEnums::PIXEL_FORMAT_D16.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_D16)
            /// Availability of IEnums::PIXEL_FORMAT_D32.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_D32)

            /// Availability of IEnums::PIXEL_FORMAT_DF32.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_DF32)

            /// Availability of IEnums::PIXEL_FORMAT_S8.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_S8)

            /// Availability of IEnums::PIXEL_FORMAT_D24_S8.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_D24_S8)

            /// Availability of IEnums::PIXEL_FORMAT_DF32_S8.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_DF32_S8)

            /// Availability of IEnums::PIXEL_FORMAT_Y8.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_Y8)
            /// Availability of IEnums::PIXEL_FORMAT_U8.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_U8)
            /// Availability of IEnums::PIXEL_FORMAT_V8.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_V8)
            /// Availability of IEnums::PIXEL_FORMAT_U8_V8.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_U8_V8)
            /// Availability of IEnums::PIXEL_FORMAT_V8_U8.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_V8_U8)

            /// Availability of IEnums::PIXEL_FORMAT_PVRTC_RGB_4BPPV1.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_PVRTC_RGB_4BPPV1)
            /// Availability of IEnums::PIXEL_FORMAT_PVRTC_RGB_2BPPV1.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_PVRTC_RGB_2BPPV1)
            /// Availability of IEnums::PIXEL_FORMAT_PVRTC_RGBA_4BPPV1.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_PVRTC_RGBA_4BPPV1)
            /// Availability of IEnums::PIXEL_FORMAT_PVRTC_RGBA_2BPPV1.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_PVRTC_RGBA_2BPPV1)
            /// Availability of IEnums::PIXEL_FORMAT_PVRTC_SRGB_4BPPV1.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_PVRTC_SRGB_4BPPV1)
            /// Availability of IEnums::PIXEL_FORMAT_PVRTC_SRGB_2BPPV1.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_PVRTC_SRGB_2BPPV1)
            /// Availability of IEnums::PIXEL_FORMAT_PVRTC_SRGBA_4BPPV1.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_PVRTC_SRGBA_4BPPV1)
            /// Availability of IEnums::PIXEL_FORMAT_PVRTC_SRGBA_2BPPV1.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_PVRTC_SRGBA_2BPPV1)

            /// Availability of IEnums::PIXEL_FORMAT_ETC1_RGB_4BPP.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ETC1_RGB_4BPP)

            /// Availability of IEnums::PIXEL_FORMAT_ETC2_R11_4BPP.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ETC2_R11_4BPP)
            /// Availability of IEnums::PIXEL_FORMAT_ETC2_SIGNED_R11_4BPP.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ETC2_SIGNED_R11_4BPP)
            /// Availability of IEnums::PIXEL_FORMAT_ETC2_RG11_8BPP.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ETC2_RG11_8BPP)
            /// Availability of IEnums::PIXEL_FORMAT_ETC2_SIGNED_RG11_8BPP.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ETC2_SIGNED_RG11_8BPP)
            /// Availability of IEnums::PIXEL_FORMAT_ETC2_RGB8_4BPP.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ETC2_RGB8_4BPP)
            /// Availability of IEnums::PIXEL_FORMAT_ETC2_SRGB8_4BPP.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ETC2_SRGB8_4BPP)
            /// Availability of IEnums::PIXEL_FORMAT_ETC2_RGB8_PUNCHTHROUGH_ALPHA1_4BPP.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ETC2_RGB8_PUNCHTHROUGH_ALPHA1_4BPP)
            /// Availability of IEnums::PIXEL_FORMAT_ETC2_SRGB8_PUNCHTHROUGH_ALPHA1_4BPP.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ETC2_SRGB8_PUNCHTHROUGH_ALPHA1_4BPP)
            /// Availability of IEnums::PIXEL_FORMAT_ETC2_RGBA8_8BPP.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ETC2_RGBA8_8BPP)
            /// Availability of IEnums::PIXEL_FORMAT_ETC2_SRGB8_ALPHA8_8BPP.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ETC2_SRGB8_ALPHA8_8BPP)

            /// Availability of IEnums::PIXEL_FORMAT_ASTC_RGBA_4X4.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ASTC_RGBA_4X4)
            /// Availability of IEnums::PIXEL_FORMAT_ASTC_RGBA_5X4.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ASTC_RGBA_5X4)
            /// Availability of IEnums::PIXEL_FORMAT_ASTC_RGBA_5X5.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ASTC_RGBA_5X5)
            /// Availability of IEnums::PIXEL_FORMAT_ASTC_RGBA_6X5.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ASTC_RGBA_6X5)
            /// Availability of IEnums::PIXEL_FORMAT_ASTC_RGBA_6X6.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ASTC_RGBA_6X6)
            /// Availability of IEnums::PIXEL_FORMAT_ASTC_RGBA_8X5.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ASTC_RGBA_8X5)
            /// Availability of IEnums::PIXEL_FORMAT_ASTC_RGBA_8X6.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ASTC_RGBA_8X6)
            /// Availability of IEnums::PIXEL_FORMAT_ASTC_RGBA_8X8.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ASTC_RGBA_8X8)
            /// Availability of IEnums::PIXEL_FORMAT_ASTC_RGBA_10X5.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ASTC_RGBA_10X5)
            /// Availability of IEnums::PIXEL_FORMAT_ASTC_RGBA_10X6.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ASTC_RGBA_10X6)
            /// Availability of IEnums::PIXEL_FORMAT_ASTC_RGBA_10X8.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ASTC_RGBA_10X8)
            /// Availability of IEnums::PIXEL_FORMAT_ASTC_RGBA_10X10.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ASTC_RGBA_10X10)
            /// Availability of IEnums::PIXEL_FORMAT_ASTC_RGBA_12X10.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ASTC_RGBA_12X10)
            /// Availability of IEnums::PIXEL_FORMAT_ASTC_RGBA_12X12.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ASTC_RGBA_12X12)

            /// Availability of IEnums::PIXEL_FORMAT_ASTC_SRGB8_ALPHA8_4X4.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ASTC_SRGB8_ALPHA8_4X4)
            /// Availability of IEnums::PIXEL_FORMAT_ASTC_SRGB8_ALPHA8_5X4.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ASTC_SRGB8_ALPHA8_5X4)
            /// Availability of IEnums::PIXEL_FORMAT_ASTC_SRGB8_ALPHA8_5X5.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ASTC_SRGB8_ALPHA8_5X5)
            /// Availability of IEnums::PIXEL_FORMAT_ASTC_SRGB8_ALPHA8_6X5.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ASTC_SRGB8_ALPHA8_6X5)
            /// Availability of IEnums::PIXEL_FORMAT_ASTC_SRGB8_ALPHA8_6X6.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ASTC_SRGB8_ALPHA8_6X6)
            /// Availability of IEnums::PIXEL_FORMAT_ASTC_SRGB8_ALPHA8_8X5.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ASTC_SRGB8_ALPHA8_8X5)
            /// Availability of IEnums::PIXEL_FORMAT_ASTC_SRGB8_ALPHA8_8X6.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ASTC_SRGB8_ALPHA8_8X6)
            /// Availability of IEnums::PIXEL_FORMAT_ASTC_SRGB8_ALPHA8_8X8.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ASTC_SRGB8_ALPHA8_8X8)
            /// Availability of IEnums::PIXEL_FORMAT_ASTC_SRGB8_ALPHA8_10X5.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ASTC_SRGB8_ALPHA8_10X5)
            /// Availability of IEnums::PIXEL_FORMAT_ASTC_SRGB8_ALPHA8_10X6.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ASTC_SRGB8_ALPHA8_10X6)
            /// Availability of IEnums::PIXEL_FORMAT_ASTC_SRGB8_ALPHA8_10X8.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ASTC_SRGB8_ALPHA8_10X8)
            /// Availability of IEnums::PIXEL_FORMAT_ASTC_SRGB8_ALPHA8_10X10.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ASTC_SRGB8_ALPHA8_10X10)
            /// Availability of IEnums::PIXEL_FORMAT_ASTC_SRGB8_ALPHA8_12X10.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ASTC_SRGB8_ALPHA8_12X10)
            /// Availability of IEnums::PIXEL_FORMAT_ASTC_SRGB8_ALPHA8_12X12.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ASTC_SRGB8_ALPHA8_12X12)

            /// Availability of IEnums::PIXEL_FORMAT_ASTC_HDR_RGBA_4X4.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ASTC_HDR_RGBA_4X4)
            /// Availability of IEnums::PIXEL_FORMAT_ASTC_HDR_RGBA_5X4.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ASTC_HDR_RGBA_5X4)
            /// Availability of IEnums::PIXEL_FORMAT_ASTC_HDR_RGBA_5X5.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ASTC_HDR_RGBA_5X5)
            /// Availability of IEnums::PIXEL_FORMAT_ASTC_HDR_RGBA_6X5.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ASTC_HDR_RGBA_6X5)
            /// Availability of IEnums::PIXEL_FORMAT_ASTC_HDR_RGBA_6X6.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ASTC_HDR_RGBA_6X6)
            /// Availability of IEnums::PIXEL_FORMAT_ASTC_HDR_RGBA_8X5.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ASTC_HDR_RGBA_8X5)
            /// Availability of IEnums::PIXEL_FORMAT_ASTC_HDR_RGBA_8X6.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ASTC_HDR_RGBA_8X6)
            /// Availability of IEnums::PIXEL_FORMAT_ASTC_HDR_RGBA_8X8.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ASTC_HDR_RGBA_8X8)
            /// Availability of IEnums::PIXEL_FORMAT_ASTC_HDR_RGBA_10X5.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ASTC_HDR_RGBA_10X5)
            /// Availability of IEnums::PIXEL_FORMAT_ASTC_HDR_RGBA_10X6.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ASTC_HDR_RGBA_10X6)
            /// Availability of IEnums::PIXEL_FORMAT_ASTC_HDR_RGBA_10X8.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ASTC_HDR_RGBA_10X8)
            /// Availability of IEnums::PIXEL_FORMAT_ASTC_HDR_RGBA_10X10.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ASTC_HDR_RGBA_10X10)
            /// Availability of IEnums::PIXEL_FORMAT_ASTC_HDR_RGBA_12X10.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ASTC_HDR_RGBA_12X10)
            /// Availability of IEnums::PIXEL_FORMAT_ASTC_HDR_RGBA_12X12.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_ASTC_HDR_RGBA_12X12)

            /// Availability of IEnums::PIXEL_FORMAT_BC1_RGB_4BPP.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_BC1_RGB_4BPP)
            /// Availability of IEnums::PIXEL_FORMAT_BC1_SRGB_4BPP.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_BC1_SRGB_4BPP)
            /// Availability of IEnums::PIXEL_FORMAT_BC1_RGBA_4BPP.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_BC1_RGBA_4BPP)
            /// Availability of IEnums::PIXEL_FORMAT_BC1_SRGBA_4BPP.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_BC1_SRGBA_4BPP)
            /// Availability of IEnums::PIXEL_FORMAT_BC2_RGBA_8BPP.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_BC2_RGBA_8BPP)
            /// Availability of IEnums::PIXEL_FORMAT_BC2_SRGBA_8BPP.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_BC2_SRGBA_8BPP)
            /// Availability of IEnums::PIXEL_FORMAT_BC3_RGBA_8BPP.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_BC3_RGBA_8BPP)
            /// Availability of IEnums::PIXEL_FORMAT_BC3_SRGBA_8BPP.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_BC3_SRGBA_8BPP)
            /// Availability of IEnums::PIXEL_FORMAT_BC4_R_4BPP.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_BC4_R_4BPP)
            /// Availability of IEnums::PIXEL_FORMAT_BC5_RG_8BPP.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_BC5_RG_8BPP)
            /// Availability of IEnums::PIXEL_FORMAT_BC6_RGB_SF_8BPP.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_BC6_RGB_SF_8BPP)
            /// Availability of IEnums::PIXEL_FORMAT_BC6_RGB_UF_8BPP.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_BC6_RGB_UF_8BPP)
            /// Availability of IEnums::PIXEL_FORMAT_BC7_RGBA_8BPP.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_BC7_RGBA_8BPP)
            /// Availability of IEnums::PIXEL_FORMAT_BC7_SRGBA_8BPP.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_BC7_SRGBA_8BPP)

            /// Availability of IEnums::PIXEL_FORMAT_RGTC_R_U_4BPP.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_RGTC_R_U_4BPP)
            /// Availability of IEnums::PIXEL_FORMAT_RGTC_R_S_4BPP.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_RGTC_R_S_4BPP)
            /// Availability of IEnums::PIXEL_FORMAT_RGTC_RG_U_8BPP.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_RGTC_RG_U_8BPP)
            /// Availability of IEnums::PIXEL_FORMAT_RGTC_RG_S_8BPP.
            MURL_DECLARE_ENUM_VALUE(FEATURE, PIXEL_FORMAT_RGTC_RG_S_8BPP)

            // === Depth buffer formats ===
            FEATURE_GROUP_DEPTH_BUFFER_FORMAT = 0x700,

            /// Availability of IEnums::DEPTH_BUFFER_FORMAT_GENERIC.
            MURL_DECLARE_ENUM_VALUE(FEATURE, DEPTH_BUFFER_FORMAT_GENERIC)

            /// Availability of IEnums::DEPTH_BUFFER_FORMAT_D16.
            MURL_DECLARE_ENUM_VALUE(FEATURE, DEPTH_BUFFER_FORMAT_D16)
            /// Availability of IEnums::DEPTH_BUFFER_FORMAT_D24.
            MURL_DECLARE_ENUM_VALUE(FEATURE, DEPTH_BUFFER_FORMAT_D24)
            /// Availability of IEnums::DEPTH_BUFFER_FORMAT_D32.
            MURL_DECLARE_ENUM_VALUE(FEATURE, DEPTH_BUFFER_FORMAT_D32)
            /// Availability of IEnums::DEPTH_BUFFER_FORMAT_DF32.
            MURL_DECLARE_ENUM_VALUE(FEATURE, DEPTH_BUFFER_FORMAT_DF32)
            /// Availability of IEnums::DEPTH_BUFFER_FORMAT_D24_S8.
            MURL_DECLARE_ENUM_VALUE(FEATURE, DEPTH_BUFFER_FORMAT_D24_S8)
            /// Availability of IEnums::DEPTH_BUFFER_FORMAT_DF32_S8.
            MURL_DECLARE_ENUM_VALUE(FEATURE, DEPTH_BUFFER_FORMAT_DF32_S8)

            // === Stencil buffer formats ===
            FEATURE_GROUP_STENCIL_BUFFER_FORMAT = 0x800,

            /// Availability of IEnums::STENCIL_BUFFER_FORMAT_GENERIC.
            MURL_DECLARE_ENUM_VALUE(FEATURE, STENCIL_BUFFER_FORMAT_GENERIC)

            /// Availability of IEnums::STENCIL_BUFFER_FORMAT_S8.
            MURL_DECLARE_ENUM_VALUE(FEATURE, STENCIL_BUFFER_FORMAT_S8)
            /// Availability of IEnums::STENCIL_BUFFER_FORMAT_D24_S8.
            MURL_DECLARE_ENUM_VALUE(FEATURE, STENCIL_BUFFER_FORMAT_D24_S8)
            /// Availability of IEnums::STENCIL_BUFFER_FORMAT_DF32_S8.
            MURL_DECLARE_ENUM_VALUE(FEATURE, STENCIL_BUFFER_FORMAT_DF32_S8)

            // === GPU program related ===
            FEATURE_GROUP_SHADER = 0x900,

            /// Vertex shader programs.
            MURL_DECLARE_ENUM_VALUE(FEATURE, VERTEX_SHADERS)
            /// Fragment (pixel) shader programs.
            MURL_DECLARE_ENUM_VALUE(FEATURE, FRAGMENT_SHADERS)
            /// Geometry shader programs.
            MURL_DECLARE_ENUM_VALUE(FEATURE, GEOMETRY_SHADERS)
            /// Geometry shader programs.
            MURL_DECLARE_ENUM_VALUE(FEATURE, DOMAIN_SHADERS)
            /// Geometry shader programs.
            MURL_DECLARE_ENUM_VALUE(FEATURE, HULL_SHADERS)

            /// Allows the vertex shader to access a texture.
            MURL_DECLARE_ENUM_VALUE(FEATURE, VERTEX_SHADER_TEXTURE_ACCESS)
            /// LOD texture access from (fragment) shaders
            MURL_DECLARE_ENUM_VALUE(FEATURE, FRAGMENT_SHADER_TEXTURE_LOD)

            /// Instanced rendering support.
            MURL_DECLARE_ENUM_VALUE(FEATURE, INSTANCED_RENDERING)
            /// Feedback buffer support.
            MURL_DECLARE_ENUM_VALUE(FEATURE, FEEDBACK_BUFFERS)
            /// Occlusion query support.
            MURL_DECLARE_ENUM_VALUE(FEATURE, OCCLUSION_QUERIES)

            /// At most 1 vertex attribute available in a vertex shader.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_VERTEX_SHADER_ATTRIBUTE_COUNT_1)
            /// At most 2 vertex attributes available in a vertex shader.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_VERTEX_SHADER_ATTRIBUTE_COUNT_2)
            /// At most 4 vertex attributes available in a vertex shader.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_VERTEX_SHADER_ATTRIBUTE_COUNT_4)
            /// At most 8 vertex attributes available in a vertex shader.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_VERTEX_SHADER_ATTRIBUTE_COUNT_8)
            /// At most 16 vertex attributes available in a vertex shader.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_VERTEX_SHADER_ATTRIBUTE_COUNT_16)
            /// At most 32 vertex attributes available in a vertex shader.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_VERTEX_SHADER_ATTRIBUTE_COUNT_32)
            /// At most 64 vertex attributes available in a vertex shader.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_VERTEX_SHADER_ATTRIBUTE_COUNT_64)

            /// At most 16 4-component uniform vectors available in a vertex shader.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_VERTEX_SHADER_UNIFORM_VECTOR_COUNT_16)
            /// At most 32 4-component uniform vectors available in a vertex shader.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_VERTEX_SHADER_UNIFORM_VECTOR_COUNT_32)
            /// At most 64 4-component uniform vectors available in a vertex shader.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_VERTEX_SHADER_UNIFORM_VECTOR_COUNT_64)
            /// At most 128 4-component uniform vectors available in a vertex shader.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_VERTEX_SHADER_UNIFORM_VECTOR_COUNT_128)
            /// At most 256 4-component uniform vectors available in a vertex shader.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_VERTEX_SHADER_UNIFORM_VECTOR_COUNT_256)
            /// At most 512 4-component uniform vectors available in a vertex shader.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_VERTEX_SHADER_UNIFORM_VECTOR_COUNT_512)
            /// At most 1024 4-component uniform vectors available in a vertex shader.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_VERTEX_SHADER_UNIFORM_VECTOR_COUNT_1024)

            /// At most 1 texture unit available to be sampled in a vertex shader.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_VERTEX_SHADER_TEXTURE_UNIT_COUNT_1)
            /// At most 2 texture units available to be sampled in a vertex shader.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_VERTEX_SHADER_TEXTURE_UNIT_COUNT_2)
            /// At most 4 texture units available to be sampled in a vertex shader.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_VERTEX_SHADER_TEXTURE_UNIT_COUNT_4)
            /// At most 8 texture units available to be sampled in a vertex shader.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_VERTEX_SHADER_TEXTURE_UNIT_COUNT_8)
            /// At most 16 texture units available to be sampled in a vertex shader.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_VERTEX_SHADER_TEXTURE_UNIT_COUNT_16)
            /// At most 32 texture units available to be sampled in a vertex shader.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_VERTEX_SHADER_TEXTURE_UNIT_COUNT_32)
            /// At most 64 texture units available to be sampled in a vertex shader.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_VERTEX_SHADER_TEXTURE_UNIT_COUNT_64)

            /// At most 16 4-component uniform vectors available in a fragment shader.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_FRAGMENT_SHADER_UNIFORM_VECTOR_COUNT_16)
            /// At most 32 4-component uniform vectors available in a fragment shader.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_FRAGMENT_SHADER_UNIFORM_VECTOR_COUNT_32)
            /// At most 64 4-component uniform vectors available in a fragment shader.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_FRAGMENT_SHADER_UNIFORM_VECTOR_COUNT_64)
            /// At most 128 4-component uniform vectors available in a fragment shader.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_FRAGMENT_SHADER_UNIFORM_VECTOR_COUNT_128)
            /// At most 256 4-component uniform vectors available in a fragment shader.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_FRAGMENT_SHADER_UNIFORM_VECTOR_COUNT_256)
            /// At most 512 4-component uniform vectors available in a fragment shader.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_FRAGMENT_SHADER_UNIFORM_VECTOR_COUNT_512)
            /// At most 1024 4-component uniform vectors available in a fragment shader.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_FRAGMENT_SHADER_UNIFORM_VECTOR_COUNT_1024)

            /// At most 1 texture unit available to be sampled in a fragment shader.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_FRAGMENT_SHADER_TEXTURE_UNIT_COUNT_1)
            /// At most 2 texture units available to be sampled in a fragment shader.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_FRAGMENT_SHADER_TEXTURE_UNIT_COUNT_2)
            /// At most 4 texture units available to be sampled in a fragment shader.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_FRAGMENT_SHADER_TEXTURE_UNIT_COUNT_4)
            /// At most 8 texture units available to be sampled in a fragment shader.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_FRAGMENT_SHADER_TEXTURE_UNIT_COUNT_8)
            /// At most 16 texture units available to be sampled in a fragment shader.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_FRAGMENT_SHADER_TEXTURE_UNIT_COUNT_16)
            /// At most 32 texture units available to be sampled in a fragment shader.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_FRAGMENT_SHADER_TEXTURE_UNIT_COUNT_32)
            /// At most 64 texture units available to be sampled in a fragment shader.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_FRAGMENT_SHADER_TEXTURE_UNIT_COUNT_64)

            /// At most 8 4-component varing vectors available between vertex and fragment shader.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_VERTEX_FRAGMENT_SHADER_VARYING_VECTOR_COUNT_8)
            /// At most 16 4-component varing vectors available between vertex and fragment shader.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_VERTEX_FRAGMENT_SHADER_VARYING_VECTOR_COUNT_16)
            /// At most 32 4-component varing vectors available between vertex and fragment shader.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_VERTEX_FRAGMENT_SHADER_VARYING_VECTOR_COUNT_32)
            /// At most 64 4-component varing vectors available between vertex and fragment shader.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_VERTEX_FRAGMENT_SHADER_VARYING_VECTOR_COUNT_64)
            /// At most 128 4-component varing vectors available between vertex and fragment shader.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_VERTEX_FRAGMENT_SHADER_VARYING_VECTOR_COUNT_128)
            /// At most 256 4-component varing vectors available between vertex and fragment shader.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_VERTEX_FRAGMENT_SHADER_VARYING_VECTOR_COUNT_256)
            /// At most 512 4-component varing vectors available between vertex and fragment shader.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_VERTEX_FRAGMENT_SHADER_VARYING_VECTOR_COUNT_512)
            /// At most 1024 4-component varing vectors available between vertex and fragment shader.
            MURL_DECLARE_ENUM_VALUE(FEATURE, MAX_VERTEX_FRAGMENT_SHADER_VARYING_VECTOR_COUNT_1024)

            // Support for shadow samplers in fragment shader
            MURL_DECLARE_ENUM_VALUE(FEATURE, FRAGMENT_SHADER_SHADOW_SAMPLERS)

            // === Color buffer formats ===
            FEATURE_GROUP_COLOR_BUFFER_FORMAT = 0xa00,

            /// Availability of IEnums::COLOR_BUFFER_FORMAT_GENERIC.
            MURL_DECLARE_ENUM_VALUE(FEATURE, COLOR_BUFFER_FORMAT_GENERIC)

            /// Availability of IEnums::COLOR_BUFFER_FORMAT_R8.
            MURL_DECLARE_ENUM_VALUE(FEATURE, COLOR_BUFFER_FORMAT_R8)
            /// Availability of IEnums::COLOR_BUFFER_FORMAT_R8_G8.
            MURL_DECLARE_ENUM_VALUE(FEATURE, COLOR_BUFFER_FORMAT_R8_G8)
            /// Availability of IEnums::COLOR_BUFFER_FORMAT_R8_G8_B8.
            MURL_DECLARE_ENUM_VALUE(FEATURE, COLOR_BUFFER_FORMAT_R8_G8_B8)
            /// Availability of IEnums::COLOR_BUFFER_FORMAT_R5_G6_B5.
            MURL_DECLARE_ENUM_VALUE(FEATURE, COLOR_BUFFER_FORMAT_R5_G6_B5)
            /// Availability of IEnums::COLOR_BUFFER_FORMAT_R8_G8_B8_A8.
            MURL_DECLARE_ENUM_VALUE(FEATURE, COLOR_BUFFER_FORMAT_R8_G8_B8_A8)
            /// Availability of IEnums::COLOR_BUFFER_FORMAT_R5_G5_B5_A1.
            MURL_DECLARE_ENUM_VALUE(FEATURE, COLOR_BUFFER_FORMAT_R5_G5_B5_A1)
            /// Availability of IEnums::COLOR_BUFFER_FORMAT_R4_G4_B4_A4.
            MURL_DECLARE_ENUM_VALUE(FEATURE, COLOR_BUFFER_FORMAT_R4_G4_B4_A4)

            /// Availability of IEnums::COLOR_BUFFER_FORMAT_SR8.
            MURL_DECLARE_ENUM_VALUE(FEATURE, COLOR_BUFFER_FORMAT_SR8)
            /// Availability of IEnums::COLOR_BUFFER_FORMAT_SR8_SG8.
            MURL_DECLARE_ENUM_VALUE(FEATURE, COLOR_BUFFER_FORMAT_SR8_SG8)
            /// Availability of IEnums::COLOR_BUFFER_FORMAT_SR8_SG8_SB8.
            MURL_DECLARE_ENUM_VALUE(FEATURE, COLOR_BUFFER_FORMAT_SR8_SG8_SB8)
            /// Availability of IEnums::COLOR_BUFFER_FORMAT_SR8_SG8_SB8_A8.
            MURL_DECLARE_ENUM_VALUE(FEATURE, COLOR_BUFFER_FORMAT_SR8_SG8_SB8_A8)

            /// Availability of IEnums::COLOR_BUFFER_FORMAT_RF16.
            MURL_DECLARE_ENUM_VALUE(FEATURE, COLOR_BUFFER_FORMAT_RF16)
            /// Availability of IEnums::COLOR_BUFFER_FORMAT_RF16_GF16.
            MURL_DECLARE_ENUM_VALUE(FEATURE, COLOR_BUFFER_FORMAT_RF16_GF16)
            /// Availability of IEnums::COLOR_BUFFER_FORMAT_RF16_GF16_BF16.
            MURL_DECLARE_ENUM_VALUE(FEATURE, COLOR_BUFFER_FORMAT_RF16_GF16_BF16)
            /// Availability of IEnums::COLOR_BUFFER_FORMAT_RF16_GF16_BF16_AF16.
            MURL_DECLARE_ENUM_VALUE(FEATURE, COLOR_BUFFER_FORMAT_RF16_GF16_BF16_AF16)

            /// Availability of IEnums::COLOR_BUFFER_FORMAT_RF32.
            MURL_DECLARE_ENUM_VALUE(FEATURE, COLOR_BUFFER_FORMAT_RF32)
            /// Availability of IEnums::COLOR_BUFFER_FORMAT_RF32_GF32.
            MURL_DECLARE_ENUM_VALUE(FEATURE, COLOR_BUFFER_FORMAT_RF32_GF32)
            /// Availability of IEnums::COLOR_BUFFER_FORMAT_RF32_GF32_BF32.
            MURL_DECLARE_ENUM_VALUE(FEATURE, COLOR_BUFFER_FORMAT_RF32_GF32_BF32)
            /// Availability of IEnums::COLOR_BUFFER_FORMAT_RF32_GF32_BF32_AF32.
            MURL_DECLARE_ENUM_VALUE(FEATURE, COLOR_BUFFER_FORMAT_RF32_GF32_BF32_AF32)

            /// Availability of IEnums::COLOR_BUFFER_FORMAT_RF11_GF11_BF10.
            MURL_DECLARE_ENUM_VALUE(FEATURE, COLOR_BUFFER_FORMAT_RF11_GF11_BF10)

            NUM_FEATURES
        };
        MURL_DECLARE_ENUM_ACCESSOR(Feature)

        /**
         * @brief Available Video APIs.
         * Depending on the platform and build configuration, not all of these APIs may
         * be available at the same time.
         */
        enum VideoApi
        {
            /// Default Video API selected by the system
            MURL_DECLARE_ENUM_VALUE(VIDEO_API, DEFAULT)
            /// Dummy Video API
            MURL_DECLARE_ENUM_VALUE(VIDEO_API, DUMMY)
            /// OpenGL ES 1.1 API
            MURL_DECLARE_ENUM_VALUE(VIDEO_API, GLES11)
            /// OpenGL ES 2.0 API
            MURL_DECLARE_ENUM_VALUE(VIDEO_API, GLES20)
            /// Microsoft DirectX 9 API
            MURL_DECLARE_ENUM_VALUE(VIDEO_API, DX90)
            /// Microsoft DirectX 11 API
            MURL_DECLARE_ENUM_VALUE(VIDEO_API, DX111)
            /// OpenGL ES 3.0 API
            MURL_DECLARE_ENUM_VALUE(VIDEO_API, GLES30)
        };
        MURL_DECLARE_ENUM_ACCESSOR(VideoApi)

        /**
         * @brief Available Audio APIs.
         * Depending on the platform and build configuration, not all of these APIs may
         * be available at the same time.
         */
        enum AudioApi
        {
            /// Default Audio API selected by the system.
            MURL_DECLARE_ENUM_VALUE(AUDIO_API, DEFAULT)
            /// Dummy Audio API, does not produce any sound at all.
            MURL_DECLARE_ENUM_VALUE(AUDIO_API, DUMMY)
            /// OpenAL 1.1 API
            MURL_DECLARE_ENUM_VALUE(AUDIO_API, AL11)
            /// OpenSL ES 1.0 API
            MURL_DECLARE_ENUM_VALUE(AUDIO_API, SLES10)
            /// Microsoft DirectX 11 API
            MURL_DECLARE_ENUM_VALUE(AUDIO_API, DX11)
        };
        MURL_DECLARE_ENUM_ACCESSOR(AudioApi)

        /**
         * @brief Screen edge.
         * Screen edges are defined as a bit mask that can be OR'ed
         * together to represent multiple edges in one value.
         */
        enum ScreenEdge
        {
            /// No edge
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(SCREEN_EDGE, NONE, 0)

            /// Top edge
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(SCREEN_EDGE, TOP,    1 << 0)
            /// Left edge
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(SCREEN_EDGE, LEFT,   1 << 1)
            /// Bottom edge
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(SCREEN_EDGE, BOTTOM, 1 << 2)
            /// Right edge
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(SCREEN_EDGE, RIGHT,  1 << 3)

            NUM_SCREEN_EDGES         = 4,

            SCREEN_EDGE_MASK         = (1 << NUM_SCREEN_EDGES) - 1
        };
        MURL_DECLARE_ENUM_ACCESSOR(ScreenEdge)

        /**
         * @brief Data type for combined screen edges,
         *  see <a href="#pub-static-attribs">Static Public Attributes</a>
         */
        typedef UInt32 CombinedScreenEdges;
        /// All edges
        const CombinedScreenEdges SCREEN_EDGES_ALL = SCREEN_EDGE_TOP | SCREEN_EDGE_LEFT | SCREEN_EDGE_BOTTOM | SCREEN_EDGE_RIGHT;
        MURL_DECLARE_ENUM_ACCESSOR(CombinedScreenEdges)

        /**
         * @brief Relative orientations.
         * The relative orientation values are defined as a bit mask that can be OR'ed
         * together to represent multiple orientations in one value.
         */
        enum Orientation
        {
            /// Default orientation (equals ORIENTATION_ROTATE_0)
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(ORIENTATION, DEFAULT, 0)

            /// Rotated 0° orientation (not rotated)
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(ORIENTATION, ROTATE_0,      1 << 0)
            /// Rotated 90° in clockwise direction
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(ORIENTATION, ROTATE_90_CW,  1 << 1)
            /// Rotated 180° orientation
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(ORIENTATION, ROTATE_180,    1 << 2)
            /// Rotated 90° in counter-clockwise direction
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(ORIENTATION, ROTATE_90_CCW, 1 << 3)

            NUM_ORIENTATIONS         = 4,

            ORIENTATION_MASK         = (1 << NUM_ORIENTATIONS) - 1
        };
        MURL_DECLARE_ENUM_ACCESSOR(Orientation)

        /**
         * @brief Data type for combined relative orientations,
         *  see <a href="#pub-static-attribs">Static Public Attributes</a>
         */
        typedef UInt32 CombinedOrientation;
        /// Combined relative orientations for all orientations.
        const CombinedOrientation ORIENTATIONS_ALL = ORIENTATION_ROTATE_0 | ORIENTATION_ROTATE_180 | ORIENTATION_ROTATE_90_CW | ORIENTATION_ROTATE_90_CCW;
        MURL_DECLARE_ENUM_ACCESSOR(CombinedOrientation)

        /**
         * @brief Absolute screen orientations.
         * The absolute screen orientation values are defined as a bit mask that can be OR'ed
         * together to represent multiple orientations in one value.
         */
        enum ScreenOrientation
        {
            /// Default orientation (equals SCREEN_ORIENTATION_PORTRAIT_1)
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(SCREEN_ORIENTATION, DEFAULT, 0)

            /// Regular portrait orientation
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(SCREEN_ORIENTATION, PORTRAIT_1,  1 << 0)
            /// Regular landscape orientation
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(SCREEN_ORIENTATION, LANDSCAPE_1, 1 << 1)
            /// Upside-down portrait orientation
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(SCREEN_ORIENTATION, PORTRAIT_2,  1 << 2)
            /// Upside-down landscape orientation
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(SCREEN_ORIENTATION, LANDSCAPE_2, 1 << 3)

            NUM_SCREEN_ORIENTATIONS         = 4,

            SCREEN_ORIENTATION_MASK         = (1 << NUM_SCREEN_ORIENTATIONS) - 1
        };
        MURL_DECLARE_ENUM_ACCESSOR(ScreenOrientation)

        /**
         * @brief Get the relative orientation of two screen orientations.
         * @param orientation1 The first screen orientation.
         * @param orientation2 The second screen orientation.
         * @return The relative orientation of the screen orientations.
         */
        Orientation GetRelativeOrientation(ScreenOrientation orientation1, ScreenOrientation orientation2);

        /**
         * @brief Data type for combined absolute screen orientations,
         *  see <a href="#pub-static-attribs">Static Public Attributes</a>
         */
        typedef UInt32 CombinedScreenOrientation;
        /// Combined absolute screen orientations for portrait orientations.
        const CombinedScreenOrientation SCREEN_ORIENTATIONS_PORTRAIT  = SCREEN_ORIENTATION_PORTRAIT_1 | SCREEN_ORIENTATION_PORTRAIT_2;
        /// Combined absolute screen orientations for landscape orientations.
        const CombinedScreenOrientation SCREEN_ORIENTATIONS_LANDSCAPE = SCREEN_ORIENTATION_LANDSCAPE_1 | SCREEN_ORIENTATION_LANDSCAPE_2;
        /// Combined absolute screen orientations for all orientations.
        const CombinedScreenOrientation SCREEN_ORIENTATIONS_ALL =(SCREEN_ORIENTATION_PORTRAIT_1 | SCREEN_ORIENTATION_LANDSCAPE_1 |
                                                                  SCREEN_ORIENTATION_PORTRAIT_2 | SCREEN_ORIENTATION_LANDSCAPE_2);
        MURL_DECLARE_ENUM_ACCESSOR(CombinedScreenOrientation)

        /**
         * @brief Sensor orientations.
         * The sensor orientations are defined with respect to the device's screen orientation.
         */
        enum SensorOrientation
        {
            /// Unknown orientation, when the device is not able to report the actual one.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(SENSOR_ORIENTATION, UNKNOWN, 0)

            /// Device oriented vertically, home button on the bottom
            MURL_DECLARE_ENUM_VALUE(SENSOR_ORIENTATION, PORTRAIT_1)
            /// Device oriented vertically, home button on the top
            MURL_DECLARE_ENUM_VALUE(SENSOR_ORIENTATION, PORTRAIT_2)
            /// Device oriented horizontally, home button on the right
            MURL_DECLARE_ENUM_VALUE(SENSOR_ORIENTATION, LANDSCAPE_1)
            /// Device oriented horizontally, home button on the left
            MURL_DECLARE_ENUM_VALUE(SENSOR_ORIENTATION, LANDSCAPE_2)
            /// Device oriented flat, face up.
            /// Android devices always report face up even if device is face down.
            /// Some devices (e.g. Galaxy Tab) do report landscape!?
            MURL_DECLARE_ENUM_VALUE(SENSOR_ORIENTATION, FACE_UP)
            /// Device oriented flat, face down.
            /// Not supported by Android devices.
            MURL_DECLARE_ENUM_VALUE(SENSOR_ORIENTATION, FACE_DOWN)

            NUM_SENSOR_ORIENTATIONS
        };

        /**
         * @brief The engine's run loop mode.
         */
        enum RunLoopMode
        {
            /// The default run loop mode.
            MURL_DECLARE_ENUM_VALUE(RUN_LOOP_MODE, DEFAULT)
            /// Interleaved processing of logic and rendering.
            MURL_DECLARE_ENUM_VALUE(RUN_LOOP_MODE, INTERLEAVED)
            /// Sequential processing of logic and rendering.
            MURL_DECLARE_ENUM_VALUE(RUN_LOOP_MODE, SEQUENTIAL)
        };
        MURL_DECLARE_ENUM_ACCESSOR(RunLoopMode)

        /**
         * @brief Run loop triggers.
         * Run loop triggers act as a hint to the platform front-end for when to perform
         * an additional execution cycle of the engine's main loop, e.g. when a key or
         * mouse button is pressed or released.
         * Currently this only has effect when running in a web browser (via the Emscripten
         * platform). Here it is usually necessary to enable one or more of these hints when
         * a security-relevant action should be triggered from logic code (such as switching
         * to full-screen mode, locking the mouse pointer or opening an external browser
         * window), as these actions are normally only carried out when explicitly triggered
         * during the execution of a JavaScript key or mouse click event.
         * Note that these additional run loop cycles may affect the actual display frame rate;
         * therefore these hints can be dynamically enabled/disabled via
         * IAppConfiguration::SetRunLoopTriggers() to provide a stutter-free frame rate for
         * e.g. a keyboard-controlled action game.
         */
        enum RunLoopTrigger
        {
            /// No trigger.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(RUN_LOOP_TRIGGER, NONE,                  0)

            /// Trigger the run loop when a key down event occurs.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(RUN_LOOP_TRIGGER, KEY_DOWN,              1 << 0)
            /// Trigger the run loop when a key up event occurs.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(RUN_LOOP_TRIGGER, KEY_UP,                1 << 1)
            /// Trigger the run loop when a mouse down event occurs.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(RUN_LOOP_TRIGGER, MOUSE_DOWN,            1 << 2)
            /// Trigger the run loop when a mouse up event occurs.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(RUN_LOOP_TRIGGER, MOUSE_UP,              1 << 3)

            /// All triggers.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(RUN_LOOP_TRIGGER, ALL,                   0xffffffff)
        };
        MURL_DECLARE_ENUM_ACCESSOR(RunLoopTrigger)

        /**
         * @brief Data type for combined run loop triggers,
         */
        typedef UInt32 RunLoopTriggers;
        /// No triggers.
        const RunLoopTriggers RUN_LOOP_TRIGGERS_NONE = 0;
        /// All triggers.
        const RunLoopTriggers RUN_LOOP_TRIGGERS_ALL  = 0xffffffff;
        MURL_DECLARE_ENUM_ACCESSOR(RunLoopTriggers)

        /**
         * @brief Application run states.
         */
        enum AppRunState
        {
            /// Default state.
            MURL_DECLARE_ENUM_VALUE(APP_RUN_STATE, DEFAULT)
            /// Application is running.
            MURL_DECLARE_ENUM_VALUE(APP_RUN_STATE, RUNNING)
            /// Application is paused. The internal clock is halted, but output is still generated.
            MURL_DECLARE_ENUM_VALUE(APP_RUN_STATE, PAUSED)
            /// Application is suspended. Neither clock nor output are running.
            MURL_DECLARE_ENUM_VALUE(APP_RUN_STATE, SUSPENDED)
        };
        MURL_DECLARE_ENUM_ACCESSOR(AppRunState)

        /**
         * @brief Suspendable resource types.
         * When the app gets suspended, it can decide which type(s) of resources may be unloaded
         * to save memory. Note: upon resuming, all the previously suspended resources are
         * re-initialized by the engine, which may take a considerable amount of time. The values
         * of this enum are defined as bit fields, to be able to combine them together.
         */
        enum SuspendableResource
        {
            /// No suspendable resources.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(SUSPENDABLE_RESOURCE, NONE,                  0)
            /// Frame buffers from the video renderer.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(SUSPENDABLE_RESOURCE, VIDEO_FRAME_BUFFER,    1 << 0)
            /// Sample buffers from the audio renderer.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(SUSPENDABLE_RESOURCE, AUDIO_BUFFER,          1 << 8)
            /// Playable objects from the audio renderer.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(SUSPENDABLE_RESOURCE, AUDIO_PLAYABLE,        1 << 9)
            /// Other resources.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(SUSPENDABLE_RESOURCE, OTHER,                 1 << 31)
            /// All available resources.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(SUSPENDABLE_RESOURCE, ALL,                   0xffffffff)
        };
        MURL_DECLARE_ENUM_ACCESSOR(SuspendableResource)

        /**
         * @brief Data type for combined suspendable resource types,
         *  see <a href="#pub-static-attribs">Static Public Attributes</a>
         */
        typedef UInt32 SuspendableResources;
        /// Combined suspendable resource types for no resources.
        const SuspendableResources SUSPENDABLE_RESOURCES_NONE = 0;
        /// Combined suspendable resource types for all resources.
        const SuspendableResources SUSPENDABLE_RESOURCES_ALL  = 0xffffffff;
        MURL_DECLARE_ENUM_ACCESSOR(SuspendableResources)

        /**
         * @brief Package types.
         */
        enum PackageType
        {
            /// Native package type (.murlpkg).
            MURL_DECLARE_ENUM_VALUE(PACKAGE_TYPE, NATIVE)
            /// XML package type (.murlres).
            MURL_DECLARE_ENUM_VALUE(PACKAGE_TYPE, XML)
            /// Custom package type.
            MURL_DECLARE_ENUM_VALUE(PACKAGE_TYPE, CUSTOM)

            NUM_PACKAGE_TYPES
        };
        MURL_DECLARE_ENUM_ACCESSOR(PackageType)

        /**
         * @brief Available categories for file access.
         */
        enum FileCategory
        {
            /// The default category.
            MURL_DECLARE_ENUM_VALUE(FILE_CATEGORY, DEFAULT)

            /// The root of the file system.
            MURL_DECLARE_ENUM_VALUE(FILE_CATEGORY, ROOT)
            /// The path where the application is residing.
            MURL_DECLARE_ENUM_VALUE(FILE_CATEGORY, APPLICATION)
            /// The current shell path at the time of starting the application.
            MURL_DECLARE_ENUM_VALUE(FILE_CATEGORY, CURRENT)
            /// The path to the application's resources.
            MURL_DECLARE_ENUM_VALUE(FILE_CATEGORY, RESOURCE)
            /// The shared user directory.
            MURL_DECLARE_ENUM_VALUE(FILE_CATEGORY, SHARED)
            /// The private user directory.
            MURL_DECLARE_ENUM_VALUE(FILE_CATEGORY, PRIVATE)
            /// The user's cache directory
            MURL_DECLARE_ENUM_VALUE(FILE_CATEGORY, CACHE)
            /// A temp directory
            MURL_DECLARE_ENUM_VALUE(FILE_CATEGORY, TEMPORARY)
            /// The path where accompanying shared libraries are residing, if available.
            MURL_DECLARE_ENUM_VALUE(FILE_CATEGORY, LIBRARY)

            NUM_FILE_CATEGORIES
        };
        MURL_DECLARE_ENUM_ACCESSOR(FileCategory)

        /**
         * @brief Available RGB pixel formats.
         */
        enum RgbPixelFormat
        {
            /// Default RGB pixel format
            MURL_DECLARE_ENUM_VALUE(RGB_PIXEL_FORMAT, DEFAULT)
            /// 24 bit RGB (8 bits per component)
            MURL_DECLARE_ENUM_VALUE(RGB_PIXEL_FORMAT, R8_G8_B8)
            /// 16 bit RGB (5 bits red, 6 bits green, 5 bits blue)
            MURL_DECLARE_ENUM_VALUE(RGB_PIXEL_FORMAT, R5_G6_B5)
        };
        MURL_DECLARE_ENUM_ACCESSOR(RgbPixelFormat)

        /**
         * @brief Available RGBA pixel formats.
         */
        enum RgbaPixelFormat
        {
            /// Default RGBA pixel format
            MURL_DECLARE_ENUM_VALUE(RGBA_PIXEL_FORMAT, DEFAULT)
            /// 32 bit integer RGBA, with 8 bits per component (always available).
            MURL_DECLARE_ENUM_VALUE(RGBA_PIXEL_FORMAT, R8_G8_B8_A8)
            /// 32 bit integer BGRA, with 8 bits per component (on certain platforms).
            MURL_DECLARE_ENUM_VALUE(RGBA_PIXEL_FORMAT, B8_G8_R8_A8)
            /// 32 bit integer ABGR, with 8 bits per component (on certain platforms).
            MURL_DECLARE_ENUM_VALUE(RGBA_PIXEL_FORMAT, A8_B8_G8_R8)
            /// 32 bit integer ARGB, with 8 bits per component (on certain platforms).
            MURL_DECLARE_ENUM_VALUE(RGBA_PIXEL_FORMAT, A8_R8_G8_B8)
            /// 16 bit RGBA (5 bits red, 5 bits green, 5 bits blue, 1 bit alpha)
            MURL_DECLARE_ENUM_VALUE(RGBA_PIXEL_FORMAT, R5_G5_B5_A1)
            /// 16 bit RGBA (4 bits per component)
            MURL_DECLARE_ENUM_VALUE(RGBA_PIXEL_FORMAT, R4_G4_B4_A4)
        };
        MURL_DECLARE_ENUM_ACCESSOR(RgbaPixelFormat)
        
        /** @} */
    }
}

#endif  // __MURL_I_ENUMS_CONFIGURATION_H__
