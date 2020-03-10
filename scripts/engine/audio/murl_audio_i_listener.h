// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_AUDIO_I_LISTENER_H__
#define __MURL_AUDIO_I_LISTENER_H__

#include "murl_audio_types.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Audio
    {
        class IObject;
        class IView;

        /**
         * @ingroup MurlAudioObjectInterfaces
         * @interface IListener
         * @brief The IListener audio object interface.
         * This interface represents an audio listener or audio sink, which can
         * be positioned and oriented in 3D world space.
         *
         * Used internally by Graph::Listener.
         */
        class IListener
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
             * @brief Enable the listener.
             * @return true if successful.
             */
            virtual Bool Enable() = 0;
            /**
             * @brief Disable the listener.
             * @return true if successful.
             */
            virtual Bool Disable() = 0;
            
            /**
             * @brief Set the listener's overall volume (gain).
             * @param volume The overall volume, usually in the range 0.0-1.0.
             * @return true if successful.
             */
            virtual Bool SetVolume(Real volume) = 0;
            /**
             * @brief Get the listener's overall volume (gain).
             * @return The overall volume.
             */
            virtual Real GetVolume() const = 0;
            
            /**
             * @brief Set the maximum hearing distance.
             * @param maxDistance The maximum distance.
             * @return true if successful.
             */
            virtual Bool SetMaxDistance(Real maxDistance) = 0;
            /**
             * @brief Get the maximum hearing distance.
             * @return The maximum distance.
             */
            virtual Real GetMaxDistance() const = 0;

            /**
             * @brief Set the listener's distance model used for attenuation calculation.
             * See Graph::Listener.
             * @param distanceModel The distance model to use.
             * @return true if successful.
             */
            virtual Bool SetDistanceModel(IEnums::DistanceModel distanceModel) = 0;
            /**
             * @brief Get the listener's distance model used for attenuation calculation.
             * @return The distance model used.
             */
            virtual IEnums::DistanceModel GetDistanceModel() const = 0;

            /**
             * @brief Set the listener's current world transform.
             * @param transform The world transform matrix.
             * @return true if successful.
             */
            virtual Bool SetWorldTransform(const Matrix& transform) = 0;

            /**
             * @brief Get the listener's current world transform.
             * @return The world transform matrix.
             */
            virtual const Matrix& GetWorldTransform() const = 0;
            /**
             * @brief Get the listener's current view matrix.
             * The view matrix equals the inverse of the transform matrix.
             * @return The view matrix.
             */
            virtual const Matrix& GetViewTransform() const = 0;

            /**
             * @brief Check if the listener's hearing area intersects a given sphere.
             * @param boundingSphere The world-coordinate bounding sphere to check.
             * @return true if the bounding sphere is in hearing range.
             */
            virtual Bool IsIntersecting(const Sphere& boundingSphere) const = 0;

            /**
             * @brief Set the listener view.
             * @param view The view to use.
             * @return true if successful.
             */
            virtual Bool SetView(IView* view) = 0;
            /**
             * @brief Get the listener view.
             * @return The view used.
             */
            virtual IView* GetView() const = 0;

        protected:
            virtual ~IListener() {}
        };
    }
}

#endif // __MURL_AUDIO_I_LISTENER_H__
