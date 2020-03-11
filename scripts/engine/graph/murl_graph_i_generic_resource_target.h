// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_GRAPH_I_GENERIC_RESOURCE_TARGET_H__
#define __MURL_GRAPH_I_GENERIC_RESOURCE_TARGET_H__

#include "murl_graph_types.h"

namespace Murl
{
    namespace Resource
    {
        class IAnimation;
        class IArchive;
        class IAtlas;
        class IAudio;
        class IBinary;
        class IDictionary;
        class IFont;
        class IGraph;
        class IGrid;
        class IImage;
        class IMesh;
        class IScript;
        class IShader;
        class IText;
        class IVideo;
    }

    namespace Graph
    {
        class IInitTracker;
        class IDeInitTracker;
        class IConfigChangedTracker;
        class IProcessLogicTracker;
        class IProcessInputTracker;
        class IProcessOutputTracker;

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @interface IGenericResourceTarget
         * @brief The IGenericResourceTarget resource object target interface.
         * A generic resource target is used to encapsulate (possibly) any number
         * of resource objects, referenced by their unique package/resource ID or
         * directly by pointer. It provides access methods to add, remove or query
         * the set of resource objects that are referenced. By using an
         * IGenericResourceTarget, a graph node's process of handling references to
         * resource objects can be unified, the respective resource object references
         * may be acquired by either specifying a resource ID in an XML scene graph
         * file, or directly set from code when a resource is obtained via a
         * Resource::ICollection from a Logic::IProcessor.
         */
        template<class ObjectType>
        class IGenericResourceTarget
        {
        public:
            /**
             * @brief Initialize the resource target.
             * To be able to reference resource objects via their unique IDs in a
             * Resource::ICollection, a Graph::IInitTracker must be passed to the
             * resource target, which holds a reference to the actual collection.
             * @param tracker The tracker used for node initialization.
             * @return true if successful.
             */
            virtual Bool Init(IInitTracker* tracker) = 0;
            /**
             * @brief De-Initialize the resource target.
             * @param tracker The tracker used for node de-initialization.
             * @return true if successful.
             */
            virtual Bool DeInit(IDeInitTracker* tracker) = 0;
            /**
             * @brief Called when the global configuration has changed.
             * @param tracker The tracker used for change notifications.
             * @param hasResourceChanged An optional pointer to a Bool value that will
             *      be set to true if any of the referenced resources has changed when
             *      the global configuration triggered a ConfigChanged event.
             * @return true if successful.
             */
            virtual Bool ConfigChanged(IConfigChangedTracker* tracker, Bool* hasResourceChanged = 0) = 0;

            /**
             * @brief Perform an update on the resource target.
             * @return true if successful.
             */
            virtual Bool Update() = 0;

            /**
             * @brief Check if the resource target is initialized.
             * @return true if initialized.
             */
            virtual Bool IsInitialized() const = 0;
            /**
             * @brief Check if the resource target is modified.
             * This method returns true, whenever the set of encapsulated resource
             * references changes, either in size or by content. When modified,
             * that state persists until a manual call to SetModified() with
             * parameter false.
             * @return true if modified.
             */
            virtual Bool IsModified() const = 0;

            /**
             * @brief Manually set or reset the initialized state of the target.
             * @param initialized The initialized state.
             * @return true if successful.
             */
            virtual Bool SetInitialized(Bool initialized) = 0;
            /**
             * @brief Manually set or reset the modified state of the target.
             * @param modified The modified state.
             * @return true if successful.
             */
            virtual Bool SetModified(Bool modified) = 0;

            /**
             * @brief Query the minimum number of resource objects.
             * This method returns the defined minimum number of resource object
             * references that must be present for the Init() call to be successful.
             * @return The required minimum number of resource objects for the
             *      target to be valid.
             */
            virtual UInt32 GetMinNumberOfResources() const = 0;
            /**
             * @brief Query the maximum number of resource objects.
             * This method returns the defined maximum number of resource object
             * references that can be present for the Init() call to be successful.
             * @return The required maximum number of resource objects for the
             *      target to be valid.
             */
            virtual UInt32 GetMaxNumberOfResources() const = 0;

