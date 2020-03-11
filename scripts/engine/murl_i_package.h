// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_I_PACKAGE_H__
#define __MURL_I_PACKAGE_H__

#include "murl_i_loader.h"
#include "murl_logic_types.h"
#include "murl_string.h"

namespace Murl
{
    namespace Resource
    {
        class IPackage;
    }

    /**
     * @ingroup MurlInterfaces
     * @interface IPackage
     * @brief The package interface.
     * Packages operations are processed by a loader thread, the IPackage interface
     * provides methods for controlling and monitoring the package processing.
     *
     * The IPackage object can be created by the ILoader object.
     */
    class IPackage
    {
    public:
        /**
         * @brief Get the name of the package.
         * @return The name of the package.
         */
        virtual const String& GetName() const = 0;

        /**
         * @brief Get the package's load mode.
         * @return The load mode.
         */
        virtual ILoader::LoadMode GetLoadMode() const = 0;
        /**
         * @brief Get the package's file category.
         * @return The file category.
         */
        virtual IEnums::FileCategory GetFileCategory() const = 0;

        /**
         * @brief Get the resource package contained in the package.
         * @return The resource package.
         */
        virtual const Resource::IPackage* GetResourcePackage() const = 0;

        /**
         * @brief Get the logic processor assigned to the package with ILoader::AddPackage().
         * @return The logic processor, or null if none is assigned.
         */
        virtual Logic::IProcessorPtr GetLogicProcessor() const = 0;

        /**
         * @brief Check if a logic processor is assigned to the package.
         * This method checks the processor assigned with ILoader::AddPackage()
         * and all processors added by script resources.
         * @param logicProcessor The logic processor to check.
         * @return true if the logic processor is assigned to the package.
         */
        virtual Bool HasLogicProcessor(Logic::IProcessorPtr logicProcessor) const = 0;

        /**
         * @brief Manually add a graph instance to create when the package is loaded.
         * This only works for packages using ILoader::LOAD_MODE_ON_DEMAND.
         * @param graphResourceId The resource ID of the graph to create.
         * @param parentNodeId The ID of the parent node where to insert the graph.
         * @param numberOfReplications The number of replications of the graph to create.
         * @return true if successful.
         */
        virtual Bool AddGraphInstance(const String& graphResourceId, const String& parentNodeId,
                                      UInt32 numberOfReplications = 1) = 0;
        /**
         * @brief Remove a manually added graph instance.
         * This method is used to remove a graph instance to be created that was previously
         * added via AddGraphInstance(). If it is desired to disable the creation of a graph
         * instance that is statically present in the package, use HideGraphInstance() instead.
         * @param graphResourceId The resource ID of the graph to remove from the creation list.
         * @param parentNodeId The ID of the parent node where to insert the graph.
         * @return true if successful.
         */
        virtual Bool RemoveGraphInstance(const String& graphResourceId, const String& parentNodeId) = 0;

        /**
         * @brief Manually remove a graph instance from the creation list, i.e. hide the instance.
         * This only works for packages using ILoader::LOAD_MODE_ON_DEMAND.
         * @param graphResourceId The resource ID of the graph to prevent from being created.
         * @param parentNodeId The ID of the parent node where the graph would be inserted.
         * @return true if successful.
         */
        virtual Bool HideGraphInstance(const String& graphResourceId, const String& parentNodeId) = 0;
        /**
         * @brief Unhide a graph instance that was previously hidden via HideGraphInstance().
         * @param graphResourceId The resource ID of the graph to unhide.
         * @param parentNodeId The ID of the parent node where the graph gets inserted.
         * @return true if successful.
         */
        virtual Bool UnhideGraphInstance(const String& graphResourceId, const String& parentNodeId) = 0;

        /**
         * @brief Manually add a script instance to create when the package is loaded.
         * This only works for packages using ILoader::LOAD_MODE_ON_DEMAND.
         * @param scriptResourceId The resource ID of the script to create.
         * @param numberOfReplications The number of replications of the script to create.
         * @return true if successful.
         */
        virtual Bool AddScriptInstance(const String& scriptResourceId, UInt32 numberOfReplications = 1) = 0;
        /**
         * @brief Remove a manually added script instance.
         * This method is used to remove a script instance to be created that was previously
         * added via AddScriptInstance(). If it is desired to disable the creation of a script
         * instance that is statically present in the package, use HideScriptInstance() instead.
         * @param scriptResourceId The resource ID of the script to remove from the creation list.
         * @return true if successful.
         */
        virtual Bool RemoveScriptInstance(const String& scriptResourceId) = 0;

