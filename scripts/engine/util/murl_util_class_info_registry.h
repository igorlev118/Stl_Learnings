// Copyright 2011-2012 Spraylight GmbH

#ifndef __MURL_UTIL_CLASS_INFO_REGISTRY_H__
#define __MURL_UTIL_CLASS_INFO_REGISTRY_H__

#include "murl_util_string.h"
#include "murl_map.h"

namespace Murl
{
    namespace Util
    {
        /**
         * @ingroup MurlUtilClasses
         * @brief The class info registration container.
         * Objects derived from IFactoryObject can be registered.
         */
        template<class ClassInfoType>
        class ClassInfoRegistry
        {
        public:
            /**
             * @brief Register a class info object.
             * @param classInfo The class info object to register.
             * @return true if successful or false if a object's class name is already registered.
             */
            Bool Register(const ClassInfoType& classInfo)
            {
                String className = classInfo.GetClassName();
                if (className.IsEmpty())
                {
                    return false;
                }
                if (mClassInfos.Find(className) >= 0)
                {
                    return false;
                }
                
                while (!className.IsEmpty())
                {
                    mClassInfos.Add(className, &classInfo);
                    className = Util::StripCppScope(className);
                }
                
                return true;
            }
            
            /**
             * @brief Unregister a class info object.
             * @param classInfo The class info object to unregister.
             * @return true if successful or false if the object's class name is not registered.
             */
            Bool Unregister(const ClassInfoType& classInfo)
            {
                String className = classInfo.GetClassName();
                SInt32 index = mClassInfos.Find(className);
                if (index < 0)
                {
                    return false;
                }
                
                while (index >= 0)
                {
                    while ((mClassInfos[index] != &classInfo) && (index >= 0))
                    {
                        index = mClassInfos.FindNext(index);
                    }
                    if (index >= 0)
                    {
                        mClassInfos.Remove(index);
                    }

                    className = Util::StripCppScope(className);
                    if (className.IsEmpty())
                    {
                        break;
                    }
                    index = mClassInfos.Find(className);
                }
                
                return true;
            }
            
            /**
             * @brief Get the index of a registered class info object.
             * @param classInfo The class info object.
             * @return The zero-based index or false if the object's class name is not registered.
             */
            SInt32 GetIndex(const ClassInfoType& classInfo) const
            {
                return mClassInfos.Find(classInfo.GetClassName());
            }
            
            /**
             * @brief Get the index of a registered class info object by name.
             * @param className The class name of the object.
             * @return The zero-based index or false if the class name is not registered.
             */
            SInt32 GetIndex(const String& className) const
            {
                return mClassInfos.Find(className);
            }
            
            /**
             * @brief Get the number of registered class info objects.
             * @return The number of registered class info objects.
             */
            UInt32 GetCount() const
            {
                return mClassInfos.GetCount();
            }
            
            /**
             * @brief Check if the class info registry is empty.
             * @return true if the class info registry is empty.
             */
            Bool IsEmpty() const
            {
                return mClassInfos.IsEmpty();
            }
            
            /**
             * @brief Get a registered class info object by name.
             * @param className The class name of the object.
             * @return The class info object or null if the class name is not registered.
             */
            const ClassInfoType* Get(const String& className) const
            {
                SInt32 index = mClassInfos.Find(className);
                if (index < 0)
                {
                    return 0;
                }
                return mClassInfos[index];
            }
            
            /**
             * @brief Get a registered class info object by index.
             * @param index The index the object.
             * @return The class info object or null if the index is out of range.
             */
            const ClassInfoType* GetAt(UInt32 index) const
            {
                if (index >= mClassInfos.GetCount())
                {
                    return 0;
                }
                return mClassInfos[index];
            }

            /**
             * @brief Get the (alias) name of a registered class info object by index.
             * @param index The index the object.
             * @return The registered name or an empty string if the index is out of range.
             */
            const String& GetKeyAt(UInt32 index) const
            {
                if (index >= mClassInfos.GetCount())
                {
                    return StaticEmptyString();
                }
                return mClassInfos.GetKey(index);
            }
            
        protected:
            /** @brief The registered class info objects mapped by the class name. */
            Map<String, const ClassInfoType*> mClassInfos;
        };
    }
}

#endif // __MURL_UTIL_CLASS_INFO_REGISTRY_H__
