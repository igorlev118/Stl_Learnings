// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_ANIMATION_TIME_CONTROLLER_H__
#define __MURL_GRAPH_I_ANIMATION_TIME_CONTROLLER_H__

#include "murl_graph_i_generic_resource_target.h"

namespace Murl
{
    namespace Graph
    {
        class IController;
        class ITimeController;
        
        /**
         * @ingroup MurlGraphControllerInterfaces
         * @interface IAnimationTimeController
         * @brief The IAnimationTimeController interface.
         * This interface provides a specialized Graph::ITimeController to manipulate a node's properties
         * according to a given Resource::IAnimation object.
         */
        class IAnimationTimeController
        {
        public:
            /**
             * @brief Get the mutable IController interface.
             * @return The mutable IController interface.
             */
            virtual IController* GetControllerInterface() = 0;
            /**
             * @brief Get the constant IController interface.
             * @return The constant IController interface.
             */
            virtual const IController* GetControllerInterface() const = 0;
            
            /**
             * @brief Get the mutable ITimeController interface.
             * @return The mutable ITimeController interface.
             */
            virtual ITimeController* GetTimeControllerInterface() = 0;
            /**
             * @brief Get the constant ITimeController interface.
             * @return The constant ITimeController interface.
             */
            virtual const ITimeController* GetTimeControllerInterface() const = 0;

            /**
             * @brief Get a mutable Graph::IAnimationResourceTarget container.
             * This method returns a mutable pointer to a Graph::IAnimationResourceTarget
             * container, which allows to add, remove or query the animation resource referenced.
             * @return The mutable Graph::IAnimationResourceTarget container.
             */
            virtual IAnimationResourceTarget* GetAnimationResourceTarget() = 0;
            /**
             * @brief Get a constant Graph::IAnimationResourceTarget container.
             * This method returns a constant pointer to a Graph::IAnimationResourceTarget
             * container, which allows to query the animation resource referenced.
             * @return The constant Graph::IAnimationResourceTarget container.
             */
            virtual const IAnimationResourceTarget* GetAnimationResourceTarget() const = 0;

            /**
             * @brief Set the bit mask of animation keys the controller should react on.
             * @param keys Any combination of IEnums::AnimationKey values.
             * @return true if successful.
             */
            virtual Bool SetAnimationKeys(UInt32 keys) = 0;
            /**
             * @brief Get the bit mask of animation keys the controller should react on.
             * @return The set combination of IEnums::AnimationKey values.
             */
            virtual UInt32 GetAnimationKeys() const = 0;

            /**
             * @brief Set the reference mode used when blending multiple rotation keys.
             * @param blendReference The blend reference mode.
             * @return true if successful.
             */
            virtual Bool SetRotationBlendReference(IEnums::BlendReference blendReference) = 0;
            /**
             * @brief Get the reference mode used when blending multiple rotation keys.
             * @return The blend reference mode.
             */
            virtual IEnums::BlendReference GetRotationBlendReference() const = 0;

            /**
             * @brief Set the blend direction used when blending multiple rotation keys.
             * @param blendDirection The blend direction.
             * @return true if successful.
             */
            virtual Bool SetRotationBlendDirection(IEnums::BlendDirection blendDirection) = 0;
            /**
             * @brief Get the blend direction used when blending multiple rotation keys.
             * @return The blend direction.
             */
            virtual IEnums::BlendDirection GetRotationBlendDirection() const = 0;

        protected:
            virtual ~IAnimationTimeController() {}
        };
    }
}

#endif // __MURL_GRAPH_I_ANIMATION_TIME_CONTROLLER_H__
