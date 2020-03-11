// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_AUDIO_I_VIEW_H__
#define __MURL_AUDIO_I_VIEW_H__

#include "murl_video_types.h"

namespace Murl
{
    namespace Audio
    {
        class IObject;

        /**
         * @ingroup MurlAudioObjectInterfaces
         * @interface IView
         * @brief The IView audio object interface.
         */
        class IView
        {
        public:
            /**
             * @brief Get the mutable Audio::IObject interface.
             * @return The IObject interface.
             */
            virtual IObject* GetObjectInterface() = 0;
            /**
             * @brief Get the constant Audio::IObject interface.
             * @return The IObject interface.
             */
            virtual const IObject* GetObjectInterface() const = 0;

            /**
             * @brief Set the depth (sorting) order.
             * @param depthOrder The sorting order.
             * @return true if successful.
             */
            virtual Bool SetDepthOrder(SInt32 depthOrder) = 0;
            /**
             * @brief Get the depth (sorting) order.
             * @return The sorting order.
             */
            virtual SInt32 GetDepthOrder() const = 0;
            
        protected:
            virtual ~IView() {}
        };
    }
}

#endif // __MURL_AUDIO_I_VIEW_H__
