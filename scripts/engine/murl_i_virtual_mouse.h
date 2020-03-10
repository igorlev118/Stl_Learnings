// Copyright 2015 Spraylight

#ifndef __MURL_I_VIRTUAL_MOUSE_H__
#define __MURL_I_VIRTUAL_MOUSE_H__

#include "murl_i_enums.h"
#include "murl_raw_button_codes.h"

namespace Murl
{
    /**
     * @ingroup MurlDeviceInterfaces
     * @interface IVirtualMouse
     * @brief The virtual mouse device interface.
     * Used by the input device handler to configure the device.
     * Used by the platform to get information of the device.
     */
    class IVirtualMouse
    {
    public:
        /**
         * @brief Set the mouse button to map for a raw button.
         * The default mapping is (for AppleTV Siri Remote):
         *  - IEnums::MOUSE_BUTTON_LEFT <- RAWBUTTON_SELECT
         *  - IEnums::MOUSE_BUTTON_RIGHT <- RAWBUTTON_MENU
         *  - IEnums::MOUSE_BUTTON_MIDDLE <- RAWBUTTON_PLAY_PAUSE
         * @param mouseButton The mouse button code.
         * @param rawButton The raw button code.
         * @return true if successful.
         */
        virtual Bool SetRawButtonMapping(IEnums::MouseButton mouseButton, RawButtonCode rawButton) = 0;

        /**
         * @brief Get the mouse button to map for a raw button.
         * @param rawButton The raw button code.
         * @return The mouse button code.
         */
        virtual IEnums::MouseButton GetRawButtonMapping(RawButtonCode rawButton) const = 0;

        /**
         * @brief Set the sensivity for the x-axis.
         * The default value is 1.0
         * @param factor The sensivity factor for the x-axis
         * @return true if successful.
         */
        virtual Bool SetSensivityX(Real factor) = 0;

        /**
         * @brief Get the sensivity for the x-axis.
         * @return The sensivity factor for the x-axis
         */
        virtual Real GetSensivityX() const = 0;

        /**
         * @brief Set the sensivity for the y-axis.
         * The default value is 1.0
         * @param factor The sensivity factor for the y-axis
         * @return true if successful.
         */
        virtual Bool SetSensivityY(Real factor) = 0;

        /**
         * @brief Get the sensivity for the y-axis.
         * @return The sensivity factor for the y-axis
         */
        virtual Real GetSensivityY() const = 0;

    protected:
        virtual ~IVirtualMouse() {}
    };
}

#endif  // __MURL_I_VIRTUAL_MOUSE_H__
