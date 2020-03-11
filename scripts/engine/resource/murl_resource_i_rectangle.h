// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_RESOURCE_I_RECTANGLE_H__
#define __MURL_RESOURCE_I_RECTANGLE_H__

#include "murl_types.h"

namespace Murl
{
    namespace Resource
    {
        /**
         * @ingroup MurlResourceMiscInterfaces
         * @interface IRectangle
         * @brief The IRectangle resource interface.
         * This interface represents a rectangle storing both screen and 
         * texture coordinates, used in Resource::IFont and Resource::IAtlas
         * objects.
         */
        class IRectangle
        {
        public:
            /**
             * @brief Get this rectangle's code value.
             * @return The code value.
             */
            virtual UInt32 GetCode() const = 0;

            /**
             * @brief Get the rectangle's start X texture coordinate (left).
             * @return The start X texture coordinate.
             */
            virtual Real GetTexCoordX1() const = 0;
            /**
             * @brief Get the rectangle's start Y texture coordinate (bottom).
             * @return The start Y texture coordinate.
             */
            virtual Real GetTexCoordY1() const = 0;
            /**
             * @brief Get the rectangle's end X texture coordinate (right).
             * @return The end X texture coordinate.
             */
            virtual Real GetTexCoordX2() const = 0;
            /**
             * @brief Get the rectangle's end Y texture coordinate (top).
             * @return The end Y texture coordinate.
             */
            virtual Real GetTexCoordY2() const = 0;

            /**
             * @brief Get the rectangle's start X screen coordinate (left).
             * @return The start X screen coordinate.
             */
            virtual Real GetCoordX1() const = 0;
            /**
             * @brief Get the rectangle's start Y screen coordinate (bottom).
             * @return The start Y screen coordinate.
             */
            virtual Real GetCoordY1() const = 0;
            /**
             * @brief Get the rectangle's end X screen coordinate (right).
             * @return The end X screen coordinate.
             */
            virtual Real GetCoordX2() const = 0;
            /**
             * @brief Get the rectangle's end Y screen coordinate (top).
             * @return The end Y screen coordinate.
             */
            virtual Real GetCoordY2() const = 0;

            /**
             * @brief Get the rectangle's actual size in X direction.
             * This value may actually be smaller than the difference of screen
             * coordinates; in this case, the rectangle should be cropped accordingly.
             * @return The horizontal size.
             */
            virtual Real GetSizeX() const = 0;
            /**
             * @brief Get the rectangle's actual size in Y direction.
             * This value may actually be smaller than the difference of screen
             * coordinates; in this case, the rectangle should be cropped accordingly.
             * @return The vertical size.
             */
            virtual Real GetSizeY() const = 0;

        protected:
            virtual ~IRectangle() {}
        };
    }
}

#endif  // __MURL_RESOURCE_I_RECTANGLE_H__
