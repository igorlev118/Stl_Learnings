// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_SYSTEM_OPENAL_H__
#define __MURL_SYSTEM_OPENAL_H__

#include "murl_types.h"

namespace Murl
{
    namespace System
    {
        namespace OpenAl
        {
            // Startup/Shutdown code
            Bool Init(Bool enableChecks);
            Bool DeInit();
            
            // AL API functions
            void Enable(SInt32 capability);
            void Disable(SInt32 capability);
            UInt8 IsEnabled(SInt32 capability);

            // State retrieval
            const char* GetString(SInt32 param);
            void GetBooleanv(SInt32 param, UInt8* data);
            void GetIntegerv(SInt32 param, SInt32* data);
            void GetFloatv(SInt32 param, Float* data);
            void GetDoublev(SInt32 param, Double* data);
            UInt8 GetBoolean(SInt32 param);
            SInt32 GetInteger(SInt32 param);
            Float GetFloat(SInt32 param);
            Double GetDouble(SInt32 param);

            // Error support.
            SInt32 GetError(void);

            // Extension support.
            UInt8 IsExtensionPresent(const char* extname);
            void* GetProcAddress(const char* fname);
            SInt32 GetEnumValue(const char* ename);

            // Set Listener parameters
            void Listenerf(SInt32 param, Float value);
            void Listener3f(SInt32 param, Float value1, Float value2, Float value3);
            void Listenerfv(SInt32 param, const Float* values);
            void Listeneri(SInt32 param, SInt32 value);
            void Listener3i(SInt32 param, SInt32 value1, SInt32 value2, SInt32 value3);
            void Listeneriv(SInt32 param, const SInt32* values);

            // Get Listener parameters
            void GetListenerf(SInt32 param, Float* value);
            void GetListener3f(SInt32 param, Float *value1, Float *value2, Float *value3);
            void GetListenerfv(SInt32 param, Float* values);
            void GetListeneri(SInt32 param, SInt32* value);
            void GetListener3i(SInt32 param, SInt32 *value1, SInt32 *value2, SInt32 *value3);
            void GetListeneriv(SInt32 param, SInt32* values);

            // Source objects
            void GenSources(SInt32 n, UInt32* sources);
            void DeleteSources(SInt32 n, const UInt32* sources);
            UInt8 IsSource(UInt32 sid);

            // Set Source parameters
            void Sourcef(UInt32 sid, SInt32 param, Float value);
            void Source3f(UInt32 sid, SInt32 param, Float value1, Float value2, Float value3);
            void Sourcefv(UInt32 sid, SInt32 param, const Float* values);
            void Sourcei(UInt32 sid, SInt32 param, SInt32 value);
            void Source3i(UInt32 sid, SInt32 param, SInt32 value1, SInt32 value2, SInt32 value3);
            void Sourceiv(UInt32 sid, SInt32 param, const SInt32* values);

            // Get Source parameters
            void GetSourcef(UInt32 sid, SInt32 param, Float* value);
            void GetSource3f(UInt32 sid, SInt32 param, Float* value1, Float* value2, Float* value3);
            void GetSourcefv(UInt32 sid, SInt32 param, Float* values);
            void GetSourcei(UInt32 sid,  SInt32 param, SInt32* value);
            void GetSource3i(UInt32 sid, SInt32 param, SInt32* value1, SInt32* value2, SInt32* value3);
            void GetSourceiv(UInt32 sid,  SInt32 param, SInt32* values);

            // Source vector based playback calls
            void SourcePlayv(SInt32 ns, const UInt32 *sids);
            void SourceStopv(SInt32 ns, const UInt32 *sids);
            void SourceRewindv(SInt32 ns, const UInt32 *sids);
            void SourcePausev(SInt32 ns, const UInt32 *sids);

            // Source based playback calls
            void SourcePlay(UInt32 sid);
            void SourceStop(UInt32 sid);
            void SourceRewind(UInt32 sid);
            void SourcePause(UInt32 sid);

            // Source Queuing
            void SourceQueueBuffers(UInt32 sid, SInt32 numEntries, const UInt32 *bids);
            void SourceUnqueueBuffers(UInt32 sid, SInt32 numEntries, UInt32 *bids);

            // Buffer objects
            void GenBuffers(SInt32 n, UInt32* buffers);
            void DeleteBuffers(SInt32 n, const UInt32* buffers);
            UInt8 IsBuffer(UInt32 bid);
            void BufferData(UInt32 bid, SInt32 format, const void* data, SInt32 size, SInt32 freq);

            // Set Buffer parameters
            void Bufferf(UInt32 bid, SInt32 param, Float value);
            void Buffer3f(UInt32 bid, SInt32 param, Float value1, Float value2, Float value3);
            void Bufferfv(UInt32 bid, SInt32 param, const Float* values);
            void Bufferi(UInt32 bid, SInt32 param, SInt32 value);
            void Buffer3i(UInt32 bid, SInt32 param, SInt32 value1, SInt32 value2, SInt32 value3);
            void Bufferiv(UInt32 bid, SInt32 param, const SInt32* values);

