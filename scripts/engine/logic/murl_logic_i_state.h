// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_LOGIC_I_STATE_H__
#define __MURL_LOGIC_I_STATE_H__

#include "murl_logic_types.h"

namespace Murl
{
    class IPlatformConfiguration;
    class IEngineConfiguration;
    class IAppConfiguration;
    class IFileInterface;
    class ILoader;

    namespace Core
    {
        class IStatistics;
    }

    namespace Graph
    {
        class INode;
        class IRoot;
    }

    namespace Net
    {
        class IFactory;
    }

    namespace Resource
    {
        class ICollection;
        class IFactory;
    }

    namespace Logic
    {
        class IFactory;
        class IDeviceHandler;

        /**
         * @ingroup MurlLogicInterfaces
         * @interface IState
         * @brief The IState interface.
         * The IState object contains all necessary engine interfaces for
         * logic processor programming.
         * \n
         * Logic methods typically gets an instance of the IState object by parameter.
         */
        class IState
        {
        public:
            /**
             * @brief Get the logic object factory.
             * @return The logic object factory.
             */
            virtual IFactory* GetFactory() const = 0;

            /**
             * @brief Get the current tick time.
             * The current tick time is the absolute time from starting the engine.
             * @return The current tick time in seconds.
             */
            virtual Double GetCurrentTickTime() const = 0;

            /**
             * @brief Get the current tick duration.
             * @return The current tick duration in seconds.
             */
            virtual Double GetCurrentTickDuration() const = 0;

            /**
             * @brief Get the platform configuration object.
             * @return The configuration object.
             */
            virtual const IPlatformConfiguration* GetPlatformConfiguration() const = 0;
            /**
             * @brief Get the engine configuration object.
             * @return The configuration object.
             */
            virtual const IEngineConfiguration* GetEngineConfiguration() const = 0;
            /**
             * @brief Get the app configuration object.
             * @return The configuration object.
             */
            virtual IAppConfiguration* GetAppConfiguration() const = 0;

            /**
             * @brief Get the device handler object.
             * @return The device handler object.
             */
            virtual Logic::IDeviceHandler* GetDeviceHandler() const = 0;

            /**
             * @brief Get the file interface object.
             * @return The file interface object.
             */
            virtual IFileInterface* GetFileInterface() const = 0;

            /**
             * @brief Get the graph root object.
             * @return The graph root object.
             */
            virtual Graph::IRoot* GetGraphRoot() const = 0;

            /**
             * @brief Get the package loader object.
             * @return The package loader object.
             */
            virtual ILoader* GetLoader() const = 0;

            /**
             * @brief Get the resource collection object.
             * @return The resource collection object.
             */
            virtual const Resource::ICollection* GetResourceCollection() const = 0;
            /**
             * @brief Get the resource factory.
             * @return The resource factory.
             */
            virtual const Resource::IFactory* GetResourceFactory() const = 0;

            /**
             * @brief Get the string value from a text resource.
             * @param resourceId The text resource identifier.
             * @return The string value of the text resource or
             *  an empty string if the resource is not available.
             */
            virtual const String& GetResourceText(const String& resourceId) const = 0;

            /**
             * @brief Get the net object factory.
             * @return The net object factory.
             */
            virtual Net::IFactory* GetNetFactory() const = 0;

            /**
             * @brief Get the core statistics interface.
             * @return The core statistics interface.
             */
            virtual const Core::IStatistics* GetStatistics() const = 0;

            /**
             * @brief Set the user debug message on render screen.
             * The debug message is displayed if the built-in "debug" resource package is loaded.
             * See also IAppConfiguration::SetUserDebugInfoEnabled() and
             * IAppConfiguration::SetUserDebugInfoScaleFactor().
             * @param message The message string.
             */
            virtual void SetUserDebugMessage(const String& message) const = 0;

            /**
             * @brief Append a user debug message on render screen.
             * The debug message is displayed if the built-in "debug" resource package is loaded.
             * @param message The message string to append.
             */
            virtual void AddUserDebugMessage(const String& message) const = 0;

            /**
             * @brief Get the user debug message string.
             * @return The user debug message string.
             */
            virtual String GetUserDebugMessage() const = 0;

            /**
             * @brief Get the current logic processor.
             * The current logic processor is not available on IAppGraph calls.
             * @return The current logic processor.
             */
            virtual IProcessorPtr GetCurrentProcessor() const = 0;

            /**
             * @brief Get the current graph node object.
             * The current graph node is available on IAppGraph calls only.
             * @return The current graph node object or null.
             */
            virtual Graph::INode* GetCurrentGraphNode() const = 0;

            /**
             * @brief Set the current logic processor.
             * The current processor is typically set by the engine.
             * @param processor The current logic processor to set.
             */
            virtual void SetCurrentProcessor(IProcessorPtr processor) = 0;

        protected:
            virtual ~IState() {}
        };
    }
}

#endif // __MURL_LOGIC_I_STATE_H__
