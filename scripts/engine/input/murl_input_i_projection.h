// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_INPUT_I_PROJECTION_H__
#define __MURL_INPUT_I_PROJECTION_H__

#include "murl_input_types.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Input
    {
        /**
         * @ingroup MurlInputInterfaces
         * @interface IProjection
         * @brief The IProjection interface.
         * The IProjection object can be created by the ITouchableHandler object.
         */
        class IProjection
        {
        public:
            /**
             * @brief Set the projection type.
             * @param type The projection type.
             * @return true if successful.
             */
            virtual Bool SetType(IEnums::ProjectionType type) = 0;
            /**
             * @brief Get the projection type.
             * @return The projection type.
             */
            virtual IEnums::ProjectionType GetType() const = 0;

            /**
             * @brief Set the absolute depth order.
             * @param depthOrder The absolute order.
             * @return true if successful.
             */
            virtual Bool SetDepthOrder(SInt32 depthOrder) = 0;
            /**
             * @brief Get the absolute depth order.
             * @return The absolute order.
             */
            virtual SInt32 GetDepthOrder() const = 0;

            /**
             * @brief Set the world transformation matrix.
             * @param transform The world transformation matrix.
             * @return true if successful.
             */
            virtual Bool SetWorldTransform(const Matrix& transform) = 0;
            /**
             * @brief Set the inverted projection matrix.
             * @param invertedProjection The inverted projection matrix.
             * @param nearPlane The absolute distance of the near clipping plane.
             * @param farPlane The absolute distance of the far clipping plane.
             * @return true if successful.
             */
            virtual Bool SetInvertedProjection(const Matrix& invertedProjection, Real nearPlane, Real farPlane) = 0;

            /**
             * @brief Get the world transformation matrix.
             * @return The world transformation matrix.
             */
            virtual const Matrix& GetWorldTransform() const = 0;
            /**
             * @brief Get the inverted projection matrix.
             * @return The inverted projection matrix.
             */
            virtual const Matrix& GetInvertedProjection() const = 0;
            
        protected:
            virtual ~IProjection() {}
        };
    }
}

#endif // __MURL_INPUT_I_PROJECTION_H__
