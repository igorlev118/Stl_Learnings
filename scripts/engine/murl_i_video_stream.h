// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_I_VIDEO_STREAM_H__
#define __MURL_I_VIDEO_STREAM_H__

#include "murl_i_video_surface.h"

namespace Murl
{
    /**
     * @ingroup MurlInterfaces
     * @interface IVideoStream
     * @brief The video stream interface.
     */
    class IVideoStream
    {
    public:
        /**
         * @brief The destructor.
         */
        virtual ~IVideoStream() {}
        
        /**
         * @brief Create a clone of the video stream object.
         * @return The new video stream object.
         */
        virtual IVideoStream* Clone() const = 0;
        /**
         * @brief Create a clone of the video with a specified pixel format.
         * @param pixelFormat The pixel format of the new video object.
         * @return The new video stream object or null if conversion is not available.
         */
        virtual IVideoStream* Clone(IEnums::PixelFormat pixelFormat) const = 0;
        /**
         * @brief Create a clone of the video with a specified pixel format and size.
         * @param pixelFormat The pixel format of the new video object.
         * @param pixelSizeX The number of horizontal pixels of the new video object.
         * @param pixelSizeY The number of vertical pixels of the new video object.
         * @return The new video stream object or null if conversion is not available.
         */
        virtual IVideoStream* Clone(IEnums::PixelFormat pixelFormat, UInt32 pixelSizeX, UInt32 pixelSizeY) const = 0;
        /**
         * @brief Create a clone with a specified pixel format and size and optional mip-mapping
         * @param pixelFormat The pixel format of the new video object.
         * @param pixelSizeX The number of horizontal pixels of the new video object.
         * @param pixelSizeY The number of vertical pixels of the new video object.
         * @param mipMapGen Specifies if and how mip maps are generated.
         * @return The new video stream object or null if conversion is not available.
         */
        virtual IVideoStream* Clone(IEnums::PixelFormat pixelFormat, UInt32 pixelSizeX, UInt32 pixelSizeY, IEnums::MipMapGenerationMode mipMapGen) const = 0;
        
        /**
         * @brief Get the total number of frames.
         * @return The number of frames.
         */
        virtual UInt32 GetNumberOfFrames() const = 0;
        /**
         * @brief Get the index of the frame at a given start time.
         * @param startTime The frame start time in seconds.
         * @return The frame index.
         */
        virtual UInt32 GetFrameIndex(Double startTime) const = 0;
        /**
         * @brief Get the start time of a frame at a given index.
         * @param frameIndex The index of the frame to query.
         * @return The frame's start time.
         */
        virtual Double GetStartTime(UInt32 frameIndex) const = 0;

        /**
         * @brief Get the number of frames per second.
         * @return The number of frames per second.
         */
        virtual Double GetFrameRate() const = 0;
        /**
         * @brief Get the duration of a single frame, i.e. the inverse frame rate.
         * @return The frame duration in seconds.
         */
        virtual Double GetFrameDuration() const = 0;
        /**
         * @brief Get the total duration of the stream, in seconds.
         * @return The total duration.
         */
        virtual Double GetTotalDuration() const = 0;

        /**
         * @brief Get the number of mip levels.
         * @return The number of mip levels.
         */
        virtual UInt32 GetNumberOfMipLevels() const = 0;
        /**
         * @brief Get the number of color planes.
         * Regular pixel formats (e.g. IEnums::PIXEL_FORMAT_R8_G8_B8_A8) only have one plane.
         * Planar YUV formats store 3 individual planes, one for each of the Y, U and V components,
         * in the order given by the pixel format itself (e.g. IEnums::PIXEL_FORMAT_Y8_U8_V8).
         * Semi-planar YUV formats have 2 planes, with index 0 representing the Y plane, and index
         * 1 storing the U and V components per pixel.
         * @return The number of color planes.
         */
        virtual UInt32 GetNumberOfPlanes() const = 0;

