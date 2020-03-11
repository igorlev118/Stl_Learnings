// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_RESOURCE_I_ANIMATION_H__
#define __MURL_RESOURCE_I_ANIMATION_H__

#include "murl_util_iff.h"
#include "murl_i_enums.h"
#include "murl_resource_types.h"

namespace Murl
{
    namespace Resource
    {
        class IObject;

        /**
         * @ingroup MurlResourceObjectInterfaces
         * @interface IAnimation
         * @brief The IAnimation resource object interface.
         * Animation resources store a number of animation clips, which in turn can contain
         * any number of key frames of different types, such as colors, positions, audio volumes
         * etc, in an ascending order with respect to their time stamps.
         */
        class IAnimation
        {
        public:
            /// IFF file specific structs
            struct Iff
            {
                /// IFF identifiers
                enum
                {
                    /// The four character code identifying a native resource as an animation.
                    FOURCC = 'ANIM',
                    /// The version of a native resource supported by the engine.
                    VERSION = '1.00'
                };

                /**
                 * @struct HeaderChunk
                 * @brief The IFF header chunk of a native animation resource.
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

                    /// The start time of the animation in seconds, if no explicit clips are present.
                    Float mStartTime;
                    /// The end time of the animation in seconds, if no explicit clips are present.
                    Float mEndTime;
                };

                /**
                 * @struct ClipChunk
                 * @brief The IFF clip chunk of a native animation resource.
                 * Clip chunks are optional within a file. If no clip chunk is present, the individual
                 * keys are stored at the root level of the chunk hierarchy, and the animation only
                 * consists of a single clip with start/end time taken from the header chunk.
                 * If there is at least one clip chunk present, there must not be any key chunks at
                 * the root level; instead, all key chunks belonging to a single clip can be found
                 * as sub-chunks in the data block pointed to by the clip chunk's mDataOffset member.
                 */
                struct ClipChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as a ClipChunk.
                        FOURCC = 'CLIP'
                    };

                    /// The zero-based index of the clip.
                    UInt32 mIndex;

                    /// The start time of the clip in seconds.
                    Float mStartTime;
                    /// The end time of the clip in seconds.
                    Float mEndTime;

                    /// An offset into the chunk where the clip's name is stored. See IffOffset().
                    UInt32 mNameOffset;
                    /// The size in bytes of the name string, including the terminating null character.
                    UInt32 mNameByteSize;

                    /// An offset into the chunk where the clip's key frame chunks are stored. See IffOffset().
                    UInt32 mDataOffset;
                    /// The size in bytes of the key frame chunk data.
                    UInt32 mDataByteSize;
                };

                /**
                 * @struct SingleKeysChunk
                 * @brief An IFF chunk of a native animation storing "single" (non-indexed) key types.
                 * The data pointed to by the mKeysOffset member must be interpreted as an array of
                 * structs of the type defined for the respective FourCC chunk identifier, e.g.
                 * a chunk of type FOURCC_DIFFUSE contains a data block consisting of mNumberOfKeys
                 * consecutive Raw::ColorKey structures, with the data size in bytes equalling
                 * mNumberOfKeys*sizeof(Raw::ColorKey).
                 *
                 * There can only be one chunk of a specific type for a single clip, hence the name
                 * SingleKeysChunk, e.g. it is not possible to have more than one key chunk of type
                 * FOURCC_POSITION per clip.
                 */
                struct SingleKeysChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// BoolKey chunk controlling a node's "visible" property.
                        FOURCC_VISIBLE      = 'VISK',
                        /// BoolKey chunk controlling a node's "active" property.
                        FOURCC_ACTIVE       = 'ACTK',

                        /// IntegerKey chunk representing an index.
                        FOURCC_INDEX        = 'IDXK',
                        /// IntegerKey chunk representing a depth order.
                        FOURCC_DEPTH_ORDER  = 'DPOK',

                        /// FloatKey chunk representing an alpha value.
                        FOURCC_ALPHA        = 'ALPK',
                        /// FloatKey chunk representing an audio volume.
                        FOURCC_VOLUME       = 'VOLK',
                        /// FloatKey chunk representing a time value.
                        FOURCC_TIME         = 'TIMK',

                        /// ColorKey chunk representing an ambient color.
                        FOURCC_AMBIENT      = 'AMCK',
                        /// ColorKey chunk representing a diffuse color.
                        FOURCC_DIFFUSE      = 'DFCK',
                        /// ColorKey chunk representing a specular color.
                        FOURCC_SPECULAR     = 'SPCK',
                        /// ColorKey chunk representing an emissive color.
                        FOURCC_EMISSIVE     = 'EMCK',

                        /// PositionKey chunk.
                        FOURCC_POSITION     = 'POSK',
                        /// FloatKey chunk representing an X position.
                        FOURCC_POSITION_X   = 'PSXK',
                        /// FloatKey chunk representing a Y position.
                        FOURCC_POSITION_Y   = 'PSYK',
                        /// FloatKey chunk representing a Z position.
                        FOURCC_POSITION_Z   = 'PSZK',

