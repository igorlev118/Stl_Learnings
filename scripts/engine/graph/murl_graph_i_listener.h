// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_LISTENER_H__
#define __MURL_GRAPH_I_LISTENER_H__

#include "murl_graph_i_view.h"
#include "murl_graph_i_state_slot.h"

namespace Murl
{
    namespace Audio
    {
        class IListener;
    }

    namespace Graph
    {
        class ICuller;
        class ISubject;
        
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IListener
         * @brief The IListener graph node interface.
         * A listener represents a node positioned in world space that is "listening" to
         * any sound sources (e.g. IAudioSequence nodes) within its hearing range. All
         * captured sources are attenuated according to their distance and given parameters,
         * and mixed together afterwards.
         *
         * See @ref sceneGraphStatesSlotsUnits for an overview of state handling during 
         * scene graph traversal.\n
         * See Graph::IListenerTransform for setting a listener's position and orientation.
         * See Graph::IListenerState for activating a listener for rendering.
         *
         * Gain calculation formula:\n
         *  REFERENCE_DISTANCE = referenceDistance attribute from IPlayable\n
         *  ROLLOFF_FACTOR = rolloffFactor attribute from IPlayable\n
         *  MAX_DISTANCE = maxDistance attribute from IPlayable\n
         *
         *  - distanceModel="INVERSE"\n
         *      gain = REFERENCE_DISTANCE / (REFERENCE_DISTANCE + ROLLOFF_FACTOR * (distance – REFERENCE_DISTANCE))
         *
         *  - distanceModel="INVERSE_CLAMPED"\n
         *      distance = max(distance, REFERENCE_DISTANCE)\n
         *      distance = min(distance, MAX_DISTANCE)\n
         *      gain = REFERENCE_DISTANCE / (REFERENCE_DISTANCE + ROLLOFF_FACTOR * (distance – REFERENCE_DISTANCE))
         *
         *  - distanceModel="LINEAR"\n
         *      distance = min(distance, MAX_DISTANCE) // avoid negative gain\n
         *      gain = (1 – ROLLOFF_FACTOR * (distance – REFERENCE_DISTANCE) / (MAX_DISTANCE – REFERENCE_DISTANCE))
         *
         *  - distanceModel="LINEAR_CLAMPED"\n
         *      distance = max(distance, REFERENCE_DISTANCE)\n
         *      distance = min(distance, MAX_DISTANCE)\n
         *      gain = (1 – ROLLOFF_FACTOR * (distance – REFERENCE_DISTANCE) / (MAX_DISTANCE – REFERENCE_DISTANCE))
         *
         *  - distanceModel="EXPONENT"\n
         *      gain = (distance / REFERENCE_DISTANCE) ^ (- ROLLOFF_FACTOR)
         *
         *  - distanceModel="EXPONENT_CLAMPED"\n
         *      distance = max(distance, REFERENCE_DISTANCE)\n
         *      distance = min(distance, MAX_DISTANCE)\n
         *      gain = (distance / REFERENCE_DISTANCE) ^ (- ROLLOFF_FACTOR)
         */
        class IListener : public IStateSlot
        {
        public:
            /**
             * @brief Get the mutable INode interface.
             * This method returns a mutable pointer to the node's INode interface, to
             * be able to query or modify common node properties such as active state,
             * visibility or ID.
             * @return The mutable INode interface, or null if not available
             */
            virtual INode* GetNodeInterface() = 0;
            /**
             * @brief Get the constant INode interface.
             * This method returns a constant pointer to the node's INode interface, to
             * be able to query common node properties such as active state, visibility
             * or ID.
             * @return The constant INode interface, or null if not available
             */
            virtual const INode* GetNodeInterface() const = 0;
            
            /**
             * @brief Get the mutable ISubject interface.
             * This method returns a mutable pointer to the node's ISubject interface, to
             * be able to query or modify subject properties such as world transform,
             * viewing matrix, projection matrix etc.
             * @return The mutable ISubject interface, or null if not available
             */
            virtual ISubject* GetSubjectInterface() = 0;
            /**
             * @brief Get the constant ISubject interface.
             * This method returns a constant pointer to the node's ISubject interface, to
             * be able to query subject properties such as world transform, viewing
             * matrix, projection matrix etc.
             * @return The mutable ISubject interface, or null if not available
             */
            virtual const ISubject* GetSubjectInterface() const = 0;
            
            /**
             * @brief Get the mutable IViewNodeTarget container.
             * This method returns a mutable pointer to the node's IViewNodeTarget
             * container, which allows to set or query the view object the listener is
             * attached to.
             * @return The mutable IViewNodeTarget container, or null if not available
             */
            virtual IViewNodeTarget* GetViewNodeTarget() = 0;
            /**
             * @brief Get the constant IViewNodeTarget container.
             * This method returns a constant pointer to the node's IViewNodeTarget
             * container, which allows to query the view object the listener is
             * attached to.
             * @return The constant IViewNodeTarget container, or null if not available
             */
            virtual const IViewNodeTarget* GetViewNodeTarget() const = 0;
            
            /**
             * @brief Set the listener's volume (gain).
             * @param volume The overall volume.
             * @return true if successful.
             */
            virtual Bool SetVolume(Real volume) = 0;
            /**
             * @brief Get the listener's volume (gain).
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
             * @brief Get the listener's number of stages.
             * @return The number of stages.
             */
            virtual UInt32 GetNumberOfStages() const = 0;
            /**
             * @brief Get the listener's internal audio renderer object.
             * @param stage The stage to query.
             * @return The audio renderer object.
             */
            virtual Audio::IListener* GetAudioListenerObject(UInt32 stage) const = 0;

        protected:
            virtual ~IListener() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IListener nodes.
         */
        typedef IGenericNodeTarget<IListener> IListenerNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_LISTENER_H__
