// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_RESOURCE_TYPES_H__
#define __MURL_RESOURCE_TYPES_H__

#include "murl_math_vector.h"
#include "murl_math_matrix.h"
#include "murl_math_quaternion.h"

namespace Murl
{
    /**
     * @ingroup MurlResourceNamespaces
     * Namespace containing interfaces for resource management and handling.
     */
    namespace Resource
    {
        /**
         * @brief Generic floating point data type in the Murl::Resource namespace.
         */
        typedef ResourceReal Real;
        
        /**
         * @brief Math::Vector data type for the Murl::Resource namespace.
         */
        typedef Math::Vector<Real> Vector;

        /**
         * @brief Math::Matrix data type for the Murl::Resource namespace.
         */
        typedef Math::Matrix<Real> Matrix;

        /**
         * @brief Math::Quaternion data type for the Murl::Resource namespace.
         */
        typedef Math::Quaternion<Real> Quaternion;
    }
}

#endif  // __MURL_RESOURCE_TYPES_H__
