// Copyright 2015 Spraylight

#ifndef __MURL_I_ENUMS_ANIMTION_H__
#define __MURL_I_ENUMS_ANIMTION_H__

#include "murl_enum.h"

namespace Murl
{
    namespace IEnums
    {
        /**
         * @addtogroup MurlAnimationEnumerations
         * @brief Animation items enumerations.
         * @{
         */

        /**
         * @brief Predefined interpolation curves (easing functions).
         */
        enum Interpolation
        {
            /// Constant y=0
            MURL_DECLARE_ENUM_VALUE(INTERPOLATION, CONSTANT)
            /// Linear y=x
            MURL_DECLARE_ENUM_VALUE(INTERPOLATION, LINEAR)

            /// Ease (cubic) "in" EaseIn(x)=x^3, y=EaseIn(x)
            MURL_DECLARE_ENUM_VALUE(INTERPOLATION, EASE_IN)
            /// Ease (cubic) "out" y=1-EaseIn(1-x)
            MURL_DECLARE_ENUM_VALUE(INTERPOLATION, EASE_OUT)
            /// Ease (cubic) "in-out" y=(x < 0.5) ? EaseIn(2*x)/2 : 1-EaseIn(2-2*x)/2
            MURL_DECLARE_ENUM_VALUE(INTERPOLATION, EASE_IN_OUT)
            /// Ease (cubic) "out-in" y=4*EaseIn(x-0.5)+0.5
            MURL_DECLARE_ENUM_VALUE(INTERPOLATION, EASE_OUT_IN)

            /// Smoothstep "in" y=SmoothstepInOut(x/2)*2
            MURL_DECLARE_ENUM_VALUE(INTERPOLATION, SMOOTHSTEP_IN)
            /// Smoothstep "out" y=SmoothstepInOut((x+1)/2)*2-1
            MURL_DECLARE_ENUM_VALUE(INTERPOLATION, SMOOTHSTEP_OUT)
            /// Smoothstep "in-out" SmoothstepInOut(x)=(x^2)*(3-2*x), y=SmoothstepInOut(x)
            MURL_DECLARE_ENUM_VALUE(INTERPOLATION, SMOOTHSTEP_IN_OUT)
            /// Smoothstep "out-in" y=(x < 0.5) ? SmoothstepInOut(x+0.5)-0.5 : SmoothstepInOut(x-0.5)+0.5
            MURL_DECLARE_ENUM_VALUE(INTERPOLATION, SMOOTHSTEP_OUT_IN)

            /// Smootherstep "in" y=SmootherstepInOut(x/2)*2
            MURL_DECLARE_ENUM_VALUE(INTERPOLATION, SMOOTHERSTEP_IN)
            /// Smootherstep "out" y=SmootherstepInOut((x+1)/2)*2-1
            MURL_DECLARE_ENUM_VALUE(INTERPOLATION, SMOOTHERSTEP_OUT)
            /// Smootherstep "in-out" SmootherstepInOut(x)=(x^3)*(x*(6*x-15)+10), y=SmootherstepInOut(x)
            MURL_DECLARE_ENUM_VALUE(INTERPOLATION, SMOOTHERSTEP_IN_OUT)
            /// Smootherstep "out-in" y=(x < 0.5) ? SmootherstepInOut(x+0.5)-0.5 : SmootherstepInOut(x-0.5)+0.5
            MURL_DECLARE_ENUM_VALUE(INTERPOLATION, SMOOTHERSTEP_OUT_IN)

            /// Ease Quart "in" EaseQuartIn(x)=x^4, y=EaseQuartIn(x)
            MURL_DECLARE_ENUM_VALUE(INTERPOLATION, EASE_QUART_IN)
            /// Ease Quart "out" y=1-EaseQuartIn(1-x)
            MURL_DECLARE_ENUM_VALUE(INTERPOLATION, EASE_QUART_OUT)
            /// Ease Quart "in-out" y=(x < 0.5) ? EaseQuartIn(2*x)/2 : 1-EaseQuartIn(2-2*x)/2
            MURL_DECLARE_ENUM_VALUE(INTERPOLATION, EASE_QUART_IN_OUT)
            /// Ease Quart "out-in" y=(x < 0.5) ? 0.5-EaseQuartIn(1-2*x)/2 : 0.5+EaseQuartIn(2*x-1)/2
            MURL_DECLARE_ENUM_VALUE(INTERPOLATION, EASE_QUART_OUT_IN)

