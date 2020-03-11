// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_I_MOTION_H__
#define __MURL_I_MOTION_H__

#include "murl_types.h"

namespace Murl
{
    /**
     * @ingroup MurlDeviceInterfaces
     * @interface IMotion
     * @brief The motion device interface.
     * Used by the platform to post events to the device.
     */
    class IMotion
    {
    public:
        /**
         * @brief Definition of event actions.
         */
        enum EventAction
        {
            /** No action. */
            EVENT_ACTION_NONE = 0,
            
            /** Motion has begun. */
            EVENT_ACTION_MOTION_BEGIN,
            /** Motion has ended. */
            EVENT_ACTION_MOTION_END,
            
            /** Motion is cancelled, e.g. cancelled by IOS if shaking too long. */
            EVENT_ACTION_CANCEL,
            
            NUM_EVENT_ACTIONS
        };
        
        /**
         * @brief Post the current motion state.
         * @param action The event action, see enum #EventAction.
         */
        virtual void PostEvent(EventAction action) = 0;
        
    protected:
        virtual ~IMotion() {}
    };
}

#endif  // __MURL_I_MOTION_H__