        /**
         * @brief Manually remove a script instance from the creation list, i.e. hide the instance.
         * This only works for packages using ILoader::LOAD_MODE_ON_DEMAND.
         * @param scriptResourceId The resource ID of the script to prevent from being created.
         * @return true if successful.
         */
        virtual Bool HideScriptInstance(const String& scriptResourceId) = 0;
        /**
         * @brief Unhide a script instance that was previously hidden via HideScriptInstance().
         * @param scriptResourceId The resource ID of the script to unhide.
         * @return true if successful.
         */
        virtual Bool UnhideScriptInstance(const String& scriptResourceId) = 0;
        
        /**
         * @brief Query the package.
         * This method takes a number of pointers to individual variables that receive
         * the results of the query. It is allowed to pass null pointers to any of these
         * variables in case the specific item is not of interest.
         * @param id A pointer to a String object receiving the internal package ID.
         * @param revision A pointer to a UInt32 variable receiving the package revision.
         * @param isDataValid A pointer to a Bool variable receiving the general validity
         *      of the package data.
         * @param isVersionValid A pointer to a Bool variable receiving the result of the file
         *      format version check.
         * @param isChecksumValid A pointer to a Bool variable receiving the result of the CRC32
         *      checksum validation.
         * @return true if the package was recognized by any of the available loader modules.
         *      If no loader module can handle the data stream, false is returned.
         */
        virtual Bool Query(String* id,
                           UInt32* revision,
                           Bool* isDataValid,
                           Bool* isVersionValid,
                           Bool* isChecksumValid) const = 0;

        /**
         * @brief Start loading the package.
         * Calls EnqueueForLoading() if the package is unloaded and not busy loading.
         * Calls CancelUnloading() if the package is busy unloading.
         * @return true if the package is loaded, false if the package is busy.
         */
        virtual Bool Load() = 0;

        /**
         * @brief Start unloading the package.
         * Calls EnqueueForUnloading() if the package is loaded and not busy unloading.
         * Calls CancelLoading() if the package is busy unloading.
         * @return true if the package is unloaded, false if the package is busy.
         */
        virtual Bool Unload() = 0;

        /**
         * @brief Enqueue the package for loading.
         * @return true if successful.
         */
        virtual Bool EnqueueForLoading() = 0;

        /**
         * @brief Enqueue the package for unloading.
         * @return true if successful.
         */
        virtual Bool EnqueueForUnloading() = 0;

        /**
         * @brief Cancel loading the package.
         * @return true if successful.
         */
        virtual Bool CancelLoading() = 0;

        /**
         * @brief Cancel unloading the package.
         * @return true if successful.
         */
        virtual Bool CancelUnloading() = 0;

        /**
         * @brief Check if the package is busy.
         * A package is busy during loading or unloading.
         * @return true if the package is busy.
         */
        virtual Bool IsBusy() const = 0;

        /**
         * @brief Check if the package is busy by loading.
         * @return true if the package is loading.
         */
        virtual Bool IsBusyLoading() const = 0;

        /**
         * @brief Check if the package is busy by unloading.
         * @return true if the package is unloading.
         */
        virtual Bool IsBusyUnloading() const = 0;

        /**
         * @brief Check if the package is loaded.
         * @return true if the package is loaded.
         */
        virtual Bool IsLoaded() const = 0;

        /**
         * @brief Check if the package is unloaded.
         * @return true if the package is unloaded.
         */
        virtual Bool IsUnloaded() const = 0;

        /**
         * @brief Check if the package failed to load.
         * @return true if the package failed to load.
         */
        virtual Bool HasFailedLoading() const = 0;

        /**
         * @brief Check if the package failed to unload.
         * @return true if the package failed to unload.
         */
        virtual Bool HasFailedUnloading() const = 0;

    protected:
        virtual ~IPackage() {}
    };
}

#endif  // __MURL_I_PACKAGE_H__
