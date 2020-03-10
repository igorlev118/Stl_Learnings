// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_VIDEO_I_CONSTANTS_H__
#define __MURL_VIDEO_I_CONSTANTS_H__

#include "murl_video_types.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Video
    {
        class IProgram;
        class IConstantBuffer;
        class IObject;
        
        /**
         * @ingroup MurlVideoObjectInterfaces
         * @interface IConstants
         * @brief The IConstants video object interface.
         * This interface represents a container object holding references to one or
         * more individual IConstantBuffer objects.
         *
         * Used internally by Graph::FixedParameters and Graph::GenericParameters.
         */
        class IConstants
        {
        public:
            /**
             * @brief Get the mutable Video::IObject interface.
             * @return The IObject interface.
             */
            virtual IObject* GetObjectInterface() = 0;
            /**
             * @brief Get the constant Video::IObject interface.
             * @return The IObject interface.
             */
            virtual const IObject* GetObjectInterface() const = 0;

            /**
             * @brief Enable the constants container.
             * @return true if successful.
             */
            virtual Bool Enable() = 0;
            /**
             * @brief Disable the constants container.
             * @return true if successful.
             */
            virtual Bool Disable() = 0;
            
            /**
             * @brief Attach the constants container to the current GPU program.
             * @param currentProgram The current GPU program.
             * @return true if successful.
             */
            virtual Bool Set(IProgram* currentProgram) = 0;
            
            /**
             * @brief Add a single default constant buffer.
             * @param constantBuffer The constant buffer to add.
             * @return The zero-based index of the constant buffer in the container, or -1 if failed.
             */
            virtual SInt32 AddConstantBuffer(IConstantBuffer* constantBuffer) = 0;
            /**
             * @brief Add a single predefined constant buffer.
             * @param item The predefined item.
             * @param constantBuffer The constant buffer to add.
             * @return The zero-based index of the constant buffer in the container, or -1 if failed.
             */
            virtual SInt32 AddConstantBuffer(IEnums::ConstantBufferItem item, IConstantBuffer* constantBuffer) = 0;
            /**
             * @brief Add a single custom constant buffer, by its unique integer ID in the renderer.
             * @param id The buffer's unique integer ID.
             * @param constantBuffer The constant buffer to add.
             * @return The zero-based index of the constant buffer in the container, or -1 if failed.
             */
            virtual SInt32 AddConstantBuffer(SInt32 id, IConstantBuffer* constantBuffer) = 0;
            /**
             * @brief Add a single custom constant buffer, by its actual name.
             * @param name The buffer name.
             * @param constantBuffer The constant buffer to add.
             * @return The zero-based index of the constant buffer in the container, or -1 if failed.
             */
            virtual SInt32 AddConstantBuffer(const String& name, IConstantBuffer* constantBuffer) = 0;
            /**
             * @brief Remove all present constant buffers from the container.
             * @return true if successful.
             */
            virtual Bool RemoveAllConstantBuffers() = 0;

            /**
             * @brief Get the index of a predefined constant buffer in the container.
             * @param item The constant buffer item to query.
             * @return The zero-based index of the buffer, or -1 if not found.
             */
            virtual SInt32 GetConstantBufferIndex(IEnums::ConstantBufferItem item) const = 0;
            /**
             * @brief Get the index of a custom constant buffer in the container, by its unique integer ID.
             * @param id The unique integer ID of the constant buffer to query.
             * @return The zero-based index of the buffer, or -1 if not found.
             */
            virtual SInt32 GetConstantBufferIndex(SInt32 id) const = 0;
            /**
             * @brief Get the index of a custom constant buffer in the container, by its actual name.
             * @param name The buffer name.
             * @return The zero-based index of the buffer, or -1 if not found.
             */
            virtual SInt32 GetConstantBufferIndex(const String& name) const = 0;
            /**
             * @brief Get the total number of individual constant buffers present in the container.
             * @return The number of constant buffers present.
             */
            virtual UInt32 GetNumberOfConstantBuffers() const = 0;
            
            /**
             * @brief Get the predefined constant buffer item at a given index.
             * @param index The index of the buffer to query, from 0 to GetNumberOfConstantBuffers()-1.
             * @return The predefined buffer item, or IEnums::CONSTANT_BUFFER_ITEM_CUSTOM if the index
             *      is out of range.
             */
            virtual IEnums::ConstantBufferItem GetConstantBufferItem(UInt32 index) const = 0;
            /**
             * @brief Get the unique integer ID of a constant buffer at a given index.
             * @param index The index of the buffer to query, from 0 to GetNumberOfConstantBuffers()-1.
             * @return The unique ID, or -1 if the index is out of range.
             */
            virtual SInt32 GetConstantBufferId(UInt32 index) const = 0;
            
            /**
             * @brief Get the constant buffer at a given index.
             * @param index The index of the buffer to query, from 0 to GetNumberOfConstantBuffers()-1.
             * @return The buffer, or null if the index is out of range.
             */
            virtual IConstantBuffer* GetConstantBuffer(UInt32 index) const = 0;
            
            /**
             * @brief Check if the container is equal to another one.
             * @param other The container to compare with.
             * @return true if the containers are equal.
             */
            virtual Bool AreEqual(const IConstants* other) const = 0;
            
            /**
             * @brief Get the signature, obtained via IRenderer::AcquireConstantsSignature().
             * @return The buffer signature.
             */
            virtual UInt32 GetSignature() const = 0;
            
        protected:
            virtual ~IConstants() {}
        };
    }
}

#endif // __MURL_VIDEO_I_CONSTANTS_H__
