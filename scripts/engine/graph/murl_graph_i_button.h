// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_BUTTON_H__
#define __MURL_GRAPH_I_BUTTON_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_graph_i_frame_buffer.h"
#include "murl_graph_i_scalable.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Graph
    {
        class ITransform;
        
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IButton
         * @brief The IButton graph node interface.
         * This interface represents a common clickable or touchable button surface.
         * A button by itself does not actually have any renderable geometry; instead, it only
         * holds a specific surface shape on which any pointing events are evaluated in 3D
         * space.
         *
         * In general, a button can be in one of 3 available states: "Up", "Down" or "Disabled".
         * For devices that provide a point input method other than a touch screen, such as a
         * mouse, there also exists an additional "Hover" state. Internally, a button node acts
         * similar to a Graph::ISwitch node, managing visibility of a subset of its child
         * nodes that are assigned to these states. Depending on the actual state the button is
         * in, the respective child node gets activated, and all other ones deactivated. If a
         * child node is not assigned to one of these states, it is left unmanaged.
         *
         * In addition, it is possible to define a single child node implementing the
         * Graph::ITimeline interface to react on state changes. The assigned timeline will then
         * be started to run up to a given time value set for that state.
         *
         * Use the button's Graph::IScalable base interface to control the actual size of the
         * button in 3D space; by default, predefined shapes such as rectangles and ellipses
         * have an X and Y extent of 1.
         */
        class IButton : public IScalable
        {
        public:
            /**
             * @brief Get the mutable Graph::INode interface.
             * This method returns a mutable pointer to the node's Graph::INode interface, to
             * be able to query or modify common node properties such as active state,
             * visibility or ID.
             * @return The mutable Graph::INode interface, or null if not available
             */
            virtual INode* GetNodeInterface() = 0;
            /**
             * @brief Get the constant Graph::INode interface.
             * This method returns a constant pointer to the node's Graph::INode interface, to
             * be able to query common node properties such as active state, visibility
             * or ID.
             * @return The constant Graph::INode interface, or null if not available
             */
            virtual const INode* GetNodeInterface() const = 0;
            
            /**
             * @brief Get the mutable Graph::ITransform interface.
             * This method returns a mutable pointer to the node's Graph::ITransform interface,
             * to be able to query or modify the node's transformation matrix and depth
             * order.
             * @return The mutable Graph::ITransform interface, or null if not available
             */
            virtual ITransform* GetTransformInterface() = 0;
            /**
             * @brief Get the constant Graph::ITransform interface.
             * This method returns a constant pointer to the node's Graph::ITransform interface,
             * to be able to query the node's transformation matrix and depth order.
             * @return The constant Graph::ITransform interface, or null if not available
             */
            virtual const ITransform* GetTransformInterface() const = 0;
            
            /**
             * @brief Get the mutable IFrameBufferNodeTarget container.
             * This method returns a mutable pointer to the node's IFrameBufferNodeTarget
             * container, which allows to set or query the frame buffer object the button object
             * delegates its input to.
             * @return The mutable IFrameBufferNodeTarget container, or null if not available
             */
            virtual IFrameBufferNodeTarget* GetFrameBufferNodeTarget() = 0;
            /**
             * @brief Get the constant IFrameBufferNodeTarget container.
             * This method returns a constant pointer to the node's IFrameBufferNodeTarget
             * container, which allows to query the frame buffer object the button object
             * delegates its input to.
             * @return The constant IFrameBufferNodeTarget container, or null if not available
             */
            virtual const IFrameBufferNodeTarget* GetFrameBufferNodeTarget() const = 0;
            
            /**
             * @brief Enable or disable the button.
             * When the button is disabled, it is still being processed and drawn, but not
             * reacting on any user input. To define the node that is active in the disabled
             * state, use SetStateNodeId() or SetStateChildIndex() with IEnums::BUTTON_STATE_DISABLED.
             * @param enabled If false, the button gets disabled.
             * @return true if successful.
             */
            virtual Bool SetEnabled(Bool enabled) = 0;
            /**
             * @brief Check if the button is enabled.
             * @return true if enabled.
             */
            virtual Bool IsEnabled() const = 0;
            
            /**
             * @brief Set which faces of the button are active.
             * @param faces One of the available IEnums::PolygonFaces enumeration values.
             * @return true if successful.
             */
            virtual Bool SetActiveFaces(IEnums::PolygonFaces faces) = 0;
            /**
             * @brief Check which faces of the button are active.
             * @return One of the available IEnums::PolygonFaces enumeration values.
             */
            virtual IEnums::PolygonFaces GetActiveFaces() const = 0;
            
            /**
             * @brief Set the button's active node ID for a given state.
             * Calling this method assigns one of the button's nodes to a given internal button
             * state. If done so, that node will be activated whenever the button changes to this
             * state, and deactivated when it changes to a different state.
             * @param state The internal state to which the given node will be assigned.
             * @param nodeId The node ID of the node to assign.
             * @return true if successful.
             */
            virtual Bool SetStateNodeId(IEnums::ButtonState state, const String& nodeId) = 0;
            /**
             * @brief Get the ID of the button's active node for a given state.
             * @param state The internal state for which to query the assigned node.
             * @return The ID of the assigned node, or an empty string if there is no present
             *      assignment for the givent state.
             */
            virtual const String& GetStateNodeId(IEnums::ButtonState state) const = 0;
            
            /**
             * @brief Set the button's active child for a given state.
             * Calling this method assigns one of the button's children to a given internal button
             * state. If done so, that child will be activated whenever the button changes to this
             * state, and deactivated when it changes to a different state. All children that are
             * not assigned to a specific button state behave normally.\n\n
             * As an example, a button may have four Graph::IParametersState children representing
             * different button colors, each assigned to one of the four possible internal states,
             * and a Graph::PlaneGeometry as an additional fifth child without state assignment.
             * Depending on the button's current state, one of these parameter sets will be selected,
             * and the plane geometry will be rendered in different colors.
             * @param state The internal state to which the given child will be assigned.
             * @param childIndex The zero-based index of the child node to assign.
             * @return true if successful.
             */
            virtual Bool SetStateChildIndex(IEnums::ButtonState state, SInt32 childIndex) = 0;
            /**
             * @brief Get the index of the button's active child for a given state.
             * @param state The internal state for which to query the assigned child.
             * @return The zero-based index into the button's array of children, or -1 if there is
             *      no present assignment for the givent state.
             */
            virtual SInt32 GetStateChildIndex(IEnums::ButtonState state) const = 0;
            
            /**
             * @brief Set the target time value for a given state.
             * When a timeline child node is defined via SetTimelineNodeId() or SetTimelineChildIndex(),
             * this method sets the target time value to run to when the button is entering the
             * given button state.
             * @param state The button state for which to set the target time value.
             * @param time The target time value.
             * @return true if successful.
             */
            virtual Bool SetStateAnimationTime(IEnums::ButtonState state, Real time) = 0;
            /**
             * @brief Get the target time value set for a given state.
             * @param state The button state for which to query the target time.
             * @return The target time value.
             */
            virtual Real GetStateAnimationTime(IEnums::ButtonState state) const = 0;
            /**
             * @brief Reset the target time value for a given state to 0.
             * @param state The button state for which to reset the target time value.
             * @return true if successful.
             */
            virtual Bool ResetStateAnimationTime(IEnums::ButtonState state) = 0;
            /**
             * @brief Query if a target time value was set for a given button state.
             * @param state The button state to query.
             * @return true if a target time value was set for the given state.
             */
            virtual Bool IsStateAnimationTimeSet(IEnums::ButtonState state) const = 0;
            
            /**
             * @brief Define a timeline node from within the current graph namespace.
             * @param nodeId The node ID of the timeline to assign.
             * @return true if successful.
             */
            virtual Bool SetTimelineNodeId(const String& nodeId) = 0;
            /**
             * @brief Query the node ID of an assigned timeline child.
             * @return The node id of the assigned timeline child, or an empty string if no
             *      timeline was assigned or a child was explicitly assigned by its child index.
             */
            virtual const String& GetTimelineNodeId() const = 0;
            
            /**
             * @brief Define a timeline node among the button's children.
             * @param nodeIndex The zero-based child index of the timeline child to assign.
             * @return true if successful.
             */
            virtual Bool SetTimelineChildIndex(SInt32 nodeIndex) = 0;
            /**
             * @brief Query the child index of an assigned timeline child.
             * @return The zero-based child index of the assigned timeline child, or -1 if no
             *      explicit child was assigned or a different timeline node was used from the
             *      current namespace via SetTimelineNodeId().
             */
            virtual SInt32 GetTimelineChildIndex() const = 0;
            
            /**
             * @brief Set the shape of the button's touch area.
             * @param shape The shape to use.
             * @return true if successful.
             */
            virtual Bool SetShape(IEnums::TouchAreaShape shape) = 0;
            /**
             * @brief Get the shape of the button's touch area.
             * @return The touch area's shape.
             */
            virtual IEnums::TouchAreaShape GetShape() const = 0;
            
            /**
             * @brief Set the horizontal container alignment.
             * The given alignment values specify how the text container is actually positioned with
             * respect to the node's world position.
             * @param alignmentX The horizontal container alignment.
             * @param alignmentY The vertical container alignment.
             * @return true if successful.
             */
            virtual Bool SetContainerAlignment(IEnums::AlignmentX alignmentX, IEnums::AlignmentY alignmentY) = 0;
            /**
             * @brief Set the horizontal container alignment.
             * See SetContainerAlignment().
             * @param alignmentX The horizontal container alignment.
             * @return true if successful.
             */
            virtual Bool SetContainerAlignmentX(IEnums::AlignmentX alignmentX) = 0;
            /**
             * @brief Set the vertical container alignment.
             * See SetContainerAlignment().
             * @param alignmentY The vertical container alignment.
             * @return true if successful.
             */
            virtual Bool SetContainerAlignmentY(IEnums::AlignmentY alignmentY) = 0;
            /**
             * @brief Get the horizontal container alignment.
             * @return The horizontal container alignment.
             */
            virtual IEnums::AlignmentX GetContainerAlignmentX() const = 0;
            /**
             * @brief Get the vertical container alignment.
             * @return The vertical container alignment.
             */
            virtual IEnums::AlignmentY GetContainerAlignmentY() const = 0;

            /**
             * @brief Set the horizontal and vertical borders used for alignment.
             * @param borderX The horizontal border.
             * @param borderY The vertical border.
             * @return true if successful.
             */
            virtual Bool SetBorder(Real borderX, Real borderY) = 0;
            /**
             * @brief Set the horizontal border used for alignment.
             * @param borderX The horizontal border.
             * @return true if successful.
             */
            virtual Bool SetBorderX(Real borderX) = 0;
            /**
             * @brief Set the vertical border used for alignment.
             * @param borderY The vertical border.
             * @return true if successful.
             */
            virtual Bool SetBorderY(Real borderY) = 0;
            /**
             * @brief Get the horizontal border used for alignment.
             * @return The horizontal border.
             */
            virtual Real GetBorderX() const = 0;
            /**
             * @brief Get the vertical border used for alignment.
             * @return The vertical border.
             */
            virtual Real GetBorderY() const = 0;
            
            /**
             * @brief Set the output coordinate reference size.
             * Generally, output coordinates are represented by values ranging from -1.0 to 1.0.
             * As a convenience, this method can be used to set an arbitrary reference size for
             * both dimensions of the button; this way it is possible to specify integer (pixel)
             * values instead of (quite unreadable) floats. By default, both sizeX and sizeY
             * are set to 1.0.
             * See also Graph::IPlaneGeometry::SetTextureSize() for a texture equivalent, and
             * Graph::IFrameBuffer::SetInCoordSize() for the counterpart taking the button's out
             * coordinates as input. Note that if it is desired to map button coordinates directly 
             * to texture coordinates e.g. for using a button on a frame buffer, it may be useful
             * to call SetOutCoord()/SetOutCoordSize() and the frame buffer's SetInCoord()/SetInCoordSize()
             * with values equivalent to the texture coordinate values of the plane displaying the
             * frame buffer contents.
             * @param sizeX The horizontal coordinate reference size.
             * @param sizeY The vertical coordinate reference size.
             * @return true if successful.
             */
            virtual Bool SetOutCoordSize(Real sizeX, Real sizeY) = 0;
            /**
             * @brief Set the horizontal output coordinate reference size.
             * See SetOutCoordSize().
             * @param sizeX The horizontal coordinate reference size.
             * @return true if successful.
             */
            virtual Bool SetOutCoordSizeX(Real sizeX) = 0;
            /**
             * @brief Set the vertical output coordinate reference size.
             * See SetOutCoordSize().
             * @param sizeY The vertical coordinate reference size.
             * @return true if successful.
             */
            virtual Bool SetOutCoordSizeY(Real sizeY) = 0;
            /**
             * @brief Get the horizontal output coordinate reference size.
             * See SetOutCoordSize().
             * @return The horizontal output coordinate reference size.
             */
            virtual Real GetOutCoordSizeX() const = 0;
            /**
             * @brief Get the vertical output coordinate reference size.
             * See SetOutCoordSize().
             * @return The vertical output coordinate reference size.
             */
            virtual Real GetOutCoordSizeY() const = 0;
            
            /**
             * @brief Set the button's output coordinate range.
             * This method sets the button's start and end output coordinates. In contrast
             * to a button event's local intersection point, which always represents the
             * actual intersection in object-space 3D coordinates, an event's output 
             * coordinate represents a 2D intersection on the button's clickable surface.
             * This can be interpreted analogously to a renderable geometry, with 3D vertex
             * coordinates and 2D texture coordinates.
             * @param x1 The start coordinate in X direction.
             * @param y1 The start coordinate in Y direction.
             * @param x2 The end coordinate in X direction.
             * @param y2 The end coordinate in Y direction.
             * @return true if successful.
             */
            virtual Bool SetOutCoord(Real x1, Real y1, Real x2, Real y2) = 0;
            /**
             * @brief Set the button's output coordinate start.
             * See SetOutCoord().
             * @param x1 The start coordinate in X direction.
             * @param y1 The start coordinate in Y direction.
             * @return true if successful.
             */
            virtual Bool SetOutCoord1(Real x1, Real y1) = 0;
            /**
             * @brief Set the button's output coordinate end.
             * See SetOutCoord().
             * @param x2 The end coordinate in X direction.
             * @param y2 The end coordinate in Y direction.
             * @return true if successful.
             */
            virtual Bool SetOutCoord2(Real x2, Real y2) = 0;
            /**
             * @brief Set the button's horizontal start output coordinate.
             * See SetOutCoord().
             * @param x1 The start coordinate in X direction.
             * @return true if successful.
             */
            virtual Bool SetOutCoordX1(Real x1) = 0;
            /**
             * @brief Set the button's vertical start output coordinates.
             * See SetOutCoord().
             * @param y1 The start coordinate in Y direction.
             * @return true if successful.
             */
            virtual Bool SetOutCoordY1(Real y1) = 0;
            /**
             * @brief Set the button's horizontal end output coordinate.
             * See SetOutCoord().
             * @param x2 The end coordinate in X direction.
             * @return true if successful.
             */
            virtual Bool SetOutCoordX2(Real x2) = 0;
            /**
             * @brief Set the button's vertical end output coordinates.
             * See SetOutCoord().
             * @param y2 The end coordinate in Y direction.
             * @return true if successful.
             */
            virtual Bool SetOutCoordY2(Real y2) = 0;
            /**
             * @brief Get the button's horizontal start output coordinate.
             * See SetOutCoord().
             * @return The start coordinate in X direction.
             */
            virtual Real GetOutCoordX1() const = 0;
            /**
             * @brief Get the button's vertical start output coordinate.
             * See SetOutCoord().
             * @return The start coordinate in Y direction.
             */
            virtual Real GetOutCoordY1() const = 0;
            /**
             * @brief Get the button's horizontal end output coordinate.
             * See SetOutCoord().
             * @return The end coordinate in X direction.
             */
            virtual Real GetOutCoordX2() const = 0;
            /**
             * @brief Get the button's vertical end output coordinate.
             * See SetOutCoord().
             * @return The end coordinate in Y direction.
             */
            virtual Real GetOutCoordY2() const = 0;

            /**
             * @brief Enable or disable output coordinate clipping.
             * By default, clipping is disabled. If the button delegates its events
             * to a given frame buffer (see GetFrameBufferNodeTarget()), this means
             * that other buttons defined in the frame buffer also receive events
             * even if they are actually outside this buttons range.
             * Set enabled to true to restrict the frame buffer's input event area
             * to this button's bounds.
             * @param enable If true, output coordinates are being clipped.
             * @return true if successful.
             */
            virtual Bool SetOutCoordClippingEnabled(Bool enable) = 0;
            /**
             * @brief Check if output coordinate clipping is enabled
             * @return true if enabled.
             */
            virtual Bool IsOutCoordClippingEnabled() const = 0;

            /**
             * @brief Set the mouse button this button responds to.
             * @param button The mouse button used for input.
             * @return true if successful.
             */
            virtual Bool SetResponseButton(IEnums::MouseButton button) = 0;
            /**
             * @brief Get the mouse button this button responds to.
             * @return The mouse button used for input.
             */
            virtual IEnums::MouseButton GetResponseButton() const = 0;
            
            /**
             * @brief Enable or disable event pass through.
             * @param enable If true events are passed through underlying buttons.
             * @return true if successful.
             */
            virtual Bool SetPassEventsEnabled(Bool enable) = 0;
            /**
             * @brief Check event pass through is enabled.
             * @return true if events are passed through underlying buttons.
             */
            virtual Bool IsPassEventsEnabled() const = 0;
            
            /**
             * @brief Set the maximum number of simultaneous touch events.
             * @param value The maximum number of touch events that are evaluated
             *      simultaneously.
             * @return true if successful.
             */
            virtual Bool SetMaxNumberOfEvents(UInt32 value) = 0;
            /**
             * @brief Get the maximum number of simultaneous touch events.
             * @return The maximum number of touch events that are evaluated
             *      simultaneously.
             */
            virtual UInt32 GetMaxNumberOfEvents() const = 0;
            
            /**
             * @brief Reset the tracking of all current events.
             * Set the button state to IEnums::BUTTON_STATE_UP if enabled
             * otherwise to IEnums::BUTTON_STATE_DISABLED.
             * @return true if successful.
             */
            virtual Bool ResetEvents() = 0;
            
            /**
             * @brief Get the total number of active events.
             * This method returns the total number of active input events, including any
             * non-tracked events and events that are already in the "up" state. For mouse-like
             * devices, this simply means move events without any button pressed. For touch
             * screen-like devices, there is no actual move event in the "up" state, so any
             * active event retains the state immediately before the finger was lifted.
             * @return The total number of active events.
             */
            virtual UInt32 GetNumberOfActiveEvents() const = 0;
            /**
             * @brief Get the unique ID of a specific active event.
             * @param activeEventIndex The event's index, in the range from 0 to
             *      GetNumberOfActiveEvents() - 1.
             * @return The active event's ID.
             */
            virtual UInt32 GetActiveEventId(UInt32 activeEventIndex) const = 0;
            
            /**
             * @brief Get the number of currently tracked events.
             * This method returns the number of currently tracked events, i.e. all those
             * events that began with a "down" action inside the button's bounds.
             * @return The number of currently tracked events.
             */
            virtual UInt32 GetNumberOfTrackedEvents() const = 0;
            /**
             * @brief Get the unique ID of a specific tracked event.
             * @param trackedEventIndex The event's index, in the range from 0 to
             *      GetNumberOfTrackedEvents() - 1.
             * @return The tracked event's ID.
             */
            virtual UInt32 GetTrackedEventId(UInt32 trackedEventIndex) const = 0;
            
            /**
             * @brief Check if a given event has received updates from any input device
             *  during the most recent logic tick.
             * Has to be considered when using GetLocalEventDelta().
             * @param id The ID of the event to query, retrieved from GetActiveEventId() or
             *      GetTrackedEventId().
             * @return true if the event has received updates.
             */
            virtual Bool HasEventUpdate(UInt32 id) const = 0;
            /**
             * @brief Get the type of input device that reported the event with a given ID.
             * @param id The ID of the event to query, retrieved from GetActiveEventId() or
             *      GetTrackedEventId().
             * @return The input device type.
             */
            virtual IEnums::InputDeviceType GetEventDeviceType(UInt32 id) const = 0;
            /**
             * @brief Get the output coordinate of an event with a given ID, in 2D space.
             * @param id The ID of the event to query, retrieved from GetActiveEventId() or
             *      GetTrackedEventId().
             * @return A const reference to the event's current out coordinate.
             */
            virtual const Vector& GetEventOutCoord(UInt32 id) const = 0;
            /**
             * @brief Get the position of an event with a given ID, in 3D object space.
             * @param id The ID of the event to query, retrieved from GetActiveEventId() or
             *      GetTrackedEventId().
             * @return A const reference to the event's current local position.
             */
            virtual const Vector& GetLocalEventPosition(UInt32 id) const = 0;
            /**
             * @brief Get the current position delta of an event with a given ID, in object space.
             * If HasEventUpdate() returns false the delta is zero and should be ignored.
             * @param id The ID of the event to query, retrieved from GetActiveEventId() or
             *      GetTrackedEventId().
             * @return A const reference to the event's current local position delta.
             */
            virtual const Vector& GetLocalEventDelta(UInt32 id) const = 0;
            /**
             * @brief Check if a given event is in the "tracked" state.
             * @param id The ID of the event to query, retrieved from GetActiveEventId() or
             *      GetTrackedEventId().
             * @return true if the event is currently tracked.
             */
            virtual Bool IsEventTracked(UInt32 id) const = 0;
            /**
             * @brief Check if a given event's incidence point is within the button's bounds.
             * As an example, for a rectangular button (SetShape(IEnums::TOUCH_AREA_SHAPE_RECTANGLE))
             * without additional scale factor, this method returns true whenever the event's local
             * X and Y coordinates are both in the range from -0.5 to +0.5.
             * @param id The ID of the event to query, retrieved from GetActiveEventId() or
             *      GetTrackedEventId().
             * @return true if the event is inside.
             */
            virtual Bool IsEventInside(UInt32 id) const = 0;
            /**
             * @brief Check if a given event is in the pressed state.
             * @param id The ID of the event to query, retrieved from GetActiveEventId() or
             *      GetTrackedEventId().
             * @return true if the event is currently in the pressed state.
             */
            virtual Bool IsEventPressed(UInt32 id) const = 0;
            
            /**
             * @brief Check if the button was pressed.
             * This method returns true when a "down" action occurred during the most recent
             * logic tick at a coordinate within the button's bounds, and the button was not
             * already in the "down" state.
             * @return true if the button was pressed.
             */
            virtual Bool WasPressed() const = 0;
            /**
             * @brief Check if the button was released inside.
             * This method returns true when the button was actually released during
             * the most recent logic tick, i.e. when first a "down" action occurred on that
             * button, and later on the corresponding "up" action occurred at a coordinate
             * within the button's bounds.
             * @return true if the button was clicked.
             */
            virtual Bool WasReleasedInside() const = 0;
            /**
             * @brief Check if the button was released outside.
             * This method returns true when a pending click action on the button was
             * actually dismissed during the most recent logic tick, i.e. when first a "down"
             * action occurred on that button, and later on the corresponding "up" action
             * occurred at a coordinate outside the button's bounds.
             * @return true if the button was released.
             */
            virtual Bool WasReleasedOutside() const = 0;
            /**
             * @brief Get the position of the current button event, in object space.
             * This method returns the current position of the last WasReleasedInside(),
             * WasPressed() or WasReleased() event.
             * @return A const reference to the event's current local position.
             */
            virtual const Vector& GetEventPosition() const = 0;
            /**
             * @brief Get the current button state.
             * @return The current button state.
             */
            virtual IEnums::ButtonState GetButtonState() const = 0;
            
        protected:
            virtual ~IButton() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IButton nodes.
         */
        typedef IGenericNodeTarget<IButton> IButtonNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_BUTTON_H__
