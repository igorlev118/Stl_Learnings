// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_I_TELEPHONY_CONTROL_H__
#define __MURL_I_TELEPHONY_CONTROL_H__

#include "murl_i_controlable.h"

namespace Murl
{
    /**
     * @ingroup MurlControlInterfaces
     * @interface ITelephonyControl
     * @brief The ITelephonyControl interface.
     */
    class ITelephonyControl : public IControlable
    {
    public:
        /**
         * @brief Get the human-readable name of the network operator.
         * @return The network operator name.
         */
        virtual String GetCarrierName() const = 0;
        /**
         * @brief Get the mobile country code of the SIM provider
         * @return The mobile country code.
         */
        virtual String GetCountryCode() const = 0;
        /**
         * @brief Get the mobile network code of the SIM provider
         * @return The mobile network code.
         */
        virtual String GetNetworkCode() const = 0;
        
    protected:
        virtual ~ITelephonyControl() {}
    };
}

#endif  // __MURL_I_TELEPHONY_CONTROL_H__
