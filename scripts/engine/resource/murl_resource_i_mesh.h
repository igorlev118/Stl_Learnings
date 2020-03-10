// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_RESOURCE_I_MESH_H__
#define __MURL_RESOURCE_I_MESH_H__

#include "murl_resource_types.h"
#include "murl_util_iff.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Resource
    {
        class IObject;

        /**
         * @ingroup MurlResourceObjectInterfaces
         * @interface IMesh
         * @brief The IMesh resource object interface.
         */
        class IMesh
        {
        public:
            /// IFF file specific structs
            struct Iff
            {
                /// IFF identifiers
                enum
                {
                    /// The four character code identifying a native resource as a mesh.
                    FOURCC = 'MESH',
                    /// The version of a native resource supported by the engine.
                    VERSION = '1.01'
                };

                /**
                 * @struct HeaderChunk
                 * @brief The IFF header chunk of a native mesh resource.
                 */
                struct HeaderChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as a HeaderChunk.
                        FOURCC = 'HEAD'
                    };

                    /// The actual resource version.
                    UInt32 mVersion;

                    /// The number of bones affecting the mesh.
                    UInt32 mNumberOfBones;

                    /// The minimum X value of the bounding box.
                    Float mBoundingBoxMinX;
                    /// The minimum Y value of the bounding box.
                    Float mBoundingBoxMinY;
                    /// The minimum Z value of the bounding box.
                    Float mBoundingBoxMinZ;

                    /// The maximum X value of the bounding box.
                    Float mBoundingBoxMaxX;
                    /// The maximum Y value of the bounding box.
                    Float mBoundingBoxMaxY;
                    /// The maximum Z value of the bounding box.
                    Float mBoundingBoxMaxZ;

                    /// The X coordinate of the bounding sphere center.
                    Float mBoundingSphereCenterX;
                    /// The Y coordinate of the bounding sphere center.
                    Float mBoundingSphereCenterY;
                    /// The Z coordinate of the bounding sphere center.
                    Float mBoundingSphereCenterZ;
                    /// The radius of the bounding sphere.
                    Float mBoundingSphereRadius;
                };

                /**
                 * @struct VertexBufferChunk
                 * @brief An IFF chunk containing a vertex buffer.
                 * A native mesh resource can contain multiple vertex buffers, which are grouped
                 * at run-time according to their slot and unit properties.
                 * When rendering a single geometry batch, all vertex buffers with the same slot
                 * are grouped, the actual combined vertex data is sourced from that group.
                 * All so-grouped buffers must contain an identical number of vertices.
                 * A specific vertex attribute may only be defined in at most one of the buffers
                 * in the group.
                 */
                struct VertexBufferChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as a VertexBufferChunk.
                        FOURCC = 'VBUF'
                    };

                    /// The global index of the vertex buffer.
                    UInt32 mBufferIndex;
                    /// The access mode, from the IEnums::BufferAccessMode enumeration.
                    UInt32 mBufferAccessMode;

                    /// The slot to bind this buffer to.
                    SInt32 mBufferSlot;
                    /// The unit to bind this buffer to.
                    UInt32 mBufferUnit;

                    /// The number of attribute components.
                    UInt32 mNumberOfComponents;
                    /// The number of actual vertices in the buffer.
                    UInt32 mNumberOfVertices;

                    /// The byte stride, i.e. the size of a single vertex entry in this buffer.
                    UInt32 mByteStride;

                    /// An offset into the chunk where the buffer data is stored. See IffOffset().
                    UInt32 mDataOffset;
                };

                /**
                 * @struct VertexAttributeChunk
                 * @brief An IFF chunk containing a single vertex attribute descriptor.
                 */
                struct VertexAttributeChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as a VertexAttributeChunk.
                        FOURCC = 'VATT'
                    };

                    /// The global index of the vertex buffer this attribute belongs to.
                    UInt32 mBufferIndex;

                    /// The vertex attribute item, from the IEnums::AttributeItem enumeration.
                    UInt32 mAttributeItem;
                    /// The vertex attribute type, from the IEnums::AttributeType enumeration.
                    UInt32 mAttributeType;

                    /// The byte offset into the referenced buffer's vertex data.
                    UInt32 mByteOffset;
                };

                /**
                 * @struct MorphBufferChunk
                 * @brief An IFF chunk containing morphing data for a given vertex buffer.
                 * For a single vertex buffer to be morphed, there can be any number of individual
                 * morph buffers identified by their mMorphBufferIndex.
                 */
                struct MorphBufferChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as a MorphBufferChunk.
                        FOURCC = 'MBUF'
                    };

                    /// The global index of the vertex buffer this morph buffer refers to.
                    UInt32 mVertexBufferIndex;
                    /// The local (wrt. the target vertex buffer) morph buffer index.
                    UInt32 mMorphBufferIndex;

                    /// The total number of vertices that get morphed.
                    UInt32 mNumberOfVertices;
                    /// The byte stride of the morph information block.
                    UInt32 mByteStride;
                    /// The type of indices, from the IEnums::IndexType enumeration.
                    UInt32 mIndexType;

                    /// An offset into the chunk where the vertex morph data is stored. See IffOffset().
                    UInt32 mVertexDataOffset;
                    /// An offset into the chunk where the affected vertex indices are stored. See IffOffset().
                    UInt32 mIndexDataOffset;
                };

                /**
                 * @struct MorphAttributeChunk
                 * @brief An IFF chunk containing a single morphed vertex attribute.
                 */
                struct MorphAttributeChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as a MorphAttributeChunk.
                        FOURCC = 'MATT'
                    };

                    /// The global index of the vertex buffer this attribute refers to.
                    UInt32 mVertexBufferIndex;
                    /// The local (wrt. the target vertex buffer) morph buffer index.
                    UInt32 mMorphBufferIndex;

                    /// The vertex attribute item, from the IEnums::AttributeItem enumeration.
                    UInt32 mAttributeItem;
                    /// The vertex attribute type, from the IEnums::AttributeType enumeration.
                    UInt32 mAttributeType;

                    /// The byte offset into the referenced buffer's vertex data.
                    UInt32 mByteOffset;
                };

                /**
                 * @struct IndexBufferChunk
                 * @brief An IFF chunk containing an index buffer.
                 * A native mesh resource can contain multiple index buffers, each of which
                 * specifies a single batch to be rendered. Each index buffer can specify
                 * a different set of property slots for material, parameters, textures
                 * and the actually used vertex buffer group.
                 */
                struct IndexBufferChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as an IndexBufferChunk.
                        FOURCC = 'IBUF'
                    };

                    /// The global index of the index buffer.
                    UInt32 mBufferIndex;
                    /// The access mode, from the IEnums::BufferAccessMode enumeration.
                    UInt32 mBufferAccessMode;

                    /// The slot from which vertex data is sourced.
                    SInt32 mVerticesSlot;
                    /// The material slot used for rendering.
                    SInt32 mMaterialSlot;
                    /// The parameters slot used for rendering.
                    SInt32 mParametersSlot;
                    /// The inidivdual texture slots used.
                    SInt32 mTextureSlot[IEnums::NUM_TEXTURE_UNITS];

                    /// The type of indices, from the IEnums::IndexType enumeration.
                    UInt32 mIndexType;
                    /// The primitive type, from the IEnums::PrimitiveType enumeration.
                    UInt32 mPrimitiveType;
                    /// The total number of indices in this buffer.
                    UInt32 mNumberOfIndices;

                    /// An offset into the chunk where the buffer data is stored. See IffOffset().
                    UInt32 mDataOffset;
                };

                /**
                 * @struct AdjacentIndicesChunk
                 * @brief An IFF chunk containing information about adjacent indices.
                 * An optional chunk of adjacent indices always refers to an existing index buffer,
                 * and contains exactly the same number of individual entries, stored as an UInt32
                 * array.
                 * Adjacency information is only supported for index buffers of type
                 * IEnums::PRIMITIVE_TYPE_TRIANGLES. Every three consecutive indices in the referenced
                 * index buffer define a single triangle, with edges 0-1, 1-2 and 2-0.
                 * The AdjacentIndicesChunk stores the position of the corresponding edge of the
                 * neighboring triangle within the index buffer, or 0xffffffff if no neighboring
                 * triangle exists.
                 */
                struct AdjacentIndicesChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as an AdjacentIndicesChunk.
                        FOURCC = 'ADJI'
                    };

                    /// The global index of the corresponding index buffer.
                    UInt32 mBufferIndex;

                    /// An offset into the chunk where the buffer data is stored. See IffOffset().
                    UInt32 mDataOffset;
                };

                /**
                 * @struct AdjacentVerticesChunk
                 * @brief An IFF chunk containing information about adjacent vertices.
                 * An optional chunk of adjacent vertices always refers to an existing index buffer,
                 * and contains exactly the same number of individual entries.
                 * Adjacency information is only supported for index buffers of type
                 * IEnums::PRIMITIVE_TYPE_TRIANGLES.
                 */
                struct AdjacentVerticesChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as an AdjacentVerticesChunk.
                        FOURCC = 'ADJV'
                    };

                    /// The global index of the corresponding index buffer.
                    UInt32 mBufferIndex;

                    /// An offset into the chunk where the buffer data is stored. See IffOffset().
                    UInt32 mDataOffset;
                };

                /**
                 * @struct IndexSegmentsChunk
                 * @brief An IFF chunk containing information about index buffer segments.
                 * An index buffer can be segmented to dynamically select pieces of that index
                 * buffer to render.
                 * The data pointed to by mDataOffset must be interpreted as a pointer to an
                 * array of Raw::IndexSegment structs, with the data size in bytes equalling
                 * mNumberOfSegments*sizeof(Raw::IndexSegment).
                 */
                struct IndexSegmentsChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as an IndexSegmentsChunk.
                        FOURCC = 'ISEG'
                    };

                    /// The global index of the corresponding index buffer.
                    UInt32 mBufferIndex;

                    /// The number of segment entries.
                    UInt32 mNumberOfSegments;
                    /// An offset into the chunk where the segment data is stored. See IffOffset().
                    UInt32 mDataOffset;
                };

                /**
                 * @struct CollisionSurfaceChunk
                 * @brief An IFF chunk containing information about a collision surface.
                 */
                struct CollisionSurfaceChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as a CollisionSurfaceChunk.
                        FOURCC = 'CSRF'
                    };

                    /// The global index of the surface.
                    UInt32 mSurfaceIndex;

                    /// The surface slot used when colliding.
                    SInt32 mSurfaceSlot;
                };

                /**
                 * @struct BspPlanesChunk
                 * @brief An IFF chunk containing information about BSP splitting planes.
                 * The data pointed to by mDataOffset must be interpreted as a pointer to an
                 * array of Raw::BspPlane structs, with the data size in bytes equalling
                 * mNumberOfPlanes*sizeof(Raw::BspPlane).
                 */
                struct BspPlanesChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as a BspPlanesChunk.
                        FOURCC = 'PPLN'
                    };

                    /// The number of plane entries.
                    UInt32 mNumberOfPlanes;
                    /// An offset into the chunk where the data is stored. See IffOffset().
                    UInt32 mDataOffset;
                };

                /**
                 * @struct BspNodesChunk
                 * @brief An IFF chunk containing information about BSP nodes.
                 * The data pointed to by mDataOffset must be interpreted as a pointer to an
                 * array of Raw::BspNode structs, with the data size in bytes equalling
                 * mNumberOfNodes*sizeof(Raw::BspNode).
                 */
                struct BspNodesChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as a BspNodesChunk.
                        FOURCC = 'PNOD'
                    };

                    /// The number of node entries.
                    UInt32 mNumberOfNodes;
                    /// An offset into the chunk where the data is stored. See IffOffset().
                    UInt32 mDataOffset;
                };

                /**
                 * @struct BspLeavesChunk
                 * @brief An IFF chunk containing information about BSP leaves.
                 * The data pointed to by mDataOffset must be interpreted as a pointer to an
                 * array of Raw::BspLeaf structs, with the data size in bytes equalling
                 * mNumberOfLeaves*sizeof(Raw::BspLeaf).
                 */
                struct BspLeavesChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as a BspLeavesChunk.
                        FOURCC = 'PLEA'
                    };

                    /// The number of leaf entries.
                    UInt32 mNumberOfLeaves;
                    /// An offset into the chunk where the data is stored. See IffOffset().
                    UInt32 mDataOffset;
                };

                /**
                 * @struct BspFacesChunk
                 * @brief An IFF chunk containing information about BSP faces.
                 * The data pointed to by mDataOffset must be interpreted as a pointer to an
                 * array of Raw::BspFace structs, with the data size in bytes equalling
                 * mNumberOfFaces*sizeof(Raw::BspFace).
                 */
                struct BspFacesChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as a BspFacesChunk.
                        FOURCC = 'PFAC'
                    };

                    /// The number of face entries.
                    UInt32 mNumberOfFaces;
                    /// An offset into the chunk where the data is stored. See IffOffset().
                    UInt32 mDataOffset;
                };

                /**
                 * @struct BspSegmentsChunk
                 * @brief An IFF chunk containing information about BSP segments.
                 * The data pointed to by mDataOffset must be interpreted as a pointer to an
                 * array of Raw::BspSegment structs, with the data size in bytes equalling
                 * mNumberOfSegments*sizeof(Raw::BspSegment).
                 */
                struct BspSegmentsChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as a BspSegmentsChunk.
                        FOURCC = 'PSGM'
                    };

                    /// The number of segment entries.
                    UInt32 mNumberOfSegments;
                    /// An offset into the chunk where the data is stored. See IffOffset().
                    UInt32 mDataOffset;
                };

                /**
                 * @struct BspPvsChunk
                 * @brief An IFF chunk containing the "potentially visible set" BSP information.
                 */
                struct BspPvsChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as a BspPvsChunk.
                        FOURCC = 'PVIS'
                    };

                    /// The number of PVS vectors.
                    UInt32 mNumberOfVectors;
                    /// The common size in bytes for each vector.
                    UInt32 mVectorByteSize;

                    /// An offset into the chunk where the data is stored. See IffOffset().
                    UInt32 mDataOffset;
                };

                /**
                 * @struct BoundingNodesChunk
                 * @brief An IFF chunk containing information about bounding volume hierarchy nodes.
                 * The data pointed to by mDataOffset must be interpreted as a pointer to an
                 * array of Raw::BoundingNode structs, with the data size in bytes equalling
                 * mNumberOfNodes*sizeof(Raw::BoundingNode).
                 */
                struct BoundingNodesChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as a BoundingNodesChunk.
                        FOURCC = 'BNOD'
                    };

                    /// The number of bounding volume hierarchy nodes.
                    UInt32 mNumberOfNodes;
                    /// An offset into the chunk where the data is stored. See IffOffset().
                    UInt32 mDataOffset;
                };

                /**
                 * @struct BoundingLeavesChunk
                 * @brief An IFF chunk containing information about bounding volume hierarchy leaves.
                 * The data pointed to by mDataOffset must be interpreted as a pointer to an
                 * array of Raw::BoundingLeaf structs, with the data size in bytes equalling
                 * mNumberOfLeaves*sizeof(Raw::BoundingLeaf).
                 */
                struct BoundingLeavesChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as a BoundingLeavesChunk.
                        FOURCC = 'BLEA'
                    };

                    /// The number of bounding volume hierarchy leaves.
                    UInt32 mNumberOfLeaves;
                    /// An offset into the chunk where the data is stored. See IffOffset().
                    UInt32 mDataOffset;
                };

                /**
                 * @struct BoundingVerticesChunk
                 * @brief An IFF chunk containing information about bounding volume hierarchy vertices.
                 * The data pointed to by mDataOffset must be interpreted as a pointer to an
                 * array of Raw::BoundingVertex structs, with the data size in bytes equalling
                 * mNumberOfVertices*sizeof(Raw::BoundingVertex).
                 */
                struct BoundingVerticesChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as a BoundingVerticesChunk.
                        FOURCC = 'BVRT'
                    };

                    /// The number of bounding volume hierarchy vertices.
                    UInt32 mNumberOfVertices;
                    /// An offset into the chunk where the data is stored. See IffOffset().
                    UInt32 mDataOffset;
                };
            };

            /// Raw data structs
            struct Raw
            {
                /**
                 * @struct IndexSegment
                 * @brief A single index buffer segment.
                 */
                struct IndexSegment
                {
                    /// The number of indices for this segment.
                    UInt32 mNumberOfIndices;
                    /// The first index into the index buffer representing this segment.
                    UInt32 mFirstIndex;
                };

                /**
                 * @struct BspPlane
                 * @brief A BSP splitting plane.
                 */
                struct BspPlane
                {
                    /// The X component of the plane's normal vector.
                    Float mNormalX;
                    /// The Y component of the plane's normal vector.
                    Float mNormalY;
                    /// The Z component of the plane's normal vector.
                    Float mNormalZ;
                    /// The normal distance of the plane from the origin.
                    Float mDistance;
                };

                /**
                 * @struct BspNode
                 * @brief A BSP node.
                 * The left and right child indices define the respective child node or leaf
                 * in the hierarchy for this node. If such an index is greater or equal than 0,
                 * the index represents the index of a BspNode, otherwise the index is bit-wise
                 * inverted and then represents the index of a BspLeaf.
                 */
                struct BspNode
                {
                    /// The zero-based index of the BspPlane that splits this node.
                    SInt32 mPlaneIndex;
                    /// The index of the left child.
                    SInt32 mLeftChildIndex;
                    /// The index of the right child.
                    SInt32 mRightChildIndex;

                    /// The minimum X coordinate of the node's axis-aligned bounding box.
                    Float mBoundingBoxMinX;
                    /// The minimum Y coordinate of the node's axis-aligned bounding box.
                    Float mBoundingBoxMinY;
                    /// The minimum Z coordinate of the node's axis-aligned bounding box.
                    Float mBoundingBoxMinZ;

                    /// The maximum X coordinate of the node's axis-aligned bounding box.
                    Float mBoundingBoxMaxX;
                    /// The maximum Y coordinate of the node's axis-aligned bounding box.
                    Float mBoundingBoxMaxY;
                    /// The maximum Z coordinate of the node's axis-aligned bounding box.
                    Float mBoundingBoxMaxZ;

                    /// The X coordinate of the node's bounding sphere.
                    Float mBoundingSphereCenterX;
                    /// The Y coordinate of the node's bounding sphere.
                    Float mBoundingSphereCenterY;
                    /// The Z coordinate of the node's bounding sphere.
                    Float mBoundingSphereCenterZ;
                    /// The radius of the node's bounding sphere.
                    Float mBoundingSphereRadius;
                };

                /**
                 * @struct BspLeaf
                 * @brief A BSP leaf.
                 */
                struct BspLeaf
                {
                    /// The cluster index this leaf belongs to, used for PVS visibility determination.
                    SInt32 mClusterIndex;

                    /// The zero-based index of the first BspFace belonging to this leaf.
                    SInt32 mFirstFaceIndex;
                    /// The number of faces belonging to this leaf.
                    SInt32 mNumFaces;

                    /// The minimum X coordinate of the leaf's axis-aligned bounding box.
                    Float mBoundingBoxMinX;
                    /// The minimum Y coordinate of the leaf's axis-aligned bounding box.
                    Float mBoundingBoxMinY;
                    /// The minimum Z coordinate of the leaf's axis-aligned bounding box.
                    Float mBoundingBoxMinZ;

                    /// The maximum X coordinate of the leaf's axis-aligned bounding box.
                    Float mBoundingBoxMaxX;
                    /// The maximum Y coordinate of the leaf's axis-aligned bounding box.
                    Float mBoundingBoxMaxY;
                    /// The maximum Z coordinate of the leaf's axis-aligned bounding box.
                    Float mBoundingBoxMaxZ;

                    /// The X coordinate of the leaf's bounding sphere.
                    Float mBoundingSphereCenterX;
                    /// The Y coordinate of the leaf's bounding sphere.
                    Float mBoundingSphereCenterY;
                    /// The Z coordinate of the leaf's bounding sphere.
                    Float mBoundingSphereCenterZ;
                    /// The radius of the leaf's bounding sphere.
                    Float mBoundingSphereRadius;
                };

                /**
                 * @struct BspFace
                 * @brief A BSP face.
                 */
                struct BspFace
                {
                    /// The zero-based index of the BspSegment for this face.
                    SInt32 mSegmentIndex;
                };

                /**
                 * @struct BspSegment
                 * @brief A BSP index buffer segment.
                 */
                struct BspSegment
                {
                    /// The global index of the index buffer containing the segment.
                    UInt32 mBufferIndex;
                    /// The zero-based index into that buffer's IndexSegment array.
                    UInt32 mSegmentIndex;
                };

                /**
                 * @struct BoundingNode
                 * @brief A bounding volume hierarchy node.
                 * The left and right child indices define the respective child node or leaf
                 * in the hierarchy for this node. If such an index is greater or equal than 0,
                 * the index represents the index of a BoundingNode, otherwise the index is 
                 * bit-wise inverted and then represents the index of a BoundingLeaf.
                 */
                struct BoundingNode
                {
                    /// The index of the left child.
                    SInt32 mLeftChildIndex;
                    /// The index of the right child.
                    SInt32 mRightChildIndex;

                    /// The X coordinate of the node's bounding sphere.
                    Float mBoundingSphereCenterX;
                    /// The Y coordinate of the node's bounding sphere.
                    Float mBoundingSphereCenterY;
                    /// The Z coordinate of the node's bounding sphere.
                    Float mBoundingSphereCenterZ;
                    /// The W coordinate of the node's bounding sphere.
                    Float mBoundingSphereCenterW;
                    /// The radius of the node's bounding sphere.
                    Float mBoundingSphereRadius;
                };

                /**
                 * @struct BoundingLeaf
                 * @brief A bounding volume hierarchy leaf.
                 */
                struct BoundingLeaf
                {
                    /// The X component of the leaf triangle's face normal.
                    Float mFaceNormalX;
                    /// The Y component of the leaf triangle's face normal.
                    Float mFaceNormalY;
                    /// The Z component of the leaf triangle's face normal.
                    Float mFaceNormalZ;

                    /// The leaf's triangle index.
                    UInt32 mTriangleIndex;
                    /// The index into the array of collision surfaces (see Iff::CollisionSurfaceChunk).
                    UInt32 mSurfaceIndex;

                    /// The zero-based index of the first BoundingVertex of the triangle.
                    SInt32 mVertexIndex0;
                    /// The zero-based index of the second BoundingVertex of the triangle.
                    SInt32 mVertexIndex1;
                    /// The zero-based index of the third BoundingVertex of the triangle.
                    SInt32 mVertexIndex2;

                    /// The index of the triangle adjacent to the first edge (0-1).
                    SInt32 mAdjacentTriangleIndex0;
                    /// The index of the triangle adjacent to the second edge (1-2).
                    SInt32 mAdjacentTriangleIndex1;
                    /// The index of the triangle adjacent to the third edge (2-0).
                    SInt32 mAdjacentTriangleIndex2;

                    /// Used to calculate barycentric coordinates u, v, w
                    Float mUConstant1;
                    /// Used to calculate barycentric coordinates u, v, w
                    Float mUConstant2;

                    /// Used to calculate barycentric coordinates u, v, w
                    Float mVConstant1;
                    /// Used to calculate barycentric coordinates u, v, w
                    Float mVConstant2;

                    /// Used to calculate barycentric coordinates u, v, w
                    UInt32 mDominantAxis;

                    /// The X coordinate of the node's bounding sphere.
                    Float mBoundingSphereCenterX;
                    /// The Y coordinate of the node's bounding sphere.
                    Float mBoundingSphereCenterY;
                    /// The Z coordinate of the node's bounding sphere.
                    Float mBoundingSphereCenterZ;
                    /// The W coordinate of the node's bounding sphere.
                    Float mBoundingSphereCenterW;
                    /// The radius of the node's bounding sphere.
                    Float mBoundingSphereRadius;
                };

                /**
                 * @struct BoundingVertex
                 * @brief A triangle vertex from the bounding volume hierarchy.
                 */
                struct BoundingVertex
                {
                    /// The X coordinate of the vertex.
                    Float mPositionX;
                    /// The Y coordinate of the vertex.
                    Float mPositionY;
                    /// The Z coordinate of the vertex.
                    Float mPositionZ;
                    /// The W coordinate of the vertex.
                    Float mPositionW;

                    /// The X (U) texture coordinate of the vertex.
                    Float mTexCoordX;
                    /// The Y (V) texture coordinate of the vertex.
                    Float mTexCoordY;
                };
            };

            /**
             * @brief Get the mutable Resource::IObject interface.
             * @return The IObject interface.
             */
            virtual IObject* GetObjectInterface() = 0;
            /**
             * @brief Get the constant Resource::IObject interface.
             * @return The IObject interface.
             */
            virtual const IObject* GetObjectInterface() const = 0;

            /**
             * @brief Get the number of bones affecting this mesh.
             * @return The number of bones.
             */
            virtual UInt32 GetNumberOfBones() const = 0;

            /**
             * @brief Get the minimum vector of the axis-aligned bounding box.
             * @return The AABB minimum vector.
             */
            virtual const Vector& GetBoundingBoxMin() const = 0;
            /**
             * @brief Get the maximum vector of the axis-aligned bounding box.
             * @return The AABB maximum vector.
             */
            virtual const Vector& GetBoundingBoxMax() const = 0;

            /**
             * @brief Get the total number of vertex buffers present.
             * @return The number of vertex buffers present.
             */
            virtual UInt32 GetNumberOfVertexBuffers() const = 0;
            /**
             * @brief Get the number of vertices stored in the vertex buffer at a given index.
             * @param vertexBufferIndex The index of the vertex buffer, from 0 to GetNumberOfVertexBuffers()-1.
             * @return The number of vertices.
             */
            virtual UInt32 GetNumberOfVertexBufferVertices(UInt32 vertexBufferIndex) const = 0;
            /**
             * @brief Get the number of attributes defined for the vertex buffer at a given index.
             * @param vertexBufferIndex The index of the vertex buffer, from 0 to GetNumberOfVertexBuffers()-1.
             * @return The number of attributes.
             */
            virtual UInt32 GetNumberOfVertexBufferAttributes(UInt32 vertexBufferIndex) const = 0;
            /**
             * @brief Get the raw buffer data of the vertex buffer at a given index.
             * @param vertexBufferIndex The index of the vertex buffer, from 0 to GetNumberOfVertexBuffers()-1.
             * @return A pointer to the raw data, or null if index is out of range.
             */
            virtual const void* GetVertexBufferData(UInt32 vertexBufferIndex) const = 0;
            /**
             * @brief Get the access mode of the vertex buffer at a given index.
             * @param vertexBufferIndex The index of the vertex buffer, from 0 to GetNumberOfVertexBuffers()-1.
             * @return The buffer access mode.
             */
            virtual IEnums::BufferAccessMode GetVertexBufferAccessMode(UInt32 vertexBufferIndex) const = 0;
            /**
             * @brief Get the byte stride of the vertex buffer at a given index.
             * @param vertexBufferIndex The index of the vertex buffer, from 0 to GetNumberOfVertexBuffers()-1.
             * @return The byte stride.
             */
            virtual UInt32 GetVertexBufferByteStride(UInt32 vertexBufferIndex) const = 0;
            /**
             * @brief Get the predefined item of a vertex buffer attribute.
             * @param vertexBufferIndex The index of the vertex buffer, from 0 to GetNumberOfVertexBuffers()-1.
             * @param attributeIndex The index of the attribute, from 0 to GetNumberOfVertexBufferAttributes()-1.
             * @return The attribute item.
             */
            virtual IEnums::AttributeItem GetVertexBufferAttributeItem(UInt32 vertexBufferIndex, UInt32 attributeIndex) const = 0;
            /**
             * @brief Get the data type of a vertex buffer attribute.
             * @param vertexBufferIndex The index of the vertex buffer, from 0 to GetNumberOfVertexBuffers()-1.
             * @param attributeIndex The index of the attribute, from 0 to GetNumberOfVertexBufferAttributes()-1.
             * @return The attribute type.
             */
            virtual IEnums::AttributeType GetVertexBufferAttributeType(UInt32 vertexBufferIndex, UInt32 attributeIndex) const = 0;
            /**
             * @brief Get the byte offset of a vertex buffer attribute.
             * @param vertexBufferIndex The index of the vertex buffer, from 0 to GetNumberOfVertexBuffers()-1.
             * @param attributeIndex The index of the attribute, from 0 to GetNumberOfVertexBufferAttributes()-1.
             * @return The byte offset.
             */
            virtual UInt32 GetVertexBufferAttributeByteOffset(UInt32 vertexBufferIndex, UInt32 attributeIndex) const = 0;
            /**
             * @brief Get the slot index to which a vertex buffer gets assigned.
             * @param vertexBufferIndex The index of the vertex buffer, from 0 to GetNumberOfVertexBuffers()-1.
             * @return The slot index.
             */
            virtual SInt32 GetVertexBufferSlot(UInt32 vertexBufferIndex) const = 0;
            /**
             * @brief Get the unit index to which a vertex buffer gets assigned.
             * @param vertexBufferIndex The index of the vertex buffer, from 0 to GetNumberOfVertexBuffers()-1.
             * @return The unit index.
             */
            virtual UInt32 GetVertexBufferUnit(UInt32 vertexBufferIndex) const = 0;

            /**
             * @brief Get the total number of index buffers present.
             * @return The number of index buffers present.
             */
            virtual UInt32 GetNumberOfIndexBuffers() const = 0;
            /**
             * @brief Get the number of indices stored in the index buffer at a given index.
             * @param indexBufferIndex The index of the index buffer, from 0 to GetNumberOfIndexBuffers()-1.
             * @return The number of indices.
             */
            virtual UInt32 GetNumberOfIndexBufferIndices(UInt32 indexBufferIndex) const = 0;
            /**
             * @brief Get the number of segments stored in the index buffer at a given index.
             * @param indexBufferIndex The index of the index buffer, from 0 to GetNumberOfIndexBuffers()-1.
             * @return The number of segments.
             */
            virtual UInt32 GetNumberOfIndexBufferSegments(UInt32 indexBufferIndex) const = 0;
            /**
             * @brief Get the raw buffer data of the index buffer at a given index.
             * @param indexBufferIndex The index of the index buffer, from 0 to GetNumberOfIndexBuffers()-1.
             * @return A pointer to the raw data, or null if index is out of range.
             */
            virtual const void* GetIndexBufferData(UInt32 indexBufferIndex) const = 0;
            /**
             * @brief Get the raw adjacent vertex data of the index buffer at a given index.
             * @param indexBufferIndex The index of the index buffer, from 0 to GetNumberOfIndexBuffers()-1.
             * @return A pointer to the raw data, or null if index is out of range.
             */
            virtual const void* GetIndexBufferAdjacentVertices(UInt32 indexBufferIndex) const = 0;
            /**
             * @brief Get the raw adjacent index data of the index buffer at a given index.
             * @param indexBufferIndex The index of the index buffer, from 0 to GetNumberOfIndexBuffers()-1.
             * @return A pointer to the raw data, or null if index is out of range.
             */
            virtual const UInt32* GetIndexBufferAdjacentIndices(UInt32 indexBufferIndex) const = 0;
            /**
             * @brief Get the raw segment data of the index buffer at a given index.
             * @param indexBufferIndex The index of the index buffer, from 0 to GetNumberOfIndexBuffers()-1.
             * @return A pointer to the raw data, or null if index is out of range.
             */
            virtual const UInt32* GetIndexBufferSegments(UInt32 indexBufferIndex) const = 0;
            /**
             * @brief Get the access mode of the index buffer at a given index.
             * @param indexBufferIndex The index of the index buffer, from 0 to GetNumberOfIndexBuffers()-1.
             * @return The buffer access mode.
             */
            virtual IEnums::BufferAccessMode GetIndexBufferAccessMode(UInt32 indexBufferIndex) const = 0;
            /**
             * @brief Get the data type of the index buffer at a given index.
             * @param indexBufferIndex The index of the index buffer, from 0 to GetNumberOfIndexBuffers()-1.
             * @return The data type.
             */
            virtual IEnums::IndexType GetIndexBufferIndexType(UInt32 indexBufferIndex) const = 0;
            /**
             * @brief Get the primitive type of the index buffer at a given index.
             * @param indexBufferIndex The index of the index buffer, from 0 to GetNumberOfIndexBuffers()-1.
             * @return The primitive type.
             */
            virtual IEnums::PrimitiveType GetIndexBufferPrimitiveType(UInt32 indexBufferIndex) const = 0;
            /**
             * @brief Get the slot of vertices used to render the index buffer at a given index.
             * @param indexBufferIndex The index of the index buffer, from 0 to GetNumberOfIndexBuffers()-1.
             * @return The vertices' slot.
             */
            virtual SInt32 GetIndexBufferVerticesSlot(UInt32 indexBufferIndex) const = 0;
            /**
             * @brief Get the slot index for the material used to render the index buffer at a given index.
             * @param indexBufferIndex The index of the index buffer, from 0 to GetNumberOfIndexBuffers()-1.
             * @return The material slot.
             */
            virtual SInt32 GetIndexBufferMaterialSlot(UInt32 indexBufferIndex) const = 0;
            /**
             * @brief Get the slot index for the parameters used to render the index buffer at a given index.
             * @param indexBufferIndex The index of the index buffer, from 0 to GetNumberOfIndexBuffers()-1.
             * @return The parameters slot.
             */
            virtual SInt32 GetIndexBufferParametersSlot(UInt32 indexBufferIndex) const = 0;
            /**
             * @brief Get the slot index for the texture at a given unit used to render the index buffer at a given index.
             * @param indexBufferIndex The index of the index buffer, from 0 to GetNumberOfIndexBuffers()-1.
             * @param unit The texture unit, in the range from 0 to IEnums::NUM_TEXTURE_UNITS.
             * @return The texture slot.
             */
            virtual SInt32 GetIndexBufferTextureSlot(UInt32 indexBufferIndex, UInt32 unit) const = 0;

            /**
             * @brief Get the total number of morph buffers present for a given vertex buffer.
             * @param vertexBufferIndex The index of the vertex buffer, from 0 to GetNumberOfVertexBuffers()-1.
             * @return The number of morph buffers present.
             */
            virtual UInt32 GetNumberOfMorphBuffers(UInt32 vertexBufferIndex) const = 0;
            /**
             * @brief Get the number of morphed vertices for a given vertex and morph buffer.
             * @param vertexBufferIndex The index of the vertex buffer, from 0 to GetNumberOfVertexBuffers()-1.
             * @param morphBufferIndex The index of the morph buffer, from 0 to GetNumberOfMorphBuffers()-1.
             * @return The number of morphed vertices.
             */
            virtual UInt32 GetNumberOfMorphBufferVertices(UInt32 vertexBufferIndex, UInt32 morphBufferIndex) const = 0;
            /**
             * @brief Get the number of morphed attributes for a given vertex and morph buffer.
             * @param vertexBufferIndex The index of the vertex buffer, from 0 to GetNumberOfVertexBuffers()-1.
             * @param morphBufferIndex The index of the morph buffer, from 0 to GetNumberOfMorphBuffers()-1.
             * @return The number of morphed attributes.
             */
            virtual UInt32 GetNumberOfMorphBufferAttributes(UInt32 vertexBufferIndex, UInt32 morphBufferIndex) const = 0;
            /**
             * @brief Get the raw vertex morph data for a given vertex and morph buffer.
             * @param vertexBufferIndex The index of the vertex buffer, from 0 to GetNumberOfVertexBuffers()-1.
             * @param morphBufferIndex The index of the morph buffer, from 0 to GetNumberOfMorphBuffers()-1.
             * @return A pointer to the raw data, or null if an index is out of range.
             */
            virtual const void* GetMorphBufferVertexData(UInt32 vertexBufferIndex, UInt32 morphBufferIndex) const = 0;
            /**
             * @brief Get the raw index morph data for a given vertex and morph buffer.
             * @param vertexBufferIndex The index of the vertex buffer, from 0 to GetNumberOfVertexBuffers()-1.
             * @param morphBufferIndex The index of the morph buffer, from 0 to GetNumberOfMorphBuffers()-1.
             * @return A pointer to the raw data, or null if an index is out of range.
             */
            virtual const void* GetMorphBufferIndexData(UInt32 vertexBufferIndex, UInt32 morphBufferIndex) const = 0;
            /**
             * @brief Get the byte stride for a given vertex and morph buffer.
             * @param vertexBufferIndex The index of the vertex buffer, from 0 to GetNumberOfVertexBuffers()-1.
             * @param morphBufferIndex The index of the morph buffer, from 0 to GetNumberOfMorphBuffers()-1.
             * @return The byte stride.
             */
            virtual UInt32 GetMorphBufferByteStride(UInt32 vertexBufferIndex, UInt32 morphBufferIndex) const = 0;
            /**
             * @brief Get the predefined morph attribute item for a given vertex and morph buffer.
             * @param vertexBufferIndex The index of the vertex buffer, from 0 to GetNumberOfVertexBuffers()-1.
             * @param morphBufferIndex The index of the morph buffer, from 0 to GetNumberOfMorphBuffers()-1.
             * @param attributeIndex The index of the attribute, from 0 to GetNumberOfMorphBufferAttributes()-1.
             * @return The attribute item.
             */
            virtual IEnums::AttributeItem GetMorphBufferAttributeItem(UInt32 vertexBufferIndex, UInt32 morphBufferIndex, UInt32 attributeIndex) const = 0;
            /**
             * @brief Get the morph attribute data type for a given vertex and morph buffer.
             * @param vertexBufferIndex The index of the vertex buffer, from 0 to GetNumberOfVertexBuffers()-1.
             * @param morphBufferIndex The index of the morph buffer, from 0 to GetNumberOfMorphBuffers()-1.
             * @param attributeIndex The index of the attribute, from 0 to GetNumberOfMorphBufferAttributes()-1.
             * @return The attribute type.
             */
            virtual IEnums::AttributeType GetMorphBufferAttributeType(UInt32 vertexBufferIndex, UInt32 morphBufferIndex, UInt32 attributeIndex) const = 0;
            /**
             * @brief Get the morph attribute byte offset for a given vertex and morph buffer.
             * @param vertexBufferIndex The index of the vertex buffer, from 0 to GetNumberOfVertexBuffers()-1.
             * @param morphBufferIndex The index of the morph buffer, from 0 to GetNumberOfMorphBuffers()-1.
             * @param attributeIndex The index of the attribute, from 0 to GetNumberOfMorphBufferAttributes()-1.
             * @return The byte offset.
             */
            virtual UInt32 GetMorphBufferAttributeByteOffset(UInt32 vertexBufferIndex, UInt32 morphBufferIndex, UInt32 attributeIndex) const = 0;
            /**
             * @brief Get the index data type for a given vertex and morph buffer.
             * @param vertexBufferIndex The index of the vertex buffer, from 0 to GetNumberOfVertexBuffers()-1.
             * @param morphBufferIndex The index of the morph buffer, from 0 to GetNumberOfMorphBuffers()-1.
             * @return The data type.
             */
            virtual IEnums::IndexType GetMorphBufferIndexType(UInt32 vertexBufferIndex, UInt32 morphBufferIndex) const = 0;

            /**
             * @brief Get the total number of collision surfaces present.
             * @return The number of collision surfaces.
             */
            virtual UInt32 GetNumberOfCollisionSurfaces() const = 0;
            /**
             * @brief Get the surface slot used for a given collision surface.
             * @param surfaceIndex The index of the surface, from 0 to GetNumberOfCollisionSurfaces()-1.
             * @return The surface slot.
             */
            virtual SInt32 GetCollisionSurfaceSlot(UInt32 surfaceIndex) const = 0;

            /**
             * @brief Get the number of BSP splitting planes present.
             * @return The number of planes.
             */
            virtual UInt32 GetNumberOfBspPlanes() const = 0;
            /**
             * @brief Get the number of BSP nodes present.
             * @return The number of nodes.
             */
            virtual UInt32 GetNumberOfBspNodes() const = 0;
            /**
             * @brief Get the number of BSP leaves present.
             * @return The number of leaves.
             */
            virtual UInt32 GetNumberOfBspLeaves() const = 0;
            /**
             * @brief Get the number of BSP faces present.
             * @return The number of faces.
             */
            virtual UInt32 GetNumberOfBspFaces() const = 0;
            /**
             * @brief Get the number of BSP segments present.
             * @return The number of segments.
             */
            virtual UInt32 GetNumberOfBspSegments() const = 0;
            /**
             * @brief Get the number of BSP clusters present.
             * @return The number of clusters.
             */
            virtual UInt32 GetNumberOfBspClusters() const = 0;
            /**
             * @brief Get the byte size of a BSP cluster.
             * @return The byte size.
             */
            virtual UInt32 GetBspClustersByteSize() const = 0;
            
            /**
             * @brief Get the raw BSP splitting plane data.
             * @return A pointer to the raw data, or null if not present.
             */
            virtual const Raw::BspPlane* GetBspPlanes() const = 0;
            /**
             * @brief Get the raw BSP node data.
             * @return A pointer to the raw data, or null if not present.
             */
            virtual const Raw::BspNode* GetBspNodes() const = 0;
            /**
             * @brief Get the raw BSP leaf data.
             * @return A pointer to the raw data, or null if not present.
             */
            virtual const Raw::BspLeaf* GetBspLeaves() const = 0;
            /**
             * @brief Get the raw BSP face data.
             * @return A pointer to the raw data, or null if not present.
             */
            virtual const Raw::BspFace* GetBspFaces() const = 0;
            /**
             * @brief Get the raw BSP segment data.
             * @return A pointer to the raw data, or null if not present.
             */
            virtual const Raw::BspSegment* GetBspSegments() const = 0;
            /**
             * @brief Get the raw BSP cluster data.
             * @return A pointer to the raw data, or null if not present.
             */
            virtual const UInt8* GetBspClusters() const = 0;
            
            /**
             * @brief Get the number of bounding volume hierarchy nodes present.
             * @return The number of nodes.
             */
            virtual UInt32 GetNumberOfBoundingNodes() const = 0;
            /**
             * @brief Get the number of bounding volume hierarchy leaves present.
             * @return The number of leaves.
             */
            virtual UInt32 GetNumberOfBoundingLeaves() const = 0;
            /**
             * @brief Get the number of bounding volume hierarchy vertices present.
             * @return The number of vertices.
             */
            virtual UInt32 GetNumberOfBoundingVertices() const = 0;
            /**
             * @brief Get the total byte size of the bounding volume hierarchy vertices.
             * @return The byte size.
             */
            virtual UInt32 GetBoundingVerticesByteSize() const = 0;
            
            /**
             * @brief Get the raw bounding volume hierarchy node data.
             * @return A pointer to the raw data, or null if not present.
             */
            virtual const Raw::BoundingNode* GetBoundingNodes() const = 0;
            /**
             * @brief Get the raw bounding volume hierarchy leaf data.
             * @return A pointer to the raw data, or null if not present.
             */
            virtual const Raw::BoundingLeaf* GetBoundingLeaves() const = 0;
            /**
             * @brief Get the raw bounding volume hierarchy vertex data.
             * @return A pointer to the raw data, or null if not present.
             */
            virtual const Raw::BoundingVertex* GetBoundingVertices() const = 0;
            
        protected:
            virtual ~IMesh() {}
        };
    }
}

#endif  // __MURL_RESOURCE_I_MESH_H__
