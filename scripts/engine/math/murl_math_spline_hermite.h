// Copyright 2015 Spraylight

#ifndef __MURL_MATH_SPLINE_HERMITE_H__
#define __MURL_MATH_SPLINE_HERMITE_H__

#include "murl_math_spline_base.h"

namespace Murl
{
    namespace Math
    {
        /**
         * @ingroup MurlMathClasses
         * @brief A template class to create a Cubic Hermite spline interpolation
         *  (aka as Cardinal Spline / Catmull-Rom spline) object.
         */
        template<class DataType>
        class SplineHermite : public SplineBase<DataType>
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
             * @brief The default constructor (Catmull-Rom spline interpolation).
             */
            SplineHermite()
            : mTk(0.5)
            {
            }

            /**
             * @brief Constructor taking the wrap mode, the curve type and the Tk value.
             * The Tk is the multiplication factor used to calculate the tangent of the Cardinal spline:
             * <TT> mk = Tk * (Pk+1 - Pk-1) = (1 - c) / 2 * (Pk+1 - Pk-1)</TT> with <TT>c in [-1,1]</TT>
             * The default value for Tk is 0.5, which corresponds to a Catmull-Rom spline interpolation.
             * @param wrapMode The wrapMode.
             * @param curveType The curveType.
             * @param Tk The Tk paramter.
             */
            SplineHermite(WrapMode wrapMode, CurveType curveType, Real Tk = 0.5)
            : BaseType::SplineBase(wrapMode, curveType)
            , mTk(Tk)
            {
            }

            /**
             * @brief The destructor.
             */
            virtual ~SplineHermite()
            {
            }

            /** @brief The control point type. */
            typedef DataType ControlPoint;

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
                    const Key& nextKey = BaseType::GetNextKey(index);

                    mControlPoints[index] = (nextKey.mValue - prevKey.mValue) * mTk;
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

                const DataType& k0v = key0.mValue;
                const DataType& k1v = key1.mValue;
                const DataType& cp0 = mControlPoints[timeIndex - 1];
                const DataType& cp1 = mControlPoints[timeIndex];

                Double t = (time - key0.mTime) / (key1.mTime - key0.mTime);
                BaseType::mCurrentValue = (((k0v * 2 - k1v * 2 + cp0 + cp1) * t * t * t) +
                                           ((k0v * (-3) + k1v * 3 - cp0 * 2 - cp1) * t * t) +
                                           (cp0 * t) + k0v);
            }

            // Control points (tangents) for each key.
            Array<ControlPoint> mControlPoints;

            Real mTk;
        };

        /**
         * @addtogroup MurlMathClasses
         * @{
         */
        /** @brief Predefined SplineHermite using a Vector data type. */
        typedef SplineHermite<Vector<Real> > SplineHermiteVector;
        /** @brief The SplineHermiteVector shared pointer type. */
        typedef SharedPointer<SplineHermiteVector> SplineHermiteVectorPtr;

        /** @brief Predefined SplineHermite using a Color data type. */
        typedef SplineHermite<Color> SplineHermiteColor;
        /** @brief The SplineHermiteColor shared pointer type. */
        typedef SharedPointer<SplineHermiteColor> SplineHermiteColorPtr;

        /** @brief Predefined SplineHermite using a Real data type. */
        typedef SplineHermite<Real> SplineHermiteReal;
        /** @brief The SplineHermiteReal shared pointer type. */
        typedef SharedPointer<SplineHermiteReal> SplineHermiteRealPtr;
        /** @} */
    }
}

#endif  // __MURL_MATH_SPLINE_HERMITE_H__
