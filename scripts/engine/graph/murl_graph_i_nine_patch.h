// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_NINE_PATCH_H__
#define __MURL_GRAPH_I_NINE_PATCH_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_graph_i_drawable.h"
#include "murl_graph_i_scalable.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphPropertyInterfaces
         * @interface INinePatch
         * @brief The INinePatch property interface.
         * This interface represents a generic object that is divided up in three
         * segments along both X and Y axes, creating a total of nine segments.
         *
         * The first and last segment along each axis is defined with fixed size and
         * texture coordinates, whereas the middle segment is stretched or shrunk depending
         * on the actual plane frame size.
         *
         * A nine patch is useful for defining the visual appearance of e.g.
         * buttons on screen, which may have different actual sizes but should retain a 
         * common (unstretched) look along its corners and edges.
         *
         * See the Graph::INinePatchPlaneGeometry and Graph::INinePatchPlaneSequenceGeometry 
         * node interfaces for further reference.
         */
        class INinePatch
        {
        public:
            /**
             * @brief Set all four of the cap coordinate sizes.
             * This method sets all four of the cap sizes, i.e. left/right and bottom/top caps.
             * Note that (x1+x2) and (y1+y2) should be less or equal to the object's actual
             * frame size along the respective axis, defined via e.g. 
             * Graph::IPlaneGeometry::SetFrameSize().
             * @param x1 The left cap size.
             * @param y1 The bottom cap size.
             * @param x2 The right cap size.
             * @param y2 The top cap size.
             * @return true if successful.
             */
            virtual Bool SetCapCoordSize(Real x1, Real y1, Real x2, Real y2) = 0;
            /**
             * @brief Set the cap coordinate start sizes.
             * This method sets the left and bottom cap sizes. See SetCapCoordSize().
             * @param x1 The left cap size.
             * @param y1 The bottom cap size.
             * @return true if successful.
             */
            virtual Bool SetCapCoordSize1(Real x1, Real y1) = 0;
            /**
             * @brief Set the cap coordinate stop sizes.
             * This method sets the right and top cap sizes. See SetCapCoordSize().
             * @param x2 The right cap size.
             * @param y2 The top cap size.
             * @return true if successful.
             */
            virtual Bool SetCapCoordSize2(Real x2, Real y2) = 0;
            /**
             * @brief Set the left cap coordinate size.
             * See SetCapCoordSize().
             * @param x1 The left cap size.
             * @return true if successful.
             */
            virtual Bool SetCapCoordSizeX1(Real x1) = 0;
            /**
             * @brief Set the bottom cap coordinate size.
             * See SetCapCoordSize().
             * @param y1 The bottom cap size.
             * @return true if successful.
             */
            virtual Bool SetCapCoordSizeY1(Real y1) = 0;
            /**
             * @brief Set the right cap coordinate size.
             * See SetCapCoordSize().
             * @param x2 The right cap size.
             * @return true if successful.
             */
            virtual Bool SetCapCoordSizeX2(Real x2) = 0;
            /**
             * @brief Set the top cap coordinate size.
             * See SetCapCoordSize().
             * @param y2 The top cap size.
             * @return true if successful.
             */
            virtual Bool SetCapCoordSizeY2(Real y2) = 0;
            /**
             * @brief Get the left cap coordinate size.
             * @return The left cap size.
             */
            virtual Real GetCapCoordSizeX1() const = 0;
            /**
             * @brief Get the bottom cap coordinate size.
             * @return The bottom cap size.
             */
            virtual Real GetCapCoordSizeY1() const = 0;
            /**
             * @brief Get the right cap coordinate size.
             * @return The right cap size.
             */
            virtual Real GetCapCoordSizeX2() const = 0;
            /**
             * @brief Get the top cap coordinate size.
             * @return The top cap size.
             */
            virtual Real GetCapCoordSizeY2() const = 0;

            /**
             * @brief Set all four of the cap texture coordinate sizes.
             * This method sets all four of the texture coordinate cap sizes, i.e. left/right 
             * and bottom/top caps.
             * @param x1 The left cap texture coordinate size.
             * @param y1 The bottom cap texture coordinate size.
             * @param x2 The right cap texture coordinate size.
             * @param y2 The top cap texture coordinate size.
             * @param index The index of the texture coordinate set.
             * @return true if successful.
             */
            virtual Bool SetCapTexCoordSize(Real x1, Real y1, Real x2, Real y2, UInt32 index) = 0;
            /**
             * @brief Set the cap texture coordinate start sizes.
             * This method sets the left and bottom texture coordinate cap sizes.
             * @param x1 The left cap texture coordinate size.
             * @param y1 The bottom cap texture coordinate size.
             * @param index The index of the texture coordinate set.
             * @return true if successful.
             */
            virtual Bool SetCapTexCoordSize1(Real x1, Real y1, UInt32 index) = 0;
            /**
             * @brief Set the cap texture coordinate stop sizes.
             * This method sets the left and bottom texture coordinate cap sizes.
             * @param x2 The right cap texture coordinate size.
             * @param y2 The top cap texture coordinate size.
             * @param index The index of the texture coordinate set.
             * @return true if successful.
             */
            virtual Bool SetCapTexCoordSize2(Real x2, Real y2, UInt32 index) = 0;
            /**
             * @brief Set the left cap texture coordinate size.
             * @param x1 The left cap texture coordinate size.
             * @param index The index of the texture coordinate set.
             * @return true if successful.
             */
            virtual Bool SetCapTexCoordSizeX1(Real x1, UInt32 index) = 0;
            /**
             * @brief Set the bottom cap texture coordinate size.
             * @param y1 The bottom cap texture coordinate size.
             * @param index The index of the texture coordinate set.
             * @return true if successful.
             */
            virtual Bool SetCapTexCoordSizeY1(Real y1, UInt32 index) = 0;
            /**
             * @brief Set the right cap texture coordinate size.
             * @param x2 The right cap texture coordinate size.
             * @param index The index of the texture coordinate set.
             * @return true if successful.
             */
            virtual Bool SetCapTexCoordSizeX2(Real x2, UInt32 index) = 0;
            /**
             * @brief Set the top cap texture coordinate size.
             * @param y2 The top cap texture coordinate size.
             * @param index The index of the texture coordinate set.
             * @return true if successful.
             */
            virtual Bool SetCapTexCoordSizeY2(Real y2, UInt32 index) = 0;
            /**
             * @brief Get the left cap texture coordinate size.
             * @param index The index of the texture coordinate set.
             * @return The left cap texture coordinate size.
             */
            virtual Real GetCapTexCoordSizeX1(UInt32 index) const = 0;
            /**
             * @brief Get the bottom cap texture coordinate size.
             * @param index The index of the texture coordinate set.
             * @return The bottom cap texture coordinate size.
             */
            virtual Real GetCapTexCoordSizeY1(UInt32 index) const = 0;
            /**
             * @brief Get the right cap texture coordinate size.
             * @param index The index of the texture coordinate set.
             * @return The right cap texture coordinate size.
             */
            virtual Real GetCapTexCoordSizeX2(UInt32 index) const = 0;
            /**
             * @brief Get the top cap texture coordinate size.
             * @param index The index of the texture coordinate set.
             * @return The top cap texture coordinate size.
             */
            virtual Real GetCapTexCoordSizeY2(UInt32 index) const = 0;

            /**
             * @brief Enable/disable rendering of the center patch.
             * To avoid excessive overdraw when e.g. only a frame with transparent
             * center is to be rendered, the center patch can be set invisible
             * using this method.
             * @param enabled If false, the center patch is not rendered.
             * @return true if successful.
             */
            virtual Bool SetCenterPatchEnabled(Bool enabled) = 0;
            /**
             * @brief Check if the center patch is visible.
             * @return true if visible.
             */
            virtual Bool IsCenterPatchEnabled() const = 0;

        protected:
            virtual ~INinePatch() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::INinePatch nodes.
         */
        typedef IGenericNodeTarget<INinePatch> INinePatchNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_NINE_PATCH_H__
