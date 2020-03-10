// Copyright 2010-2011 Spraylight GmbH

#ifndef __MURL_GRAPH_I_DESERIALIZE_ATTRIBUTE_TRACKER_H__
#define __MURL_GRAPH_I_DESERIALIZE_ATTRIBUTE_TRACKER_H__

#include "murl_graph_types.h"
#include "murl_attribute_info.h"
#include "murl_i_attributes.h"

namespace Murl
{
    class IAttributes;
    class Result;

    namespace Resource
    {
        class IGraphNode;
    }

    namespace Graph
    {
        class IFactory;
        
        /**
         * @ingroup MurlGraphTrackerInterfaces
         * @interface IDeserializeAttributeTracker
         * @brief The tracker used for deserializing nodes and their attributes.
         * This interface represents a graph state tracker used in calls to the
         * Graph::INode::DeserializeNode and Graph::INode::DeserializeAttribute methods,
         * as well as the respective methods in Graph::IController, Graph::IGenericNodeTarget
         * and Graph::IGenericResourceTarget.
         */
        class IDeserializeAttributeTracker
        {
        public:
            /**
             * @brief Get the engine's graph factory.
             * @return The graph factory.
             */
            virtual const IFactory* GetGraphFactory() const = 0;

            /**
             * @brief Get the resource graph node containing the attributes to deserialize.
             * @return The resource graph node.
             */
            virtual const Resource::IGraphNode* GetResourceGraphNode() const = 0;
            /**
             * @brief Get a reference to the container holding the attributes to deserialize.
             * @return The attribute container.
             */
            virtual const IAttributes& GetAttributes() const = 0;
            /**
             * @brief Get a pointer to the container holding optional parameters to use.
             * @return The parameter container, or null if not used.
             */
            virtual const IAttributes* GetParameters() const = 0;

            /**
             * @brief Get the index of the attribute currently being deserialized.
             * @return The zero-based index into the attribute container from GetAttributes().
             */
            virtual UInt32 GetAttributeIndex() const = 0;
            /**
             * @brief Get the scope level of the attribute currently being deserialized.
             * @return The scope level.
             */
            virtual UInt32 GetAttributeLevel() const = 0;

            /**
             * @brief Exclude/include the node (and its children) currently being deserialized.
             * @param excluded If true, the sub-graph made up from this node and its children
             *      is excluded from creation.
             */
            virtual void SetNodeExcluded(Bool excluded) = 0;
            /**
             * @brief Exclude/include the children of the node currently being deserialized.
             * @param excluded If true, the node's children are excluded from creation.
             */
            virtual void SetChildrenExcluded(Bool excluded) = 0;
            /**
             * @brief Check if the current node (and its sub-graph) must be excluded from creation.
             * @return true if excluded.
             */
            virtual Bool MustExcludeNode() const = 0;
            /**
             * @brief Check if the current node's children must be excluded from creation.
             * @return true if excluded.
             */
            virtual Bool MustExcludeChildren() const = 0;

            /**
             * @brief Increase the current scope level by one.
             */
            virtual void IncreaseCurrentLevel() = 0;
            /**
             * @brief Decrease the current scope level by one.
             */
            virtual void DecreaseCurrentLevel() = 0;
            /**
             * @brief Get the current scope level.
             * @return The current scope level.
             */
            virtual UInt32 GetCurrentLevel() const = 0;

            /**
             * @brief Convert a given resource ID to an absolute path.
             * If the given resource ID already represents an absolute path, this method simply
             * returns true. This is the case when the ID is either in the form
             * "<PackageID>[/<SubPackageID>...]:<ResourceID>", or
             * "/<PackageID>[/<SubPackageID>...]/<ResourceID>".
             * Otherwise, the path is considered relative, and the current resource graph node
             * is used to get the absolute path to the graph resource from which deserialization
             * was started. If this cannot be done, false is returned.
             * @param resourceId A reference to the resource ID to convert.
             * @return true if successful.
             */
            virtual Bool MakeResourceIdAbsolute(String& resourceId) const = 0;

            /**
             * @brief Check if the current attribute has an actual value.
             * @return true if a value is given for the current attribute.
             */
            virtual Bool HasAttributeValue() const = 0;

