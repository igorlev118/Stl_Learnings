// Copyright 2012-2014 Spraylight GmbH

#ifndef __MURL_LOGIC_I_ENGINE_FACTORY_H__
#define __MURL_LOGIC_I_ENGINE_FACTORY_H__

#include "murl_logic_i_engine_state.h"

namespace Murl
{
    namespace Input
    {
        class IDeviceHandler;
    }
    namespace Output
    {
        class IDeviceHandler;
    }

    namespace Logic
    {
        class IFactory;

        /**
         * @ingroup MurlLogicInterfaces
         * @interface IEngineFactory
         * @brief The IEngineFactory interface.
         * The IEngineFactory object is created and used by the engine's core only.
         * Application implementations are using the IFactory object from
         * IState::GetFactory() which is passed via the IEngineProcessor methods.
         */
        class IEngineFactory
        {
        public:
            /**
             * @brief Initialize the factory.
             * @return true if successful.
             */
            virtual Bool Init() = 0;
            /**
             * @brief Deinitialize the factory.
             * @return true if successful.
             */
            virtual Bool DeInit() = 0;

            /**
             * @brief Create the engine state object.
             * @param deviceHandler The device handler object.
             * @param appConfig The application configuration object.
             * @param loader The loader object.
             * @param fileInterface The file interface object.
             * @param resourceFactory The resource factory.
             * @param netFactory The net object factory.
             * @param statistics The core statistics object.
             * @return The created engine state object, or null if failed.
             */
            virtual IEngineState* CreateEngineState(IDeviceHandler* deviceHandler, IAppConfiguration* appConfig,
                                                    ILoader* loader, IFileInterface* fileInterface,
                                                    Resource::IFactory* resourceFactory, Net::IFactory* netFactory,
                                                    const Core::IStatistics* statistics) = 0;
            /**
             * @brief Destroy the engine state object.
             * @param engineState A reference to the engine state pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            virtual Bool DestroyEngineState(IEngineState*& engineState) = 0;

            /**
             * @brief Create the device handler object.
             * @param inputDeviceHandler The input device handler object.
             * @param outputDeviceHandler The output device handler object.
             * @return The created device handler object, or null if failed.
             */
            virtual IDeviceHandler* CreateDeviceHandler(Input::IDeviceHandler* inputDeviceHandler,
                                                        Output::IDeviceHandler* outputDeviceHandler) = 0;
            /**
             * @brief Destroy the device handler object.
             * @param deviceHandler A reference to the device handler pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            virtual Bool DestroyDeviceHandler(IDeviceHandler*& deviceHandler) = 0;

            /**
             * @brief Get the IFactory object.
             * @return The IFactory object.
             */
            virtual IFactory* GetIFactory() = 0;

        protected:
            virtual ~IEngineFactory() {}
        };

        /**
         * @ingroup MurlLogicClasses
         * @brief The StaticEngineFactory class to create the IEngineFactory object.
         * The StaticEngineFactory is used by the engine's core only.
         */
        class StaticEngineFactory
        {
        public:
            /**
             * @brief Create the engine factory object.
             * @return The created engine factory object, or null if failed.
             */
            static IEngineFactory* CreateEngineFactory();
            /**
             * @brief Destroy the engine factory object.
             * @param engineFactory A reference to the engine factory pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            static Bool DestroyEngineFactory(IEngineFactory*& engineFactory);
        };
    }
}

#endif  // __MURL_LOGIC_I_ENGINE_FACTORY_H__
