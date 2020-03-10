// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_I_FEATURE_SET_H__
#define __MURL_I_FEATURE_SET_H__

#include "murl_types.h"
#include "murl_i_enums.h"

namespace Murl
{
    /**
     * @ingroup MurlInterfaces
     * @interface IFeatureSet
     * @brief The IFeatureSet interface.
     */
    class IFeatureSet
    {
    public:
        /**
         * @brief Set the availability of a feature.
         * @param feature The feature enumeration value.
         * @param available The availability to set, true if the feature is available.
         */
        virtual void SetFeatureAvailable(IEnums::Feature feature, Bool available) = 0;

        /**
         * @brief Force the availability of a feature.
         * This overrides the setting of a feature defined via SetFeatureAvailable().
         * @param feature The feature enumeration value.
         * @param available If true, the feature is always present, otherwise it is
         *  never present.
         */
        virtual void ForceFeatureAvailable(IEnums::Feature feature, Bool available) = 0;

        /**
         * @brief Check if a feature is available.
         * @param feature The feature enumeration value.
         * @return true if the fetature is available.
         */
        virtual Bool IsFeatureAvailable(IEnums::Feature feature) const = 0;
        
    protected:
        virtual ~IFeatureSet() {}
    };
}

#endif  // __MURL_I_FEATURE_SET_H__
