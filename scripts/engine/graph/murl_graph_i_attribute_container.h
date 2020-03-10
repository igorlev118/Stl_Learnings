// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_ATTRIBUTE_CONTAINER_H__
#define __MURL_GRAPH_I_ATTRIBUTE_CONTAINER_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_graph_i_attribute.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphPropertyInterfaces
         * @interface IAttributeContainer
         * @brief The IAttributeContainer property interface.
         * This interface provides a common way to store and retrieve individual vertex attributes
         * of different types, usually found in nodes implementing e.g. the Graph::IVertexBuffer
         * interface.
         */
        class IAttributeContainer
        {
        public:
            /**
             * @brief Add a predefined vertex attribute.
             * This method adds a predefined vertex attribute to the container, with a
             * given attribute type and a given byte offset relative to each vertex entry's
             * start pointer. As a convenience, the byte offset variable is incremented by the
             * actual number of bytes used by the given attribute type, e.g. 12 for a
             * 3-component vector of floats. If successful, this method returns the zero-based
             * index of the newly created attribute in the container; if failed, -1 is returned.
             * @param item The predefined attribute to add.
             * @param type The attribute's data type.
             * @param byteOffset The byte offset of the attribute location relative to a vertex
             *      entry's start.
             * @return The zero-based index of the attribute in the container, or -1 if failed.
             */
            virtual SInt32 AddAttribute(IEnums::AttributeItem item, IEnums::AttributeType type, UInt32& byteOffset) = 0;
            /**
             * @brief Add a user-defined vertex attribute.
             * This method adds a user-defined vertex attribute to the container, with a
             * given attribute type and a given byte offset relative to each vertex entry's
             * start pointer. The newly created attribute is only in effect when a shader material
             * is currently active that actually uses an attribute with the given name as input
             * to the vertex shader. As a convenience, the byte offset variable is incremented by
             * the actual number of bytes used by the given attribute type, e.g. 12 for a
             * 3-component vector of floats. If successful, this method returns the zero-based
             * index of the newly created attribute in the container; if failed, -1 is returned.
             * @param name The name of the attribute variable to add.
             * @param type The attribute's data type.
             * @param byteOffset The byte offset of the attribute location relative to a vertex
             *      entry's start.
             * @return The zero-based index of the attribute in the container, or -1 if failed.
             */
            virtual SInt32 AddAttribute(const String& name, IEnums::AttributeType type, UInt32& byteOffset) = 0;
            
            /**
             * @brief Query the location of a predefined attribute in the container.
             * This method can be used to query the zero-based index of a given predefined attribute
             * in the container. If the container does not hold the given attribute, -1 is returned.
             * @param item The predefined attribute to query.
             * @return The zero-based index of the attribute, or -1 if not found.
             */
            virtual SInt32 GetAttributeIndex(IEnums::AttributeItem item) const = 0;
            /**
             * @brief Query the location of a user-defined attribute in the container.
             * This method can be used to query the zero-based index of a given user-defined attribute
             * in the container. If the container does not hold the given attribute, -1 is returned.
             * @param name The name of the user-defined attribute to query.
             * @return The zero-based index of the attribute, or -1 if not found.
             */
            virtual SInt32 GetAttributeIndex(const String& name) const = 0;
            /**
             * @brief Get the total number of individual attributes in the container.
             * @return The total number of attributes added.
             */
            virtual UInt32 GetNumberOfAttributes() const = 0;
            
            /**
             * @brief Query the type of an attribute at a given index.
             * @param index The zero-based index of the attribute to query.
             * @return The attribute type.
             */
            virtual IEnums::AttributeType GetAttributeType(UInt32 index) const = 0;
            /**
             * @brief Query the predefined item of an attribute at a given index.
             * If the attribute at the given index represents a predefined one, this method returns
             * the actual item, e.g. IEnums::ATTRIBUTE_ITEM_NORMAL for vertex normal vectors.
             * If the attribute is a user-defined one, it returns IEnums::ATTRIBUTE_ITEM_CUSTOM.
             * @param index The zero-based index of the attribute to query.
             * @return The predefined attribute item.
             */
            virtual IEnums::AttributeItem GetAttributeItem(UInt32 index) const = 0;
            /**
             * @brief Query the variable name of an attribute at a given index.
             * If the attribute at the given index represents a user-defined one, this method returns
             * its actual name string. If it is a predefined one, an empty string is returned.
             * @param index The zero-based index of the attribute to query.
             * @return The user-defined attribute variable name.
             */
            virtual const String& GetAttributeName(UInt32 index) const = 0;
            /**
             * @brief Get the byte offset of an attribute at a given index.
             * @param index The zero-based index of the attribute to query.
             * @return The attribute's byte offset relative to the beginning of a vertex entry.
             */
            virtual UInt32 GetAttributeByteOffset(UInt32 index) const = 0;
            
            /**
             * @brief Get the attribute object at a given index.
             * This method returns an actual attribute object by its Graph::IAttribute base interface.
             * The base interface can be used to query common attribute properties; if access to actual
             * attribute data is required, use either a dynamic_cast to one of the available specialized
             * interfaces (e.g. Graph::IFloatVector4Attribute), or use the respective explicit method,
             * e.g. GetFloatVector4Attribute().
             * @param index The zero-based index of the attribute to retrieve.
             * @return The attribute object.
             */
            virtual IAttribute* GetAttribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute at a given index as a scalar float object.
             * This method can be used as a convenience to retrieve a typed attribute object. If the
             * attribute present in the container at the given index does not match the requested
             * type (scalar float in this case), a null pointer is returned.
             * @param index The zero-based index of the attribute to retrieve.
             * @return The attribute object, or a null pointer if the types do not match.
             */
            virtual IFloatAttribute* GetFloatAttribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute at a given index as a 2-component float vector object.
             * See GetFloatAttribute().
             * @param index The zero-based index of the attribute to retrieve.
             * @return The attribute object, or a null pointer if the types do not match.
             */
            virtual IFloatVector2Attribute* GetFloatVector2Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute at a given index as a 3-component float vector object.
             * See GetFloatAttribute().
             * @param index The zero-based index of the attribute to retrieve.
             * @return The attribute object, or a null pointer if the types do not match.
             */
            virtual IFloatVector3Attribute* GetFloatVector3Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute at a given index as a 4-component float vector object.
             * See GetFloatAttribute().
             * @param index The zero-based index of the attribute to retrieve.
             * @return The attribute object, or a null pointer if the types do not match.
             */
            virtual IFloatVector4Attribute* GetFloatVector4Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute at a given index as a scalar UInt8 object.
             * See GetFloatAttribute().
             * @param index The zero-based index of the attribute to retrieve.
             * @return The attribute object, or a null pointer if the types do not match.
             */
            virtual IUInt8Attribute* GetUInt8Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute at a given index as a 2-component UInt8 vector object.
             * See GetFloatAttribute().
             * @param index The zero-based index of the attribute to retrieve.
             * @return The attribute object, or a null pointer if the types do not match.
             */
            virtual IUInt8Vector2Attribute* GetUInt8Vector2Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute at a given index as a 3-component UInt8 vector object.
             * See GetFloatAttribute().
             * @param index The zero-based index of the attribute to retrieve.
             * @return The attribute object, or a null pointer if the types do not match.
             */
            virtual IUInt8Vector3Attribute* GetUInt8Vector3Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute at a given index as a 4-component UInt8 vector object.
             * See GetFloatAttribute().
             * @param index The zero-based index of the attribute to retrieve.
             * @return The attribute object, or a null pointer if the types do not match.
             */
            virtual IUInt8Vector4Attribute* GetUInt8Vector4Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute at a given index as a scalar SInt8 object.
             * See GetFloatAttribute().
             * @param index The zero-based index of the attribute to retrieve.
             * @return The attribute object, or a null pointer if the types do not match.
             */
            virtual ISInt8Attribute* GetSInt8Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute at a given index as a 2-component SInt8 vector object.
             * See GetFloatAttribute().
             * @param index The zero-based index of the attribute to retrieve.
             * @return The attribute object, or a null pointer if the types do not match.
             */
            virtual ISInt8Vector2Attribute* GetSInt8Vector2Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute at a given index as a 3-component SInt8 vector object.
             * See GetFloatAttribute().
             * @param index The zero-based index of the attribute to retrieve.
             * @return The attribute object, or a null pointer if the types do not match.
             */
            virtual ISInt8Vector3Attribute* GetSInt8Vector3Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute at a given index as a 4-component SInt8 vector object.
             * See GetFloatAttribute().
             * @param index The zero-based index of the attribute to retrieve.
             * @return The attribute object, or a null pointer if the types do not match.
             */
            virtual ISInt8Vector4Attribute* GetSInt8Vector4Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute at a given index as a scalar UInt16 object.
             * See GetFloatAttribute().
             * @param index The zero-based index of the attribute to retrieve.
             * @return The attribute object, or a null pointer if the types do not match.
             */
            virtual IUInt16Attribute* GetUInt16Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute at a given index as a 2-component UInt16 vector object.
             * See GetFloatAttribute().
             * @param index The zero-based index of the attribute to retrieve.
             * @return The attribute object, or a null pointer if the types do not match.
             */
            virtual IUInt16Vector2Attribute* GetUInt16Vector2Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute at a given index as a 3-component UInt16 vector object.
             * See GetFloatAttribute().
             * @param index The zero-based index of the attribute to retrieve.
             * @return The attribute object, or a null pointer if the types do not match.
             */
            virtual IUInt16Vector3Attribute* GetUInt16Vector3Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute at a given index as a 4-component UInt16 vector object.
             * See GetFloatAttribute().
             * @param index The zero-based index of the attribute to retrieve.
             * @return The attribute object, or a null pointer if the types do not match.
             */
            virtual IUInt16Vector4Attribute* GetUInt16Vector4Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute at a given index as a scalar SInt16 object.
             * See GetFloatAttribute().
             * @param index The zero-based index of the attribute to retrieve.
             * @return The attribute object, or a null pointer if the types do not match.
             */
            virtual ISInt16Attribute* GetSInt16Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute at a given index as a 2-component SInt16 vector object.
             * See GetFloatAttribute().
             * @param index The zero-based index of the attribute to retrieve.
             * @return The attribute object, or a null pointer if the types do not match.
             */
            virtual ISInt16Vector2Attribute* GetSInt16Vector2Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute at a given index as a 3-component SInt16 vector object.
             * See GetFloatAttribute().
             * @param index The zero-based index of the attribute to retrieve.
             * @return The attribute object, or a null pointer if the types do not match.
             */
            virtual ISInt16Vector3Attribute* GetSInt16Vector3Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute at a given index as a 4-component SInt16 vector object.
             * See GetFloatAttribute().
             * @param index The zero-based index of the attribute to retrieve.
             * @return The attribute object, or a null pointer if the types do not match.
             */
            virtual ISInt16Vector4Attribute* GetSInt16Vector4Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute at a given index as a normalized scalar UInt8 object.
             * See GetFloatAttribute().
             * @param index The zero-based index of the attribute to retrieve.
             * @return The attribute object, or a null pointer if the types do not match.
             */
            virtual IUInt8Attribute* GetNormalizedUInt8Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute at a given index as a normalized 2-component UInt8 vector object.
             * See GetFloatAttribute().
             * @param index The zero-based index of the attribute to retrieve.
             * @return The attribute object, or a null pointer if the types do not match.
             */
            virtual IUInt8Vector2Attribute* GetNormalizedUInt8Vector2Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute at a given index as a normalized 3-component UInt8 vector object.
             * See GetFloatAttribute().
             * @param index The zero-based index of the attribute to retrieve.
             * @return The attribute object, or a null pointer if the types do not match.
             */
            virtual IUInt8Vector3Attribute* GetNormalizedUInt8Vector3Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute at a given index as a normalized 4-component UInt8 vector object.
             * See GetFloatAttribute().
             * @param index The zero-based index of the attribute to retrieve.
             * @return The attribute object, or a null pointer if the types do not match.
             */
            virtual IUInt8Vector4Attribute* GetNormalizedUInt8Vector4Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute at a given index as a normalized scalar SInt8 object.
             * See GetFloatAttribute().
             * @param index The zero-based index of the attribute to retrieve.
             * @return The attribute object, or a null pointer if the types do not match.
             */
            virtual ISInt8Attribute* GetNormalizedSInt8Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute at a given index as a normalized 2-component SInt8 vector object.
             * See GetFloatAttribute().
             * @param index The zero-based index of the attribute to retrieve.
             * @return The attribute object, or a null pointer if the types do not match.
             */
            virtual ISInt8Vector2Attribute* GetNormalizedSInt8Vector2Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute at a given index as a normalized 3-component SInt8 vector object.
             * See GetFloatAttribute().
             * @param index The zero-based index of the attribute to retrieve.
             * @return The attribute object, or a null pointer if the types do not match.
             */
            virtual ISInt8Vector3Attribute* GetNormalizedSInt8Vector3Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute at a given index as a normalized 4-component SInt8 vector object.
             * See GetFloatAttribute().
             * @param index The zero-based index of the attribute to retrieve.
             * @return The attribute object, or a null pointer if the types do not match.
             */
            virtual ISInt8Vector4Attribute* GetNormalizedSInt8Vector4Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute at a given index as a normalized scalar UInt16 object.
             * See GetFloatAttribute().
             * @param index The zero-based index of the attribute to retrieve.
             * @return The attribute object, or a null pointer if the types do not match.
             */
            virtual IUInt16Attribute* GetNormalizedUInt16Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute at a given index as a normalized 2-component UInt16 vector object.
             * See GetFloatAttribute().
             * @param index The zero-based index of the attribute to retrieve.
             * @return The attribute object, or a null pointer if the types do not match.
             */
            virtual IUInt16Vector2Attribute* GetNormalizedUInt16Vector2Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute at a given index as a normalized 3-component UInt16 vector object.
             * See GetFloatAttribute().
             * @param index The zero-based index of the attribute to retrieve.
             * @return The attribute object, or a null pointer if the types do not match.
             */
            virtual IUInt16Vector3Attribute* GetNormalizedUInt16Vector3Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute at a given index as a normalized 4-component UInt16 vector object.
             * See GetFloatAttribute().
             * @param index The zero-based index of the attribute to retrieve.
             * @return The attribute object, or a null pointer if the types do not match.
             */
            virtual IUInt16Vector4Attribute* GetNormalizedUInt16Vector4Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute at a given index as a normalized scalar SInt16 object.
             * See GetFloatAttribute().
             * @param index The zero-based index of the attribute to retrieve.
             * @return The attribute object, or a null pointer if the types do not match.
             */
            virtual ISInt16Attribute* GetNormalizedSInt16Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute at a given index as a normalized 2-component SInt16 vector object.
             * See GetFloatAttribute().
             * @param index The zero-based index of the attribute to retrieve.
             * @return The attribute object, or a null pointer if the types do not match.
             */
            virtual ISInt16Vector2Attribute* GetNormalizedSInt16Vector2Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute at a given index as a normalized 3-component SInt16 vector object.
             * See GetFloatAttribute().
             * @param index The zero-based index of the attribute to retrieve.
             * @return The attribute object, or a null pointer if the types do not match.
             */
            virtual ISInt16Vector3Attribute* GetNormalizedSInt16Vector3Attribute(UInt32 index) const = 0;
            /**
             * @brief Get the attribute at a given index as a normalized 4-component SInt16 vector object.
             * See GetFloatAttribute().
             * @param index The zero-based index of the attribute to retrieve.
             * @return The attribute object, or a null pointer if the types do not match.
             */
            virtual ISInt16Vector4Attribute* GetNormalizedSInt16Vector4Attribute(UInt32 index) const = 0;


        protected:
            virtual ~IAttributeContainer() {}
        };

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IAttributeContainer nodes.
         */
        typedef IGenericNodeTarget<IAttributeContainer> IAttributeContainerNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_ATTRIBUTE_CONTAINER_H__
