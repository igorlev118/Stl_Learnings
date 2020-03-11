// Copyright 2010-2015 Spraylight

#ifndef __MURL_I_ENUMS_H__
#define __MURL_I_ENUMS_H__

#include "murl_i_enums_animation.h"
#include "murl_i_enums_audio.h"
#include "murl_i_enums_debug.h"
#include "murl_i_enums_device.h"
#include "murl_i_enums_configuration.h"
#include "murl_i_enums_graph.h"

namespace Murl
{
    /**
     * @ingroup MurlEnumerations
     * @brief A collection of system-wide constant enumerations.
     *  All enumerations can be accessed by a corresponding Enum accessor.
     */
    namespace IEnums
    {
        /**
         * @addtogroup MurlMiscEnumerations
         * @brief Miscellaneous enumeration items.
         * @{
         */

        /**
         * @brief The static enum container in the Murl::IEnums namespace.
         */
        class StaticEnumContainer
        {
        public:
            /**
             * @brief Get the static enum container.
             * @return A reference to the container.
             */
            static EnumContainer& Get();
        };

        /**
         * @brief Shapes of touch areas used in the input handler.
         */
        enum TouchAreaShape
        {
            /// A rectangular touch area.
            MURL_DECLARE_ENUM_VALUE(TOUCH_AREA_SHAPE, RECTANGLE)
            /// An elliptical touch area.
            MURL_DECLARE_ENUM_VALUE(TOUCH_AREA_SHAPE, ELLIPSE)
            /// A generic triangle mesh used for capturing input touches.
            MURL_DECLARE_ENUM_VALUE(TOUCH_AREA_SHAPE, MESH)

            NUM_TOUCH_AREA_SHAPES
        };
        MURL_DECLARE_ENUM_ACCESSOR(TouchAreaShape)

        /**
         * @brief Projection types used for both rendering and input handling.
         */
        enum ProjectionType
        {
            /// Perspective projection.
            MURL_DECLARE_ENUM_VALUE(PROJECTION_TYPE, PERSPECTIVE)
            /// Orthographic (i.e. parallel) projection.
            MURL_DECLARE_ENUM_VALUE(PROJECTION_TYPE, ORTHOGRAPHIC)

            NUM_PROJECTION_TYPES
        };
        MURL_DECLARE_ENUM_ACCESSOR(ProjectionType)

        /**
         * @brief Globally defined result codes.
         */
        enum ResultCode
        {
            /// No error (success).
            MURL_DECLARE_ENUM_VALUE(RESULT_CODE, NONE)

            /// An unspecified (generic) error.
            MURL_DECLARE_ENUM_VALUE(RESULT_CODE, UNSPECIFIED_ERROR)

            /// A version error.
            MURL_DECLARE_ENUM_VALUE(RESULT_CODE, VERSION_ERROR)
            /// Error during parsing a resource or file.
            MURL_DECLARE_ENUM_VALUE(RESULT_CODE, PARSING_ERROR)
            /// A general file error (not existing or read error).
            MURL_DECLARE_ENUM_VALUE(RESULT_CODE, FILE_ERROR)
            /// Error converting a numeric attribute value.
            MURL_DECLARE_ENUM_VALUE(RESULT_CODE, ATTRIBUTE_NUMBER_CONVERSION_ERROR)
            /// Error converting a attribute enum value.
            MURL_DECLARE_ENUM_VALUE(RESULT_CODE, ATTRIBUTE_ENUM_CONVERSION_ERROR)
            /// Unknown attribute value.
            MURL_DECLARE_ENUM_VALUE(RESULT_CODE, ATTRIBUTE_UNKNOWN_ERROR)
            /// Referenced graph node not found.
            MURL_DECLARE_ENUM_VALUE(RESULT_CODE, GRAPH_NODE_NOT_FOUND_ERROR)
            /// Referenced graph node has wrong interface.
            MURL_DECLARE_ENUM_VALUE(RESULT_CODE, GRAPH_NODE_WRONG_INTERFACE_ERROR)
            /// Referenced resource object not found.
            MURL_DECLARE_ENUM_VALUE(RESULT_CODE, RESOURCE_OBJECT_NOT_FOUND_ERROR)
            /// Referenced resource object has wrong interface.
            MURL_DECLARE_ENUM_VALUE(RESULT_CODE, RESOURCE_OBJECT_WRONG_INTERFACE_ERROR)

