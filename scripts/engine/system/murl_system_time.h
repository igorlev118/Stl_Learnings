// Copyright 2010-2015 Spraylight GmbH

#ifndef __MURL_SYSTEM_TIME_H__
#define __MURL_SYSTEM_TIME_H__

#include "murl_util_string.h"

namespace Murl
{
    namespace System
    {
        /**
         * @ingroup MurlSystemClasses
         * @brief The time class provides high resolution time data.
         */
        class Time
        {
        public:
            enum
            {
                MILLI_SECONDS_PER_SECOND        = 1000,
                MICRO_SECONDS_PER_SECOND        = MILLI_SECONDS_PER_SECOND * 1000,
                NANO_SECONDS_PER_SECOND         = MICRO_SECONDS_PER_SECOND * 1000,

                MICRO_SECONDS_PER_MILLI_SECOND  = 1000,
                NANO_SECONDS_PER_MILLI_SECOND   = MICRO_SECONDS_PER_MILLI_SECOND * 1000,

                NANO_SECONDS_PER_MICRO_SECOND   = 1000
            };

            /**
             * @brief Get the current time-of-day.
             *  The time is the number of seconds since 00:00 hours, Jan 1, 1970 UTC.
             * @return The Time object containing the time from now.
             */
            static Time GetNow();

            /**
             * @brief Get the current tick count.
             *  The tick count is the absolute elapsed time since some arbitrary,
             *  fixed point in the past.\n
             *  It is not affected by changes in the system time-of-day clock.
             * @return The Time object containing the current tick count.
             */
            static Time GetTickCount();

            /**
             * @brief Get the time from specified seconds.
             * @param seconds The number of seconds.
             * @return The Time object containing the number of seconds.
             */
            static Time FromSeconds(UInt64 seconds);

            /**
             * @brief Get the time from specified milliseconds.
             * @param milliSeconds The number of milliseconds.
             * @return The Time object containing the number of milliseconds.
             */
            static Time FromMilliSeconds(UInt64 milliSeconds);

            /**
             * @brief Get the time from specified microseconds.
             * @param microSeconds The number of microseconds.
             * @return The Time object containing the number of microseconds.
             */
            static Time FromMicroSeconds(UInt64 microSeconds);

            /**
             * @brief Get the time from specified nanoseconds.
             * @param nanoSeconds The number of nanoseconds.
             * @return The Time object containing the number of nanoseconds.
             */
            static Time FromNanoSeconds(UInt64 nanoSeconds);

            /**
             * @brief Get zero time.
             * @return The Time object containing zero time.
             */
            static Time Zero();

            /**
             * @brief Get infinite time.
             * @return The Time object containing infinite time.
             */
            static Time Infinite();

            /**
             * @brief Get minimum time.
             * @return The Time object containing zero time.
             */
            static Time Min();

            /**
             * @brief Get maximum time.
             * @return The Time object containing infinite time.
             */
            static Time Max();

            /**
             * @brief The default constructor.
             * The time is set to zero.
             */
            Time();

            /**
             * @brief Constructor taking floating point seconds.
             * @param seconds The number of seconds.
             */
            Time(Double seconds);

            /**
             * @brief Constructor taking integer seconds.
             * @param seconds The number of seconds.
             */
            Time(UInt64 seconds);

            /**
             * @brief Constructor taking seconds and nanoseconds.
             * @param seconds The number of seconds.
             * @param nanoSeconds The number of nanoseconds.
             */
            Time(UInt64 seconds, UInt64 nanoSeconds);

            /**
             * @brief Set to the current time-of-day.
             *  The time is the number of seconds since 00:00 hours, Jan 1, 1970 UTC.
             */
            void SetNow();

            /**
             * @brief Set to the current tick count.
             *  The tick count is the absolute elapsed time since some arbitrary,
             *  fixed point in the past.\n
             *  It is not affected by changes in the system time-of-day clock.
             */
            void SetTickCount();

            /**
             * @brief Set to the zero time.
             */
            void SetZero();

            /**
             * @brief Set to the infinite time.
             */
            void SetInfinite();

            /**
             * @brief Get the time in floating point seconds.
             * @return The time in number of seconds.
             */
            Double GetDouble() const;

            /**
             * @brief Set the time from floating point seconds.
             * @param seconds The time in number of seconds.
             */
            void SetDouble(Double seconds);

            /**
             * @brief Get the time in integer seconds.
             * @return The time in seconds.
             */
            UInt64 GetSeconds() const;

            /**
             * @brief Set the time in integer seconds.
             * @param seconds The time in seconds.
             */
            void SetSeconds(UInt64 seconds);

            /**
             * @brief Get the time in milliseconds.
             * @return The time in milliseconds.
             */
            UInt64 GetMilliSeconds() const;

            /**
             * @brief Set the time in milliseconds.
             * @param milliSeconds The time in milliseconds.
             */
            void SetMilliSeconds(UInt64 milliSeconds);

            /**
             * @brief Get the time in microseconds.
             * @return The time in microseconds.
             */
            UInt64 GetMicroSeconds() const;

