// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_TEXT_H__
#define __MURL_GRAPH_I_TEXT_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_graph_i_generic_resource_target.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Graph
    {
        class INode;
        class IText;
        class ITexture;

        typedef IGenericNodeTarget<ITexture> ITextureNodeTarget;
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IText nodes.
         */
        typedef IGenericNodeTarget<IText> ITextNodeTarget;

        /**
         * @ingroup MurlGraphPropertyInterfaces
         * @interface IText
         * @brief The IText property interface.
         * This interface represents a generic way to describe an object used for
         * text output.
         */
        class IText
        {
        public:
            /**
             * @brief Get a mutable Graph::IFontResourceTarget container.
             * This method returns a mutable pointer to a Graph::IFontResourceTarget
             * container, which allows to add, remove or query the font resources referenced
             * by a node implementing this interface.
             * @return The mutable Graph::IFontResourceTarget container, or null if not available
             */
            virtual IFontResourceTarget* GetFontResourceTarget() = 0;
            /**
             * @brief Get a constant Graph::IFontResourceTarget container.
             * This method returns a constant pointer to a Graph::IFontResourceTarget
             * container, which allows to query the font resources referenced by a node
             * implementing this interface.
             * @return The constant Graph::IFontResourceTarget container, or null if not available
             */
            virtual const IFontResourceTarget* GetFontResourceTarget() const = 0;

            /**
             * @brief Set the ID of the system font used to render the text.
             * @param fontName A valid system font name, e.g. "SansBold".
             * @return true if successful.
             */
            virtual Bool SetSystemFontName(const String& fontName) = 0;
            /**
             * @brief Get the ID of the system font used to render the text.
             * @return The predefined system font ID.
             */
            virtual const String& GetSystemFontName() const = 0;

            /**
             * @brief Set the type of font used for rendering.
             * If not specified, the actual font type is retrieved from the given values
             * for either system font name or the font resource. Once initialized, the node's
             * font type cannot be changed anymore.
             * @param fontType The font type.
             * @return true if successful.
             */
            virtual Bool SetFontType(IEnums::FontType fontType) = 0;
            /**
             * @brief Get the type of font used for rendering.
             * @return The font type.
             */
            virtual IEnums::FontType GetFontType() const = 0;

            /**
             * @brief Set the font size.
             * @param fontSize The font size in system units.
             * @return true if successful.
             */
            virtual Bool SetFontSize(Real fontSize) = 0;
            /**
             * @brief Get the font size.
             * @return The font size in system units.
             */
            virtual Real GetFontSize() const = 0;
            
            /**
             * @brief Set the foreground (text) color used for rendering the text.
             * @param textColor The text color.
             * @return true if successful.
             */
            virtual Bool SetTextColor(const Color& textColor) = 0;
            /**
             * @brief Get the text color.
             * @return The text color.
             */
            virtual const Color& GetTextColor() const = 0;
            
            /**
             * @brief Set the background color used for rendering.
             * @param backgroundColor The background color.
             * @return true if successful.
             */
            virtual Bool SetBackgroundColor(const Color& backgroundColor) = 0;
            /**
             * @brief Get the background color.
             * @return The background color.
             */
            virtual const Color& GetBackgroundColor() const = 0;

            /**
             * @brief Get the optional mutable Graph::ITextNodeTarget parent container.
             * This method returns a mutable pointer to a Graph::ITextNodeTarget
             * container, which allows to add, remove or query the parent text node that is
             * used as a source for the displayed text.
             * @return The mutable Graph::ITextNodeTarget parent container, or null if not available
             */
            virtual ITextNodeTarget* GetParentTextNodeTarget() = 0;
            /**
             * @brief Get the optional constant Graph::ITextNodeTarget parent container.
             * This method returns a constant pointer to a Graph::ITextNodeTarget
             * container, which allows to query the parent text node that is
             * used as a source for the displayed text.
             * @return The constant Graph::ITextNodeTarget parent container, or null if not available
             */
            virtual const ITextNodeTarget* GetParentTextNodeTarget() const = 0;
            
            /**
             * @brief Get the optional mutable output Graph::ITextureNodeTarget container.
             * This method returns a mutable pointer to a Graph::ITextureNodeTarget
             * container, which allows to add, remove or query the texture node that is used as an
             * optional output surface for the displayed text.
             * @return The mutable output Graph::ITextureNodeTarget container, or null if not available
             */
            virtual ITextureNodeTarget* GetOutputTextureNodeTarget() = 0;
            /**
             * @brief Get the optional constant output Graph::ITextureNodeTarget container.
             * This method returns a constant pointer to a Graph::ITextureNodeTarget
             * container, which allows to query the texture node that is used as an
             * optional output surface for the displayed text.
             * @return The constant output Graph::ITextureNodeTarget container, or null if not available
             */
            virtual const ITextureNodeTarget* GetOutputTextureNodeTarget() const = 0;
            
            /**
             * @brief Get a mutable Graph::ITextResourceTarget container.
             * This method returns a mutable pointer to a Graph::ITextResourceTarget
             * container, which allows to add, remove or query the text resources referenced
             * by a node implementing this interface.
             * @return The mutable Graph::ITextResourceTarget container, or null if not available
             */
            virtual ITextResourceTarget* GetTextResourceTarget() = 0;
            /**
             * @brief Get a constant Graph::ITextResourceTarget container.
             * This method returns a constant pointer to a Graph::ITextResourceTarget
             * container, which allows to query the text resources referenced by a node
             * implementing this interface.
             * @return The constant Graph::ITextResourceTarget container, or null if not available
             */
            virtual const ITextResourceTarget* GetTextResourceTarget() const = 0;

            /**
             * @brief Set the text to be displayed.
             * @param text A string containing the text to be displayed.
             * @return true if successful.
             */
            virtual Bool SetText(const String& text) = 0;
            /**
             * @brief Get the displayed text.
             * @return A constant reference to the string representing the displayed text.
             */
            virtual const String& GetText() const = 0;
            
            /**
             * @brief Set the character spacing value.
             * This method sets the character spacing used for output, i.e. the horizontal
             * distance between neighbored characters. The given spacing value adds to the
             * default value specified in the font used for rendering this text; a value of
             * 0.0 represents the font's original spacing, a positive value increases the
             * horizontal distance between characters, and a negative value decreases it.\n\n
             * Note: The given spacing value is not scaled by the font used; if e.g. a positive
             * value is used for a large font, the same value used with a smaller version of
             * that same font will result in a (relatively) larger distance between characters.
             * It is however influenced by a possible additional scaling operation performed
             * by a text rendering object.
             * @param spacing The character spacing value.
             * @return true if successful.
             */
            virtual Bool SetSpacing(Real spacing) = 0;
            /**
             * @brief Get the character spacing value.
             * @return The character spacing value.
             */
            virtual Real GetSpacing() const = 0;
            
            /**
             * @brief Set the leading value.
             * This method sets the leading value used for output, i.e. the vertical distance
             * between subsequent text lines. The given leading value adds to the default value
             * specified in the font used for rendering this text; a value of 0.0 represents
             * the font's original leading, a positive value increases the vertical distance
             * between lines, and a negative value decreases it.\n\n
             * Note: The given leading value is not scaled by the font used; if e.g. a positive
             * value is used for a large font, the same value used with a smaller version of
             * that same font will result in a (relatively) larger distance between lines.
             * It is however influenced by a possible additional scaling operation performed
             * by a text rendering object.
             * @param leading The leading value.
             * @return true if successful.
             */
            virtual Bool SetLeading(Real leading) = 0;
            /**
             * @brief Get the leading value.
             * @return The leading value.
             */
            virtual Real GetLeading() const = 0;

            /**
             * @brief Set the embolding strength value.
             * The embolding strength determines the "boldness" or "weight" of the font's
             * rendered glyphs. Positive values result in thicker lines, and negative values
             * can be used to make the font "thinner". Useful values are in the range from
             * -1 to +1, but can also lie beyond that range.\n\n
             * Note that not all types of fonts allow glyph embolding.
             * If not supported, this method returns false.
             * @param strength The embolding strength value.
             * @return true if successful.
             */
            virtual Bool SetEmbolding(Real strength) = 0;
            /**
             * @brief Get the embolding strength value.
             * @return The embolding strength value.
             */
            virtual Real GetEmbolding() const = 0;
            
            /**
             * @brief Set the blur strength value.
             * @param strength The positive blur strength value.
             * @return true if successful.
             */
            virtual Bool SetBlur(Real strength) = 0;
            /**
             * @brief Get the blur strength value.
             * @return The blur strength value.
             */
            virtual Real GetBlur() const = 0;
            
            /**
             * @brief Set the space width factor.
             * This method sets a factor used to control the actual width of the white space
             * character. In some cases, it is useful to manually control the space character's
             * width, when a font's default space width produces too small or too big a
             * distance between subsequent words. A space width factor of 1.0 represents the
             * original width defined by the font used for rendering.
             * @param factor The space width factor.
             * @return true if successful.
             */
            virtual Bool SetSpaceWidthFactor(Real factor) = 0;
            /**
             * @brief Get the space width factor.
             * @return The space width factor.
             */
            virtual Real GetSpaceWidthFactor() const = 0;
            
            /**
             * @brief Set the digit width factor.
             * This method sets a factor used to control the horizontal advance of all digit
             * characters of a font ('0'-'9'). A digit width factor of 1.0 represents the
             * original width defined by the font used for rendering.\n\n
             * Note, that this value only influences distance and not visual width; a value of
             * e.g. 0.1 will result in overlapping digits without actually scaling them.
             * @param factor The digit width factor.
             * @return true if successful.
             */
            virtual Bool SetDigitWidthFactor(Real factor) = 0;
            /**
             * @brief Get the digit width factor.
             * @return The digit width factor.
             */
            virtual Real GetDigitWidthFactor() const = 0;
            
            /**
             * @brief Enable/disable unified digit width.
             * For certain use cases, such as a score counter in an action game, it is useful
             * to set a common width for all digits ('0'-'9'); doing so prevents the counter
             * from jittering due to different digit widths.
             * @param enabled If true, all digits use the same horizontal advance value.
             * @return true if successful.
             */
            virtual Bool SetSameDigitWidthEnabled(Bool enabled) = 0;
            /**
             * @brief Check if unified digit width is enabled.
             * @return true if all digits use the same horizontal advance value.
             */
            virtual Bool IsSameDigitWidthEnabled() const = 0;

            /**
             * @brief Enable/disable word wrapping.
             * @param enabled If true, word wrapping is enabled.
             * @return true if successful.
             */
            virtual Bool SetWordWrappingEnabled(Bool enabled) = 0;
            /**
             * @brief Check if word wrapping is enabled.
             * @return true if word wrapping is enabled.
             */
            virtual Bool IsWordWrappingEnabled() const = 0;
            
            /**
             * @brief Set the horizontal text alignment.
             * @param alignment The horizontal text alignment.
             * @return true if successful.
             */
            virtual Bool SetTextAlignmentX(IEnums::TextAlignmentX alignment) = 0;
            /**
             * @brief Get the horizontal text alignment.
             * @return The horizontal text alignment.
             */
            virtual IEnums::TextAlignmentX GetTextAlignmentX() const = 0;
            
            /**
             * @brief Set the vertical text alignment.
             * @param alignment The vertical text alignment.
             * @return true if successful.
             */
            virtual Bool SetTextAlignmentY(IEnums::TextAlignmentY alignment) = 0;
            /**
             * @brief Get the vertical text alignment.
             * @return The vertical text alignment.
             */
            virtual IEnums::TextAlignmentY GetTextAlignmentY() const = 0;
            
            /**
             * @brief Query the dimensions of a given UTF8 text.
             * @param text The text to query
             * @param sizeX A reference to a Real variable receiving the horizontal text size.
             * @param sizeY A reference to a Real variable receiving the vertical text size.
             * @return true if successful.
             */
            virtual Bool QueryTextSize(const String& text, Real& sizeX, Real& sizeY) const = 0;
            
        protected:
            virtual ~IText() {}
        };
    }
}

#endif // __MURL_GRAPH_I_TEXT_H__
