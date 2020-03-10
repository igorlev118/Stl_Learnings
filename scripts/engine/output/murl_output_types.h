// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_OUTPUT_TYPES_H__
#define __MURL_OUTPUT_TYPES_H__

#include "murl_types.h"

namespace Murl
{
    namespace Math
    {
        template<class DataType>
        class Vector;
        
        template<class DataType>
        class Matrix;
    }
    
    /**
     * @ingroup MurlOutputNamespaces
     * @brief Namespace containing output related interfaces.
     */
    namespace Output
    {
        /**
         * @brief Generic floating point data type for the Murl::Output namespace.
         */
        typedef OutputReal Real;
        
        /**
         * @brief Math::Vector data type for the Murl::Output namespace.
         */
        typedef Math::Vector<Real> Vector;
        
        /**
         * @brief Math::Matrix data type for the Murl::Output namespace.
         */
        typedef Math::Matrix<Real> Matrix;
    }
}

#endif  // __MURL_OUTPUT_TYPES_H__
