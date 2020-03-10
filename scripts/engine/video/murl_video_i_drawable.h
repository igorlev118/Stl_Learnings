// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_VIDEO_I_DRAWABLE_H__
#define __MURL_VIDEO_I_DRAWABLE_H__

#include "murl_video_types.h"

namespace Murl
{
    namespace Video
    {
        class IObject;

        /**
         * @ingroup MurlVideoObjectInterfaces
         * @interface IDrawable
         * @brief The IDrawable video object interface.
         * This is the base class of a drawable object.
         */
        class IDrawable
        {
        public:
            /**
             * @brief Get the mutable Video::IObject interface.
             * @return The IObject interface.
             */
            virtual IObject* GetObjectInterface() = 0;
            /**
             * @brief Get the constant Video::IObject interface.
             * @return The IObject interface.
             */
            virtual const IObject* GetObjectInterface() const = 0;

            /**
             * @brief Draw the object.
             * @return true if successful.
             */
            virtual Bool Draw() = 0;

            /**
             * @brief Check if the drawable allows for dynamic batching.
             * @return true if dynamic batching is allowed.
             */
            virtual Bool IsDynamicBatchingAllowed() const = 0;
            
            /**
             * @brief Check if the drawable is actually containing any geometry data.
             * @return true if the object has data to draw.
             */
            virtual Bool HasDataToDraw() const = 0;

            /**
             * @brief Get the number of bones affecting the drawable.
             * @return The number of bones needed.
             */
            virtual UInt32 GetNumberOfBones() const = 0;

            /**
             * @brief Get the drawable's signature.
             * @return The signature.
             */
            virtual UInt32 GetSignature() const = 0;
            
        protected:
            virtual ~IDrawable() {}
        };
    }
}

#endif // __MURL_VIDEO_I_DRAWABLE_H__
