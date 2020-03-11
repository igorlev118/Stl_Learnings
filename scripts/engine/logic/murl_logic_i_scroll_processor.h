// Copyright 2015 Spraylight GmbH

#ifndef __MURL_LOGIC_I_SCROLL_PROCESSOR_H__
#define __MURL_LOGIC_I_SCROLL_PROCESSOR_H__

#include "murl_logic_i_processor.h"

namespace Murl
{
    namespace Graph
    {
        class IButton;
        class INode;
    }

    namespace Logic
    {
        /**
         * @ingroup MurlLogicInterfaces
         * @interface IScrollProcessor
         * @brief The IScrollProcessor interface.
         * The ScrollProcessor is used for tracking the inputs of a Graph::IButton node
         * and/or any input provided by the user's logic code.
         * \n
         * The ScrollProcessor is used for scroll areas and swipe gestures:
         *  - Tracking the relative movement of the input.
         *  - Performing a deceleration when the input is released.
         *  - Performing an acceleration when the input is repeated.
         *
         * Additional a position tracking can be used for:
         *  - Tracking an absolute position.
         *  - Specifying minimum and maximum bounds.
         *  - Damping on the bounds.
         *  - Position animation.
         * \n
         *
         * The ScrollProcessor operates in units of 1, which means the button size is
         * 1 in x and y direction independent of the button's scalefactor.
         *
         * All values used by the ScrollProcessor simply operates in units of 1.
         * Scaling the results to adequate values applies to the user's logic code.
         *
         * The ScrollProcessor implements an IProcessor which is typically attached
         * as a child of an user defined logic processor.
         */
        class IScrollProcessor
        {
        public:
            /**
             * @brief Get the processor interface from a IScrollProcessor object.
             * The ScrollProcessor implements an IProcessor which is typically
             * attached as a child of an user defined logic processor.
             * @return The processor interface shared pointer.
             */
            virtual IProcessorPtr GetProcessor() = 0;

            /**
             * @name Setup button
             * @brief Methods to setup the button to track.
             * @{
             */
            /**
             * @brief Set the path and identifier of the button node to track.
             * The button node can be set alternatively by using SetButtonNode().
             * @param buttonId The full path and identifier to a button node.
             */
            virtual void SetButtonId(const String& buttonId) = 0;
            /**
             * @brief Get the identifier of the button node to track.
             * The identifier contains the path and identifier set by SetButtonId().
             * If the button node is specified by SetButtonNode() the
             * identifier contains the node identifer only without path.
             * @return The identifier of the button node.
             */
            virtual const String& GetButtonId() const = 0;

            /**
             * @brief Set the button node to track.
             * The button node can be set alternatively by using SetButtonId().
             * @param buttonNode The button node object.
             * @return true if successful, false if the node is invalid.
             */
            virtual Bool SetButtonNode(Graph::INode* buttonNode) = 0;
            /**
             * @brief Get the button node to track.
             * If the button node is specified by SetButtonId() the node is
             * valid after Init() or at least one tick has been processed. If
             * using SetButtonNode() the button node is available immediately.
             * @return The button node object.
             */
            virtual Graph::IButton* GetButtonNode() const = 0;

            /**
             * @brief Set enable or disable the button.
             * @param isEnabled true for enable, false for disable.
             * @return true if successful.
             */
            virtual Bool SetButtonEnabled(Bool isEnabled) = 0;
            /**
             * @brief Check if the button is enabled.
             * @return true if the button is enabled.
             */
            virtual Bool IsButtonEnabled() const = 0;
            /** @} */


