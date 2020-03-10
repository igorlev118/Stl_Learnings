// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_TEXT_GEOMETRY_H__
#define __MURL_GRAPH_I_TEXT_GEOMETRY_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_graph_i_drawable.h"
#include "murl_graph_i_text.h"
#include "murl_graph_i_scalable.h"

namespace Murl
{
    namespace Resource
    {
        class IFont;
    }
    
    namespace Graph
    {
        class ITransform;
        
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface ITextGeometry
         * @brief The ITextGeometry graph node interface.
         * This interface represents a renderable text object, which makes use of either a read-only
         * Resource::IFont object representing a collection of individual glyph positions in a
         * corresponding font atlas bitmap image, or a system font with a given ID.
         *
         * To correctly display any given text using a bitmap font, the following prerequisites must be met:
         * - The ITextGeometry node must reference a given Resource::IFont object containing bitmap glyph
         *   rectangles.
         * - There must be an active material used for rendering the font at the material state slot with
         *   given index ("materialSlot" attribute, see Graph::IDrawable::SetMaterialSlot()).
         * - There must be an active texture containing the actual bitmap glyphs corresponding
         *   to the Resource::IFont used, at the texture state slot given via the "textureSlots" attribute
         *   or the Graph::IDrawable::SetTextureSlot() method. The texture state unit depends on the actual
         *   program used for the material.
         *
         * To display a given text using an embedded outline font, the following settings are needed:
         * - The ITextGeometry node must reference a given Resource::IFont object containig valid outlines
         * - The "fontSize" attribute must specify a non-zero positive font size.
         *
         * To display a given text using a system font, the following settings are needed:
         * - The "systemFontName" attribute must be set to a valid system font ID, e.g. "SansRegular"
         * - The "fontSize" attribute must specify a non-zero positive font size.
         *
         * Use the Graph::IText base interface to access common text properties, such as spacing or
         * leading, or the actual text to be shown.
         *
         * Use the Graph::IScalable base interface to set an overall scaling factor for the
         * object, i.e. define its actual size.
         */
        class ITextGeometry : public IDrawable, public IText, public IScalable
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
             * @brief Set the number of characters to reserve.
             * If the given value is 0, the text object always dynamically expands its underlying
             * buffer to hold the number of characters needed for correctly displaying any given
             * text. If the value is higher than 0, only that number of entries are allocated in the
             * buffers; any text with a length beyond that number will be truncated.
             * @param numReserved The number of characters to reserve.
             * @return true if successful.
             */
            virtual Bool SetNumberOfReservedCharacters(UInt32 numReserved) = 0;
            /**
             * @brief Get the number of characters currently reserved.
             * @return The number of characters.
             */
            virtual UInt32 GetNumberOfReservedCharacters() const = 0;
            
            /**
             * @brief Set the text node's container size.
             * When text alignment other than IEnums::TEXT_ALIGNMENT_X_CENTER is desired (set
             * via Graph::IText::SetTextAlignmentX and Graph::IText::SetTextAlignmentY) or word wrapping
             * should be performed, it is necessary to specify an explicit container size, so that the 
             * text can be laid out correctly. Note that the container size only determines how the text
             * is aligned within that container; use SetContainerAlignmentX() and SetContainerAlignmentY()
             * to control alignment of the container itself.\n
             * If any of the given size values are 0, the respective container dimension is automatically
             * calculated from the actual dimension of the text to render, which is the reason why in
             * this case all types of text alignment appear to be centered.\n
             * When using bitmap fonts, the container size only affects the size of the resulting geometry.
             * For other font types, which also create a texture object to render to, this also affects
             * the actual dimension of the underlying texture.
             * @param sizeX The horizontal size of the text container.
             * @param sizeY The vertical size of the text container.
             * @return true if successful.
             */
            virtual Bool SetContainerSize(Real sizeX, Real sizeY) = 0;
            /**
             * @brief Set the text node's horizontal container size.
             * See SetContainerSize().
             * @param sizeX The horizontal size of the text container.
             * @return true if successful.
             */
            virtual Bool SetContainerSizeX(Real sizeX) = 0;
            /**
             * @brief Set the text node's vertical container size.
             * See SetContainerSize().
             * @param sizeY The vertical size of the text container.
             * @return true if successful.
             */
            virtual Bool SetContainerSizeY(Real sizeY) = 0;
            /**
             * @brief Get the text node's horizontal container size.
             * @return The horizontal size of the text container.
             */
            virtual Real GetContainerSizeX() const = 0;
            /**
             * @brief Get the text node's vertical container size.
             * @return The vertical size of the text container.
             */
            virtual Real GetContainerSizeY() const = 0;
            
