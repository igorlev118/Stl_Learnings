// Copyright 2015 Spraylight

#ifndef __MURL_MATH_SPLINE_BASE_H__
#define __MURL_MATH_SPLINE_BASE_H__

#include "murl_math_vector.h"
#include "murl_array.h"

namespace Murl
{
    namespace Math
    {
        /**
         * @ingroup MurlMathClasses
         * @brief A template class to create spline key objects for the spline interpolation classes.
         */
        template<class DataType>
        class SplineKey
        {
        public:
            /** @brief The template parameter value type. */
            typedef DataType ValueType;

            /**
             * @brief The default constructor.
             */
            SplineKey()
            : mTime()
            , mValue()
            {
            }

            /**
             * @brief The constructor including time and value.
             * @param time The time for the key in seconds.
             * @param value The value for the key.
             */
            SplineKey(Real time, const DataType& value)
            : mTime(time)
            , mValue(value)
            {
            }

            /**
             * @brief Compare the animation key to another one.
             * @param other The key to compare.
             * @return true if both keys are identical.
             */
            Bool IsEqual(const SplineKey& other) const
            {
                return (mTime == other.mTime) && (mValue == other.mValue);
            }

            /**
             * @brief The "equal to" comparison operator, calls IsEqual().
             * @param rhs The right hand side key to compare.
             * @return true if both keys are identical.
             */
            bool operator==(const SplineKey& rhs) const
            {
                return IsEqual(rhs);
            }
            /**
             * @brief The "not equal to" comparison operator, calls IsEqual().
             * @param rhs The right hand side key to compare.
             * @return true if both keys are not identical.
             */
            bool operator!=(const SplineKey& rhs) const
            {
                return !IsEqual(rhs);
            }

            /** @brief The time of the key. */
            Real mTime;
            /** @brief The value of the key. */
            DataType mValue;
        };

        /**
         * @ingroup MurlMathClasses
         * @brief A template base class for spline interpolations.
         */
        template<class DataType>
        class SplineBase
        {
        public:
            /** @brief The template parameter value type. */
            typedef DataType ValueType;

            /** @brief Type definition of the animation key data type. */
            typedef SplineKey<DataType> Key;

            /**
             * @brief Enumeration of the wrap modes.
             */
            enum WrapMode
            {
                /** No wrapping. */
                WRAP_NONE = 0,
                /** Clamp if time lies outside of the defined curve. */
                WRAP_CLAMP_TO_EDGE,
                /** Repeat infinitely in either direction. */
                WRAP_REPEAT,
                /** Repeat infinitely in either direction, flipping each time. */
                WRAP_REPEAT_MIRRORED
            };

            /**
             * @brief Enumeration of the curve type.
             */
            enum CurveType
            {
                /** Use p[0]/p[n-1] to calculate the control points for first/last point. */
                CURVE_DEFAULT = 0,
                /** Closed curve, use p[n-2]/p[1] to calculate the control points for first/last point. */
                CURVE_CLOSED,
            };

#ifdef MURL_COMPILER_C11
            MURL_STL_INIT_LIST_TYPEDEF(Key);

            /**
             * @brief Add an initializer-list to the keys.
             * @param initList The initializer-list to be added.
             */
            void Add(InitListType initList)
            {
                mKeys.Reserve(mKeys.GetCount() + SInt32(initList.size()));
                for (const Key& item : initList)
                {
                    AddKey(item);
                }
            }

            /**
             * @brief Definition of the keys const iterator.
             */
            typedef const Key* ConstIterator;

            /**
             * @brief Get the const iterator to the first key.
             * @return The const iterator to the first key.
             */
            ConstIterator Begin() const
            {
                return mKeys.Begin();
            }

            /**
             * @brief Get the const iterator next to the last key.
             * @return The const iterator next to the last key.
             */
            ConstIterator End() const
            {
                return mKeys.End();
            }

            MURL_STL_CONST_ITERATOR
#endif  // MURL_COMPILER_C11

            /**
             * @brief The default constructor.
             * The default wrap mode is CLAMP_TO_EDGE.
             * The default curve type is CURVE_DEFAULT.
             */
            SplineBase()
            : mWrapMode(WRAP_NONE)
            , mCurveType(CURVE_DEFAULT)
            , mAreControlPointsValid(false)
            {
            }

            /**
             * @brief Constructor taking the wrap mode and the curve type.
             * @param wrapMode The wrapMode.
             * @param curveType The curveType.
             */
            SplineBase(WrapMode wrapMode, CurveType curveType)
            : mWrapMode(wrapMode)
            , mCurveType(curveType)
            , mAreControlPointsValid(false)
            {
            }

