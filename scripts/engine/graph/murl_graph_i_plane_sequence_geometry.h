// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_PLANE_SEQUENCE_GEOMETRY_H__
#define __MURL_GRAPH_I_PLANE_SEQUENCE_GEOMETRY_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_graph_i_generic_resource_target.h"
#include "murl_graph_i_drawable.h"
#include "murl_graph_i_indexed.h"
#include "murl_graph_i_scalable.h"

namespace Murl
{
    namespace Graph
    {
        class ITransform;
        
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IPlaneSequenceGeometry
         * @brief The IPlaneSequenceGeometry graph node interface.
         * This interface represents a flat rectangular geometry object (quad) in world space
         * that retrieves its actual size and texture coordinates from a given Resource::IAtlas
         * object.
         *
         * Use the Graph::IIndexed base interface to access the individual rectangles stored in
         * the referenced resource atlas.\n
         * Use the Graph::IScalable base interface to set an overall scaling factor for the
         * geometry.
         *
         * See Graph::IPlaneGeometry for a non-animated version.
         */
        class IPlaneSequenceGeometry : public IDrawable, public IIndexed, public IScalable
        {
        public:
            /**
             * @brief Get the mutable Graph::INode interface.
             * This method returns a mutable pointer to the node's Graph::INode interface, to
             * be able to query or modify common node properties such as active state,
             * visibility or ID.
             * @return The mutable Graph::INode interface, or null if not available
             */
            virtual INode* GetNodeInterface() = 0;
            /**
             * @brief Get the constant Graph::INode interface.
             * This method returns a constant pointer to the node's Graph::INode interface, to
             * be able to query common node properties such as active state, visibility
             * or ID.
             * @return The constant Graph::INode interface, or null if not available
             */
            virtual const INode* GetNodeInterface() const = 0;
            
            /**
             * @brief Get the mutable Graph::ITransform interface.
             * This method returns a mutable pointer to the node's Graph::ITransform interface,
             * to be able to query or modify the node's transformation matrix and depth
             * order.
             * @return The mutable Graph::ITransform interface, or null if not available
             */
            virtual ITransform* GetTransformInterface() = 0;
            /**
             * @brief Get the constant Graph::ITransform interface.
             * This method returns a constant pointer to the node's Graph::ITransform interface,
             * to be able to query the node's transformation matrix and depth order.
             * @return The constant Graph::ITransform interface, or null if not available
             */
            virtual const ITransform* GetTransformInterface() const = 0;
            
            /**
             * @brief Get a mutable Graph::IAtlasResourceTarget container.
             * This method returns a mutable pointer to a Graph::IAtlasResourceTarget
             * container, which allows to add, remove or query the atlas resources referenced
             * by a node implementing this interface.
             * @return The mutable Graph::IAtlasResourceTarget container, or null if not available
             */
            virtual IAtlasResourceTarget* GetAtlasResourceTarget() = 0;
            /**
             * @brief Get a constant Graph::IAtlasResourceTarget container.
             * This method returns a constant pointer to a Graph::IAtlasResourceTarget
             * container, which allows to query the atlas resources referenced by a node
             * implementing this interface.
             * @return The constant Graph::IAtlasResourceTarget container, or null if not available
             */
            virtual const IAtlasResourceTarget* GetAtlasResourceTarget() const = 0;
            
            /**
             * @brief Add an attribute item to the plane's vertex data prior to initialization.
             * This method allows to add one of the available attribute items to the plane's
             * internal vertex buffer. Available items from the IEnums::AttributeItem enum are
             * NORMAL, BINORMAL, TANGENT, COLOR, TEXCOORD_0 and TEXCOORD_1. The item COORD is
             * always present, and by default also TEXCOORD_0 is active. 
             * See also RemoveAttribute() to unset the latter one.
             * @param item The item to add.
             * @return true if successful.
             */
            virtual Bool AddAttribute(IEnums::AttributeItem item) = 0;
            /**
             * @brief Remove an attribute item frome the plane's vertex data prior to initialization.
             * See AddAttribute().
             * @param item The item to remove.
             * @return true if successful.
             */
            virtual Bool RemoveAttribute(IEnums::AttributeItem item) = 0;
            