            /**
             * @brief Check if any of the node's condition attributes matches the current user configuration.
             * See IAppConfiguration::IsUserConfigurationMatching().
             * @param evaluateParams if true, the attribute values are evaluated using the present parameters.
             * @return true if at least of the condition attributes matches the user configuration.
             */
            virtual Bool IsAnyAttributeValueMatchingAppUserConfiguration(Bool evaluateParams = true) const = 0;
            /**
             * @brief Check if any of the node's condition attributes matches the current language.
             * See IAppConfiguration::IsLanguageMatching().
             * @param evaluateParams if true, the attribute values are evaluated using the present parameters.
             * @return true if at least of the condition attributes matches the language.
             */
            virtual Bool IsAnyAttributeValueMatchingAppLanguage(Bool evaluateParams = true) const = 0;
            /**
             * @brief Check if any of the node's condition attributes matches the current target class.
             * See IPlatformConfiguration::IsTargetClassMatching().
             * @param evaluateParams if true, the attribute values are evaluated using the present parameters.
             * @return true if at least of the condition attributes matches the target class.
             */
            virtual Bool IsAnyAttributeValueMatchingPlatformTargetClass(Bool evaluateParams = true) const = 0;
            /**
             * @brief Check if any of the node's condition attributes matches the current target device.
             * See IPlatformConfiguration::IsTargetDeviceMatching().
             * @param evaluateParams if true, the attribute values are evaluated using the present parameters.
             * @return true if at least of the condition attributes matches the target device.
             */
            virtual Bool IsAnyAttributeValueMatchingPlatformTargetDevice(Bool evaluateParams = true) const = 0;
            /**
             * @brief Check if any of the node's condition attributes matches the current target host.
             * See IPlatformConfiguration::IsTargetHostMatching().
             * @param evaluateParams if true, the attribute values are evaluated using the present parameters.
             * @return true if at least of the condition attributes matches the target device.
             */
            virtual Bool IsAnyAttributeValueMatchingPlatformTargetHost(Bool evaluateParams = true) const = 0;
            /**
             * @brief Check if any of the node's condition attributes matches the current operating system.
             * See IPlatformConfiguration::IsOperatingSystemMatching().
             * @param evaluateParams if true, the attribute values are evaluated using the present parameters.
             * @return true if at least of the condition attributes matches the operating system.
             */
            virtual Bool IsAnyAttributeValueMatchingPlatformOperatingSystem(Bool evaluateParams = true) const = 0;
            /**
             * @brief Check if any of the node's condition attributes matches the current GPU.
             * See IPlatformConfiguration::IsGpuMatching().
             * @param evaluateParams if true, the attribute values are evaluated using the present parameters.
             * @return true if at least of the condition attributes matches the GPU.
             */
            virtual Bool IsAnyAttributeValueMatchingPlatformGpu(Bool evaluateParams = true) const = 0;
            /**
             * @brief Check if any of the node's condition attributes matches the current video API.
             * See IEngineConfiguration::IsVideoApiMatching().
             * @param evaluateParams if true, the attribute values are evaluated using the present parameters.
             * @return true if at least of the condition attributes matches the video API.
             */
            virtual Bool IsAnyAttributeValueMatchingEngineVideoApi(Bool evaluateParams = true) const = 0;
            /**
             * @brief Check if any of the node's condition attributes matches the current audio API.
             * See IEngineConfiguration::IsAudioApiMatching().
             * @param evaluateParams if true, the attribute values are evaluated using the present parameters.
             * @return true if at least of the condition attributes matches the audio API.
             */
            virtual Bool IsAnyAttributeValueMatchingEngineAudioApi(Bool evaluateParams = true) const = 0;
            /**
             * @brief Check if any of the node's condition attributes matches the current prescale factor.
             * See IEngineConfiguration::IsTexturePrescaleDivisorMatching().
             * @param evaluateParams if true, the attribute values are evaluated using the present parameters.
             * @return true if at least of the condition attributes matches the prescale factor.
             */
            virtual Bool IsAnyAttributeValueMatchingEnginePrescaleFactor(Bool evaluateParams = true) const = 0;
            /**
             * @brief Check if all of the node's condition attributes match the current engine feature set.
             * See IEngineConfiguration::GetFeatures().
             * @param evaluateParams if true, the attribute values are evaluated using the present parameters.
             * @return true if all of the condition attributes match the engine feature set.
             */
            virtual Bool AreAllAttributeValuesMatchingEngineFeatures(Bool evaluateParams = true) const = 0;