        /**
         * @brief Get the pixel format of the stream.
         * For regular (single plane) formats, this method usually returns the same pixel format
         * as the surfaces returned by GetDecodedSurface() or LockDecodedSurface(). For multi-plane
         * formats (such as IEnums::PIXEL_FORMAT_Y8_U8_V8) it returns the respective format, whereas
         * the individual plane surfaces return their internal format, such as IEnums::PIXEL_FORMAT_L8
         * for a Y plane or IEnums::PIXEL_FORMAT_L8_A8 for a combined UV plane.
         * @return The pixel format of the stream.
         */
        virtual IEnums::PixelFormat GetPixelFormat() const = 0;
        /**
         * @brief Get the number of bytes per pixel.
         * This method is a convenience to get the number of bytes per pixel for the stream's
         * pixel format, it only returns a concrete value for single-plane pixel formats. Querying
         * the number of bytes per pixel for multi-plane formats must be done by calling the
         * overloaded method GetBytesPerPixel(UInt32 planeIndex).
         * @return The number of bytes per pixel for the stream format.
         */
        virtual UInt32 GetBytesPerPixel() const = 0;
        /**
         * @brief Get the number of horizontal pixels.
         * @param mipLevel The mip level in the range [0 .. GetNumberOfMipLevels() - 1].
         * @return The number of horizontal pixels.
         */
        virtual UInt32 GetPixelSizeX(UInt32 mipLevel) const = 0;
        /**
         * @brief Get the number of vertical pixels.
         * @param mipLevel The mip level in the range [0 .. GetNumberOfMipLevels() - 1].
         * @return The number of vertical pixels.
         */
        virtual UInt32 GetPixelSizeY(UInt32 mipLevel) const = 0;
        /**
         * @brief Get the number of bytes per line.
         * @param mipLevel The mip level in the range [0 .. GetNumberOfMipLevels() - 1].
         * @return The number of bytes per line.
         */
        virtual UInt32 GetBytesPerLine(UInt32 mipLevel) const = 0;
        /**
         * @brief Get the number of bytes occupied by a single decoded mip level image.
         * @param mipLevel The mip level in the range [0 .. GetNumberOfMipLevels() - 1].
         * @return The number of bytes.
         */
        virtual UInt32 GetNumberOfBytes(UInt32 mipLevel) const = 0;

        /**
         * @brief Get the pixel format of a given plane.
         * @param planeIndex The color plane index in the range [0 .. GetNumberOfPlanes() - 1].
         * @return The pixel format of the plane.
         */
        virtual IEnums::PixelFormat GetPixelFormat(UInt32 planeIndex) const = 0;
        /**
         * @brief Get the number of bytes per pixel for a given plane.
         * This method is a convenience to get the number of bytes per pixel for a color plane
         * given by its index.
         * @param planeIndex The color plane index in the range [0 .. GetNumberOfPlanes() - 1].
         * @return The number of bytes per pixel for the given plane.
         */
        virtual UInt32 GetBytesPerPixel(UInt32 planeIndex) const = 0;
        /**
         * @brief Get the number of horizontal pixels of a given color plane.
         * @param mipLevel The mip level in the range [0 .. GetNumberOfMipLevels() - 1].
         * @param planeIndex The color plane index in the range [0 .. GetNumberOfPlanes() - 1].
         * @return The number of horizontal pixels.
         */
        virtual UInt32 GetPixelSizeX(UInt32 mipLevel, UInt32 planeIndex) const = 0;
        /**
         * @brief Get the number of vertical pixels of a given color plane.
         * @param mipLevel The mip level in the range [0 .. GetNumberOfMipLevels() - 1].
         * @param planeIndex The color plane index in the range [0 .. GetNumberOfPlanes() - 1].
         * @return The number of vertical pixels.
         */
        virtual UInt32 GetPixelSizeY(UInt32 mipLevel, UInt32 planeIndex) const = 0;
        /**
         * @brief Get the number of bytes per line of a given color plane.
         * @param mipLevel The mip level in the range [0 .. GetNumberOfMipLevels() - 1].
         * @param planeIndex The color plane index in the range [0 .. GetNumberOfPlanes() - 1].
         * @return The number of bytes per line.
         */
        virtual UInt32 GetBytesPerLine(UInt32 mipLevel, UInt32 planeIndex) const = 0;
        /**
         * @brief Get the number of bytes occupied by a single decoded mip level plane.
         * @param mipLevel The mip level in the range [0 .. GetNumberOfMipLevels() - 1].
         * @param planeIndex The color plane index in the range [0 .. GetNumberOfPlanes() - 1].
         * @return The number of bytes.
         */
        virtual UInt32 GetNumberOfBytes(UInt32 mipLevel, UInt32 planeIndex) const = 0;

        /**
         * @brief Check if the stream is ready to be decoded.
         * @return true if ready.
         */
        virtual Bool IsReadyForDecoding() const = 0;

        /**
         * @brief Start decoding the stream.
         * Has to be called before Decode().
         * @return true if successful.
         */
        virtual Bool StartDecoding() = 0;
        /**
         * @brief End decoding the stream.
         * Has to be called after Decode().
         * @return true if successful.
         */
        virtual Bool EndDecoding() = 0;
        /**
         * @brief Decode the stream.
         * StartDecoding() has to be called before, see also EndDecoding().
         * @param mipLevel The mip level in the range [0 .. GetNumberOfMipLevels() - 1].
         * @param planeIndex The color plane index in the range [0 .. GetNumberOfPlanes() - 1].
         * @param dstBuffer The destination data.
         * @param dstFormat The destination pixel format.
         * @param firstFrame The first frame to decode.
         * @param numFrames The number of frames to decode.
         * @return The number of decoded frames.
         */
        virtual UInt32 Decode(UInt32 mipLevel, UInt32 planeIndex, Data& dstBuffer, IEnums::PixelFormat dstFormat, UInt32 firstFrame, UInt32 numFrames) = 0;

