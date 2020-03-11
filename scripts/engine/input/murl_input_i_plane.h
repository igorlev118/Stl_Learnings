// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_INPUT_I_PLANE_H__
#define __MURL_INPUT_I_PLANE_H__

#include "murl_input_types.h"

namespace Murl
{
    namespace Input
    {
        /**
         * @ingroup MurlInputInterfaces
         * @interface IPlane
         * @brief The IPlane interface.
         */
        class IPlane
        {
        public:
            /** 
             * @brief Set the width and height of the plane.
             * @param sizeX The width of the plane.
             * @param sizeY The height of the plane.
             */
            virtual void SetSize(Real sizeX, Real sizeY) = 0;
            /** 
             * @brief Get the width of the plane.
             * @return The width of the plane.
             */
            virtual Real GetSizeX() const = 0;
            /**
             * @brief Get the height of the plane.
             * @return The height of the plane.
             */
            virtual Real GetSizeY() const = 0;
            
            /**
             * @brief Set the horizontal and vertical offset of the plane
             * @param offsetX The horizontal offset.
             * @param offsetY The vertical offset.
             */
            virtual void SetOffset(Real offsetX, Real offsetY) = 0;
            /**
             * @brief Get the horizontal offset of the plane.
             * @return The horizontal offset.
             */
            virtual Real GetOffsetX() const = 0;
            /**
             * @brief Get the vertical offset of the plane.
             * @return The vertical offset.
             */
            virtual Real GetOffsetY() const = 0;
            
        protected:
            virtual ~IPlane() {}
        };
    }
}

#endif // __MURL_INPUT_I_PLANE_H__
