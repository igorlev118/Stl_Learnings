// Copyright 2012-2014 Spraylight GmbH

#ifndef __MURL_SYSTEM_CONSOLE_H__
#define __MURL_SYSTEM_CONSOLE_H__

#include "murl_data.h"

namespace Murl
{
    namespace System
    {
        /**
         * @ingroup MurlSystemClasses
         * @brief The console printing class.
         * The console prints to std::printf or ANDROID_LOG_INFO.
         *
         * The console class has serveral static methods to print
         * without a class context e.g. System::Console::Print().
         *
         * An instance of the console class can print three levels:
         *  - The information level.
         *  - The warning level.
         *  - The error level.
         *
         * Printing a message supports:
         *  - A customizable prefix string for each level.
         *  - A customizable global prefix string.
         *  - Nested sections with customizable indentation width and character.
         *  - Suppress printing by setting the current print level.
         *
         * The output string is:
         * [global prefix]" "[indent string][level prefix]" "[message].
         */
        class Console
        {
        public:
            /**
             * @brief Print formatted variadic arguments.
             * @param format The format string.
             * @param ... The variadic arguments.
             * @return true if successful.
             */
            static Bool Print(const Char* format, ...);
            /**
             * @brief Print a string.
             * @param message The message string to print.
             * @return true if successful.
             */
            static Bool Print(const String& message);
            /**
             * @brief Print a string including an end-of-line
             * character at the end of the string.
             * @param message The message string to print.
             * @return true if successful.
             */
            static Bool PrintEndline(const String& message);
            /**
             * @brief Print the hex dump of a data object.
             * @param data The data object to print.
             * @param bytesPerLine The the number of source bytes per line.
             * @return true if successful.
             */
            static Bool PrintHex(const ConstData& data, UInt32 bytesPerLine = 16);

            /**
             * @brief The default constructor.
             */
            Console();
            /**
             * @brief Constructor taking a global prefix string.
             * @param globalPrefix The global prefix string.
             */
            Console(const String& globalPrefix);

            /**
             * @brief Definition of the print levels.
             * Use GetLevel() to get the current level.
             */
            enum Level
            {
                /** @brief Do not print. */
                QUIET = 0,
                /** @brief Print errors only. */
                ERROR,
                /** @brief Print errors and warnings. */
                WARNING,
                /** @brief Print errors, warnings and infos. */
                INFO,

                MAX_LEVELS
            };
            /**
             * @brief Set the current print level.
             * @param level The current print level.
             * @return true if successful, false if level is invalid.
             */
            Bool SetLevel(Level level);
            /**
             * @brief Get the current print level.
             * @return The current print level.
             */
            Level GetLevel() const;

            /**
             * @brief Set the number of indent characters per section.
             * The default number of indent characters is 2.
             * The indent string contains the indent character
             * (GetIndentWidth() * GetCurrentSection()) times.
             * The indent string is printed for each message.
             * @param indentWidth The number of indent characters per section,
             *  a width of zero disables indentation.
             */
            void SetIndentWidth(UInt32 indentWidth);
            /**
             * @brief Get the number of indent characters per section.
             * @return The number of indent characters per section.
             */
            UInt32 GetIndentWidth() const;

            /**
             * @brief Set the indent character.
             * The default indent character is a space.
             * The indent string contains the indent character
             * (GetIndentWidth() * GetCurrentSection()) times.
             * The indent string is printed for each message.
             * @param indentChar The indent character.
             */
            void SetIndentChar(Char indentChar);
            /**
             * @brief Get the indent character.
             * @return The indent character.
             */
            Char GetIndentChar() const;

            /**
             * @brief Set the global prefix string.
             * The global prefix string is printed for each message
             * including a trailing space character.
             * @param prefix The global prefix string.
             */
            void SetGlobalPrefix(const String& prefix);
            /**
             * @brief Get the global prefix string.
             * @return The global prefix string.
             */
            const String& GetGlobalPrefix() const;

            /**
             * @brief Set the info prefix string.
             * The info prefix string is printed for info messages
             * including a trailing space character.
             * @param prefix The info prefix string.
             */
            void SetInfoPrefix(const String& prefix);
            /**
             * @brief Get the info prefix string.
             * @return The info prefix string.
             */
            const String& GetInfoPrefix() const;

