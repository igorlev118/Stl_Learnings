// Copyright 2012-2014 Spraylight GmbH

#ifndef __MURL_UTIL_ENCODING_BASE64_H__
#define __MURL_UTIL_ENCODING_BASE64_H__

#include "murl_data.h"

namespace Murl
{
    namespace Util
    {
        /**
         * @addtogroup MurlUtilCodingFunctions
         * @brief Encoding / Decoding functions.
         * @{
         */

        /**
         * @brief Encode a string to a Base64 character string.
         * @param dataIn The source string to encode.
         * @return The Base64 character encoded string.
         */
        String EncodeBase64(const String& dataIn);

        /**
         * @brief Encode a data object to a Base64 character string.
         * @param dataIn The source data object to encode.
         * @return The Base64 character encoded string.
         */
        String EncodeBase64(const ConstData& dataIn);

        /**
         * @brief Encode a memory block to a Base64 string.
         * @param dataIn Pointer to the source memory block.
         * @param byteSizeIn The byte size of the memory block.
         * @return The Base64 character encoded string.
         */
        String EncodeBase64(const void* dataIn, UInt64 byteSizeIn);

        /**
         * @brief Decode a Base64 character string.
         * @param dataIn The source Base64 character string to decode.
         * @return The decoded data object.
         */
        Data DecodeBase64(const String& dataIn);

        /**
         * @brief Decode Base64 characters from a data object.
         * @param dataIn The source data object to decode.
         * @return The decoded data object.
         */
        Data DecodeBase64(const ConstData& dataIn);

        /**
         * @brief Decode Base64 characters from a memory block.
         * @param dataIn Pointer to the source memory block.
         * @param byteSizeIn The byte size of the memory block.
         * @return The decoded data object.
         */
        Data DecodeBase64(const void* dataIn, UInt64 byteSizeIn);

        /**
         * @brief Check if a string is Base64 encoded.
         * @param dataIn The source Base64 string.
         * @return true if the string is Base64 encoded.
         */
        Bool IsBase64(const String& dataIn);

        /**
         * @brief Check if a data object is Base64 encoded.
         * @param dataIn The source Base64 data object.
         * @return true if the data object is Base64 encoded.
         */
        Bool IsBase64(const ConstData& dataIn);

        /**
         * @brief Check if a memory block is Base64 encoded.
         * @param dataIn Pointer to the source memory block.
         * @param byteSizeIn The byte size of the memory block.
         * @return true if the memory block is Base64 encoded.
         */
        Bool IsBase64(const void* dataIn, UInt64 byteSizeIn);

        /** @} */

        /**
         * @ingroup MurlUtilClasses
         * @brief The Base64 state class.
         * The Base64State class is the base class of the Base64Encoder
         * and Base64Decoder class to accomplish sequential
         * Base64Encoder::Encode or Base64Decoder::Decode calls.
         */
        class Base64State
        {
        public:
            /**
             * @brief The default constructor.
             */
            Base64State();

            /** @brief State enumeration. */
            enum Step
            {
                STEP_A, ///< Process bit  0 ..  5
                STEP_B, ///< Process bit  6 .. 11
                STEP_C, ///< Process bit 12 .. 17
                STEP_D  ///< Process bit 18 .. 23
            };

            /** @brief The current state. */
            Step mStep;
            /** @brief The current character. */
            Char mChar;
        };

        /**
         * @ingroup MurlUtilClasses
         * @brief The Base64 encoder class.
         */
        class Base64Encoder : protected Base64State
        {
        public:
            /**
             * @brief The default constructor.
             * Line formatting is disabled.
             */
            Base64Encoder();

            /**
             * @brief Constructor enabling line formatting.
             * @param charsPerLine The maximum characters per line.
             */
            Base64Encoder(UInt32 charsPerLine);

            /**
             * @brief Compute the Base64 encoded length.
             * @param byteSizeIn The number of source bytes.
             * @return The number of bytes required for Base64 encoding.
             */
            UInt64 GetEncodedLength(UInt64 byteSizeIn) const;

            /**
             * @brief Encode a memory block to Base64 characters.
             * Encoding can be called sequential for divided source blocks.
             * @param dataIn Pointer to the source memory block.
             * @param byteSizeIn The byte size of the source memory block.
             * @param dataOut Pointer to the destination memory block.
             * @param byteSizeOut The byte size of the destination memory block.
             * @param encodeEnd If true the padding characters are encoded
             *  automatically at the end of the block.
             *  Set to false if sequential encoding is required and
             *  call EncodeEnd method finally.
             * @return The number of bytes written into destination.
             */
            UInt64 Encode(const void* dataIn, UInt64 byteSizeIn,
                          void* dataOut, UInt64 byteSizeOut, Bool encodeEnd = true);

            /**
             * @brief Encode the Base64 end padding characters.
             * This method is required if the encodeEnd parameter from the
             * Encode method is set to false.
             * @param dataOut Pointer to the destination memory block.
             * @param byteSizeOut The byte size of the destination memory block.
             * @return The number of bytes written into destination.
             */
            UInt64 EncodeEnd(void* dataOut, UInt64 byteSizeOut);

            /**
             * @brief Encode a 6-bit value to the Base64 character.
             * @param value The 6-bit value to encode.
             * @return The corresponding Base64 character
             *  or '=' if the value is out of range.
             */
            Char EncodeValue(Char value) const;

        protected:
            /** The current line character position. */
            UInt32 mLineCount;
            /** The maximum characters per line. */
            UInt32 mCharsPerLine;
        };

        /**
         * @ingroup MurlUtilClasses
         * @brief The Base64 decoder class.
         */
        class Base64Decoder : protected Base64State
        {
        public:
            /**
             * @brief The default constructor.
             */
            Base64Decoder();

            /**
             * @brief Compute the Base64 decoded length.
             * @param dataIn Pointer to the Base64 source memory block.
             * @param byteSizeIn The byte size of the source memory block.
             * @return The number of bytes required for decoding.
             */
            UInt64 GetDecodedLength(const void* dataIn, UInt64 byteSizeIn) const;

            /**
             * @brief Check if a memory block is Base64 encoded.
             * @param dataIn Pointer to the Base64 source memory block.
             * @param byteSizeIn The byte size of the source memory block.
             * @return true if the memory block is Base64 encoded.
             */
            Bool IsBase64(const void* dataIn, UInt64 byteSizeIn) const;

            /**
             * @brief Decode Base64 characters from a memory block.
             * Decoding can be called sequential for divided source blocks.
             * @param dataIn Pointer to the source memory block.
             * @param byteSizeIn The byte size of the source memory block.
             * @param dataOut Pointer to the destination memory block.
             * @param byteSizeOut The byte size of the destination memory block.
             * @return The number of bytes written into destination.
             */
            UInt64 Decode(const void* dataIn, UInt64 byteSizeIn,
                          void* dataOut, UInt64 byteSizeOut);

            /**
             * @brief Decode a Base64 character to the 6-bit value.
             * @param charIn The Base64 character to decode.
             * @return The corresponding 6-bit value
             *  or -1 if the character is invalid.
             */
            Char DecodeValue(Char charIn) const;
        };
    }
}

#endif // __MURL_UTIL_ENCODING_BASE64_H__
