// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_PHYSICS_TYPES_H__
#define __MURL_PHYSICS_TYPES_H__

#include "murl_math_vector.h"
#include "murl_math_matrix.h"

namespace Murl
{
    namespace Math
    {
        template<class DataType>
        class Vector;
        
        template<class DataType>
        class VectorUninitialized;
        
        template<class DataType>
        class Matrix;
        
        template<class DataType>
        class Quaternion;

        template<class DataType>
        class Box;

        template<class DataType>
        class Sphere;

        template<class DataType>
        class Ray;
    }

    /**
     * @ingroup MurlPhysicsNamespaces
     * @brief Namespace containing physics simulator related interfaces.
     */
    namespace Physics
    {
        /**
         * @ingroup MurlPhysicsNamespaces
         * @brief Namespace containing builtin physics simulator related interfaces.
         */
        namespace Builtin
        {
        }

        /**
         * @brief Generic floating point data type for the Murl::Physics namespace.
         */
        typedef PhysicsReal Real;
        
        /**
         * @brief Math::Vector data type for the Murl::Physics namespace.
         */
        typedef Math::Vector<Real> Vector;
        /**
         * @brief Math::VectorUninitialized data type for the Murl::Physics namespace.
         */
        typedef Math::VectorUninitialized<Real> VectorUninitialized;
        /**
         * @brief Math::StaticVector data type for the Murl::Graph namespace.
         */
        typedef Math::StaticVector<Real> StaticVector;
        /**
         * @brief Math::Matrix data type for the Murl::Physics namespace.
         */
        typedef Math::Matrix<Real> Matrix;
        /**
         * @brief Math::Quaternion data type for the Murl::Physics namespace.
         */
        typedef Math::Quaternion<Real> Quaternion;

        /**
         * @brief Math::Sphere data type for the Murl::Physics namespace.
         */
        typedef Math::Sphere<Real> Sphere;
        /**
         * @brief Math::Box data type for the Murl::Physics namespace.
         */
        typedef Math::Box<Real> Box;
        /**
         * @brief Math::Ray data type for the Murl::Physics namespace.
         */
        typedef Math::Ray<Real> Ray;


        /// Default epsilon.
        const Real EPSILON = Real(0.00001);
    }
}

#endif  // __MURL_PHYSICS_TYPES_H__
