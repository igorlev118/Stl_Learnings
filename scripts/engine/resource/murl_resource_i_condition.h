// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_RESOURCE_I_CONDITION_H__
#define __MURL_RESOURCE_I_CONDITION_H__

#include "murl_types.h"

namespace Murl
{
    class IAppConfiguration;

    namespace Resource
    {
        /**
         * @ingroup MurlResourceMiscInterfaces
         * @interface ICondition
         * @brief The ICondition resource interface.
         * The condition interface represents a mechanism for checking if a resource
         * is valid for a given configuration, queried via an IAppConfiguration object.
         * The resource may contain any number of tag key/value pairs, which specify the
         * individual configuration item(s) to check. All of the given values must
         * match the given configuration for the resource to be valid.
         */
        class ICondition
        {
        public:
            /// Condition tags
            enum Tag
            {
                /// Current language, see IAppConfiguration::IsLanguageMatching().
                TAG_LANGUAGE,
                /// Target class, see IPlatformConfiguration::IsTargetClassMatching().
                TAG_TARGET_CLASS,
                /// Target device, see IPlatformConfiguration::IsTargetDeviceMatching().
                TAG_TARGET_DEVICE,
                /// Operating system, see IPlatformConfiguration::IsOperatingSystemMatching().
                TAG_OPERATING_SYSTEM,
                /// GPU, see IPlatformConfiguration::IsGpuMatching().
                TAG_GPU,
                /// Texture prescale factor, see IEngineConfiguration::IsTexturePrescaleDivisorMatching().
                TAG_PRESCALE_FACTOR,
                /// Selected video API, see IEngineConfiguration::IsVideoApiMatching().
                TAG_VIDEO_API,
                /// Selected audio API, see IEngineConfiguration::IsAudioApiMatching().
                TAG_AUDIO_API,
                /// Engine features, see IEngineConfiguration::GetFeatures().
                TAG_FEATURE,
                /// User-defined configuration, see IAppConfiguration::IsUserConfigurationMatching().
                TAG_USER_CONFIGURATION,
                /// Target host, see IPlatformConfiguration::IsTargetHostMatching().
                TAG_TARGET_HOST,

                /// Bit mask for tag value.
                TAG_VALUE_MASK   = 0xffffff,

                /// Bit mask for tag key.
                TAG_KEY_MASK     = 0x1f,
                /// Tag key flag to combine multiple tags of the same type.
                TAG_COMBINE_MASK = 0x20,
                /// Tag key flag to include the given value in the valid configuration set.
                TAG_INCLUDE_MASK = 0x40,
                /// Tag key flag to exclude the given value from the valid configuration set.
                TAG_EXCLUDE_MASK = 0x80,

                /// Number of bits to shift the tag key to the left.
                TAG_SHIFT = 24
            };

            /**
             * @brief Check if the condition holds for a given configuration.
             * @param appConfig The configuration object to check against.
             * @return true if the condition holds.
             */
            virtual Bool IsValidForConfiguration(const IAppConfiguration* appConfig) const = 0;

            /**
             * @brief Get a raw pointer to the tags.
             * @return A pointer to the tags, or null if none are defined.
             */
            virtual const UInt32* GetTags() const = 0;
            /**
             * @brief Get the number of tags present.
             * @return The number of tags.
             */
            virtual UInt32 GetNumberOfTags() const = 0;

            /**
             * @brief Get a raw pointer to the user-defined configuration strings.
             * @return A pointer to the C string array, or null if none are defined.
             */
            virtual const Char* const* GetStrings() const = 0;
            /**
             * @brief Get the number of user-defined configuration strings.
             * @return The number of strings.
             */
            virtual UInt32 GetNumberOfStrings() const = 0;

        protected:
            virtual ~ICondition() {}
        };
    }
}

#endif  // __MURL_RESOURCE_I_CONDITION_H__
