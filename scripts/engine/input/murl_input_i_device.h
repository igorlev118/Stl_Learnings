// Copyright 2010-2013 Spraylight GmbH

#ifndef __MURL_INPUT_I_DEVICE_H__
#define __MURL_INPUT_I_DEVICE_H__

#include "murl_input_types.h"

namespace Murl
{
    class IAppConfiguration;

    namespace Input
    {
        /**
         * @ingroup MurlInputInterfaces
         * @interface IDevice
         * @brief The IDevice interface.
         * The base interface of all input device classes.
         */
        class IDevice
        {
        public:
            /**
             * @brief Get the device name.
             * The default device name is "BuiltIn".
             * @return The device name.
             */
            virtual const String& GetName() const = 0;

            /**
             * @brief Get the unique device identifier.
             * @return The unique device identifier.
             */
            virtual UInt32 GetId() const = 0;

            /**
             * @brief Check if the device has received new data since the last Update().
             * @return true if the device has received new data since the last Update().
             */
            virtual Bool HasUpdate() const = 0;

            /**
             * @brief Is executed in the logic thread context each logic tick.
             */
            virtual void LogicUpdate() = 0;

            /**
             * @brief Notification of changed configuration.
             * The notification is executed in the engine thread context
             * if any configuration item has changed.
             * @param appConfig The application configuration object.
             */
            virtual void ConfigChanged(const IAppConfiguration* appConfig) = 0;

        protected:
            virtual ~IDevice() {}
        };
    }
}

#endif  // __MURL_INPUT_I_DEVICE_H__