            /// Ease Exponential "in" EaseExponentialIn(x)=(2^8x)*x/256, y=EaseExponentialIn(x)
            MURL_DECLARE_ENUM_VALUE(INTERPOLATION, EASE_EXPONENTIAL_IN)
            /// Ease Exponential "out" y=1-EaseExponentialIn(1-x)
            MURL_DECLARE_ENUM_VALUE(INTERPOLATION, EASE_EXPONENTIAL_OUT)
            /// Ease Exponential "in-out" y=(x < 0.5) ? EaseExponentialIn(2*x)/2 : 1-EaseExponentialIn(2-2*x)/2
            MURL_DECLARE_ENUM_VALUE(INTERPOLATION, EASE_EXPONENTIAL_IN_OUT)
            /// Ease Exponential "out-in" y=(x < 0.5) ? 0.5-EaseExponentialIn(1-2*x)/2 : 0.5+EaseExponentialIn(2*x-1)/2
            MURL_DECLARE_ENUM_VALUE(INTERPOLATION, EASE_EXPONENTIAL_OUT_IN)

            /// Ease Circular "in" y=1-sqrt(1-x^2)
            MURL_DECLARE_ENUM_VALUE(INTERPOLATION, EASE_CIRCULAR_IN)
            /// Ease Circular "out" y=sqrt((2-x)*x)
            MURL_DECLARE_ENUM_VALUE(INTERPOLATION, EASE_CIRCULAR_OUT)
            /// Ease Circular "in-out" y=(x < 0.5) ? 0.5-EaseCircularHelper(x+0.5) : 0.5+EaseCircularHelper(x-0.5)
            MURL_DECLARE_ENUM_VALUE(INTERPOLATION, EASE_CIRCULAR_IN_OUT)
            /// Ease Circular "out-in" EaseCircularHelper(x)=sqrt(x-x^2), y=(x < 0.5) ? EaseCircularHelper(x) : 1-EaseCircularHelper(x)
            MURL_DECLARE_ENUM_VALUE(INTERPOLATION, EASE_CIRCULAR_OUT_IN)

            /// Ease Back "in" EaseBackIn(x)=(x^3)-x*sin(x*PI), y=EaseBackIn(x)
            MURL_DECLARE_ENUM_VALUE(INTERPOLATION, EASE_BACK_IN)
            /// Ease Back "out" y=1-EaseBackIn(1-x)
            MURL_DECLARE_ENUM_VALUE(INTERPOLATION, EASE_BACK_OUT)
            /// Ease Back "in-out" y=(x < 0.5) ? EaseBackIn(2*x)/2 : 1-EaseBackIn(2-2*x)/2
            MURL_DECLARE_ENUM_VALUE(INTERPOLATION, EASE_BACK_IN_OUT)
            /// Ease Back "out-in" y=(x < 0.5) ? 0.5-EaseBackIn(1-2*x)/2 : 0.5+EaseBackIn(2*x-1)/2
            MURL_DECLARE_ENUM_VALUE(INTERPOLATION, EASE_BACK_OUT_IN)

            /// Ease Elastic "in" EaseElasticIn(x)=sin(13*PI/2*x)*2^(10*(x-1)), y=EaseElasticIn(x)
            MURL_DECLARE_ENUM_VALUE(INTERPOLATION, EASE_ELASTIC_IN)
            /// Ease Elastic "out" y=1-EaseElasticIn(1-x)
            MURL_DECLARE_ENUM_VALUE(INTERPOLATION, EASE_ELASTIC_OUT)
            /// Ease Elastic "in-out" y=(x < 0.5) ? EaseElasticIn(2*x)/2 : 1-EaseElasticIn(2-2*x)/2
            MURL_DECLARE_ENUM_VALUE(INTERPOLATION, EASE_ELASTIC_IN_OUT)
            /// Ease Elastic "out-in" y=(x < 0.5) ? 0.5-EaseElasticIn(1-2*x)/2 : 0.5+EaseElasticIn(2*x-1)/2
            MURL_DECLARE_ENUM_VALUE(INTERPOLATION, EASE_ELASTIC_OUT_IN)

