// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_VIDEO_I_OBJECT_H__
#define __MURL_VIDEO_I_OBJECT_H__

#include "murl_video_types.h"
#include "murl_i_factory_object.h"
#include "murl_string.h"

namespace Murl
{
    namespace Video
    {
        class IRenderer;
        
        /**
         * @ingroup MurlVideoObjectInterfaces
         * @interface IObject
         * @brief The base interface for all video objects.
         */
        class IObject : public IFactoryObject<IObject>
        {
        public:
            typedef IObject* (*CreateFunction)(IRenderer*);

        public:
            /**
             * @brief Get the mutable IObject interface.
             * @return The IObject interface.
             */
            virtual IObject* GetObjectInterface() = 0;
            /**
             * @brief Get the constant IObject interface.
             * @return The IObject interface.
             */
            virtual const IObject* GetObjectInterface() const = 0;

            /**
             * @brief Set the initial suspension state hint.
             * If the initial suspension state is set to true, the object does not
             * create any GPU-bound resources until it is actually referenced during
             * rendering, if it supports this feature.
             * @param suspended The initial suspension state.
             * @return true if successful.
             */
            virtual Bool SetInitiallySuspended(Bool suspended) = 0;
            /**
             * @brief Enable/disable automatic suspension, if supported.
             * When automatic suspension is enabled, the object destroys its internally
             * held GPU-bound resources whenever it has not been used during rendering
             * of the most recent frame. The next time it is used again, all necessary
             * resources are restored. Care must be taken not to enable this feature
             * for objects that get activated and deactivated frequently, otherwise
             * a lot of overhead is generated for destroying and recreating its resources.
             * @param enabled If true, automatic suspension is enabled.
             * @return true if successful.
             */
            virtual Bool SetAutomaticallySuspendableEnabled(Bool enabled) = 0;
            /**
             * @brief Enable/disable manual suspension, if supported.
             * When manual suspension is enabled, the object destroys its internally
             * held GPU-bound resources whenever the object's owning renderer received a
             * manual cleanup trigger via its BeginRendering() method.
             * @param enabled If true, manual suspension is enabled.
             * @return true if successful.
             */
            virtual Bool SetManuallySuspendableEnabled(Bool enabled) = 0;
            
            /**
             * @brief Initialize this object.
             * Called by the IRenderer owning this object.
             * @return true if successful.
             */
            virtual Bool Init() = 0;
            /**
             * @brief De-initialize this object.
             * Called by the IRenderer owning this object.
             * @return true if successful.
             */
            virtual Bool DeInit() = 0;
            
            /**
             * @brief Suspend this object.
             * Called by the IRenderer owning this object.
             * @return true if successful.
             */
            virtual Bool Suspend() = 0;
            /**
             * @brief Resume this object.
             * Called by the IRenderer owning this object.
             * @return true if successful.
             */
            virtual Bool Resume() = 0;

            /**
             * @brief Evict any additional resources held by the object, if possible.
             * In addition to GPU resource suspension, this method also triggers an eviction
             * of any system memory resources (if possible) to free up even more memory.
             * Called by the IRenderer owning this object.
             * @return true if successful.
             */
            virtual Bool Evict() = 0;

            /**
             * @brief Update the object.
             * Called by the IRenderer owning this object.
             * @param localTime The time stamp used.
             * @return true if successful.
             */
            virtual Bool Update(Real localTime) = 0;

            /**
             * @brief Check if this object is initialized.
             * @return true if initialized.
             */
            virtual Bool IsInitialized() const = 0;
            /**
             * @brief Check if this object is suspended.
             * @return true if suspended.
             */
            virtual Bool IsSuspended() const = 0;

            /**
             * @brief Get the global number of the frame the object was most recently used in.
             * @return The most recent frame number.
             */
            virtual UInt32 GetRecentFrameCount() const = 0;

        protected:
            virtual ~IObject() {}
        };
    }
}

#endif // __MURL_VIDEO_I_OBJECT_H__
