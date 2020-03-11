// Copyright 2010-2013 Spraylight GmbH

#ifndef __MURL_UTIL_ATTRIBUTES_H__
#define __MURL_UTIL_ATTRIBUTES_H__

#include "murl_util_attributes_base.h"
#include "murl_auto_pointer.h"
#include "murl_index.h"

namespace Murl
{
    namespace Util
    {
        /**
         * @ingroup MurlUtilClasses
         * @brief The attributes class, see IAttributes.
         */
        class Attributes : public AttributesBase
        {
        public:
            /**
             * @brief The default constructor.
             */
            Attributes();
            /**
             * @brief Constructor taking a string array.
             * The first array element contains the attribute name and the
             * second array element contains the corresponding attribute value.
             * The array must be terminated by a null pointer in the last element.
             * @param attributes The string array containing name and value pairs.
             */
            Attributes(const Char** attributes);
            /**
             * @brief Constructor copying attributes with option.
             * @param other The attributes to copy.
             * @param unusedOnly Copy unused attributes only if true.
             */
            Attributes(const IAttributes* other, Bool unusedOnly = false);
            /**
             * @brief Constructor copying attributes.
             * @param base The attributes to copy.
             * @param additional The additional attributes to copy.
             */
            Attributes(const IAttributes* base, const IAttributes* additional);
            /**
             * @brief The destructor.
             */
            virtual ~Attributes();
            
            virtual Bool Clear();

            virtual Bool AddDefaults(const IAttributes* defaultAttributes);
            virtual UInt32 GetNumberOfDefaults() const;
            virtual const IAttributes* GetDefaults(UInt32 index) const;

            virtual Bool AddAttribute(const String& fullName, const String& value);
            virtual Bool SetAttribute(const String& fullName, const String& value);
            
            virtual UInt32 GetNumberOfAttributes() const;
            
            virtual UInt32 GetAttributeHash(UInt32 index, UInt32 level = 0) const;
            virtual const Char* GetAttributeName(UInt32 index, UInt32 level = 0) const;
            virtual const Char* GetAttributeValue(UInt32 index, UInt32 level = 0) const;
            virtual String GetFullAttributeName(UInt32 index) const;
            virtual const Char* GetFullAttributeValue(UInt32 index) const;
            virtual SInt32 GetAttributeIndex(const char* name) const;
            virtual SInt32 GetFullAttributeIndex(const char* fullName) const;

            virtual SInt32 GetAttributeParent(UInt32 index) const;
            virtual UInt32 GetAttributeLevel(UInt32 index) const;
            virtual Bool IsAttributeUsed(UInt32 index) const;
            virtual Bool HasAttributeValue(UInt32 index) const;
            
            virtual UInt32 GetNumberOfUnusedAttributes() const;
            virtual Bool GetUnusedAttributeNames(StringArray& names) const;
            
            virtual Bool SetAllAttributesUsed() const;
            
            virtual Bool GetValueByIndex(UInt32 index, const IAttributes* params, String& value, Bool& error) const;
            virtual Bool GetValueByIndex(UInt32 index, const IAttributes* params, Bool& value, Bool& error) const;
            virtual Bool GetValueByIndex(UInt32 index, const IAttributes* params, UInt32& value, Bool& error) const;
            virtual Bool GetValueByIndex(UInt32 index, const IAttributes* params, SInt32& value, Bool& error) const;
            virtual Bool GetValueByIndex(UInt32 index, const IAttributes* params, Double& value, Bool& error) const;
            virtual Bool GetValueByIndex(UInt32 index, const IAttributes* params, Float& value, Bool& error) const;
            virtual Bool GetValueByIndex(UInt32 index, const IAttributes* params, Color& value, Bool& error) const;
            virtual Bool GetValueByIndex(UInt32 index, const IAttributes* params, String& value, Result& result) const;
            virtual Bool GetValueByIndex(UInt32 index, const IAttributes* params, Bool& value, Result& result) const;
            virtual Bool GetValueByIndex(UInt32 index, const IAttributes* params, UInt32& value, Result& result) const;
            virtual Bool GetValueByIndex(UInt32 index, const IAttributes* params, SInt32& value, Result& result) const;
            virtual Bool GetValueByIndex(UInt32 index, const IAttributes* params, Double& value, Result& result) const;
            virtual Bool GetValueByIndex(UInt32 index, const IAttributes* params, Float& value, Result& result) const;
            virtual Bool GetValueByIndex(UInt32 index, const IAttributes* params, Color& value, Result& result) const;

