// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_UTIL_VIDEO_STREAM_H__
#define __MURL_UTIL_VIDEO_STREAM_H__

#include "murl_i_video_stream.h"

namespace Murl
{
    namespace Util
    {
        /**
         * @ingroup MurlUtilVideoClasses
         * @brief The video stream class, see IVideoStream.
         */
        class VideoStream : public IVideoStream
        {
        public:
            /**
             * @brief The constructor.
             * Creates a video stream with spcified pixel format and dimension.
             * @param outputFormat The pixel format of the new video object.
             * @param pixelSizeX The number of horizontal pixels.
             * @param pixelSizeY The number of vertical pixels.
             * @param mipMapGen Specifies if and how mip maps are generated.
             */
            VideoStream(IEnums::PixelFormat outputFormat, UInt32 pixelSizeX, UInt32 pixelSizeY,
                        IEnums::MipMapGenerationMode mipMapGen);

            /**
             * @brief The destructor.
             */
            virtual ~VideoStream();

            /**
             * @brief Implementation of IVideoStream::Clone().
             * @return The new video stream object.
             */
            virtual IVideoStream* Clone() const;
            /**
             * @brief Implementation of IVideoStream::Clone(IEnums::PixelFormat pixelFormat).
             * @param pixelFormat The pixel format of the new video object.
             * @return The new video stream object or null if conversion is not available.
             */
            virtual IVideoStream* Clone(IEnums::PixelFormat pixelFormat) const;
            /**
             * @brief Implementation of IVideoStream::Clone((IEnums::PixelFormat pixelFormat, UInt32 pixelSizeX, UInt32 pixelSizeY).
             * @param pixelFormat The pixel format of the new video object.
             * @param pixelSizeX The number of horizontal pixels of the new video object.
             * @param pixelSizeY The number of vertical pixels of the new video object.
             * @return The new video stream object or null if conversion is not available.
             */
            virtual IVideoStream* Clone(IEnums::PixelFormat pixelFormat, UInt32 pixelSizeX, UInt32 pixelSizeY) const;
            /**
             * @brief Implementation of IVideoStream::Clone(IEnums::PixelFormat pixelFormat, UInt32 pixelSizeX, UInt32 pixelSizeY,
             *  IEnums::MipMapGenerationMode mipMapGen).
             * @param pixelFormat The pixel format of the new video object.
             * @param pixelSizeX The number of horizontal pixels of the new video object.
             * @param pixelSizeY The number of vertical pixels of the new video object.
             * @param mipMapGen Specifies if and how mip maps are generated.
             * @return The new video stream object or null if conversion is not available.
             */
            virtual IVideoStream* Clone(IEnums::PixelFormat pixelFormat, UInt32 pixelSizeX, UInt32 pixelSizeY,
                                        IEnums::MipMapGenerationMode mipMapGen) const;

            /**
             * @brief Implementation of IVideoStream::GetNumberOfFrames().
             * @return The number of frames.
             */
            virtual UInt32 GetNumberOfFrames() const;
            /**
             * @brief Implementation of IVideoStream::GetFrameIndex().
             * @param startTime The frame start time in seconds.
             * @return The frame index.
             */
            virtual UInt32 GetFrameIndex(Double startTime) const;
            /**
             * @brief Implementation of IVideoStream::GetStartTime().
             * @param frameIndex The index of the frame to query.
             * @return The frame's start time.
             */
            virtual Double GetStartTime(UInt32 frameIndex) const;

            /**
             * @brief Implementation of IVideoStream::GetFrameRate().
             * @return The number of frames per second.
             */
            virtual Double GetFrameRate() const;
            /**
             * @brief Implementation of IVideoStream::GetFrameDuration().
             * @return The frame duration in seconds.
             */
            virtual Double GetFrameDuration() const;
            /**
             * @brief Implementation of IVideoStream::GetTotalDuration().
             * @return The total duration.
             */
            virtual Double GetTotalDuration() const;

