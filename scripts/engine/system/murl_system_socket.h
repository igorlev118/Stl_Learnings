// Copyright 2012-2013 Spraylight GmbH

#ifndef __MURL_SYSTEM_SOCKET_H__
#define __MURL_SYSTEM_SOCKET_H__

#include "murl_system_socket_address.h"
#include "murl_system_time.h"
#include "murl_i_enums.h"
#include "murl_data.h"

namespace Murl
{
    namespace System
    {
        class SocketHandle;

        class Socket;
        /**
         * @ingroup MurlSystemClasses
         * @brief Definition of the socket array.
         */
        typedef Array<Socket*> SocketArray;

        /**
         * @ingroup MurlSystemClasses
         * @brief IPV4 socket class.
         * Platform independent low-level abstraction of the Berkeley socket api.
         * Several methods are blocking calls when waiting for network response.
         *
         * (!) Do not use this class directly in the logic code.
         * Use Net::ISocketClient and Net::ISocketServer interfaces instead.
         */
        class Socket : NonCopyable
        {
        public:
            /**
             * @brief The default constructor.
             */
            Socket();
            /**
             * @brief The destructor.
             */
            virtual ~Socket();

            /**
             * @brief Create the socket by protocol name.
             * @param protocolName The protocol name. If the protocol name
             * is "udp" a datagram socket is created, otherwise e.g.
             * for "tcp" a stream socket is created.
             * @return true is successful.
             */
            Bool Create(const String& protocolName);
            /**
             * @brief Destroy the socket.
             * @return true is successful.
             */
            Bool Destroy();
            /**
             * @brief Check if the socket is created.
             * @return true if the socket is created.
             */
            Bool IsCreated() const;

            /**
             * @brief Check and clear the last socket error.
             * This method does not set or clear the GetLastError() code.
             * @return true if the socket has an error.
             */
            Bool HasError();

            /**
             * @brief Enable/disable the tcp-no-delay socket option.
             * @param enable The enabled state.
             * @return true if successful.
             */
            Bool EnableTcpNoDelay(Bool enable);
            /**
             * @brief Enable/disable the reuse-address socket option.
             * @param enable The enabled state.
             * @return true if successful.
             */
            Bool EnableReuseAddress(Bool enable);
            /**
             * @brief Enable/disable the keep-alive socket option.
             * @param enable The enabled state.
             * @return true if successful.
             */
            Bool EnableKeepAlive(Bool enable);
            /**
             * @brief Enable/disable the Broadcast socket option.
             * @param enable The enabled state.
             * @return true if successful.
             */
            Bool EnableBroadcast(Bool enable);
            /**
             * @brief Enable/disable the non-blocking socket option.
             * @param enable The enabled state.
             * @return true if successful.
             */
            Bool EnableNonBlocking(Bool enable);

            /**
             * @brief Bind the socket to an address.
             * @param address The address to bind to.
             * @return true if successful.
             */
            Bool Bind(const SocketAddress& address);

            /**
             * @brief Connect the socket to an address.
             * @param address The address to connect to.
             * @return true if successful.
             */
            Bool Connect(const SocketAddress& address);

            /**
             * @brief Listen to the socket.
             * @param maxQueue The maximum length of the queue of pending connections.
             * @return true if successful.
             */
            Bool Listen(UInt32 maxQueue);

            /**
             * @brief Accept connection on the socket.
             * @param listenSocket The socket which is listening for the connection.
             * @return true if successful.
             */
            Bool Accept(const Socket& listenSocket);

            /**
             * @brief Create a socket pair ready to communicate.
             * @param pairSocket The socket to connect with this socket.
             * @return true if successful.
             */
            Bool Pair(Socket& pairSocket);

            /**
             * @brief Wait for ready to read and write sockets with timeout.
             * @param readSockets Array of read sockets to wait for.
             * @param writeSockets Array of write sockets to wait for.
             * @param timeout The maximum time to wait, set to
             *  System::Time::Infinite() for blocking operation.
             * @return The number of selected sockets, zero if the timeout
             * was reached or -1 if select failed.
             */
            SInt32 Select(SocketArray& readSockets, SocketArray& writeSockets, const Time& timeout);

            /**
             * @brief Check if the socket was read selected during the last Select().
             * The select status is valid until the next call of Select() or
             * the socket is closed due to errors or Destroy() is called.
             * @return true if the socket was read selected during the last Select().
             */
            Bool IsReadSelected() const;
            /**
             * @brief Check if the socket was write selected during the last Select().
             * The select status is valid until the next call of Select() or
             * the socket is closed due to errors or Destroy() is called.
             * @return true if the socket was write selected during the last Select().
             */
            Bool IsWriteSelected() const;

            /**
             * @brief Receive data from the socket.
             * @param data The data object to store the incoming data.
             *  The data object's byte size is the maximum number of bytes to receive.
             *  If the data object is empty a size of 1500 bytes is reserved internally.
             * @return true if successful.
             *  The data object is resized to the number of bytes received,
             *  otherwise if receive failed the data object is empty.
             */
            Bool Receive(Data& data);
            /**
             * @brief Send data form a specified offset to the socket.
             * In non-blocking operation this method sends only a portion of data and
             * has to be called in a loop which allows to monitor the data transfer.
             * @param data The data to send.
             * @param byteOffset The data offset in number of bytes.
             * @return The number of bytes sent from the offset,
             *  zero if the data is empty or the data offset is invalid,
             *  -1 if a socket error occurs.
             */
            SInt64 Send(const ConstData& data, UInt64 byteOffset);

            /**
             * @brief Receive data and the sender address from the socket.
             * @param data The data object to store the incoming data.
             *  The data object's byte size is the maximum number of bytes to receive.
             *  If the data object is empty a size of 1500 bytes is reserved internally.
             * @param address The sender address return value.
             * @return true if successful.
             *  The data object is resized to the number of bytes received,
             *  otherwise if receive failed the data object is empty.
             */
            Bool ReceiveFrom(Data& data, SocketAddress& address);
            /**
             * @brief Send data form a specified offset to a specified address.
             * In non-blocking operation this method sends only a portion of data and
             * has to be called in a loop which allows to monitor the data transfer.
             * @param data The data to send.
             * @param byteOffset The data offset in number of bytes.
             * @param address The address to send the data.
             * @return The number of bytes sent from the offset,
             *  zero if the data is empty or the data offset is invalid,
             *  -1 if a socket error occurs.
             */
            SInt64 SendTo(const ConstData& data, UInt64 byteOffset, const SocketAddress& address);

            /**
             * @brief Get the address of the socket.
             * @return The address object of the socket.
             */
            const SocketAddress& GetAddress() const;

            /**
             * @brief Get the last socket error code.
             * When calling a socket method the error code is set to
             * the result of the operation performed by the method.
             * @return The last socket error code.
             */
            IEnums::SocketError GetLastError() const;

        protected:
            /**
             * @brief Verify if the socket is created and
             * set the corresponding socket error code.
             * @return true if the socket is created.
             */
            Bool VerifyCreated();
            /**
             * @brief Verify if the socket is not created and
             * set the corresponding socket error code.
             * @return true if the socket is not created.
             */
            Bool VerifyNotCreated();
            /**
             * @brief Set the socket error code.
             * @param socketError The socket error code.
             * @param reason The description for the reason.
             */
            void SetLastError(IEnums::SocketError socketError, const String& reason);
            /**
             * @brief Close the socket.
             */
            void Close();

            /** The anonymous socket handle for internal use only. */
            SocketHandle* mHandle;
        };
    }
}

#endif  // __MURL_SYSTEM_SOCKET_H__