            /// Ease Bounce "in" three and a halve growing bounces
            MURL_DECLARE_ENUM_VALUE(INTERPOLATION, EASE_BOUNCE_IN)
            /// Ease Bounce "out" a halve and three shrinking bounces
            MURL_DECLARE_ENUM_VALUE(INTERPOLATION, EASE_BOUNCE_OUT)
            /// Ease Bounce "in-out" combined in-out bounces
            MURL_DECLARE_ENUM_VALUE(INTERPOLATION, EASE_BOUNCE_IN_OUT)
            /// Ease Bounce "out-in" combined out-in bounces
            MURL_DECLARE_ENUM_VALUE(INTERPOLATION, EASE_BOUNCE_OUT_IN)

            /// Cubic Bezier interpolation
            MURL_DECLARE_ENUM_VALUE(INTERPOLATION, CUBIC_BEZIER)

            NUM_INTERPOLATIONS,

            /// Deprecated, equal to IEnums::INTERPOLATION_SMOOTHSTEP_IN
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(INTERPOLATION, HERMITE_EASE_IN, INTERPOLATION_SMOOTHSTEP_IN)
            /// Deprecated, equal to IEnums::INTERPOLATION_SMOOTHSTEP_OUT
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(INTERPOLATION, HERMITE_EASE_OUT, INTERPOLATION_SMOOTHSTEP_OUT)
            /// Deprecated, equal to IEnums::INTERPOLATION_SMOOTHSTEP_IN_OUT
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(INTERPOLATION, HERMITE_EASE_IN_OUT, INTERPOLATION_SMOOTHSTEP_IN_OUT)
            /// Deprecated, equal to IEnums::INTERPOLATION_SMOOTHSTEP_OUT_IN
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(INTERPOLATION, HERMITE_EASE_OUT_IN, INTERPOLATION_SMOOTHSTEP_OUT_IN)
        };
        MURL_DECLARE_ENUM_ACCESSOR(Interpolation)

        /**
         * @brief Arithmetic/logic operations.
         */
        enum AluOperation
        {
            /// Copy
            MURL_DECLARE_ENUM_VALUE(ALU_OPERATION, COPY)
            /// Replace
            MURL_DECLARE_ENUM_VALUE(ALU_OPERATION, REPLACE)

            /// Addition
            MURL_DECLARE_ENUM_VALUE(ALU_OPERATION, ADD)
            /// Subtraction other - this
            MURL_DECLARE_ENUM_VALUE(ALU_OPERATION, SUBTRACT)
            /// Subtraction this - other
            MURL_DECLARE_ENUM_VALUE(ALU_OPERATION, SUBTRACT_REVERSE)
            /// Multiplication
            MURL_DECLARE_ENUM_VALUE(ALU_OPERATION, MULTIPLY)
            /// Division other / this
            MURL_DECLARE_ENUM_VALUE(ALU_OPERATION, DIVIDE)
            /// Division this / other
            MURL_DECLARE_ENUM_VALUE(ALU_OPERATION, DIVIDE_REVERSE)

            /// Map input values to output values
            MURL_DECLARE_ENUM_VALUE(ALU_OPERATION, MAP)
            /// Map input values to output values with clamping
            MURL_DECLARE_ENUM_VALUE(ALU_OPERATION, MAP_CLAMPED)

            // Compare a < b
            MURL_DECLARE_ENUM_VALUE(ALU_OPERATION, LESS)
            // Compare a <= b
            MURL_DECLARE_ENUM_VALUE(ALU_OPERATION, LESS_OR_EQUAL)
            // Compare a > b
            MURL_DECLARE_ENUM_VALUE(ALU_OPERATION, GREATER)
            // Compare a >= b
            MURL_DECLARE_ENUM_VALUE(ALU_OPERATION, GREATER_OR_EQUAL)
            // Compare a == b
            MURL_DECLARE_ENUM_VALUE(ALU_OPERATION, EQUAL)
            // Compare a != b
            MURL_DECLARE_ENUM_VALUE(ALU_OPERATION, NOT_EQUAL)

            // Negation
            MURL_DECLARE_ENUM_VALUE(ALU_OPERATION, NEGATE)

