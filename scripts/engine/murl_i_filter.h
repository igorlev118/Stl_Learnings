// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_I_FILTER_H__
#define __MURL_I_FILTER_H__

#include "murl_types.h"

namespace Murl
{
    /**
     * @ingroup MurlInterfaces
     * @interface IFilter
     * @brief The filter interface.
     */
    class IFilter
    {
    public:
        /**
         * @brief The destructor.
         */
        virtual ~IFilter() {}

        /**
         * @brief Get the filter width.
         * @return The filter width.
         */
        virtual Double GetWidth() const = 0;
        
        /**
         * @brief Set the filter width.
         * @param width The filter width.
         */
        virtual void SetWidth(Double width) = 0;
        
        /**
         * @brief Apply the filter horizontally.
         * @param dValH The horizontal distance in range [-filterWidth .. filterWidth].
         * @return The filtered value or zero if distance is out of range.
         */
        virtual Double Apply(Double dValH) const = 0;
        
        /**
         * @brief Apply the filter horizontally and vertically.
         * @param dValH The horizontal distance in range [-filterWidth .. filterWidth].
         * @param dValV The vertical distance in range [-filterWidth .. filterWidth].
         * @return The filtered value or zero if any distance is out of range.
         */
        virtual Double Apply(Double dValH, Double dValV) const = 0;
    };
}

#endif  // __MURL_I_FILTER_H__
