// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_INPUT_TYPES_H__
#define __MURL_INPUT_TYPES_H__

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
     * @ingroup MurlInputNamespaces
     * @brief Namespace containing input related interfaces.
     */
    namespace Input
    {
        /**
         * @brief Generic floating point data type for the Murl::Input namespace.
         */
        typedef InputReal Real;
        
        /**
         * @brief Math::Vector data type for the Murl::Input namespace.
         */
        typedef Math::Vector<Real> Vector;
        
        /**
         * @brief Math::Matrix data type for the Murl::Input namespace.
         */
        typedef Math::Matrix<Real> Matrix;
    }
}

#endif  // __MURL_INPUT_TYPES_H__