            /**
             * @name Setup input
             * @brief Methods for controlling relative inputs.
             * @{
             */
            /**
             * @brief Set the dead zone distances.
             * The dead zone distance specifies the minimum length of the input
             * movement on the corresponding axis. This is useful to filter "short"
             * movements when tapping on the button, use WasButtonReleasedInsideDeadZone().
             * The dead zone state is available by IsOutsideDeadZone() which is set to
             * true if the input movement exceeds any of the dead zone minimum distances.
             * If the minimum distance is <= 0.0 the corresponding axis is ignored.
             * The deceleration/acceleration is applied only if the input movement
             * is outside the dead zone.
             * \n
             * The default value is Vector(0.01, 0.01, 0.01, 0.0) in units.
             * @param distances The minimum input move distances in units.
             */
            virtual void SetDeadZode(const Vector& distances) = 0;
            /**
             * @brief Get the minimum dead zone distances.
             * @return The minimum dead zone distances in units.
             */
            virtual const Vector& GetDeadZone() const = 0;

            /**
             * @brief Set the acceleration factor.
             * If an input is repeated within the acceleration timeout, the recent
             * velocity of the previous input is multiplied by the acceleration factor
             * and added to the current velocity.
             * \n
             * The default value is 16.0.
             * @param accelerationFactor The acceleration factor.
             */
            virtual void SetAccelerationFactor(Real accelerationFactor) = 0;
            /**
             * @brief Get the acceleration factor.
             * @return The acceleration factor.
             */
            virtual Real GetAccelerationFactor() const = 0;

            /**
             * @brief Set the acceleration timeout.
             * The acceleration is applied only if an input is repeated within
             * the acceleration timeout.
             * \n
             * The default value is 0.5 seconds.
             * @param timeout The acceleration timeout in seconds.
             */
            virtual void SetAccelerationTimeout(Real timeout) = 0;
            /**
             * @brief Get the acceleration timeout.
             * @return The acceleration timeout in seconds.
             */
            virtual Real GetAccelerationTimeout() const = 0;

            /**
             * @brief Set the deceleration factor.
             * The deceleration factor is multiplied to the recent movement when
             * the input ends. The deceleration stops if the recent velocity
             * underflows the stop velocity value.
             * \n
             * The default value is 0.01.
             * @param decelerationFactor The deceleration factor per second must be < 1.
             * @return true if successful, false if decelerationFactor is >= 1.
             */
            virtual Bool SetDecelerationFactor(Real decelerationFactor) = 0;
            /**
             * @brief Get the deceleration factor.
             * @return The deceleration factor per second.
             */
            virtual Real GetDecelerationFactor() const = 0;

            /**
             * @brief Set the deceleration timeout.
             * Inhibit deceleration if the time between the last and the
             * recent movement exceeds the deceleration timeout.
             * \n
             * The default value is 0.1 seconds.
             * @param timeout The deceleration timeout in seconds.
             */
            virtual void SetDecelerationTimeout(Real timeout) = 0;
            /**
             * @brief Get the deceleration timeout.
             * @return The deceleration timeout in seconds.
             */
            virtual Real GetDecelerationTimeout() const = 0;

            /**
             * @brief Set the deceleration stop velocity.
             * The deceleration stops if the recent velocity underflows
             * the stop velocity value.
             * \n
             * The default value is 0.01 units/second.
             * @param stopVelocity The deceleration stop velocity value.
             */
            virtual void SetStopVelocity(Real stopVelocity) = 0;
            /**
             * @brief Get the deceleration stop velocity.
             * @return The deceleration stop velocity in units/seconds.
             */
            virtual Real GetStopVelocity() const = 0;

            /**
             * @brief Set the maximum velocity.
             * The maximum velocity is the highest allowed velocity, which means
             * the current velocity is clamped to the maximum velocity.
             * The velocity is not clamped if the maximum velocity is 0.
             * \n
             * The default value is 32.0 units/second.
             * @param maxVelocity The the maximum velocity in units/second.
             */
            virtual void SetMaxVelocity(Real maxVelocity) = 0;
            /**
             * @brief Get the maximum velocity.
             * @return The maximum velocity in units/second.
             */
            virtual Real GetMaxVelocity() const = 0;
            /** @} */


