// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_RESOURCE_I_OUTLINE_H__
#define __MURL_RESOURCE_I_OUTLINE_H__

#include "murl_types.h"

namespace Murl
{
    namespace Resource
    {
        /**
         * @ingroup MurlResourceMiscInterfaces
         * @interface IOutline
         * @brief The IOutline resource interface.
         * This interface represents a single vector glyph outline, used in a 
         * Resource::IFont object.
         */
        class IOutline
        {
        public:
            /// Outline flags.
            enum OutlineFlag
            {
                OUTLINE_FLAG_NONE             = 0,
                
                OUTLINE_FLAG_OWNER            = (1 << 0),
                OUTLINE_FLAG_EVEN_ODD_FILL    = (1 << 1),
                OUTLINE_FLAG_REVERSE_FILL     = (1 << 2),
                OUTLINE_FLAG_IGNORE_DROPOUTS  = (1 << 3),
                OUTLINE_FLAG_SMART_DROPOUTS   = (1 << 4),
                OUTLINE_FLAG_INCLUDE_STUBS    = (1 << 5),
                
                OUTLINE_FLAG_HIGH_PRECISION   = (1 << 8),
                OUTLINE_FLAG_SINGLE_PASS      = (1 << 9),
                
                OUTLINE_FLAG_CLOCKWISE        = (1 << 16)
            };
            
            /// Outline tags.
            enum OutlineTag
            {
                OUTLINE_TAG_CONIC             = 0,
                OUTLINE_TAG_ON                = 1,
                OUTLINE_TAG_CUBIC             = 2,
                OUTLINE_TAG_MASK              = 3,
                OUTLINE_TAG_HAS_SCANMODE      = 4,
                OUTLINE_TAG_TOUCH_X           = 8,
                OUTLINE_TAG_TOUCH_Y           = 16,
                OUTLINE_TAG_TOUCH_BOTH        = (OUTLINE_TAG_TOUCH_X | OUTLINE_TAG_TOUCH_Y)
            };

            /**
             * @brief Get this outline's code value.
             * @return The code value.
             */
            virtual UInt32 GetCode() const = 0;
            
            /**
             * @brief Get the horizontal size of the glyph.
             * @return The horizontal size.
             */
            virtual Real GetSizeX() const = 0;
            /**
             * @brief Get the vertical size of the glyph.
             * @return The vertical size.
             */
            virtual Real GetSizeY() const = 0;
            
            /**
             * @brief Get the number of outline points.
             * @return The number of points.
             */
            virtual UInt32 GetNumberOfPoints() const = 0;
            /**
             * @brief Get the number of outline contours.
             * @return The number of contours.
             */
            virtual UInt32 GetNumberOfContours() const = 0;

            /**
             * @brief Get the outline points.
             * @return A pointer to the points.
             */
            virtual const Real* GetPoints() const = 0;
            /**
             * @brief Get the outline contours.
             * @return A pointer to the contours.
             */
            virtual const SInt16* GetContours() const = 0;
            /**
             * @brief Get the outline tags.
             * @return A pointer to the tags, from the OutlineTag enumeration
             */
            virtual const UInt8* GetTags() const = 0;

            /**
             * @brief Get the outline flags.
             * @return A bit mask of outline flags from the OutlineFlag enumeration.
             */
            virtual UInt32 GetFlags() const = 0;
            
        protected:
            virtual ~IOutline() {}
        };
    }
}

#endif  // __MURL_RESOURCE_I_OUTLINE_H__
