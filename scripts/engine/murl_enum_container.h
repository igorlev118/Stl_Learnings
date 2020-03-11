// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_ENUM_CONTAINER_H__
#define __MURL_ENUM_CONTAINER_H__

#include "murl_map.h"
#include "murl_string.h"

namespace Murl
{
    template<class EnumType>
    class Enum;

    /**
     * @ingroup MurlEnumerationsClasses
     * @brief A container holding individual enumeration objects by name.
     */
    class EnumContainer
    {
    public:
        /**
         * @brief Constructor taking a namespace name.
         * @param nmspc The namespace the container resides in.
         */
        EnumContainer(const String& nmspc);
        /**
         * @brief Constructor taking a namespace name and a parent container.
         * @param nmspc The namespace the container resides in.
         * @param parent The parent enum container.
         */
        EnumContainer(const String& nmspc, EnumContainer& parent);

        /**
         * @brief Get the container's namespace.
         * @return The namespace.
         */
        String GetNamespace() const;

        /**
         * @brief Add an enumeration object.
         * @param name The name of the object.
         * @param e The enumeration object.
         * @return true if successful.
         */
        Bool Add(const String& name, const Enum<SInt32>* e);

        /**
         * @brief Try to get an enumeration object by its name.
         * @param scopedName The name to query.
         * @return A pointer to the enumeration object, or null if not found.
         */
        const Enum<SInt32>* Find(const String& scopedName) const;

        /**
         * @brief Get the number of enumeration objects in the container.
         * @return The number of registered objects.
         */
        UInt32 GetCount() const;

        /**
         * @brief Get the name of an enumeration object at a given index.
         * @param index The index, from 0 to GetCount()-1.
         * @return The object name, or an empty string if index is out of range.
         */
        String GetName(UInt32 index) const;

        /**
         * @brief Get the enumeration object at a given index.
         * @param index The index, from 0 to GetCount()-1.
         * @return The object, or null if index is out of range.
         */
        const Enum<SInt32>* Get(UInt32 index) const;

    private:
        String mNamespace;
        Map<String, const Enum<SInt32>*> mEnums;
        Array<EnumContainer*> mChildren;
    };

    /**
     * @ingroup MurlEnumerationsClasses
     * @brief The static enum container in the Murl namespace.
     */
    class StaticEnumContainer
    {
    public:
        /**
         * @brief Get the static enum container.
         * @return A reference to the container.
         */
        static EnumContainer& Get();
    };
}

#endif  // __MURL_ENUM_CONTAINER_H__
