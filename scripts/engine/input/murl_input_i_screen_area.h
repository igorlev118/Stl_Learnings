// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_INPUT_I_SCREEN_AREA_H__
#define __MURL_INPUT_I_SCREEN_AREA_H__

#include "murl_input_types.h"

namespace Murl
{
    namespace Input
    {
        /**
         * @ingroup MurlInputInterfaces
         * @interface IScreenArea
         * @brief The IScreenArea interface.
         * The IScreenArea object can be created by the ITouchableHandler object.
         */
        class IScreenArea
        {
        public:
            /**
             * @brief Set the area's input coordinate range.
             * This method sets the area's start and end input coordinates.
             * @param x1 The start coordinate in X direction.
             * @param y1 The start coordinate in Y direction.
             * @param x2 The end coordinate in X direction.
             * @param y2 The end coordinate in Y direction.
             * @return true if successful.
             */
            virtual Bool SetInCoord(Real x1, Real y1, Real x2, Real y2) = 0;
            /**
             * @brief Set the area's input coordinate start.
             * See SetInCoord().
             * @param x1 The start coordinate in X direction.
             * @param y1 The start coordinate in Y direction.
             * @return true if successful.
             */
            virtual Bool SetInCoord1(Real x1, Real y1) = 0;
            /**
             * @brief Set the area's input coordinate end.
             * See SetInCoord().
             * @param x2 The end coordinate in X direction.
             * @param y2 The end coordinate in Y direction.
             * @return true if successful.
             */
            virtual Bool SetInCoord2(Real x2, Real y2) = 0;
            /**
             * @brief Set the area's horizontal start input coordinate.
             * See SetInCoord().
             * @param x1 The start coordinate in X direction.
             * @return true if successful.
             */
            virtual Bool SetInCoordX1(Real x1) = 0;
            /**
             * @brief Set the area's vertical start input coordinates.
             * See SetInCoord().
             * @param y1 The start coordinate in Y direction.
             * @return true if successful.
             */
            virtual Bool SetInCoordY1(Real y1) = 0;
            /**
             * @brief Set the area's horizontal end input coordinate.
             * See SetInCoord().
             * @param x2 The end coordinate in X direction.
             * @return true if successful.
             */
            virtual Bool SetInCoordX2(Real x2) = 0;
            /**
             * @brief Set the area's vertical end input coordinates.
             * See SetInCoord().
             * @param y2 The end coordinate in Y direction.
             * @return true if successful.
             */
            virtual Bool SetInCoordY2(Real y2) = 0;
            /**
             * @brief Get the area's horizontal start input coordinate.
             * See SetInCoord().
             * @return The start coordinate in X direction.
             */
            virtual Real GetInCoordX1() const = 0;
            /**
             * @brief Get the area's vertical start input coordinate.
             * See SetInCoord().
             * @return The start coordinate in Y direction.
             */
            virtual Real GetInCoordY1() const = 0;
            /**
             * @brief Get the area's horizontal end input coordinate.
             * See SetInCoord().
             * @return The end coordinate in X direction.
             */
            virtual Real GetInCoordX2() const = 0;
            /**
             * @brief Get the area's vertical end input coordinate.
             * See SetInCoord().
             * @return The end coordinate in Y direction.
             */
            virtual Real GetInCoordY2() const = 0;

        protected:
            virtual ~IScreenArea() {}
        };
    }
}

#endif // __MURL_INPUT_I_SCREEN_AREA_H__
