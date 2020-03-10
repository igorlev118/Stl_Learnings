// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_I_SYSTEM_FONT_CONTROL_H__
#define __MURL_I_SYSTEM_FONT_CONTROL_H__

#include "murl_i_controlable.h"
#include "murl_i_font.h"

namespace Murl
{
    class IVideoStream;

    /**
     * @ingroup MurlInterfaces
     * @interface ISystemFontControl
     * @brief The system font control interface.
     */
    class ISystemFontControl : public IControlable
    {
    public:
        /**
         * @brief Get the number of font identifiers.
         * @return The number of font identifiers.
         */
        virtual UInt32 GetNumberOfSystemFontIds() const = 0;
        /**
         * @brief Get the font identifier.
         * @param index The index in range [0 .. GetNumberOfSystemFontIds() - 1].
         * @return The font identifier.
         */
        virtual const String& GetSystemFontId(UInt32 index) const = 0;
        
        /**
         * @brief Create a system font object.
         * @param fontId The font identifier.
         * @param fontSize The font size.
         * @return The system font object or null if font identifier is unknown.
         */
        virtual IFont* CreateSystemFont(const String& fontId, Real fontSize) const = 0;
        /**
         * @brief Destroy a system font object.
         * @param font The system font object to destroy.
         */
        virtual void DestroySystemFont(IFont*& font) const = 0;
        
        /**
         * @brief Create a video stream object for system font rendering.
         * @param pixelFormat The pixel format of the new video object.
         * @param pixelSizeX The number of horizontal pixels of the new video object.
         * @param pixelSizeY The number of vertical pixels of the new video object.
         * @return The new video stream object or null if not available.
         */
        virtual IVideoStream* CreateVideoStream(IEnums::PixelFormat pixelFormat,
                                                UInt32 pixelSizeX, UInt32 pixelSizeY) const = 0;
        /**
         * @brief Destroy a video stream object.
         * @param stream The video stream object to destroy.
         */
        virtual void DestroyVideoStream(IVideoStream*& stream) const = 0;
        
    protected:
        virtual ~ISystemFontControl() {}
    };
}

#endif  // __MURL_I_SYSTEM_FONT_CONTROL_H__