            /**
             * @brief Retrieve the current attribute value as a String.
             * @param value A reference to a variable receiving the attribute value.
             * @param evaluateParams if true, the attribute values are evaluated using the present parameters.
             * @return true if the value is valid.
             */
            virtual Bool GetAttributeValue(String& value, Bool evaluateParams = true) const = 0;
            /**
             * @brief Retrieve the current attribute value as a Bool value.
             * @param value A reference to a variable receiving the attribute value.
             * @param evaluateParams if true, the attribute values are evaluated using the present parameters.
             * @return true if the value is valid.
             */
            virtual Bool GetAttributeValue(Bool& value, Bool evaluateParams = true) const = 0;
            /**
             * @brief Retrieve the current attribute value as an UInt32 value.
             * @param value A reference to a variable receiving the attribute value.
             * @param evaluateParams if true, the attribute values are evaluated using the present parameters.
             * @return true if the value is valid.
             */
            virtual Bool GetAttributeValue(UInt32& value, Bool evaluateParams = true) const = 0;
            /**
             * @brief Retrieve the current attribute value as an SInt32 value.
             * @param value A reference to a variable receiving the attribute value.
             * @param evaluateParams if true, the attribute values are evaluated using the present parameters.
             * @return true if the value is valid.
             */
            virtual Bool GetAttributeValue(SInt32& value, Bool evaluateParams = true) const = 0;
            /**
             * @brief Retrieve the current attribute value as a Double value.
             * @param value A reference to a variable receiving the attribute value.
             * @param evaluateParams if true, the attribute values are evaluated using the present parameters.
             * @return true if the value is valid.
             */
            virtual Bool GetAttributeValue(Double& value, Bool evaluateParams = true) const = 0;
            /**
             * @brief Retrieve the current attribute value as a Float value.
             * @param value A reference to a variable receiving the attribute value.
             * @param evaluateParams if true, the attribute values are evaluated using the present parameters.
             * @return true if the value is valid.
             */
            virtual Bool GetAttributeValue(Float& value, Bool evaluateParams = true) const = 0;
            /**
             * @brief Retrieve the current attribute value as a Color value.
             * @param value A reference to a variable receiving the attribute value.
             * @param evaluateParams if true, the attribute values are evaluated using the present parameters.
             * @return true if the value is valid.
             */
            virtual Bool GetAttributeValue(Color& value, Bool evaluateParams = true) const = 0;

            /**
             * @brief Retrieve the current attribute value interpreted as an angle value.
             * The attribute value must contain either the "deg" or "d" postfix for an angle value in degrees,
             * or the "rad" or "r" postfix for an angle value in radians.
             * @param value A reference to a variable to receive the angle value in radians.
             * @param evaluateParams if true, the attribute values are evaluated using the present parameters.
             * @return true if the value is valid.
             */
            virtual Bool GetAttributeAngleValue(Double& value, Bool evaluateParams = true) const = 0;
            /**
             * @brief Retrieve the current attribute value interpreted as an angle value.
             * The attribute value must contain either the "deg" or "d" postfix for an angle value in degrees,
             * or the "rad" or "r" postfix for an angle value in radians.
             * @param value A reference to a variable to receive the angle value in radians.
             * @param evaluateParams if true, the attribute values are evaluated using the present parameters.
             * @return true if the value is valid.
             */
            virtual Bool GetAttributeAngleValue(Float& value, Bool evaluateParams = true) const = 0;
            /**
             * @brief Retrieve the current attribute value interpreted as an color value.
             * @param value A reference to a variable to receive the color value.
             * @param evaluateParams if true, the attribute values are evaluated using the present parameters.
             * @return true if the value is valid.
             */
            virtual Bool GetAttributeColorValue(Float& value, Bool evaluateParams = true) const = 0;

