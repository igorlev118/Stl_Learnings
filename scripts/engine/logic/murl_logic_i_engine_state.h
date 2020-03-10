// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_LOGIC_I_ENGINE_STATE_H__
#define __MURL_LOGIC_I_ENGINE_STATE_H__

#include "murl_logic_i_state.h"
#include "murl_i_enums.h"

namespace Murl
{
    class IPackage;

    namespace Logic
    {
        /**
         * @ingroup MurlLogicInterfaces
         * @interface IEngineState
         * @brief The IEngineState interface.
         * The IEngineState object is created and used by the engine's core only.
         * Application implementations are using the IState object which is
         * passed via the IEngineProcessor methods.
         */
        class IEngineState
        {
        public:
            /**
             * @brief Initialize the state object.
             * @return true if successful.
             */
            virtual Bool Init() = 0;
            /**
             * @brief Deinitialize the state object.
             * @return true if successful.
             */
            virtual Bool DeInit() = 0;

            /**
             * @brief Lock the state object.
             * @return true if successful.
             */
            virtual Bool Lock() = 0;
            /**
             * @brief Unlock the state object.
             * @return true if successful.
             */
            virtual Bool Unlock() = 0;

            /**
             * @brief Set the graph root object.
             * @param graphRoot The graph root object.
             */
            virtual void SetGraphRoot(Graph::IRoot* graphRoot) = 0;

            /**
             * @brief Set the resource collection object.
             * @param resourceCollection The resource collection object.
             */
            virtual void SetResourceCollection(const Resource::ICollection* resourceCollection) = 0;

            /**
             * @brief Set the current tick time.
             * The current tick time is the absolute time from starting the engine.
             * @param time The current tick time in seconds.
             */
            virtual void SetCurrentTickTime(Double time) = 0;
            /**
             * @brief Set the current tick duration.
             * @param time The current tick duration in seconds.
             */
            virtual void SetCurrentTickDuration(Double time) = 0;

            /**
             * @brief Set the current graph node object.
             * @param node The graph node object.
             * The current graph node is set for IAppGraph calls only.
             */
            virtual void SetCurrentGraphNode(Graph::INode* node) = 0;

            /**
             * @brief Initialze a processor.
             * @param processor The logic processor to initialize.
             * @return true if successful.
             */
            virtual Bool InitProcessor(IProcessorPtr processor) = 0;
            /**
             * @brief Deinitialze a processor.
             * @param processor The logic processor to deinitialize.
             * @return true if successful.
             */
            virtual Bool DeInitProcessor(IProcessorPtr processor) = 0;

            /**
             * @brief Add a logic processor.
             * @param processor The logic processor to add.
             * @return true if successful.
             */
            virtual Bool AddProcessor(IProcessorPtr processor) = 0;
            /**
             * @brief Remove a logic processor.
             * @param processor The logic processor to remove.
             * @return true if successful.
             */
            virtual Bool RemoveProcessor(IProcessorPtr processor) = 0;

            /**
             * @brief Get the number of logic processors.
             * @return The number of logic processor.
             */
            virtual UInt32 GetNumberOfProcessors() const = 0;
            /**
             * @brief Get an logic processor by index.
             * A valid index is [0 .. GetNumberOfEngineProcessors() - 1].
             * @param index The zero-based index of the logic processor.
             * @return The logic processor object or null if the index is out of range.
             */
            virtual IProcessorPtr GetProcessor(UInt32 index) const = 0;

            /**
             * @brief Execute a logic tick.
             * A valid index is [0 .. GetNumberOfEngineProcessors() - 1].
             * @param index The zero-based index of the logic processor.
             */
            virtual void ProcessTick(UInt32 index) = 0;
            /**
             * @brief Execute a frame tick.
             * A valid index is [0 .. GetNumberOfEngineProcessors() - 1].
             * @param index The zero-based index of the logic processor.
             */
            virtual void ProcessFrame(UInt32 index) = 0;

            /**
             * @brief Finish a logic tick.
             * A valid index is [0 .. GetNumberOfEngineProcessors() - 1].
             * @param index The zero-based index of the logic processor.
             */
            virtual void FinishTick(UInt32 index) = 0;
            /**
             * @brief Finish a frame tick.
             * A valid index is [0 .. GetNumberOfEngineProcessors() - 1].
             * @param index The zero-based index of the logic processor.
             */
            virtual void FinishFrame(UInt32 index) = 0;

            /**
             * @brief Report the beginning of package loading.
             * A valid index is [0 .. GetNumberOfEngineProcessors() - 1].
             * @param index The zero-based index of the logic processor.
             * @param package The package to load.
             */
            virtual void PackageWillBeLoaded(UInt32 index, IPackage* package) = 0;

            /**
             * @brief Report the succesful loading of a package.
             * A valid index is [0 .. GetNumberOfEngineProcessors() - 1].
             * @param index The zero-based index of the logic processor.
             * @param package The package loaded.
             */
            virtual void PackageWasLoaded(UInt32 index, IPackage* package) = 0;

            /**
             * @brief Report failed loading a package.
             * A valid index is [0 .. GetNumberOfEngineProcessors() - 1].
             * @param index The zero-based index of the logic processor.
             * @param package The package which failed loading.
             */
            virtual void PackageFailedLoading(UInt32 index, IPackage* package) = 0;

            /**
             * @brief Report the beginning of package unloading.
             * A valid index is [0 .. GetNumberOfEngineProcessors() - 1].
             * @param index The zero-based index of the logic processor.
             * @param package The package to unload.
             */
            virtual void PackageWillBeUnloaded(UInt32 index, IPackage* package) = 0;

            /**
             * @brief Report the succesful unloading of a package.
             * A valid index is [0 .. GetNumberOfEngineProcessors() - 1].
             * @param index The zero-based index of the logic processor.
             * @param package The package unloaded.
             */
            virtual void PackageWasUnloaded(UInt32 index, IPackage* package) = 0;

            /**
             * @brief Report failed unloading a package.
             * A valid index is [0 .. GetNumberOfEngineProcessors() - 1].
             * @param index The zero-based index of the logic processor.
             * @param package The package which failed unloading.
             */
            virtual void PackageFailedUnloading(UInt32 index, IPackage* package) = 0;

            /**
             * @brief Report a change of the application run state.
             * A valid index is [0 .. GetNumberOfEngineProcessors() - 1].
             * @param index The zero-based index of the logic processor.
             * @param currentState The current run state.
             * @param previousState The previous run state.
             */
            virtual void RunStateChanged(UInt32 index, IEnums::AppRunState currentState,
                                         IEnums::AppRunState previousState) = 0;

            /**
             * @brief Get the constant IState object.
             * @return The constant IState object.
             */
            virtual const IState* GetIState() const = 0;

        protected:
            virtual ~IEngineState() {}
        };
    }
}

#endif // __MURL_LOGIC_I_ENGINE_STATE_H__
