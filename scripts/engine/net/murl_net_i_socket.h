// Copyright 2012-2014 Spraylight GmbH

#ifndef __MURL_NET_I_SOCKET_H__
#define __MURL_NET_I_SOCKET_H__

#include "murl_data.h"
#include "murl_i_enums.h"
#include "murl_net_i_socket_address.h"

namespace Murl
{
    namespace System
    {
        class Socket;
    }

    namespace Net
    {
        /**
         * @ingroup MurlNetInterfaces
         * @interface ISocket
         * @brief The socket interface.
         * Several methods are blocking calls when waiting for network response.
         *
         * (!) Do not use this class directly in the logic code.
         * Use Net::ISocketClient and Net::ISocketServer interfaces instead.
         */
        class ISocket
        {
        public:
            /**
             * @brief Definition of the socket shared pointer.
             */
            typedef SharedPointer<ISocket> SharedPtr;

            /**
             * @brief Definition of the socket shared pointer array.
             */
            typedef Array<SharedPtr> PtrArray;

            /**
             * @brief Set the name of the socket.
             * @param name The name of the socket.
             */
            virtual void SetName(const String& name) = 0;

            /**
             * @brief Get the name of the socket.
             * @return The name of the socket.
             */
            virtual const String& GetName() const = 0;

            /**
             * @brief Set the unique identifier of the socket.
             * @param uniqueId The unique identifier of the socket.
             */
            virtual void SetUniqueIdentifier(const String& uniqueId) = 0;

            /**
             * @brief Get the unique identifier of the socket.
             * @return The unique identifier of the socket.
             */
            virtual const String& GetUniqueIdentifier() const = 0;

            /**
             * @brief Connects to a specified server address using tcp.
             * Enables reuse-address, keep-alive and tcp-no-delay socket option.
             * @param address The address of the server to connect.
             * @return true if successful.
             */
            virtual Bool ConnectTcp(ISocketAddressPtr address) = 0;

            /**
             * @brief Connects to a specified server address using tcp with non blocking.
             * Enables reuse-address, keep-alive, tcp-no-delay and non-blocking socket option.
             * @param address The address of the server to connect.
             * @return true if successful.
             */
            virtual Bool ConnectTcpNonBlocking(ISocketAddressPtr address) = 0;

            /**
             * @brief Confirm connect using tcp with non blocking.
             * When connection by ConnectTcpNonBlocking() a write select to the socket
             * indicates the connection and must be confirmed by calling this method.
             * @return true if connection established, false if connection error.
             */
            virtual Bool ConfirmConnectTcpNonBlocking() = 0;

            /**
             * @brief Connects to a specified server address using udp.
             * Enables tcp-no-delay socket option.
             * @param address The address of the server to connect.
             * @return true if successful.
             */
            virtual Bool ConnectUdp(ISocketAddressPtr address) = 0;

            /**
             * @brief Bind a listener to accept tcp connections.
             * Enables reuse-address and keep-alive socket option.
             * @param address The address to listen for incoming connections.
             *  The address specifies the port to listen and the ip-address to find
             *  the correct network adapter (any-address is listening on all adapters).
             * @param maxQueue The maximum length of the queue of pending connections.
             * @return true if successful.
             */
            virtual Bool BindTcpListen(ISocketAddressPtr address, UInt32 maxQueue = 5) = 0;

            /**
             * @brief Bind a listener to accept udp connections.
             * Enables reuse-address socket option.
             * @param address The address to listen for incoming connections.
             *  The address specifies the port to listen and the ip-address to find
             *  the correct network adapter (any-address is listening on all adapters).
             * @return true if successful.
             */
            virtual Bool BindUdpListen(ISocketAddressPtr address) = 0;

            /**
             * @brief Create a socket to send udp broadcast.
             * Enables reuse-address and broadcast socket option.
             * @return true if successful.
             */
            virtual Bool CreateUdpBroadcast() = 0;

            /**
             * @brief Disconnect the socket.
             * @return true if successful.
             */
            virtual Bool Disconnect() = 0;

            /**
             * @brief Check if the socket is connected.
             * @return true if the socket is connected.
             */
            virtual Bool IsConnected() const = 0;

            /**
             * @brief Check if the socket is connecting in non blocking mode.
             * @return true if the socket is connected in non blocking mode.
             */
            virtual Bool IsConnecting() const = 0;

            /**
             * @brief Accept connection on the socket.
             * Enables keep-alive and tcp-no-delay socket option after accept.
             * @param listenSocket The socket which is listening for the connection.
             * @return true if successful.
             */
            virtual Bool Accept(ISocket::SharedPtr listenSocket) = 0;