            /**
             * @brief Split the current attribute value to a String array.
             * @param values A reference to an array receiving the output values.
             * @param clear If true, the given array is cleared prior to conversion.
             * @param evaluateParams if true, the attribute values are evaluated using the present parameters.
             * @return true if the value is valid.
             */
            virtual Bool GetAttributeValues(StringArray& values, Bool clear = true, Bool evaluateParams = true) const = 0;
            /**
             * @brief Split the current attribute value to a Bool array.
             * @param values A reference to an array receiving the output values.
             * @param clear If true, the given array is cleared prior to conversion.
             * @param evaluateParams if true, the attribute values are evaluated using the present parameters.
             * @return true if the value is valid.
             */
            virtual Bool GetAttributeValues(BoolArray& values, Bool clear = true, Bool evaluateParams = true) const = 0;
            /**
             * @brief Split the current attribute value to an UInt32 array.
             * @param values A reference to an array receiving the output values.
             * @param clear If true, the given array is cleared prior to conversion.
             * @param evaluateParams if true, the attribute values are evaluated using the present parameters.
             * @return true if the value is valid.
             */
            virtual Bool GetAttributeValues(UInt32Array& values, Bool clear = true, Bool evaluateParams = true) const = 0;
            /**
             * @brief Split the current attribute value to an SInt32 array.
             * @param values A reference to an array receiving the output values.
             * @param clear If true, the given array is cleared prior to conversion.
             * @param evaluateParams if true, the attribute values are evaluated using the present parameters.
             * @return true if the value is valid.
             */
            virtual Bool GetAttributeValues(SInt32Array& values, Bool clear = true, Bool evaluateParams = true) const = 0;
            /**
             * @brief Split the current attribute value to a Double array.
             * @param values A reference to an array receiving the output values.
             * @param clear If true, the given array is cleared prior to conversion.
             * @param evaluateParams if true, the attribute values are evaluated using the present parameters.
             * @return true if the value is valid.
             */
            virtual Bool GetAttributeValues(DoubleArray& values, Bool clear = true, Bool evaluateParams = true) const = 0;
            /**
             * @brief Split the current attribute value to a Float array.
             * @param values A reference to an array receiving the output values.
             * @param clear If true, the given array is cleared prior to conversion.
             * @param evaluateParams if true, the attribute values are evaluated using the present parameters.
             * @return true if the value is valid.
             */
            virtual Bool GetAttributeValues(FloatArray& values, Bool clear = true, Bool evaluateParams = true) const = 0;

            /**
             * @brief Split the current attribute value to a Double array, interpreted as angle values.
             * @param values A reference to an array receiving the output values.
             * @param clear If true, the given array is cleared prior to conversion.
             * @param evaluateParams if true, the attribute values are evaluated using the present parameters.
             * @return true if the value is valid.
             */
            virtual Bool GetAttributeAngleValues(DoubleArray& values, Bool clear = true, Bool evaluateParams = true) const = 0;
            /**
             * @brief Split the current attribute value to a Float array, interpreted as angle values.
             * @param values A reference to an array receiving the output values.
             * @param clear If true, the given array is cleared prior to conversion.
             * @param evaluateParams if true, the attribute values are evaluated using the present parameters.
             * @return true if the value is valid.
             */
            virtual Bool GetAttributeAngleValues(FloatArray& values, Bool clear = true, Bool evaluateParams = true) const = 0;

            /**
             * @brief Split the current attribute value to a String buffer.
             * @param values A pointer to a raw memory buffer receiving the output values.
             * @param maxValues The capacity of the given buffer.
             * @param numValues An optional pointer to a variable receiving the actual number of values.
             * @param evaluateParams if true, the attribute values are evaluated using the present parameters.
             * @return true if the value is valid.
             */
            virtual Bool GetAttributeValues(String* values, UInt32 maxValues, UInt32* numValues = 0, Bool evaluateParams = true) const = 0;
            /**
             * @brief Split the current attribute value to a Bool buffer.
             * @param values A pointer to a raw memory buffer receiving the output values.
             * @param maxValues The capacity of the given buffer.
             * @param numValues An optional pointer to a variable receiving the actual number of values.
             * @param evaluateParams if true, the attribute values are evaluated using the present parameters.
             * @return true if the value is valid.
             */
            virtual Bool GetAttributeValues(Bool* values, UInt32 maxValues, UInt32* numValues = 0, Bool evaluateParams = true) const = 0;
            /**
             * @brief Split the current attribute value to an UInt32 buffer.
             * @param values A pointer to a raw memory buffer receiving the output values.
             * @param maxValues The capacity of the given buffer.
             * @param numValues An optional pointer to a variable receiving the actual number of values.
             * @param evaluateParams if true, the attribute values are evaluated using the present parameters.
             * @return true if the value is valid.
             */
            virtual Bool GetAttributeValues(UInt32* values, UInt32 maxValues, UInt32* numValues = 0, Bool evaluateParams = true) const = 0;
            /**
             * @brief Split the current attribute value to an SInt32 buffer.
             * @param values A pointer to a raw memory buffer receiving the output values.
             * @param maxValues The capacity of the given buffer.
             * @param numValues An optional pointer to a variable receiving the actual number of values.
             * @param evaluateParams if true, the attribute values are evaluated using the present parameters.
             * @return true if the value is valid.
             */
            virtual Bool GetAttributeValues(SInt32* values, UInt32 maxValues, UInt32* numValues = 0, Bool evaluateParams = true) const = 0;
            /**
             * @brief Split the current attribute value to a Double buffer.
             * @param values A pointer to a raw memory buffer receiving the output values.
             * @param maxValues The capacity of the given buffer.
             * @param numValues An optional pointer to a variable receiving the actual number of values.
             * @param evaluateParams if true, the attribute values are evaluated using the present parameters.
             * @return true if the value is valid.
             */
            virtual Bool GetAttributeValues(Double* values, UInt32 maxValues, UInt32* numValues = 0, Bool evaluateParams = true) const = 0;
            /**
             * @brief Split the current attribute value to a Float buffer.
             * @param values A pointer to a raw memory buffer receiving the output values.
             * @param maxValues The capacity of the given buffer.
             * @param numValues An optional pointer to a variable receiving the actual number of values.
             * @param evaluateParams if true, the attribute values are evaluated using the present parameters.
             * @return true if the value is valid.
             */
            virtual Bool GetAttributeValues(Float* values, UInt32 maxValues, UInt32* numValues = 0, Bool evaluateParams = true) const = 0;

