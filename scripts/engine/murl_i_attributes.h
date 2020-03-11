// Copyright 2010-2013 Spraylight GmbH

#ifndef __MURL_I_ATTRIBUTES_H__
#define __MURL_I_ATTRIBUTES_H__

#include "murl_string.h"
#include "murl_color.h"
#include "murl_enum.h"
#include "murl_result.h"

namespace Murl
{
    /**
     * @ingroup MurlInterfaces
     * @interface IAttributes
     * @brief The XML attributes interface.
     * The attributes interface provides XML attributes name and value information.
     * \n Names can be separated by a "dot syntax" e.g. `position.x="14" position.y="15"`.
     * \n Attribute can use multiple values separated by "," e.g. `digits="one, two, three"`.
     * \n Attribute values can be substitued by using attribute names in braces e.g. `size="{myAttribute}"`.
     */
    class IAttributes
    {
    public:
        /**
         * @brief The destructor.
         */
        virtual ~IAttributes() {}

        /**
         * @brief Clear all attributes.
         * @return true if successful.
         */
        virtual Bool Clear() = 0;

        /**
         * @brief Add a set of default attributes for named queries.
         * @param defaultAttributes The default attributes object to add.
         * @return true if successful, false if the given object was already added
         *      or the container does not allow to add defaults.
         */
        virtual Bool AddDefaults(const IAttributes* defaultAttributes) = 0;

        /**
         * @brief Get the number of default attribute sets added via AddDefaults().
         * @return The number of default attribute sets.
         */
        virtual UInt32 GetNumberOfDefaults() const = 0;

        /**
         * @brief Get the default attribute set at a given index.
         * @param index The index, from 0 to GetNumberOfDefaults()-1.
         * @return The default attribute set, or null if index is out of range.
         */
        virtual const IAttributes* GetDefaults(UInt32 index) const = 0;

        /**
         * @brief Add a single attribute name and value.
         * @param fullName The full name of the attribute (including the dots).
         * @param value The value of the attribute.
         * @return true if successful, false if the name already exists.
         */
        virtual Bool AddAttribute(const String& fullName, const String& value) = 0;
        /**
         * @brief Set a value for a named attribute.
         * Sets the attribute to unused state.
         * @param fullName The full name of the attribute (including the dots).
         * @param value The value of the attribute.
         * @return true if successful, false if the name does not exist.
         */
        virtual Bool SetAttribute(const String& fullName, const String& value) = 0;

        /**
         * @brief Get the number of attributes.
         * Attributes are organized using an index and a level number
         * to support the "dot syntax" native.
         * \n e.g. `a="7" e.f="9" b.c.d="8" e.g="10"`
         *  - The number of attributes is 6.
         *  - "a" has index 0 and level 0, value is "7".
         *  - "e" has index 1 and level 0, value is "null".
         *  - "f" has index 2 and level 1, value is "9".
         *  - "b" has index 3 and level 0, value is null.
         *  - "c" has index 4 and level 1, value is null.
         *  - "d" has index 5 and level 2, value is "8".
         *  - "g" has index 6 and level 1, value is "10".
         *
         * The parents can be accessed by decreasing the level.
         *  - "b" can be found at index 4 and level 0.
         *  - "b" can be found at index 5 and level 0.
         *  - "c" can be found at index 5 and level 1.
         *  - "e" can be found at index 2 and level 0.
         *  - "e" can be found at index 6 and level 0.
         * @return The number of attributes.
         */
        virtual UInt32 GetNumberOfAttributes() const = 0;
        
        /**
         * @brief Get the hash of an attribute name.
         * @param index The index of the attribute.
         * @param level The level of the attribute.
         * @return The hash value of the attribute name.
         */
        virtual UInt32 GetAttributeHash(UInt32 index, UInt32 level = 0) const = 0;
        /**
         * @brief Get the name of an attribute.
         * @param index The index of the attribute.
         * @param level The level of the attribute.
         * @return The name of the attribute or null if index / level is out of range.
         */
        virtual const Char* GetAttributeName(UInt32 index, UInt32 level = 0) const = 0;
        /**
         * @brief Get the value of an attribute.
         * @param index The index of the attribute.
         * @param level The level of the attribute.
         * @return The value of the attribute or null if the attribute has no value or
         *  if index / level is out of range.
         */
        virtual const Char* GetAttributeValue(UInt32 index, UInt32 level = 0) const = 0;
        /**
         * @brief Get the full name of an attribute.
         * The full name includes all parent attributes separated by dots.
         * @param index The index of the attribute.
         * @return The name of the attribute or an empty string if index is out of range.
         */
        virtual String GetFullAttributeName(UInt32 index) const = 0;
        /**
         * @brief Get the value of an attribute (ignoring the level).
         * @param index The index of the attribute.
         * @return The value of the attribute or null if the attribute has no value or
         *  if index is out of range.
         */
        virtual const Char* GetFullAttributeValue(UInt32 index) const = 0;
        /**
         * @brief Get the index of an attribute name at level 0.
         * @param name The name of the attribute.
         * @return The index of the attribute or -1 if the name at level 0 does not exist.
         */
        virtual SInt32 GetAttributeIndex(const char* name) const = 0;
        /**
         * @brief Get the index of a fully qualified attribute.
         * @param fullName The full name of the attribute, including separating dots.
         * @return The index of the attribute or -1 if the given name does not exist.
         */
        virtual SInt32 GetFullAttributeIndex(const char* fullName) const = 0;