            /**
             * @brief Set the time in microseconds.
             * @param microSeconds The time in microseconds.
             */
            void SetMicroSeconds(UInt64 microSeconds);

            /**
             * @brief Get the time in nanoseconds.
             * @return The time in nanoseconds.
             */
            UInt64 GetNanoSeconds() const;

            /**
             * @brief Set the time in nanoseconds.
             * @param nanoSeconds The time in nanoseconds.
             */
            void SetNanoSeconds(UInt64 nanoSeconds);

            /**
             * @brief Get the seconds fractional part in milliseconds.
             * @return The seconds fractional part in milliseconds.
             */
            UInt64 GetMilliSecondsFraction() const;

            /**
             * @brief Get the seconds fractional part in microseconds.
             * @return The seconds fractional part in microseconds.
             */
            UInt64 GetMicroSecondsFraction() const;

            /**
             * @brief Get the seconds fractional part in nanoseconds.
             * @return The seconds fractional part in nanoseconds.
             */
            UInt64 GetNanoSecondsFraction() const;

            /**
             * @brief Check if the time is zero.
             * @return true if the time is zero.
             */
            Bool IsZero() const;
            
            /**
             * @brief Check if the time is infinite.
             * @return true if the time is infinite.
             */
            Bool IsInfinite() const;

            /**
             * @brief In-place addition operator.
             * @param rhs The time to add.
             * @return The object itself.
             */
            Time& operator+=(const Time& rhs);

            /**
             * @brief In-place subtraction operator.
             * @param rhs The time to subtract.
             * @return The object itself.
             */
            Time& operator-=(const Time& rhs);

            /**
             * @brief Addition operator.
             * @param rhs The right hand side time.
             * @return The added time.
             */
            Time operator+(const Time& rhs) const;

            /**
             * @brief Subtraction operator.
             * @param rhs The right hand side time.
             * @return The subtracted time.
             */
            Time operator-(const Time& rhs) const;

            /**
             * @brief Equal to comparison operator.
             * @param rhs The right hand side time to compare.
             * @return true if the time is the same.
             */
            bool operator==(const Time& rhs) const;

            /**
             * @brief Not equal to comparison operator.
             * @param rhs The right hand side time to compare.
             * @return true if the time is not the same.
             */
            bool operator!=(const Time& rhs) const;

            /**
             * @brief Less than operator.
             * @param rhs The right hand side time to compare.
             * @return true if the left hand side (this) is
             * less than the right hand side.
             */
            bool operator<(const Time& rhs) const;

            /**
             * @brief Less than or equal to operator.
             * @param rhs The right hand side time to compare.
             * @return true if the left hand side (this) is
             * less than or equal to the right hand side.
             */
            bool operator<=(const Time& rhs) const;

            /**
             * @brief Greater than operator.
             * @param rhs The right hand side time to compare.
             * @return true if the left hand side (this) is
             * greater than the right hand side.
             */
            bool operator>(const Time& rhs) const;

            /**
             * @brief Greater than or equal to operator.
             * @param rhs The right hand side time to compare.
             * @return true if the left hand side (this) is
             * greater than or equal to the right hand side.
             */
            bool operator>=(const Time& rhs) const;

            /**
             * @brief Get the string representation of the object.
             * @return The string representation of the object.
             */
            String ToString() const;

        protected:
            /** @brief The seconds. */
            UInt64 mSeconds;
            /** @brief The nanoseconds fraction. */
            UInt64 mNanoSeconds;
        };

        /**
         * @ingroup MurlSystemClasses
         * @brief The date and time class provides date and time members.
         */
        class DateTime
        {
        public:
            /**
             * @brief Get the date and time from now.
             * @return The DateTime object containing the date and time from now.
             */
            static DateTime GetNow();

            /**
             * @brief The default constructor.
             * All members are initialized to zero.
             */
            DateTime();

            /**
             * @brief Constructor taking a time object.
             * @param time The number of seconds since 00:00 hours, Jan 1, 1970 UTC.
             */
            DateTime(const Time& time);

            /**
             * @brief Get the string representation of the object.
             * @return The string representation of the object.
             */
            String ToString() const;

            /** @brief The hours since midnight in range [0 .\ .\ 23]. */
            UInt32 mHour;
            /** @brief The minutes after the hour in range [0 .\ .\ 59]. */
            UInt32 mMinute;
            /** @brief The seconds after the minute in range [0 .\ .\ 59]. */
            UInt32 mSecond;

            /** @brief The year anno domini. */
            SInt32 mYear;
            /** @brief The month in range [1 .\ .\ 12]. */
            UInt32 mMonth;
            /** @brief The day in range [1 .\ .\ 31]. */
            UInt32 mDay;

            /** @brief The day of week in range [0 .\ .\ 6] == [Monday .\ .\ Sunday]. */
            UInt32 mDayOfWeek;
            /** @brief The day of year in range [0 .\ .\ 365]. */
            UInt32 mDayOfYear;
        };
    }
}

#endif  // __MURL_SYSTEM_TIME_H__