            /**
             * @brief Set the texture reference size.
             * Generally, texture coordinates are represented by values ranging from 0.0 to 1.0.
             * As a convenience, this method can be used to set an arbitrary reference size for
             * both dimensions of the plane; this way it is possible to specify integer (pixel)
             * values instead of (quite unreadable) floats. For example, if a 256x128 texture is
             * to be used when rendering this plane, a sizeX value of 256 and sizeY value of 128
             * directly maps incoming integer texture coordinates to whole texture pixels.
             * Note, that it may also be necessary to set these values depending on the actual
             * texture coordinates stored in the Resource::IAtlas that is referenced; it is often
             * desired to store an atlas' texture coordinates with an already present scale factor.
             * Use the index parameter to specify the actual set of texture coordinates for which
             * to set the reference size, either 0 for TEXCOORD_0 or 1 for TEXCOORD_1.
             * @param sizeX The horizontal (X, or U) texture coordinate reference size.
             * @param sizeY The vertical (Y, or V) texture coordinate reference size.
             * @param index The index of the texture coordinate set.
             * @return true if successful.
             */
            virtual Bool SetTextureSize(Real sizeX, Real sizeY, UInt32 index = 0) = 0;
            /**
             * @brief Set the horizontal texture reference size.
             * See SetTextureSize().
             * @param sizeX The horizontal (X, or U) texture coordinate reference size.
             * @param index The index of the texture coordinate set.
             * @return true if successful.
             */
            virtual Bool SetTextureSizeX(Real sizeX, UInt32 index = 0) = 0;
            /**
             * @brief Set the vertical texture reference size.
             * See SetTextureSize().
             * @param sizeY The vertical (Y, or V) texture coordinate reference size.
             * @param index The index of the texture coordinate set.
             * @return true if successful.
             */
            virtual Bool SetTextureSizeY(Real sizeY, UInt32 index = 0) = 0;
            /**
             * @brief Get the horizontal texture reference size.
             * See SetTextureSize().
             * @param index The index of the texture coordinate set.
             * @return The horizontal (X, or U) texture coordinate reference size.
             */
            virtual Real GetTextureSizeX(UInt32 index = 0) const = 0;
            /**
             * @brief Get the vertical texture reference size.
             * See SetTextureSize().
             * @param index The index of the texture coordinate set.
             * @return The vertical (Y, or V) texture coordinate reference size.
             */
            virtual Real GetTextureSizeY(UInt32 index = 0) const = 0;
            
            /**
             * @brief Set the plane's texture coordinates.
             * This method sets the plane's start and end texture coordinates, to allow for
             * rendering only part of the currently active texture on the plane. All given
             * texture coordinate values are divided by their respective reference sizes
             * (See SetTextureSize() for description), before they are actually applied for
             * rendering.
             * An IPlaneSequenceGeometry directly takes the texture coordinates for set #0
             * from the given atlas resource, so this method only accepts the value 1 for
             * the index parameter to set texture coordinates for set #1 (TEXCOORD_1).
             * @param x1 The start coordinate in X direction.
             * @param y1 The start coordinate in Y direction.
             * @param x2 The end coordinate in X direction.
             * @param y2 The end coordinate in Y direction.
             * @param index The index of the texture coordinate set.
             * @return true if successful.
             */
            virtual Bool SetTexCoord(Real x1, Real y1, Real x2, Real y2, UInt32 index = 0) = 0;
            /**
             * @brief Set the plane's start texture coordinates.
             * See SetTexCoord().
             * @param x1 The start coordinate in X direction.
             * @param y1 The start coordinate in Y direction.
             * @param index The index of the texture coordinate set.
             * @return true if successful.
             */
            virtual Bool SetTexCoord1(Real x1, Real y1, UInt32 index = 0) = 0;
            /**
             * @brief Set the plane's end texture coordinates.
             * See SetTexCoord().
             * @param x2 The end coordinate in X direction.
             * @param y2 The end coordinate in Y direction.
             * @param index The index of the texture coordinate set.
             * @return true if successful.
             */
            virtual Bool SetTexCoord2(Real x2, Real y2, UInt32 index = 0) = 0;
            /**
             * @brief Set the plane's horizontal start texture coordinate.
             * See SetTexCoord().
             * @param x1 The start coordinate in X direction.
             * @param index The index of the texture coordinate set.
             * @return true if successful.
             */
            virtual Bool SetTexCoordX1(Real x1, UInt32 index = 0) = 0;
            /**
             * @brief Set the plane's vertical start texture coordinates.
             * See SetTexCoord().
             * @param y1 The start coordinate in Y direction.
             * @param index The index of the texture coordinate set.
             * @return true if successful.
             */
            virtual Bool SetTexCoordY1(Real y1, UInt32 index = 0) = 0;
            /**
             * @brief Set the plane's horizontal end texture coordinate.
             * See SetTexCoord().
             * @param x2 The end coordinate in X direction.
             * @param index The index of the texture coordinate set.
             * @return true if successful.
             */
            virtual Bool SetTexCoordX2(Real x2, UInt32 index = 0) = 0;
            /**
             * @brief Set the plane's vertical end texture coordinates.
             * See SetTexCoord().
             * @param y2 The end coordinate in Y direction.
             * @param index The index of the texture coordinate set.
             * @return true if successful.
             */
            virtual Bool SetTexCoordY2(Real y2, UInt32 index = 0) = 0;
            /**
             * @brief Get the plane's horizontal start texture coordinate.
             * See SetTexCoord().
             * @param index The index of the texture coordinate set.
             * @return The start coordinate in X direction.
             */
            virtual Real GetTexCoordX1(UInt32 index = 0) const = 0;
            /**
             * @brief Get the plane's vertical start texture coordinate.
             * See SetTexCoord().
             * @param index The index of the texture coordinate set.
             * @return The start coordinate in Y direction.
             */
            virtual Real GetTexCoordY1(UInt32 index = 0) const = 0;
            /**
             * @brief Get the plane's horizontal end texture coordinate.
             * See SetTexCoord().
             * @param index The index of the texture coordinate set.
             * @return The end coordinate in X direction.
             */
            virtual Real GetTexCoordX2(UInt32 index = 0) const = 0;
            /**
             * @brief Get the plane's vertical end texture coordinate.
             * See SetTexCoord().
             * @param index The index of the texture coordinate set.
             * @return The end coordinate in Y direction.
             */
            virtual Real GetTexCoordY2(UInt32 index = 0) const = 0;
            
