// Copyright 2010-2016 Spraylight

#ifndef __MURL_LOGIC_ANIMATION_H__
#define __MURL_LOGIC_ANIMATION_H__

#include "murl_logic_timeline.h"
#include "murl_color.h"
#include "murl_math_interpolation.h"
#include "murl_math_vector.h"

namespace Murl
{
    namespace Logic
    {
        /**
         * @ingroup MurlLogicClasses
         * @brief A template class to create key objects for the Animation class.
         */
        template<class DataType>
        class AnimationKey
        {
        public:
            /** @brief The template parameter value type. */
            typedef DataType ValueType;

            /**
             * @brief The default constructor.
             */
            AnimationKey()
            : mTime()
            , mValue()
            , mInterpolation()
            {
            }

            /**
             * @brief The constructor including time and value.
             * @param time The time for the key in seconds.
             * @param value The value for the key.
             */
            AnimationKey(Real time, const DataType& value)
            : mTime(time)
            , mValue(value)
            , mInterpolation(IEnums::INTERPOLATION_LINEAR)
            {
            }

            /**
             * @brief The constructor including time, value and linear flag.
             * @param time The time for the key in seconds.
             * @param value The value for the key.
             * @param linear true for linear interpolation, false for constant interpolation.
             */
            AnimationKey(Real time, const DataType& value, Bool linear)
            : mTime(time)
            , mValue(value)
            , mInterpolation(linear ? IEnums::INTERPOLATION_LINEAR : IEnums::INTERPOLATION_CONSTANT)
            {
            }

            /**
             * @brief The constructor including time, value and interpolation.
             * @param time The time for the key in seconds.
             * @param value The value for the key.
             * @param interpolation The interpolation type.
             */
            AnimationKey(Real time, const DataType& value, IEnums::Interpolation interpolation)
            : mTime(time)
            , mValue(value)
            , mInterpolation(interpolation)
            {
            }

            /**
             * @brief Compare the animation key to another one.
             * @param other The key to compare.
             * @return true if both keys are identical.
             */
            Bool IsEqual(const AnimationKey& other) const
            {
                return (mTime == other.mTime) && (mValue == other.mValue) && (mInterpolation == other.mInterpolation);
            }

            /**
             * @brief The "equal to" comparison operator, calls IsEqual().
             * @param rhs The right hand side key to compare.
             * @return true if both keys are identical.
             */
            bool operator==(const AnimationKey& rhs) const
            {
                return IsEqual(rhs);
            }
            /**
             * @brief The "not equal to" comparison operator, calls IsEqual().
             * @param rhs The right hand side key to compare.
             * @return true if both keys are not identical.
             */
            bool operator!=(const AnimationKey& rhs) const
            {
                return !IsEqual(rhs);
            }

            /** @brief The time of the key. */
            Real mTime;
            /** @brief The value of the key. */
            DataType mValue;
            /** @brief The interpolation type of the key. */
            IEnums::Interpolation mInterpolation;
        };

        /**
         * @ingroup MurlLogicClasses
         * @brief A template class to create an ITimeline object with
         * key animation capabilities.
         */
        template<class DataType>
        class Animation : public IAppTimeline, public Timeline, NonCopyable
        {
        public:
            /** @brief The template parameter value type. */
            typedef DataType ValueType;

            /** @brief Type definition of the animation key data type. */
            typedef AnimationKey<DataType> Key;

            /** @brief The animation keys array. */
            Array<Key> mKeys;

            /**
             * @brief Add a key to the animation key array.
             * @param key The key to copy and add.
             * @return The added key.
             */
            Key& AddKey(const Key& key)
            {
                return mKeys.Add(key);
            }

            /**
             * @brief Add a key to the animation key array with linear interpolation.
             * @param time The time for the key in seconds.
             * @param value The value for the key.
             * @return The added key.
             */
            Key& AddKey(Real time, const DataType& value)
            {
                return mKeys.Add(Key(time, value));
            }

            /**
             * @brief Add a key to the animation key array.
             * @param time The time for the key in seconds.
             * @param value The value for the key.
             * @param interpolation The interpolation type.
             * @return The added key.
             */
            Key& AddKey(Real time, const DataType& value, IEnums::Interpolation interpolation)
            {
                return mKeys.Add(Key(time, value, interpolation));
            }

            /**
             * @brief Set a key in the animation key array.
             * @param index The zero-based index of the key to set.
             * @param key The key to copy and set.
             * @return The added key.
             */
            Key& SetKey(SInt32 index, const Key& key)
            {
                return mKeys.Set(index, key);
            }

