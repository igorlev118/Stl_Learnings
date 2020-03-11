// Copyright 2010-2015 Spraylight GmbH

#ifndef __MURL_I_LOADER_H__
#define __MURL_I_LOADER_H__

#include "murl_logic_types.h"
#include "murl_i_enums.h"

namespace Murl
{
    class IPackage;

    /**
     * @ingroup MurlInterfaces
     * @interface ILoader
     * @brief The loader interface.
     * The loader is a thread which provides functionality for loading and unloading
     * resource packages parallel to the engine's logic and rendering processing.
     *
     * The IEngineConfiguration::SetResourceFileCategory() setting specifies the
     * working directory for the loader.
     *
     * The ILoader object is provided by the IAppState and the Logic::IState object.
     */
    class ILoader
    {
    public:
        /**
         * @brief Definition of the load operation modes.
         */
        enum LoadMode
        {
            /** @brief Load the package before engine startup. */
            LOAD_MODE_STARTUP,
            /** @brief Load the package immediately in background. */
            LOAD_MODE_BACKGROUND,
            /** @brief Load the package on demand using the IPackage. */
            LOAD_MODE_ON_DEMAND,

            NUM_LOAD_MODES
        };

        /**
         * @brief Add a logic processor without a package.
         * Logic processors without a package can be added before startup only.
         * @param processor The logic processor to add.
         * @return true if successful.
         */
        virtual Bool AddProcessor(Logic::IProcessorPtr processor) = 0;

        /**
         * @brief Remove a logic processor added by AddProcessor().
         * @param processor The logic processor to remove.
         * @return true if successful.
         */
        virtual Bool RemoveProcessor(Logic::IProcessorPtr processor) = 0;

        /**
         * @brief Create and register a package by name.
         * @param packageName The name of the package.
         * @param mode The load mode.
         * @return The package object or null if creating the package failed.
         */
        virtual IPackage* AddPackage(const String& packageName, LoadMode mode) = 0;

        /**
         * @brief Create and register a package by name and a corresponding logic processor.
         * @param packageName The name of the package.
         * @param mode The load mode.
         * @param processor The corresponding logic processor.
         * @return The package object or null if creating the package failed.
         */
        virtual IPackage* AddPackage(const String& packageName, LoadMode mode,
                                     Logic::IProcessorPtr processor) = 0;

        /**
         * @brief Create and register a package by name and category.
         * @param packageName The name of the package.
         * @param category The file category.
         * @param mode The load mode.
         * @return The package object or null if creating the package failed.
         */
        virtual IPackage* AddPackage(const String& packageName,
                                     IEnums::FileCategory category,
                                     LoadMode mode) = 0;

        /**
         * @brief Create and register a package by name, category and a corresponding logic processor.
         * @param packageName The name of the package.
         * @param category The file category.
         * @param mode The load mode.
         * @param processor The corresponding logic processor.
         * @return The package object or null if creating the package failed.
         */
        virtual IPackage* AddPackage(const String& packageName,
                                     IEnums::FileCategory category,
                                     LoadMode mode,
                                     Logic::IProcessorPtr processor) = 0;

        /**
         * @brief Remove a registered package by name.
         * A package can be removed only if package is unloaded.
         * @param packageName The name of the package to remove.
         * @return true if successful.
         */
        virtual Bool RemovePackage(const String& packageName) = 0;

        /**
         * @brief Get a registered package of a specified package name.
         * @param packageName The name of the package.
         * @return The package object or null if the package name is not registered.
         */
        virtual IPackage* GetPackage(const String& packageName) const = 0;
        /**
         * @brief Get a registered package connected to a given processor.
         * @param processor The processor to query.
         * @return The package object or null if no package is connected to the processor.
         */
        virtual IPackage* GetPackage(Logic::IProcessorPtr processor) const = 0;

        /**
         * @brief Query a registered package.
         * This method takes a number of pointers to individual variables that receive
         * the results of the query. It is allowed to pass null pointers to any of these
         * variables in case the specific item is not of interest.
         * @param packageName The name of the package.
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
        virtual Bool QueryPackage(const String& packageName,
                                  String* id,
                                  UInt32* revision,
                                  Bool* isDataValid,
                                  Bool* isVersionValid,
                                  Bool* isChecksumValid) const = 0;

        /**
         * @brief Load a registered package.
         * @param packageName The name of the package.
         * @return The result of IPackage::Load() or
         *  false if the package name is not registered.
         */
        virtual Bool LoadPackage(const String& packageName) const = 0;

        /**
         * @brief Load a registered package.
         * @param packageName The name of the package.
         * @return The result of IPackage::Unload() or
         *  false if the package name is not registered.
         */
        virtual Bool UnloadPackage(const String& packageName) const = 0;

    protected:
        virtual ~ILoader() {}
    };
}

#endif  // __MURL_I_LOADER_H__
