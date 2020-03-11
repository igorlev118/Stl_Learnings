// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_VIDEO_I_INDEX_BUFFER_H__
#define __MURL_VIDEO_I_INDEX_BUFFER_H__

#include "murl_video_types.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Video
    {
        class IObject;

        /**
         * @ingroup MurlVideoObjectInterfaces
         * @interface IIndexBuffer
         * @brief The IIndexBuffer video object interface.
         * This interface represents a buffer containing indices of an indexed geometry.
         *
         * Used internally by various geometry graph nodes, such as Graph::GenericGeometry,
         * Graph::ResourceMeshGeometry and others.
         */
        class IIndexBuffer
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
             * @brief Draw geometry using this index buffer.
             * @return true if successful.
             */
            virtual Bool Draw() = 0;

            /**
             * @brief Allow/disallow dynamic batching.
             * @param allowed If true, dynamic batching is allowed.
             * @return true if successful.
             */
            virtual Bool SetDynamicBatchingAllowed(Bool allowed) = 0;
            /**
             * @brief Check if the buffer allows for dynamic batching.
             * @return true if dynamic batching is allowed.
             */
            virtual Bool IsDynamicBatchingAllowed() const = 0;
            
            /**
             * @brief Set the access mode hint (read only or read/write).
             * @param mode The access mode.
             * @return true if successful.
             */
            virtual Bool SetAccessMode(IEnums::BufferAccessMode mode) = 0;
            /**
             * @brief Get the access mode hint.
             * @return The access mode.
             */
            virtual IEnums::BufferAccessMode GetAccessMode() const = 0;

            /**
             * @brief Set the primitive type to render.
             * @param type The primitive type.
             * @return true if successful.
             */
            virtual Bool SetPrimitiveType(IEnums::PrimitiveType type) = 0;
            /**
             * @brief Get the primitive type.
             * @return The primitive type.
             */
            virtual IEnums::PrimitiveType GetPrimitiveType() const = 0;

            /**
             * @brief Set the data type of the indices stored in the buffer.
             * @param type One of the IEnums::IndexType members.
             * @return true if successful.
             */
            virtual Bool SetIndexType(IEnums::IndexType type) = 0;
            /**
             * @brief Get the data type of the indices stored in the buffer.
             * @return One of the IEnums::IndexType members.
             */
            virtual IEnums::IndexType GetIndexType() const = 0;

            /**
             * @brief Assign a mutable source data storage.
             * @param indices A pointer to the mutable buffer holding the source indices.
             * @param maxNumberOfIndices The maximum number of indices the buffer can hold.
             * @return true if successful.
             */
            virtual Bool SetIndexData(void* indices, UInt32 maxNumberOfIndices) = 0;
            /**
             * @brief Assign a constant source data storage.
             * @param indices A pointer to the constant buffer holding the source indices.
             * @param maxNumberOfIndices The maximum number of indices the buffer can hold.
             * @return true if successful.
             */
            virtual Bool SetIndexData(const void* indices, UInt32 maxNumberOfIndices) = 0;
            /**
             * @brief Set the actual number of indices used.
             * @param numberOfIndices The actual number of indices. Must be less or equal than
             *      the maximum number defined via SetIndexData().
             * @return true if successful.
             */
            virtual Bool SetNumberOfIndices(UInt32 numberOfIndices) = 0;
            /**
             * @brief Mark the whole buffer as modified.
             * @return true if successful.
             */
            virtual Bool SetIndicesModified() = 0;
            /**
             * @brief Mark a sub-region of the buffer as modified.
             * @param firstIndex The first modified index in the buffer.
             * @param numberOfIndices The number of modified indices.
             * @return true if successful.
             */
            virtual Bool SetIndicesModified(UInt32 firstIndex, UInt32 numberOfIndices) = 0;
            /**
             * @brief Get a pointer to the mutable source data, if available.
             * If the source data storage was defined using a constant pointer, this method returns null.
             * @return A pointer to the mutable source data, or null if the source is immutable.
             */
            virtual void* GetIndexData() = 0;
            /**
             * @brief Get a pointer to the constant source data.
             * @return A pointer to the source data.
             */
            virtual const void* GetIndexData() const = 0;
            /**
             * @brief Get a pointer to the actual mutable buffer data.
             * @return A pointer to the actual buffer data.
             */
            virtual void* GetIndexBufferData() = 0;
            /**
             * @brief Get a pointer to the actual constant buffer data.
             * @return A pointer to the actual buffer data.
             */
            virtual const void* GetIndexBufferData() const = 0;
            /**
             * @brief Get the maximum number of indices the buffer can hold.
             * @return The maximum number of indices.
             */
            virtual UInt32 GetMaxNumberOfIndices() const = 0;
            /**
             * @brief Get the actual number of indices used.
             * @return The actual number of indices.
             */
            virtual UInt32 GetNumberOfIndices() const = 0;
            /**
             * @brief Check if the buffer contents are modified.
             * @return true if modified.
             */
            virtual Bool AreIndicesModified() const = 0;

            /**
             * @brief Assign a mutable data storage defining individual buffer segments.
             * The given segment data must be an array of 2*N UInt32 values defining N
             * individual index buffer segments. The first UInt32 value of each segment
             * (2*i) defines the number of indices belonging to that segment, and the
             * second (2*i+1) value defines the start index into the source indices
             * set via SetIndexData().
             * If segments are defined, an intermediate buffer is created that receives
             * a consecutive list of all indices over all segments.
             * If not defined, the whole index buffer is rendered "as-is".
             * @param segments An array of segments.
             * @return true if successful.
             */
            virtual Bool SetSegmentData(UInt32* segments) = 0;
            /**
             * @brief Assign a constant data storage defining individual buffer segments.
             * See SetSegmentData(UInt32*).
             * @param segments An array of segments.
             * @return true if successful.
             */
            virtual Bool SetSegmentData(const UInt32* segments) = 0;
            /**
             * @brief Set the actual number of segments used.
             * @param numberOfSegments The actual number of segments. 2*numberOfSegments
             *      must be less or equal than the number of array entries for the
             *      segments set via SetSegmentData().
             * @return true if successful.
             */
            virtual Bool SetNumberOfSegments(UInt32 numberOfSegments) = 0;
            /**
             * @brief Mark the segments as modified.
             * @return true if successful.
             */
            virtual Bool SetSegmentsModified() = 0;
            /**
             * @brief Get a pointer to the mutable segment data, if available.
             * If the segment data storage was defined using a constant pointer, this method returns null.
             * @return A pointer to the mutable segment data, or null if the segments are immutable.
             */
            virtual UInt32* GetSegmentData() = 0;
            /**
             * @brief Get a pointer to the constant segment data.
             * @return A pointer to the segment data.
             */
            virtual const UInt32* GetSegmentData() const = 0;
            /**
             * @brief Get the actual number of segments used.
             * @return The actual number of segments.
             */
            virtual UInt32 GetNumberOfSegments() const = 0;
            /**
             * @brief Check if the segments are modified.
             * @return true if modified.
             */
            virtual Bool AreSegmentsModified() const = 0;

            /**
             * @brief Assign a mutable data storage defining actually active buffer segments.
             * The given data is an array of K UInt32 indices into the segment array defined
             * via SetSegmentData(). Each entry specifies a single active segment from that
             * array, which in turn references a sub-region of the source index data.
             * If present, the intermediate buffer described in SetSegmentData() is not 
             * filled with all present segments; instead, only those segments are considered
             * that are in the array given at this method.
             * @param segmentIndices An array of active segment indices.
             * @return true if successful.
             */
            virtual Bool SetActiveSegmentData(UInt32* segmentIndices) = 0;
            /**
             * @brief Assign a constant data storage defining actually active buffer segments.
             * See SetActiveSegmentData(UInt32*).
             * @param segmentIndices An array of active segment indices.
             * @return true if successful.
             */
            virtual Bool SetActiveSegmentData(const UInt32* segmentIndices) = 0;
            /**
             * @brief Set the actual number of segment indices used.
             * @param numberOfSegmentIndices The actual number of segment indices. This must
             *      be less or equal than the number of entries in the array defined via
             *      SetActiveSegmentData().
             * @return true if successful.
             */
            virtual Bool SetNumberOfActiveSegments(UInt32 numberOfSegmentIndices) = 0;
            /**
             * @brief Mark the active segments as modified.
             * @return true if successful.
             */
            virtual Bool SetActiveSegmentsModified() = 0;
            /**
             * @brief Get a pointer to the mutable active segment data, if available.
             * If the active segment data storage was defined using a constant pointer, this method 
             * returns null.
             * @return A pointer to the mutable active segment data, or null if the active segments
             *      are immutable.
             */
            virtual UInt32* GetActiveSegmentData() = 0;
            /**
             * @brief Get a pointer to the constant active segment data.
             * @return A pointer to the active segment data.
             */
            virtual const UInt32* GetActiveSegmentData() const = 0;
            /**
             * @brief Get the actual number of active segments used.
             * @return The actual number of active segments.
             */
            virtual UInt32 GetNumberOfActiveSegments() const = 0;
            /**
             * @brief Check if the active segments are modified.
             * @return true if modified.
             */
            virtual Bool AreActiveSegmentsModified() const = 0;

            /**
             * @brief Check if the actual buffer resides in video memory.
             * @return true if in video memory.
             */
            virtual Bool IsInVideoMemory() const = 0;
            
            /**
             * @brief Check if the buffer is actually containing any indices.
             * @return true if the buffer has data to draw.
             */
            virtual Bool HasDataToDraw() const = 0;
            
            /**
             * @brief Get the signature, obtained via IRenderer::AcquireIndexBufferSignature().
             * @return The buffer signature.
             */
            virtual UInt32 GetSignature() const = 0;
            
        protected:
            virtual ~IIndexBuffer() {}
        };
    }
}

#endif // __MURL_VIDEO_I_INDEX_BUFFER_H__
