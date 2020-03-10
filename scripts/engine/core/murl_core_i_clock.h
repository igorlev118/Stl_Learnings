// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_CORE_I_CLOCK_H__
#define __MURL_CORE_I_CLOCK_H__

#include "murl_core_types.h"
#include "murl_system_time.h"

namespace Murl
{
    namespace Core
    {
        /**
         * @ingroup MurlCoreInterfaces
         * @interface IClock
         * @brief The clock interface.
         * The clock is used by the engine core to determine frame duration and logik ticks.
         * The engine clock is configured by the IEngineConfiguration interface.
         */
        class IClock
        {
        public:
            /**
             * @brief Set the maximum frame duration.
             * The default value is 1000 milliseconds.
             * @param limit The maximum frame duration.
             */
            virtual void SetDeltaLimit(System::Time limit) = 0;
            /**
             * @brief Get the maximum frame duration.
             * @return The maximum frame duration.
             */
            virtual System::Time GetDeltaLimit() const = 0;
            
            /**
             * @brief Set the time base factor.
             * The delta time is multiplied by the time base factor.
             * The default time base factor is 1.0.
             * @param timeBase The time base factor.
             */
            virtual void SetTimeBase(Double timeBase) = 0;
            /**
             * @brief Get the time base factor.
             * @return The time base factor.
             */
            virtual Double GetTimeBase() const = 0;
            
            /**
             * @brief Set the averaging factor.
             * The delta time is multiplied by the averaging factor plus
             * the last delta time multiplied by 1 - the averaging factor.
             * The default averaging factor is 0.1.
             * @param factor The averaging factor.
             */
            virtual void SetAveragingFactor(Double factor) = 0;
            /**
             * @brief Get the averaging factor.
             * @return The averaging factor.
             */
            virtual Double GetAveragingFactor() const = 0;
            
            /**
             * @brief Start the clock measurement.
             */
            virtual void Start() = 0;
            /**
             * @brief Stop the clock measurement.
             */
            virtual void Stop() = 0;
            /**
             * @brief Pause the logic tick measurement.
             */
            virtual void PauseLogicTicks() = 0;
            /**
             * @brief Continue the logic tick measurement.
             */
            virtual void ContinueLogicTicks() = 0;
            /**
             * @brief Reset the internally filtered delta value.
             * @param frameDuration The desired frame duration, or 0.0 if variable.
             * @param numFrames The number of subsequent frames where averaging is
             *      disabled.
             */
            virtual void ResetAveraging(System::Time frameDuration, UInt32 numFrames) = 0;
            /**
             * @brief Update the clock measurement.
             * The clock is updated every time a frame is drawn.
             * At this point the clock measures the frame duration and
             * calculates the logic ticks.
             */
            virtual void Update() = 0;
            
            /**
             * @brief Reset the total running time.
             */
            virtual void ResetTotalRunningTime() = 0;
            /**
             * @brief Get the total running time.
             * @return The total running time.
             */
            virtual System::Time GetTotalRunningTime() const = 0;
            /**
             * @brief Get the current time.
             * @return The current time.
             */
            virtual System::Time GetCurrentTime() const = 0;
            
            /**
             * @brief Get the number of logic ticks per frame.
             * @return The number of logic ticks per frame.
             */
            virtual UInt32 GetNumberOfLogicTicksPerFrame() const = 0;
            
            /**
             * @brief Get the frame number.
             * @return The frame number.
             */
            virtual UInt32 GetFrameNumber() const = 0;
            /**
             * @brief Get the logick tick number.
             * @return The logick tick number.
             */
            virtual UInt32 GetLogicTickNumber() const = 0;
            
            /**
             * @brief Get the frame time.
             * @return The frame time.
             */
            virtual Double GetFrameTime() const = 0;
            /**
             * @brief Get the logick tick time.
             * @return The logick tick time.
             */
            virtual Double GetLogicTickTime() const = 0;
            
            /**
             * @brief Get the frame duration.
             * @return The frame duration.
             */
            virtual Double GetFrameDuration() const = 0;
            /**
             * @brief Get the logick tick duration.
             * @return The logick tick duration.
             */
            virtual Double GetLogicTickDuration() const = 0;
            
        protected:
            virtual ~IClock() {}
        };
    }
}

#endif  // __MURL_CORE_I_CLOCK_H__