            /**
             * @brief Split the current attribute value to a Double buffer, interpreted as angle values.
             * @param values A pointer to a raw memory buffer receiving the output values.
             * @param maxValues The capacity of the given buffer.
             * @param numValues An optional pointer to a variable receiving the actual number of values.
             * @param evaluateParams if true, the attribute values are evaluated using the present parameters.
             * @return true if the value is valid.
             */
            virtual Bool GetAttributeAngleValues(Double* values, UInt32 maxValues, UInt32* numValues = 0, Bool evaluateParams = true) const = 0;
            /**
             * @brief Split the current attribute value to a Float buffer, interpreted as angle values.
             * @param values A pointer to a raw memory buffer receiving the output values.
             * @param maxValues The capacity of the given buffer.
             * @param numValues An optional pointer to a variable receiving the actual number of values.
             * @param evaluateParams if true, the attribute values are evaluated using the present parameters.
             * @return true if the value is valid.
             */
            virtual Bool GetAttributeAngleValues(Float* values, UInt32 maxValues, UInt32* numValues = 0, Bool evaluateParams = true) const = 0;

            /**
             * @brief Set a bit mask if the current attribute value evaluates to boolean true.
             * @param mask The bit mask to set if true.
             * @param value A reference to a variable where the bits are set.
             * @param evaluateParams if true, the attribute values are evaluated using the present parameters.
             * @return true if the value is valid.
             */
            virtual Bool GetAttributeFlagToSet(UInt32 mask, UInt32& value, Bool evaluateParams = true) const = 0;
            /**
             * @brief Clear a bit mask if the current attribute value evaluates to boolean true.
             * @param mask The bit mask to clear if true.
             * @param value A reference to a variable where the bits are cleared.
             * @param evaluateParams if true, the attribute values are evaluated using the present parameters.
             * @return true if the value is valid.
             */
            virtual Bool GetAttributeFlagToClear(UInt32 mask, UInt32& value, Bool evaluateParams = true) const = 0;

            /**
             * @brief Retrieve the actual bit numbers to set from the given attribute value.
             * The attribute value must contain a comma-separated list of bit numbers (0-31) to set in the 
             * given output value.
             * @param value A reference to a variable where the bits are set.
             * @param evaluateParams if true, the attribute values are evaluated using the present parameters.
             * @return true if the value is valid.
             */
            virtual Bool GetAttributeBitsToSet(UInt32& value, Bool evaluateParams = true) const = 0;

            /**
             * @brief Retrieve the current attribute containing an enumeration string identifier.
             * @param e The enumeration containing valid values.
             * @param value A reference to an enum variable to receive the converted value.
             * @param evaluateParams if true, the attribute values are evaluated using the present parameters.
             * @return true if the value is valid.
             */
            template<class EnumType>
            Bool GetAttributeEnumValue(const Enum<EnumType>& e, EnumType& value, Bool evaluateParams = true) const
            {
                const IAttributes& attr = GetAttributes();
                const IAttributes* params = evaluateParams ? GetParameters() : 0;
                UInt32 index = GetAttributeIndex();
                return attr.GetEnumValueByIndex(index, params, e, value, GetResult());
            }
            
