// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_UTIL_FEATURE_SET_H__
#define __MURL_UTIL_FEATURE_SET_H__

#include "murl_i_feature_set.h"
#include "murl_bitfield.h"

namespace Murl
{
    namespace Util
    {
        class FeatureSet : public IFeatureSet
        {
        public:
            FeatureSet();
            virtual ~FeatureSet();
            
            virtual void SetFeatureAvailable(IEnums::Feature feature, Bool available);
            virtual void ForceFeatureAvailable(IEnums::Feature feature, Bool available);
            virtual Bool IsFeatureAvailable(IEnums::Feature feature) const;
            
        protected:
            Bitfield mFeatureBitfield;
            Bitfield mForcedSetBitfield;
            Bitfield mForcedClearBitfield;
        };
    }
}

#endif  // __MURL_UTIL_FEATURE_SET_H__