            /**
             * @brief Implementation of IVideoStream::GetNumberOfMipLevels().
             * @return The number of mip levels.
             */
            virtual UInt32 GetNumberOfMipLevels() const;
            /**
             * @brief Implementation of IVideoStream::GetNumberOfPlanes().
             * @return The number of color planes.
             */
            virtual UInt32 GetNumberOfPlanes() const;

            /**
             * @brief Implementation of IVideoStream::GetPixelFormat().
             * @return The pixel format of the stream.
             */
            virtual IEnums::PixelFormat GetPixelFormat() const;
            /**
             * @brief Implementation of IVideoStream::GetBytesPerPixel().
             * @return The number of bytes per pixel for the stream format.
             */
            virtual UInt32 GetBytesPerPixel() const;
            /**
             * @brief Implementation of IVideoStream::GetPixelSizeX(UInt32 mipLevel).
             * @param mipLevel The mip level in the range [0 .. GetNumberOfMipLevels() - 1].
             * @return The number of horizontal pixels.
             */
            virtual UInt32 GetPixelSizeX(UInt32 mipLevel) const;
            /**
             * @brief Implementation of IVideoStream::GetPixelSizeY(UInt32 mipLevel).
             * @param mipLevel The mip level in the range [0 .. GetNumberOfMipLevels() - 1].
             * @return The number of vertical pixels.
             */
            virtual UInt32 GetPixelSizeY(UInt32 mipLevel) const;
            /**
             * @brief Implementation of IVideoStream::GetBytesPerLine(UInt32 mipLevel).
             * @param mipLevel The mip level in the range [0 .. GetNumberOfMipLevels() - 1].
             * @return The number of bytes per line.
             */
            virtual UInt32 GetBytesPerLine(UInt32 mipLevel) const;
            /**
             * @brief Implementation of IVideoStream::GetNumberOfBytes(UInt32 mipLevel).
             * @param mipLevel The mip level in the range [0 .. GetNumberOfMipLevels() - 1].
             * @return The number of bytes.
             */
            virtual UInt32 GetNumberOfBytes(UInt32 mipLevel) const;

            /**
             * @brief Implementation of IVideoStream::GetPixelFormat(UInt32 planeIndex).
             * @param planeIndex The color plane index in the range [0 .. GetNumberOfPlanes() - 1].
             * @return The pixel format of the plane.
             */
            virtual IEnums::PixelFormat GetPixelFormat(UInt32 planeIndex) const;
            /**
             * @brief Implementation of IVideoStream::GetBytesPerPixel(UInt32 planeIndex).
             * @param planeIndex The color plane index in the range [0 .. GetNumberOfPlanes() - 1].
             * @return The number of bytes per pixel for the given plane.
             */
            virtual UInt32 GetBytesPerPixel(UInt32 planeIndex) const;
            /**
             * @brief Implementation of IVideoStream::GetPixelSizeX(UInt32 mipLevel, UInt32 planeIndex).
             * @param mipLevel The mip level in the range [0 .. GetNumberOfMipLevels() - 1].
             * @param planeIndex The color plane index in the range [0 .. GetNumberOfPlanes() - 1].
             * @return The number of horizontal pixels.
             */
            virtual UInt32 GetPixelSizeX(UInt32 mipLevel, UInt32 planeIndex) const;
            /**
             * @brief Implementation of IVideoStream::GetPixelSizeY(UInt32 mipLevel, UInt32 planeIndex).
             * @param mipLevel The mip level in the range [0 .. GetNumberOfMipLevels() - 1].
             * @param planeIndex The color plane index in the range [0 .. GetNumberOfPlanes() - 1].
             * @return The number of vertical pixels.
             */
            virtual UInt32 GetPixelSizeY(UInt32 mipLevel, UInt32 planeIndex) const;
            /**
             * @brief Implementation of IVideoStream::GetBytesPerLine(UInt32 mipLevel, UInt32 planeIndex).
             * @param mipLevel The mip level in the range [0 .. GetNumberOfMipLevels() - 1].
             * @param planeIndex The color plane index in the range [0 .. GetNumberOfPlanes() - 1].
             * @return The number of bytes per line.
             */
            virtual UInt32 GetBytesPerLine(UInt32 mipLevel, UInt32 planeIndex) const;
            /**
             * @brief Implementation of IVideoStream::GetNumberOfBytes(UInt32 mipLevel, UInt32 planeIndex).
             * @param mipLevel The mip level in the range [0 .. GetNumberOfMipLevels() - 1].
             * @param planeIndex The color plane index in the range [0 .. GetNumberOfPlanes() - 1].
             * @return The number of bytes.
             */
            virtual UInt32 GetNumberOfBytes(UInt32 mipLevel, UInt32 planeIndex) const;