            /**
             * @brief Accept connection on the socket.
             * Enables keep-alive, tcp-no-delay and non-blocking socket option after accept.
             * @param listenSocket The socket which is listening for the connection.
             * @return true if successful.
             */
            virtual Bool AcceptNonBlocking(ISocket::SharedPtr listenSocket) = 0;

            /**
             * @brief Create a socket pair ready to communicate.
             * @param pairSocket The socket to connect with this socket.
             * @return true if successful.
             */
            virtual Bool Pair(ISocket::SharedPtr pairSocket) = 0;

            /**
             * @brief Wait for ready to read and write sockets with timeout.
             * @param readSockets Array of read sockets to wait for.
             * @param writeSockets Array of write sockets to wait for.
             * @param timeout The maximum time to wait in seconds, -1 for no timeout.
             * @return The number of selected sockets, zero if the timeout
             * was reached or -1 if select failed.
             */
            virtual SInt32 Select(PtrArray& readSockets, PtrArray& writeSockets, Double timeout) = 0;

            /**
             * @brief Check if the socket was read selected during the last Select().
             * The select status is valid until the next call of Select() or
             * the socket is closed due to errors or Destroy() is called.
             * @return true if the socket was read selected during the last Select().
             */
            virtual Bool IsReadSelected() const = 0;
            /**
             * @brief Check if the socket was write selected during the last Select().
             * The select status is valid until the next call of Select() or
             * the socket is closed due to errors or Destroy() is called.
             * @return true if the socket was write selected during the last Select().
             */
            virtual Bool IsWriteSelected() const = 0;

            /**
             * @brief Receive data from the socket.
             * @param data The data object to store the incoming data.
             *  The data object's byte size is the maximum number of bytes to receive.
             *  If the data object is empty a size of 1500 bytes is reserved internally.
             * @return true if successful.
             *  The data object is resized to the number of bytes received,
             *  otherwise if receive failed the data object is empty.
             */
            virtual Bool Receive(Data& data) = 0;

            /**
             * @brief Send the entire data to the socket.
             * @param data The data to send.
             * @return true if successful.
             */
            virtual Bool Send(const ConstData& data) = 0;

            /**
             * @brief Send data form a specified offset to the socket.
             * In non-blocking operation this method sends only a portion of data and
             * has to be called in a loop which allows to monitor the data transfer.
             * @param data The data to send.
             * @param byteOffset The data offset in number of bytes.
             * @return The number of bytes sent from the offset,
             *  zero if the data is empty or the data offset is invalid,
             *  a negative return value if a socket error occurs.
             */
            virtual SInt64 Send(const ConstData& data, UInt64 byteOffset) = 0;

            /**
             * @brief Receive data and the sender address from the socket.
             * This is typically used by sockets connected with ConnectUdpListen().
             * @param data The data object to store the incoming data.
             *  The data object's byte size is the maximum number of bytes to receive.
             *  If the data object is empty a size of 1500 bytes is reserved internally.
             * @param address The sender address return value.
             * @return true if successful.
             *  The data object is resized to the number of bytes received,
             *  otherwise if receive failed the data object is empty.
             */
            virtual Bool ReceiveFrom(Data& data, ISocketAddressPtr address) = 0;

            /**
             * @brief Send the entire data to a specified address.
             * This is typically used by sockets connected with ConnectUdpBroadcast().
             * @param data The data to send.
             * @param address The address to send the data.
             * @return true if successful.
             */
            virtual Bool SendTo(const ConstData& data, ISocketAddressPtr address) = 0;

            /**
             * @brief Send data form a specified offset to a specified address.
             * In non-blocking operation this method sends only a portion of data and
             * has to be called in a loop which allows to monitor the data transfer.
             * @param data The data to send.
             * @param byteOffset The data offset in number of bytes.
             * @param address The address to send the data.
             * @return The number of bytes sent from the offset,
             *  zero if the data is empty or the data offset is invalid or the address is null,
             *  a negative return value if a socket error occurs.
             */
            virtual SInt64 SendTo(const ConstData& data, UInt64 byteOffset, ISocketAddressPtr address) = 0;

            /**
             * @brief Get the system socket object.
             * @return The system socket object.
             */
            virtual System::Socket& GetSystemSocket() = 0;
            /**
             * @brief Get the const system socket object.
             * @return The const system socket object.
             */
            virtual const System::Socket& GetSystemSocket() const = 0;

            virtual ~ISocket() {}
        };
    }
}

#endif  // __MURL_NET_I_SOCKET_H__
