// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_SCALABLE_H__
#define __MURL_GRAPH_I_SCALABLE_H__

#include "murl_graph_i_generic_node_target.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphPropertyInterfaces
         * @interface IScalable
         * @brief The IScalable property interface.
         * This interface provides setting and retrieving of a scale factor, either
         * as a uniform value or individual values for scaling along the X, Y and
         * Z axes.
         *
         * Animation controllers may call the SetScaleFactor() method when scaling keys
         * are present in a given Resource::IAnimation.
         */
        class IScalable
        {
        public:
            /**
             * @brief Set individual scaling factors for the X, Y and Z axes.
             * @param scaleFactor A vector containing individual scale factors.
             * @return true if successful.
             */
            virtual Bool SetScaleFactor(const Vector& scaleFactor) = 0;
            /**
             * @brief Set individual scaling factors for the X, Y and Z axes.
             * @param x The scale factor for the X axis.
             * @param y The scale factor for the Y axis.
             * @param z The scale factor for the Z axis.
             * @return true if successful.
             */
            virtual Bool SetScaleFactor(Real x, Real y, Real z) = 0;
            /**
             * @brief Set a uniform scaling factor for all three axes.
             * @param s The scale factor for the X, Y and Z axes.
             * @return true if successful.
             */
            virtual Bool SetScaleFactor(Real s) = 0;
            /**
             * @brief Set the scaling factor for the X axis only.
             * @param x The scale factor for the X axis.
             * @return true if successful.
             */
            virtual Bool SetScaleFactorX(Real x) = 0;
            /**
             * @brief Set the scaling factor for the Y axis only.
             * @param y The scale factor for the Y axis.
             * @return true if successful.
             */
            virtual Bool SetScaleFactorY(Real y) = 0;
            /**
             * @brief Set the scaling factor for the Z axis only.
             * @param z The scale factor for the Z axis.
             * @return true if successful.
             */
            virtual Bool SetScaleFactorZ(Real z) = 0;
            
            /**
             * @brief Get the scaling factors for the X, Y and Z axes.
             * @return A vector containing the individual scale factors.
             */
            virtual const Vector& GetScaleFactor() const = 0;
            /**
             * @brief Get the scaling factor for the X axis.
             * @return The scale factor for the X axis.
             */
            virtual Real GetScaleFactorX() const = 0;
            /**
             * @brief Get the scaling factor for the Y axis.
             * @return The scale factor for the Y axis.
             */
            virtual Real GetScaleFactorY() const = 0;
            /**
             * @brief Get the scaling factor for the Z axis.
             * @return The scale factor for the Z axis.
             */
            virtual Real GetScaleFactorZ() const = 0;
            
        protected:
            virtual ~IScalable() {}
        };

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IScalable nodes.
         */
        typedef IGenericNodeTarget<IScalable> IScalableNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_SCALABLE_H__