            /**
             * @brief Implementation of IVideoStream::IsReadyForDecoding().
             * @return true if ready.
             */
            virtual Bool IsReadyForDecoding() const;

            /**
             * @brief Implementation of IVideoStream::StartDecoding().
             * @return true if successful.
             */
            virtual Bool StartDecoding();
            /**
             * @brief Implementation of IVideoStream::EndDecoding().
             * @return true if successful.
             */
            virtual Bool EndDecoding();
            /**
             * @brief Implementation of IVideoStream::Decode().
             * @param mipLevel The mip level in the range [0 .. GetNumberOfMipLevels() - 1].
             * @param planeIndex The color plane index in the range [0 .. GetNumberOfPlanes() - 1].
             * @param dstBuffer The destination data.
             * @param dstFormat The destination pixel format.
             * @param firstFrame The first frame to decode.
             * @param numFrames The number of frames to decode.
             * @return The number of decoded frames.
             */
            virtual UInt32 Decode(UInt32 mipLevel, UInt32 planeIndex, Data& dstBuffer, IEnums::PixelFormat dstFormat,
                                  UInt32 firstFrame, UInt32 numFrames);

            /**
             * @brief Implementation of IVideoStream::SetCurrentMode().
             * @param mode The access mode to apply.
             * @return true if a new frame was triggered.
             */
            virtual Bool SetCurrentMode(IEnums::StreamMode mode);
            /**
             * @brief Implementation of IVideoStream::GetCurrentMode().
             * @return The current access mode.
             */
            virtual const IEnums::StreamMode GetCurrentMode() const;

            /**
             * @brief Implementation of IVideoStream::SetCurrentTimeOffset().
             * @param timeOffset The time offset in seconds.
             * @return true if a new frame was triggered.
             */
            virtual Bool SetCurrentTimeOffset(Double timeOffset);
            /**
             * @brief Implementation of IVideoStream::GetCurrentTimeOffset().
             * @return The time offset in seconds.
             */
            virtual Double GetCurrentTimeOffset() const;

            /**
             * @brief Implementation of IVideoStream::PrepareDecodedData().
             * @return true if successful.
             */
            virtual Bool PrepareDecodedData();
            /**
             * @brief Implementation of IVideoStream::FinishDecodedData().
             * @return true if successful.
             */
            virtual Bool FinishDecodedData();
            /**
             * @brief Implementation of IVideoStream::ReleaseDecodedData().
             * @return true if successful.
             */
            virtual Bool ReleaseDecodedData();

            /**
             * @brief Implementation of IVideoStream::GetDecodedTimeOffset().
             * @return The time offset in seconds.
             */
            virtual Double GetDecodedTimeOffset() const;
            /**
             * @brief Implementation of IVideoStream::GetDecodedFrameIndex().
             * @return The frame index.
             */
            virtual UInt64 GetDecodedFrameIndex() const;

            /**
             * @brief Implementation of IVideoStream::GetDecodedData().
             * @param mipLevel The mip level in the range [0 .. GetNumberOfMipLevels() - 1].
             * @param planeIndex The color plane index in the range [0 .. GetNumberOfPlanes() - 1].
             * @return The decoded data or empty data if not supported.
             */
            virtual const ConstData& GetDecodedData(UInt32 mipLevel, UInt32 planeIndex);
            /**
             * @brief Implementation of IVideoStream::GetDecodedSurface().
             * @param mipLevel The mip level in the range [0 .. GetNumberOfMipLevels() - 1].
             * @param planeIndex The color plane index in the range [0 .. GetNumberOfPlanes() - 1].
             * @return The decoded surface or null if not supported.
             */
            virtual const IVideoSurface* GetDecodedSurface(UInt32 mipLevel, UInt32 planeIndex);

