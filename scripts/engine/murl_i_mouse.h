// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_I_MOUSE_H__
#define __MURL_I_MOUSE_H__

#include "murl_i_enums.h"

namespace Murl
{
    /**
     * @ingroup MurlDeviceInterfaces
     * @interface IMouse
     * @brief The mouse device interface.
     * Used by the platform to post events to the device.
     */
    class IMouse
    {
    public:
        /**
         * @brief Definition of event actions.
         */
        enum EventAction
        {
            /** No action. */
            EVENT_ACTION_NONE = 0,
            
            /** Mouse button is pressed, positions are evaluated. */
            EVENT_ACTION_BUTTON_DOWN,
            /** Mouse button is released, positions are evaluated. */
            EVENT_ACTION_BUTTON_UP,
            /** Mouse button not evaluated, positions are evaluated. */
            EVENT_ACTION_MOVE,
            
            /** Flush all button states to the up state.
             * This is useful in rare cases, e.g. if the platform is loosing
             * events when changing from window to full screen mode. */
            EVENT_ACTION_FLUSH,
            
            NUM_EVENT_ACTIONS
        };
        
        /**
         * @brief Post the current mouse state.
         * Mouse positions are clipped by the mouse device and should be reported
         * as is, e.g. if the mouse cursor is moved out of the display surface the
         * platform should report the calculated values < -1.0 or > 1.0.
         * @param action The event action, see enum #EventAction.
         * @param button The mouse button identifier.
         * @param posX The mouse x-position on the display surface
         * in range [-1.0 left .. 1.0 right].
         * @param posY The mouse y-position on the display surface
         * in range [-1.0 bottom .. 1.0 top].
         */
        virtual void PostEvent(EventAction action, IEnums::MouseButton button,
                               Real posX, Real posY) = 0;
        
    protected:
        virtual ~IMouse() {}
    };
}

#endif  // __MURL_I_MOUSE_H__
