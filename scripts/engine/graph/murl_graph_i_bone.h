// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_BONE_H__
#define __MURL_GRAPH_I_BONE_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_graph_i_state_unit.h"

namespace Murl
{
    namespace Video
    {
        class IBone;
    }
    
    namespace Graph
    {
        class ITransform;

        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IBone
         * @brief The IBone graph node interface.
         * Bones can be used to build an (animated) skeleton structure, to
         * later apply vertex skinning to a mesh, in other words deform the model of
         * e.g. a human body according to the movements of the skeleton.
         *
         * The first of two ways to use a bone is to activate it through a Graph::IBoneState
         * node later in the scene graph, which assigns the bone to a given unit. Subsequent
         * rendering geometry can refer to this bone through the assigned unit; there is a
         * maximum of 24 distinct units that can be used in parallel (geometry that is using
         * more than 24 bones by design must be split into multiple separate geometries through
         * the scene converter tool. See IEnums::BoneUnit).
         *
         * Use the Graph::IStateUnit base interface to set or get the bone unit index this
         * bone is temporarily attached to if any children are present.
         *
         * See @ref sceneGraphStatesSlotsUnits for an overview of state handling during scene 
         * graph traversal.\n
         * See Graph::IBoneState for assigning bones.
         */
        class IBone : public IStateUnit
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
             * @brief Set the offset transform.
             * An animated skeleton can simply be built and visualized in a hierarchical way,
             * using relative transforms (and attached animations) for each individual bone
             * with regard to its parent structure. To connect the skeleton to a given
             * renderable mesh at run-time, which is usually modeled in some form of "bind pose",
             * an additional transform for each bone is needed. This "offset transform" is
             * static for a single mesh-skeleton relation.
             * @param offsetTransform The offset transform to set.
             * @return true if successful.
             */
            virtual Bool SetOffsetTransform(const Matrix& offsetTransform) = 0;
            /**
             * @brief Get the constant offset transform.
             * @return A constant reference to the internal offset transform.
             */
            virtual const Matrix& GetOffsetTransform() const = 0;
            /**
             * @brief Get the mutable offset transform.
             * This method can be called to get access to the internal offset transform
             * for direct manipulation. Internally, the bone's state will be set to
             * "modified" as soon as this method is called.
             * @return A mutable reference to the internal offset transform.
             */
            virtual Matrix& GetOffsetTransform() = 0;
            
            /**
             * @brief Set the user transform.
             * By default, the user transform equals the identity matrix. Individual
             * bones of a skeleton may be easily controlled by a Logic::IProcessor
             * by simply manipulating their user transform, i.e. by calling this function.
             * For example, in an animated human body model one could simply pick
             * the skeleton's "spine" bone and replace its user matrix with a matrix
             * containing a rotation around e.g. the Y axis (depending how the model
             * was designed) to make the figure's head turn.
             * @param userTransform The user transform to set.
             * @return true if successful.
             */
            virtual Bool SetUserTransform(const Matrix& userTransform) = 0;
            /**
             * @brief Get the constant user transform.
             * @return A constant reference to the internal user transform.
             */
            virtual const Matrix& GetUserTransform() const = 0;
            /**
             * @brief Get the mutable user transform.
             * This method can be called to get access to the internal user transform
             * for direct manipulation. Internally, the bone's state will be set to
             * "modified" as soon as this method is called.
             * @return A mutable reference to the internal user transform.
             */
            virtual Matrix& GetUserTransform() = 0;

            /**
             * @brief Get the constant overall bone transform.
             * @return A constant reference to the overall bone transform.
             */
            virtual const Matrix& GetBoneTransform() const = 0;

            /**
             * @brief Get the bone's number of stages.
             * @return The number of stages.
             */
            virtual UInt32 GetNumberOfStages() const = 0;
            /**
             * @brief Get the bone's internal video renderer object.
             * @param stage The stage to query.
             * @return The video renderer object.
             */
            virtual Video::IBone* GetVideoBoneObject(UInt32 stage) const = 0;
            
        protected:
            virtual ~IBone() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IBone nodes.
         */
        typedef IGenericNodeTarget<IBone> IBoneNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_BONE_H__