            /**
             * @brief Implementation of IVideoStream::LockDecodedData().
             * @param mipLevel The mip level in the range [0 .. GetNumberOfMipLevels() - 1].
             * @param planeIndex The color plane index in the range [0 .. GetNumberOfPlanes() - 1].
             * @return The mutable data or empty data if not supported.
             */
            virtual const MutableData& LockDecodedData(UInt32 mipLevel, UInt32 planeIndex);
            /**
             * @brief Implementation of IVideoStream::LockDecodedSurface().
             * @param mipLevel The mip level in the range [0 .. GetNumberOfMipLevels() - 1].
             * @param planeIndex The color plane index in the range [0 .. GetNumberOfPlanes() - 1].
             * @return The mutable surface or null if not supported.
             */
            virtual IVideoSurface* LockDecodedSurface(UInt32 mipLevel, UInt32 planeIndex);
            /**
             * @brief Implementation of IVideoStream::UnlockDecodedData().
             * @param mipLevel The mip level in the range [0 .. GetNumberOfMipLevels() - 1].
             * @param planeIndex The color plane index in the range [0 .. GetNumberOfPlanes() - 1].
             * @return true if successful.
             */
            virtual Bool UnlockDecodedData(UInt32 mipLevel, UInt32 planeIndex);
            /**
             * @brief Implementation of IVideoStream::UnlockDecodedSurface().
             * @param mipLevel The mip level in the range [0 .. GetNumberOfMipLevels() - 1].
             * @param planeIndex The color plane index in the range [0 .. GetNumberOfPlanes() - 1].
             * @return true if successful.
             */
            virtual Bool UnlockDecodedSurface(UInt32 mipLevel, UInt32 planeIndex);

            /**
             * @brief Set the surface.
             * @param mipLevel The mip level in the range [0 .. GetNumberOfMipLevels() - 1].
             * @param planeIndex The color plane index in the range [0 .. GetNumberOfPlanes() - 1].
             * @param surface The source video surface.
             * @param takeOwnership Take the source video surface ownershop if true.
             * @return true if successful.
             */
            virtual Bool SetSurface(UInt32 mipLevel, UInt32 planeIndex, IVideoSurface* surface, Bool takeOwnership);

        protected:
            class MipLevel
            {
            public:
                MipLevel()
                : mPixelSizeX(0)
                , mPixelSizeY(0)
                , mSurface(0)
                , mIsOwnSurface(false)
                {
                }

                ~MipLevel()
                {
                    if (mIsOwnSurface)
                    {
                        Util::Release(mSurface);
                    }
                }

                Bool HasSurface() const
                {
                    return mSurface != 0;
                }

                IVideoSurface* GetSurface() const
                {
                    return mSurface;
                }

                void SetSurface(IVideoSurface* surface, Bool owner)
                {
                    if (mIsOwnSurface)
                    {
                        Util::Release(mSurface);
                    }
                    mSurface = surface;
                    mIsOwnSurface = owner;
                }

                UInt32 mPixelSizeX;
                UInt32 mPixelSizeY;

            protected:
                IVideoSurface* mSurface;
                Bool mIsOwnSurface;
            };

            virtual IVideoStream* DeepClone(IEnums::PixelFormat pixelFormat, UInt32 pixelSizeX, UInt32 pixelSizeY,
                                            IEnums::MipMapGenerationMode mipMapGen) const;

            virtual Bool AcquireMipLevelSurfaces();
            virtual Bool AcquireMipLevelSurface(UInt32 mipLevel);

            IEnums::StreamMode mCurrentMode;
            Double mCurrentTime;

            IEnums::PixelFormat mOutputFormat;
            UInt32 mPixelSizeX;
            UInt32 mPixelSizeY;

            IEnums::MipMapGenerationMode mMipMapGenerationMode;
            UInt32 mNumberOfPlanes;
            Array<MipLevel> mMipLevels;
        };
    }
}

#endif  // __MURL_UTIL_VIDEO_STREAM_H__