            /**
             * @brief Retrieve the current attribute containing a list of comma-separated enumeration string identifiers.
             * @param e The enumeration containing valid values.
             * @param values A reference to an array of enum variables to receive the converted values.
             * @param evaluateParams if true, the attribute values are evaluated using the present parameters.
             * @return true if the value is valid.
             */
            template<class EnumType>
            Bool GetAttributeEnumValues(const Enum<EnumType>& e, Array<EnumType>& values, Bool evaluateParams = true) const
            {
                const IAttributes& attr = GetAttributes();
                const IAttributes* params = evaluateParams ? GetParameters() : 0;
                UInt32 index = GetAttributeIndex();
                return attr.GetEnumValuesByIndex(index, params, e, values, GetResult());
            }
            /**
             * @brief Retrieve the current attribute containing a list of comma-separated enumeration string identifiers.
             * @param e The enumeration containing valid values.
             * @param values A pointer to a raw memory buffer receiving the output values.
             * @param maxValues The capacity of the given buffer.
             * @param numValues An optional pointer to a variable receiving the actual number of values.
             * @param evaluateParams if true, the attribute values are evaluated using the present parameters.
             * @return true if the value is valid.
             */
            template<class EnumType>
            Bool GetAttributeEnumValues(const Enum<EnumType>& e, EnumType* values, UInt32 maxValues, UInt32* numValues = 0, Bool evaluateParams = true) const
            {
                const IAttributes& attr = GetAttributes();
                const IAttributes* params = evaluateParams ? GetParameters() : 0;
                UInt32 index = GetAttributeIndex();
                return attr.GetEnumValuesByIndex(index, params, e, values, maxValues, GetResult(), numValues);
            }

            /**
             * @brief Retrieve the actual bit numbers to set from the given attribute value via enumeration string identifiers.
             * The attribute value must contain a comma-separated list of enumeration string identifiers that represent 
             * individual bits to set in the given output value.
             * @param e The enumeration containing valid values.
             * @param value A reference to a variable where the bits are set.
             * @param evaluateParams if true, the attribute values are evaluated using the present parameters.
             * @return true if the value is valid.
             */
            template<class EnumType>
            Bool GetAttributeEnumBitsToSet(const Enum<EnumType>& e, UInt32& value, Bool evaluateParams = true) const
            {
                const IAttributes& attr = GetAttributes();
                const IAttributes* params = evaluateParams ? GetParameters() : 0;
                UInt32 index = GetAttributeIndex();
                return attr.GetEnumBitsToSetByIndex(index, params, e, value, GetResult());
            }

            /**
             * @brief Get the actual ID of the current base attribute being deserialized.
             * @param info The AttributeInfo structure of the current class, obtained from GetAttributeInfo().
             * @return The base ID.
             */
            virtual UInt32 GetBaseAttribute(const AttributeInfo* info) const = 0;
            /**
             * @brief Get the actual ID of the current parent attribute being deserialized.
             * @param info The AttributeInfo structure of the current class, obtained from GetAttributeInfo().
             * @return The parent ID.
             */
            virtual UInt32 GetParentAttribute(const AttributeInfo* info) const = 0;
            /**
             * @brief Get the actual ID of the current grand parent attribute being deserialized.
             * @param info The AttributeInfo structure of the current class, obtained from GetAttributeInfo().
             * @return The grand parent ID.
             */
            virtual UInt32 GetGrandParentAttribute(const AttributeInfo* info) const = 0;

            /**
             * @brief Get the name of the current base attribute.
             * @return The base attribute name.
             */
            virtual String GetBaseAttributeName() const = 0;
            /**
             * @brief Get the name of the current parent attribute.
             * @return The parent attribute name.
             */
            virtual String GetParentAttributeName() const = 0;
            /**
             * @brief Get the name of the current grand parent attribute.
             * @return The parent attribute name.
             */
            virtual String GetGrandParentAttributeName() const = 0;

            /**
             * @brief Get the result object.
             * @return The result object.
             */
            virtual Result& GetResult() const = 0;

        protected:
            virtual ~IDeserializeAttributeTracker() {}
        };
    }
}

#endif // __MURL_GRAPH_I_DESERIALIZE_ATTRIBUTE_TRACKER_H__
