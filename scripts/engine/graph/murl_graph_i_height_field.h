// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_HEIGHT_FIELD_H__
#define __MURL_GRAPH_I_HEIGHT_FIELD_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IHeightField
         * @brief The IHeightField graph node interface.
         * This interface represents a generic height field, which consists of a rectangular
         * data set representing discrete points in the XZ plane with exactly one elevation value
         * at a given XZ coordinate.
         */
        class IHeightField
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
             * @brief Get the height field's extent along the X axis.
             * @return The X dimension of the height field.
             */
            virtual Real GetFieldSizeX() const = 0;
            /**
             * @brief Get the height field's extent along the Z axis.
             * @return The Z dimension of the height field.
             */
            virtual Real GetFieldSizeZ() const = 0;

            /**
             * @brief Get the height field's elevation (Y coordinate) for a given XZ coordinate.
             * @param posX The X coordinate to query.
             * @param posZ The Z coordinate to query.
             * @return The (interpolated) Y elevation at the given XZ coordinate.
             */
            virtual Real GetFieldElevation(Real posX, Real posZ) const = 0;
            
        protected:
            virtual ~IHeightField() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IHeightField nodes.
         */
        typedef IGenericNodeTarget<IHeightField> IHeightFieldNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_HEIGHT_FIELD_H__
