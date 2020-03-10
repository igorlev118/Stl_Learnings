// Copyright 2012 Spraylight GmbH

#ifndef __MURL_CORE_TYPES_H__
#define __MURL_CORE_TYPES_H__

#include "murl_types.h"

namespace Murl
{
    namespace Math
    {
        template<class DataType>
        class Vector;
        
        template<class DataType>
        class StaticVector;
        
        template<class DataType>
        class Matrix;
        
        template<class DataType>
        class Limits;
    }
    
    /**
     * @ingroup MurlCoreNamespaces
     * @brief Namespace containing core related interfaces.
     */
    namespace Core
    {
        /**
         * @brief Generic floating point data type for the Murl::Core namespace.
         */
        typedef CoreReal Real;
        
        /**
         * @brief Math::Vector data type for the Murl::Core namespace.
         */
        typedef Math::Vector<Real> Vector;
        
        /**
         * @brief Math::StaticVector data type for the Murl::Core namespace.
         */
        typedef Math::StaticVector<Real> StaticVector;
        
        /**
         * @brief Math::Matrix data type for the Murl::Core namespace.
         */
        typedef Math::Matrix<Real> Matrix;
        
        /**
         * @brief Math::Limits data type for the Murl::Core namespace.
         */
        typedef Math::Limits<Real> Limits;
    }
}

#endif  // __MURL_CORE_TYPES_H__