            /**
             * @brief Enable/disable container fitting.
             * If enabled, the given text is automatically downscaled when it does not fit into the
             * optional container rectangle given via SetContainerSize().
             * @param enabled If true, autofitting is enabled.
             * @return true if successful.
             */
            virtual Bool SetContainerFittingEnabled(Bool enabled) = 0;
            /**
             * @brief Check if container fitting is enabled.
             * @return true if container fitting is enabled.
             */
            virtual Bool IsContainerFittingEnabled() const = 0;

            /**
             * @brief Set the number of iterations to perform for container fitting.
             * By default, the number of iterations is 0, which always shrinks the text in X direction
             * when it does not fit in Y direction.
             * Setting iterations to a higher count tries to fill the container in both directions,
             * with a possible better effect for higher counts.
             * This method has no effect when container fitting is disabled.
             * @param numIterations The number of iterations
             * @return true if successful.
             */
            virtual Bool SetNumberOfContainerFittingIterations(UInt32 numIterations) = 0;
            /**
             * @brief Get the number of iterations to perform for container fitting.
             * @return The number of iterations
             */
            virtual UInt32 GetNumberOfContainerFittingIterations() const = 0;

            /**
             * @brief Set the text alignment unit.
             * For the sake of rendering quality, it is often desired to render text using a bitmap font
             * at exact pixel coordinates, so that no blurring occurs due to hardware filtering. For this
             * reason, it is possible to specify both a horizontal and vertical alignment unit, which
             * ensures that all characters are only positioned at locations that are equally dividable by
             * the given unit values. For this to work however, the virtual coordinate system of the
             * camera used to render the text must also be grid-aligned, as the text alignment algorithm
             * only acts on virtual coordinates and not on pixel coordinates!
             * @param unitX The horizontal alignment unit.
             * @param unitY The vertical alignment unit.
             * @return true if successful.
             */
            virtual Bool SetAlignmentUnit(Real unitX, Real unitY) = 0;
            /**
             * @brief Set the horizontal text alignment unit.
             * See SetAlignmentUnit().
             * @param unitX The horizontal alignment unit.
             * @return true if successful.
             */
            virtual Bool SetAlignmentUnitX(Real unitX) = 0;
            /**
             * @brief Set the vertical text alignment unit.
             * See SetAlignmentUnit().
             * @param unitY The vertical alignment unit.
             * @return true if successful.
             */
            virtual Bool SetAlignmentUnitY(Real unitY) = 0;
            /**
             * @brief Get the horizontal text alignment unit.
             * @return The horizontal alignment unit.
             */
            virtual Real GetAlignmentUnitX() const = 0;
            /**
             * @brief Get the vertical text alignment unit.
             * @return The vertical alignment unit.
             */
            virtual Real GetAlignmentUnitY() const = 0;
            
