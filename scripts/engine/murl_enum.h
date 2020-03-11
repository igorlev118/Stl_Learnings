// Copyright 2010-2015 Spraylight GmbH

#ifndef __MURL_ENUM_H__
#define __MURL_ENUM_H__

#include "murl_enum_container.h"
#include "murl_util_string.h"

namespace Murl
{
    /**
     * @ingroup MurlEnumerationsClasses
     * @brief Enumeration string mapping template class.
     */
    template<class EnumType>
    class Enum
    {
    public:
        /** @brief The template parameter value type. */
        typedef EnumType ValueType;

        /**
         * @brief Definition of an Enum initialization item.
         */
        struct Item
        {
            /** @brief The name of the value. */
            const Char* mName;
            /** @brief The enumeration value. */
            EnumType mValue;
        };

        /**
         * @brief Constructor taking an array of enum items.
         * @param items Pointer to an array of initialization items.
         *  If the item's mName has a null pointer, the mValue is the default value.
         * @param numberOfElements The number of elements in the array.
         *  The macro NUMBER_OF_ARRAY_ELEMENTS can be used to determine the number.
         */
        Enum(const Item* items, UInt32 numberOfElements)
        : mDefaultValue()
        {
            SetItems(items, numberOfElements);
        }

        /**
         * @brief Constructor taking an enumeration name and an array of enum items.
         * @param name The enumeration's name.
         * @param items Pointer to an array of initialization items.
         *  If the item's mName has a null pointer, the mValue is the default value.
         * @param numberOfElements The number of elements in the array.
         *  The macro NUMBER_OF_ARRAY_ELEMENTS can be used to determine the number.
         */
        Enum(const String& name, const Item* items, UInt32 numberOfElements)
        : mDefaultValue()
        , mName(name)
        {
            SetItems(items, numberOfElements);
        }

        /**
         * @brief Constructor taking an array of enum items and a container.
         * @param name The enumeration's name.
         * @param container The container to add this enumeration to.
         * @param items Pointer to an array of initialization items.
         *  If the item's mName has a null pointer, the mValue is the default value.
         * @param numberOfElements The number of elements in the array.
         *  The macro NUMBER_OF_ARRAY_ELEMENTS can be used to determine the number.
         */
        Enum(const String& name, EnumContainer& container, const Item* items, UInt32 numberOfElements)
        : mDefaultValue()
        , mName(name)
        {
            SetItems(items, numberOfElements);
            container.Add(name, reinterpret_cast<const Enum<SInt32>*>(this));
        }

        /**
         * @brief Get the name of the enumerator.
         * @return The name of the enumerator.
         */
        const String& GetName() const
        {
            return mName;
        }

        /**
         * @brief Get the default enumeration value.
         * @return The default value.
         */
        EnumType GetDefaultValue() const
        {
            return mDefaultValue;
        }

        /**
         * @brief Get the total number of enumeration entries.
         * @return The number of entries.
         */
        UInt32 GetCount() const
        {
            return mItemsByName.GetCount();
        }

        /**
         * @brief Check if an enumeration value is available.
         * @param value The enumeration value to check.
         * @return true if the enumeration value is available.
         */
        Bool IsEnumValueAvailable(EnumType value) const
        {
            SInt32 index = mItemsByValue.Find(value);
            return index >= 0;
        }
        /**
         * @brief Check if an enumeration name is available.
         * @param name The enumeration name to check.
         * @return true if the enumeration name is available.
         */
        Bool IsEnumNameAvailable(const String& name) const
        {
            SInt32 index = mItemsByName.Find(name);
            return index >= 0;
        }

        /**
         * @brief Get the zero-based index of an enumeration value.
         * @param value The enumeration value to check.
         * @return The index in the range from 0 to GetCount()-1, or -1 if not found.
         */
        SInt32 GetEnumIndexByValue(EnumType value) const
        {
            return mItemsByValue.Find(value);
        }
        /**
         * @brief Get the zero-based index of an enumeration value.
         * @param value The enumeration value to check.
         * @param hash The precomputed hash value.
         * @return The index in the range from 0 to GetCount()-1, or -1 if not found.
         */
        SInt32 GetEnumIndexByValue(EnumType value, UInt32 hash) const
        {
            return mItemsByValue.Find(value, hash);
        }

