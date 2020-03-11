// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_RESOURCE_SHADOW_GEOMETRY_H__
#define __MURL_GRAPH_I_RESOURCE_SHADOW_GEOMETRY_H__

#include "murl_graph_i_resource_mesh_geometry.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IResourceShadowGeometry
         * @brief The IResourceShadowGeometry graph node interface.
         * This interface represents a renderable shadow volume geometry that is dynamically
         * generated from the geometry information stored in a given read-only Resource::IMesh 
         * object, together with (an) active light source(s) at a given unit.
         */
        class IResourceShadowGeometry
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
             * @brief Get the mutable Graph::IResourceMeshGeometry interface.
             * This method returns a mutable pointer to the node's Graph::IResourceMeshGeometry interface,
             * to be able to query or modify base properties of the shadow geometry.
             * @return The mutable Graph::IResourceMeshGeometry interface.
             */
            virtual IResourceMeshGeometry* GetResourceMeshGeometryInterface() = 0;
            /**
             * @brief Get the constant Graph::IResourceMeshGeometry interface.
             * This method returns a constant pointer to the node's Graph::IResourceMeshGeometry interface,
             * to be able to query base properties of the shadow geometry.
             * @return The constant Graph::ITransform Graph::IResourceMeshGeometry interface.
             */
            virtual const IResourceMeshGeometry* GetResourceMeshGeometryInterface() const = 0;

            /**
             * @brief Set the light unit used for shadow volume creation.
             * @param unit The light unit in the range from 0 to IEnums::NUM_LIGHT_UNITS-1.
             * @return true if successful.
             */
            virtual Bool SetLightUnit(UInt32 unit) = 0;
            /**
             * @brief Get the light unit used for shadow volume creation.
             * @return The light unit in the range from 0 to IEnums::NUM_LIGHT_UNITS-1.
             */
            virtual UInt32 GetLightUnit() const = 0;

            /**
             * @brief Set which faces are used to extrude the shadow volumes.
             * @param faces The used faces, either IEnums::POLYGON_FACES_FRONT_ONLY or 
             *      IEnums::POLYGON_FACES_BACK_ONLY.
             * @return true if successful.
             */
            virtual Bool SetFacesToExtrude(IEnums::PolygonFaces faces) = 0;
            /**
             * @brief Query which faces are used to extrude the shadow volumes.
             * @return The used faces.
             */
            virtual IEnums::PolygonFaces GetFacesToExtrude() const = 0;

            /**
             * @brief Set the shadow volume generation mode.
             * If set to IEnums::SHADOW_VOLUME_GENERATION_MODE_DEFAULT, the preferred way is to
             * use geometry adjacency information, if present. Otherwise, bounding data
             * is used.
             * @param mode The generation mode.
             * @return true if successful.
             */
            virtual Bool SetShadowVolumeGenerationMode(IEnums::ShadowVolumeGenerationMode mode) = 0;
            /**
             * @brief Query the shadow volume generation mode.
             * @return The generation mode.
             */
            virtual IEnums::ShadowVolumeGenerationMode GetShadowVolumeGenerationMode() const = 0;

        protected:
            virtual ~IResourceShadowGeometry() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IResourceShadowGeometry nodes.
         */
        typedef IGenericNodeTarget<IResourceShadowGeometry> IResourceShadowGeometryNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_RESOURCE_SHADOW_GEOMETRY_H__
