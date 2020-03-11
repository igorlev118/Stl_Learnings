// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_CLONE_TRANSFORM_H__
#define __MURL_GRAPH_I_CLONE_TRANSFORM_H__

#include "murl_graph_i_anchor.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface ICloneTransform
         * @brief The ICloneTransform graph node interface.
         * Nodes implementing the ICloneTransform interface can be connected to Graph::IAnchor nodes,
         * for the purpose of remotely retrieving and setting the most recent world-space transform
         * during traversal, i.e. cloning the transform of another node.
         * Anchors can either be accessed via the IAnchorNodeTarget returned from GetAnchorNodeTarget(),
         * or by setting an anchor slot in the range [0..NUM_ANCHOR_SLOTS-1] via SetAnchorSlot().
         *
         * See Graph::IAnchor for defining an anchor transform to refer to.
         */
        class ICloneTransform
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
             * @brief Get the mutable Graph::IAnchorNodeTarget container.
             * This method returns a mutable pointer to the node's Graph::IAnchorNodeTarget
             * container, which allows to add, remove or query the referenced Graph::IAnchor node.
             * @return The mutable Graph::IAnchorNodeTarget container, or null if not available
             */
            virtual IAnchorNodeTarget* GetAnchorNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::IAnchorNodeTarget container.
             * This method returns a constant pointer to the node's Graph::IAnchorNodeTarget
             * container, which allows to query the referenced Graph::IAnchor node.
             * @return The constant Graph::IAnchorNodeTarget container, or null if not available
             */
            virtual const IAnchorNodeTarget* GetAnchorNodeTarget() const = 0;

            /**
             * @brief Set the anchor slot used to source an anchor.
             * @param slot The anchor slot.
             * @return true if successful.
             */
            virtual Bool SetAnchorSlot(SInt32 slot) = 0;
            /**
             * @brief Get the anchor slot used source an anchor.
             * @return The anchor slot.
             */
            virtual SInt32 GetAnchorSlot() const = 0;

            /**
             * @brief Enable/disable absolute transform.
             * Whereas the matrix returned by the targeted Graph::IAnchor node always represents
             * the anchor's most recent transform in world coordinates, the ICloneTransform may
             * use that matrix in either an absolute fashion (i.e. replace the current world
             * transform by the anchor's), or re-apply it onto the world transform currently on
             * its traversal stack (i.e. multiply it).
             * @param enabled If true, the anchor's transform replaces the current world transform
             * @return true if successful
             */
            virtual Bool SetUsingAbsoluteTransformEnabled(Bool enabled) = 0;
            /**
             * @brief Check if absolute transforms are enabled.
             * @return true if enabled.
             */
            virtual Bool IsUsingAbsoluteTransformEnabled() const = 0;

            /**
             * @brief Enable/disable rotation cloning.
             * If disabled, the cloned transform's upper 3x3 matrix will be set to the identity
             * matrix, i.e. the anchor's rotation part will not be cloned.
             * @param enabled If false, rotation cloning is disabled
             * @return true if successful
             */
            virtual Bool SetAffectRotationEnabled(Bool enabled) = 0;
            /**
             * @brief Check if rotation cloning is enabled.
             * @return true if enabled.
             */
            virtual Bool IsAffectRotationEnabled() const = 0;
            
            /**
             * @brief Enable/disable translation cloning.
             * If disabled, the cloned transform's XW, YW and ZW components will be initialized
             * to zero, i.e. the anchor's translation part will not be cloned.
             * @param enabled If false, translation cloning is disabled
             * @return true if successful
             */
            virtual Bool SetAffectTranslationEnabled(Bool enabled) = 0;
            /**
             * @brief Check if translation cloning is enabled.
             * @return true if enabled.
             */
            virtual Bool IsAffectTranslationEnabled() const = 0;
            
            /**
             * @brief Enable/disable depth order cloning.
             * @param enabled If true, the depth order is cloned.
             * @return true if successful.
             */
            virtual Bool SetAffectDepthOrderEnabled(Bool enabled) = 0;
            /**
             * @brief Check if cloning of the current depth order is enabled.
             * @return true if enabled.
             */
            virtual Bool IsAffectDepthOrderEnabled() const = 0;

        protected:
            virtual ~ICloneTransform() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::ICloneTransform nodes.
         */
        typedef IGenericNodeTarget<ICloneTransform> ICloneTransformNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_CLONE_TRANSFORM_H__
