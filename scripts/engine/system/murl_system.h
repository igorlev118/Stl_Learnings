// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_SYSTEM_H__
#define __MURL_SYSTEM_H__

#include "murl_string.h"

namespace Murl
{
    /**
     * @ingroup MurlSystemNamespaces
     * @brief System-specific classes and functions.
     * The system namespace implements access to the operation system
     * and C-runtime library to ensure cross-platform compatibility.
     */
    namespace System
    {
        class Time;

        /**
         * @addtogroup MurlSystemFunctions
         * @brief Basic system functions.
         * @{
         */

        /**
         * @brief Initialize the System module.
         * This method is called by the engine's Murl::Engine::Init() method.
         * @return true if successful.
         */
        Bool Init();
        /**
         * @brief Deinitialize the System module.
         * This method is called by the engine's Murl::Engine::DeInit() method.
         * @return true if successful.
         */
        Bool DeInit();

        /**
         * @brief Sleep for a specified time.
         * @param sleepTime The time to sleep.
         */
        void Sleep(const Time& sleepTime);

        /**
         * @brief Check for a little endian host.
         * @return true if the host is a little endian machine.
         */
        Bool IsHostLittleEndian();
        /**
         * @brief Check for a big endian host.
         * @return true if the host is a big endian machine.
         */
        Bool IsHostBigEndian();

        /**
         * @brief Swap the endianness of a 16 bit integer value.
         * @param value The integer to convert.
         * @return The byte-swapped integer.
         */
        UInt16 SwapEndianness(UInt16 value);
        /**
         * @brief Swap the endianness of a 32 bit integer value.
         * @param value The integer to convert.
         * @return The byte-swapped integer.
         */
        UInt32 SwapEndianness(UInt32 value);
        /**
         * @brief Swap the endianness of a 64 bit integer value.
         * @param value The integer to convert.
         * @return The byte-swapped integer.
         */
        UInt64 SwapEndianness(UInt64 value);

        /**
         * @brief Convert a big endian ordered 16 bit integer
         *  to host byte ordering.
         * @param value The big endian integer to convert.
         * @return The integer in host byte ordering.
         */
        UInt16 BigEndianToHost(UInt16 value);
        /**
         * @brief Convert a little endian ordered 16 bit integer
         *  to host byte ordering.
         * @param value The little endian integer to convert.
         * @return The integer in host byte ordering.
         */
        UInt16 LittleEndianToHost(UInt16 value);

        /**
         * @brief Convert a host ordered 16 bit integer
         *  to big endian byte ordering.
         * @param value The host integer to convert.
         * @return The integer in big endian byte ordering.
         */
        UInt16 HostToBigEndian(UInt16 value);
        /**
         * @brief Convert a host ordered 16 bit integer
         *  to little endian byte ordering.
         * @param value The host integer to convert.
         * @return The integer in little endian byte ordering.
         */
        UInt16 HostToLittleEndian(UInt16 value);

        /**
         * @brief Convert a big endian ordered 32 bit integer
         *  to host byte ordering.
         * @param value The big endian integer to convert.
         * @return The integer in host byte ordering.
         */
        UInt32 BigEndianToHost(UInt32 value);
        /**
         * @brief Convert a little endian ordered 32 bit integer
         *  to host byte ordering.
         * @param value The little endian integer to convert.
         * @return The integer in host byte ordering.
         */
        UInt32 LittleEndianToHost(UInt32 value);

        /**
         * @brief Convert a host ordered 32 bit integer
         *  to big endian byte ordering.
         * @param value The host integer to convert.
         * @return The integer in big endian byte ordering.
         */
        UInt32 HostToBigEndian(UInt32 value);
        /**
         * @brief Convert a host ordered 32 bit integer
         *  to little endian byte ordering.
         * @param value The host integer to convert.
         * @return The integer in little endian byte ordering.
         */
        UInt32 HostToLittleEndian(UInt32 value);

        /**
         * @brief Convert a big endian ordered 64 bit integer
         *  to host byte ordering.
         * @param value The big endian integer to convert.
         * @return The integer in host byte ordering.
         */
        UInt64 BigEndianToHost(UInt64 value);
        /**
         * @brief Convert a little endian ordered 64 bit integer
         *  to host byte ordering.
         * @param value The little endian integer to convert.
         * @return The integer in host byte ordering.
         */
        UInt64 LittleEndianToHost(UInt64 value);

        /**
         * @brief Convert a host ordered 64 bit integer
         *  to big endian byte ordering.
         * @param value The host integer to convert.
         * @return The integer in big endian byte ordering.
         */
        UInt64 HostToBigEndian(UInt64 value);
        /**
         * @brief Convert a host ordered 64 bit integer
         *  to little endian byte ordering.
         * @param value The host integer to convert.
         * @return The integer in little endian byte ordering.
         */
        UInt64 HostToLittleEndian(UInt64 value);

        /**
         * @brief Get the absolute path of the currently running executable.
         * Platforms not supporting this will return an empty string.
         * @return The absolute path to the currently running executable.
         */
        String GetAbsolutePathOfCurrentExecutable();
        /**
         * @brief Get the fully qualified name of a command line executable.
         * @param path The path to the executable
         * @param name The name of the executable
         * @return The full path.
         */
        String GetNameOfShellExecutable(const String& path, const String& name);
        /**
         * @brief Get the fully qualified name of a GUI executable.
         * @param path The path to the executable
         * @param name The name of the executable
         * @return The full path.
         */
        String GetNameOfGuiExecutable(const String& path, const String& name);

        /**
         * @brief Demangle a RTTI name.
         *  Convert a RTTI name to a human readable string.
         * @code
         *  #include <typeinfo>
         *  String className = System::DemangleTypeName(typeid(MyClass).name());
         * @endcode
         * @param name The RTTI name to demangle.
         * @return The demangled name.
         */
        String DemangleTypeName(const Char* name);

        /** @} */
    }
}

#endif  // __MURL_SYSTEM_H__
