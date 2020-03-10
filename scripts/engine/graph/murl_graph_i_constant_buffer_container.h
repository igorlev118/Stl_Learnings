// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_CONSTANT_BUFFER_CONTAINER_H__
#define __MURL_GRAPH_I_CONSTANT_BUFFER_CONTAINER_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_graph_i_constant_buffer.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphPropertyInterfaces
         * @interface IConstantBufferContainer
         * @brief The IConstantBufferContainer property interface.
         * This interface provides a way to manage multiple individual constant buffer
         * objects, which each of them holdin a set of different shader variables.
         */
        class IConstantBufferContainer
        {
        public:
            /**
             * @brief Add a constant buffer with predefined semantics.
             * This method creates and adds a constant buffer to the container, using one of the 
             * available predefined semantics defined in IEnums::ConstantBufferItem. If successful, 
             * this method returns the zero-based index of the newly created constant buffer within
             * the container; if failed, -1 is returned.
             * @param item The predefined constant buffer item to add.
             * @return The zero-based index of the buffer in the container, or -1 if failed.
             */
            virtual SInt32 AddConstantBuffer(IEnums::ConstantBufferItem item) = 0;
            /**
             * @brief Add a constant buffer with custom semantics.
             * This method creates and adds a constant buffer to the container, using custom
             * semantics defined via a unique name. If successful, this method returns the zero-based 
             * index of the newly created constant buffer within the container; if failed, -1 is 
             * returned.
             * @param name The custom semantic name.
             * @return The zero-based index of the buffer in the container, or -1 if failed.
             */
            virtual SInt32 AddConstantBuffer(const String& name) = 0;
            
            /**
             * @brief Query the location of a predefined constant buffer in the container.
             * This method can be used to query the zero-based index of a constant buffer with given 
             * predefined semantics. If the container does not hold a buffer with the requested
             * semantics, -1 is returned.
             * @param item The predefined constant buffer item to query.
             * @return The zero-based index of the buffer, or -1 if not found.
             */
            virtual SInt32 GetConstantBufferIndex(IEnums::ConstantBufferItem item) const = 0;
            /**
             * @brief Query the location of a constant buffer with custom semantics.
             * This method can be used to query the zero-based index of a constant buffer with given
             * user-defined semantics. If the container does not hold a buffer with the requested
             * semantics, -1 is returned.
             * @param name The custom semantic name.
             * @return The zero-based index of the buffer, or -1 if not found.
             */
            virtual SInt32 GetConstantBufferIndex(const String& name) const = 0;
            /**
             * @brief Get the total number of individual constant buffers in the container.
             * @return The total number of buffers added.
             */
            virtual UInt32 GetNumberOfConstantBuffers() const = 0;
            
            /**
             * @brief Query the predefined semantic item of a constant buffer at a given index.
             * If the buffer at the given index represents has predefined semantics, this method 
             * returns the actual item, e.g. IEnums::CONSTANT_BUFFER_ITEM_MATERIAL for a material-
             * related buffer.
             * If the buffer is a user-defined one, it returns IEnums::CONSTANT_BUFFER_ITEM_CUSTOM.
             * @param index The zero-based index of the buffer to query.
             * @return The predefined constant buffer semantics item.
             */
            virtual IEnums::ConstantBufferItem GetConstantBufferItem(UInt32 index) const = 0;
            /**
             * @brief Query the semantic name of a constant buffer at a given index.
             * If the buffer at the given index has user-defined semantics, this method returns
             * its actual name string. If it has predefined semantics, an empty string is returned.
             * @param index The zero-based index of the buffer to query.
             * @return The user-defined constant buffer semantics item.
             */
            virtual const String& GetConstantBufferName(UInt32 index) const = 0;
            
            /**
             * @brief Get the constant buffer object at a given index.
             * @param index The zero-based index of the buffer to retrieve.
             * @return The constant buffer object.
             */
            virtual IConstantBuffer* GetConstantBuffer(UInt32 index) const = 0;
            
        protected:
            virtual ~IConstantBufferContainer() {}
        };

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IConstantBufferContainer nodes.
         */
        typedef IGenericNodeTarget<IConstantBufferContainer> IConstantBufferContainerNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_CONSTANT_BUFFER_CONTAINER_H__