            /**
             * @brief The destructor.
             */
            virtual ~SplineBase()
            {
            }

            /**
             * @brief Set the current curve type.
             * @param curveType The curve type to set.
             */
            void SetCurveType(CurveType curveType)
            {
                mCurveType = curveType;
                mAreControlPointsValid = false;
            }

            /**
             * @brief Get the current curve type.
             * @return The current curve type.
             */
            CurveType GetCurveType() const
            {
                return mCurveType;
            }

            /**
             * @brief Set the current wrap mode.
             * @param wrapMode The wrap mode to set.
             */
            void SetWrapMode(WrapMode wrapMode)
            {
                mWrapMode = wrapMode;
                mAreControlPointsValid = false;
            }

            /**
             * @brief Get the current wrap mode.
             * @return The current wrap mode.
             */
            WrapMode GetWrapMode() const
            {
                return mWrapMode;
            }

            /**
             * @brief Add a new interpolation key.
             * The key is inserted into the sorted key array according to the time value.
             * @param key The key to copy and add.
             * @return The index of the key.
             */
            SInt32 AddKey(const Key& key)
            {
                SInt32 insertionIndex = FindIndex(key.mTime);
                mKeys.Insert(insertionIndex, key);
                mAreControlPointsValid = false;
                return insertionIndex;
            }

            /**
             * @brief Add a new interpolation key.
             * The key is inserted into the sorted key array according to the time value.
             * @param time The time for the key in seconds.
             * @param value The value for the key.
             * @return The index of the key.
             */
            SInt32 AddKey(Real time, const DataType& value)
            {
                return AddKey(Key(time, value));
            }

            /**
             * @brief Remove a key at a specified index.
             * @param index The zero-based index.
             * @return true if successful, false if the index is invalid.
             */
            Bool RemoveKey(SInt32 index)
            {
                if (mKeys.IsIndexValid(index))
                {
                    mKeys.Remove(index);
                    mAreControlPointsValid = false;
                    return true;
                }
                return false;
            }

            /**
             * @brief Set a key's value for a specified index.
             * @param index The zero-based index.
             * @param value The value to set.
             * @return true if successful, false if the index is invalid.
             */
            Bool SetKeyValue(SInt32 index, const DataType& value)
            {
                if (mKeys.IsIndexValid(index))
                {
                    mKeys[index].mValue = value;
                    mAreControlPointsValid = false;
                    return true;
                }
                return false;
            }

            /**
             * @brief Set a key for a specified index.
             * The key is set into the sorted key array according to the key's time value,
             * therefore the key's index may change which is returned.
             * @param index The zero-based index.
             * @param key The key to copy and set.
             * @return The new index of the key, -1 if the index is invalid.
             */
            SInt32 SetKey(SInt32 index, const Key& key)
            {
                if (mKeys.IsIndexValid(index))
                {
                    SInt32 newIndex = FindIndex(key.mTime);
                    if (index < newIndex)
                    {
                        newIndex--;
                    }
                    if (newIndex == index)
                    {
                        mKeys[index] = key;
                    }
                    else
                    {
                        mKeys.Remove(index);
                        mKeys.Insert(newIndex, key);
                    }
                    mAreControlPointsValid = false;
                    return newIndex;
                }
                return -1;
            }

            /**
             * @brief Set a key for a specified index.
             * The key is set into the sorted key array according to the time value,
             * therefore the key's index may change which is returned.
             * @param index The zero-based index.
             * @param time The time for the key in seconds.
             * @param value The value to set.
             * @return The new index of the key, -1 if the index is invalid.
             */
            SInt32 SetKey(SInt32 index, Real time, const DataType& value)
            {
                return SetKey(index, Key(time, value));
            }

            /**
             * @brief Copy the keys from a spline object.
             *  Overwrites this object's keys with the source keys.
             * @param source The source spline object.
             */
            void CopyKeys(const SplineBase<DataType>& source)
            {
                mKeys = source.mKeys;
                mAreControlPointsValid = false;
            }

