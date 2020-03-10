// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_I_KEYBOARD_H__
#define __MURL_I_KEYBOARD_H__

#include "murl_string.h"

namespace Murl
{
    /**
     * @ingroup MurlDeviceInterfaces
     * @interface IKeyboard
     * @brief The keyboard device interface.
     * Used by the platform to post events to the device.
     */
    class IKeyboard
    {
    public:
        /**
         * @brief Post a keystroke.
         * @param utf8key The key in UTF8 representation.
         */
        virtual void PostEvent(const String& utf8key) = 0;
        
    protected:
        virtual ~IKeyboard() {}
    };
}

#endif  // __MURL_I_KEYBOARD_H__
