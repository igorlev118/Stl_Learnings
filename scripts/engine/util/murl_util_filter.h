// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_UTIL_FILTER_H__
#define __MURL_UTIL_FILTER_H__

#include "murl_i_filter.h"
#include "murl_math.h"

namespace Murl
{
    namespace Util
    {
        /**
         * @ingroup MurlUtilVideoClasses
         * @brief The filter base class.
         */
        class Filter : public IFilter
        {
        public:
            /**
             * @brief Constructor taking the filter width.
             * @param width The filter width.
             */
            Filter(Double width)
            : mWidth(width)
            {
            }
            
            /**
             * @brief The destructor.
             */
            virtual ~Filter()
            {
            }
            
            /**
             * @brief Implementation of IFilter::GetWidth().
             * @return The filter width.
             */
            virtual Double GetWidth() const
            {
                return mWidth;
            }
            
            /**
             * @brief Implementation of IFilter::SetWidth().
             * @param width The filter width.
             */
            virtual void SetWidth(Double width)
            {
                mWidth = width;
            }
            
        protected:
            /** @brief The filter width. */
            Double mWidth;
        };
        
        /**
         * @ingroup MurlUtilVideoClasses
         * @brief The box filter class has not interpolation.
         */
        class BoxFilter : public Filter
        {
        public:
            /**
             * @brief The default constructor.
             * @param width The filter width defaulted to 0.5.
             */
            BoxFilter(Double width = Double(0.5))
            : Filter(width > 0.0 ? width : Double(0.5))
            {
            }
            
            /**
             * @brief The destructor.
             */
            virtual ~BoxFilter()
            {
            }
            
            /**
             * @brief Apply the filter horizontally.
             * @param dValH The horizontal distance in range [-filterWidth .. filterWidth].
             * @return 1.0 if distance is in filter width range.
             */
            virtual Double Apply(Double dValH) const
            {
                return (Math::Abs(dValH) <= mWidth ? 1.0 : 0.0);
            }
            
            /**
             * @brief Apply the filter horizontally and vertically.
             * @param dValH The horizontal distance in range [-filterWidth .. filterWidth].
             * @param dValV The vertical distance in range [-filterWidth .. filterWidth].
             * @return 1.0 if both distances are in filter width range.
             */
            virtual Double Apply(Double dValH, Double dValV) const
            {
                return ((Math::Abs(dValH) <= mWidth) && (Math::Abs(dValV) <= mWidth) ? 1.0 : 0.0);
            }
        };
        
        /**
         * @ingroup MurlUtilVideoClasses
         * @brief The bilinear filter class has linear interpolation.
         */
        class BilinearFilter: public Filter
        {
        public:
            /**
             * @brief The default constructor.
             * @param width The filter width defaulted to 1.0.
             */
            BilinearFilter(Double width = Double(1.0))
            : Filter(width > 0.0 ? width : Double(1.0))
            {
            }
            
            /**
             * @brief The destructor.
             */
            virtual ~BilinearFilter()
            {
            }
            
            /**
             * @brief Apply the filter horizontally.
             * @param dValH The horizontal distance in range [-filterWidth .. filterWidth].
             * @return (width - abs(dValH))
             *  or zero if distance is out of range.
             */
            virtual Double Apply(Double dValH) const
            {
                dValH = Math::Abs(dValH);
                return (dValH < mWidth ? mWidth - dValH : 0.0);
            }
            
            /**
             * @brief Apply the filter horizontally and vertically.
             * @param dValH The horizontal distance in range [-filterWidth .. filterWidth].
             * @param dValV The vertical distance in range [-filterWidth .. filterWidth].
             * @return ((width - abs(dValH)) * (width - abs(dValV)))
             *  or zero if distance is out of range.
             */
            virtual Double Apply(Double dValH, Double dValV) const
            {
                dValH = Math::Abs(dValH);
                dValV = Math::Abs(dValV);
                
                if ((dValH >= mWidth) || (dValV >= mWidth))
                {
                    return 0.0;
                }
                
                return (mWidth - dValH) * (mWidth - dValV);
            }
        };
        
        /**
         * @ingroup MurlUtilVideoClasses
         * @brief The gaussian filter class has gaussian function interpolation.
         */
        class GaussianFilter: public Filter
        {
        public:
            /**
             * @brief The default constructor.
             * @param width The filter width defaulted to 3.0.
             * @param sigma The filter standard deviation defaulted to 1.0.
             */
            GaussianFilter(Double width = Double(3.0), Double sigma = Double(1.0))
            : Filter(width > 0.0 ? width : Double(3.0))
            {
                if (sigma <= 0.0)
                {
                    sigma = 1.0;
                }
                mSqrtTwoPiSigma = Math::Sqrt(Math::TWO_PI) * sigma;
                mTwoSigmaSquared = 2.0 * sigma * sigma;
            }
            
            /**
             * @brief The destructor.
             */
            virtual ~GaussianFilter()
            {
            }
            
            /**
             * @brief Apply the filter horizontally.
             * @param dValH The horizontal distance in range [-filterWidth .. filterWidth].
             * @return e^((-dValH^2) / (2 * sigma^2)) / (sqrt(2 * Pi) * sigma)
             *  or zero if distance is out of range.
             */
            virtual Double Apply(Double dValH) const
            {
                if (Math::Abs(dValH) > mWidth)
                {
                    return 0.0;
                }
                else
                {
                    return Math::Exp(-(dValH * dValH) / mTwoSigmaSquared) / mSqrtTwoPiSigma;
                }
            }
            
            /**
             * @brief Apply the filter horizontally and vertically.
             * @param dValH The horizontal distance in range [-filterWidth .. filterWidth].
             * @param dValV The vertical distance in range [-filterWidth .. filterWidth].
             * @return e^((-dValH^2 + dValV^2) / (2 * sigma^2)) / (2 * Pi * sigma^2)
             *  or zero if distance is out of range.
             */
            virtual Double Apply(Double dValH, Double dValV) const
            {
                if ((Math::Abs(dValH) > mWidth) || (Math::Abs(dValV) > mWidth))
                {
                    return 0.0;
                }
                else
                {
                    return Math::Exp(-(dValH * dValH + dValV * dValV) / mTwoSigmaSquared) / (Math::PI * mTwoSigmaSquared);
                }
            }
            
        protected:
            Double mSqrtTwoPiSigma;
            Double mTwoSigmaSquared;
        };
    }
}

#endif // __MURL_UTIL_FILTER_H__