        /**
         * @brief Get the zero-based index of an enumeration name.
         * @param name The enumeration name to check.
         * @return The index in the range from 0 to GetCount()-1, or -1 if not found.
         */
        SInt32 GetEnumIndexByName(const String& name) const
        {
            return mItemsByName.Find(name);
        }
        /**
         * @brief Get the zero-based index of an enumeration name.
         * @param name The enumeration name to check.
         * @param hash The precomputed hash value.
         * @return The index in the range from 0 to GetCount()-1, or -1 if not found.
         */
        SInt32 GetEnumIndexByName(const String& name, UInt32 hash) const
        {
            return mItemsByName.Find(name, hash);
        }

        /**
         * @brief Get the enumeration name at a given index.
         * @param index The index to query, in the range from 0 to GetCount()-1.
         * @return The enumeration name, or an empty string if index is out of range.
         */
        const String& GetEnumNameByIndex(UInt32 index) const
        {
            if (index >= mItemsByValue.GetCount())
            {
                return Util::StaticEmptyString();
            }
            return mItemsByValue[index];
        }

        /**
         * @brief Get the enumeration value at a given index.
         * @param index The index to query, in the range from 0 to GetCount()-1.
         * @return The enumeration value, or the default value if index is out of range.
         */
        EnumType GetEnumValueByIndex(UInt32 index) const
        {
            if (index >= mItemsByName.GetCount())
            {
                return mDefaultValue;
            }
            return mItemsByName[index];
        }

        /**
         * @brief Get the enumeration name for a given enumeration value.
         * @param value The enumeration value to look up.
         * @param error The error return value is set to true if the value is not found.
         * @param clearError If false, the error parameter is left in its given state if no error occurred.
         * @return The string of the enumeration value or
         *  an empty string if the value is not found.
         */
        const String& GetEnumNameByValue(EnumType value, Bool& error, Bool clearError) const
        {
            if (clearError)
            {
                error = false;
            }
            SInt32 index = mItemsByValue.Find(value);
            if (index < 0)
            {
                error = true;
                return Util::StaticEmptyString();
            }
            return mItemsByValue[index];
        }

        /**
         * @brief Get the enumeration name for a given enumeration value.
         * @param value The enumeration value to look up.
         * @param error The error return value is set to true if the value is not found, or false if OK.
         * @return The string of the enumeration value or
         *  an empty string if the value is not found.
         */
        const String& GetEnumNameByValue(EnumType value, Bool& error) const
        {
            return GetEnumNameByValue(value, error, true);
        }

        /**
         * @brief Get the enumeration name for a given enumeration value.
         * @param value The enumeration value to look up.
         * @return The string of the enumeration value or
         *  an empty string if the value is not found.
         */
        const String& GetEnumNameByValue(EnumType value) const
        {
            Bool error;
            return GetEnumNameByValue(value, error, true);
        }

        /**
         * @brief Get the enumeration value for a given enumeration name.
         * @param name The name string to look up.
         * @param error The error return value is set to true if the name is not found.
         * @param clearError If false, the error parameter is left in its given state if no error occurred.
         * @return The enumeration value of the string or the
         *  default value if the string is not found.
         */
        EnumType GetEnumValueByName(const String& name, Bool& error, Bool clearError) const
        {
            if (clearError)
            {
                error = false;
            }
            SInt32 index = mItemsByName.Find(name);
            if (index < 0)
            {
                error = true;
                return mDefaultValue;
            }
            return static_cast<EnumType>(mItemsByName[index]);
        }