            /**
             * @brief Get the width of the currently displayed atlas rectangle.
             * @return The current atlas rectangle width.
             */
            virtual Real GetFrameSizeX() const = 0;
            /**
             * @brief Get the height of the currently displayed atlas rectangle.
             * @return The current atlas rectangle height.
             */
            virtual Real GetFrameSizeY() const = 0;
            
            /**
             * @brief Get the width of a given atlas rectangle.
             * @param frameIndex The zero-based index into the referenced atlas resource's
             *      rectangles.
             * @return The atlas rectangle width, or 0 if the given index is out of range.
             */
            virtual Real GetFrameSizeX(UInt32 frameIndex) const = 0;
            /**
             * @brief Get the height of a given atlas rectangle.
             * @param frameIndex The zero-based index into the referenced atlas resource's
             *      rectangles.
             * @return The atlas rectangle height, or 0 if the given index is out of range.
             */
            virtual Real GetFrameSizeY(UInt32 frameIndex) const = 0;
            
            /**
             * @brief Set the horizontal container alignment.
             * The given alignment values specify how the text container is actually positioned with
             * respect to the node's world position.
             * @param alignmentX The horizontal container alignment.
             * @param alignmentY The vertical container alignment.
             * @return true if successful.
             */
            virtual Bool SetContainerAlignment(IEnums::AlignmentX alignmentX, IEnums::AlignmentY alignmentY) = 0;
            /**
             * @brief Set the horizontal container alignment.
             * See SetContainerAlignment().
             * @param alignmentX The horizontal container alignment.
             * @return true if successful.
             */
            virtual Bool SetContainerAlignmentX(IEnums::AlignmentX alignmentX) = 0;
            /**
             * @brief Set the vertical container alignment.
             * See SetContainerAlignment().
             * @param alignmentY The vertical container alignment.
             * @return true if successful.
             */
            virtual Bool SetContainerAlignmentY(IEnums::AlignmentY alignmentY) = 0;
            /**
             * @brief Get the horizontal container alignment.
             * @return The horizontal container alignment.
             */
            virtual IEnums::AlignmentX GetContainerAlignmentX() const = 0;
            /**
             * @brief Get the vertical container alignment.
             * @return The vertical container alignment.
             */
            virtual IEnums::AlignmentY GetContainerAlignmentY() const = 0;
            
            /**
             * @brief Set the horizontal and vertical borders used for alignment.
             * @param borderX The horizontal border.
             * @param borderY The vertical border.
             * @return true if successful.
             */
            virtual Bool SetBorder(Real borderX, Real borderY) = 0;
            /**
             * @brief Set the horizontal border used for alignment.
             * @param borderX The horizontal border.
             * @return true if successful.
             */
            virtual Bool SetBorderX(Real borderX) = 0;
            /**
             * @brief Set the vertical border used for alignment.
             * @param borderY The vertical border.
             * @return true if successful.
             */
            virtual Bool SetBorderY(Real borderY) = 0;
            /**
             * @brief Get the horizontal border used for alignment.
             * @return The horizontal border.
             */
            virtual Real GetBorderX() const = 0;
            /**
             * @brief Get the vertical border used for alignment.
             * @return The vertical border.
             */
            virtual Real GetBorderY() const = 0;

            /**
             * @brief Set the current atlas rectangle by name.
             * If the given name is empty, the rectangle is explicitly set via a given index
             * (see SetIndex()).
             * This method fails if no atlas resource is set, or the given name is not found within
             * the atlas resource.
             * @param rectangleName The rectangle name.
             * @return true if successful.
             */
            virtual Bool SetRectangleName(const String& rectangleName) = 0;
            /**
             * @brief Get the current rectangle's name.
             * This method returns an empty string when no atlas resource is defined or the
             * currently active rectangle is unnamed.
             * @return The rectangle name if available.
             */
            virtual String GetRectangleName() const = 0;

        protected:
            virtual ~IPlaneSequenceGeometry() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IPlaneSequenceGeometry nodes.
         */
        typedef IGenericNodeTarget<IPlaneSequenceGeometry> IPlaneSequenceGeometryNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_PLANE_SEQUENCE_GEOMETRY_H__
