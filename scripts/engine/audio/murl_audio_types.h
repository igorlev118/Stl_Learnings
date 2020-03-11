// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_AUDIO_TYPES_H__
#define __MURL_AUDIO_TYPES_H__

#include "murl_types.h"

namespace Murl
{
    namespace Math
    {
        template<class DataType>
        class Vector;
        
        template<class DataType>
        class Matrix;
        
        template<class DataType>
        class Quaternion;
        
        template<class DataType>
        class Sphere;
    }
    
    /**
     * @ingroup MurlAudioNamespaces
     * @brief Namespace containing audio related interfaces.
     */
    namespace Audio
    {
        /**
         * @ingroup MurlAudioNamespaces
         * @brief Namespace containing OpenAL 1.1 audio related interfaces.
         */
        namespace Al11
        {
        }
        /**
         * @ingroup MurlAudioNamespaces
         * @brief Namespace containing Dummy audio related interfaces.
         */
        namespace Dummy
        {
        }

        /**
         * @brief Generic floating point data type for the Murl::Audio namespace.
         */
        typedef AudioReal Real;
        
        /**
         * @brief Math::Vector data type for the Murl::Audio namespace.
         */
        typedef Math::Vector<Real> Vector;
        /**
         * @brief Math::Matrix data type for the Murl::Audio namespace.
         */
        typedef Math::Matrix<Real> Matrix;
        /**
         * @brief Math::Quaternion data type for the Murl::Audio namespace.
         */
        typedef Math::Quaternion<Real> Quaternion;
        
        /**
         * @brief Math::Sphere data type for the Murl::Audio namespace.
         */
        typedef Math::Sphere<Real> Sphere;
    }
}

#endif  // __MURL_AUDIO_TYPES_H__
