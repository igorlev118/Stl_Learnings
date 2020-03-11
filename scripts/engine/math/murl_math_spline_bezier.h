// Copyright 2015 Spraylight

#ifndef __MURL_MATH_SPLINE_BEZIER_H__
#define __MURL_MATH_SPLINE_BEZIER_H__

#include "murl_math_spline_base.h"

namespace Murl
{
    namespace Math
    {
        /**
         * @ingroup MurlMathClasses
         * @brief A template class to create a Bezier spline interpolation object.
         *  The control points are calculated automatically.
         */
        template<class DataType>
        class SplineBezier : public SplineBase<DataType>
        {
        public:
            /** @brief The template parameter value type. */
            typedef DataType ValueType;

            /** @brief The base class type. */
            typedef SplineBase<DataType> BaseType;

            using typename BaseType::Key;
            using typename BaseType::WrapMode;
            using typename BaseType::CurveType;

            /**
             * @brief The default constructor.
             */
            SplineBezier()
            {
            }

            /**
             * @brief Constructor taking the wrap mode and the curve type.
             * @param wrapMode The wrapMode.
             * @param curveType The curveType.
             */
            SplineBezier(WrapMode wrapMode, CurveType curveType)
            : BaseType::SplineBase(wrapMode, curveType)
            {
            }

            /**
             * @brief The destructor.
             */
            virtual ~SplineBezier()
            {
            }

            /** @brief The control point class. */
            class ControlPoint
            {
            public:
                /**
                 * @brief The default constructor.
                 */
                ControlPoint()
                : mPrev()
                , mNext()
                {
                }

                /** @brief The control point previous to the corresponding key. */
                DataType mPrev;
                /** @brief The control point next to the corresponding key. */
                DataType mNext;
            };

            /**
             * @brief Get the control points for each key.
             * @return The control points for each key.
             */
            Array<ControlPoint>& GetControlPoints()
            {
                return mControlPoints;
            }

            /**
             * @brief Calculate the control point for a specified index.
             * @param index The zero-based index in range [0 .. GetNumberOfKeys()-1].
             * @return true if successful, false if the index is invalid.
             */
            Bool CalculateControlPoint(SInt32 index)
            {
                if (mControlPoints.IsIndexValid(index) && mKeys.IsIndexValid(index))
                {
                    const Key& prevKey = BaseType::GetPrevKey(index);
                    const Key& key = mKeys[index];
                    const Key& nextKey = BaseType::GetNextKey(index);

                    DataType k = (nextKey.mValue - prevKey.mValue) / (nextKey.mTime - prevKey.mTime);
                    k *= ((nextKey.mTime - key.mTime) / 3);

                    mControlPoints[index].mPrev = key.mValue - k;
                    mControlPoints[index].mNext = key.mValue + k;
                    return true;
                }
                return false;
            }

        protected:
            using BaseType::mKeys;

            virtual Bool CalculateControlPoints()
            {
                SInt32 numKeys = mKeys.GetCount();
                mControlPoints.SetCount(numKeys);

                for (SInt32 i = 0; i < numKeys; i++)
                {
                    CalculateControlPoint(i);
                }
                return true;
            }

            virtual void InterpolateCurrentValue(Double time, SInt32 timeIndex)
            {
                if (mControlPoints.GetCount() != mKeys.GetCount())
                {
                    CalculateControlPoints();
                }

                const Key& key0 = mKeys[timeIndex - 1];
                const Key& key1 = mKeys[timeIndex];

                const DataType& cp0 = mControlPoints[timeIndex - 1].mNext;
                const DataType& cp1 = mControlPoints[timeIndex].mPrev;

                Double t = (time - key0.mTime) / (key1.mTime - key0.mTime);
                Double t1 = Double(1) - t;
                BaseType::mCurrentValue = ((key0.mValue * t1 * t1 * t1) + (cp0 * 3 * t * t1 * t1) +
                                           (cp1 * 3 * t * t * t1) + (key1.mValue * t * t * t));
            }

            // Control points (tangents) for each key.
            Array<ControlPoint> mControlPoints;
        };

        /**
         * @addtogroup MurlMathClasses
         * @{
         */
        /** @brief Predefined SplineBezier using a Vector data type. */
        typedef SplineBezier<Vector<Real> > SplineBezierVector;
        /** @brief The SplineBezierVector shared pointer type. */
        typedef SharedPointer<SplineBezierVector> SplineBezierVectorPtr;

        /** @brief Predefined SplineBezier using a Color data type. */
        typedef SplineBezier<Color> SplineBezierColor;
        /** @brief The SplineBezierColor shared pointer type. */
        typedef SharedPointer<SplineBezierColor> SplineBezierColorPtr;

        /** @brief Predefined SplineBezier using a Real data type. */
        typedef SplineBezier<Real> SplineBezierReal;
        /** @brief The SplineBezierReal shared pointer type. */
        typedef SharedPointer<SplineBezierReal> SplineBezierRealPtr;
        /** @} */
    }
}

#endif  // __MURL_MATH_SPLINE_BEZIER_H__
