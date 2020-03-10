// Copyright 2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_MULTI_TOUCHABLE_H__
#define __MURL_GRAPH_I_MULTI_TOUCHABLE_H__

#include "murl_graph_i_touchable.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphMiscInterfaces
         * @interface IMultiTouchable
         * @brief The IMultiTouchable interface.
         * The IMultiTouchable object combines the ITouchable events
         * and reports the results to the ITouchableTarget interface.
         */
        class IMultiTouchable : public ITouchable
        {
        public:
            /**
             * @brief Set the maximum number of events to combine.
             * @param maxNumberOfEvents The maximum number of events.
             */
            virtual void SetMaxNumberOfEvents(UInt32 maxNumberOfEvents) = 0;
            /**
             * @brief Get the maximum number of events to combine.
             * @return The maximum number of events.
             */
            virtual UInt32 GetMaxNumberOfEvents() const = 0;
            
            /**
             * @brief Reset all states.
             */
            virtual void ResetStates() = 0;
            
            /**
             * @brief Get the unique event identifier by index.
             * A valid index is [0 .. GetCount() - 1].
             * @param index The index of the event.
             * @return The unique event identifier.
             */
            virtual UInt32 GetId(UInt32 index) const = 0;
            /**
             * @brief Get the event index by identifier.
             * @param id The event identifier.
             * @return The event index.
             */
            virtual SInt32 GetIndex(UInt32 id) const = 0;
            /**
             * @brief Get the number of events.
             * @return The number of events.
             */
            virtual UInt32 GetCount() const = 0;
            
            /**
             * @brief Get the unique tracked-event identifier by index.
             * An event which was pressed inside the touch area is
             * a tracked event.
             * A valid index is [0 .. GetTrackedCount() - 1].
             * @param index The index of the tracked event.
             * @return The unique event identifier.
             */
            virtual UInt32 GetTrackedId(UInt32 index) const = 0;
            /**
             * @brief Get the tracked event index by identifier.
             * An event which was pressed inside the touch area is
             * a tracked event.
             * @param id The event identifier.
             * @return The tracked event index.
             */
            virtual SInt32 GetTrackedIndex(UInt32 id) const = 0;
            /**
             * @brief Get the number of tracked events.
             * An event which was pressed inside the touch area is
             * a tracked event.
             * @return The number of tracked events.
             */
            virtual UInt32 GetTrackedCount() const = 0;
            
            /**
             * @brief Check if an event is inside the touch area.
             * A valid index is [0 .. GetCount() - 1].
             * @param index The index of the event.
             * @return true if the event is inside the touch area.
             */
            virtual Bool IsInside(SInt32 index) const = 0;
            /**
             * @brief Check if an event is pressed.
             * A valid index is [0 .. GetCount() - 1].
             * @param index The index of the event.
             * @return true if the event is pressed.
             */
            virtual Bool IsPressed(SInt32 index) const = 0;
            /**
             * @brief Check if an event is tracked.
             * An event which was pressed inside the touch area is
             * a tracked event.
             * A valid index is [0 .. GetCount() - 1].
             * @param index The index of the event.
             * @return true if the event is tracked.
             */
            virtual Bool IsTracked(SInt32 index) const = 0;
            
            /**
             * @brief Check if an event has received updates from any input device.
             * A valid index is [0 .. GetCount() - 1].
             * @param index The index of the event.
             * @return true if the event has received updates.
             */
            virtual Bool HasUpdate(SInt32 index) const = 0;
            /**
             * @brief Get the input device type that reported this event.
             * A valid index is [0 .. GetCount() - 1].
             * @param index The index of the event.
             * @return The input device type.
             */
            virtual IEnums::InputDeviceType GetInputDeviceType(SInt32 index) const = 0;
            /**
             * @brief Get the output coordinate vector of an event in 2D space.
             * A valid index is [0 .. GetCount() - 1].
             * @param index The index of the event.
             * @return The output coordinate vector.
             */
            virtual const Vector& GetOutCoord(SInt32 index) const = 0;
            /**
             * @brief Get the local position vector of an event in 3D object space.
             * A valid index is [0 .. GetCount() - 1].
             * @param index The index of the event.
             * @return The local position vector.
             */
            virtual const Vector& GetLocalPosition(SInt32 index) const = 0;
            /**
             * @brief Get the local position delta vector of an event.
             * A valid index is [0 .. GetCount() - 1].
             * @param index The index of the event.
             * @return The local position delta vector.
             */
            virtual const Vector& GetLocalDelta(SInt32 index) const = 0;
            
        protected:
            virtual ~IMultiTouchable() {}
        };
    }
}

#endif // __MURL_GRAPH_I_TOUCHABLE_H__