            /// An unspecified (generic) warning.
            MURL_DECLARE_ENUM_VALUE(RESULT_CODE, UNSPECIFIED_WARNING)

            /// An unspecified (generic) information message.
            MURL_DECLARE_ENUM_VALUE(RESULT_CODE, UNSPECIFIED_INFO)

            NUM_RESULT_CODES
        };
        MURL_DECLARE_ENUM_ACCESSOR(ResultCode)

        /**
         * @brief Possible actions to perform on a specific result code.
         */
        enum ResultAction
        {
            /// Undefined action.
            MURL_DECLARE_ENUM_VALUE(RESULT_ACTION, UNDEFINED)

            /// Ignore the result (do not warn and keep running).
            MURL_DECLARE_ENUM_VALUE(RESULT_ACTION, IGNORE)
            /// Report a message, but keep running.
            MURL_DECLARE_ENUM_VALUE(RESULT_ACTION, WARN)
            /// Report a message and abort.
            MURL_DECLARE_ENUM_VALUE(RESULT_ACTION, ABORT)

            NUM_RESULT_ACTIONS
        };
        MURL_DECLARE_ENUM_ACCESSOR(ResultAction)

        /**
         * @brief Definition of the file access modes.
         */
        enum FileAccessMode
        {
            /** @brief Read only access.
             * The file must exist.
             */
            MURL_DECLARE_ENUM_VALUE(FILE_ACCESS_MODE, READ_ONLY)
            /** @brief Write only access.
             * Create an empty file or erase an already existing file.
             */
            MURL_DECLARE_ENUM_VALUE(FILE_ACCESS_MODE, WRITE_ONLY)
            /** @brief Read and write access.
             * Create an empty file or erase an already existing file.
             */
            MURL_DECLARE_ENUM_VALUE(FILE_ACCESS_MODE, READ_AND_WRITE)
            /** @brief Append access.
             * Create an empty file if the file does not exist.
             * All writing operations are performed at the end of the file.
             */
            MURL_DECLARE_ENUM_VALUE(FILE_ACCESS_MODE, APPEND_ONLY)
            /** @brief Read and append access.
             * Create an empty file if the file does not exist.
             * All writing operations are performed at the end of the file,
             * the file position can be set to anywhere in the file for reading,
             * writing operations will move the file position back to the end of file.
             */
            MURL_DECLARE_ENUM_VALUE(FILE_ACCESS_MODE, READ_AND_APPEND)

            NUM_FILE_ACCESS_MODES
        };
        MURL_DECLARE_ENUM_ACCESSOR(FileAccessMode)

        /**
         * @brief Authorization status enumeration.
         */
        enum AuthorizationStatus
        {
            /// Authorization not determined.
            MURL_DECLARE_ENUM_VALUE(AUTHORIZATION, NOT_DETERMINED)
            /// Authorization is restricted by the system.
            MURL_DECLARE_ENUM_VALUE(AUTHORIZATION, RESTRICTED)
            /// Authorization is denied by user.
            MURL_DECLARE_ENUM_VALUE(AUTHORIZATION, DENIED)
            /// Authorization is authorized.
            MURL_DECLARE_ENUM_VALUE(AUTHORIZATION, AUTHORIZED)

            NUM_AUTHORIZATIONS
        };
        MURL_DECLARE_ENUM_ACCESSOR(AuthorizationStatus)