            // Get Buffer parameters
            void GetBufferf(UInt32 bid, SInt32 param, Float* value);
            void GetBuffer3f(UInt32 bid, SInt32 param, Float* value1, Float* value2, Float* value3);
            void GetBufferfv(UInt32 bid, SInt32 param, Float* values);
            void GetBufferi(UInt32 bid, SInt32 param, SInt32* value);
            void GetBuffer3i(UInt32 bid, SInt32 param, SInt32* value1, SInt32* value2, SInt32* value3);
            void GetBufferiv(UInt32 bid, SInt32 param, SInt32* values);

            // Global Parameters
            void DopplerFactor(Float value);
            void DopplerVelocity(Float value);
            void SpeedOfSound(Float value);
            void DistanceModel(SInt32 distanceModel);

            // Constants
            enum
            {
                /* Misc */
                INVALID                                = -1,
                NONE                                   = 0,
                FALSE                                  = 0,
                TRUE                                   = 1,

                SOURCE_RELATIVE                        = 0x202,

                CONE_INNER_ANGLE                       = 0x1001,
                CONE_OUTER_ANGLE                       = 0x1002,
                PITCH                                  = 0x1003,
                POSITION                               = 0x1004,
                DIRECTION                              = 0x1005,
                VELOCITY                               = 0x1006,
                LOOPING                                = 0x1007,
                BUFFER                                 = 0x1009,
                GAIN                                   = 0x100A,
                MIN_GAIN                               = 0x100D,
                MAX_GAIN                               = 0x100E,
                ORIENTATION                            = 0x100F,
                CHANNEL_MASK                           = 0x3000,

                /* Source state information */
                SOURCE_STATE                           = 0x1010,
                INITIAL                                = 0x1011,
                PLAYING                                = 0x1012,
                PAUSED                                 = 0x1013,
                STOPPED                                = 0x1014,

                /* Buffer Queue params */
                BUFFERS_QUEUED                         = 0x1015,
                BUFFERS_PROCESSED                      = 0x1016,

                /* Source buffer position information */
                SEC_OFFSET                             = 0x1024,
                SAMPLE_OFFSET                          = 0x1025,
                BYTE_OFFSET                            = 0x1026,

                /* Source type (Static, Streaming or undetermined) */
                SOURCE_TYPE                            = 0x1027,
                STATIC                                 = 0x1028,
                STREAMING                              = 0x1029,
                UNDETERMINED                           = 0x1030,

                /* Sound samples: format specifier. */
                FORMAT_MONO8                           = 0x1100,
                FORMAT_MONO16                          = 0x1101,
                FORMAT_STEREO8                         = 0x1102,
                FORMAT_STEREO16                        = 0x1103,

                REFERENCE_DISTANCE                     = 0x1020,
                ROLLOFF_FACTOR                         = 0x1021,
                CONE_OUTER_GAIN                        = 0x1022,
                MAX_DISTANCE                           = 0x1023,

                /* Sound samples: frequency, in units of Hertz [Hz]. */
                FREQUENCY                              = 0x2001,
                BITS                                   = 0x2002,
                CHANNELS                               = 0x2003,
                SIZE                                   = 0x2004,

                /* Buffer state. */
                UNUSED                                 = 0x2010,
                PENDING                                = 0x2011,
                PROCESSED                              = 0x2012,

                /* Errors */
                NO_ERROR                               = FALSE,
                INVALID_NAME                           = 0xA001,
                ILLEGAL_ENUM                           = 0xA002,
                INVALID_ENUM                           = 0xA002,
                INVALID_VALUE                          = 0xA003,
                ILLEGAL_COMMAND                        = 0xA004,
                INVALID_OPERATION                      = 0xA004,
                OUT_OF_MEMORY                          = 0xA005,

                /* Context strings: Vendor Name. */
                VENDOR                                 = 0xB001,
                VERSION                                = 0xB002,
                RENDERER                               = 0xB003,
                EXTENSIONS                             = 0xB004,

                /* Global tweakage. */
                DOPPLER_FACTOR                         = 0xC000,
                DOPPLER_VELOCITY                       = 0xC001,
                SPEED_OF_SOUND                         = 0xC003,

                /* Distance models */
                DISTANCE_MODEL                         = 0xD000,
                INVERSE_DISTANCE                       = 0xD001,
                INVERSE_DISTANCE_CLAMPED               = 0xD002,
                LINEAR_DISTANCE                        = 0xD003,
                LINEAR_DISTANCE_CLAMPED                = 0xD004,
                EXPONENT_DISTANCE                      = 0xD005,
                EXPONENT_DISTANCE_CLAMPED              = 0xD006,
            };
        }
    }
}

#endif  // __MURL_SYSTEM_OPENAL_H__
