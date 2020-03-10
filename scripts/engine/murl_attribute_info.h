// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_ATTRIBUTE_INFO_H__
#define __MURL_ATTRIBUTE_INFO_H__

#include "murl_property_info.h"
#include "murl_macros.h"

namespace Murl
{
    /**
     * @ingroup MurlClasses
     * @brief A container for storing attribute information about a class.
     * This class holds an array of individual items each describing a single
     * object attribute, which is used e.g. in XML graph nodes. An attribute
     * usually (but not necessarily) refers to a single object property
     * (see Murl::PropertyInfo). It describes which elements or components
     * of that property are modified when the attribute is set.
     * See also Murl::IFactoryObject.
     */
    class AttributeInfo
    {
    public:
        /**
         * @brief A single attribute information item.
         */
        struct Item
        {
            /** @brief The attribute ID. */
            UInt32 mId;
            /** @brief The attribute name. */
            String mName;

            /** @brief The ID of the property this attribute refers to, or -1 if not used. */
            SInt32 mPropertyId;
            /** @brief The bit mask of affected property components for multi-component types. */
            UInt32 mComponents;
            /** @brief Access mode into the given components. */
            UInt32 mAccess;
            /** @brief The index of an individual element of a collection, or -1 for all elements. */
            SInt32 mElement;
        };

        /**
         * @brief The constructor.
         * @param items An array of individual attribute info items. Must be delimited by
         *      an item with the highest ID in the array and an empty name.
         * @param numberOfItems The number of items in the array, including the terminating
         *      item.
         */
        AttributeInfo(const Item* items, UInt32 numberOfItems)
        : mUnknownId(0)
        {
            for (UInt32 i = 0; i < numberOfItems; i++)
            {
                if (!items[i].mName.IsEmpty())
                {
                    mItemsById.Add(items[i].mId, &items[i]);
                    mItemsByName.Add(items[i].mName, &items[i]);
                }
                else
                {
                    mUnknownId = items[i].mId;
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
         * @return The ID, or the ID of the terminating element if the name was not found.
         */
        UInt32 GetIdByNameAndHash(const String& name, UInt32 hash) const
        {
            SInt32 index = mItemsByName.Find(name, hash);
            if (index < 0)
            {
                return mUnknownId;
            }
            return mItemsByName[index]->mId;
        }

        /**
         * @brief Get a single item's name by its ID.
         * @param id The ID to search for.
         * @return The item name, or an empty string if the given ID was not found.
         */
        String GetNameById(UInt32 id) const
        {
            SInt32 index = mItemsById.Find(id);
            if (index < 0)
            {
                return "";
            }
            return mItemsById[index]->mName;
        }

    protected:
        Map<UInt32, const Item*> mItemsById;
        Map<String, const Item*> mItemsByName;
        UInt32 mUnknownId;
    };
}

#endif  // __MURL_ATTRIBUTE_INFO_H__