        /**
         * @brief Get the enumeration value for a given enumeration name.
         * @param name The name string to look up.
         * @param error The error return value is set to true if the value is not found, or false if OK.
         * @return The enumeration value of the string or the
         *  default value if the string is not found.
         */
        EnumType GetEnumValueByName(const String& name, Bool& error) const
        {
            return GetEnumValueByName(name, error, true);
        }

        /**
         * @brief Get the enumeration value for a given enumeration name.
         * @param name The name string to look up.
         * @return The enumeration value of the string or the
         *  default value if the string is not found.
         */
        EnumType GetEnumValueByName(const String& name) const
        {
            Bool error;
            return GetEnumValueByName(name, error, true);
        }

        /**
         * @brief Get the enumeration name for a given enumeration value, using a precomputed
         * hash value.
         * @param value The enumeration value to look up.
         * @param hash The precomputed hash value.
         * @param error The error return value is set to true if the value is not found.
         * @param clearError If false, the error parameter is left in its given state if no error occurred.
         * @return The string of the enumeration value or
         *  an empty string if the value is not found.
         */
        const String& GetEnumNameByValue(EnumType value, UInt32 hash, Bool& error, Bool clearError) const
        {
            if (clearError)
            {
                error = false;
            }
            SInt32 index = mItemsByValue.Find(value, hash);
            if (index < 0)
            {
                error = true;
                return Util::StaticEmptyString();
            }
            return mItemsByValue[index];
        }

        /**
         * @brief Get the enumeration name for a given enumeration value, using a precomputed
         * hash value.
         * @param value The enumeration value to look up.
         * @param hash The precomputed hash value.
         * @param error The error return value is set to true if the value is not found, or false if OK.
         * @return The string of the enumeration value or
         *  an empty string if the value is not found.
         */
        const String& GetEnumNameByValue(EnumType value, UInt32 hash, Bool& error) const
        {
            return GetEnumNameByValue(value, hash, error, true);
        }

        /**
         * @brief Get the enumeration name for a given enumeration value, using a precomputed
         * hash value.
         * @param value The enumeration value to look up.
         * @param hash The precomputed hash value.
         * @return The string of the enumeration value or
         *  an empty string if the value is not found.
         */
        const String& GetEnumNameByValue(EnumType value, UInt32 hash) const
        {
            Bool error;
            return GetEnumNameByValue(value, hash, error, true);
        }

        /**
         * @brief Get the enumeration value for a given enumeration name, using a precomputed
         * hash value.
         * @param name The name string to look up.
         * @param hash The precomputed hash value.
         * @param error The error return value is set to true if the name is not found.
         * @param clearError If false, the error parameter is left in its given state if no error occurred.
         * @return The enumeration value of the string or the
         *  default value if the string is not found.
         */
        EnumType GetEnumValueByName(const String& name, UInt32 hash, Bool& error, Bool clearError) const
        {
            if (clearError)
            {
                error = false;
            }
            SInt32 index = mItemsByName.Find(name, hash);
            if (index < 0)
            {
                error = true;
                return mDefaultValue;
            }
            return static_cast<EnumType>(mItemsByName[index]);
        }

        /**
         * @brief Get the enumeration value for a given enumeration name, using a precomputed
         * hash value.
         * @param name The name string to look up.
         * @param hash The precomputed hash value.
         * @param error The error return value is set to true if the value is not found, or false if OK.
         * @return The enumeration value of the string or the
         *  default value if the string is not found.
         */
        EnumType GetEnumValueByName(const String& name, UInt32 hash, Bool& error) const
        {
            return GetEnumValueByName(name, hash, error, true);
        }

        /**
         * @brief Get the enumeration value for a given enumeration name, using a precomputed
         * hash value.
         * @param name The name string to look up.
         * @param hash The precomputed hash value.
         * @return The enumeration value of the string or the
         *  default value if the string is not found.
         */
        EnumType GetEnumValueByName(const String& name, UInt32 hash) const
        {
            Bool error;
            return GetEnumValueByName(name, hash, error, true);
        }

