// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_RESOURCE_CONDITION_H__
#define __MURL_RESOURCE_CONDITION_H__

#include "murl_resource_i_condition.h"

namespace Murl
{
    namespace Resource
    {
        class Condition : public ICondition
        {
        public:
            Condition();
            Condition(const Condition& other);
            Condition(const ICondition* other);
            Condition(const UInt32* tags, UInt32 numberOfTags, const Char* const* strings, UInt32 numberOfStrings);
            virtual ~Condition();

            virtual Bool IsValidForConfiguration(const IAppConfiguration* appConfig) const;

            virtual const UInt32* GetTags() const;
            virtual UInt32 GetNumberOfTags() const;

            virtual const Char* const* GetStrings() const;
            virtual UInt32 GetNumberOfStrings() const;
            
        protected:
            void Set(const UInt32* tags, UInt32 numberOfTags, const Char* const* strings, UInt32 numberOfStrings);

            Bool IsTagMatching(UInt32 tagKey, UInt32 tagValue, const IAppConfiguration* appConfig) const;
            Bool IsUserConfigTagMatching(UInt32 tagValue, const IAppConfiguration* appConfig) const;

            UInt32* mTags;
            UInt32 mNumberOfTags;

            const Char* const* mStrings;
            UInt32 mNumberOfStrings;
        };
    }
}

#endif  // __MURL_RESOURCE_CONDITION_H__
