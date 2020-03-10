// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_PROPERTY_INFO_H__
#define __MURL_PROPERTY_INFO_H__

#include "murl_i_enums.h"

namespace Murl
{
    /**
     * @ingroup MurlClasses
     * @brief A container for storing property information about a class.
     * This class holds an array of individual items each describing a single
     * object property, which is essentially a single class member encapsulating
     * one or more variable elements, which in turn can consist of one or more
     * individual components. For example, a Graph::VectorFieldProperty stores
     * a fixed-size array of NUM_ELEMENTS individual Graph::Vector instances,
     * each of which has 4 components.
     * See also Murl::IFactoryObject and Murl::AttributeInfo.
     */
    class PropertyInfo
    {
    public:
        /**
         * @brief A single property information item.
         */
        struct Item
        {
            /** @brief The property ID. */
            UInt32 mId;
            /** @brief A human-readable string representing the property's variable type. */
            String mTypeName;

            /** @brief The property value semantic. */
            IEnums::PropertySemantic mSemantic;
            /** @brief The number of individual components, e.g. 4 for a Graph::Vector. */
            UInt32 mNumComponents;
            /** @brief The minimum number of elements the property can store. */
            UInt32 mMinCapacity;
            /** @brief The maximum number of elements the property can store. */
            UInt32 mMaxCapacity;
            /** @brief The minimum number of required elements. */
            UInt32 mMinRequired;
            /** @brief The maximum number of required elements. */
            UInt32 mMaxRequired;

            /** @brief The default string values. Accessed using mDefaultValue[elementIndex][componentIndex]. */
            Array<Array<String> > mDefaultValue;

            /** @brief Optional value enumeration. */
            const Enum<SInt32>* mEnum;
        };

        /**
         * @brief The constructor.
         * @param items An array of pointers to individual property info items.
         * @param numberOfItems The number of items in the array.
         */
        PropertyInfo(const Item** items, UInt32 numberOfItems)
        {
            for (UInt32 i = 0; i < numberOfItems; i++)
            {
                if (items[i] != 0)
                {
                    mItemsById.Add(items[i]->mId, items[i]);
                    mItemsByName.Add(items[i]->mTypeName, items[i]);
                }
            }
        }

        /**
         * @brief Get the number of items.
         * @return The number of items.
         */
        UInt32 GetNumberOfItems() const
        {
            return mItemsById.GetCount();
        }

        /**
         * @brief Get a single item by its index.
         * @param index The item index, from 0 to GetNumberOfItems()-1.
         * @return The item, or null if index is out of range.
         */
        const Item* GetItemByIndex(UInt32 index) const
        {
            if (index >= mItemsById.GetCount())
            {
                return 0;
            }
            return mItemsById[index];
        }

        /**
         * @brief Get a single item by its ID.
         * @param id The ID to search for.
         * @return The item, or null if the given ID was not found.
         */
        const Item* GetItemById(UInt32 id) const
        {
            SInt32 index = mItemsById.Find(id);
            if (index < 0)
            {
                return 0;
            }
            return mItemsById[index];
        }

        /**
         * @brief Get a single item by its name.
         * @param name The name to search for.
         * @return The item, or null if the given name was not found.
         */
        const Item* GetItemByName(const String& name) const
        {
            SInt32 index = mItemsByName.Find(name);
            if (index < 0)
            {
                return 0;
            }
            return mItemsByName[index];
        }

        /**
         * @brief Get the ID of an item by its name.
         * @param name The name to search for.
         * @param hash The name string's hash value.
         * @return The ID, 0xffffffff if the name was not found.
         */
        UInt32 GetIdByNameAndHash(const String& name, UInt32 hash) const
        {
            SInt32 index = mItemsByName.Find(name, hash);
            if (index < 0)
            {
                return UInt32(-1);
            }
            return mItemsByName[index]->mId;
        }

    protected:
        Map<UInt32, const Item*> mItemsById;
        Map<String, const Item*> mItemsByName;
    };
}

#endif  // __MURL_PROPERTY_INFO_H__
