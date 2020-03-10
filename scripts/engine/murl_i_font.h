// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_I_FONT_H__
#define __MURL_I_FONT_H__

#include "murl_color.h"
#include "murl_i_enums.h"

namespace Murl
{
    class IVideoSurface;
    
    /**
     * @ingroup MurlInterfaces
     * @interface IFont
     * @brief The font interface.
     */
    class IFont
    {
    public:
        virtual ~IFont() {}

        /**
         * @brief Set the font size.
         * @param size The font size.
         * @return true if successful.
         */
        virtual Bool SetSize(Real size) = 0;
        /**
         * @brief Get the font size.
         * @return The font size.
         */
        virtual Real GetSize() const = 0;

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
         * by a text rendering object.\n\n
         * Note also that not all types of fonts allow setting a custom spacing value.
         * If not supported, this method returns false.
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
         * @brief Get the font leading value.
         * @return The font leading value.
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
         * original width defined by the font used for rendering.\n\n
         * Note that not all types of fonts allow setting a custom space width factor.
         * If not supported, this method returns false.
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
         * e.g. 0.1 will result in overlapping digits without actually scaling them.\n\n
         * Note also that not all types of fonts allow setting a custom digit width value.
         * If not supported, this method returns false.
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
         * Note that not all types of fonts allow a common digit width.
         * If not supported, this method returns false.
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
         * @brief Render a text into a video stream.
         * @param text The text to render.
         * @param textColor The text color to render.
         * @param backgroundColor The text background color to render.
         * @param clearSurface If true, the output surface is cleared before rendering.
         * @param enableWordWrap If true, word wrapping is enabled.
         * @param containerPosX The horizontal text position in the video stream.
         * @param containerPosY The vertical text position in the video stream.
         * @param containerSizeX The horizontal size of the text rectangle, or 0
         *      if the video stream's X size should be used
         * @param containerSizeY The vertical size of the text rectangle, or 0 if 
         *      the video stream's Y size should be used
         * @param alignX The horizontal text alignment.
         * @param alignY The vertical text alignment.
         * @param surface The destination video surface.
         * @return true if successful.
         */
        virtual Bool RenderText(const String& text,
                                const Color& textColor, const Color& backgroundColor,
                                Bool clearSurface, Bool enableWordWrap,
                                Real containerPosX, Real containerPosY,
                                Real containerSizeX, Real containerSizeY,
                                IEnums::TextAlignmentX alignX, IEnums::TextAlignmentY alignY,
                                IVideoSurface* surface) const = 0;
        
        /**
         * @brief Query the pixel dimensions of a given text.
         * @param text The text to query.
         * @param enableWordWrap If true, word wrapping is enabled.
         * @param containerPosX The horizontal text position in the video stream.
         * @param containerPosY The vertical text position in the video stream.
         * @param containerSizeX The horizontal size of the text rectangle, or 0
         *      if the video stream's X size should be used
         * @param containerSizeY The vertical size of the text rectangle, or 0 if
         *      the video stream's Y size should be used
         * @param textSizeX The text width return value.
         * @param textSizeY The text height return value.
         * @return true if successful.
         */
        virtual Bool QueryTextSize(const String& text,
                                   Bool enableWordWrap,
                                   Real containerPosX, Real containerPosY,
                                   Real containerSizeX, Real containerSizeY,
                                   Real& textSizeX, Real& textSizeY) const = 0;
        
    protected:
    };
}

#endif  // __MURL_I_FONT_H__
