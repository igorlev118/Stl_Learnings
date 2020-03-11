// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_RESOURCE_I_FONT_H__
#define __MURL_RESOURCE_I_FONT_H__

#include "murl_util_iff.h"

namespace Murl
{
    class IVideoStream;
    
    namespace Resource
    {
        class IRectangle;
        class IObject;
        class IOutline;

        /**
         * @ingroup MurlResourceObjectInterfaces
         * @interface IFont
         * @brief The IFont resource object interface.
         * A font resource can either store a number of individual glyph rectangles referencing
         * sub-regions of a Resource::IImage in order to render bitmap fonts, or a number of
         * glyph outlines for rendering vector fonts on the fly (without the need of a
         * Resource::IImage).
         * Note, that bitmap font rendering works similar to using a Resource::IAtlas, in that
         * the font resource does not store the actual glyph bitmaps. A corresponding
         * Resource::IImage must be active during rendering e.g. a Graph::ITextGeometry object
         * to produce the correct output.
         */
        class IFont
        {
        public:
            /// IFF file specific structs
            struct Iff
            {
                /// IFF identifiers
                enum
                {
                    /// The four character code identifying a native resource as a font.
                    FOURCC = 'FONT',
                    /// The version of a native resource supported by the engine.
                    VERSION = '1.00'
                };

                /**
                 * @struct HeaderChunk
                 * @brief The IFF header chunk of a native font resource.
                 */
                struct HeaderChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as a HeaderChunk.
                        FOURCC = 'HEAD'
                    };

                    /// The actual resource version.
                    UInt32 mVersion;

                    /// The font scale factor.
                    Float mScaleFactor;
                    /// The vertical size of a line.
                    Float mSizeY;
                    /// The base line offset.
                    Float mBaseLine;
                    /// The font's ascent.
                    Float mAscent;
                    /// The font's descent.
                    Float mDescent;
                    /// The spacing, i.e. horizontal distance between glyphs.
                    Float mSpacing;
                    /// The leading, i.e. vertical distance between lines.
                    Float mLeading;
                    /// The width of the white space character.
                    Float mSpaceWidth;
                    /// The common digit width.
                    Float mDigitWidth;
                    /// The horizontal screen offset for rendering.
                    Float mOffsetX;
                    /// The vertical screen offset for rendering.
                    Float mOffsetY;
                };

                /**
                 * @struct GlyphsChunk
                 * @brief An IFF chunk of a native font resource storing multiple glyph structures.
                 * The data pointed to by mGlyphsDataOffset must be interpreted as a pointer to
                 * an array of Raw::GlyphData structs, with the data size in bytes equalling
                 * mNumberOfGlyphs*sizeof(Raw::GlyphData).
                 */
                struct GlyphsChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as a GlyphsChunk.
                        FOURCC = 'GLPH'
                    };
                    
