// Copyright 2010-2011 Spraylight GmbH

#ifndef __MURL_GRAPH_RESOURCE_TARGET_H__
#define __MURL_GRAPH_RESOURCE_TARGET_H__

#include "murl_graph_generic_resource_target.h"
#include "murl_graph_property.h"
#include "murl_graph_i_init_tracker.h"
#include "murl_graph_i_de_init_tracker.h"
#include "murl_graph_i_config_changed_tracker.h"
#include "murl_graph_i_process_logic_tracker.h"
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
         * @interface ResourceTarget
         * @brief The ResourceTarget class.
         * This class implements an IGenericResourceTarget that can reference at most
         * one resource object.
         * The MIN_NUMBER_OF_RESOURCES template parameter represents the minimum number
         * of referenced resources that must be present for the Init() method to succeed.
         * May be either 0 or 1.
         */
        template<class ObjectType, UInt32 MIN_NUMBER_OF_RESOURCES>
        class ResourceTarget : public GenericResourceTarget<ObjectType>
        {
        public:
            /**
             * @brief The constructor.
             */
            ResourceTarget()
            : mResourceCollection(0)
            , mResource(0)
            , mNumberOfResources(0)
            {
            }
            /**
             * @brief Constructor taking a single (optional) object.
             * @param object The object or null.
             */
            ResourceTarget(ObjectType* object)
            : mResourceCollection(0)
            , mResource(object)
            , mNumberOfResources(object == 0 ? 0 : 1)
            {
            }

            virtual ~ResourceTarget()
            {
            }
            
            /**
             * @brief Deserialize the single target resource ID from a given tracker.
             * @param tracker The tracker to deserialize.
             * @return true if successful.
             */
            Bool DeserializeResourceId(IDeserializeAttributeTracker* tracker)
            {
                tracker->GetAttributeValue(mResourceId);
                return tracker->MakeResourceIdAbsolute(mResourceId);
            }
            
            virtual Bool Init(IInitTracker* tracker)
            {
                if (GenericResourceTarget<ObjectType>::IsInitialized())
                {
                    return true;
                }
                
                if (MIN_NUMBER_OF_RESOURCES > 1)
                {
                    MURL_ERROR("Minimum number of targets cannot be greater than 1");
                    return false;
                }

                mResourceCollection = tracker->GetResourceCollection();

                if (!mResourceId.IsEmpty())
                {
                    if (mResource != 0)
                    {
                        MURL_ERROR("Cannot specify both resource ID \"%s\" and resource object", mResourceId.Begin());
                        return false;
                    }

                    IEnums::ResultAction actionNotFound = tracker->GetTrackerInterface()->GetEngineConfiguration()->GetGraphObjectResultAction(IEnums::RESULT_CODE_GRAPH_NODE_NOT_FOUND_ERROR);
                    IEnums::ResultAction actionWrongInterface = tracker->GetTrackerInterface()->GetEngineConfiguration()->GetGraphObjectResultAction(IEnums::RESULT_CODE_GRAPH_NODE_WRONG_INTERFACE_ERROR);

                    if (!GenericResourceTarget<ObjectType>::GetResourceFromCollection(mResourceCollection, mResourceId, mResource))
                    {
                        if (mResourceCollection->GetObject(mResourceId) != 0)
                        {
                            if (actionWrongInterface != IEnums::RESULT_ACTION_IGNORE)
                            {
                                MURL_ERROR("Resource \"%s\" has wrong type", mResourceId.Begin());
                                if (actionNotFound == IEnums::RESULT_ACTION_ABORT)
                                {
                                    return false;
                                }
                            }
                        }
                        else
                        {
                            if (actionNotFound != IEnums::RESULT_ACTION_IGNORE)
                            {
                                MURL_ERROR("Failed to get resource \"%s\"", mResourceId.Begin());
                                if (actionNotFound == IEnums::RESULT_ACTION_ABORT)
                                {
                                    return false;
                                }
                            }
                        }
                        mResource = 0;
                    }
                    
                    mNumberOfResources = 1;
                }
                
                if ((MIN_NUMBER_OF_RESOURCES != 0) && (mNumberOfResources == 0))
                {
                    MURL_ERROR("Need exactly 1 object");
                    return false;
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
                
                if (!mResourceId.IsEmpty())
                {
                    mResource = 0;
                    mNumberOfResources = 0;
                }

                GenericResourceTarget<ObjectType>::SetInitialized(false);
                GenericResourceTarget<ObjectType>::SetModified(false);

                mResourceCollection = 0;

                return true;
            }
            
            virtual Bool ConfigChanged(IConfigChangedTracker* tracker, Bool* hasResourceChanged)
            {
                if (!mResourceId.IsEmpty())
                {
                    Resource::ICollection* collection = tracker->GetResourceCollection();
                    
                    const ObjectType* object;
                    if (!GenericResourceTarget<ObjectType>::GetResourceFromCollection(collection, mResourceId, object))
                    {
                        MURL_ERROR("Failed to get resource \"%s\"", mResourceId.Begin());
                        return false;
                    }
                    
                    if (mResource != object)
                    {
                        mResource = object;
                        
                        if (hasResourceChanged != 0)
                        {
                            *hasResourceChanged = true;
                            GenericResourceTarget<ObjectType>::SetModified(true);
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
                
                if (!mResourceId.IsEmpty())
                {
                    if (!GenericResourceTarget<ObjectType>::GetResourceFromCollection(mResourceCollection, mResourceId, mResource))
                    {
                        MURL_ERROR("Failed to get resource \"%s\"", mResourceId.Begin());
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
                return 1;
            }
            
            virtual Bool SetNumberOfResources(UInt32 numberOfResources)
            {
                if (numberOfResources == mNumberOfResources)
                {
                    return true;
                }
                
                if (numberOfResources == 0)
                {
                    mResourceId.Clear();
                    mResource = 0;
                }
                else if (numberOfResources != 1)
                {
                    return false;
                }

                mNumberOfResources = numberOfResources;
                GenericResourceTarget<ObjectType>::SetModified(true);
                
                return true;
            }
            
            virtual UInt32 GetNumberOfResources() const
            {
                return mNumberOfResources;
            }
            
            virtual Bool SetResourceId(const String& resourceId, UInt32 index)
            {
                if (index >= mNumberOfResources)
                {
                    return false;
                }
                if (mResourceId == resourceId)
                {
                    return true;
                }
                
                mResourceId = resourceId;
                mResource = 0;
                GenericResourceTarget<ObjectType>::SetModified(true);
                
                return true;
            }
        
            /**
             * @brief Get the single resource ID.
             * @return The resource ID, or an empty string if no resource is referenced.
             */
            const String& GetResourceId() const
            {
                return mResourceId;
            }
            
            virtual const String& GetResourceId(UInt32 index) const
            {
                if (index > 0)
                {
                    return Util::StaticEmptyString();
                }
                return mResourceId;
            }
            
            virtual Bool SetResource(const ObjectType* object, UInt32 index)
            {
                if (index >= mNumberOfResources)
                {
                    return false;
                }
                if (mResource == object)
                {
                    return true;
                }
                mResourceId.Clear();
                mResource = object;
                GenericResourceTarget<ObjectType>::SetModified(true);
                return true;
            }
            
            /**
             * @brief Get the single resource object.
             * @return The resource object, or null if none is referenced.
             */
            const ObjectType* GetResource() const
            {
                return mResource;
            }
            
            virtual const ObjectType* GetResource(UInt32 index) const
            {
                if (index > 0)
                {
                    return 0;
                }
                return mResource;
            }

        protected:
            Resource::ICollection* mResourceCollection;

            String mResourceId;
            const ObjectType* mResource;
            
            UInt32 mNumberOfResources;
        };

        template<class ObjectType, UInt32 MIN_NUMBER_OF_RESOURCES>
        class ResourcePropertyBase : public TypedProperty<ObjectType>
        {
        public:
            struct Value
            {
                UInt32 mId;
                ObjectType* mValue;
            };

            typedef const Value& (*GetValueFunction)();

        public:
            explicit ResourcePropertyBase(const Value& v)
            : mValue(v.mValue)
            {
            }

            Bool DeserializeResourceId(IDeserializeAttributeTracker* tracker)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                return mValue.DeserializeResourceId(tracker);
            }

            ResourceTarget<ObjectType, MIN_NUMBER_OF_RESOURCES>* operator&()
            {
                return &mValue;
            }
            const ResourceTarget<ObjectType, MIN_NUMBER_OF_RESOURCES>* operator&() const
            {
                return &mValue;
            }

            ResourceTarget<ObjectType, MIN_NUMBER_OF_RESOURCES>& operator*()
            {
                return mValue;
            }
            const ResourceTarget<ObjectType, MIN_NUMBER_OF_RESOURCES>& operator*() const
            {
                return mValue;
            }

            ResourceTarget<ObjectType, MIN_NUMBER_OF_RESOURCES>* operator->()
            {
                return &mValue;
            }
            const ResourceTarget<ObjectType, MIN_NUMBER_OF_RESOURCES>* operator->() const
            {
                return &mValue;
            }

            ResourceTarget<ObjectType, MIN_NUMBER_OF_RESOURCES> mValue;
        };

        template<class ObjectType, UInt32 MIN_NUMBER_OF_RESOURCES, const typename ResourcePropertyBase<ObjectType, MIN_NUMBER_OF_RESOURCES>::GetValueFunction DEFAULT>
        class ResourceProperty : public ResourcePropertyBase<ObjectType, MIN_NUMBER_OF_RESOURCES>
        {
        public:
            explicit ResourceProperty()
            : ResourcePropertyBase<ObjectType, MIN_NUMBER_OF_RESOURCES>(DEFAULT())
            {
            }
            void Reset()
            {
                ResourcePropertyBase<ObjectType, MIN_NUMBER_OF_RESOURCES>::mValue = DEFAULT().mValue;
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
                    1,
                    MIN_NUMBER_OF_RESOURCES,
                    1
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

#endif // __MURL_GRAPH_RESOURCE_TARGET_H__
