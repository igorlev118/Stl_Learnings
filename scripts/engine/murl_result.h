// Copyright 2014 Spraylight GmbH

#ifndef __MURL_RESULT_H__
#define __MURL_RESULT_H__

#include "murl_i_enums.h"

namespace Murl
{
    /**
     * @ingroup MurlClasses
     * @brief A class for retrieving the result of some operation.
     */
    class Result
    {
    public:
        /**
         * @brief The default constructor
         */
        Result();

        /**
         * @brief Clear the result (Set OK).
         */
        void Clear();

        /**
         * @brief Set a result from a given other result.
         * @param other The result object to copy from.
         */
        void Set(const Result& other);

        /**
         * @brief Append a given other result.
         * @param other The result object to copy from.
         */
        void Append(const Result& other);

        /**
         * @brief Set a result code and message.
         * This clears the current result and sets a single message only.
         * @param code The result code.
         * @param message The message.
         */
        void Set(IEnums::ResultCode code, const Char* message, ...);

        /**
         * @brief Append a result code and message.
         * @param code The result code.
         * @param message The message.
         */
        void Append(IEnums::ResultCode code, const Char* message, ...);

        /**
         * @brief Check if the contained result is OK.
         * @return true if OK.
         */
        Bool IsClear() const;

        /**
         * @brief Check if the result contains at least one info.
         * @return true if error.
         */
        Bool HasInfo() const;
        /**
         * @brief Get the number of infos.
         * @return The number of infos.
         */
        UInt32 GetNumberOfInfos() const;
        /**
         * @brief Get the code of a info at a given index.
         * @param index The info index, in the range [0..GetNumberOfInfos()-1].
         * @return The result code.
         */
        IEnums::ResultCode GetInfoCode(UInt32 index) const;
        /**
         * @brief Get the message of a info at a given index.
         * @param index The info index, in the range [0..GetNumberOfInfos()-1].
         * @return The message.
         */
        const String& GetInfoMessage(UInt32 index) const;
        /**
         * @brief Get all info messages.
         * This method concatenates all existing infos to one string, each one
         * delimited by a single line feed character.
         * @return The concatenated info messages.
         */
        String GetAllInfoMessages() const;

        /**
         * @brief Check if the result contains at least one warning.
         * @return true if error.
         */
        Bool HasWarning() const;
        /**
         * @brief Get the number of warnings.
         * @return The number of warnings.
         */
        UInt32 GetNumberOfWarnings() const;
        /**
         * @brief Get the code of a warning at a given index.
         * @param index The warning index, in the range [0..GetNumberOfWarnings()-1].
         * @return The result code.
         */
        IEnums::ResultCode GetWarningCode(UInt32 index) const;
        /**
         * @brief Get the message of a warning at a given index.
         * @param index The warning index, in the range [0..GetNumberOfWarnings()-1].
         * @return The message.
         */
        const String& GetWarningMessage(UInt32 index) const;
        /**
         * @brief Get all warning messages.
         * This method concatenates all existing warnings to one string, each one
         * delimited by a single line feed character.
         * @return The concatenated warning messages.
         */
        String GetAllWarningMessages() const;

        /**
         * @brief Check if the result contains at least one error.
         * @return true if error.
         */
        Bool HasError() const;
        /**
         * @brief Get the number of errors.
         * @return The number of errors.
         */
        UInt32 GetNumberOfErrors() const;
        /**
         * @brief Get the code of a error at a given index.
         * @param index The error index, in the range [0..GetNumberOfErrors()-1].
         * @return The result code.
         */
        IEnums::ResultCode GetErrorCode(UInt32 index) const;
        /**
         * @brief Get the message of a error at a given index.
         * @param index The error index, in the range [0..GetNumberOfErrors()-1].
         * @return The message.
         */
        const String& GetErrorMessage(UInt32 index) const;
        /**
         * @brief Get all error messages.
         * This method concatenates all existing errors to one string, each one
         * delimited by a single line feed character.
         * @return The concatenated error messages.
         */
        String GetAllErrorMessages() const;

        /**
         * @brief Get all messages.
         * This method concatenates all existing errors, warnings and infos to one string,
         * each one delimited by a single line feed character.
         * @return The concatenated messages.
         */
        String GetAllMessages() const;

    private:
        struct Entry
        {
            Entry()
            : mCode(IEnums::RESULT_CODE_NONE)
            {
            }

            IEnums::ResultCode mCode;
            String mMessage;
        };

        Array<Entry> mInfoEntries;
        Array<Entry> mWarningEntries;
        Array<Entry> mErrorEntries;
    };
}

#endif  // __MURL_RESULT_H__