            /**
             * @brief Set a key in the animation key array with linear interpolation.
             * @param index The zero-based index of the key to set.
             * @param time The time for the key in seconds.
             * @param value The value for the key.
             * @return The set key.
             */
            Key& SetKey(SInt32 index, Real time, const DataType& value)
            {
                return mKeys.Set(index, Key(time, value));
            }

            /**
             * @brief Set a key in the animation key array.
             * @param index The zero-based index of the key to set.
             * @param time The time for the key in seconds.
             * @param value The value for the key.
             * @param interpolation The interpolation type.
             * @return The set key.
             */
            Key& SetKey(SInt32 index, Real time, const DataType& value, IEnums::Interpolation interpolation)
            {
                return mKeys.Set(index, Key(time, value, interpolation));
            }

            /**
             * @brief Insert a key to the animation key array.
             * @param index The zero-based index of the key to insert.
             * @param key The key to copy and insert.
             * @return The inserted key.
             */
            Key& InsertKey(SInt32 index, const Key& key)
            {
                return mKeys.Insert(index, key);
            }

            /**
             * @brief Insert a key to the animation key array with linear interpolation.
             * @param index The zero-based index of the key to insert.
             * @param time The time for the key in seconds.
             * @param value The value for the key.
             * @return The inserted key.
             */
            Key& InsertKey(SInt32 index, Real time, const DataType& value)
            {
                return mKeys.Insert(index, Key(time, value));
            }

            /**
             * @brief Insert a key to the animation key array.
             * @param index The zero-based index of the key to insert.
             * @param time The time for the key in seconds.
             * @param value The value for the key.
             * @param interpolation The interpolation type.
             * @return The inserted key.
             */
            Key& InsertKey(SInt32 index, Real time, const DataType& value, IEnums::Interpolation interpolation)
            {
                return mKeys.Insert(index, Key(time, value, interpolation));
            }

            /**
             * @brief Get the number of keys.
             * @return The number of keys.
             */
            SInt32 GetNumberOfKeys() const
            {
                return mKeys.GetCount();
            }

            /**
             * @brief Get a key from the animation key array.
             * @param index The zero-based index of the key.
             * @return The constant key at the specified index.
             */
            const Key& GetKey(SInt32 index) const
            {
                return mKeys.Get(index);
            }

            /**
             * @brief Get a key from the animation key array.
             * @param index The zero-based index of the key.
             * @return The key at the specified index.
             */
            Key& GetKey(SInt32 index)
            {
                return mKeys.Get(index);
            }

            /**
             * @brief Modify the time of a key in the animation key array.
             * @param index The zero-based index of the key to modify.
             * @param time The time for the key in seconds.
             * @return true if successful, false if the index is out of range.
             */
            Bool ModifyKeyTime(SInt32 index, Real time)
            {
                if (mKeys.IsIndexValid(index))
                {
                    mKeys[index].mTime = time;
                    return true;
                }
                return false;
            }

            /**
             * @brief Modify the value of a key in the animation key array.
             * @param index The zero-based index of the key to modify.
             * @param value The value for the key.
             * @return true if successful, false if the index is out of range.
             */
            Bool ModifyKeyValue(SInt32 index, const DataType& value)
            {
                if (mKeys.IsIndexValid(index))
                {
                    mKeys[index].mValue = value;
                    return true;
                }
                return false;
            }

            /**
             * @brief Modify the interpolation of a key in the animation key array.
             * @param index The zero-based index of the key to modify.
             * @param interpolation The interpolation type.
             * @return true if successful, false if the index is out of range.
             */
            Bool ModifyKeyInterpoation(SInt32 index, IEnums::Interpolation interpolation)
            {
                if (mKeys.IsIndexValid(index))
                {
                    mKeys[index].mInterpolation = interpolation;
                    return true;
                }
                return false;
            }

            /**
             * @brief Set the number of keys.
             * @param n The number of keys.
             * @return true if successful.
             */
            Bool SetNumberOfKeys(SInt32 n)
            {
                return mKeys.SetCount(n);
            }

            /**
             * @brief Remove keys at a given position.
             * @param index The zero-based index from where to remove the keys.
             * @param count The number of keys to remove.
             * @return true if successful.
             */
            Bool RemoveKey(SInt32 index, SInt32 count = 1)
            {
                return mKeys.Remove(index, count);
            }

            /**
             * @brief Empty the keys, but keep the underlying storage.
             */
            void EmptyKeys()
            {
                mKeys.Empty();
            }

            /**
             * @brief Clear the keys and remove the underlying storage.
             */
            void ClearKeys()
            {
                mKeys.Clear();
            }

