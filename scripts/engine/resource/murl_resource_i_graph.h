// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_RESOURCE_I_GRAPH_H__
#define __MURL_RESOURCE_I_GRAPH_H__

#include "murl_util_iff.h"

namespace Murl
{
    class IAttributes;

    namespace Resource
    {
        class IGraphNode;
        class IObject;

        /**
         * @ingroup MurlResourceObjectInterfaces
         * @interface IGraph
         * @brief The IGraph resource object interface.
         * A graph resource stores template information for creating actual (sub-)graph instances
         * in the engine's master scene graph.
         */
        class IGraph
        {
        public:
            /// IFF file specific structs
            struct Iff
            {
                /// IFF identifiers
                enum
                {
                    /// The four character code identifying a native resource as a graph.
                    FOURCC = 'GRPH',
                    /// The version of a native resource supported by the engine.
                    VERSION = '1.00'
                };

                /**
                 * @struct HeaderChunk
                 * @brief The IFF header chunk of a native graph resource.
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

                    /// The total number of individual nodes in the graph resource.
                    UInt32 mNumberOfNodes;
                    /// The index of the root node.
                    UInt32 mRootNodeIndex;
                };

                /**
                 * @struct StringsChunk
                 * @brief An IFF chunk of a native graph resource storing the string table.
                 * The data block pointed to by mStringsOffset contains all C strings defined in
                 * this graph resource (null-terminated), one directly after the other.
                 * The data block pointed to by mIndicesOffset contains an array of N UInt32 
                 * values, each defining a byte offset into the above string memory block for
                 * each of the N strings present.
                 */
                struct StringsChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as a StringsChunk.
                        FOURCC = 'STRG'
                    };

                    /// An offset into the chunk where where the string offsets are stored. See IffOffset().
                    UInt32 mIndicesOffset;
                    /// An offset into the chunk where where the actual string data is stored. See IffOffset().
                    UInt32 mStringsOffset;
                };

                /**
                 * @struct AttributesChunk
                 * @brief An IFF chunk of a native graph resource storing multiple node attributes.
                 * The data pointed to by mAttributesOffset must be interpreted as a pointer to
                 * an array of Raw::Attribute structs.
                 */
                struct AttributesChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as an AttributesChunk.
                        FOURCC = 'ATTR'
                    };

                    /// An offset into the chunk where where the Raw::Attribute array is stored. See IffOffset().
                    UInt32 mAttributesOffset;
                };

                /**
                 * @struct NodesChunk
                 * @brief An IFF chunk of a native graph resource storing multiple node descriptors.
                 * The data pointed to by mNodesOffset must be interpreted as a pointer to
                 * an array of Raw::Node structs.
                 */
                struct NodesChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as a NodesChunk.
                        FOURCC = 'NODE'
                    };

                    /// An offset into the chunk where where the Raw::Node array is stored. See IffOffset().
                    UInt32 mNodesOffset;
                };

            };

            /// Raw data structs
            struct Raw
            {
                /**
                 * @struct Attribute
                 * @brief A single node attribute.
                 */
                struct Attribute
                {
                    /// The attribute level.
                    UInt32 mLevel;
                    /// The 32bit attribute name hash.
                    UInt32 mNameHash;

                    /// The index of the parent attribute.
                    UInt32 mParentAttributeIndex;
                    /// The index into the string table where the attribute name is stored.
                    UInt32 mNameStringIndex;
                    /// The index into the string table where the attribute value is stored.
                    SInt32 mValueStringIndex;
                };

                /**
                 * @struct Node
                 * @brief A single node descriptor.
                 */
                struct Node
                {
                    /// The index into the string table where the class name for the node is stored.
                    UInt32 mClassIdIndex;

                    /// The number of node attributes.
                    UInt32 mNumberOfAttributes;
                    /// The index of the first attribute in the attribute table.
                    UInt32 mAttributesIndex;
                    
                    /// The number of child nodes.
                    UInt32 mNumberOfChildren;
                    /// The index of the first child in the node table.
                    UInt32 mChildrenIndex;
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
             * @brief Get the root node to create an instance from.
             * @return The root node.
             */
            virtual const IGraphNode* GetRootNode() const = 0;
            /**
             * @brief Get the default node parameters.
             * @return The default parameters.
             */
            virtual const IAttributes* GetDefaultParameters() const = 0;
            
        protected:
            virtual ~IGraph() {}
        };
    }
}

#endif  // __MURL_RESOURCE_I_GRAPH_H__
