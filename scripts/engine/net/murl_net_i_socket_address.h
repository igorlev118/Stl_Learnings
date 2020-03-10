// Copyright 2012-2014 Spraylight GmbH

#ifndef __MURL_NET_I_SOCKET_ADDRESS_H__
#define __MURL_NET_I_SOCKET_ADDRESS_H__

#include "murl_shared_pointer.h"
#include "murl_string.h"

namespace Murl
{
    namespace System
    {
        class SocketAddress;
    }

    namespace Net
    {
        class ISocketAddress;
        /** @brief The ISocketAddress shared pointer type. */
        typedef SharedPointer<ISocketAddress> ISocketAddressPtr;
        /** @brief The ISocketAddress const shared pointer type. */
        typedef SharedPointer<ISocketAddress const> ISocketAddressCPtr;

        /**
         * @ingroup MurlNetInterfaces
         * @interface ISocketAddress
         * @brief The socket address interface.
         * GetIpAddress() and GetPortNumber() returns the values set by
         * SetIpAddress(), SetPortNumber(), SetAnyAddress(),
         * SetBroadcastAddress() and SetLoopbackAddress() only.
         *
         * The SetResolveHostName() method is safe to be used in the logic code.
         * The ip-address is evaluated later by MakeSystemAddress().
         *
         * GetHostName() returns the string set by SetResolveHostName() until
         * MakeSystemAddress() evaluates the ip-address, which replaces the
         * host name by the "real" name used for evaluation.
         * The Net::ISocketClient and Net::ISocketServer implementation makes copies
         * of all address objects, so that addresses passed to these classes are not
         * affected by this mechanism.
         *
         * (!) Do not use MakeSystemAddress() directly in the logic code,
         * this method will wait for network response and is intend for
         * internal socket implementation only.
         */
        class ISocketAddress
        {
        public:
            /**
             * @brief Get the ip-address.
             * The ip-address format is 0xaabbccdd for "aaa.bbb.ccc.ddd".
             * @return The ip-address.
             */
            virtual UInt32 GetIpAddress() const = 0;
            /**
             * @brief Get the port number.
             * @return The port number.
             */
            virtual UInt32 GetPortNumber() const = 0;
            /**
             * @brief Get the host name.
             * @return The host name.
             */
            virtual String GetHostName() const = 0;

            /**
             * @brief Get the dot notation string of the ip-address.
             * @return The dot notation string of the ip-address.
             */
            virtual String GetDotNotation() const = 0;
            /**
             * @brief Get the dot notation string of the ip-address and the port.
             * @return The dot notation string of the ip-address and the port.
             */
            virtual String GetDotPortNotation() const = 0;

            /**
             * @brief Set the ip-address.
             * Additionally the host name is set to the dot-notation of the ip-address.
             * The ip-address format is 0xaabbccdd for "aaa.bbb.ccc.ddd".
             * @param ipAddress The ip-address.
             */
            virtual void SetIpAddress(UInt32 ipAddress) = 0;
            /**
             * @brief Set the port number.
             * @param portNumber The port number.
             */
            virtual void SetPortNumber(UInt32 portNumber) = 0;

            /**
             * @brief Set to the any ip-address (0.0.0.0).
             * This is the default address for new address objects.
             */
            virtual void SetAnyAddress() = 0;
            /**
             * @brief Set to the broadcast ip-address (255.255.255.255).
             */
            virtual void SetBroadcastAddress() = 0;
            /**
             * @brief Set to the loopback ip-address (127.0.0.1).
             */
            virtual void SetLoopbackAddress() = 0;

            /**
             * @brief Copy the address information.
             * @param address The source address object.
             */
            virtual void CopyAddress(ISocketAddressCPtr address) = 0;

            /**
             * @brief Set the host name for resolving.
             *  An empty string resolves the local host.
             * @param hostName The host name.
             *  The host name can be specified by the domain name or
             *  the dot notation e.g. "127.0.0.1".
             *  If the host name is empty, the local ip-address is used.
             */
            virtual void SetResolveHostName(const String& hostName = String()) = 0;

            /**
             * @brief Get the system socket address object.
             * (!) Do not use MakeSystemAddress() directly in the logic code,
             * this method will wait for network response and is intend for
             * internal socket implementation only.
             * @return The system socket address object.
             */
            virtual System::SocketAddress& MakeSystemAddress() = 0;

            virtual ~ISocketAddress() {}
        };
    }
}

#endif  // __MURL_NET_I_SOCKET_ADDRESS_H__
