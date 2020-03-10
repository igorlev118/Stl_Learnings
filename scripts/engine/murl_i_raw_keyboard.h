// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_I_RAW_KEYBOARD_H__
#define __MURL_I_RAW_KEYBOARD_H__

#include "murl_raw_key_codes.h"

namespace Murl
{
    /**
     * @ingroup MurlDeviceInterfaces
     * @interface IRawKeyboard
     * @brief The raw-keyboard device interface.
     * Used by the platform to post events to the device.
     */
    class IRawKeyboard
    {
    public:
        /**
         * @brief Definition of event actions.
         */
        enum EventAction
        {
            /** No action. */
            EVENT_ACTION_NONE = 0,
            
            /** The key is pressed. */
            EVENT_ACTION_KEY_DOWN,
            /** The key is released. */
            EVENT_ACTION_KEY_UP,
            
            /** Flush all key states to the up state.
             * This is useful in rare cases, e.g. if the platform is loosing
             * events when changing from window to full screen mode. */
            EVENT_ACTION_FLUSH,
            
            NUM_EVENT_ACTIONS
        };
        
        /**
         * @brief Post the current raw-key state.
         * @param action The event action, see enum #EventAction.
         * @param code The raw-key code.
         */
        virtual void PostEvent(EventAction action, RawKeyCode code) = 0;
        
    protected:
        virtual ~IRawKeyboard() {}
    };
}

#endif  // __MURL_I_RAW_KEYBOARD_H__