        /**
         * @brief Get the enumeration values by name map.
         * @return The enumeration values by name map.
         */
        const Map<String, UInt32>& GetItemsByName() const
        {
            return mItemsByName;
        }

        /**
         * @brief Get the names by enumeration value map.
         * @return The names by enumeration value map.
         */
        const Map<UInt32, String>& GetItemsByValue() const
        {
            return mItemsByValue;
        }

        /**
         * @brief Conversion operator.
         * @return This Enum instance with SInt32 specialization.
         */
        operator const Enum<SInt32>&() const
        {
            return *reinterpret_cast<const Enum<SInt32>*>(this);
        }

    protected:
        void SetItems(const Item* items, UInt32 numberOfElements)
        {
            for (UInt32 i = 0; i < numberOfElements; i++)
            {
                if (items[i].mName != 0)
                {
                    mItemsByName.Add(items[i].mName, UInt32(items[i].mValue));
                    mItemsByValue.Add(UInt32(items[i].mValue), items[i].mName);
                }
                else
                {
                    mDefaultValue = items[i].mValue;
                }
            }
        }

        /** @brief The enumeration values by name map. */
        Map<String, UInt32> mItemsByName;
        /** @brief The names by enumeration value map. */
        Map<UInt32, String> mItemsByValue;
        /** @brief The default enumeration value. */
        EnumType mDefaultValue;
        /** @brief The name of the enumerator. */
        String mName;
    };
}

/**
 * @ingroup MurlEnumerationsClasses
 * @{
 */

/**
 * @brief Declare an enumeration entry.
 * Creates "prefix##_##name,".
 * @param prefix The prefix of the entry.
 * @param name The name of the entry.
 */
#define MURL_DECLARE_ENUM_VALUE(prefix, name) \
prefix##_##name,

/**
 * @brief Declare an enumeration entry with a value.
 * Creates "prefix##_##name = value,".
 * @param prefix The prefix of the entry.
 * @param name The name of the entry.
 * @param value The value of the entry.
 */
#define MURL_DECLARE_ENUM_VALUE_PREDEFINED(prefix, name, value) \
prefix##_##name = value,

/**
 * @brief Declare an enumeration string mapping accessor.
 * Creates "const Enum<name>& Get##name##Enum();".
 * @param name The name of the enumerator.
 */
#define MURL_DECLARE_ENUM_ACCESSOR(name) \
const Murl::Enum<name>& Get##name##Enum();

/**
 * @brief Start defining a Enum::Item array.
 * @param name The name of the enumerator.
 */
#define MURL_DEFINE_ENUM_BEGIN(name) \
static const Murl::Enum<name>::Item s##name##Items[] =

/**
 * @brief Define a Enum::Item array entry.
 * @param prefix The prefix of the enumeration value.
 * @param name The name of the enumeration value and the string.
 */
#define MURL_DEFINE_ENUM_ITEM(prefix, name) \
{ #name, prefix##_##name },

/**
 * @brief Define the default Enum::Item array.
 * @param defaultName The name of the default enumeration value.
 */
#define MURL_DEFINE_ENUM_ITEM_DEFAULT(defaultName) \
{ 0, defaultName }

/**
 * @brief Create an instance of the enumeration string mapping class
 *  and a getter method "Get##name##Enum()".
 * @param name The name of the enumerator.
 */
#define MURL_DEFINE_ENUM_END(name) \
static const Murl::Enum<name> s##name##Enum(#name, StaticEnumContainer::Get(), s##name##Items, NUMBER_OF_ARRAY_ELEMENTS(s##name##Items)); \
const Murl::Enum<name>& Get##name##Enum() \
{ \
return s##name##Enum; \
}

/**
 * @brief Get the number of array elements.
 * @param name The name of the array.
 */
#define NUMBER_OF_ARRAY_ELEMENTS(name) (sizeof(name) / sizeof(*name))

/** @} */

#endif  // __MURL_ENUM_H__
