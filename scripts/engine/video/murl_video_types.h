// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_VIDEO_TYPES_H__
#define __MURL_VIDEO_TYPES_H__

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

        template<class DataType>
        class Box;

        template<class DataType>
        class Ray;

        template<class DataType>
        class Plane;

        template<class DataType>
        class Cone;

        template<class DataType>
        class Frustum;
        
        template<class DataType>
        class Rectangle;
    }

    /**
     * @ingroup MurlVideoNamespaces
     * @brief Namespace containing video related interfaces.
     */
    namespace Video
    {
        /**
         * @ingroup MurlVideoNamespaces
         * @brief Namespace containing DirectX 9.0 video related interfaces.
         */
        namespace Dx90
        {
        }
        /**
         * @ingroup MurlVideoNamespaces
         * @brief Namespace containing DirectX 11.1 video related interfaces.
         */
        namespace Dx111
        {
        }
        /**
         * @ingroup MurlVideoNamespaces
         * @brief Namespace containing OpenGL|ES 2.0 video related interfaces.
         */
        namespace GlEs20
        {
        }

        /**
         * @brief Generic floating point data type for the Murl::Video namespace.
         */
        typedef VideoReal Real;
        
        /**
         * @brief Math::Vector data type for the Murl::Video namespace.
         */
        typedef Math::Vector<Real> Vector;
        /**
         * @brief Math::Matrix data type for the Murl::Video namespace.
         */
        typedef Math::Matrix<Real> Matrix;
        /**
         * @brief Math::Quaternion data type for the Murl::Video namespace.
         */
        typedef Math::Quaternion<Real> Quaternion;
        
        /**
         * @brief Math::Sphere data type for the Murl::Video namespace.
         */
        typedef Math::Sphere<Real> Sphere;
        /**
         * @brief Math::Box data type for the Murl::Video namespace.
         */
        typedef Math::Box<Real> Box;
        /**
         * @brief Math::Ray data type for the Murl::Video namespace.
         */
        typedef Math::Ray<Real> Ray;
        /**
         * @brief Math::Plane data type for the Murl::Video namespace.
         */
        typedef Math::Plane<Real> Plane;
        /**
         * @brief Math::Cone data type for the Murl::Video namespace.
         */
        typedef Math::Cone<Real> Cone;
        /**
         * @brief Math::Frustum data type for the Murl::Video namespace.
         */
        typedef Math::Frustum<Real> Frustum;
        /**
         * @brief Math::Rectangle data type for the Murl::Video namespace.
         */
        typedef Math::Rectangle<Real> Rectangle;
    }
}

#endif  // __MURL_VIDEO_TYPES_H__