        /**
         * @brief Get the parent index of an attribute.
         * @param index The index of the attribute.
         * @return The parent index of the attribute or -1 if the attribute has no parent or
         *  if index is out of range.
         */
        virtual SInt32 GetAttributeParent(UInt32 index) const = 0;
        /**
         * @brief Get the level of an attribute.
         * @param index The index of the attribute.
         * @return The level of the attribute.
         */
        virtual UInt32 GetAttributeLevel(UInt32 index) const = 0;
        /**
         * @brief Check if the attribute is used.
         * The attribute used state is set when calling one if the GetValue...() methods was successful.
         * @param index The index of the attribute.
         * @return true if the attribute is used.
         */
        virtual Bool IsAttributeUsed(UInt32 index) const = 0;
        /**
         * @brief Check if the attribute has a value.
         * @param index The index of the attribute.
         * @return true if the attribute has a value.
         */
        virtual Bool HasAttributeValue(UInt32 index) const = 0;
        
        /**
         * @brief Get the number of unused attributes.
         * @return The number of unused attributes.
         */
        virtual UInt32 GetNumberOfUnusedAttributes() const = 0;
        /**
         * @brief Get the names of unused attributes.
         * @param names The string array to add the names.
         * @return true if names were added.
         */
        virtual Bool GetUnusedAttributeNames(StringArray& names) const = 0;
        
        /**
         * @brief Set all attributes to used state.
         * @return true if successful.
         */
        virtual Bool SetAllAttributesUsed() const = 0;

        /**
         * @brief Evaluate an expression string.
         * @param expression The expression string to evaluate.
         * @param value A reference to a string receiving the result if successful.
         * @param error The error return value is set to true if evaluation failed.
         * @return true if successful.
         */
        virtual Bool EvaluateExpression(const Char* expression, String& value, Bool& error) const = 0;
        /**
         * @brief Evaluate an expression string.
         * @param expression The expression string to evaluate.
         * @param value A reference to a string receiving the result if successful.
         * @param result An error message is appended to this object if evaluation failed.
         * @return true if successful.
         */
        virtual Bool EvaluateExpression(const Char* expression, String& value, Result& result) const = 0;