        /**
         * @brief Socket error status enumeration.
         */
        enum SocketError
        {
            /// No error.
            MURL_DECLARE_ENUM_VALUE(SOCKET_ERROR, NONE)
            /// Socket is not connected.
            MURL_DECLARE_ENUM_VALUE(SOCKET_ERROR, NOT_CONNECTED)
            /// Connection was reset by peer.
            MURL_DECLARE_ENUM_VALUE(SOCKET_ERROR, RESET_BY_PEER)
            /// Last send operation failed.
            MURL_DECLARE_ENUM_VALUE(SOCKET_ERROR, SEND_FAILED)
            /// Last receive operation failed.
            MURL_DECLARE_ENUM_VALUE(SOCKET_ERROR, RECEIVE_FAILED)
            /// Resource temporarily unavailable.
            MURL_DECLARE_ENUM_VALUE(SOCKET_ERROR, WOULD_BLOCK)
            /// Operation is in progress.
            MURL_DECLARE_ENUM_VALUE(SOCKET_ERROR, IN_PROGRESS)
            /// Last operation failed.
            MURL_DECLARE_ENUM_VALUE(SOCKET_ERROR, FAILED)

            NUM_SOCKET_ERRORS
        };
        MURL_DECLARE_ENUM_ACCESSOR(SocketError)

        /**
         * @brief Available resource types
         */
        enum ResourceType
        {
            /// Default resource type, use any suitable.
            MURL_DECLARE_ENUM_VALUE(RESOURCE_TYPE, DEFAULT)

            /// Generic resource type, exposing raw binary contents.
            MURL_DECLARE_ENUM_VALUE(RESOURCE_TYPE, BINARY)
            /// Animation resource.
            MURL_DECLARE_ENUM_VALUE(RESOURCE_TYPE, ANIMATION)
            /// Atlas resource.
            MURL_DECLARE_ENUM_VALUE(RESOURCE_TYPE, ATLAS)
            /// Font resource.
            MURL_DECLARE_ENUM_VALUE(RESOURCE_TYPE, FONT)
            /// Graph resource.
            MURL_DECLARE_ENUM_VALUE(RESOURCE_TYPE, GRAPH)
            /// Image resource.
            MURL_DECLARE_ENUM_VALUE(RESOURCE_TYPE, IMAGE)
            /// Mesh resource.
            MURL_DECLARE_ENUM_VALUE(RESOURCE_TYPE, MESH)
            /// Shader resource.
            MURL_DECLARE_ENUM_VALUE(RESOURCE_TYPE, SHADER)
            /// Audio resource.
            MURL_DECLARE_ENUM_VALUE(RESOURCE_TYPE, AUDIO)
            /// Generic resource type storing compressed binary contents.
            MURL_DECLARE_ENUM_VALUE(RESOURCE_TYPE, ARCHIVE)
            /// Video resource.
            MURL_DECLARE_ENUM_VALUE(RESOURCE_TYPE, VIDEO)
            /// Script resource.
            MURL_DECLARE_ENUM_VALUE(RESOURCE_TYPE, SCRIPT)
            /// Unknown resource.
            MURL_DECLARE_ENUM_VALUE(RESOURCE_TYPE, UNKNOWN)
            /// Package containing multiple resources and/or sub-packages.
            MURL_DECLARE_ENUM_VALUE(RESOURCE_TYPE, PACKAGE)
            /// Dictionary resource containing multiple key/value pairs.
            MURL_DECLARE_ENUM_VALUE(RESOURCE_TYPE, DICTIONARY)
            /// Grid resource.
            MURL_DECLARE_ENUM_VALUE(RESOURCE_TYPE, GRID)
            /// Text resource.
            MURL_DECLARE_ENUM_VALUE(RESOURCE_TYPE, TEXT)

            NUM_RESOURCE_TYPES
        };
        MURL_DECLARE_ENUM_ACCESSOR(ResourceType)

        /**
         * @brief Available file types
         */
        enum FileType
        {
            /// Default file type, use any suitable.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, DEFAULT)

            /// Unknown file type.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, UNKNOWN)

            /// A text file.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, TXT)

            /// XML file type.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, XML)
            /// Native Murl binary.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, MURL)

