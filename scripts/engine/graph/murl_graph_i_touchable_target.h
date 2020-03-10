// Copyright 2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_TOUCHABLE_TARGET_H__
#define __MURL_GRAPH_I_TOUCHABLE_TARGET_H__

#include "murl_graph_types.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphMiscInterfaces
         * @interface ITouchableTarget
         * @brief The ITouchableTarget interface.
         * The ITouchableTarget interface is used by the IMultiTouchable
         * object to notify the combined state from ITouchable events.
         */
        class ITouchableTarget
        {
        public:
            /**
             * @brief Set the pressed state.
             * The first ITouchable event was pressed on the touch area.
             * @param localPosition The local position of the event.
             */
            virtual void SetPressed(const Vector& localPosition) = 0;
            
            /**
             * @brief Set the released inside state.
             * A ITouchable event was pressed first and released at last
             * inside the touch area.
             * @param localPosition The local position of the event.
             */
            virtual void SetReleasedInside(const Vector& localPosition) = 0;
            
            /**
             * @brief Set the released outside state.
             * A ITouchable event was pressed first and released at last
             * outside the touch area.
             * @param localPosition The local position of the event.
             */
            virtual void SetReleasedOutside(const Vector& localPosition) = 0;
            
            /**
             * @brief Set the button state.
             * @param state The current button state.
             */
            virtual void SetButtonState(IEnums::ButtonState state) = 0;
            
        protected:
            virtual ~ITouchableTarget() {}
        };
    }
}

#endif // __MURL_GRAPH_I_TOUCHABLE_TARGET_H__