            /**
             * @brief Set the container alignment.
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
             * @brief Set the object bounding mode.
             * The given values specify how the geometry's bounding volume is calculated, mainly used
             * for automatic alignment via Graph::IAligner nodes.
             * A value of IEnums::OBJECT_BOUNDING_MODE_CONTAINER uses the given container size along the
             * respective axis, and a value of IEnums::OBJECT_BOUNDING_MODE_CONTENTS uses the actual text
             * size. If no explicit container size is given, the actual text size is used for the container size.
             * @param modeX The horizontal bounding mode.
             * @param modeY The vertical bounding mode.
             * @return true if successful.
             */
            virtual Bool SetObjectBoundingMode(IEnums::ObjectBoundingMode modeX, IEnums::ObjectBoundingMode modeY) = 0;
            /**
             * @brief Set the horizontal object bounding mode.
             * See SetObjectBoundingMode().
             * @param modeX The horizontal bounding mode.
             * @return true if successful.
             */
            virtual Bool SetObjectBoundingModeX(IEnums::ObjectBoundingMode modeX) = 0;
            /**
             * @brief Set the vertical object bounding mode.
             * See SetObjectBoundingMode().
             * @param modeY The vertical bounding mode.
             * @return true if successful.
             */
            virtual Bool SetObjectBoundingModeY(IEnums::ObjectBoundingMode modeY) = 0;
            /**
             * @brief Get the horizontal object bounding mode.
             * @return The horizontal object bounding mode.
             */
            virtual IEnums::ObjectBoundingMode GetObjectBoundingModeX() const = 0;
            /**
             * @brief Get the vertical object bounding mode.
             * @return The vertical object bounding mode.
             */
            virtual IEnums::ObjectBoundingMode GetObjectBoundingModeY() const = 0;

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
             * @brief Set horizontal and vertical offsets used for outline rendering.
             * @param offsetX The horizontal offset.
             * @param offsetY The vertical offset.
             * @return true if successful.
             */
            virtual Bool SetOffset(Real offsetX, Real offsetY) = 0;
            /**
             * @brief Set the horizontal offset used for outline rendering.
             * @param offsetX The horizontal offset.
             * @return true if successful.
             */
            virtual Bool SetOffsetX(Real offsetX) = 0;
            /**
             * @brief Set the vertical offset used for outline rendering.
             * @param offsetY The vertical offset.
             * @return true if successful.
             */
            virtual Bool SetOffsetY(Real offsetY) = 0;
            /**
             * @brief Get the horizontal offset used for outline rendering.
             * @return The horizontal offset.
             */
            virtual Real GetOffsetX() const = 0;
            /**
             * @brief Get the vertical offset used for outline rendering.
             * @return The vertical offset.
             */
            virtual Real GetOffsetY() const = 0;
            
            /**
             * @brief Set the underlying texture's actual pixel format for outline fonts.
             * @param pixelFormat The pixel format to use.
             * @return true if successful.
             */
            virtual Bool SetPixelFormat(IEnums::PixelFormat pixelFormat) = 0;
            /**
             * @brief Get the underlying texture's actual pixel format.
             * @return The texture's pixel format.
             */
            virtual IEnums::PixelFormat GetPixelFormat() const = 0;
            
            /**
             * @brief Check if a given UTF8 character sequence is printable.
             * @param utf8Char A C-String containing the UTF8 character sequence to check.
             * @return true if the UTF8 character is printable.
             */
            virtual Bool IsCharacterPrintable(const Char* utf8Char) const = 0;
            /**
             * @brief Check if a given UTF8 character sequence is printable.
             * @param utf8Char A String containing the UTF8 character sequence to check.
             * @return true if the UTF8 character is printable.
             */
            virtual Bool IsCharacterPrintable(const String& utf8Char) const = 0;
            
            /**
             * @brief Enable/disable prescaling if the text geometry is rendering to a texture.
             * See Graph::ITexture::SetPrescalingEnabled().
             * @param enabled If true, prescaling is enabled.
             * @return true if successful.
             */
            virtual Bool SetPrescalingEnabled(Bool enabled) = 0;
            /**
             * @brief Check if prescaling is enabled.
             * @return true if enabled.
             */
            virtual Bool IsPrescalingEnabled() const = 0;
            
            /**
             * @brief Allow/disallow the use of a NPOT texture if outline fonts are used.
             * @param allowed If true, NPOT textures are allowed.
             * @return true if successful.
             */
            virtual Bool SetNonPowerOfTwoTextureAllowed(Bool allowed) = 0;
            /**
             * @brief Check if the use of a NPOT texture for outline fonts is allowed.
             * @return true if NPOT textures are allowed.
             */
            virtual Bool IsNonPowerOfTwoTextureAllowed() const = 0;
            
        protected:
            virtual ~ITextGeometry() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::ITextGeometry nodes.
         */
        typedef IGenericNodeTarget<ITextGeometry> ITextGeometryNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_TEXT_GEOMETRY_H__