            /**
             * @brief Set keys for an intermediate time and value.
             * Enter an interpolation curve at a variable time with a specified value.
             * \n Setup key 0 with start time zero and key 1 with the given end time;
             * the mid value is the value at mid time using the given interpolation.
             * \n The keys are typically used with Start(midTime, endTime).
             * @param midTime The time between zero and the endTime.
             * @param midValue The value at mid time.
             * @param endTime The end time.
             * @param endValue The value at end time.
             * @param interpolation The interpolation type.
             */
            void SetIntermediateKeys(Real midTime, const DataType& midValue,
                                     Real endTime, const DataType& endValue,
                                     IEnums::Interpolation interpolation)
            {
                Real f = Math::Interpolation(interpolation, midTime / endTime);
                mKeys.Empty();
                mKeys.Set(0, Key(Real(0.0), (midValue - endValue * f) / (Real(1.0) - f), interpolation));
                mKeys.Set(1, Key(endTime, endValue));
            }

            /** @brief The Animation shared pointer type. */
            typedef SharedPointer<Animation> Ptr;

            /**
             * @brief Create an Animation object.
             * @return The Animation shared pointer.
             */
            static Ptr Create()
            {
                Ptr ret = Ptr(new Animation());
                ret->mSelf = ret;
                return ret;
            }

            /**
             * @brief The default constructor.
             */
            Animation()
            : mCurrentValue()
            , mCurrentStartKeyIndex(0)
            {
                SetAppTimeline(IAppTimelinePtr(this, NoDeleter()));
            }

            /**
             * @brief The destructor.
             */
            virtual ~Animation()
            {
            }

            /**
             * @brief Conversion operator.
             * @return The IStepable interface.
             */
            operator IStepablePtr()
            {
                return GetStepable();
            }

            /**
             * @brief Called if the current value is set.
             * This method is empty and can be overwritten.
             * @param currentValue The current value.
             */
            virtual void OnEvaluateAnimation(const DataType& currentValue)
            {
            }

            /**
             * @brief Get the current value.
             * @return The current value.
             */
            virtual const DataType& GetCurrentValue() const
            {
                return mCurrentValue;
            }

            /**
             * @brief Start the timeline forward.
             * The first animation array key is the start time,
             * the last animation array key is the end time.
             * @return true if successful.
             */
            virtual Bool StartForward()
            {
                if (mKeys.GetCount() > 1)
                {
                    return Timeline::Start(mKeys.Bottom().mTime, mKeys.Top().mTime);
                }
                return false;
            }

            /**
             * @brief Start the timeline backward.
             * The last animation array key is the start time,
             * the first animation array key is the end time.
             * @return true if successful.
             */
            virtual Bool StartBackward()
            {
                if (mKeys.GetCount() > 1)
                {
                    return Timeline::Start(mKeys.Top().mTime, mKeys.Bottom().mTime);
                }
                return false;
            }

            /**
             * @brief Set the timeline start time from a specified key index.
             * @param index The zero-based index to the mKeys array.
             * @return true if successful, false if index is out of range.
             */
            virtual Bool SetStartTimeFromKey(SInt32 index)
            {
                if (mKeys.IsIndexValid(index))
                {
                    SetStartTime(mKeys[index].mTime);
                    return true;
                }
                return false;
            }

            /**
             * @brief Set the timeline end time from a specified key index.
             * @param index The zero-based index to the mKeys array.
             * @return true if successful, false if index is out of range.
             */
            virtual Bool SetEndTimeFromKey(SInt32 index)
            {
                if (mKeys.IsIndexValid(index))
                {
                    SetEndTime(mKeys[index].mTime);
                    return true;
                }
                return false;
            }

            /**
             * @brief Set the timeline loop start time from a specified key index.
             * @param index The zero-based index to the mKeys array.
             * @return true if successful, false if index is out of range.
             */
            virtual Bool SetLoopStartTimeFromKey(SInt32 index)
            {
                if (mKeys.IsIndexValid(index))
                {
                    SetLoopStartTime(mKeys[index].mTime);
                    return true;
                }
                return false;
            }

            /**
             * @brief Set the timeline loop end time from a specified key index.
             * @param index The zero-based index to the mKeys array.
             * @return true if successful, false if index is out of range.
             */
            virtual Bool SetLoopEndTimeFromKey(SInt32 index)
            {
                if (mKeys.IsIndexValid(index))
                {
                    SetLoopEndTime(mKeys[index].mTime);
                    return true;
                }
                return false;
            }

            /**
             * @brief Check if the current time has passed the time from a specified key index.
             * Does not consider loops, for evaluating loops see ITimeline::HasPassedLoop().
             * @param index The zero-based index to the mKeys array.
             * @return true if the current time has passed the key time
             *  within the most recent tick.
             */
            virtual Bool HasPassedTimeFromKey(SInt32 index) const
            {
                if (mKeys.IsIndexValid(index))
                {
                    return HasPassedTime(mKeys[index].mTime);
                }
                return false;
            }

