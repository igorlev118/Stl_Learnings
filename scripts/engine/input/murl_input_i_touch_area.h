// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_INPUT_I_TOUCH_AREA_H__
#define __MURL_INPUT_I_TOUCH_AREA_H__

#include "murl_input_types.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Graph
    {
        class ITouchable;
    }
    
    namespace Input
    {
        /**
         * @ingroup MurlInputInterfaces
         * @interface ITouchArea
         * @brief The ITouchArea interface.
         * The ITouchArea object can be created by the ITouchableHandler object.
         */
        class ITouchArea
        {
        public:
            /**
             * @brief Set which faces of the touch area are active.
             * @param faces One of the available IEnums::PolygonFaces enumeration values.
             * @return true if successful.
             */
            virtual Bool SetActiveFaces(IEnums::PolygonFaces faces) = 0;
            /**
             * @brief Check which faces of the touch area are active.
             * @return One of the available IEnums::PolygonFaces enumeration values.
             */
            virtual IEnums::PolygonFaces GetActiveFaces() const = 0;
            
            /**
             * @brief Set the button's output coordinate range.
             * This method sets the button's start and end output coordinates. In contrast
             * to a button event's local intersection point, which always represents the
             * actual intersection in object-space 3D coordinates, an event's output
             * coordinate represents a 2D intersection on the button's clickable surface.
             * This can be interpreted analogously to a renderable geometry, with 3D vertex
             * coordinates and 2D texture coordinates.
             * @param x1 The start coordinate in X direction.
             * @param y1 The start coordinate in Y direction.
             * @param x2 The end coordinate in X direction.
             * @param y2 The end coordinate in Y direction.
             * @return true if successful.
             */
            virtual Bool SetOutCoord(Real x1, Real y1, Real x2, Real y2) = 0;
            /**
             * @brief Set the button's output coordinate start.
             * See SetOutCoord().
             * @param x1 The start coordinate in X direction.
             * @param y1 The start coordinate in Y direction.
             * @return true if successful.
             */
            virtual Bool SetOutCoord1(Real x1, Real y1) = 0;
            /**
             * @brief Set the button's output coordinate end.
             * See SetOutCoord().
             * @param x2 The end coordinate in X direction.
             * @param y2 The end coordinate in Y direction.
             * @return true if successful.
             */
            virtual Bool SetOutCoord2(Real x2, Real y2) = 0;
            /**
             * @brief Set the button's horizontal start output coordinate.
             * See SetOutCoord().
             * @param x1 The start coordinate in X direction.
             * @return true if successful.
             */
            virtual Bool SetOutCoordX1(Real x1) = 0;
            /**
             * @brief Set the button's vertical start output coordinates.
             * See SetOutCoord().
             * @param y1 The start coordinate in Y direction.
             * @return true if successful.
             */
            virtual Bool SetOutCoordY1(Real y1) = 0;
            /**
             * @brief Set the button's horizontal end output coordinate.
             * See SetOutCoord().
             * @param x2 The end coordinate in X direction.
             * @return true if successful.
             */
            virtual Bool SetOutCoordX2(Real x2) = 0;
            /**
             * @brief Set the button's vertical end output coordinates.
             * See SetOutCoord().
             * @param y2 The end coordinate in Y direction.
             * @return true if successful.
             */
            virtual Bool SetOutCoordY2(Real y2) = 0;
            /**
             * @brief Get the button's horizontal start output coordinate.
             * See SetOutCoord().
             * @return The start coordinate in X direction.
             */
            virtual Real GetOutCoordX1() const = 0;
            /**
             * @brief Get the button's vertical start output coordinate.
             * See SetOutCoord().
             * @return The start coordinate in Y direction.
             */
            virtual Real GetOutCoordY1() const = 0;
            /**
             * @brief Get the button's horizontal end output coordinate.
             * See SetOutCoord().
             * @return The end coordinate in X direction.
             */
            virtual Real GetOutCoordX2() const = 0;
            /**
             * @brief Get the button's vertical end output coordinate.
             * See SetOutCoord().
             * @return The end coordinate in Y direction.
             */
            virtual Real GetOutCoordY2() const = 0;

            /**
             * @brief Enable or disable output coordinate clipping.
             * @param enable If true, output coordinates are being clipped.
             * @return true if successful.
             */
            virtual Bool SetOutCoordClippingEnabled(Bool enable) = 0;
            /**
             * @brief Check if output coordinate clipping is enabled
             * @return true if enabled.
             */
            virtual Bool IsOutCoordClippingEnabled() const = 0;

            /**
             * @brief Set the response target object.
             * @param node The response target object.
             */
            virtual void SetResponseTarget(Graph::ITouchable* node) = 0;
            /**
             * @brief Get the response target object.
             * @return The response target object.
             */
            virtual Graph::ITouchable* GetResponseTarget() const = 0;
            
            /**
             * @brief Set the response button.
             * @param button The response button.
             */
            virtual void SetResponseButton(IEnums::MouseButton button) = 0;
            /**
             * @brief Get the response button.
             * @return The response button.
             */
            virtual IEnums::MouseButton GetResponseButton() const = 0;
            
            /**
             * @brief Set the pass events state.
             * @param enable true for enable passing events.
             */
            virtual void SetPassEventsEnabled(Bool enable) = 0;
            /**
             * @brief Check the pass events state.
             * @return true if enabled.
             */
            virtual Bool IsPassEventsEnabled() const = 0;
            
        protected:
            virtual ~ITouchArea() {}
        };
    }
}

#endif // __MURL_INPUT_I_TOUCH_AREA_H__
