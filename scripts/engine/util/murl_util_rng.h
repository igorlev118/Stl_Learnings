// Copyright 2010-2015 Spraylight GmbH

#ifndef __MURL_UTIL_RNG_H__
#define __MURL_UTIL_RNG_H__

#include "murl_array.h"

namespace Murl
{
    namespace Util
    {
        /**
         * @ingroup MurlUtilRngClasses
         * @brief The random number generator base class.
         * The base class is abstract and is implemented
         * by the TT800, Well1024 and Marsaglia class.
         */
        class Rng
        {
        public:
            /**
             * @brief The destructor.
             */
            virtual ~Rng();

            /**
             * @brief Seed the random number generator.
             * @param seed The seed value.
             */
            virtual void Seed(UInt32 seed) = 0;

            /**
             * @brief Get a random number in the full UInt32 range.
             * @return The random number.
             */
            virtual UInt32 Rand() = 0;

            /**
             * @brief Get a random Bool value.
             * @return The random Bool value.
             */
            Bool RandBool();

            /**
             * @brief Get a random UInt32 value within a specified range.
             * It is supported to pass a range of from > to.
             * @param from The start of the range.
             * @param to The end of the range.
             * @return The random UInt32 value in range [from .. to].
             */
            UInt32 RandUInt(UInt32 from, UInt32 to);

            /**
             * @brief Get a random SInt32 value within a specified range.
             * It is supported to pass a range of from > to.
             * @param from The start of the range.
             * @param to The end of the range.
             * @return The random SInt32 value in range [from .. to].
             */
            SInt32 RandSInt(SInt32 from, SInt32 to);

            /**
             * @brief Get a random Real value within a specified range.
             * Scales (from - to) within a 32 bit random number.
             * It is supported to pass a range of from > to.
             * @param from The start of the range.
             * @param to The end of the range.
             * @return The random Real value in range [from .. to].
             */
            Real RandReal(Real from, Real to);

            /**
             * @brief Get a random Double value within a specified range.
             * Scales (from - to) within a 64 bit random number.
             * It is supported to pass a range of from > to.
             * @param from The start of the range.
             * @param to The end of the range.
             * @return The random Real value in range [from .. to].
             */
            Double RandDouble(Double from, Double to);

            /**
             * @brief Draw an index from a distribution array.
             * The distribution array contains numbers which
             * are defining the probability of the partition.
             * The higher the value of the partition, the higher
             * is the probability of drawing the partition.
             * @param distribution An array of partitions.
             * @return The index of the drawn partition
             *  or -1 if all partitions are zero.
             */
            SInt32 Draw(const UInt32Array& distribution);

            /**
             * @brief Draw an index from a distribution array with no replacement.
             * Draw() and set the drawn partition to zero.
             * @param distribution An array of partitions.
             * @return The index of the drawn partition
             *  or -1 if all partitions are zero.
             */
            SInt32 DrawNoReplacement(UInt32Array& distribution);

            /**
             * @brief Draw an index from a distribution array with no replacement.
             * Draw() and decrement the drawn partition by a specified value.
             * @param distribution An array of partitions.
             * @param decrement The value to decrement the drawn partition.
             *  The drawn partition is set to zero if the decrement underflows the partition.
             * @return The index of the drawn partition
             *  or -1 if all partitions are zero.
             */
            SInt32 DrawNoReplacement(UInt32Array& distribution, UInt32 decrement);

        protected:
            /**
             * @brief The default constructor.
             */
            Rng();
        };

        /**
         * @ingroup MurlUtilRngClasses
         * @brief The marsaglia random number generator.
         * The marsaglia generator has low quality with a period
         * of 2^32 only, but calculates fast results and uses
         * 32 bit state memory only. The better choice with an
         * acceptable overhead is the TT800 or Well1024 class.
         */
        class Marsaglia : public Rng
        {
        public:
            /**
             * @brief The default constructor.
             * Seed() the random number generator with the
             * current time nanoseconds fraction.
             */
            Marsaglia();

            /**
             * @brief Constructor taking a seed value.
             * @param seed The seed value.
             */
            Marsaglia(UInt32 seed);

            /**
             * @brief The destructor.
             */
            virtual ~Marsaglia();

            /**
             * @brief Seed the random number generator.
             * @param seed The seed value.
             */
            virtual void Seed(UInt32 seed);

            /**
             * @brief Get a random number in the full UInt32 range.
             * @return The random number.
             */
            virtual UInt32 Rand();

        protected:
            UInt32 mState;
        };

        /**
         * @ingroup MurlUtilRngClasses
         * @brief The TT800 random number generator.
         * The TT800 generator has high quality with a period of 2^800.
         * The TT800 is a light version of the Mersenne-Twister generator.
         */
        class TT800 : public Rng
        {
        public:
            /**
             * @brief The default constructor.
             * Seed() the random number generator with the
             * current time nanoseconds fraction.
             */

            TT800();
            /**
             * @brief Constructor taking a seed value.
             * @param seed The seed value.
             */
            TT800(UInt32 seed);

            /**
             * @brief The destructor.
             */
            virtual ~TT800();

            /**
             * @brief Seed the random number generator.
             * The seed is used for a temporary Marsaglia generator
             * which is used for initializing the internal 800 bit state.
             * @param seed The seed value.
             */
            virtual void Seed(UInt32 seed);

            /**
             * @brief Get a random number in the full UInt32 range.
             * @return The random number.
             */
            virtual UInt32 Rand();

        protected:
            enum { TT800_BYTE_LENGTH = 25 };
            UInt32 mIndex;
            UInt32 mState[TT800_BYTE_LENGTH];
        };

        /**
         * @ingroup MurlUtilRngClasses
         * @brief The Well random number generator.
         * The Well1024 generator has high quality with a period of 2^1024.
         */
        class Well1024 : public Rng
        {
        public:
            /**
             * @brief The default constructor.
             * Seed() the random number generator with the
             * current time nanoseconds fraction.
             */

            Well1024();
            /**
             * @brief Constructor taking a seed value.
             * @param seed The seed value.
             */
            Well1024(UInt32 seed);

            /**
             * @brief The destructor.
             */
            virtual ~Well1024();

            /**
             * @brief Seed the random number generator.
             * The seed is used for a temporary Marsaglia generator
             * which is used for initializing the internal 1024 bit state.
             * @param seed The seed value.
             */
            virtual void Seed(UInt32 seed);

            /**
             * @brief Get a random number in the full UInt32 range.
             * @return The random number.
             */
            virtual UInt32 Rand();

        protected:
            enum { Well1024_BYTE_LENGTH = 32 };
            UInt32 mIndex;
            UInt32 mState[Well1024_BYTE_LENGTH];

            inline UInt32 GetIndex(UInt32 offset) const
            {
                return (mIndex + offset) & UInt32(Well1024_BYTE_LENGTH - 1);
            }

            inline UInt32 GetState(UInt32 offset) const
            {
                return mState[GetIndex(offset)];
            }

            inline UInt32 Mat0Pos(UInt32 t, UInt32 v) const
            {
                return v ^ (v >> t);
            }

            inline UInt32 Mat0Neg(UInt32 t, UInt32 v) const
            {
                return v ^ (v << t);
            }
        };
    }
}

#endif  // __MURL_UTIL_RNG_H__
