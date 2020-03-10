// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_BOUNDING_BOX_H__
#define __MURL_GRAPH_I_BOUNDING_BOX_H__

#include "murl_graph_i_generic_node_target.h"

namespace Murl
{
    namespace Graph
    {
        class ITransform;
        
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IBoundingBox
         * @brief The IBoundingBox graph node interface.
         * Bounding box nodes are used in conjunction with Graph::IAligner nodes, in order
         * to explicitly define a minium volume used during the alignment process. This may be
         * necessary when a specific aligner child is able to change its actual size, but it
         * is not desired that the actual alignment reacts to that change (e.g. a pulsating
         * icon in a horizontally aligned sequence of individual icons). In such a case,
         * the pulsating icon can be defined as a child of a Graph::Bounding box node, which
         * defines the minimum alignment dimensions. However, when the icon grows bigger than
         * the given box size, the alignment again reflects that bigger size. If this is not
         * desired (e.g. the grown icon should overlap its neighbors), this behavior can be 
         * prevented by enable clamping via SetClampingEnabled(true). In this case, the box
         * represents an exact alignment volume.
         */
        class IBoundingBox
        {
        public:
            /**
             * @brief Get the mutable Graph::INode interface.
             * This method returns a mutable pointer to the node's Graph::INode interface, to
             * be able to query or modify common node properties such as active state,
             * visibility or ID.
             * @return The mutable Graph::INode interface, or null if not available
             */
            virtual INode* GetNodeInterface() = 0;
            /**
             * @brief Get the constant Graph::INode interface.
             * This method returns a constant pointer to the node's Graph::INode interface, to
             * be able to query common node properties such as active state, visibility
             * or ID.
             * @return The constant Graph::INode interface, or null if not available
             */
            virtual const INode* GetNodeInterface() const = 0;
            
            /**
             * @brief Get the mutable Graph::ITransform interface.
             * This method returns a mutable pointer to the node's Graph::ITransform interface,
             * to be able to query or modify the node's transformation matrix and depth
             * order.
             * @return The mutable Graph::ITransform interface, or null if not available
             */
            virtual ITransform* GetTransformInterface() = 0;
            /**
             * @brief Get the constant Graph::ITransform interface.
             * This method returns a constant pointer to the node's Graph::ITransform interface,
             * to be able to query the node's transformation matrix and depth order.
             * @return The constant Graph::ITransform interface, or null if not available
             */
            virtual const ITransform* GetTransformInterface() const = 0;

            /**
             * @brief Enable/disable inner volume clamping.
             * If enabled is set to true, the resulting "inner" bounding volume is clamped to
             * the minimum/maximum values set via SetMinimum() and SetMaximum() respectively.
             * In other words, the children's inner volumes, which are used by a Graph::IAligner 
             * node for content alignment, are not considered for adding to the overall bounding 
             * volume. This can be used to provide correct alignment for aligner children that
             * are actually bigger than the desired alignment size.
             * @param enabled If true, inner volume clamping is enabled.
             * @return true if successful.
             */
            virtual Bool SetClampingEnabled(Bool enabled) = 0;
            /**
             * @brief Check if inner volume clamping is enabled.
             * @return true if enabled.
             */
            virtual Bool IsClampingEnabled() const = 0;

            /**
             * @brief Enable/disable view culling.
             * @param enabled If true, culling is performed.
             * @return true if successful.
             */
            virtual Bool SetViewCullingEnabled(Bool enabled) = 0;
            /**
             * @brief Check if view culling is enabled.
             * @return true if enabled.
             */
            virtual Bool IsViewCullingEnabled() const = 0;

            /**
             * @brief Set minimum coordinate values for the X, Y and Z axes.
             * @param minimum A vector containing individual minimum values.
             * @return true if successful.
             */
            virtual Bool SetMinimum(const Vector& minimum) = 0;
            /**
             * @brief Set minimum coordinate values for the X, Y and Z axes.
             * @param x The minimum value for the X axis.
             * @param y The minimum value for the Y axis.
             * @param z The minimum value for the Z axis.
             * @return true if successful.
             */
            virtual Bool SetMinimum(Real x, Real y, Real z) = 0;
            /**
             * @brief Set the minimum coordinate value for the X axis only.
             * @param x The minimum value for the X axis.
             * @return true if successful.
             */
            virtual Bool SetMinimumX(Real x) = 0;
            /**
             * @brief Set the minimum coordinate value for the Y axis only.
             * @param y The minimum value for the Y axis.
             * @return true if successful.
             */
            virtual Bool SetMinimumY(Real y) = 0;
            /**
             * @brief Set the minimum coordinate value for the Z axis only.
             * @param z The minimum value for the Z axis.
             * @return true if successful.
             */
            virtual Bool SetMinimumZ(Real z) = 0;
            
            /**
             * @brief Get the minimum coordinate values for the X, Y and Z axes.
             * @return A vector containing the individual coordinate values.
             */
            virtual const Vector& GetMinimum() const = 0;
            /**
             * @brief Get the minimum coordinate value for the X axis.
             * @return The minimum coordinate for the X axis.
             */
            virtual Real GetMinimumX() const = 0;
            /**
             * @brief Get the minimum coordinate value for the Y axis.
             * @return The minimum coordinate for the Y axis.
             */
            virtual Real GetMinimumY() const = 0;
            /**
             * @brief Get the minimum coordinate value for the Z axis.
             * @return The minimum coordinate for the Z axis.
             */
            virtual Real GetMinimumZ() const = 0;
            
            /**
             * @brief Set maximum coordinate values for the X, Y and Z axes.
             * @param maximum A vector containing individual maximum values.
             * @return true if successful.
             */
            virtual Bool SetMaximum(const Vector& maximum) = 0;
            /**
             * @brief Set maximum coordinate values for the X, Y and Z axes.
             * @param x The maximum value for the X axis.
             * @param y The maximum value for the Y axis.
             * @param z The maximum value for the Z axis.
             * @return true if successful.
             */
            virtual Bool SetMaximum(Real x, Real y, Real z) = 0;
            /**
             * @brief Set the maximum coordinate value for the X axis only.
             * @param x The maximum value for the X axis.
             * @return true if successful.
             */
            virtual Bool SetMaximumX(Real x) = 0;
            /**
             * @brief Set the maximum coordinate value for the Y axis only.
             * @param y The maximum value for the Y axis.
             * @return true if successful.
             */
            virtual Bool SetMaximumY(Real y) = 0;
            /**
             * @brief Set the maximum coordinate value for the Z axis only.
             * @param z The maximum value for the Z axis.
             * @return true if successful.
             */
            virtual Bool SetMaximumZ(Real z) = 0;
            
            /**
             * @brief Get the maximum coordinate values for the X, Y and Z axes.
             * @return A vector containing the individual coordinate values.
             */
            virtual const Vector& GetMaximum() const = 0;
            /**
             * @brief Get the maximum coordinate value for the X axis.
             * @return The maximum coordinate for the X axis.
             */
            virtual Real GetMaximumX() const = 0;
            /**
             * @brief Get the maximum coordinate value for the Y axis.
             * @return The maximum coordinate for the Y axis.
             */
            virtual Real GetMaximumY() const = 0;
            /**
             * @brief Get the maximum coordinate value for the Z axis.
             * @return The maximum coordinate for the Z axis.
             */
            virtual Real GetMaximumZ() const = 0;
            
        protected:
            virtual ~IBoundingBox() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IBoundingBox nodes.
         */
        typedef IGenericNodeTarget<IBoundingBox> IBoundingBoxNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_BOUNDING_BOX_H__