            virtual Bool GetAngleValueByIndex(UInt32 index, const IAttributes* params, Double& value, Bool& error) const;
            virtual Bool GetAngleValueByIndex(UInt32 index, const IAttributes* params, Float& value, Bool& error) const;
            virtual Bool GetColorValueByIndex(UInt32 index, const IAttributes* params, Float& value, Bool& error) const;
            virtual Bool GetAngleValueByIndex(UInt32 index, const IAttributes* params, Double& value, Result& result) const;
            virtual Bool GetAngleValueByIndex(UInt32 index, const IAttributes* params, Float& value, Result& result) const;
            virtual Bool GetColorValueByIndex(UInt32 index, const IAttributes* params, Float& value, Result& result) const;

            virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, StringArray& values, Bool& error, Bool clear = true) const;
            virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, BoolArray& values, Bool& error, Bool clear = true) const;
            virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, UInt32Array& values, Bool& error, Bool clear = true) const;
            virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, SInt32Array& values, Bool& error, Bool clear = true) const;
            virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, DoubleArray& values, Bool& error, Bool clear = true) const;
            virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, FloatArray& values, Bool& error, Bool clear = true) const;
            virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, StringArray& values, Result& result, Bool clear = true) const;
            virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, BoolArray& values, Result& result, Bool clear = true) const;
            virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, UInt32Array& values, Result& result, Bool clear = true) const;
            virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, SInt32Array& values, Result& result, Bool clear = true) const;
            virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, DoubleArray& values, Result& result, Bool clear = true) const;
            virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, FloatArray& values, Result& result, Bool clear = true) const;

            virtual Bool GetAngleValuesByIndex(UInt32 index, const IAttributes* params, DoubleArray& values, Bool& error, Bool clear = true) const;
            virtual Bool GetAngleValuesByIndex(UInt32 index, const IAttributes* params, FloatArray& values, Bool& error, Bool clear = true) const;
            virtual Bool GetAngleValuesByIndex(UInt32 index, const IAttributes* params, DoubleArray& values, Result& result, Bool clear = true) const;
            virtual Bool GetAngleValuesByIndex(UInt32 index, const IAttributes* params, FloatArray& values, Result& result, Bool clear = true) const;

            virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, String* values, UInt32 maxValues, Bool& error, UInt32* numValues) const;
            virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, Bool* values, UInt32 maxValues, Bool& error, UInt32* numValues) const;
            virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, UInt32* values, UInt32 maxValues, Bool& error, UInt32* numValues) const;
            virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, SInt32* values, UInt32 maxValues, Bool& error, UInt32* numValues) const;
            virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, Double* values, UInt32 maxValues, Bool& error, UInt32* numValues) const;
            virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, Float* values, UInt32 maxValues, Bool& error, UInt32* numValues) const;
            virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, String* values, UInt32 maxValues, Result& result, UInt32* numValues) const;
            virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, Bool* values, UInt32 maxValues, Result& result, UInt32* numValues) const;
            virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, UInt32* values, UInt32 maxValues, Result& result, UInt32* numValues) const;
            virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, SInt32* values, UInt32 maxValues, Result& result, UInt32* numValues) const;
            virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, Double* values, UInt32 maxValues, Result& result, UInt32* numValues) const;
            virtual Bool GetValuesByIndex(UInt32 index, const IAttributes* params, Float* values, UInt32 maxValues, Result& result, UInt32* numValues) const;

            virtual Bool GetAngleValuesByIndex(UInt32 index, const IAttributes* params, Double* values, UInt32 maxValues, Bool& error, UInt32* numValues) const;
            virtual Bool GetAngleValuesByIndex(UInt32 index, const IAttributes* params, Float* values, UInt32 maxValues, Bool& error, UInt32* numValues) const;
            virtual Bool GetAngleValuesByIndex(UInt32 index, const IAttributes* params, Double* values, UInt32 maxValues, Result& result, UInt32* numValues) const;
            virtual Bool GetAngleValuesByIndex(UInt32 index, const IAttributes* params, Float* values, UInt32 maxValues, Result& result, UInt32* numValues) const;

            virtual Bool GetBitsToSetByIndex(UInt32 index, const IAttributes* params, UInt32& value, Bool& error) const;
            virtual Bool GetBitsToSetByIndex(UInt32 index, const IAttributes* params, UInt32& value, Result& result) const;

            virtual Bool GetValueByName(const Char* name, const IAttributes* params, String& value, Bool& error) const;
            virtual Bool GetValueByName(const Char* name, const IAttributes* params, Bool& value, Bool& error) const;
            virtual Bool GetValueByName(const Char* name, const IAttributes* params, UInt32& value, Bool& error) const;
            virtual Bool GetValueByName(const Char* name, const IAttributes* params, SInt32& value, Bool& error) const;
            virtual Bool GetValueByName(const Char* name, const IAttributes* params, Double& value, Bool& error) const;
            virtual Bool GetValueByName(const Char* name, const IAttributes* params, Float& value, Bool& error) const;
            virtual Bool GetValueByName(const Char* name, const IAttributes* params, Color& value, Bool& error) const;
            virtual Bool GetValueByName(const Char* name, const IAttributes* params, String& value, Result& result) const;
            virtual Bool GetValueByName(const Char* name, const IAttributes* params, Bool& value, Result& result) const;
            virtual Bool GetValueByName(const Char* name, const IAttributes* params, UInt32& value, Result& result) const;
            virtual Bool GetValueByName(const Char* name, const IAttributes* params, SInt32& value, Result& result) const;
            virtual Bool GetValueByName(const Char* name, const IAttributes* params, Double& value, Result& result) const;
            virtual Bool GetValueByName(const Char* name, const IAttributes* params, Float& value, Result& result) const;
            virtual Bool GetValueByName(const Char* name, const IAttributes* params, Color& value, Result& result) const;

            virtual Bool GetAngleValueByName(const Char* name, const IAttributes* params, Double& value, Bool& error) const;
            virtual Bool GetAngleValueByName(const Char* name, const IAttributes* params, Float& value, Bool& error) const;
            virtual Bool GetColorValueByName(const Char* name, const IAttributes* params, Float& value, Bool& error) const;
            virtual Bool GetAngleValueByName(const Char* name, const IAttributes* params, Double& value, Result& result) const;
            virtual Bool GetAngleValueByName(const Char* name, const IAttributes* params, Float& value, Result& result) const;
            virtual Bool GetColorValueByName(const Char* name, const IAttributes* params, Float& value, Result& result) const;

            virtual Bool GetValuesByName(const Char* name, const IAttributes* params, StringArray& values, Bool& error, Bool clear = true) const;
            virtual Bool GetValuesByName(const Char* name, const IAttributes* params, BoolArray& values, Bool& error, Bool clear = true) const;
            virtual Bool GetValuesByName(const Char* name, const IAttributes* params, UInt32Array& values, Bool& error, Bool clear = true) const;
            virtual Bool GetValuesByName(const Char* name, const IAttributes* params, SInt32Array& values, Bool& error, Bool clear = true) const;
            virtual Bool GetValuesByName(const Char* name, const IAttributes* params, DoubleArray& values, Bool& error, Bool clear = true) const;
            virtual Bool GetValuesByName(const Char* name, const IAttributes* params, FloatArray& values, Bool& error, Bool clear = true) const;
            virtual Bool GetValuesByName(const Char* name, const IAttributes* params, StringArray& values, Result& result, Bool clear = true) const;
            virtual Bool GetValuesByName(const Char* name, const IAttributes* params, BoolArray& values, Result& result, Bool clear = true) const;
            virtual Bool GetValuesByName(const Char* name, const IAttributes* params, UInt32Array& values, Result& result, Bool clear = true) const;
            virtual Bool GetValuesByName(const Char* name, const IAttributes* params, SInt32Array& values, Result& result, Bool clear = true) const;
            virtual Bool GetValuesByName(const Char* name, const IAttributes* params, DoubleArray& values, Result& result, Bool clear = true) const;
            virtual Bool GetValuesByName(const Char* name, const IAttributes* params, FloatArray& values, Result& result, Bool clear = true) const;

            virtual Bool GetAngleValuesByName(const Char* name, const IAttributes* params, DoubleArray& values, Bool& error, Bool clear = true) const;
            virtual Bool GetAngleValuesByName(const Char* name, const IAttributes* params, FloatArray& values, Bool& error, Bool clear = true) const;
            virtual Bool GetAngleValuesByName(const Char* name, const IAttributes* params, DoubleArray& values, Result& result, Bool clear = true) const;
            virtual Bool GetAngleValuesByName(const Char* name, const IAttributes* params, FloatArray& values, Result& result, Bool clear = true) const;

            virtual Bool GetBitsToSetByName(const Char* name, const IAttributes* params, UInt32& value, Bool& error) const;
            virtual Bool GetBitsToSetByName(const Char* name, const IAttributes* params, UInt32& value, Result& result) const;

        private:
            class ValueItem
            {
            public:
                typedef AutoPointer<ValueItem> AutoPtr;
                
                ValueItem(const String& name, const String& value, UInt32 level, SInt32 parentIndex)
                : mLevel(level)
                , mParentIndex(parentIndex)
                , mName(name)
                , mValue(value)
                , mIsUsed(false)
                , mIsValueSet(true)
                {
                }
                
                ValueItem(const String& name, UInt32 level, SInt32 parentIndex)
                : mLevel(level)
                , mParentIndex(parentIndex)
                , mName(name)
                , mIsUsed(false)
                , mIsValueSet(false)
                {
                }
                
                UInt32 mLevel;
                SInt32 mParentIndex;
                
                String mName;
                String mValue;
                Bool mIsUsed;
                Bool mIsValueSet;
            };
            
            Bool AddAttributeRecursive(const String& name, const String& value);
            SInt32 GetLevelIndex(SInt32 index, UInt32 level) const;
            SInt32 GetAttributeRecursive(const String& name, SInt32 level, SInt32 parentIndex) const;

            template<class DataType>
            Bool GetValueByNameInternal(const Char* name, const IAttributes* params, DataType& value, Bool& error) const;
            template<class DataType>
            Bool GetValueByNameInternal(const Char* name, const IAttributes* params, DataType& value, Result& result) const;

            template<class DataType>
            Bool GetAngleValueByNameInternal(const Char* name, const IAttributes* params, DataType& value, Bool& error) const;
            template<class DataType>
            Bool GetAngleValueByNameInternal(const Char* name, const IAttributes* params, DataType& value, Result& result) const;

            template<class DataType>
            Bool GetColorValueByNameInternal(const Char* name, const IAttributes* params, DataType& value, Bool& error) const;
            template<class DataType>
            Bool GetColorValueByNameInternal(const Char* name, const IAttributes* params, DataType& value, Result& result) const;

            template<class DataType>
            Bool GetValuesByNameInternal(const Char* name, const IAttributes* params, DataType& value, Bool& error, Bool clear) const;
            template<class DataType>
            Bool GetValuesByNameInternal(const Char* name, const IAttributes* params, DataType& value, Result& result, Bool clear) const;

            template<class DataType>
            Bool GetAngleValuesByNameInternal(const Char* name, const IAttributes* params, DataType& value, Bool& error, Bool clear) const;
            template<class DataType>
            Bool GetAngleValuesByNameInternal(const Char* name, const IAttributes* params, DataType& value, Result& result, Bool clear) const;

            template<class DataType>
            Bool GetBitsToSetByNameInternal(const Char* name, const IAttributes* params, DataType& value, Bool& error) const;
            template<class DataType>
            Bool GetBitsToSetByNameInternal(const Char* name, const IAttributes* params, DataType& value, Result& result) const;

            Map<String, ValueItem::AutoPtr> mAttributes;
            Map<String, UInt32> mAttributeIndices;
            mutable UInt32 mNumAttributesUsed;

            Index<const IAttributes*> mDefaults;
        };
    }
}

#endif // __MURL_UTIL_ATTRIBUTES_H__
