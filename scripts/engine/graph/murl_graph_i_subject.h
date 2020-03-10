// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_SUBJECT_H__
#define __MURL_GRAPH_I_SUBJECT_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_graph_i_anchor.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface ISubject
         * @brief The ISubject graph node interface.
         * Graph::ISubject nodes represent a generic way to define properties like view matrix,
         * projection matrix, view frustum etc. that are common to e.g. cameras and listeners.
         */
        class ISubject
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
             * @brief Set the subject's world transform matrix.
             * @param worldTransform The world transform.
             * @return true if successful.
             */
            virtual Bool SetWorldTransform(const Matrix& worldTransform) = 0;
            /**
             * @brief Get the subject's world transform matrix.
             * @return The world transform.
             */
            virtual const Matrix& GetWorldTransform() const = 0;
            /**
             * @brief Get the subject's view matrix.
             * The view matrix is actually the inverse of the subject's world transform matrix;
             * it is used to transform geometry from world space to view space.
             * @return The view matrix.
             */
            virtual const Matrix& GetViewMatrix() const = 0;
            /**
             * @brief Get the subject's projection matrix.
             * @return The projection matrix.
             */
            virtual const Matrix& GetProjectionMatrix() const = 0;
            /**
             * @brief Get the subject's view frustum, if available.
             * @return A constant pointer to the view frustum, or a null pointer if not available.
             */
            virtual const Frustum* GetViewFrustum() const = 0;
            /**
             * @brief Get the subject's view cone, if available.
             * @return A constant pointer to the view cone, or a null pointer if not available.
             */
            virtual const Cone* GetViewCone() const = 0;
            /**
             * @brief Get the subject's view box, if available.
             * @return A constant pointer to the view box, or a null pointer if not available.
             */
            virtual const Box* GetViewBox() const = 0;
            /**
             * @brief Get the subject's view cylinder, if available.
             * @return A constant pointer to the view cylinder, or a null pointer if not available.
             */
            virtual const Cylinder* GetViewCylinder() const = 0;

        protected:
            virtual ~ISubject() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::ISubject nodes.
         */
        typedef IGenericNodeTarget<ISubject> ISubjectNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_SUBJECT_H__