                        /// ScalingKey chunk.
                        FOURCC_SCALING      = 'SCLK',
                        /// FloatKey chunk representing a scale factor in X direction.
                        FOURCC_SCALING_X    = 'SCXK',
                        /// FloatKey chunk representing a scale factor in Y direction.
                        FOURCC_SCALING_Y    = 'SCYK',
                        /// FloatKey chunk representing a scale factor in Z direction.
                        FOURCC_SCALING_Z    = 'SCZK',

                        /// AxisAngleKey chunk rotation represented in axis/angle format.
                        FOURCC_AXIS_ANGLE   = 'ROTK',
                        /// QuaternionKey chunk rotation represented as a quaternion.
                        FOURCC_QUATERNION   = 'QUTK',
                        /// EulerAngleKey chunk representing euler X/Y/Z angle.
                        FOURCC_EULER_ANGLE  = 'ERTK',
                        /// FloatKey chunk representing an euler X angle.
                        FOURCC_EULER_ANGLE_X  = 'ERXK',
                        /// FloatKey chunk representing an euler Y angle.
                        FOURCC_EULER_ANGLE_Y  = 'ERYK',
                        /// FloatKey chunk representing an euler Z angle.
                        FOURCC_EULER_ANGLE_Z  = 'ERZK',
                    };

