// Copyright 2012-2014 Spraylight GmbH

#ifndef __MURL_SYSTEM_SOCKET_ADDRESS_H__
#define __MURL_SYSTEM_SOCKET_ADDRESS_H__

#include "murl_string.h"

namespace Murl
{
    namespace System
    {
        class SocketAddressHandle;

        /**
         * @ingroup MurlSystemClasses
         * @brief IPV4 socket address class.
         * Platform independent low-level abstraction of the Berkeley socket api.
         * Several methods are blocking calls when waiting for network response.
         *
         * (!) Do not use this class directly in the logic code.
         * Use Net::ISocketClient and Net::ISocketServer interfaces instead.
         */
        class SocketAddress
        {
        public:
            /**
             * @brief The default constructor.
             * Initializes with any ip-address, see SetToAnyAddress().
             */
            SocketAddress();
            /**
             * @brief The copy constructor.
             * @param socketAddress The SocketAddress object to copy.
             */
            SocketAddress(const SocketAddress& socketAddress);
            /**
             * @brief Assignment operator.
             * @param socketAddress The SocketAddress object to copy.
             * @return The object itself.
             */
            SocketAddress& operator=(const SocketAddress& socketAddress);

            /**
             * @brief Constructor setting the ip-address by SetHostName().
             * @param hostName The host name.
             */
            SocketAddress(const String& hostName);
            /**
             * @brief Constructor setting the ip-address by SetIpAddress().
             * @param ipAddress The ip-address in host format.
             */
            SocketAddress(UInt32 ipAddress);

            /**
             * @brief The destructor.
             */
            virtual ~SocketAddress();

            /**
             * @brief Set the ip-address.
             * The ip-address host format is 0xaabbccdd for "aaa.bbb.ccc.ddd".
             * @param ipAddress The ip-address in host format.
             * @return true if successful.
             */
            Bool SetIpAddress(UInt32 ipAddress);
            /**
             * @brief Set the port number.
             * @param portNumber The port number.
             * @return true if successful.
             */
            Bool SetPortNumber(UInt16 portNumber);

            /**
             * @brief Set to the any ip-address (0.0.0.0).
             * @return true if successful.
             */
            Bool SetToAnyAddress();
            /**
             * @brief Set to the broadcast ip-address (255.255.255.255).
             * @return true if successful.
             */
            Bool SetToBroadcastAddress();
            /**
             * @brief Set to the loopback ip-address (127.0.0.1).
             * @return true if successful.
             */
            Bool SetToLoopBackAddress();

            /**
             * @brief Set the ip-address by resolving a host name.
             *  An empty string resolves the local host.
             * @param hostName The host name.
             *  The host name can be specified by the domain name or
             *  the dot notation e.g. "127.0.0.1".
             *  If the host name is empty, the local ip-address is used.
             * @return The host name or an empty string if resolving failed.
             */
            String SetResolveHostName(const String& hostName);

            /**
             * @brief Get the ip-address.
             * The ip-address host format is 0xaabbccdd for "aaa.bbb.ccc.ddd".
             * @return The ip-address in host format.
             */
            UInt32 GetIpAddress() const;
            /**
             * @brief Get the port number.
             * @return The port number.
             */
            UInt16 GetPortNumber() const;
            /**
             * @brief Get the dot notation string of the ip-address.
             * @return The dot notation string of the ip-address.
             */
            String GetDotNotation() const;
            /**
             * @brief Get the dot notation string of the ip-address and the port.
             * @return The dot notation string of the ip-address and the port.
             */
            String GetDotPortNotation() const;
            /**
             * @brief Get the host name by resolving the ip-address.
             * @return The resolved host name or the dot notation if resolving failed.
             */
            String GetHostName() const;

            /**
             * @brief Get the ip-address in network format.
             * @return The ip-address in network format.
             */
            UInt32 GetNetworkIpAddress() const;
            /**
             * @brief Set the ip-address in network format.
             * @param networkIp The ip-address in network format.
             */
            void SetNetworkIpAddress(UInt32 networkIp);
            /**
             * @brief Get the port number in network format.
             * @return The port number in network format.
             */
            UInt16 GetNetworkPortNumber() const;
            /**
             * @brief Set the port number in network format.
             * @param networkPort The port number in network format.
             */
            void SetNetworkPortNumber(UInt16 networkPort);

        protected:
            /** The anonymous socket address handle for internal use only. */
            SocketAddressHandle* mHandle;
        };
    }
}

#endif  // __MURL_SYSTEM_SOCKET_ADDRESS_H__