            /**
             * @brief Get the nearest key index for a specified time.
             * @param time The time in seconds.
             * @return The index of the key.
             */
            SInt32 GetKeyIndex(Real time) const
            {
                SInt32 index = FindIndex(time);
                if (index == mKeys.GetCount())
                {
                    index--;
                }
                else if (index > 0)
                {
                    if ((time - mKeys[index - 1].mTime) < (mKeys[index].mTime - time))
                    {
                        index--;
                    }
                }
                return index;
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
             * @brief Get a key for a specified index.
             * @param index The zero-based index in range [0 .. GetNumberOfKeys()-1].
             * @return The key at the specified index.
             */
            const Key& GetKey(SInt32 index) const
            {
                return mKeys[index];
            }

            /**
             * @brief Empty the keys, but keep the underlying storage.
             */
            void EmptyKeys()
            {
                mKeys.Empty();
                mAreControlPointsValid = false;
            }

            /**
             * @brief Clear the keys and remove the underlying storage.
             */
            void ClearKeys()
            {
                mKeys.Clear();
                mAreControlPointsValid = false;
            }

            /**
             * @brief Get the interpolated value at a specific time.
             * @param time The time for the interpolation value in seconds.
             * @return The the interpolated value.
             */
            virtual const DataType& Interpolate(Double time)
            {
                UpdateControlPoints();

                SInt32 numKeys = mKeys.GetCount();
                if (numKeys == 0)
                {
                    mCurrentValue = DataType();
                }
                else if (numKeys == 1)
                {
                    mCurrentValue = mKeys[0].mValue;
                }
                else
                {
                    if ((mWrapMode >= WRAP_CLAMP_TO_EDGE) && (mWrapMode <= WRAP_REPEAT_MIRRORED))
                    {
                        Double minTime = mKeys[0].mTime;
                        Double maxTime = mKeys[numKeys - 1].mTime;

                        switch (mWrapMode)
                        {
                            case WRAP_CLAMP_TO_EDGE:
                                time = Math::Clamp(time, minTime, maxTime);
                                break;

                            case WRAP_REPEAT:
                                time = Math::Fmod((time - minTime), (maxTime - minTime));
                                time += (time < 0) ? maxTime : minTime;
                                break;

                            case WRAP_REPEAT_MIRRORED:
                                time = Math::Fmod((time - minTime), (2 * (maxTime - minTime)));
                                if (time < 0)
                                {
                                    time *= -1;
                                }
                                time += minTime;

                                if (time > maxTime)
                                {
                                    time = 2 * maxTime - time;
                                }
                                break;

                            default:
                                break;
                        }
                    }

                    SInt32 timeIndex = FindIndex(time);
                    if (timeIndex >= numKeys)
                    {
                        timeIndex = numKeys - 1;
                    }

                    if (mKeys[timeIndex].mTime == time)
                    {
                        mCurrentValue = mKeys[timeIndex].mValue;
                    }
                    else
                    {
                        if (timeIndex == 0)
                        {
                            timeIndex++;
                        }
                        InterpolateCurrentValue(time, timeIndex);
                    }
                }
                return mCurrentValue;
            }

            /**
             * @brief Update the control points immediately.
             * The countrol points are updated automatically during Interpolate() if necessary,
             * this method is used to update the control points before calling Interpolate().
             * @return true if the control points are valid.
             */
            Bool UpdateControlPoints()
            {
                if (!mAreControlPointsValid)
                {
                    mAreControlPointsValid = CalculateControlPoints();
                }
                return mAreControlPointsValid;
            }

            /**
             * @brief Set the control points valid state.
             * Every modification of the key's time or value invalidates the control points.
             * This method is used to suppress automatic updating of the control points,
             * if manually modification of the control points is required.
             * @param areValid The control points valid state.
             */
            void SetControlPointsValid(Bool areValid)
            {
                mAreControlPointsValid = areValid;
            }

        protected:
            /**
             * @brief Override point for updating control points if
             *  the keys or the wrap mode or the curve type changed.
             * @return true if the control points are updated successful.
             */
            virtual Bool CalculateControlPoints() = 0;

            /**
             * @brief Override point to update the current value for a specified time.
             * @param time The time to interpolate.
             * @param timeIndex The index to the nearest key which is greater or equal the time.
             */
            virtual void InterpolateCurrentValue(Double time, SInt32 timeIndex) = 0;

            /**
             * @brief Get the previous key for a specified index depending on
             *  the curve type and the wrap mode.
             * @param index The index.
             * @return The previous key.
             */
            Key GetPrevKey(SInt32 index) const
            {
                SInt32 numKeys = mKeys.GetCount();
                if (numKeys == 1)
                {
                    return mKeys[0];
                }

                if (index > 0)
                {
                    return mKeys[index - 1];
                }

                if (mCurveType != CURVE_CLOSED)
                {
                    return mKeys[0];
                }

                if (mWrapMode == WRAP_REPEAT_MIRRORED)
                {
                    Real dt = mKeys[0].mTime - (mKeys[1].mTime - mKeys[0].mTime);
                    return Key(dt, mKeys[1].mValue);
                }
                else
                {
                    Real dt = mKeys[0].mTime - (mKeys[numKeys - 1].mTime - mKeys[numKeys - 2].mTime);
                    return Key(dt, mKeys[numKeys - 2].mValue);
                }
            }

            /**
             * @brief Get the next key for a specified index depending on
             *  the curve type and the wrap mode.
             * @param index The index.
             * @return The previous key.
             */
            Key GetNextKey(SInt32 index) const
            {
                SInt32 numKeys = mKeys.GetCount();
                if (numKeys == 1)
                {
                    return mKeys[0];
                }

                if (index < numKeys - 1)
                {
                    return mKeys[index + 1];
                }

                if (mCurveType != CURVE_CLOSED)
                {
                    return mKeys[numKeys - 1];
                }

                if (mWrapMode == WRAP_REPEAT_MIRRORED)
                {
                    Real dt = mKeys[numKeys - 1].mTime + mKeys[numKeys - 1].mTime - mKeys[numKeys - 2].mTime;
                    return Key(dt, mKeys[numKeys - 2].mValue);
                }
                else
                {
                    Real dt = mKeys[numKeys - 1].mTime + mKeys[1].mTime - mKeys[0].mTime;
                    return Key(dt, mKeys[1].mValue);
                }
            }

            /**
             * @brief Find the index using binary search O(log n).
             * Returns the index of the nearest key that is greater or equal to the given time.
             * @param time The time to search for.
             * @return The index of the nearest key in the range [0, mKeys.GetCount()].
             */
            SInt32 FindIndex(Real time) const
            {
                SInt32 startIndex = 0;
                SInt32 endIndex = mKeys.GetCount() - 1;

                if (endIndex < 0)
                {
                    return 0;
                }
                if (time < mKeys[0].mTime)
                {
                    return 0;
                }
                if (time >= mKeys[endIndex].mTime)
                {
                    return endIndex + 1;
                }

                while (true)
                {
                    SInt32 midIndex = (endIndex + startIndex) / 2;
                    if (time == mKeys[midIndex].mTime)
                    {
                        return midIndex;
                    }
                    if (startIndex == midIndex)
                    {
                        return (time < mKeys[midIndex].mTime) ? midIndex : midIndex + 1;
                    }
                    if (time < mKeys[midIndex].mTime)
                    {
                        endIndex = midIndex;
                    }
                    else
                    {
                        startIndex = midIndex;
                    }
                }
            }

            /** @brief The key array stores all given keys sorted according to the time value. */
            Array<Key> mKeys;

            /** @brief The current curve type. */
            CurveType mCurveType;

            /** @brief The current wrap mode. */
            WrapMode mWrapMode;

            /** @brief The current interpolated value. */
            DataType mCurrentValue;

            Bool mAreControlPointsValid;
        };