                    /// The total number of glyphs in this chunk.
                    UInt32 mNumberOfGlyphs;
                    /// An offset into the chunk where the glyph data is stored. See IffOffset().
                    UInt32 mGlyphDataOffset;
                };

                /**
                 * @struct OutlineChunk
                 * @brief An IFF chunk of a native font resource storing multiple outline structures.
                 * This chunk stores the vector outline(s) of a single glyph, defined by its
                 * Unicode character code.
                 */
                struct OutlineChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as an OutlineChunk.
                        FOURCC = 'OUTL'
                    };

                    /// The Unicode value.
                    UInt32 mCharCode;

                    /// The horizontal size of the glyph.
                    Float mSizeX;
                    /// The horizontal size of the glyph.
                    Float mSizeY;

                    /// The total number of outline points.
                    UInt32 mNumberOfPoints;
                    /// The total number of outline contours.
                    UInt32 mNumberOfContours;

                    /// Internal rendering flags, from the IOutline::OutlineFlag enumeration
                    UInt32 mFlags;

                    /// An offset into the chunk where the outline's points are stored. See IffOffset().
                    UInt32 mPointsDataOffset;
                    /// An offset into the chunk where the outline's contours are stored. See IffOffset().
                    UInt32 mContoursDataOffset;
                    /// An offset into the chunk where the tags (IOutline::OutlineTag) are stored. See IffOffset().
                    UInt32 mTagsDataOffset;
                };

                /**
                 * @struct KerningChunk
                 * @brief An optional IFF chunk of a native font resource storing kerning information.
                 * The data pointed to by mKerningPairDataOffset must be interpreted as a pointer to
                 * an array of Raw::KerningPair structs, with the data size in bytes equalling
                 * mNumberOfKerningPairs*sizeof(Raw::KerningPair).
                 */
                struct KerningChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as a KerningChunk.
                        FOURCC = 'KERN'
                    };
                    
                    /// The total number of kerning pairs in this chunk.
                    UInt32 mNumberOfKerningPairs;
                    /// An offset into the chunk where the kerning information is stored. See IffOffset().
                    UInt32 mKerningPairDataOffset;
                };
            };

            /// Raw data structs
            struct Raw
            {
                /**
                 * @struct GlyphData
                 * @brief A single bitmap glyph descriptor.
                 */
                struct GlyphData
                {
                    /// The glyph's Unicode value.
                    UInt32 mCharCode;

                    /// The start X texture coordinate (left).
                    Float mTexCoordX1;
                    /// The start Y texture coordinate (bottom).
                    Float mTexCoordY1;
                    /// The end X texture coordinate (right).
                    Float mTexCoordX2;
                    /// The end Y texture coordinate (top).
                    Float mTexCoordY2;

                    /// The start X screen coordinate (left).
                    Float mCoordX1;
                    /// The start Y screen coordinate (bottom).
                    Float mCoordY1;
                    /// The end X screen coordinate (right).
                    Float mCoordX2;
                    /// The end Y screen coordinate (top).
                    Float mCoordY2;

                    /// The actual cropped horizontal size of the glyph.
                    Float mSizeX;
                    /// The actual cropped vertical size of the glyph.
                    Float mSizeY;
                };

                /**
                 * @struct KerningPair
                 * @brief A single kerning pair descriptor.
                 */
                struct KerningPair
                {
                    /// The Unicode value of the left glyph.
                    UInt32 mCharCodeLeft;
                    /// The Unicode value of the right glyph.
                    UInt32 mCharCodeRight;
                    
                    /// The horizontal offset.
                    Float mOffset;
                };
            };
            
            /**
             * @brief Get the mutable Resource::IObject interface.
             * @return The IObject interface.
             */
            virtual IObject* GetObjectInterface() = 0;
            /**
             * @brief Get the constant Resource::IObject interface.
             * @return The IObject interface.
             */
            virtual const IObject* GetObjectInterface() const = 0;

            /**
             * @brief Get the font's scale factor.
             * @return The scale factor.
             */
            virtual Real GetScaleFactor() const = 0;
            /**
             * @brief Get the font's vertical line size.
             * @return The vertical line size.
             */
            virtual Real GetSizeY() const = 0;
            /**
             * @brief Get the font's base line offset.
             * @return The base line offset.
             */
            virtual Real GetBaseLine() const = 0;
            /**
             * @brief Get the font's ascent.
             * @return The ascent.
             */
            virtual Real GetAscent() const = 0;
            /**
             * @brief Get the font's descent.
             * @return The descent.
             */
            virtual Real GetDescent() const = 0;
            /**
             * @brief Get the font spacing, i.e. the horizontal distance between glyphs.
             * @return The spacing value.
             */
            virtual Real GetSpacing() const = 0;
            /**
             * @brief Get the font leading, i.e. the vertical distance between lines.
             * @return The leading value.
             */
            virtual Real GetLeading() const = 0;
            /**
             * @brief Get the horizontal size of the whitespace character.
             * @return The whitespace width.
             */
            virtual Real GetSpaceWidth() const = 0;
            /**
             * @brief Get the common horizontal size of all digits.
             * @return The digit width.
             */
            virtual Real GetDigitWidth() const = 0;
            /**
             * @brief Get the horizontal screen offset for rendering.
             * @return The horizontal offset.
             */
            virtual Real GetOffsetX() const = 0;
            /**
             * @brief Get the vertical screen offset for rendering.
             * @return The vertical offset.
             */
            virtual Real GetOffsetY() const = 0;

            /**
             * @brief Check if the font resource contains bitmap glyph rectangles.
             * @return true if present.
             */
            virtual Bool HasRectangles() const = 0;
            /**
             * @brief Get the actual number of bitmap glyph rectangles contained in the font.
             * @return The number of rectangles.
             */
            virtual UInt32 GetNumberOfRectangles() const = 0;
            /**
             * @brief Get a bitmap glyph rectangle by its index.
             * @param index The index in the range from 0 to GetNumberOfRectangles()-1.
             * @return A pointer to the glyph's rectangle, or null if index is out of range.
             */
            virtual const IRectangle* GetRectangleByIndex(UInt32 index) const = 0;
            /**
             * @brief Get a bitmap glyph rectangle for a given Unicode value.
             * @param charCode The Unicode value to query.
             * @return A pointer to the glyph's rectangle, or null if not found.
             */
            virtual const IRectangle* GetRectangleByCode(UInt32 charCode) const = 0;
            
            /**
             * @brief Check if the font resource contains glyph outlines.
             * @return true if present.
             */
            virtual Bool HasOutlines() const = 0;
            /**
             * @brief Get the actual number of glyph outlines contained in the font.
             * @return The number of outlines.
             */
            virtual UInt32 GetNumberOfOutlines() const = 0;
            /**
             * @brief Get a glyph outline by its index.
             * @param index The index in the range from 0 to GetNumberOfOutlines()-1.
             * @return A pointer to the glyph's outline, or null if index is out of range.
             */
            virtual const IOutline* GetOutlineByIndex(UInt32 index) const = 0;
            /**
             * @brief Get a glyph outline for a given Unicode value.
             * @param charCode The Unicode value to query.
             * @return A pointer to the glyph's outline, or null if not found.
             */
            virtual const IOutline* GetOutlineByCode(UInt32 charCode) const = 0;

            /**
             * @brief Check if the font resource contains kerning information.
             * @return true if present.
             */
            virtual Bool HasKerning() const = 0;
            /**
             * @brief Get the kerning offset for a pair of Unicode characters.
             * @param charCodeLeft The Unicode value of the left character.
             * @param charCodeRight The Unicode value of the right character.
             * @return The horizontal offset.
             */
            virtual Real GetKerningByCode(UInt32 charCodeLeft, UInt32 charCodeRight) const = 0;
            
        protected:
            virtual ~IFont() {}
        };
    }
}

#endif  // __MURL_RESOURCE_I_FONT_H__
