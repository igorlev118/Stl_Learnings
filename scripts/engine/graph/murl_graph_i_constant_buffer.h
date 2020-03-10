// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_CONSTANT_BUFFER_H__
#define __MURL_GRAPH_I_CONSTANT_BUFFER_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_graph_i_uniform_container.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphPropertyInterfaces
         * @interface IConstantBuffer
         * @brief The IConstantBuffer property interface.
         * This interface provides properties common to a class representing an
         * array of individual uniform variables, grouped together in order to quickly
         * activate them for a shader program.
         */
        class IConstantBuffer : public IUniformContainer
        {
        public:
            /**
             * @brief Get the zero-based index of this constant buffer.
             * @return The constant buffer's index inside the parent container.
             */
            virtual SInt32 GetIndex() const = 0;
            /**
             * @brief Get the constant buffer's name.
             * @return The name.
             */
            virtual const String& GetName() const = 0;
            /**
             * @brief Get the constant buffer's predefined item.
             * If the constant buffer is a user-defined one, this method always returns
             * IEnums::CONSTANT_BUFFER_ITEM_CUSTOM.
             * @return The constant buffer item.
             */
            virtual IEnums::ConstantBufferItem GetItem() const = 0;

            /**
             * @brief Set the maximum byte size of the constant buffer.
             * @param maxByteSize The maximum capacity in bytes.
             * @param preserveContents If true, existing contents will be copied;
             *      but existing data beyond the new capacity is discarded.
             * @return true if successful.
             */
            virtual Bool SetMaxByteSize(UInt32 maxByteSize, Bool preserveContents) = 0;
            /**
             * @brief Get the maximum capacity of the constant buffer in bytes.
             * @return The maximum capacity.
             */
            virtual UInt32 GetMaxByteSize() const = 0;
            
            /**
             * @brief Set the total byte size of all variables in the constant buffer.
             * @param byteSize The currently used total number of bytes for all variables.
             * @return true if successful.
             */
            virtual Bool SetByteSize(UInt32 byteSize) = 0;
            /**
             * @brief Get the total byte size of all variables in the constant buffer.
             * @return The currently used total number of bytes for all variables.
             */
            virtual UInt32 GetByteSize() const = 0;
            
            /**
             * @brief Retrieve a mutable pointer to the variable data stored in the buffer.
             * @return A mutable pointer to the data.
             */
            virtual void* GetConstantData() = 0;
            /**
             * @brief Retrieve a constant pointer to the variable data stored in the buffer.
             * @return A constant pointer to the data.
             */
            virtual const void* GetConstantData() const = 0;

            /**
             * @brief Mark the constant buffer as modified.
             * @return true if successful.
             */
            virtual Bool SetConstantsModified() = 0;
            
        protected:
            virtual ~IConstantBuffer() {}
        };

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IConstantBuffer nodes.
         */
        typedef IGenericNodeTarget<IConstantBuffer> IConstantBufferNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_CONSTANT_BUFFER_H__
