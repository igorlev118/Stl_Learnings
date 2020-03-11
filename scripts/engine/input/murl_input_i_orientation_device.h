// Copyright 2010-2013 Spraylight GmbH

#ifndef __MURL_INPUT_I_ORIENTATION_DEVICE_H__
#define __MURL_INPUT_I_ORIENTATION_DEVICE_H__

#include "murl_input_i_device.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Input
    {
        /**
         * @ingroup MurlInputInterfaces
         * @interface IOrientationDevice
         * @brief The IOrientationDevice interface.
         * To receive data the device must be activated by
         * IAppConfiguration::SetOrientationActive().
         */
        class IOrientationDevice : public IDevice
        {
        public:
            /**
             * @brief Get the current device orientation.
             * @return true The current device orientation.
             */
            virtual IEnums::SensorOrientation GetOrientation() const = 0;

        protected:
            virtual ~IOrientationDevice() {}
        };
    }
}

#endif  // __MURL_INPUT_I_ORIENTATION_DEVICE_H__