            /**
             * @name Current states
             * @brief Methods for getting the current states.
             * @{
             */
            /**
             * @brief Check if the ScrollProcessor is active.
             * The ScrollProcessor is active if the graph button is pressed or the
             * accleration/deceleration is active or the move animation is running.
             * @return true if the ScrollProcessor is active.
             */
            virtual Bool IsActive() const = 0;
            /**
             * @brief Check if the current movement is outside the dead zone.
             * This state reports also true if the deceleration is stopped by
             * a tap, even if the tap's input is probably inside the dead zone.
             * See also SetDeadZode().
             * @return true if the current movement is outside the dead zone.
             */
            virtual Bool IsOutsideDeadZone() const = 0;
            /**
             * @brief Check if the graph button is tracked and pressed.
             * @return true if the graph button is pressed.
             */
            virtual Bool IsButtonPressed() const = 0;
            /**
             * @brief Check if the graph button was released.
             * @return true if the graph button was released.
             */
            virtual Bool WasButtonReleased() const = 0;
            /**
             * @brief Check if the graph button was released inside the dead zone.
             * @return true if the graph button was released inside the dead zone.
             */
            virtual Bool WasButtonReleasedInsideDeadZone() const = 0;
            /** @} */


            /**
             * @name Movement controlling
             * @brief Methods for controlling the current movement.
             * @{
             */
            /**
             * @brief Get the recent movement.
             * The movement is set by the button input or the acceleration/deceleration
             * or the move animation.
             * @return The movement vector in units of the recent tick.
             */
            virtual const Vector& GetMovement() const = 0;
            /**
             * @brief Begin setting the next movement.
             * This method can be called optionally before applying custom movements using
             * SetMovement(). This enables the deceleration/acceleration behaviour.
             * The movement can be set only if the button is not pressed.
             * @param state The IState object.
             * @return true if successful, false if the button is pressed.
             */
            virtual Bool BeginMovement(const IState* state) = 0;
            /**
             * @brief End setting the next movement.
             * This method can be called optionally after applying custom movements using
             * SetMovement(). This applies the deceleration/acceleration behaviour.
             * The movement can be set only if the button is not pressed.
             * @param state The IState object.
             * @return true if successful, false if the button is pressed.
             */
            virtual Bool EndMovement(const IState* state) = 0;
            /**
             * @brief Set the next movement.
             * Setting the movement sets the IsActive() state to true in the next tick.
             * The movement can be set only if the button is not pressed. If the
             * button is pressed during the next tick, the next movement is ignored.
             * See also BeginMovement() and EndMovement().
             * @param delta The movement vector in units for the next tick.
             * @return true if successful, false if the button is pressed.
             */
            virtual Bool SetMovement(const Vector& delta) = 0;
            /**
             * @brief Reset the current movement including all current states.
             */
            virtual void ResetMovement() = 0;
            /** @} */


            /**
             * @name Position tracking
             * @brief Methods for position tracking.
             * Consider that the position tracking operates on vector data,
             * which means that all 3 axis (x/y/z) are evaluated and should be
             * setup correctly.
             * @{
             */
            /**
             * @brief Set enable or disable the position tracking.
             * The position tracking can be disabled for implementing endless scrolling
             * by using the relative movement methods only, typically GetMovement().
             * \n
             * The default value is true.
             * @param isEnabled true for enable, false for disable.
             */
            virtual void SetPositionEnabled(Bool isEnabled) = 0;
            /**
             * @brief Check if the position tracking is enabled.
             * @return true if the position tracking is enabled.
             */
            virtual Bool IsPositionEnabled() const = 0;

            /**
             * @brief Set the minimum position.
             * The default value is Vector(0.0, 0.0, 0.0, 1.0).
             * @param position The minimum position in units.
             */
            virtual void SetMinPosition(const Vector& position) = 0;
            /**
             * @brief Get the minimum position.
             * @return The minimum position in units.
             */
            virtual const Vector& GetMinPosition() const = 0;

            /**
             * @brief Set the maximum position.
             * The default value is Vector(1.0, 1.0, 1.0, 1.0).
             * @param position The maximum position in units.
             */
            virtual void SetMaxPosition(const Vector& position) = 0;
            /**
             * @brief Get the maximum position.
             * @return The maximum position in units.
             */
            virtual const Vector& GetMaxPosition() const = 0;