            /**
             * @brief Set the total number of resources.
             * The given value must be in the range from GetMinNumberOfResources()
             * to GetMaxNumberOfResources().
             * @param numberOfResources The total number of resources in the target.
             * @return true if successful.
             */
            virtual Bool SetNumberOfResources(UInt32 numberOfResources) = 0;
            /**
             * @brief Get the total number of resources.
             * @return The total number of resources in the target.
             */
            virtual UInt32 GetNumberOfResources() const = 0;

            /**
             * @brief Set a single resource ID at a given index.
             * You need to make sure that the given index is in the range from
             * 0 to GetNumberOfResources()-1, use SetNumberOfResources() to define the
             * actual node count.
             * @param resourceId A string containing the full package name and ID
             *      to a resource object in the resource collection.
             * @param index The index of the resource ID to set, in the range from
             *      0 to GetNumberOfResources()-1.
             * @return true if successful.
             */
            virtual Bool SetResourceId(const String& resourceId, UInt32 index) = 0;
            /**
             * @brief Get the resource ID at a given index.
             * @param index The resource ID index in the range from 0 to
             *      GetNumberOfResources()-1.
             * @return The total number of resource IDs in the target.
             */
            virtual const String& GetResourceId(UInt32 index) const = 0;

            /**
             * @brief Set (replace) a single resource for referencing at a given position.
             * You need to make sure that the given index is in the range from
             * 0 to GetNumberOfResources()-1, use SetNumberOfResources() to define the
             * actual node count.
             * @param object A pointer to the resource.
             * @param index The zero-based position where to set the resource, in the
             *      range from 0 to GetNumberOfResources()-1.
             * @return true if successful.
             */
            virtual Bool SetResource(const ObjectType* object, UInt32 index) = 0;
            /**
             * @brief Get the resource at a given index.
             * @param index The resource index in the range from 0 to
             *      GetNumberOfResources()-1.
             * @return The resource at the given index.
             */
            virtual const ObjectType* GetResource(UInt32 index) const = 0;

        protected:
            virtual ~IGenericResourceTarget() {}
        };

        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more text resources.
         */
        typedef IGenericResourceTarget<Resource::IText> ITextResourceTarget;
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Resource::IAnimation objects.
         */
        typedef IGenericResourceTarget<Resource::IAnimation> IAnimationResourceTarget;
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Resource::IArchive objects.
         */
        typedef IGenericResourceTarget<Resource::IArchive> IArchiveResourceTarget;
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Resource::IAudio objects.
         */
        typedef IGenericResourceTarget<Resource::IAudio> IAudioResourceTarget;
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Resource::IAtlas objects.
         */
        typedef IGenericResourceTarget<Resource::IAtlas> IAtlasResourceTarget;
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Resource::IBinary objects.
         */
        typedef IGenericResourceTarget<Resource::IBinary> IBinaryResourceTarget;
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Resource::IDictionary objects.
         */
        typedef IGenericResourceTarget<Resource::IDictionary> IDictionaryResourceTarget;
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Resource::IFont objects.
         */
        typedef IGenericResourceTarget<Resource::IFont> IFontResourceTarget;
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Resource::IGraph objects.
         */
        typedef IGenericResourceTarget<Resource::IGraph> IGraphResourceTarget;
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Resource::IGrid objects.
         */
        typedef IGenericResourceTarget<Resource::IGrid> IGridResourceTarget;
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Resource::IImage objects.
         */
        typedef IGenericResourceTarget<Resource::IImage> IImageResourceTarget;
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Resource::IMesh objects.
         */
        typedef IGenericResourceTarget<Resource::IMesh> IMeshResourceTarget;
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Resource::IScript objects.
         */
        typedef IGenericResourceTarget<Resource::IScript> IScriptResourceTarget;
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Resource::IShader objects.
         */
        typedef IGenericResourceTarget<Resource::IShader> IShaderResourceTarget;
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Resource::IVideo objects.
         */
        typedef IGenericResourceTarget<Resource::IVideo> IVideoResourceTarget;
    }
}

#endif // __MURL_GRAPH_I_GENERIC_RESOURCE_TARGET_H__
