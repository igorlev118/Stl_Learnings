// Copyright 2010-2015 Spraylight

#ifndef __MURL_RAW_BUTTON_CODES_H__
#define __MURL_RAW_BUTTON_CODES_H__

#include "murl_enum.h"

namespace Murl
{
    /**
     * @addtogroup MurlDeviceEnumerations
     * @{
     */

    /**
     * @brief The raw-button codes enumeration.
     */
    enum RawButtonCode
    {
        /** @brief No button. */
        RAWBUTTON_NONE = 0,

        /** @brief The back button. */
        RAWBUTTON_BACK,
        /** @brief The menu button. */
        RAWBUTTON_MENU,
        /** @brief The select button. */
        RAWBUTTON_SELECT,
        /** @brief The play/pause button. */
        RAWBUTTON_PLAY_PAUSE,

        /** @brief The volume up button. */
        RAWBUTTON_VOLUME_UP,
        /** @brief The volume down button. */
        RAWBUTTON_VOLUME_DOWN,

        /** @brief The arrow up button. */
        RAWBUTTON_ARROW_UP,
        /** @brief The arrow down button. */
        RAWBUTTON_ARROW_DOWN,
        /** @brief The arrow left button. */
        RAWBUTTON_ARROW_LEFT,
        /** @brief The arrow right button. */
        RAWBUTTON_ARROW_RIGHT,

        NUM_RAWBUTTON_CODES
    };

    MURL_DECLARE_ENUM_ACCESSOR(RawButtonCode)

    /** @} */
}

#endif  // __MURL_RAW_BUTTON_CODES_H__