                    /// The number of keys in this chunk.
                    UInt32 mNumberOfKeys;
                    /// An offset into the chunk where the key frame data is stored. See IffOffset().
                    UInt32 mKeysOffset;
                };

                /**
                 * @struct IndexedKeysChunk
                 * @brief An IFF chunk of a native animation storing indexed key types.
                 * It is possible to have more than one IndexedKeysChunk of the same type per clip,
                 * however all of these must have a unique mIndex value.
                 * See also SingleKeysChunk.
                 */
                struct IndexedKeysChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// FloatKey chunks representing a blend factor.
                        FOURCC_BLEND_FACTOR = 'BLDF',
                    };

                    /// The key set index.
                    UInt32 mIndex;
                    /// The number of keys in this chunk.
                    UInt32 mNumberOfKeys;
                    /// An offset into the chunk where the key frame data is stored. See IffOffset().
                    UInt32 mKeysOffset;
                };

                /**
                 * @struct CubicBezierParameterSetsChunk
                 * @brief An IFF chunk of a native animation storing an array of cubic bezier curve parameter sets.
                 * If the lower 8 bits of a key's mInterpolation field represent the IEnums::INTERPOLATION_CUBIC_BEZIER
                 * enumeration value, the upper 24 bits of the same field specify the zero-based index into this
                 * array.
                 */
                struct CubicBezierParameterSetsChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as a CubicBezierParameterSetsChunk.
                        FOURCC = 'CBZP',
                    };

                    /// The number of parameter sets in this chunk.
                    UInt32 mNumberOfParameterSets;
                    /// An offset into the chunk where the parameter set data is stored. See IffOffset().
                    UInt32 mParameterSetsOffset;
                };

                /**
                 * @struct EulerRotationOrderChunk
                 * @brief An IFF chunk of a native animation storing the default Euler rotation order to use.
                 * The default Euler rotation order is only used when the actual rotation is evaluated
                 * through individual key sets for X, Y and Z rotation ('ERXK', 'ERYK' and 'ERZK' chunks).
                 * If the rotation is evaluated through a combined Euler rotation key set ('ERTK' chunk),
                 * the rotation order stored with each key is used.
                 */
                struct EulerRotationOrderChunk : public Util::IffChunk
                {
                    /// IFF identifiers
                    enum
                    {
                        /// The four character code identifying this chunk as an EulerRotationOrderChunk.
                        FOURCC = 'ERTO',
                    };

                    /// The rotation order
                    UInt32 mRotationOrder;
                };
            };

            /// Raw data structs
            struct Raw
            {
                /**
                 * @struct Key
                 * @brief A generic animation key.
                 */
                struct Key
                {
                    /// The key's time code.
                    Float mTime;
                    /// The interpolation mode. See @ref IEnums::Interpolation.
                    UInt32 mInterpolation;
                };

                /**
                 * @struct BoolKey
                 * @brief An animation key holding a single 32bit signed integer value.
                 */
                struct BoolKey : public Key
                {
                    /// 32 bit value
                    union
                    {
                        /// The boolean value.
                        Bool mValue;
                        /// Force the Bool value to 32 bits.
                        UInt32 mReserved;
                    };
                };

                /**
                 * @struct IntegerKey
                 * @brief An animation key holding a single 32bit signed integer value.
                 */
                struct IntegerKey : public Key
                {
                    /// The integer value.
                    SInt32 mValue;
                };

                /**
                 * @struct FloatKey
                 * @brief An animation key holding a single 32bit floating point value.
                 */
                struct FloatKey : public Key
                {
                    /// The floating point value.
                    Float mValue;
                };

                /**
                 * @struct ColorKey
                 * @brief An animation key holding an RGBA color value.
                 */
                struct ColorKey : public Key
                {
                    /// The floating point value for the color's red component.
                    Float mRed;
                    /// The floating point value for the color's green component.
                    Float mGreen;
                    /// The floating point value for the color's blue component.
                    Float mBlue;
                    /// The floating point value for the color's alpha component.
                    Float mAlpha;
                };

                /**
                 * @struct VectorKey
                 * @brief An animation key holding a 4-component float vector.
                 */
                struct VectorKey : public Key
                {
                    /// The floating point value for the vector's X component.
                    Float mX;
                    /// The floating point value for the vector's Y component.
                    Float mY;
                    /// The floating point value for the vector's Z component.
                    Float mZ;
                    /// The floating point value for the vector's W component.
                    Float mW;
                };

                /**
                 * @struct PositionKey
                 * @brief An animation key holding a 3-component float position vector.
                 */
                struct PositionKey : public Key
                {
                    /// The floating point value for the position's X component.
                    Float mPosX;
                    /// The floating point value for the position's Y component.
                    Float mPosY;
                    /// The floating point value for the position's Z component.
                    Float mPosZ;
                };

                /**
                 * @struct ScalingKey
                 * @brief An animation key holding a 3-component float scaling vector.
                 */
                struct ScalingKey : public Key
                {
                    /// The floating point value for the scale factor's X component.
                    Float mScaleX;
                    /// The floating point value for the scale factor's Y component.
                    Float mScaleY;
                    /// The floating point value for the scale factor's Z component.
                    Float mScaleZ;
                };

                /**
                 * @struct AxisAngleKey
                 * @brief An animation key holding an axis/angle rotation vector.
                 */
                struct AxisAngleKey : public Key
                {
                    /// The floating point value for the rotation axis' X component.
                    Float mAxisX;
                    /// The floating point value for the rotation axis' Y component.
                    Float mAxisY;
                    /// The floating point value for the rotation axis' Z component.
                    Float mAxisZ;
                    /// The floating point value for the rotation angle.
                    Float mAngle;
                };

                /**
                 * @struct QuaternionKey
                 * @brief An animation key holding a rotation quaternion.
                 */
                struct QuaternionKey : public Key
                {
                    /// The floating point value for the quaternion's R.
                    Float mQuatR;
                    /// The floating point value for the quaternion's I component.
                    Float mQuatI;
                    /// The floating point value for the quaternion's J component.
                    Float mQuatJ;
                    /// The floating point value for the quaternion's K component.
                    Float mQuatK;
                };

                /**
                 * @struct EulerAngleKey
                 * @brief An animation key holding euler X/Y/Z rotation angles.
                 */
                struct EulerAngleKey : public Key
                {
                    /// The floating point value for the X rotation angle.
                    Float mAngleX;
                    /// The floating point value for the Y rotation angle.
                    Float mAngleY;
                    /// The floating point value for the Z rotation angle.
                    Float mAngleZ;
                    // The axis rotation order IEnum::RotationOrder.
                    SInt32 mRotationOrder;
                };

                /**
                 * @struct CubicBezierParameterSet
                 * @brief A set of cubic bezier parameters.
                 * Together with two successive FloatKey entries acting as the starting and ending
                 * point, this set of parameters defines a cubic bezier curve segment made up of
                 * four control points (t0,v0), (t1,v1), (t2,v2) and (t3,v3).
                 * With the start key's time stamp and value as (t0,v0) (first control point) and
                 * the end key's time stamp and value as (t3,v3) (fourth control point), the second
                 * control point is calculated as t1=t0+mStartWeight*(t3-t0) and v1=v0+mStartDelta,
                 * and the third one as t2=t3+mEndWeight*(t3-t0) and v2=v3+mEndDelta.
                 */
                struct CubicBezierParameterSet
                {
                    /// The start weight.
                    Float mStartWeight;
                    /// The start value delta.
                    Float mStartDelta;
                    /// The end weight.
                    Float mEndWeight;
                    /// The end value delta.
                    Float mEndDelta;
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
             * @brief Get the rotation order for evaluating Euler angles.
             * @return The Euler rotation order.
             */
            virtual IEnums::RotationOrder GetEulerRotationOrder() const = 0;

            /**
             * @brief Check if this animation contains keys of a given type.
             * @param keyType The animation key type to query.
             * @return true if keys of the requested type are present.
             */
            virtual Bool HasKeys(IEnums::AnimationKey keyType) const = 0;
            /**
             * @brief Get the bit mask of animation key types present in this animation.
             * @return A bit mask of IEnums::AnimationKey values.
             */
            virtual UInt32 GetPresentKeys() const = 0;

            /**
             * @brief Get the number of clips stored in the animation.
             * @return The total number of clips.
             */
            virtual UInt32 GetNumberOfClips() const = 0;
            /**
             * @brief Get the index of a clip with a given name.
             * @param clipName The name of the clip to query.
             * @return The zero-based index of the clip, or -1 if not found.
             */
            virtual SInt32 GetClipIndex(const Char* clipName) const = 0;
            /**
             * @brief Get the name of a clip at a given index.
             * @param clipIndex The zero-based index of the clip, in the range from
             *      0 to GetNumberOfClips()-1.
             * @return The name of the clip, or null if the index was out of range.
             */
            virtual const Char* GetClipName(UInt32 clipIndex) const = 0;

            /**
             * @brief Get a clip's start time.
             * @param clipIndex The zero-based index of the clip, in the range from
             *      0 to GetNumberOfClips()-1.
             * @return The start time in seconds, or 0.0 if the index was out of range.
             */
            virtual Float GetStartTime(UInt32 clipIndex) const = 0;
            /**
             * @brief Get a clip's end time.
             * @param clipIndex The zero-based index of the clip, in the range from
             *      0 to GetNumberOfClips()-1.
             * @return The end time in seconds, or 0.0 if the index was out of range.
             */
            virtual Float GetEndTime(UInt32 clipIndex) const = 0;
            /**
             * @brief Get a clip's duration.
             * @param clipIndex The zero-based index of the clip, in the range from
             *      0 to GetNumberOfClips()-1.
             * @return The duration in seconds, or 0.0 if the index was out of range.
             */
            virtual Float GetDuration(UInt32 clipIndex) const = 0;

            /**
             * @brief Get the number of "visible" keys stored in a clip.
             * @param clipIndex The clip index.
             * @return The number of keys.
             */
            virtual UInt32 GetNumberOfVisibleKeys(UInt32 clipIndex) const = 0;
            /**
             * @brief Get the number of "active" keys stored in a clip.
             * @param clipIndex The clip index.
             * @return The number of keys.
             */
            virtual UInt32 GetNumberOfActiveKeys(UInt32 clipIndex) const = 0;
            /**
             * @brief Get the "visible" keys stored in a clip.
             * @param clipIndex The clip index.
             * @return A pointer to the keys, or null if not present.
             */
            virtual const Raw::BoolKey* GetVisibleKeys(UInt32 clipIndex) const = 0;
            /**
             * @brief Get the "active" keys stored in a clip.
             * @param clipIndex The clip index.
             * @return A pointer to the keys, or null if not present.
             */
            virtual const Raw::BoolKey* GetActiveKeys(UInt32 clipIndex) const = 0;

            /**
             * @brief Get the number of index keys stored in a clip.
             * @param clipIndex The clip index.
             * @return The number of keys.
             */
            virtual UInt32 GetNumberOfIndexKeys(UInt32 clipIndex) const = 0;
            /**
             * @brief Get the number of depth order keys stored in a clip.
             * @param clipIndex The clip index.
             * @return The number of keys.
             */
            virtual UInt32 GetNumberOfDepthOrderKeys(UInt32 clipIndex) const = 0;
            /**
             * @brief Get the index keys stored in a clip.
             * @param clipIndex The clip index.
             * @return A pointer to the keys, or null if not present.
             */
            virtual const Raw::IntegerKey* GetIndexKeys(UInt32 clipIndex) const = 0;
            /**
             * @brief Get the depth order keys stored in a clip.
             * @param clipIndex The clip index.
             * @return A pointer to the keys, or null if not present.
             */
            virtual const Raw::IntegerKey* GetDepthOrderKeys(UInt32 clipIndex) const = 0;

            /**
             * @brief Get the number of alpha keys stored in a clip.
             * @param clipIndex The clip index.
             * @return The number of keys.
             */
            virtual UInt32 GetNumberOfAlphaKeys(UInt32 clipIndex) const = 0;
            /**
             * @brief Get the number of audio volume keys stored in a clip.
             * @param clipIndex The clip index.
             * @return The number of keys.
             */
            virtual UInt32 GetNumberOfVolumeKeys(UInt32 clipIndex) const = 0;
            /**
             * @brief Get the number of time keys stored in a clip.
             * @param clipIndex The clip index.
             * @return The number of keys.
             */
            virtual UInt32 GetNumberOfTimeKeys(UInt32 clipIndex) const = 0;
            /**
             * @brief Get the alpha keys stored in a clip.
             * @param clipIndex The clip index.
             * @return A pointer to the keys, or null if not present.
             */
            virtual const Raw::FloatKey* GetAlphaKeys(UInt32 clipIndex) const = 0;
            /**
             * @brief Get the audio volume keys stored in a clip.
             * @param clipIndex The clip index.
             * @return A pointer to the keys, or null if not present.
             */
            virtual const Raw::FloatKey* GetVolumeKeys(UInt32 clipIndex) const = 0;
            /**
             * @brief Get the time keys stored in a clip.
             * @param clipIndex The clip index.
             * @return A pointer to the keys, or null if not present.
             */
            virtual const Raw::FloatKey* GetTimeKeys(UInt32 clipIndex) const = 0;

            /**
             * @brief Get the number of ambient color keys stored in a clip.
             * @param clipIndex The clip index.
             * @return The number of keys.
             */
            virtual UInt32 GetNumberOfAmbientColorKeys(UInt32 clipIndex) const = 0;
            /**
             * @brief Get the number of diffuse color keys stored in a clip.
             * @param clipIndex The clip index.
             * @return The number of keys.
             */
            virtual UInt32 GetNumberOfDiffuseColorKeys(UInt32 clipIndex) const = 0;
            /**
             * @brief Get the number of specular color keys stored in a clip.
             * @param clipIndex The clip index.
             * @return The number of keys.
             */
            virtual UInt32 GetNumberOfSpecularColorKeys(UInt32 clipIndex) const = 0;
            /**
             * @brief Get the number of emissive color keys stored in a clip.
             * @param clipIndex The clip index.
             * @return The number of keys.
             */
            virtual UInt32 GetNumberOfEmissiveColorKeys(UInt32 clipIndex) const = 0;
            /**
             * @brief Get the ambient color keys stored in a clip.
             * @param clipIndex The clip index.
             * @return A pointer to the keys, or null if not present.
             */
            virtual const Raw::ColorKey* GetAmbientColorKeys(UInt32 clipIndex) const = 0;
            /**
             * @brief Get the diffuse color keys stored in a clip.
             * @param clipIndex The clip index.
             * @return A pointer to the keys, or null if not present.
             */
            virtual const Raw::ColorKey* GetDiffuseColorKeys(UInt32 clipIndex) const = 0;
            /**
             * @brief Get the specular color keys stored in a clip.
             * @param clipIndex The clip index.
             * @return A pointer to the keys, or null if not present.
             */
            virtual const Raw::ColorKey* GetSpecularColorKeys(UInt32 clipIndex) const = 0;
            /**
             * @brief Get the emissive color keys stored in a clip.
             * @param clipIndex The clip index.
             * @return A pointer to the keys, or null if not present.
             */
            virtual const Raw::ColorKey* GetEmissiveColorKeys(UInt32 clipIndex) const = 0;

            /**
             * @brief Get the number of position keys stored in a clip.
             * @param clipIndex The clip index.
             * @return The number of keys.
             */
            virtual UInt32 GetNumberOfPositionKeys(UInt32 clipIndex) const = 0;
            /**
             * @brief Get the number of position X keys stored in a clip.
             * @param clipIndex The clip index.
             * @return The number of keys.
             */
            virtual UInt32 GetNumberOfPositionXKeys(UInt32 clipIndex) const = 0;
            /**
             * @brief Get the number of position Y keys stored in a clip.
             * @param clipIndex The clip index.
             * @return The number of keys.
             */
            virtual UInt32 GetNumberOfPositionYKeys(UInt32 clipIndex) const = 0;
            /**
             * @brief Get the number of position Z keys stored in a clip.
             * @param clipIndex The clip index.
             * @return The number of keys.
             */
            virtual UInt32 GetNumberOfPositionZKeys(UInt32 clipIndex) const = 0;
            /**
             * @brief Get the number of scaling keys stored in a clip.
             * @param clipIndex The clip index.
             * @return The number of keys.
             */
            virtual UInt32 GetNumberOfScalingKeys(UInt32 clipIndex) const = 0;
            /**
             * @brief Get the number of scaling X keys stored in a clip.
             * @param clipIndex The clip index.
             * @return The number of keys.
             */
            virtual UInt32 GetNumberOfScalingXKeys(UInt32 clipIndex) const = 0;
            /**
             * @brief Get the number of scaling Y keys stored in a clip.
             * @param clipIndex The clip index.
             * @return The number of keys.
             */
            virtual UInt32 GetNumberOfScalingYKeys(UInt32 clipIndex) const = 0;
            /**
             * @brief Get the number of scaling Z keys stored in a clip.
             * @param clipIndex The clip index.
             * @return The number of keys.
             */
            virtual UInt32 GetNumberOfScalingZKeys(UInt32 clipIndex) const = 0;
            /**
             * @brief Get the number of euler X/Y/Z rotation angle keys stored in a clip.
             * @param clipIndex The clip index.
             * @return The number of keys.
             */
            virtual UInt32 GetNumberOfEulerAngleKeys(UInt32 clipIndex) const = 0;
            /**
             * @brief Get the number of euler X rotation angle keys stored in a clip.
             * @param clipIndex The clip index.
             * @return The number of keys.
             */
            virtual UInt32 GetNumberOfEulerAngleXKeys(UInt32 clipIndex) const = 0;
            /**
             * @brief Get the number of euler Y rotation angle keys stored in a clip.
             * @param clipIndex The clip index.
             * @return The number of keys.
             */
            virtual UInt32 GetNumberOfEulerAngleYKeys(UInt32 clipIndex) const = 0;
            /**
             * @brief Get the number of euler Z rotation angle keys stored in a clip.
             * @param clipIndex The clip index.
             * @return The number of keys.
             */
            virtual UInt32 GetNumberOfEulerAngleZKeys(UInt32 clipIndex) const = 0;
            /**
             * @brief Get the number of axis/angle keys stored in a clip.
             * @param clipIndex The clip index.
             * @return The number of keys.
             */
            virtual UInt32 GetNumberOfAxisAngleKeys(UInt32 clipIndex) const = 0;
            /**
             * @brief Get the number of quaternion keys stored in a clip.
             * @param clipIndex The clip index.
             * @return The number of keys.
             */
            virtual UInt32 GetNumberOfQuaternionKeys(UInt32 clipIndex) const = 0;
            /**
             * @brief Get the position keys stored in a clip.
             * @param clipIndex The clip index.
             * @return A pointer to the keys, or null if not present.
             */
            virtual const Raw::PositionKey* GetPositionKeys(UInt32 clipIndex) const = 0;
            /**
             * @brief Get the position X keys stored in a clip.
             * @param clipIndex The clip index.
             * @return A pointer to the keys, or null if not present.
             */
            virtual const Raw::FloatKey* GetPositionXKeys(UInt32 clipIndex) const = 0;
            /**
             * @brief Get the position Y keys stored in a clip.
             * @param clipIndex The clip index.
             * @return A pointer to the keys, or null if not present.
             */
            virtual const Raw::FloatKey* GetPositionYKeys(UInt32 clipIndex) const = 0;
            /**
             * @brief Get the position Z keys stored in a clip.
             * @param clipIndex The clip index.
             * @return A pointer to the keys, or null if not present.
             */
            virtual const Raw::FloatKey* GetPositionZKeys(UInt32 clipIndex) const = 0;
            /**
             * @brief Get the scaling keys stored in a clip.
             * @param clipIndex The clip index.
             * @return A pointer to the keys, or null if not present.
             */
            virtual const Raw::ScalingKey* GetScalingKeys(UInt32 clipIndex) const = 0;
            /**
             * @brief Get the scaling X keys stored in a clip.
             * @param clipIndex The clip index.
             * @return A pointer to the keys, or null if not present.
             */
            virtual const Raw::FloatKey* GetScalingXKeys(UInt32 clipIndex) const = 0;
            /**
             * @brief Get the scaling Y keys stored in a clip.
             * @param clipIndex The clip index.
             * @return A pointer to the keys, or null if not present.
             */
            virtual const Raw::FloatKey* GetScalingYKeys(UInt32 clipIndex) const = 0;
            /**
             * @brief Get the scaling Z keys stored in a clip.
             * @param clipIndex The clip index.
             * @return A pointer to the keys, or null if not present.
             */
            virtual const Raw::FloatKey* GetScalingZKeys(UInt32 clipIndex) const = 0;
            /**
             * @brief Get the euler X/Y/Z rotation angle keys stored in a clip.
             * @param clipIndex The clip index.
             * @return A pointer to the keys, or null if not present.
             */
            virtual const Raw::EulerAngleKey* GetEulerAngleKeys(UInt32 clipIndex) const = 0;
            /**
             * @brief Get the euler X rotation angle keys stored in a clip.
             * @param clipIndex The clip index.
             * @return A pointer to the keys, or null if not present.
             */
            virtual const Raw::FloatKey* GetEulerAngleXKeys(UInt32 clipIndex) const = 0;
            /**
             * @brief Get the euler Y rotation angle keys stored in a clip.
             * @param clipIndex The clip index.
             * @return A pointer to the keys, or null if not present.
             */
            virtual const Raw::FloatKey* GetEulerAngleYKeys(UInt32 clipIndex) const = 0;
            /**
             * @brief Get the euler Z rotation angle keys stored in a clip.
             * @param clipIndex The clip index.
             * @return A pointer to the keys, or null if not present.
             */
            virtual const Raw::FloatKey* GetEulerAngleZKeys(UInt32 clipIndex) const = 0;
            /**
             * @brief Get the axis/angle keys stored in a clip.
             * @param clipIndex The clip index.
             * @return A pointer to the keys, or null if not present.
             */
            virtual const Raw::AxisAngleKey* GetAxisAngleKeys(UInt32 clipIndex) const = 0;
            /**
             * @brief Get the quaternion keys stored in a clip.
             * @param clipIndex The clip index.
             * @return A pointer to the keys, or null if not present.
             */
            virtual const Raw::QuaternionKey* GetQuaternionKeys(UInt32 clipIndex) const = 0;

            /**
             * @brief Get the number of blend factor key sets stored in the animation.
             * @return The number of key sets..
             */
            virtual UInt32 GetNumberOfBlendFactorKeySets() const = 0;
            /**
             * @brief Get the number of blend factor keys for a given key set stored in a clip.
             * @param clipIndex The clip index.
             * @param keySet The key set index.
             * @return The number of keys.
             */
            virtual UInt32 GetNumberOfBlendFactorKeys(UInt32 clipIndex, UInt32 keySet) const = 0;
            /**
             * @brief Get the blend factor keys for a given key set stored in a clip.
             * @param clipIndex The clip index.
             * @param keySet The key set index.
             * @return A pointer to the keys, or null if not present.
             */
            virtual const Raw::FloatKey* GetBlendFactorKeys(UInt32 clipIndex, UInt32 keySet) const = 0;
            
            /**
             * @brief Get the number of cubic bezier curve parameter sets in this animation.
             * @return The number of parameter sets.
             */
            virtual UInt32 GetNumberOfCubicBezierParameterSets() const = 0;
            /**
             * @brief Get the cubic bezier curve parameter set for a given index.
             * @param parameterSetIndex The index of the parameter set, in the range from 0 to GetNumberOfCubicBezierParameterSets()-1..
             * @return A pointer to the parameter set, or null if not present.
             */
            virtual const Raw::CubicBezierParameterSet* GetCubicBezierParameterSet(UInt32 parameterSetIndex) const = 0;

            /**
             * @brief Evaluate the output value for two FloatKey entries and a given time value, and store it in a given Float variable.
             * @param startKey The start key.
             * @param endKey The end key.
             * @param t The absolute time value.
             * @param output A reference to a variable receiving the evaluation result.
             */
            virtual void Evaluate(const Raw::FloatKey& startKey, const Raw::FloatKey& endKey, Double t, Float& output) const = 0;
            /**
             * @brief Evaluate the output value for two FloatKey entries and a given time value, and store it in a given Double variable.
             * @param startKey The start key.
             * @param endKey The end key.
             * @param t The absolute time value.
             * @param output A reference to a variable receiving the evaluation result.
             */
            virtual void Evaluate(const Raw::FloatKey& startKey, const Raw::FloatKey& endKey, Double t, Double& output) const = 0;
            /**
             * @brief Evaluate the output value for two IntegerKey entries and a given time value, and store it in a given UInt32 variable.
             * @param startKey The start key.
             * @param endKey The end key.
             * @param t The absolute time value.
             * @param output A reference to a variable receiving the evaluation result.
             */
            virtual void Evaluate(const Raw::IntegerKey& startKey, const Raw::IntegerKey& endKey, Double t, UInt32& output) const = 0;
            /**
             * @brief Evaluate the output value for two IntegerKey entries and a given time value, and store it in a given SInt32 variable.
             * @param startKey The start key.
             * @param endKey The end key.
             * @param t The absolute time value.
             * @param output A reference to a variable receiving the evaluation result.
             */
            virtual void Evaluate(const Raw::IntegerKey& startKey, const Raw::IntegerKey& endKey, Double t, SInt32& output) const = 0;
            /**
             * @brief Evaluate the output value for two BoolKey entries and a given time value, and store it in a given Bool variable.
             * @param startKey The start key.
             * @param endKey The end key.
             * @param t The absolute time value.
             * @param output A reference to a variable receiving the evaluation result.
             */
            virtual void Evaluate(const Raw::BoolKey& startKey, const Raw::BoolKey& endKey, Double t, Bool& output) const = 0;
            /**
             * @brief Evaluate the RGBA output values for two ColorKey entries and a given time value, and store them in a given Color variable.
             * @param startKey The start key.
             * @param endKey The end key.
             * @param t The absolute time value.
             * @param output A reference to a variable receiving the evaluation result.
             */
            virtual void Evaluate(const Raw::ColorKey& startKey, const Raw::ColorKey& endKey, Double t, Color& output) const = 0;
            /**
             * @brief Evaluate the XYZ output values for two PositionKey entries and a given time value, and store them in the X, Y and Z fields of a given Vector variable.
             * @param startKey The start key.
             * @param endKey The end key.
             * @param t The absolute time value.
             * @param output A reference to a variable receiving the evaluation result.
             */
            virtual void Evaluate(const Raw::PositionKey& startKey, const Raw::PositionKey& endKey, Double t, Vector& output) const = 0;
            /**
             * @brief Evaluate the XYZ output values for two PositionKey entries and a given time value, and store them in the XW, YW and ZW fields of a given Matrix variable.
             * @param startKey The start key.
             * @param endKey The end key.
             * @param t The absolute time value.
             * @param output A reference to a variable receiving the evaluation result.
             */
            virtual void Evaluate(const Raw::PositionKey& startKey, const Raw::PositionKey& endKey, Double t, Matrix& output) const = 0;
            /**
             * @brief Evaluate the XYZ output values for two ScalingKey entries and a given time value, and store them in the X, Y and Z fields of a given Vector variable.
             * @param startKey The start key.
             * @param endKey The end key.
             * @param t The absolute time value.
             * @param output A reference to a variable receiving the evaluation result.
             */
            virtual void Evaluate(const Raw::ScalingKey& startKey, const Raw::ScalingKey& endKey, Double t, Vector& output) const = 0;
            /**
             * @brief Evaluate the XYZ output values for two ScalingKey entries and a given time value, and store them in the XX, YY and ZZ fields of a given Matrix variable.
             * @param startKey The start key.
             * @param endKey The end key.
             * @param t The absolute time value.
             * @param output A reference to a variable receiving the evaluation result.
             */
            virtual void Evaluate(const Raw::ScalingKey& startKey, const Raw::ScalingKey& endKey, Double t, Matrix& output) const = 0;
            /**
             * @brief Evaluate the XYZ output rotation values for two EulerAngleKey entries and a given time value, and store them in the X, Y and Z fields of a given Vector variable.
             * @param startKey The start key.
             * @param endKey The end key.
             * @param t The absolute time value.
             * @param output A reference to a variable receiving the evaluation result.
             */
            virtual void Evaluate(const Raw::EulerAngleKey& startKey, const Raw::EulerAngleKey& endKey, Double t, Vector& output) const = 0;
            /**
             * @brief Evaluate the XYZ output values for two EulerAngleKey entries and a given time value, and store their combined rotation in the upper 3x3 fields of a given Matrix variable.
             * The rotation order is defined by the enum value stored in the start key.
             * @param startKey The start key.
             * @param endKey The end key.
             * @param t The absolute time value.
             * @param output A reference to a variable receiving the evaluation result.
             */
            virtual void Evaluate(const Raw::EulerAngleKey& startKey, const Raw::EulerAngleKey& endKey, Double t, Matrix& output) const = 0;
            /**
             * @brief Evaluate the XYZ output values for two EulerAngleKey entries and a given time value, and store their combined rotation in a given Quaternion variable.
             * The rotation order is defined by the enum value stored in the start key.
             * @param startKey The start key.
             * @param endKey The end key.
             * @param t The absolute time value.
             * @param output A reference to a variable receiving the evaluation result.
             */
            virtual void Evaluate(const Raw::EulerAngleKey& startKey, const Raw::EulerAngleKey& endKey, Double t, Quaternion& output) const = 0;
            /**
             * @brief Evaluate the XYZ axis and rotation angle output values for two AxisAngleKey entries and a given time value, and store them in the X, Y, Z and W fields of a given Vector variable.
             * @param startKey The start key.
             * @param endKey The end key.
             * @param t The absolute time value.
             * @param output A reference to a variable receiving the evaluation result.
             */
            virtual void Evaluate(const Raw::AxisAngleKey& startKey, const Raw::AxisAngleKey& endKey, Double t, Vector& output) const = 0;
            /**
             * @brief Evaluate the XYZ axis and rotation angle output values for two AxisAngleKey entries and a given time value, and store the resulting rotation in the upper 3x3 fields of a given Matrix variable.
             * @param startKey The start key.
             * @param endKey The end key.
             * @param t The absolute time value.
             * @param output A reference to a variable receiving the evaluation result.
             */
            virtual void Evaluate(const Raw::AxisAngleKey& startKey, const Raw::AxisAngleKey& endKey, Double t, Matrix& output) const = 0;
            /**
             * @brief Evaluate the XYZ axis and rotation angle output values for two AxisAngleKey entries and a given time value, and store the resulting rotation in a given Quaternion variable.
             * @param startKey The start key.
             * @param endKey The end key.
             * @param t The absolute time value.
             * @param output A reference to a variable receiving the evaluation result.
             */
            virtual void Evaluate(const Raw::AxisAngleKey& startKey, const Raw::AxisAngleKey& endKey, Double t, Quaternion& output) const = 0;
            /**
             * @brief Evaluate the RIJK output values for two QuaternionKey entries and a given time value, and store the resulting rotation axis in the X, Y and Z fields and the rotation angle in the W field of a given Vector variable.
             * @param startKey The start key.
             * @param endKey The end key.
             * @param t The absolute time value.
             * @param output A reference to a variable receiving the evaluation result.
             */
            virtual void Evaluate(const Raw::QuaternionKey& startKey, const Raw::QuaternionKey& endKey, Double t, Vector& output) const = 0;
            /**
             * @brief Evaluate the RIJK output values for two QuaternionKey entries and a given time value, and store the resulting rotation in the upper 3x3 fields of a given Matrix variable.
             * @param startKey The start key.
             * @param endKey The end key.
             * @param t The absolute time value.
             * @param output A reference to a variable receiving the evaluation result.
             */
            virtual void Evaluate(const Raw::QuaternionKey& startKey, const Raw::QuaternionKey& endKey, Double t, Matrix& output) const = 0;
            /**
             * @brief Evaluate the RIJK output values for two QuaternionKey entries and a given time value, and store them in a given Quaternion variable.
             * @param startKey The start key.
             * @param endKey The end key.
             * @param t The absolute time value.
             * @param output A reference to a variable receiving the evaluation result.
             */
            virtual void Evaluate(const Raw::QuaternionKey& startKey, const Raw::QuaternionKey& endKey, Double t, Quaternion& output) const = 0;

        protected:
            virtual ~IAnimation() {}
        };
    }
}

#endif  // __MURL_RESOURCE_I_ANIMATION_H__
