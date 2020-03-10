// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_I_TOUCH_SCREEN_H__
#define __MURL_I_TOUCH_SCREEN_H__

#include "murl_types.h"

namespace Murl
{
    /**
     * @ingroup MurlDeviceInterfaces
     * @interface ITouchScreen
     * @brief The touch screen device interface.
     * Used by the platform to post events to the device.
     */
    class ITouchScreen
    {
    public:
        /**
         * @brief Definition of event actions.
         */
        enum EventAction
        {
            /** No action. */
            EVENT_ACTION_NONE = 0,
            
            /** The touch is pressed, positions are evaluated. */
            EVENT_ACTION_TOUCH,
            /** The touch is released, positions are evaluated. */
            EVENT_ACTION_RELEASE,
            /** The touch positions are evaluated only. */
            EVENT_ACTION_MOVE,
            
            /** Touch action is cancelled, e.g. incoming phone call or too much touches. */
            EVENT_ACTION_CANCEL,
            
            NUM_EVENT_ACTIONS
        };
        
        /**
         * @brief Post the current touch state.
         * Touch positions are clipped by the touch device and should be reported
         * as is, e.g. if the touch is out of the display surface the
         * platform should report the calculated values < -1.0 or > 1.0.
         * @param action The event action, see enum #EventAction.
         * @param posX The touch x-position on the display surface
         * in range [-1.0 left .. 1.0 right].
         * @param posY The touch y-position on the display surface
         * in range [-1.0 bottom .. 1.0 top].
         */
        virtual void PostEvent(EventAction action, Real posX, Real posY) = 0;
        
    protected:
        virtual ~ITouchScreen() {}
    };
}

#endif  // __MURL_I_TOUCH_SCREEN_H__