            // Bitwise/logical inversion
            MURL_DECLARE_ENUM_VALUE(ALU_OPERATION, INVERT)
            // Bitwise/logical AND
            MURL_DECLARE_ENUM_VALUE(ALU_OPERATION, AND)
            // Bitwise/logical OR
            MURL_DECLARE_ENUM_VALUE(ALU_OPERATION, OR)
            // Bitwise/logical XOR
            MURL_DECLARE_ENUM_VALUE(ALU_OPERATION, XOR)

            NUM_ALU_OPERATIONS
        };
        MURL_DECLARE_ENUM_ACCESSOR(AluOperation)

        /**
         * @brief Animation states, e.g. for timelines.
         */
        enum AnimationState
        {
            /// Animation is stopped.
            MURL_DECLARE_ENUM_VALUE(ANIMATION_STATE, STOPPED)
            /// Animation is paused.
            MURL_DECLARE_ENUM_VALUE(ANIMATION_STATE, PAUSED)
            /// Animation is running forward.
            MURL_DECLARE_ENUM_VALUE(ANIMATION_STATE, RUNNING_FORWARD)
            /// Animation is running backward.
            MURL_DECLARE_ENUM_VALUE(ANIMATION_STATE, RUNNING_BACKWARD)

            NUM_ANIMATION_STATES
        };
        MURL_DECLARE_ENUM_ACCESSOR(AnimationState)

        /**
         * @brief Available predefined resource animation keys (bit mask).
         */
        enum AnimationKey
        {
            /// No key.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(ANIMATION_KEY, NONE, 0)

            /// Controls Graph::ITraversable::SetActive().
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(ANIMATION_KEY, ACTIVE,           1 << 0)
            /// Controls Graph::ITraversable::SetVisible().
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(ANIMATION_KEY, VISIBLE,          1 << 1)
            /// Index animation key, for e.g. Graph::ISwitch or Graph::IPlaneSequenceGeometry.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(ANIMATION_KEY, INDEX,            1 << 2)
            /// Depth order animation key, for Graph::ITransformable::SetDepthOrder().
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(ANIMATION_KEY, DEPTH_ORDER,      1 << 3)

            /// Alpha component.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(ANIMATION_KEY, ALPHA,            1 << 4)
            /// Sound volume, e.g. for Graph::IAudible.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(ANIMATION_KEY, VOLUME,           1 << 5)
            /// Time value.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(ANIMATION_KEY, TIME,             1 << 6)

            /// Ambient color, for e.g. Graph::IColored.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(ANIMATION_KEY, AMBIENT_COLOR,    1 << 7)
            /// Diffuse color, for e.g. Graph::IColored.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(ANIMATION_KEY, DIFFUSE_COLOR,    1 << 8)
            /// Specular color, for e.g. Graph::IColored.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(ANIMATION_KEY, SPECULAR_COLOR,   1 << 9)
            /// Emissive color, for e.g. Graph::IColored.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(ANIMATION_KEY, EMISSIVE_COLOR,   1 << 10)

            /// Position key, for Graph::ITransformable:
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(ANIMATION_KEY, POSITION,         1 << 11)
            /// Rotation key, for Graph::ITransformable:
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(ANIMATION_KEY, ROTATION,         1 << 12)
            /// Scaling key, for Graph::ITransformable:
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(ANIMATION_KEY, SCALE,            1 << 13)

            /// Blend factor key, for Graph::IBlendable:
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(ANIMATION_KEY, BLEND_FACTOR,     1 << 14)

            /// Position X key, for Graph::ITransformable:
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(ANIMATION_KEY, POSITION_X,       1 << 15)
            /// Position Y key, for Graph::ITransformable:
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(ANIMATION_KEY, POSITION_Y,       1 << 16)
            /// Position Z key, for Graph::ITransformable:
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(ANIMATION_KEY, POSITION_Z,       1 << 17)

            /// Euler Rotation X key, for Graph::ITransformable:
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(ANIMATION_KEY, ROTATION_X,       1 << 18)
            /// Euler Rotation Y key, for Graph::ITransformable:
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(ANIMATION_KEY, ROTATION_Y,       1 << 19)
            /// Euler Rotation Z key, for Graph::ITransformable:
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(ANIMATION_KEY, ROTATION_Z,       1 << 20)

