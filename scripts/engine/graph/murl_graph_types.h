// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_TYPES_H__
#define __MURL_GRAPH_TYPES_H__

#include "murl_math_vector.h"
#include "murl_math_matrix.h"

namespace Murl
{
    namespace Math
    {
        template<class DataType>
        class Rectangle;

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
        class Cylinder;

        template<class DataType>
        class Frustum;
        
        template<class DataType>
        class Limits;
    }
    
    /**
     * @ingroup MurlGraphNamespaces
     * Namespace containing scene graph related interfaces.
     */
    namespace Graph
    {
        /**
         * @brief Generic floating point data type in the Murl::Graph namespace.
         */
        typedef GraphReal Real;
        
        /**
         * @brief Math::Vector data type for the Murl::Graph namespace.
         */
        typedef Math::Vector<Real> Vector;
        
        /**
         * @brief Math::VectorUninitialized data type for the Murl::Graph namespace.
         */
        typedef Math::VectorUninitialized<Real> VectorUninitialized;
        
        /**
         * @brief Math::StaticVector data type for the Murl::Graph namespace.
         */
        typedef Math::StaticVector<Real> StaticVector;
        
        /**
         * @brief Math::Matrix data type for the Murl::Graph namespace.
         */
        typedef Math::Matrix<Real> Matrix;
        
        /**
         * @brief Math::Quaternion data type for the Murl::Graph namespace.
         */
        typedef Math::Quaternion<Real> Quaternion;

        /**
         * @brief Math::Rectangle data type for the Murl::Graph namespace.
         */
        typedef Math::Rectangle<Real> Rectangle;

        /**
         * @brief Math::Sphere data type for the Murl::Graph namespace.
         */
        typedef Math::Sphere<Real> Sphere;
        
        /**
         * @brief Math::Box data type for the Murl::Graph namespace.
         */
        typedef Math::Box<Real> Box;
        
        /**
         * @brief Math::Ray data type for the Murl::Graph namespace.
         */
        typedef Math::Ray<Real> Ray;

        /**
         * @brief Math::Plane data type for the Murl::Graph namespace.
         */
        typedef Math::Plane<Real> Plane;
        
        /**
         * @brief Math::Cone data type for the Murl::Graph namespace.
         */
        typedef Math::Cone<Real> Cone;
        
        /**
         * @brief Math::Cylinder data type for the Murl::Graph namespace.
         */
        typedef Math::Cylinder<Real> Cylinder;

        /**
         * @brief Math::Frustum data type for the Murl::Graph namespace.
         */
        typedef Math::Frustum<Real> Frustum;
        
        /**
         * @brief Math::Limits data type for the Murl::Graph namespace.
         */
        typedef Math::Limits<Real> Limits;
    }
}

#endif  // __MURL_GRAPH_TYPES_H__