            /// PNG image.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, PNG)
            /// JPEG image.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, JPG)
            /// WEBP image.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, WEBP)
            /// DDS (DirectX) image.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, DDS)
            /// ETC1 compressed image.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, ETC1)
            /// PVRTC compressed image.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, PVR)
            /// TGA image.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, TGA)
            /// TIFF image.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, TIF)

            /// Microsoft WAVE audio.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, WAV)
            /// OGG/Vorbis audio.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, OGG)
            /// MP3 audio.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, MP3)

            /// MP4 audio/video.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, MP4)
            /// WMV audio/video.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, WMV)

            /// GLSL shader source.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, GLSL)
            /// HLSL shader source or binary.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, HLSL)

            /// Blender scene.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, BLEND)
            /// Collada scene.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, DAE)
            /// Autodesk FBX scene.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, FBX)
            /// Maxon Cinema4D scene.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, C4D)
            /// 3D Studio scene.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, 3DS)
            /// 3D Studio Max ASCII export scene.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, ASE)
            /// Wavefront object.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, OBJ)
            /// Wavefront material.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, MTL)
            /// Lightwave object.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, LWO)
            /// Lightwave scene.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, LWS)
            /// DirectX 3D object.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, X)
            /// Quake model.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, MDL)
            /// Quake II model.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, MD2)
            /// Quake III model.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, MD3)
            /// Doom 3 model.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, MD5)
            /// Quake III compressed Map/BSP package.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, PK3)
            /// Quake III BSP file.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, BSP)
            /// Quake III Map file.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, MAP)

            /// TrueType font.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, TTF)
            /// OpenType font.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, OTF)

            /// ZIP archive.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, ZIP)
            /// TAR/GZ archive.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, TGZ)
            /// BZIP2 archive.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, BZ2)

            /// CSV file.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, CSV)

            /// KTX (Khronos texture) file.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, KTX)
            /// PKM image file.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, PKM)
            /// ASTC image file.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, ASTC)
            /// Radiance HDR image file.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, HDR)
            /// PFM (Portable Float Map) image file.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, PFM)
            /// EXR image file.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, EXR)

            /// LUA script file.
            MURL_DECLARE_ENUM_VALUE(FILE_TYPE, LUA)

            NUM_FILE_TYPES
        };
        MURL_DECLARE_ENUM_ACCESSOR(FileType)

        /**
         * @brief Available font types
         */
        enum FontType
        {
            /// Undefined font type.
            MURL_DECLARE_ENUM_VALUE(FONT_TYPE, UNDEFINED)

            /// Bitmap font, composed of a set of glyph descriptors and a bitmap image.
            MURL_DECLARE_ENUM_VALUE(FONT_TYPE, BITMAP)
            /// Outline font, containing individual vector outlines for each glyph.
            MURL_DECLARE_ENUM_VALUE(FONT_TYPE, OUTLINE)
            /// System font, to be retrieved and rendered via the OS.
            MURL_DECLARE_ENUM_VALUE(FONT_TYPE, SYSTEM)

            NUM_FONT_TYPES
        };
        MURL_DECLARE_ENUM_ACCESSOR(FontType)

        /**
         * @brief Available property semantics
         */
        enum PropertySemantic
        {
            /// No semantic (property is not used).
            MURL_DECLARE_ENUM_VALUE(PROPERTY_SEMANTIC, NONE)