            /// Scaling X key, for Graph::ITransformable:
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(ANIMATION_KEY, SCALE_X,          1 << 21)
            /// Scaling Y key, for Graph::ITransformable:
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(ANIMATION_KEY, SCALE_Y,          1 << 22)
            /// Scaling Z key, for Graph::ITransformable:
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(ANIMATION_KEY, SCALE_Z,          1 << 23)

            /// All keys combined.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(ANIMATION_KEY, ALL, 0xffffffff)
        };
        MURL_DECLARE_ENUM_ACCESSOR(AnimationKey)

        /**
         * @brief Wave forms.
         */
        enum Waveform
        {
            /// No waveform.
            MURL_DECLARE_ENUM_VALUE(WAVEFORM, NONE)

            /// Constant waveform, i.e. flat line.
            MURL_DECLARE_ENUM_VALUE(WAVEFORM, CONSTANT)
            /// Sine wave, in the range [-1,+1].
            MURL_DECLARE_ENUM_VALUE(WAVEFORM, SINE)
            /// Triangle wave, in the range [0,+1].
            MURL_DECLARE_ENUM_VALUE(WAVEFORM, TRIANGLE)
            /// Saw tooth wave, in the range [0,+1].
            MURL_DECLARE_ENUM_VALUE(WAVEFORM, SAWTOOTH)
            /// Rectangular wave, in the range [0,+1].
            MURL_DECLARE_ENUM_VALUE(WAVEFORM, RECTANGLE)
            /// Noise, in the range [-1,+1].
            MURL_DECLARE_ENUM_VALUE(WAVEFORM, NOISE)
            
            NUM_WAVEFORMS
        };
        MURL_DECLARE_ENUM_ACCESSOR(Waveform)

        /**
         * @brief Trigger conditions.
         */
        enum TriggerCondition
        {
            /// No trigger.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TRIGGER_CONDITION, NONE, 0)

            /// Immediate trigger
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TRIGGER_CONDITION, CLIP_FINISHED, 1 << 0)
            /// Expiration trigger
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TRIGGER_CONDITION, LOOP_FINISHED, 1 << 1)
            /// Variable trigger
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TRIGGER_CONDITION, VARIABLE,      1 << 2)

            /// All triggers combined.
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(TRIGGER_CONDITION, ALL, 0xffffffff)
        };
        MURL_DECLARE_ENUM_ACCESSOR(TriggerCondition)

        /**
         * @brief Blending reference types.
         */
        enum BlendReference
        {
            /// Undefined blend reference.
            MURL_DECLARE_ENUM_VALUE(BLEND_REFERENCE, UNDEFINED)

            /// No blend reference,
            MURL_DECLARE_ENUM_VALUE(BLEND_REFERENCE, NONE)

            /// Use the identity as reference.
            MURL_DECLARE_ENUM_VALUE(BLEND_REFERENCE, IDENTITY)

            /// Use the sum of previous blend operations as reference.
            MURL_DECLARE_ENUM_VALUE(BLEND_REFERENCE, SUM)

            /// Use the first blend target with non-zero weight as reference, without actually considering its weight.
            MURL_DECLARE_ENUM_VALUE(BLEND_REFERENCE, FIRST_WEIGHTED)
            /// Use the first blend target with non-zero weight as reference, considering its weight.
            MURL_DECLARE_ENUM_VALUE(BLEND_REFERENCE, FIRST_UNWEIGHTED)

            NUM_BLEND_REFERENCES
        };
        MURL_DECLARE_ENUM_ACCESSOR(BlendReference)

        /**
         * @brief Blending directions.
         */
        enum BlendDirection
        {
            /// Undefined blend direction.
            MURL_DECLARE_ENUM_VALUE(BLEND_DIRECTION, UNDEFINED)

            /// Blend in arbitrary direction.
            MURL_DECLARE_ENUM_VALUE(BLEND_DIRECTION, ARBITRARY)

            /// Blend the shortest way, considering a given blend reference.
            MURL_DECLARE_ENUM_VALUE(BLEND_DIRECTION, SHORTEST)
            /// Blend the longest way, considering a given blend reference.
            MURL_DECLARE_ENUM_VALUE(BLEND_DIRECTION, LONGEST)

            NUM_BLEND_DIRECTIONS
        };
        MURL_DECLARE_ENUM_ACCESSOR(BlendDirection)

        /** @} */
    }
}

#endif  // __MURL_I_ENUMS_ANIMTION_H__