        /**
         * @brief Set the stream's current access mode.
         * This serves as a hint to a possible underlying stream decoder, to be able to
         * do optimal decoding whether single frame access or a continuous sequence of
         * frames is desired.
         * This method returns true whenever the given time offset triggers the decoding
         * of a new frame.
         * @param mode The access mode to apply.
         * @return true if a new frame was triggered.
         */
        virtual Bool SetCurrentMode(IEnums::StreamMode mode) = 0;
        /**
         * @brief Get the stream's current access mode.
         * @return The current access mode.
         */
        virtual const IEnums::StreamMode GetCurrentMode() const = 0;

        /**
         * @brief Set the current time offset for subsequent PrepareDecodedData() calls.
         * This method returns true whenever the given time offset triggers the decoding
         * of a new frame.
         * @param timeOffset The time offset in seconds.
         * @return true if a new frame was triggered.
         */
        virtual Bool SetCurrentTimeOffset(Double timeOffset) = 0;
        /**
         * @brief Get the current time offset.
         * @return The time offset in seconds.
         */
        virtual Double GetCurrentTimeOffset() const = 0;

        /**
         * @brief Prepare decoded data, creating the underlying pixel storage if needed.
         * Decode a single frame at the current position, see GetDecodedData().
         * @return true if successful.
         */
        virtual Bool PrepareDecodedData() = 0;
        /**
         * @brief Finish decoded data after a call to PrepareDecodedData().
         * @return true if successful.
         */
        virtual Bool FinishDecodedData() = 0;
        /**
         * @brief Release decoded data.
         * If the stream supports re-creating its contents on its own, it may
         * free any underlying pixel storage to save memory on this call, otherwise
         * this may be a no-op.
         * @return true if successful.
         */
        virtual Bool ReleaseDecodedData() = 0;

        /**
         * @brief Get the time offset of the recently decoded data buffer.
         * @return The time offset in seconds.
         */
        virtual Double GetDecodedTimeOffset() const = 0;
        /**
         * @brief Get the index of the recently decoded buffer's frame.
         * @return The frame index.
         */
        virtual UInt64 GetDecodedFrameIndex() const = 0;
        
        /**
         * @brief Get the decoded data.
         * PrepareDecodedData() has to be called before, see also FinishDecodedData().
         * @param mipLevel The mip level in the range [0 .. GetNumberOfMipLevels() - 1].
         * @param planeIndex The color plane index in the range [0 .. GetNumberOfPlanes() - 1].
         * @return The decoded data or empty data if not supported.
         */
        virtual const ConstData& GetDecodedData(UInt32 mipLevel, UInt32 planeIndex) = 0;
        /**
         * @brief Get the decoded surface.
         * PrepareDecodedData() has to be called before, see also FinishDecodedData().
         * @param mipLevel The mip level in the range [0 .. GetNumberOfMipLevels() - 1].
         * @param planeIndex The color plane index in the range [0 .. GetNumberOfPlanes() - 1].
         * @return The decoded surface or null if not supported.
         */
        virtual const IVideoSurface* GetDecodedSurface(UInt32 mipLevel, UInt32 planeIndex) = 0;
        
        /**
         * @brief Lock the decoded data.
         * @param mipLevel The mip level in the range [0 .. GetNumberOfMipLevels() - 1].
         * @param planeIndex The color plane index in the range [0 .. GetNumberOfPlanes() - 1].
         * @return The mutable data or empty data if not supported.
         */
        virtual const MutableData& LockDecodedData(UInt32 mipLevel, UInt32 planeIndex) = 0;
        /**
         * @brief Lock the decoded surface.
         * @param mipLevel The mip level in the range [0 .. GetNumberOfMipLevels() - 1].
         * @param planeIndex The color plane index in the range [0 .. GetNumberOfPlanes() - 1].
         * @return The mutable surface or null if not supported.
         */
        virtual IVideoSurface* LockDecodedSurface(UInt32 mipLevel, UInt32 planeIndex) = 0;
        /**
         * @brief Unlock the decoded data.
         * @param mipLevel The mip level in the range [0 .. GetNumberOfMipLevels() - 1].
         * @param planeIndex The color plane index in the range [0 .. GetNumberOfPlanes() - 1].
         * @return true if successful.
         */
        virtual Bool UnlockDecodedData(UInt32 mipLevel, UInt32 planeIndex) = 0;
        /**
         * @brief Unlock the decoded surface.
         * @param mipLevel The mip level in the range [0 .. GetNumberOfMipLevels() - 1].
         * @param planeIndex The color plane index in the range [0 .. GetNumberOfPlanes() - 1].
         * @return true if successful.
         */
        virtual Bool UnlockDecodedSurface(UInt32 mipLevel, UInt32 planeIndex) = 0;
    };
}

#endif  // __MURL_I_VIDEO_STREAM_H__