            /// A generic value.
            MURL_DECLARE_ENUM_VALUE(PROPERTY_SEMANTIC, VALUE)
            /// An angle value.
            MURL_DECLARE_ENUM_VALUE(PROPERTY_SEMANTIC, ANGLE)
            /// A bit mask.
            MURL_DECLARE_ENUM_VALUE(PROPERTY_SEMANTIC, MASK)
            /// A generic object.
            MURL_DECLARE_ENUM_VALUE(PROPERTY_SEMANTIC, OBJECT)
            /// An ID string.
            MURL_DECLARE_ENUM_VALUE(PROPERTY_SEMANTIC, ID)
            /// A string representing a single file name.
            MURL_DECLARE_ENUM_VALUE(PROPERTY_SEMANTIC, FILE_NAME)
            /// A string representing a path to a single file.
            MURL_DECLARE_ENUM_VALUE(PROPERTY_SEMANTIC, FILE_PATH)
            /// A string representing a single folder name.
            MURL_DECLARE_ENUM_VALUE(PROPERTY_SEMANTIC, FOLDER_NAME)
            /// A string representing a path to a single folder.
            MURL_DECLARE_ENUM_VALUE(PROPERTY_SEMANTIC, FOLDER_PATH)

            NUM_PROPERTY_SEMANTICS
        };
        MURL_DECLARE_ENUM_ACCESSOR(PropertySemantic)

        /**
         * @brief The ZLib compression levels
         */
        enum CompressionLevel
        {
            /// Default compression (ZLib Z_DEFAULT_COMPRESSION).
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(COMPRESSION_LEVEL, DEFAULT, -1)

            /// No compression (ZLib Z_NO_COMPRESSION).
            MURL_DECLARE_ENUM_VALUE_PREDEFINED(COMPRESSION_LEVEL, NONE, 0)
            /// Fastest compression (ZLib Z_BEST_SPEED).
            MURL_DECLARE_ENUM_VALUE(COMPRESSION_LEVEL, SPEED)
            /// Compression level 2.
            MURL_DECLARE_ENUM_VALUE(COMPRESSION_LEVEL, 2)
            /// Compression level 3.
            MURL_DECLARE_ENUM_VALUE(COMPRESSION_LEVEL, 3)
            /// Compression level 4.
            MURL_DECLARE_ENUM_VALUE(COMPRESSION_LEVEL, 4)
            /// Compression level 5.
            MURL_DECLARE_ENUM_VALUE(COMPRESSION_LEVEL, 5)
            /// Compression level 6 (default ZLib compression).
            MURL_DECLARE_ENUM_VALUE(COMPRESSION_LEVEL, 6)
            /// Compression level 7.
            MURL_DECLARE_ENUM_VALUE(COMPRESSION_LEVEL, 7)
            /// Compression level 8.
            MURL_DECLARE_ENUM_VALUE(COMPRESSION_LEVEL, 8)
            /// Best compression (ZLib Z_BEST_COMPRESSION).
            MURL_DECLARE_ENUM_VALUE(COMPRESSION_LEVEL, BEST)
        };

        /**
         * @brief Definition of the image file format types.
         */
        enum ImageFormat
        {
            /** @brief Unknown image file format. */
            IMAGE_FORMAT_UNKNOWN = 0,
            /** @brief The PNG image file format. */
            IMAGE_FORMAT_PNG,
            /** @brief The JPG image file format. */
            IMAGE_FORMAT_JPG,
            /** @brief The WEBP image file format. */
            IMAGE_FORMAT_WEBP,
            /** @brief The DDS image file format. */
            IMAGE_FORMAT_DDS,
            /** @brief The TGA image file format. */
            IMAGE_FORMAT_TGA,
            /** @brief Raw image data. */
            IMAGE_FORMAT_RAW,
            /** @brief The KTX image file format. */
            IMAGE_FORMAT_KTX,
            /** @brief The PVR image file format. */
            IMAGE_FORMAT_PVR,
            /** @brief The PKM (ETC1) image file format. */
            IMAGE_FORMAT_PKM,
            /** @brief The ASTC image file format. */
            IMAGE_FORMAT_ASTC,
            /** @brief The Radiance HDR image file format. */
            IMAGE_FORMAT_HDR,
            /** @brief The PFM (Portable Float Map) image file format. */
            IMAGE_FORMAT_PFM,

            NUM_IMAGE_FORMATS
        };
        MURL_DECLARE_ENUM_ACCESSOR(ImageFormat)

        /** @} */
    }
}

#endif  // __MURL_I_ENUMS_H__
