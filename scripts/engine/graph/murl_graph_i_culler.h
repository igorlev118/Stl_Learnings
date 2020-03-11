// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_CULLER_H__
#define __MURL_GRAPH_I_CULLER_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_graph_i_subject.h"

namespace Murl
{
    namespace Graph
    {
        class IBoundingVolume;
        class ICuller;

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::ICuller nodes.
         */
        typedef IGenericNodeTarget<ICuller> ICullerNodeTarget;

        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface ICuller
         * @brief The ICuller graph node interface.
         * This interface represents a node that can be used to cull away any objects that
         * cannot be seen through a specific camera or heard via a specific listener, mainly
         * to speed up audio/video rendering.
         *
         * Cullers are always attached to a given Graph::ISubject node (a camera or listener),
         * retrieving that subject's position, orientation and other parameters such as viewing
         * frustum etc., to determine its actual perception area. In addition, cullers may
         * rely on extended information (such as BSP visibility information optionally contained
         * within a Resource::IMesh object for a Graph::IResourceMeshCuller node) to perform
         * more precise object culling.
         *
         * See @ref sceneGraphStatesSlotsUnits for an overview of state handling during scene 
         * graph traversal.\n
         * See Graph::ICullerState for activating a culler during traversal.
         */
        class ICuller
        {
        public:
            /// Intersection flags.
            enum IntersectionFlags
            {
                /// Query intersections with the overall bounding volume.
                INTERSECTION_FLAG_VOLUME        = (1 << 0),
                /// Query intersections with the near plane.
                INTERSECTION_FLAG_NEAR_PLANE    = (1 << 1),
                /// Query intersections with the far plane.
                INTERSECTION_FLAG_FAR_PLANE     = (1 << 2),

                /// Do not query intersections, report back the same flag.
                INTERSECTION_FLAG_ALWAYS        = 0xffffffff,

                /// No intersection flags.
                INTERSECTION_FLAG_NONE          = 0,

                /// All available intersection flags combined.
                INTERSECTION_FLAG_ALL           = INTERSECTION_FLAG_VOLUME
                                                + INTERSECTION_FLAG_NEAR_PLANE
                                                + INTERSECTION_FLAG_FAR_PLANE
            };
            
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
             * @brief Get the mutable container holding the optional child cullers.
             * This method returns a mutable pointer to the node's Graph::ICullerNodeTarget
             * sub container, which is used to store multiple sub-cullers.
             * @return The mutable Graph::ICullerNodeTarget container, or null if not available.
             */
            virtual ICullerNodeTarget* GetSubCullerNodeTarget() = 0;
            /**
             * @brief Get the constant container holding the optional child cullers.
             * This method returns a constant pointer to the node's Graph::ICullerNodeTarget
             * sub container, which is used to store multiple sub-cullers.
             * @return The constant Graph::ICullerNodeTarget container, or null if not available.
             */
            virtual const ICullerNodeTarget* GetSubCullerNodeTarget() const = 0;

            /**
             * @brief Get the mutable Graph::ISubjectNodeTarget container.
             * This method returns a mutable pointer to the node's Graph::ISubjectNodeTarget
             * container, which allows to set or query the subject this culler refers to.
             * @return The mutable Graph::ISubjectNodeTarget container, or null if not available.
             */
            virtual ISubjectNodeTarget* GetSubjectNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::ISubjectNodeTarget container.
             * This method returns a constant pointer to the node's Graph::ISubjectNodeTarget
             * container, which allows to query the camera this state node refers to.
             * @return The mutable Graph::ISubjectNodeTarget container, or null if not available.
             */
            virtual const ISubjectNodeTarget* GetSubjectNodeTarget() const = 0;
            
            /**
             * @brief Get the mutable Graph::ICullerNodeTarget container storing the culler's parent.
             * This method returns a mutable pointer to the node's Graph::ICullerNodeTarget
             * container that stores an optional reference to another culler, to set or query the
             * culler's parent.
             * @return The mutable Graph::ICullerNodeTarget parent container, or null if not available.
             */
            virtual ICullerNodeTarget* GetParentCullerNodeTarget() = 0;
            /**
             * @brief Get the constant Graph::ICullerNodeTarget container storing the culler's parent.
             * This method returns a constant pointer to the node's Graph::ICullerNodeTarget
             * container that stores an optional reference to another culler, to query the
             * culler's parent.
             * @return The constant Graph::ICullerNodeTarget parent container, or null if not available.
             */
            virtual const ICullerNodeTarget* GetParentCullerNodeTarget() const = 0;

            /**
             * @brief Check if a given bounding volume can be culled.
             * This method checks if a bounding volume transformed via a given world matrix and
             * scale factor is intersecting the culler's view area. If false, the object represented
             * through this volume is not visible and can be culled.
             * @param boundingVolume The object's bounding volume.
             * @param flags A combination of IntersectionFlags specifying for which attributes to
             *      perform the intersection test.
             * @return A combination of IntersectionFlags specifying the result of the intersection test.
             */
            virtual UInt32 Intersect(const IBoundingVolume* boundingVolume, UInt32 flags) const = 0;

            /**
             * @brief Get the culler's number of stages.
             * @return The number of stages.
             */
            virtual UInt32 GetNumberOfStages() const = 0;
            /**
             * @brief Get the culler's actual node at a given stage.
             * @param stage The stage to query.
             * @return The culler sub-object.
             */
            virtual const ICuller* GetCuller(UInt32 stage) const = 0;

        protected:
            virtual ~ICuller() {}
        };
    }
}

#endif // __MURL_GRAPH_I_CULLER_H__