        /**
         * @addtogroup MurlMathClasses
         * @{
         */
        /** @brief Predefined SplineBase using a Vector data type. */
        typedef SplineBase<Vector<Real> > SplineBaseVector;
        /** @brief The SplineBaseVector shared pointer type. */
        typedef SharedPointer<SplineBaseVector> SplineBaseVectorPtr;
        /** @brief Predefined SplineBaseKey using a Vector data type. */
        typedef SplineBaseVector::Key SplineVectorKey;


        /** @brief Predefined SplineBase using a Color data type. */
        typedef SplineBase<Color> SplineBaseColor;
        /** @brief The SplineBaseColor shared pointer type. */
        typedef SharedPointer<SplineBaseColor> SplineBaseColorPtr;
        /** @brief Predefined SplineBaseKey using a Color data type. */
        typedef SplineBaseColor::Key SplineColorKey;

        /** @brief Predefined SplineBase using a Real data type. */
        typedef SplineBase<Real> SplineBaseReal;
        /** @brief The SplineBaseReal shared pointer type. */
        typedef SharedPointer<SplineBaseReal> SplineBaseRealPtr;
        /** @brief Predefined SplineBaseKey using a Real data type. */
        typedef SplineBaseReal::Key SplineRealKey;
        /** @} */
    }
}

#endif  // __MURL_MATH_SPLINE_BASE_H__