            /**
             * @brief Check if the current time is the time from a specified key index.
             * @param index The zero-based index to the mKeys array.
             * @return true if the current time is the key time.
             */
            virtual Bool IsOnTimeFromKey(SInt32 index) const
            {
                if (mKeys.IsIndexValid(index))
                {
                    return GetCurrentTime() == mKeys[index].mTime;
                }
                return false;
            }

            /**
             * Reset the animation.
             */
            virtual void Reset()
            {
                mCurrentStartKeyIndex = 0;
                mCurrentValue = DataType();

                Timeline::Reset();
            }

        protected:
            /**
             * @brief Overwrite of the IAppTimeline::OnEvaluate() method.
             * Calculates the current value from the animation keys depending
             * on the current time.
             * OnEvaluateAnimation() is called after evaluation.
             * @param currentTime The current timeline time.
             */
            virtual void OnEvaluate(Double currentTime)
            {
                if (mKeys.GetCount() > 0)
                {
                    if (mCurrentStartKeyIndex >= mKeys.GetCount())
                    {
                        mCurrentStartKeyIndex = 0;
                    }
                    UInt32 startKeyIndex = mCurrentStartKeyIndex;
                    UInt32 endKeyIndex;

                    if (currentTime < mKeys[startKeyIndex].mTime)
                    {
                        startKeyIndex = 0;
                    }
                    while ((startKeyIndex < (mKeys.GetCount() - 1)) &&
                           (currentTime >= mKeys[startKeyIndex + 1].mTime))
                    {
                        startKeyIndex++;
                    }
                    mCurrentStartKeyIndex = startKeyIndex;

                    if (currentTime < mKeys[startKeyIndex].mTime)
                    {
                        endKeyIndex = startKeyIndex;
                    }
                    else if (startKeyIndex < (mKeys.GetCount() - 1))
                    {
                        endKeyIndex = startKeyIndex + 1;
                    }
                    else
                    {
                        endKeyIndex = startKeyIndex;
                    }

                    const Key& startKey = mKeys[startKeyIndex];
                    const Key& endKey   = mKeys[endKeyIndex];
                    Real keyDuration = endKey.mTime - startKey.mTime;

                    if ((keyDuration > Real(0.0)) && (startKey.mInterpolation != IEnums::INTERPOLATION_CONSTANT))
                    {
                        Double keyOffset = currentTime - startKey.mTime;
                        Double t = keyOffset / keyDuration;
                        t = Math::Interpolation(startKey.mInterpolation, t);
                        mCurrentValue = Math::Lerp(startKey.mValue, endKey.mValue, t);
                    }
                    else
                    {
                        mCurrentValue = startKey.mValue;
                    }
                }

                OnEvaluateAnimation(mCurrentValue);
            }

            DataType mCurrentValue;

            UInt32 mCurrentStartKeyIndex;
        };

        /**
         * @addtogroup MurlLogicClasses
         * @{
         */
        /** @brief Predefined Animation using a Vector data type. */
        typedef Animation<Vector> AnimationVector;
        /** @brief Predefined AnimationKey using a Vector data type. */
        typedef AnimationVector::Key AnimationVectorKey;

        /** @brief Predefined Animation using a Color data type. */
        typedef Animation<Color> AnimationColor;
        /** @brief Predefined AnimationKey using a Color data type. */
        typedef AnimationColor::Key AnimationColorKey;

        /** @brief Predefined Animation using a Real data type. */
        typedef Animation<Real> AnimationReal;
        /** @brief Predefined AnimationKey using a Real data type. */
        typedef AnimationReal::Key AnimationRealKey;

        /** @brief Predefined Animation using a UInt32 data type. */
        typedef Animation<UInt32> AnimationUInt32;
        /** @brief Predefined AnimationKey using a UInt32 data type. */
        typedef AnimationUInt32::Key AnimationUInt32Key;

        /** @brief Predefined Animation using a SInt32 data type. */
        typedef Animation<SInt32> AnimationSInt32;
        /** @brief Predefined AnimationKey using a SInt32 data type. */
        typedef AnimationSInt32::Key AnimationSInt32Key;
        /** @} */

        /** @brief Predefined Animation using a UInt64 data type. */
        typedef Animation<UInt64> AnimationUInt64;
        /** @brief Predefined AnimationKey using a UInt64 data type. */
        typedef AnimationUInt64::Key AnimationUInt64Key;

        /** @brief Predefined Animation using a SInt64 data type. */
        typedef Animation<SInt64> AnimationSInt64;
        /** @brief Predefined AnimationKey using a SInt64 data type. */
        typedef AnimationSInt64::Key AnimationSInt64Key;
        /** @} */
    }
}

#endif // __MURL_LOGIC_ANIMATION_H__
