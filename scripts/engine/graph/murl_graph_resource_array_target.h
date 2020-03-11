// Copyright 2010-2011 Spraylight GmbH

#ifndef __MURL_GRAPH_RESOURCE_ARRAY_TARGET_H__
#define __MURL_GRAPH_RESOURCE_ARRAY_TARGET_H__

#include "murl_graph_generic_resource_target.h"
#include "murl_graph_property.h"
#include "murl_graph_i_init_tracker.h"
#include "murl_graph_i_de_init_tracker.h"
#include "murl_graph_i_config_changed_tracker.h"
#include "murl_graph_i_process_input_tracker.h"
#include "murl_graph_i_process_output_tracker.h"
#include "murl_graph_i_deserialize_attribute_tracker.h"
#include "murl_resource_i_collection.h"
#include "murl_i_engine_configuration.h"
#include "murl_debug_trace.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphTargetClasses
         * @interface ResourceArrayTarget
         * @brief The ResourceArrayTarget class.
         * This class implements an IGenericResourceTarget that can reference any number
         * of resource objects.
         * The MIN_NUMBER_OF_RESOURCES and MAX_NUMBER_OF_RESOURCES template parameters represent
         * the minimum and maximum number of referenced resources that must be present for
         * the Init() method to succeed.
         * The RESERVED_NUMBER_OF_RESOURCES parameter defines the initial size of the reference
         * array. Must be in the range from MIN_NUMBER_OF_RESOURCES to MAX_NUMBER_OF_RESOURCES.
         */
        template<class ObjectType, UInt32 MIN_NUMBER_OF_RESOURCES, UInt32 MAX_NUMBER_OF_RESOURCES, UInt32 RESERVED_NUMBER_OF_RESOURCES>
        class ResourceArrayTarget : public GenericResourceTarget<ObjectType>
        {
        public:
            /**
             * @brief The constructor.
             */
            ResourceArrayTarget()
            : mResourceCollection(0)
            {
                if (RESERVED_NUMBER_OF_RESOURCES > 0)
                {
                    mResourceIds.SetCount(RESERVED_NUMBER_OF_RESOURCES);
                    mResources.SetCount(RESERVED_NUMBER_OF_RESOURCES, 0);
                }
            }

            ResourceArrayTarget(ObjectType* const* objects)
            {
                if (RESERVED_NUMBER_OF_RESOURCES > 0)
                {
                    mResourceIds.SetCount(RESERVED_NUMBER_OF_RESOURCES);
                    mResources.SetCount(RESERVED_NUMBER_OF_RESOURCES, 0);
                    for (UInt32 i = 0; i < RESERVED_NUMBER_OF_RESOURCES; i++)
                    {
                        mResources[i] = objects[i];
                    }
                }
            }

            virtual ~ResourceArrayTarget()
            {
            }
            
            /**
             * @brief Deserialize all defined target resource IDs from a given tracker.
             * @param tracker The tracker to deserialize.
             * @return true if successful.
             */
            Bool DeserializeResourceIds(IDeserializeAttributeTracker* tracker)
            {
                tracker->GetAttributeValues(mResourceIds);
                mResources.SetCount(mResourceIds.GetCount(), 0);
                for (UInt32 i = 0; i < mResourceIds.GetCount(); i++)
                {
                    if (!tracker->MakeResourceIdAbsolute(mResourceIds[i]))
                    {
                        return false;
                    }
                }
                return true;
            }
            
            /**
             * @brief Deserialize a single target resource ID from a given tracker.
             * The actual index is retrieved from the tracker's base attribute.
             * @param tracker The tracker to deserialize.
             * @return true if successful.
             */
            Bool DeserializeResourceId(IDeserializeAttributeTracker* tracker)
            {
                UInt32 index;
                if (!Util::StringToUInt32(tracker->GetBaseAttributeName(), index))
                {
                    return false;
                }
                return DeserializeResourceId(tracker, index);
            }
            
            /**
             * @brief Deserialize a single target resource ID from a given tracker at a given index.
             * @param tracker The tracker to deserialize.
             * @param index The index of the referenced resource.
             * @return true if successful.
             */
            Bool DeserializeResourceId(IDeserializeAttributeTracker* tracker, UInt32 index)
            {
                if (index >= mResourceIds.GetCount())
                {
                    mResourceIds.SetCount(index + 1);
                }
                if (index >= mResources.GetCount())
                {
                    mResources.SetCount(index + 1, 0);
                    
                    for (UInt32 i = 0; i <= index; i++)
                    {
                        mResources[i] = 0;
                    }
                }
                
                tracker->GetAttributeValue(mResourceIds[index]);
                return tracker->MakeResourceIdAbsolute(mResourceIds[index]);
            }
            
            virtual Bool Init(IInitTracker* tracker)
            {
                if (GenericResourceTarget<ObjectType>::IsInitialized())
                {
                    return true;
                }
                
                if (MIN_NUMBER_OF_RESOURCES > MAX_NUMBER_OF_RESOURCES)
                {
                    MURL_ERROR("Minimum number of targets cannot be greater than %d", MAX_NUMBER_OF_RESOURCES);
                    return false;
                }
                
                mResourceCollection = tracker->GetResourceCollection();
                
                IEnums::ResultAction actionNotFound = tracker->GetTrackerInterface()->GetEngineConfiguration()->GetGraphObjectResultAction(IEnums::RESULT_CODE_GRAPH_NODE_NOT_FOUND_ERROR);
                IEnums::ResultAction actionWrongInterface = tracker->GetTrackerInterface()->GetEngineConfiguration()->GetGraphObjectResultAction(IEnums::RESULT_CODE_GRAPH_NODE_WRONG_INTERFACE_ERROR);

                for (UInt32 i = 0; i < mResourceIds.GetCount(); i++)
                {
                    if (mResourceIds[i].IsEmpty())
                    {
                        continue;
                    }
                    
                    if (mResources.GetCount() > i)
                    {
                        if (mResources[i] != 0)
                        {
                            MURL_ERROR("Cannot specify both resource ID and object for index %d", i);
                            ClearNamedResources();
                            return false;
                        }
                    }
                    while (mResources.GetCount() <= i)
                    {
                        mResources.Add(0);
                    }

                    const ObjectType* object;
                    if (!GenericResourceTarget<ObjectType>::GetResourceFromCollection(mResourceCollection, mResourceIds[i], object))
                    {
                        if (mResourceCollection->GetObject(mResourceIds[i]) != 0)
                        {
                            if (actionWrongInterface != IEnums::RESULT_ACTION_IGNORE)
                            {
                                MURL_ERROR("Resource \"%s\" has wrong type", mResourceIds[i].Begin());
                                if (actionNotFound == IEnums::RESULT_ACTION_ABORT)
                                {
                                    ClearNamedResources();
                                    return false;
                                }
                            }
                        }
                        else
                        {
                            if (actionNotFound != IEnums::RESULT_ACTION_IGNORE)
                            {
                                MURL_ERROR("Failed to get resource \"%s\"", mResourceIds[i].Begin());
                                if (actionNotFound == IEnums::RESULT_ACTION_ABORT)
                                {
                                    ClearNamedResources();
                                    return false;
                                }
                            }
                        }
                        object = 0;
                    }
                    
                    mResources[i] = object;
                }
                
                if (mResources.GetCount() < MIN_NUMBER_OF_RESOURCES)
                {
                    MURL_ERROR("Need at least %d resources", MIN_NUMBER_OF_RESOURCES);
                    ClearNamedResources();
                    return false;
                }
                for (UInt32 i = 0; i < MIN_NUMBER_OF_RESOURCES; i++)
                {
                    if (mResources[i] == 0)
                    {
                        if (mResourceIds[i].IsEmpty())
                        {
                            MURL_ERROR("Resource %d is empty", i);
                            ClearNamedResources();
                            return false;
                        }
                    }
                }
                
                GenericResourceTarget<ObjectType>::SetInitialized(true);
                GenericResourceTarget<ObjectType>::SetModified(false);
                return true;
            }
            
            virtual Bool DeInit(IDeInitTracker* tracker)
            {
                if (!GenericResourceTarget<ObjectType>::IsInitialized())
                {
                    return true;
                }

                ClearNamedResources();

                GenericResourceTarget<ObjectType>::SetInitialized(false);
                GenericResourceTarget<ObjectType>::SetModified(false);

                mResourceCollection = 0;

                return true;
            }
            
            virtual Bool ConfigChanged(IConfigChangedTracker* tracker, Bool* hasResourceChanged)
            {
                if (!mResourceIds.IsEmpty())
                {
                    Resource::ICollection* collection = tracker->GetResourceCollection();
                    
                    for (UInt32 i = 0; i < mResourceIds.GetCount(); i++)
                    {
                        if (mResourceIds[i].IsEmpty())
                        {
                            continue;
                        }

                        const ObjectType* object;
                        if (!GenericResourceTarget<ObjectType>::GetResourceFromCollection(collection, mResourceIds[i], object))
                        {
                            MURL_ERROR("Failed to get resource \"%s\"", mResourceIds[i].Begin());
                            return false;
                        }

                        if (mResources[i] != object)
                        {
                            mResources[i] = object;
                            
                            if (hasResourceChanged != 0)
                            {
                                *hasResourceChanged = true;
                                GenericResourceTarget<ObjectType>::SetModified(true);
                            }
                        }
                    }
                }
                return true;
            }
            
            virtual Bool Update()
            {
                if (!GenericResourceTarget<ObjectType>::IsModified())
                {
                    return true;
                }

                for (UInt32 i = 0; i < mResourceIds.GetCount(); i++)
                {
                    const String& resourceId = mResourceIds[i];
                    if (resourceId.IsEmpty())
                    {
                        continue;
                    }

                    if (!GenericResourceTarget<ObjectType>::GetResourceFromCollection(mResourceCollection, resourceId, mResources[i]))
                    {
                        MURL_ERROR("Failed to get resource \"%s\"", resourceId.Begin());
                        return false;
                    }
                }

                GenericResourceTarget<ObjectType>::SetModified(false);
                return true;
            }
            
            virtual UInt32 GetMinNumberOfResources() const
            {
                return MIN_NUMBER_OF_RESOURCES;
            }
            
            virtual UInt32 GetMaxNumberOfResources() const
            {
                return MAX_NUMBER_OF_RESOURCES;
            }
            
            virtual Bool SetNumberOfResources(UInt32 numberOfResources)
            {
                if (numberOfResources == mResources.GetCount())
                {
                    return true;
                }
                
                mResourceIds.SetCount(numberOfResources);
                mResources.SetCount(numberOfResources, 0);

                GenericResourceTarget<ObjectType>::SetModified(true);
                return true;
            }
            
            virtual UInt32 GetNumberOfResources() const
            {
                return mResources.GetCount();
            }
            
            virtual Bool SetResourceId(const String& resourceId, UInt32 index)
            {
                if (index >= mResources.GetCount())
                {
                    return false;
                }
                if (mResourceIds[index] == resourceId)
                {
                    return true;
                }
                
                mResourceIds[index] = resourceId;
                mResources[index] = 0;
                GenericResourceTarget<ObjectType>::SetModified(true);
                
                return true;
            }
            
            virtual const String& GetResourceId(UInt32 index) const
            {
                if (index >= mResourceIds.GetCount())
                {
                    return Util::StaticEmptyString();
                }
                return mResourceIds[index];
            }
            
            virtual Bool SetResource(const ObjectType* object, UInt32 index)
            {
                if (index >= mResources.GetCount())
                {
                    return false;
                }
                if (mResources[index] == object)
                {
                    return true;
                }
                
                mResourceIds[index].Clear();
                mResources[index] = object;
                GenericResourceTarget<ObjectType>::SetModified(true);
                
                return true;
            }
            
            virtual const Array<const ObjectType*>& GetResources() const
            {
                return mResources;
            }
            
            virtual const ObjectType* GetResource(UInt32 index) const
            {
                if (index >= mResources.GetCount())
                {
                    return 0;
                }
                return mResources[index];
            }

        protected:
            void ClearNamedResources()
            {
                UInt32 numResources = Math::Min(mResourceIds.GetCount(), mResources.GetCount());
                for (UInt32 i = 0; i < numResources; i++)
                {
                    if (mResourceIds[i].IsEmpty())
                    {
                        continue;
                    }
                    mResources[i] = 0;
                }
            }

            Resource::ICollection* mResourceCollection;

            StringArray mResourceIds;
            Array<const ObjectType*> mResources;
        };

        template<class ObjectType, UInt32 MIN_NUMBER_OF_RESOURCES, UInt32 MAX_NUMBER_OF_RESOURCES, UInt32 RESERVED_NUMBER_OF_RESOURCES>
        class ResourceArrayPropertyBase : public TypedProperty<ObjectType>
        {
        public:
            struct Value
            {
                UInt32 mId;
                ObjectType* mValue[MAX_NUMBER_OF_RESOURCES];
            };

            typedef const Value& (*GetValueFunction)();

        public:
            explicit ResourceArrayPropertyBase(const Value& v)
            : mValue(v.mValue)
            {
            }

            Bool DeserializeResourceIds(IDeserializeAttributeTracker* tracker)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                return mValue.DeserializeResourceIds(tracker);
            }
            Bool DeserializeResourceId(IDeserializeAttributeTracker* tracker)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                return mValue.DeserializeResourceId(tracker);
            }
            Bool DeserializeResourceId(IDeserializeAttributeTracker* tracker, UInt32 index)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                return mValue.DeserializeResourceId(tracker, index);
            }

            ResourceArrayTarget<ObjectType, MIN_NUMBER_OF_RESOURCES, MAX_NUMBER_OF_RESOURCES, RESERVED_NUMBER_OF_RESOURCES>* operator&()
            {
                return &mValue;
            }
            const ResourceArrayTarget<ObjectType, MIN_NUMBER_OF_RESOURCES, MAX_NUMBER_OF_RESOURCES, RESERVED_NUMBER_OF_RESOURCES>* operator&() const
            {
                return &mValue;
            }

            ResourceArrayTarget<ObjectType, MIN_NUMBER_OF_RESOURCES, MAX_NUMBER_OF_RESOURCES, RESERVED_NUMBER_OF_RESOURCES>& operator*()
            {
                return mValue;
            }
            const ResourceArrayTarget<ObjectType, MIN_NUMBER_OF_RESOURCES, MAX_NUMBER_OF_RESOURCES, RESERVED_NUMBER_OF_RESOURCES>& operator*() const
            {
                return mValue;
            }

            ResourceArrayTarget<ObjectType, MIN_NUMBER_OF_RESOURCES, MAX_NUMBER_OF_RESOURCES, RESERVED_NUMBER_OF_RESOURCES>* operator->()
            {
                return &mValue;
            }
            const ResourceArrayTarget<ObjectType, MIN_NUMBER_OF_RESOURCES, MAX_NUMBER_OF_RESOURCES, RESERVED_NUMBER_OF_RESOURCES>* operator->() const
            {
                return &mValue;
            }

            ResourceArrayTarget<ObjectType, MIN_NUMBER_OF_RESOURCES, MAX_NUMBER_OF_RESOURCES, RESERVED_NUMBER_OF_RESOURCES> mValue;
        };

        template<class ObjectType, UInt32 MIN_NUMBER_OF_RESOURCES, UInt32 MAX_NUMBER_OF_RESOURCES, UInt32 RESERVED_NUMBER_OF_RESOURCES, const typename ResourceArrayPropertyBase<ObjectType, MIN_NUMBER_OF_RESOURCES, MAX_NUMBER_OF_RESOURCES, RESERVED_NUMBER_OF_RESOURCES>::GetValueFunction DEFAULT>
        class ResourceArrayProperty : public ResourceArrayPropertyBase<ObjectType, MIN_NUMBER_OF_RESOURCES, MAX_NUMBER_OF_RESOURCES, RESERVED_NUMBER_OF_RESOURCES>
        {
        public:
            explicit ResourceArrayProperty()
            : ResourceArrayPropertyBase<ObjectType, MIN_NUMBER_OF_RESOURCES, MAX_NUMBER_OF_RESOURCES, RESERVED_NUMBER_OF_RESOURCES>(DEFAULT())
            {
            }
            void Reset()
            {
                ResourceArrayPropertyBase<ObjectType, MIN_NUMBER_OF_RESOURCES, MAX_NUMBER_OF_RESOURCES, RESERVED_NUMBER_OF_RESOURCES>::mValue = DEFAULT().mValue;
            }
            static const PropertyInfo::Item* GetTypeInfo()
            {
                static PropertyInfo::Item p =
                {
                    DEFAULT().mId,
                    "Murl::Graph::IGenericResourceTarget<" + TypedProperty<ObjectType>::GetTypeName() + ">",
                    IEnums::PROPERTY_SEMANTIC_OBJECT,
                    1,
                    MIN_NUMBER_OF_RESOURCES,
                    MAX_NUMBER_OF_RESOURCES,
                    MIN_NUMBER_OF_RESOURCES,
                    MAX_NUMBER_OF_RESOURCES
                };
                return &p;
            }
            static SInt32 GetId()
            {
                return DEFAULT().mId;
            }
        };
    }
}

#endif // __MURL_GRAPH_RESOURCE_ARRAY_TARGET_H__
