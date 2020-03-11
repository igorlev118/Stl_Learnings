// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_LOGIC_I_ENGINE_PROCESSOR_H__
#define __MURL_LOGIC_I_ENGINE_PROCESSOR_H__

#include "murl_logic_i_state.h"
#include "murl_i_enums.h"

namespace Murl
{
    class IPackage;

    namespace Logic
    {
        /**
         * @ingroup MurlLogicInterfaces
         * @interface IEngineProcessor
         * @brief The IEngineProcessor interface.
         * The IEngineProcessor interface defines the entry point from
         * the engine's core to the logic for:
         *  - Initialize / Deinitialize a logic processor by executing Init() / DeInit() methods.
         *  - Perform a logic tick by executing the ProcessTick() and FinishTick() methods.
         *  - Perform a frame tick by executing the ProcessFrame() and FinishFrame() method.
         *  - Notifying package loading states by executing Package[...] methods.
         *  - Notifying application run state changes by executing the RunStateChanged() method.
         */
        class IEngineProcessor
        {
        public:
            /**
             * @brief Initialze the processor.
             * @param state The IState object.
             * @return true if successful.
             */
            virtual Bool Init(const IState* state) = 0;

            /**
             * @brief Deinitialze the processor.
             * @param state The IState object.
             * @return true if successful.
             */
            virtual Bool DeInit(const IState* state) = 0;

            /**
             * @brief Execute a logic tick.
             * @param state The IState object.
             */
            virtual void ProcessTick(const IState* state) = 0;
            /**
             * @brief Execute a frame tick.
             * @param state The IState object.
             */
            virtual void ProcessFrame(const IState* state) = 0;

            /**
             * @brief Finish a logic tick.
             * @param state The IState object.
             */
            virtual void FinishTick(const IState* state) = 0;
            /**
             * @brief Finish a frame tick.
             * @param state The IState object.
             */
            virtual void FinishFrame(const IState* state) = 0;

            /**
             * @brief Report the beginning of package loading.
             * @param state The IState object.
             * @param package The package to load.
             */
            virtual void PackageWillBeLoaded(const IState* state, IPackage* package) = 0;

            /**
             * @brief Report the succesful loading of a package.
             * @param state The IState object.
             * @param package The package loaded.
             */
            virtual void PackageWasLoaded(const IState* state, IPackage* package) = 0;

            /**
             * @brief Report failed loading a package.
             * @param state The IState object.
             * @param package The package which failed loading.
             */
            virtual void PackageFailedLoading(const IState* state, IPackage* package) = 0;

            /**
             * @brief Report the beginning of package unloading.
             * @param state The IState object.
             * @param package The package to unload.
             */
            virtual void PackageWillBeUnloaded(const IState* state, IPackage* package) = 0;

            /**
             * @brief Report the succesful unloading of a package.
             * @param state The IState object.
             * @param package The package unloaded.
             */
            virtual void PackageWasUnloaded(const IState* state, IPackage* package) = 0;

            /**
             * @brief Report failed unloading a package.
             * @param state The IState object.
             * @param package The package which failed unloading.
             */
            virtual void PackageFailedUnloading(const IState* state, IPackage* package) = 0;

            /**
             * @brief Report a change of the application run state.
             * @param state The IState object.
             * @param currentState The current run state.
             * @param previousState The previous run state.
             */
            virtual void RunStateChanged(const IState* state, IEnums::AppRunState currentState,
                                         IEnums::AppRunState previousState) = 0;

        protected:
            virtual ~IEngineProcessor() {}
        };
    }
}

#endif // __MURL_LOGIC_I_ENGINE_PROCESSOR_H__