            /**
             * @brief Set the warning prefix string.
             * The warning prefix string is printed for warning messages
             * including a trailing space character.
             * @param prefix The warning prefix string.
             */
            void SetWarningPrefix(const String& prefix);
            /**
             * @brief Get the warning prefix string.
             * @return The warning prefix string.
             */
            const String& GetWarningPrefix() const;

            /**
             * @brief Set the error prefix string.
             * The error prefix string is printed for error messages
             * including a trailing space character.
             * @param prefix The error prefix string.
             */
            void SetErrorPrefix(const String& prefix);
            /**
             * @brief Get the error prefix string.
             * @return The error prefix string.
             */
            const String& GetErrorPrefix() const;

            /**
             * @brief Get the current section.
             * The currend section is incremented by BeginInfo()
             * and decremented by EndInfo().
             * The current section is used for indentation only,
             * see SetIndentChar() and SetIndentWidth().
             * @return The current section.
             */
            UInt32 GetCurrentSection() const;
            /**
             * @brief Get the current indent string.
             * The indent string contains the indent character
             * (GetIndentWidth() * GetCurrentSection()) times.
             * The indent string is printed for each message.
             * @return The current indent string.
             */
            const String& GetCurrentIndentString() const;

            /**
             * @brief Begin a section and print formatted variadic arguments.
             * The message is printed before incrementing the current section.
             * @param format The format string.
             * @param ... The variadic arguments.
             * @return true if successful.
             */
            Bool BeginSection(const Char* format, ...);
            /**
             * @brief Begin a section and print a string.
             * The message is printed before incrementing the current section.
             * @param message The message string to print.
             * @return true if successful.
             */
            Bool BeginSection(const String& message);
            /**
             * @brief Begin a section.
             * Increments the current section.
             * @return true if successful.
             */
            Bool BeginSection();

            /**
             * @brief End a section and print formatted variadic arguments.
             * The message is printed after decrementing the current section.
             * @param format The format string.
             * @param ... The variadic arguments.
             * @return true if successful.
             */
            Bool EndSection(const Char* format, ...);
            /**
             * @brief End a section and print a string.
             * The message is printed after decrementing the current section.
             * @param message The message string to print.
             * @return true if successful.
             */
            Bool EndSection(const String& message);
            /**
             * @brief End a section.
             * Decrements the current section.
             * @return true if successful.
             */
            Bool EndSection();

            /**
             * @brief Print formatted variadic arguments at info level.
             * @param format The format string.
             * @param ... The variadic arguments.
             * @return true if info level is enabled.
             */
            Bool PrintInfo(const Char* format, ...) const;
            /**
             * @brief Print a string at info level.
             * @param message The message string to print.
             * @return true if info level is enabled.
             */
            Bool PrintInfo(const String& message) const;

            /**
             * @brief Print formatted variadic arguments at warning level.
             * @param format The format string.
             * @param ... The variadic arguments.
             * @return true if warning or info level is enabled.
             */
            Bool PrintWarning(const Char* format, ...) const;
            /**
             * @brief Print a string at warning level.
             * @param message The message string to print.
             * @return true if warning or info level is enabled.
             */
            Bool PrintWarning(const String& message) const;

            /**
             * @brief Print formatted variadic arguments at error level.
             * @param format The format string.
             * @param ... The variadic arguments.
             * @return true if error, warning or info level is enabled.
             */
            Bool PrintError(const Char* format, ...) const;
            /**
             * @brief Print a string at error level.
             * @param message The message string to print.
             * @return true if error, warning or info level is enabled.
             */
            Bool PrintError(const String& message) const;

        protected:
            /**
             * @brief Print a string with level prefix.
             * @param prefix The level prefix string.
             * @param message The message string to print.
             */
            void PrintMessage(const String& prefix, const String& message) const;

            /** @brief The current level. */
            Level mLevel;
            /** @brief The indentation character. */
            Char mIndentChar;
            /** @brief The indentation width. */
            UInt32 mIndentWidth;
            /** @brief The section counter. */
            UInt32 mSection;
            /** @brief The indentation string cache. */
            String mIndentString;

            /** @brief The global prefix string. */
            String mGlobalPrefix;
            /** @brief The info prefix string. */
            String mInfoPrefix;
            /** @brief The warning prefix string. */
            String mWarningPrefix;
            /** @brief The error prefix string. */
            String mErrorPrefix;
        };
    }
}

#endif // __MURL_SYSTEM_CONSOLE_H__