        /**
         * @brief Get the string value of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param value The string return value.
         * @param error The error return value is set to true if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValueByIndex(UInt32 index, const IAttributes* params, String& value, Bool& error) const = 0;
        /**
         * @brief Get the boolean value of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param value The boolean return value.
         * @param error The error return value is set to true if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValueByIndex(UInt32 index, const IAttributes* params, Bool& value, Bool& error) const = 0;
        /**
         * @brief Get the unsigned integer value of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param value The unsigned integer return value.
         * @param error The error return value is set to true if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValueByIndex(UInt32 index, const IAttributes* params, UInt32& value, Bool& error) const = 0;
        /**
         * @brief Get the signed integer value of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param value The signed integer return value.
         * @param error The error return value is set to true if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValueByIndex(UInt32 index, const IAttributes* params, SInt32& value, Bool& error) const = 0;
        /**
         * @brief Get the double value of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param value The double return value.
         * @param error The error return value is set to true if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValueByIndex(UInt32 index, const IAttributes* params, Double& value, Bool& error) const = 0;
        /**
         * @brief Get the float value of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param value The float return value.
         * @param error The error return value is set to true if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValueByIndex(UInt32 index, const IAttributes* params, Float& value, Bool& error) const = 0;
        /**
         * @brief Get the color value of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param value The color return value.
         * @param error The error return value is set to true if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValueByIndex(UInt32 index, const IAttributes* params, Color& value, Bool& error) const = 0;
        /**
         * @brief Get the string value of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param value The string return value.
         * @param result An error message is appended to this object if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValueByIndex(UInt32 index, const IAttributes* params, String& value, Result& result) const = 0;
        /**
         * @brief Get the boolean value of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param value The boolean return value.
         * @param result An error message is appended to this object if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValueByIndex(UInt32 index, const IAttributes* params, Bool& value, Result& result) const = 0;
        /**
         * @brief Get the unsigned integer value of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param value The unsigned integer return value.
         * @param result An error message is appended to this object if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValueByIndex(UInt32 index, const IAttributes* params, UInt32& value, Result& result) const = 0;
        /**
         * @brief Get the signed integer value of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param value The signed integer return value.
         * @param result An error message is appended to this object if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValueByIndex(UInt32 index, const IAttributes* params, SInt32& value, Result& result) const = 0;
        /**
         * @brief Get the double value of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param value The double return value.
         * @param result An error message is appended to this object if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValueByIndex(UInt32 index, const IAttributes* params, Double& value, Result& result) const = 0;
        /**
         * @brief Get the float value of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param value The float return value.
         * @param result An error message is appended to this object if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValueByIndex(UInt32 index, const IAttributes* params, Float& value, Result& result) const = 0;
        /**
         * @brief Get the color value of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param value The color return value.
         * @param result An error message is appended to this object if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValueByIndex(UInt32 index, const IAttributes* params, Color& value, Result& result) const = 0;

        /**
         * @brief Get the angle double value of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param value The angle double return value.
         * @param error The error return value is set to true if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetAngleValueByIndex(UInt32 index, const IAttributes* params, Double& value, Bool& error) const = 0;
        /**
         * @brief Get the angle float value of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param value The angle float return value.
         * @param error The error return value is set to true if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetAngleValueByIndex(UInt32 index, const IAttributes* params, Float& value, Bool& error) const = 0;
        /**
         * @brief Get the color component value of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param value The color component return value.
         * @param error The error return value is set to true if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetColorValueByIndex(UInt32 index, const IAttributes* params, Float& value, Bool& error) const = 0;
        /**
         * @brief Get the angle double value of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param value The angle double return value.
         * @param result An error message is appended to this object if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetAngleValueByIndex(UInt32 index, const IAttributes* params, Double& value, Result& result) const = 0;
        /**
         * @brief Get the angle float value of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param value The angle float return value.
         * @param result An error message is appended to this object if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetAngleValueByIndex(UInt32 index, const IAttributes* params, Float& value, Result& result) const = 0;
        /**
         * @brief Get the color component value of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param value The color component return value.
         * @param result An error message is appended to this object if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetColorValueByIndex(UInt32 index, const IAttributes* params, Float& value, Result& result) const = 0;

        /**
         * @brief Get the string values of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values The string array return value.
         * @param error The error return value is set to true if data conversion failed.
         * @param clear If true clear the return value array before adding the return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, StringArray& values, Bool& error, Bool clear = true) const = 0;
        /**
         * @brief Get the boolean values of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values The boolean array return value.
         * @param error The error return value is set to true if data conversion failed.
         * @param clear If true clear the return value array before adding the return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, BoolArray& values, Bool& error, Bool clear = true) const = 0;
        /**
         * @brief Get the unsigned integer values of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values The unsigned integer array return value.
         * @param error The error return value is set to true if data conversion failed.
         * @param clear If true clear the return value array before adding the return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, UInt32Array& values, Bool& error, Bool clear = true) const = 0;
        /**
         * @brief Get the signed integer values of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values The signed integer array return value.
         * @param error The error return value is set to true if data conversion failed.
         * @param clear If true clear the return value array before adding the return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, SInt32Array& values, Bool& error, Bool clear = true) const = 0;
        /**
         * @brief Get the double values of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values The double array return value.
         * @param error The error return value is set to true if data conversion failed.
         * @param clear If true clear the return value array before adding the return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, DoubleArray& values, Bool& error, Bool clear = true) const = 0;
        /**
         * @brief Get the float values of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values The float array return value.
         * @param error The error return value is set to true if data conversion failed.
         * @param clear If true clear the return value array before adding the return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, FloatArray& values, Bool& error, Bool clear = true) const = 0;
        /**
         * @brief Get the string values of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values The string array return value.
         * @param result An error message is appended to this object if data conversion failed.
         * @param clear If true clear the return value array before adding the return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, StringArray& values, Result& result, Bool clear = true) const = 0;
        /**
         * @brief Get the boolean values of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values The boolean array return value.
         * @param result An error message is appended to this object if data conversion failed.
         * @param clear If true clear the return value array before adding the return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, BoolArray& values, Result& result, Bool clear = true) const = 0;
        /**
         * @brief Get the unsigned integer values of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values The unsigned integer array return value.
         * @param result An error message is appended to this object if data conversion failed.
         * @param clear If true clear the return value array before adding the return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, UInt32Array& values, Result& result, Bool clear = true) const = 0;
        /**
         * @brief Get the signed integer values of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values The signed integer array return value.
         * @param result An error message is appended to this object if data conversion failed.
         * @param clear If true clear the return value array before adding the return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, SInt32Array& values, Result& result, Bool clear = true) const = 0;
        /**
         * @brief Get the double values of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values The double array return value.
         * @param result An error message is appended to this object if data conversion failed.
         * @param clear If true clear the return value array before adding the return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, DoubleArray& values, Result& result, Bool clear = true) const = 0;
        /**
         * @brief Get the float values of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values The float array return value.
         * @param result An error message is appended to this object if data conversion failed.
         * @param clear If true clear the return value array before adding the return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, FloatArray& values, Result& result, Bool clear = true) const = 0;

        /**
         * @brief Get the double angle values of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values The double array return value.
         * @param error The error return value is set to true if data conversion failed.
         * @param clear If true clear the return value array before adding the return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetAngleValuesByIndex(UInt32 index, const IAttributes* params, DoubleArray& values, Bool& error, Bool clear = true) const = 0;
        /**
         * @brief Get the float angle values of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values The float array return value.
         * @param error The error return value is set to true if data conversion failed.
         * @param clear If true clear the return value array before adding the return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetAngleValuesByIndex(UInt32 index, const IAttributes* params, FloatArray& values, Bool& error, Bool clear = true) const = 0;
        /**
         * @brief Get the double angle values of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values The double array return value.
         * @param result An error message is appended to this object if data conversion failed.
         * @param clear If true clear the return value array before adding the return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetAngleValuesByIndex(UInt32 index, const IAttributes* params, DoubleArray& values, Result& result, Bool clear = true) const = 0;
        /**
         * @brief Get the float angle values of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values The float array return value.
         * @param result An error message is appended to this object if data conversion failed.
         * @param clear If true clear the return value array before adding the return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetAngleValuesByIndex(UInt32 index, const IAttributes* params, FloatArray& values, Result& result, Bool clear = true) const = 0;

        /**
         * @brief Get the String values of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values A pointer to a raw array of String objects to receive the return values.
         * @param maxValues The capacity of the raw array.
         * @param error The error return value is set to true if data conversion failed.
         * @param numValues An optional pointer to a variable receiving the number of return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, String* values, UInt32 maxValues, Bool& error, UInt32* numValues = 0) const = 0;
        /**
         * @brief Get the boolean values of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values A pointer to a raw array of Bool values to receive the return values.
         * @param maxValues The capacity of the raw array.
         * @param error The error return value is set to true if data conversion failed.
         * @param numValues An optional pointer to a variable receiving the number of return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, Bool* values, UInt32 maxValues, Bool& error, UInt32* numValues = 0) const = 0;
        /**
         * @brief Get the unsigned integer values of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values A pointer to a raw array of UInt32 values to receive the return values.
         * @param maxValues The capacity of the raw array.
         * @param error The error return value is set to true if data conversion failed.
         * @param numValues An optional pointer to a variable receiving the number of return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, UInt32* values, UInt32 maxValues, Bool& error, UInt32* numValues = 0) const = 0;
        /**
         * @brief Get the signed integer values of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values A pointer to a raw array of SInt32 values to receive the return values.
         * @param maxValues The capacity of the raw array.
         * @param error The error return value is set to true if data conversion failed.
         * @param numValues An optional pointer to a variable receiving the number of return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, SInt32* values, UInt32 maxValues, Bool& error, UInt32* numValues = 0) const = 0;
        /**
         * @brief Get the double values of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values A pointer to a raw array of double values to receive the return values.
         * @param maxValues The capacity of the raw array.
         * @param error The error return value is set to true if data conversion failed.
         * @param numValues An optional pointer to a variable receiving the number of return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, Double* values, UInt32 maxValues, Bool& error, UInt32* numValues = 0) const = 0;
        /**
         * @brief Get the float values of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values A pointer to a raw array of float values to receive the return values.
         * @param maxValues The capacity of the raw array.
         * @param error The error return value is set to true if data conversion failed.
         * @param numValues An optional pointer to a variable receiving the number of return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, Float* values, UInt32 maxValues, Bool& error, UInt32* numValues = 0) const = 0;
        /**
         * @brief Get the String values of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values A pointer to a raw array of String objects to receive the return values.
         * @param maxValues The capacity of the raw array.
         * @param result An error message is appended to this object if data conversion failed.
         * @param numValues An optional pointer to a variable receiving the number of return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, String* values, UInt32 maxValues, Result& result, UInt32* numValues = 0) const = 0;
        /**
         * @brief Get the boolean values of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values A pointer to a raw array of Bool values to receive the return values.
         * @param maxValues The capacity of the raw array.
         * @param result An error message is appended to this object if data conversion failed.
         * @param numValues An optional pointer to a variable receiving the number of return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, Bool* values, UInt32 maxValues, Result& result, UInt32* numValues = 0) const = 0;
        /**
         * @brief Get the unsigned integer values of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values A pointer to a raw array of UInt32 values to receive the return values.
         * @param maxValues The capacity of the raw array.
         * @param result An error message is appended to this object if data conversion failed.
         * @param numValues An optional pointer to a variable receiving the number of return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, UInt32* values, UInt32 maxValues, Result& result, UInt32* numValues = 0) const = 0;
        /**
         * @brief Get the signed integer values of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values A pointer to a raw array of SInt32 values to receive the return values.
         * @param maxValues The capacity of the raw array.
         * @param result An error message is appended to this object if data conversion failed.
         * @param numValues An optional pointer to a variable receiving the number of return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, SInt32* values, UInt32 maxValues, Result& result, UInt32* numValues = 0) const = 0;
        /**
         * @brief Get the double values of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values A pointer to a raw array of double values to receive the return values.
         * @param maxValues The capacity of the raw array.
         * @param result An error message is appended to this object if data conversion failed.
         * @param numValues An optional pointer to a variable receiving the number of return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, Double* values, UInt32 maxValues, Result& result, UInt32* numValues = 0) const = 0;
        /**
         * @brief Get the float values of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values A pointer to a raw array of float values to receive the return values.
         * @param maxValues The capacity of the raw array.
         * @param result An error message is appended to this object if data conversion failed.
         * @param numValues An optional pointer to a variable receiving the number of return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, Float* values, UInt32 maxValues, Result& result, UInt32* numValues = 0) const = 0;

        /**
         * @brief Get the double angle values of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values A pointer to a raw array of double values to receive the return values.
         * @param maxValues The capacity of the raw array.
         * @param error The error return value is set to true if data conversion failed.
         * @param numValues An optional pointer to a variable receiving the number of return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetAngleValuesByIndex(UInt32 index, const IAttributes* params, Double* values, UInt32 maxValues, Bool& error, UInt32* numValues = 0) const = 0;
        /**
         * @brief Get the float angle values of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values A pointer to a raw array of float values to receive the return values.
         * @param maxValues The capacity of the raw array.
         * @param error The error return value is set to true if data conversion failed.
         * @param numValues An optional pointer to a variable receiving the number of return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetAngleValuesByIndex(UInt32 index, const IAttributes* params, Float* values, UInt32 maxValues, Bool& error, UInt32* numValues = 0) const = 0;
        /**
         * @brief Get the double angle values of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values A pointer to a raw array of double values to receive the return values.
         * @param maxValues The capacity of the raw array.
         * @param result An error message is appended to this object if data conversion failed.
         * @param numValues An optional pointer to a variable receiving the number of return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetAngleValuesByIndex(UInt32 index, const IAttributes* params, Double* values, UInt32 maxValues, Result& result, UInt32* numValues = 0) const = 0;
        /**
         * @brief Get the float angle values of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values A pointer to a raw array of float values to receive the return values.
         * @param maxValues The capacity of the raw array.
         * @param result An error message is appended to this object if data conversion failed.
         * @param numValues An optional pointer to a variable receiving the number of return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetAngleValuesByIndex(UInt32 index, const IAttributes* params, Float* values, UInt32 maxValues, Result& result, UInt32* numValues = 0) const = 0;

        /**
         * @brief Get the bit number values of an attribute by index and set the bits.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param value The bits return value.
         * @param error The error return value is set to true if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetBitsToSetByIndex(UInt32 index, const IAttributes* params, UInt32& value, Bool& error) const = 0;
        /**
         * @brief Get the bit number values of an attribute by index and set the bits.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param value The bits return value.
         * @param result An error message is appended to this object if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetBitsToSetByIndex(UInt32 index, const IAttributes* params, UInt32& value, Result& result) const = 0;

        /**
         * @brief Get the enumeration value of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param enumClass The enumeration class for looking up the value.
         * @param value The enumeration return value.
         * @param error The error return value is set to true if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        template<class EnumType>
        Bool GetEnumValueByIndex(UInt32 index, const IAttributes* params, const Enum<EnumType>& enumClass,
                                 EnumType& value, Bool& error) const
        {
            String strVal;
            if (!GetValueByIndex(index, params, strVal, error))
            {
                return false;
            }
            
            value = enumClass.GetEnumValueByName(strVal, error, false);
            return true;
        }
        /**
         * @brief Get the enumeration value of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param enumClass The enumeration class for looking up the value.
         * @param value The enumeration return value.
         * @param result An error message is appended to this object if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        template<class EnumType>
        Bool GetEnumValueByIndex(UInt32 index, const IAttributes* params, const Enum<EnumType>& enumClass,
                                 EnumType& value, Result& result) const
        {
            String strVal;
            if (!GetValueByIndex(index, params, strVal, result))
            {
                return false;
            }

            Bool error = false;
            value = enumClass.GetEnumValueByName(strVal, error, false);
            if (error)
            {
                result.Append(IEnums::RESULT_CODE_ATTRIBUTE_ENUM_CONVERSION_ERROR, "Failed to get enum value for name '%s'", strVal.Begin());
            }
            return true;
        }

        /**
         * @brief Get the enumeration values of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param enumClass The enumeration class for looking up the value.
         * @param values The enumeration array return value.
         * @param error The error return value is set to true if data conversion failed.
         * @param clear If true clear the return value array before adding the return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        template<class EnumType>
        Bool GetEnumValuesByIndex(UInt32 index, const IAttributes* params, const Enum<EnumType>& enumClass,
                                  Array<EnumType>& values, Bool& error, Bool clear = true) const
        {
            if (clear)
            {
                values.Clear();
            }
            
            StringArray strValues;
            if (!GetValuesByIndex(index, params, strValues, error))
            {
                return false;
            }
            
            for (UInt32 j = 0; j < strValues.GetCount(); j++)
            {
                values.Add(enumClass.GetEnumValueByName(strValues[j], error, false));
            }
            return true;
        }
        /**
         * @brief Get the enumeration values of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param enumClass The enumeration class for looking up the value.
         * @param values A pointer to a raw array of enum variables to receive the return values.
         * @param maxValues The capacity of the raw array.
         * @param error The error return value is set to true if data conversion failed.
         * @param numValues An optional pointer to a variable receiving the number of return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        template<class EnumType>
        Bool GetEnumValuesByIndex(UInt32 index, const IAttributes* params, const Enum<EnumType>& enumClass,
                                  EnumType* values, UInt32 maxValues, Bool& error, UInt32* numValues = 0) const
        {
            StringArray strValues;
            if (!GetValuesByIndex(index, params, strValues, error))
            {
                return false;
            }

            UInt32 n = Math::Min(UInt32(strValues.GetCount()), maxValues);
            for (UInt32 i = 0; i < n; i++)
            {
                values[i] = enumClass.GetEnumValueByName(strValues[i], error);
            }
            
            if (numValues != 0)
            {
                *numValues = n;
            }
            return true;
        }
        /**
         * @brief Get the enumeration values of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param enumClass The enumeration class for looking up the value.
         * @param values The enumeration array return value.
         * @param result An error message is appended to this object if data conversion failed.
         * @param clear If true clear the return value array before adding the return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        template<class EnumType>
        Bool GetEnumValuesByIndex(UInt32 index, const IAttributes* params, const Enum<EnumType>& enumClass,
                                  Array<EnumType>& values, Result& result, Bool clear = true) const
        {
            if (clear)
            {
                values.Clear();
            }

            StringArray strValues;
            if (!GetValuesByIndex(index, params, strValues, result))
            {
                return false;
            }

            for (UInt32 j = 0; j < strValues.GetCount(); j++)
            {
                Bool error = false;
                values.Add(enumClass.GetEnumValueByName(strValues[j], error, false));
                if (error)
                {
                    result.Append(IEnums::RESULT_CODE_ATTRIBUTE_ENUM_CONVERSION_ERROR, "Failed to get enum value for name '%s'", strValues[j].Begin());
                }
            }
            return true;
        }
        /**
         * @brief Get the enumeration values of an attribute by index.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param enumClass The enumeration class for looking up the value.
         * @param values A pointer to a raw array of enum variables to receive the return values.
         * @param maxValues The capacity of the raw array.
         * @param result An error message is appended to this object if data conversion failed.
         * @param numValues An optional pointer to a variable receiving the number of return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        template<class EnumType>
        Bool GetEnumValuesByIndex(UInt32 index, const IAttributes* params, const Enum<EnumType>& enumClass,
                                  EnumType* values, UInt32 maxValues, Result& result, UInt32* numValues = 0) const
        {
            StringArray strValues;
            if (!GetValuesByIndex(index, params, strValues, result))
            {
                return false;
            }

            UInt32 n = Math::Min(UInt32(strValues.GetCount()), maxValues);
            for (UInt32 i = 0; i < n; i++)
            {
                Bool error = false;
                values[i] = enumClass.GetEnumValueByName(strValues[i], error);
                if (error)
                {
                    result.Append(IEnums::RESULT_CODE_ATTRIBUTE_ENUM_CONVERSION_ERROR, "Failed to get enum value for name '%s'", strValues[i].Begin());
                }
            }

            if (numValues != 0)
            {
                *numValues = n;
            }
            return true;
        }

        /**
         * @brief Get the enumerated bit number values of an attribute by index and set the bits.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param enumClass The enumeration class for looking up the value.
         * @param value The bits return value.
         * @param error The error return value is set to true if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        template<class EnumType>
        Bool GetEnumBitsToSetByIndex(UInt32 index, const IAttributes* params, const Enum<EnumType>& enumClass,
                                     UInt32& value, Bool& error) const
        {
            StringArray strValues;
            if (!GetValuesByIndex(index, params, strValues, error))
            {
                return false;
            }
            
            for (UInt32 j = 0; j < strValues.GetCount(); j++)
            {
                value |= enumClass.GetEnumValueByName(strValues[j], error, false);
            }
            return true;
        }
        /**
         * @brief Get the enumerated bit number values of an attribute by index and set the bits.
         * @param index The index of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param enumClass The enumeration class for looking up the value.
         * @param value The bits return value.
         * @param result An error message is appended to this object if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        template<class EnumType>
        Bool GetEnumBitsToSetByIndex(UInt32 index, const IAttributes* params, const Enum<EnumType>& enumClass,
                                     UInt32& value, Result& result) const
        {
            StringArray strValues;
            if (!GetValuesByIndex(index, params, strValues, result))
            {
                return false;
            }

            for (UInt32 j = 0; j < strValues.GetCount(); j++)
            {
                Bool error = false;
                value |= enumClass.GetEnumValueByName(strValues[j], error, false);
                if (error)
                {
                    result.Append(IEnums::RESULT_CODE_ATTRIBUTE_ENUM_CONVERSION_ERROR, "Failed to get enum value for name '%s'", strValues[j].Begin());
                }
            }
            return true;
        }

        /**
         * @brief Get the string value of an attribute by name at level 0.
         * @param name The name of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param value The string return value.
         * @param error The error return value is set to true if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValueByName(const Char* name, const IAttributes* params, String& value, Bool& error) const = 0;
        /**
         * @brief Get the boolean value of an attribute by name at level 0.
         * @param name The name of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param value The boolean return value.
         * @param error The error return value is set to true if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValueByName(const Char* name, const IAttributes* params, Bool& value, Bool& error) const = 0;
        /**
         * @brief Get the unsigned integer value of an attribute by name at level 0.
         * @param name The name of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param value The unsigned integer return value.
         * @param error The error return value is set to true if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValueByName(const Char* name, const IAttributes* params, UInt32& value, Bool& error) const = 0;
        /**
         * @brief Get the signed integer value of an attribute by name at level 0.
         * @param name The name of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param value The signed integer return value.
         * @param error The error return value is set to true if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValueByName(const Char* name, const IAttributes* params, SInt32& value, Bool& error) const = 0;
        /**
         * @brief Get the double value of an attribute by name at level 0.
         * @param name The name of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param value The double return value.
         * @param error The error return value is set to true if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValueByName(const Char* name, const IAttributes* params, Double& value, Bool& error) const = 0;
        /**
         * @brief Get the float value of an attribute by name at level 0.
         * @param name The name of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param value The float return value.
         * @param error The error return value is set to true if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValueByName(const Char* name, const IAttributes* params, Float& value, Bool& error) const = 0;
        /**
         * @brief Get the color value of an attribute by name at level 0.
         * @param name The name of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param value The color return value.
         * @param error The error return value is set to true if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValueByName(const Char* name, const IAttributes* params, Color& value, Bool& error) const = 0;
        /**
         * @brief Get the string value of an attribute by name at level 0.
         * @param name The name of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param value The string return value.
         * @param result An error message is appended to this object if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValueByName(const Char* name, const IAttributes* params, String& value, Result& result) const = 0;
        /**
         * @brief Get the boolean value of an attribute by name at level 0.
         * @param name The name of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param value The boolean return value.
         * @param result An error message is appended to this object if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValueByName(const Char* name, const IAttributes* params, Bool& value, Result& result) const = 0;
        /**
         * @brief Get the unsigned integer value of an attribute by name at level 0.
         * @param name The name of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param value The unsigned integer return value.
         * @param result An error message is appended to this object if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValueByName(const Char* name, const IAttributes* params, UInt32& value, Result& result) const = 0;
        /**
         * @brief Get the signed integer value of an attribute by name at level 0.
         * @param name The name of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param value The signed integer return value.
         * @param result An error message is appended to this object if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValueByName(const Char* name, const IAttributes* params, SInt32& value, Result& result) const = 0;
        /**
         * @brief Get the double value of an attribute by name at level 0.
         * @param name The name of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param value The double return value.
         * @param result An error message is appended to this object if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValueByName(const Char* name, const IAttributes* params, Double& value, Result& result) const = 0;
        /**
         * @brief Get the float value of an attribute by name at level 0.
         * @param name The name of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param value The float return value.
         * @param result An error message is appended to this object if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValueByName(const Char* name, const IAttributes* params, Float& value, Result& result) const = 0;
        /**
         * @brief Get the color value of an attribute by name at level 0.
         * @param name The name of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param value The color return value.
         * @param result An error message is appended to this object if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValueByName(const Char* name, const IAttributes* params, Color& value, Result& result) const = 0;

        /**
         * @brief Get the angle double value of an attribute by name at level 0.
         * @param name The name of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param value The angle double return value.
         * @param error The error return value is set to true if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetAngleValueByName(const Char* name, const IAttributes* params, Double& value, Bool& error) const = 0;
        /**
         * @brief Get the angle float value of an attribute by name at level 0.
         * @param name The name of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param value The angle float return value.
         * @param error The error return value is set to true if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetAngleValueByName(const Char* name, const IAttributes* params, Float& value, Bool& error) const = 0;
        /**
         * @brief Get the color component value of an attribute by name at level 0.
         * @param name The name of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param value The color component return value.
         * @param error The error return value is set to true if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetColorValueByName(const Char* name, const IAttributes* params, Float& value, Bool& error) const = 0;
        /**
         * @brief Get the angle double value of an attribute by name at level 0.
         * @param name The name of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param value The angle double return value.
         * @param result An error message is appended to this object if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetAngleValueByName(const Char* name, const IAttributes* params, Double& value, Result& result) const = 0;
        /**
         * @brief Get the angle float value of an attribute by name at level 0.
         * @param name The name of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param value The angle float return value.
         * @param result An error message is appended to this object if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetAngleValueByName(const Char* name, const IAttributes* params, Float& value, Result& result) const = 0;
        /**
         * @brief Get the color component value of an attribute by name at level 0.
         * @param name The name of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param value The color component return value.
         * @param result An error message is appended to this object if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetColorValueByName(const Char* name, const IAttributes* params, Float& value, Result& result) const = 0;

        /**
         * @brief Get the string values of an attribute by name at level 0.
         * @param name The name of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values The string array return value.
         * @param error The error return value is set to true if data conversion failed.
         * @param clear If true clear the return value array before adding the return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValuesByName(const Char* name, const IAttributes* params, StringArray& values, Bool& error, Bool clear = true) const = 0;
        /**
         * @brief Get the boolean values of an attribute by name at level 0.
         * @param name The name of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values The boolean array return value.
         * @param error The error return value is set to true if data conversion failed.
         * @param clear If true clear the return value array before adding the return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValuesByName(const Char* name, const IAttributes* params, BoolArray& values, Bool& error, Bool clear = true) const = 0;
        /**
         * @brief Get the unsigned integer values of an attribute by name at level 0.
         * @param name The name of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values The unsigned integer array return value.
         * @param error The error return value is set to true if data conversion failed.
         * @param clear If true clear the return value array before adding the return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValuesByName(const Char* name, const IAttributes* params, UInt32Array& values, Bool& error, Bool clear = true) const = 0;
        /**
         * @brief Get the signed integer values of an attribute by name at level 0.
         * @param name The name of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values The signed integer array return value.
         * @param error The error return value is set to true if data conversion failed.
         * @param clear If true clear the return value array before adding the return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValuesByName(const Char* name, const IAttributes* params, SInt32Array& values, Bool& error, Bool clear = true) const = 0;
        /**
         * @brief Get the double values of an attribute by name at level 0.
         * @param name The name of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values The double array return value.
         * @param error The error return value is set to true if data conversion failed.
         * @param clear If true clear the return value array before adding the return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValuesByName(const Char* name, const IAttributes* params, DoubleArray& values, Bool& error, Bool clear = true) const = 0;
        /**
         * @brief Get the float values of an attribute by name at level 0.
         * @param name The name of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values The float array return value.
         * @param error The error return value is set to true if data conversion failed.
         * @param clear If true clear the return value array before adding the return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValuesByName(const Char* name, const IAttributes* params, FloatArray& values, Bool& error, Bool clear = true) const = 0;
        /**
         * @brief Get the string values of an attribute by name at level 0.
         * @param name The name of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values The string array return value.
         * @param result An error message is appended to this object if data conversion failed.
         * @param clear If true clear the return value array before adding the return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValuesByName(const Char* name, const IAttributes* params, StringArray& values, Result& result, Bool clear = true) const = 0;
        /**
         * @brief Get the boolean values of an attribute by name at level 0.
         * @param name The name of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values The boolean array return value.
         * @param result An error message is appended to this object if data conversion failed.
         * @param clear If true clear the return value array before adding the return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValuesByName(const Char* name, const IAttributes* params, BoolArray& values, Result& result, Bool clear = true) const = 0;
        /**
         * @brief Get the unsigned integer values of an attribute by name at level 0.
         * @param name The name of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values The unsigned integer array return value.
         * @param result An error message is appended to this object if data conversion failed.
         * @param clear If true clear the return value array before adding the return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValuesByName(const Char* name, const IAttributes* params, UInt32Array& values, Result& result, Bool clear = true) const = 0;
        /**
         * @brief Get the signed integer values of an attribute by name at level 0.
         * @param name The name of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values The signed integer array return value.
         * @param result An error message is appended to this object if data conversion failed.
         * @param clear If true clear the return value array before adding the return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValuesByName(const Char* name, const IAttributes* params, SInt32Array& values, Result& result, Bool clear = true) const = 0;
        /**
         * @brief Get the double values of an attribute by name at level 0.
         * @param name The name of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values The double array return value.
         * @param result An error message is appended to this object if data conversion failed.
         * @param clear If true clear the return value array before adding the return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValuesByName(const Char* name, const IAttributes* params, DoubleArray& values, Result& result, Bool clear = true) const = 0;
        /**
         * @brief Get the float values of an attribute by name at level 0.
         * @param name The name of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values The float array return value.
         * @param result An error message is appended to this object if data conversion failed.
         * @param clear If true clear the return value array before adding the return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetValuesByName(const Char* name, const IAttributes* params, FloatArray& values, Result& result, Bool clear = true) const = 0;

        /**
         * @brief Get the double angle values of an attribute by name at level 0.
         * @param name The name of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values The double array return value.
         * @param error The error return value is set to true if data conversion failed.
         * @param clear If true clear the return value array before adding the return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetAngleValuesByName(const Char* name, const IAttributes* params, DoubleArray& values, Bool& error, Bool clear = true) const = 0;
        /**
         * @brief Get the float angle values of an attribute by name at level 0.
         * @param name The name of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values The float array return value.
         * @param error The error return value is set to true if data conversion failed.
         * @param clear If true clear the return value array before adding the return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetAngleValuesByName(const Char* name, const IAttributes* params, FloatArray& values, Bool& error, Bool clear = true) const = 0;
        /**
         * @brief Get the double angle values of an attribute by name at level 0.
         * @param name The name of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values The double array return value.
         * @param result An error message is appended to this object if data conversion failed.
         * @param clear If true clear the return value array before adding the return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetAngleValuesByName(const Char* name, const IAttributes* params, DoubleArray& values, Result& result, Bool clear = true) const = 0;
        /**
         * @brief Get the float angle values of an attribute by name at level 0.
         * @param name The name of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param values The float array return value.
         * @param result An error message is appended to this object if data conversion failed.
         * @param clear If true clear the return value array before adding the return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetAngleValuesByName(const Char* name, const IAttributes* params, FloatArray& values, Result& result, Bool clear = true) const = 0;

        /**
         * @brief Get the bit number values of an attribute by name at level 0 and set the bits.
         * @param name The name of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param value The bits return value.
         * @param error The error return value is set to true if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetBitsToSetByName(const Char* name, const IAttributes* params, UInt32& value, Bool& error) const = 0;
        /**
         * @brief Get the bit number values of an attribute by name at level 0 and set the bits.
         * @param name The name of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param value The bits return value.
         * @param result An error message is appended to this object if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        virtual Bool GetBitsToSetByName(const Char* name, const IAttributes* params, UInt32& value, Result& result) const = 0;

        /**
         * @brief Get the enumeration value of an attribute by name at level 0.
         * @param name The name of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param enumClass The enumeration class for looking up the value.
         * @param value The enumeration return value.
         * @param error The error return value is set to true if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        template<class EnumType>
        Bool GetEnumValueByName(const Char* name, const IAttributes* params, const Enum<EnumType>& enumClass,
                                EnumType& value, Bool& error) const
        {
            SInt32 index = GetAttributeIndex(name);
            if (index < 0)
            {
                return false;
            }
            return GetEnumValueByIndex(index, params, enumClass, value, error);
        }
        /**
         * @brief Get the enumeration value of an attribute by name at level 0.
         * @param name The name of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param enumClass The enumeration class for looking up the value.
         * @param value The enumeration return value.
         * @param result An error message is appended to this object if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        template<class EnumType>
        Bool GetEnumValueByName(const Char* name, const IAttributes* params, const Enum<EnumType>& enumClass,
                                EnumType& value, Result& result) const
        {
            SInt32 index = GetAttributeIndex(name);
            if (index < 0)
            {
                return false;
            }
            return GetEnumValueByIndex(index, params, enumClass, value, result);
        }

        /**
         * @brief Get the enumeration values of an attribute by name at level 0.
         * @param name The name of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param enumClass The enumeration class for looking up the value.
         * @param values The enumeration array return value.
         * @param error The error return value is set to true if data conversion failed.
         * @param clear If true clear the return value array before adding the return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        template<class EnumType>
        Bool GetEnumValuesByName(const Char* name, const IAttributes* params, const Enum<EnumType>& enumClass,
                                 Array<EnumType>& values, Bool& error, Bool clear = true) const
        {
            SInt32 index = GetAttributeIndex(name);
            if (index < 0)
            {
                return false;
            }
            return GetEnumValuesByIndex(index, params, enumClass, values, error, clear);
        }
        /**
         * @brief Get the enumeration values of an attribute by name at level 0.
         * @param name The name of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param enumClass The enumeration class for looking up the value.
         * @param values The enumeration array return value.
         * @param result An error message is appended to this object if data conversion failed.
         * @param clear If true clear the return value array before adding the return values.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        template<class EnumType>
        Bool GetEnumValuesByName(const Char* name, const IAttributes* params, const Enum<EnumType>& enumClass,
                                 Array<EnumType>& values, Result& result, Bool clear = true) const
        {
            SInt32 index = GetAttributeIndex(name);
            if (index < 0)
            {
                return false;
            }
            return GetEnumValuesByIndex(index, params, enumClass, values, result, clear);
        }

        /**
         * @brief Get the enumerated bit number values of an attribute by name at level 0 and set the bits.
         * @param name The name of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param enumClass The enumeration class for looking up the value.
         * @param value The bits return value.
         * @param error The error return value is set to true if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        template<class EnumType>
        Bool GetEnumBitsToSetByName(const Char* name, const IAttributes* params, const Enum<EnumType>& enumClass,
                                    UInt32& value, Bool& error) const
        {
            SInt32 index = GetAttributeIndex(name);
            if (index < 0)
            {
                return false;
            }
            return GetEnumBitsToSetByIndex(index, params, enumClass, value, error);
        }
        /**
         * @brief Get the enumerated bit number values of an attribute by name at level 0 and set the bits.
         * @param name The name of the attribute.
         * @param params The attributes for value substituion inside curly braces or null.
         * @param enumClass The enumeration class for looking up the value.
         * @param value The bits return value.
         * @param result An error message is appended to this object if data conversion failed.
         * @return true if successful, false if the attribute index is out of range
         *  or if the attribute has no value or if error is true.
         */
        template<class EnumType>
        Bool GetEnumBitsToSetByName(const Char* name, const IAttributes* params, const Enum<EnumType>& enumClass,
                                    UInt32& value, Result& result) const
        {
            SInt32 index = GetAttributeIndex(name);
            if (index < 0)
            {
                return false;
            }
            return GetEnumBitsToSetByIndex(index, params, enumClass, value, result);
        }
    };
}

#endif // __MURL_I_ATTRIBUTES_H__