            /**
             * @brief Set the damping distance for the minimum position.
             * The damping distance specifies an extra minimum to converge to.
             * The position range is (minimum position - minimum damping distance, minimum position].
             * \n
             * The default value is Vector(0.5, 0.5, 0.5, 0.0).
             * @param distance The damping distance for the minimum position in units.
             */
            virtual void SetMinDampDistance(const Vector& distance) = 0;
            /**
             * @brief Get the damping distance for the minimum position.
             * @return The damping distance for the minimum position in units.
             */
            virtual const Vector& GetMinDampDistance() const = 0;

            /**
             * @brief Set the damping distance for the maximum position.
             * The damping distance specifies an extra maximum to converge to.
             * The position range is [maximum position, maximum position + maximum damping distance).
             * \n
             * The default value is Vector(0.5, 0.5, 0.5, 0.0).
             * @param distance The damping distance for the maximum position in units.
             */
            virtual void SetMaxDampDistance(const Vector& distance) = 0;
            /**
             * @brief Get the damping distance for the maximum position.
             * @return The damping distance for the maximum position in units.
             */
            virtual const Vector& GetMaxDampDistance() const = 0;

            /**
             * @brief Set the damping factor.
             * The higher the factor, the stronger is the damping (1 + 1 / (-x / f - 1)).
             * \n
             * The default value is 1.0.
             * @param dampFactor The damping factor should be >= 1.0.
             */
            virtual void SetDampFactor(Real dampFactor) = 0;
            /**
             * @brief Get the damping factor.
             * @return The damping factor.
             */
            virtual Real GetDampFactor() const = 0;

            /**
             * @brief Set the bounce time.
             * The bounce time is the duration to move back from the damping
             * area to the minimum / maximum position.
             * @param bounceTime The bounce time in seconds.
             */
            virtual void SetBounceTime(Real bounceTime) = 0;
            /**
             * @brief Get the bounce time.
             * @return The bounce time in seconds.
             */
            virtual Real GetBounceTime() const = 0;

            /**
             * @brief Set the bounce interpolation.
             * The bounce interpolation is applied when moving back from the
             * damping area to the minimum / maximum position.
             * @param interpolation The bounce interpolation.
             */
            virtual void SetBounceInterpolation(IEnums::Interpolation interpolation) = 0;
            /**
             * @brief Get the bounce interpolation.
             * @return The bounce interpolation.
             */
            virtual IEnums::Interpolation GetBounceInterpolation() const = 0;

            /**
             * @brief Get the current position.
             * @return The current position in units.
             */
            virtual const Vector& GetPosition() const = 0;
            /**
             * @brief Set the current position.
             * If setting the position simply set the "real" position from input,
             * this method calculates immediately the resulting damped position
             * if necessary, use GetPosition() to get the resulting position.
             * @param position The current position in units.
             */
            virtual void SetPosition(const Vector& position) = 0;

            /**
             * @brief Start a position animation.
             * The position animation starts at the current position and
             * and can be triggered only if the ScrollProcessor is not active.
             * @param duration The animation duration in seconds.
             * @param position The destination position in units.
             * @param interpolation The interpolation type.
             * @return true if the animation was started successfully,
             *  false if the ScrollProcessor is already active.
             */
            virtual Bool MoveToPosition(Real duration, const Vector& position,
                                        IEnums::Interpolation interpolation = IEnums::INTERPOLATION_EASE_IN_OUT) = 0;
            /**
             * @brief Check if the position animation is running.
             * @return true if running.
             */
            virtual Bool IsMoveToPositionRunning() const = 0;
            /**
             * @brief Check if the position animation has stopped running.
             * If the animation is stopped, this state is true within the current
             * logic tick only and will be cleared at the next logic tick.
             * @return true if stopped.
             */
            virtual Bool WasMoveToPositionRunning() const = 0;
            /** @} */
            
        protected:
            virtual ~IScrollProcessor() {}
        };
    }
}

#endif // __MURL_LOGIC_I_SCROLL_PROCESSOR_H__
