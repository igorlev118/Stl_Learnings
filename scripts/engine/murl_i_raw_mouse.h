// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_I_RAW_MOUSE_H__
#define __MURL_I_RAW_MOUSE_H__

#include "murl_types.h"

namespace Murl
{
    /**
     * @ingroup MurlDeviceInterfaces
     * @interface IRawMouse
     * @brief The raw-mouse device interface.
     * Used by the platform to post events to the device.
     */
    class IRawMouse
    {
    public:
        /**
         * @brief Definition of event actions.
         */
        enum EventAction
        {
            /** No action. */
            EVENT_ACTION_NONE = 0,
            
            /** Mouse position axis values. */
            EVENT_ACTION_MOUSE,
            /** Mouse wheel axis values. */
            EVENT_ACTION_WHEEL,
            
            NUM_EVENT_ACTIONS
        };
        
        /**
         * @brief Post the current mouse state.
         * @param action The event action, see enum #EventAction.
         * @param deltaX The mouse x-axis delta values.
         * @param deltaY The mouse y-axis delta values.
         */
        virtual void PostEvent(EventAction action, SInt32 deltaX, SInt32 deltaY) = 0;
        
    protected:
        virtual ~IRawMouse() {}
    };
}

#endif  // __MURL_I_RAW_MOUSE_H__
