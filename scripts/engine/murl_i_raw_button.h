// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_I_RAW_BUTTON_H__
#define __MURL_I_RAW_BUTTON_H__

#include "murl_raw_button_codes.h"

namespace Murl
{
    /**
     * @ingroup MurlDeviceInterfaces
     * @interface IRawButton
     * @brief The raw-button device interface.
     * Used by the platform to post events to the device.
     */
    class IRawButton
    {
    public:
        /**
         * @brief Definition of event actions.
         */
        enum EventAction
        {
            /** No action. */
            EVENT_ACTION_NONE = 0,
            
            /** The button is pressed. */
            EVENT_ACTION_BUTTON_DOWN,
            /** The button is released. */
            EVENT_ACTION_BUTTON_UP,
            
            /** Flush all button states to the up state.
             * This is useful in rare cases, e.g. if the platform is loosing
             * events when changing from window to full screen mode. */
            EVENT_ACTION_FLUSH,
            
            NUM_EVENT_ACTIONS
        };
        
        /**
         * @brief Post the current raw-button state.
         * @param action The event action, see enum #EventAction.
         * @param code The raw-button code.
         */
        virtual void PostEvent(EventAction action, RawButtonCode code) = 0;
        
    protected:
        virtual ~IRawButton() {}
    };
}

#endif  // __MURL_I_RAW_BUTTON_H__
