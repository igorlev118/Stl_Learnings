// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_RESOURCE_I_ATLAS_H__
#define __MURL_RESOURCE_I_ATLAS_H__

#include "murl_util_iff.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Resource
    {
        class IObject;
        class IRectangle;
        
        /**
         * @ingroup MurlResourceObjectInterfaces
         * @interface IAtlas
         * @brief The IAtlas resource object interface.
         * An atlas resource contains a number of structures, each storing both a coordinate
         * and a corresponding texture coordinate rectangle, which define the actual
         * size of e.g. a plane on screen together with its corresponding sub-region of a
         * texture.
         * Note that there is no texture image actually stored within the atlas resource.
         * When using the atlas for rendering, a corresponding Resource::IImage must be used
         * for a separate texture to produce the correct output.
         */
        class IAtlas
        {
        public:
            /// IFF file specific structs
            struct Iff
            {
                /// IFF identifiers
                enum
                {
                    /// The four character code identifying a native resource as an atlas.
                    FOURCC = 'ATLS',
                    /// The version of a native resource supported by the engine.
                    VERSION = '1.00'
                };

                /**
                 * @struct HeaderChunk
                 * @brief The IFF header chunk of a native atlas resource.
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

                    /// The horizontal texture reference size.
                    UInt32 mTextureSizeX;
                    /// The vertical texture reference size.
                    UInt32 mTextureSizeY;
                };

                /**
                 * @struct RectanglesChunk
                 * @brief An IFF chunk of a native atlas resource storing multiple rectangles.
                 * The data pointed to by mRectanglesOffset must be interpreted as a pointer
                 * to an array of Raw::Rectangle structs, with the data size in bytes equalling
                 * mNumberOfRectangles*sizeof(Raw::Rectangle).
                 */
                struct RectanglesChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as a RectanglesChunk.
                        FOURCC  = 'RECT',
                    };

                    /// The total number of rectangles in this chunk.
                    UInt32 mNumberOfRectangles;
                    /// An offset into the chunk where the rectangles' data is stored. See IffOffset().
                    UInt32 mRectanglesOffset;
                };

                struct RectangleInfoChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as a RectangleInfoChunk.
                        FOURCC  = 'RINF',
                    };

                    /// The zero-based index of the rectangle.
                    UInt32 mIndex;

                    /// The explicit material slot used for rendering, or -1 if undefined.
                    SInt32 mMaterialSlot;
                    /// The explicit parameters slot used for rendering, or -1 if undefined.
                    SInt32 mParametersSlot;
                    /// The explicit texture slot used, or -1 if undefined.
                    SInt32 mTextureSlot;

                    /// The horizontal texture reference size.
                    UInt32 mTextureSizeX;
                    /// The vertical texture reference size.
                    UInt32 mTextureSizeY;

                    /// An offset into the chunk where the rectangle's name is stored. See IffOffset().
                    UInt32 mNameOffset;
                    /// The size in bytes of the name string, including the terminating null character.
                    UInt32 mNameByteSize;
                };
            };
            
            /// Raw data structs
            struct Raw
            {
                /**
                 * @struct Rectangle
                 * @brief A single rectangle.
                 */
                struct Rectangle
                {
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
             * @brief Get the atlas' horizontal texture reference size, or 0 if undefined.
             * @return The horizontal reference size.
             */
            virtual UInt32 GetTextureSizeX() const = 0;
            /**
             * @brief Get the atlas' vertical texture reference size, or 0 if undefined.
             * @return The vertical reference size.
             */
            virtual UInt32 GetTextureSizeY() const = 0;

            /**
             * @brief Get the total number of rectangles stored in this resource.
             * @return The number of rectangles.
             */
            virtual UInt32 GetNumberOfRectangles() const = 0;
            /**
             * @brief Get the index of a rectangle with a given name.
             * @param rectangleName The name of the rectangle to query.
             * @return The zero-based index of the rectangle, or -1 if not found.
             */
            virtual SInt32 GetRectangleIndex(const Char* rectangleName) const = 0;
            /**
             * @brief Get the name of a rectangle at a given index.
             * @param rectangleIndex The zero-based index of the rectangle, in the range from
             *      0 to GetNumberOfRectangles()-1.
             * @return The name of the rectangle, or null if the index was out of range.
             */
            virtual const Char* GetRectangleName(UInt32 rectangleIndex) const = 0;

            /**
             * @brief Get the rectangle at a given index.
             * @param rectangleIndex The index in the range from 0 to GetNumberOfRectangles()-1.
             * @return A pointer to the rectangle, or null if index is out of bounds.
             */
            virtual const IRectangle* GetRectangle(UInt32 rectangleIndex) const = 0;

            /**
             * @brief Get the material slot of a rectangle at a given index.
             * @param rectangleIndex The index in the range from 0 to GetNumberOfRectangles()-1.
             * @return The slot, or -1 if not set or index is out of bounds.
             */
            virtual SInt32 GetRectangleMaterialSlot(UInt32 rectangleIndex) const = 0;
            /**
             * @brief Get the parameters slot of a rectangle at a given index.
             * @param rectangleIndex The index in the range from 0 to GetNumberOfRectangles()-1.
             * @return The slot, or -1 if not set or index is out of bounds.
             */
            virtual SInt32 GetRectangleParametersSlot(UInt32 rectangleIndex) const = 0;
            /**
             * @brief Get the texture slot of a rectangle at a given index.
             * @param rectangleIndex The index in the range from 0 to GetNumberOfRectangles()-1.
             * @return The slot, or -1 if not set or index is out of bounds.
             */
            virtual SInt32 GetRectangleTextureSlot(UInt32 rectangleIndex) const = 0;

            /**
             * @brief Get the horizontal texture reference size for a given rectangle.
             * @param rectangleIndex The index in the range from 0 to GetNumberOfRectangles()-1.
             * @return The horizontal reference size.
             */
            virtual UInt32 GetRectangleTextureSizeX(UInt32 rectangleIndex) const = 0;
            /**
             * @brief Get the vertical texture reference size for a given rectangle.
             * @param rectangleIndex The index in the range from 0 to GetNumberOfRectangles()-1.
             * @return The vertical reference size.
             */
            virtual UInt32 GetRectangleTextureSizeY(UInt32 rectangleIndex) const = 0;

        protected:
            virtual ~IAtlas() {}
        };
    }
}

#endif  // __MURL_RESOURCE_I_ATLAS_H__
