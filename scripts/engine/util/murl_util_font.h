// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_UTIL_FONT_H__
#define __MURL_UTIL_FONT_H__

#include "murl_i_font.h"

namespace Murl
{
    namespace Resource
    {
        class IFont;
    }

    namespace Util
    {
        class OutlineRasterizer;

        /**
         * @ingroup MurlUtilVideoClasses
         * @brief The font rendering class, see IFont.
         */
        class Font : public IFont
        {
        public:
            /**
             * @brief Constructor taking a font resource and size.
             * @param resourceFont The font resource.
             * @param size The size of the font.
             */
            Font(const Resource::IFont* resourceFont, Real size);

            /**
             * @brief The destructor.
             */
            virtual ~Font();

            /**
             * @brief Implementation of IFont::SetSize().
             * @param size The font size.
             * @return true if successful.
             */
            virtual Bool SetSize(Real size);
            /**
             * @brief Implementation of IFont::GetSize().
             * @return The font size.
             */
            virtual Real GetSize() const;

            /**
             * @brief Implementation of IFont::SetSpacing().
             * @param spacing The character spacing value.
             * @return true if successful.
             */
            virtual Bool SetSpacing(Real spacing);
            /**
             * @brief Implementation of IFont::GetSpacing().
             * @return The character spacing value.
             */
            virtual Real GetSpacing() const;

            /**
             * @brief Implementation of IFont::SetLeading().
             * @param leading The leading value.
             * @return true if successful.
             */
            virtual Bool SetLeading(Real leading);
            /**
             * @brief Implementation of IFont::GetLeading().
             * @return The font leading value.
             */
            virtual Real GetLeading() const;

            /**
             * @brief Implementation of IFont::SetEmbolding().
             * @param strength The embolding strength value.
             * @return true if successful.
             */
            virtual Bool SetEmbolding(Real strength);
            /**
             * @brief Implementation of IFont::GetEmbolding().
             * @return The embolding strength value.
             */
            virtual Real GetEmbolding() const;

            /**
             * @brief Implementation of IFont::SetBlur().
             * @param strength The positive blur strength value.
             * @return true if successful.
             */
            virtual Bool SetBlur(Real strength);
            /**
             * @brief Implementation of IFont::GetBlur().
             * @return The blur strength value.
             */
            virtual Real GetBlur() const;

            /**
             * @brief Implementation of IFont::SetSpaceWidthFactor().
             * @param factor The space width factor.
             * @return true if successful.
             */
            virtual Bool SetSpaceWidthFactor(Real factor);
            /**
             * @brief Implementation of IFont::GetSpaceWidthFactor().
             * @return The space width factor.
             */
            virtual Real GetSpaceWidthFactor() const;

            /**
             * @brief Implementation of IFont::SetDigitWidthFactor().
             * @param factor The digit width factor.
             * @return true if successful.
             */
            virtual Bool SetDigitWidthFactor(Real factor);
            /**
             * @brief Implementation of IFont::GetDigitWidthFactor().
             * @return The digit width factor.
             */
            virtual Real GetDigitWidthFactor() const;

            /**
             * @brief Implementation of IFont::SetSameDigitWidthEnabled().
             * @param enabled If true, all digits use the same horizontal advance value.
             * @return true if successful.
             */
            virtual Bool SetSameDigitWidthEnabled(Bool enabled);
            /**
             * @brief Implementation of IFont::IsSameDigitWidthEnabled().
             * @return true if all digits use the same horizontal advance value.
             */
            virtual Bool IsSameDigitWidthEnabled() const;

            /**
             * @brief Implementation of IFont::RenderText().
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
                                    IVideoSurface* surface) const;

            /**
             * @brief Implementation of IFont::QueryTextSize().
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
                                       Real& textSizeX, Real& textSizeY) const;

            /**
             * @brief Set the font resource.
             * @param resourceFont The font resource.
             */
            virtual void SetResourceFont(const Resource::IFont* resourceFont);
            /**
             * @brief Get the font resource.
             * @return The font resource.
             */
            virtual const Resource::IFont* GetResourceFont() const;

        protected:
            Bool GetLine(const Char* textBytes, UInt32 start, UInt32 end, Real maxSizeX, UInt32& last, UInt32& next, Real& sizeX, Bool& hasLf) const;

            const Resource::IFont* mResourceFont;

            Real mSize;
            Real mSpacing;
            Real mLeading;
            Real mEmboldingStrength;
            Real mBlurStrength;
            Real mSpaceWidthFactor;
            Real mDigitWidthFactor;
            Bool mIsSameDigitWidthEnabled;

            OutlineRasterizer* mRasterizer;
        };
    }
}

#endif  // __MURL_UTIL_FONT_H__
