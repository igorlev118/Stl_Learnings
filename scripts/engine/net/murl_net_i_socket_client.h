// Copyright 2012-2014 Spraylight GmbH

#ifndef __MURL_NET_I_SOCKET_CLIENT_H__
#define __MURL_NET_I_SOCKET_CLIENT_H__

#include "murl_net_i_socket_address.h"
#include "murl_net_i_socket_packet.h"

namespace Murl
{
    namespace Util
    {
        class MessageQueue;
    }

    namespace Net
    {
        /**
         * @ingroup MurlNetInterfaces
         * @interface ISocketClient
         * @brief The socket client thread interface.
         * The socket client implements a thread for network communication
         * which can be commanded by a logic implementation.
         *
         * The client can connect to an ISocketServer either via listening
         * for broadcasts or by specifying an address directly.
         *
         * If the client is connected to a server, data can be transfered
         * from an to the server simultaneously via the network.
         */
        class ISocketClient
        {
        public:
            /**
             * @brief Get the name of the client.
             * @return The name of the client.
             */
            virtual const String& GetClientName() const = 0;
            /**
             * @brief Get the unique identifier of the client.
             * @return The unique identifier of the client.
             */
            virtual const String& GetUniqueIdentifier() const = 0;

            /**
             * @brief Start listening for broadcasts from an ISocketServer.
             * @param address The address to bind for listening.
             * @return true if passing the address was successful or
             *  the thread is already listening for broadcasts.
             */
            virtual Bool StartListenBroadcast(ISocketAddressCPtr address) = 0;
            /**
             * @brief Stop listening for broadcasts from an ISocketServer.
             * Stop listening for broadcasts clears the broadcast packet queue.
             * @return true if passing the command was successful or
             *  the thread is not listening for broadcasts.
             */
            virtual Bool StopListenBroadcast() = 0;
            /**
             * @brief Check if the thread is listening for braodcasts.
             * @return true if the thread is listening for braodcasts.
             */
            virtual Bool IsListenBroadcast() const = 0;

            /**
             * @brief Get the maximum number of broadcast packets the thread can store.
             * The default broadcast packets queue length is 10.
             * @return The maximum number of broadcast packets the thread can store.
             */
            virtual UInt32 GetMaxBroadcastQueueLength() const = 0;
            /**
             * @brief Set the maximum number of broadcast packet the thread can store.
             * If the given maximum length is smaller than the current maximum length,
             * the broadcast packet queue is cleared.
             * If the broadcast packet queue is full, the oldest packet is discarded.
             * @param maxLength The maximum number of broadcast packets the thread can store.
             */
            virtual void SetMaxBroadcastQueueLength(UInt32 maxLength) = 0;
            /**
             * @brief Clear the incoming boradcast packets queue.
             */
            virtual void ClearBroadcastQueue() = 0;

            /**
             * @brief Get a broadcast packet from a server.
             * If the packet returned is not null, the logic can decide
             * depending on the packet information if the client should
             * accept or deny the server.
             * The logic must call AcceptServer() or DenyServer() to remove the
             * packet from the broadcast queue.
             * @return A broadcast packet from a server or null
             *  if the broadcast packet queue is empty.
             */
            virtual ISocketPacketCPtr GetServerBroadcast() = 0;
            /**
             * @brief Accept a server connection.
             * When connecting to the server was successful, listening for broadcasts
             * is stopped and the broadcast packet queue is cleared.
             * @param serverBroadcast The broadcast packet received by GetServerBroadcast().
             * @return true if accepting the server was successful.
             */
            virtual Bool AcceptServer(ISocketPacketCPtr serverBroadcast) = 0;
            /**
             * @brief Deny a server broadcast packet.
             * @param serverBroadcast The broadcast packet received by GetServerBroadcast().
             * @return true if removing the packet from the broadcast queue was successful.
             */
            virtual Bool DenyServer(ISocketPacketCPtr serverBroadcast) = 0;

            /**
             * @brief Connect to a server using an address directly.
             * The parameters name and unique identifier of the server must not be
             * the real server information, these values are simply stored in the
             * received packets to help identifying the sender.
             * When connecting to the server was successful, listening for broadcasts
             * is stopped and the broadcast packet queue is cleared.
             * @param address The server address to connect to.
             * @param name The name of the server.
             * @param uniqueId The unique identifier of the server.
             * @return true if passing the command was successful.
             */
            virtual Bool ConnectToServer(ISocketAddressCPtr address,
                                         const String& name, const String& uniqueId) = 0;
            /**
             * @brief Disconnect from the server.
             * @return true if passing the command was successful.
             */
            virtual Bool DisconnectServer() = 0;
            /**
             * @brief Check if the client is connected to a server or connecting
             *  to the server is in progress.
             * @return true if the client is connected to a server or connecting
             *  to the server is in progress.
             */
            virtual Bool IsConnectedOrConnecting() const = 0;
            /**
             * @brief Check if the client is connected to a server.
             * @return true if the client is connected to a server.
             */
            virtual Bool IsConnected() const = 0;

            /**
             * @brief Get detailed information of a connected server.
             * @return The server information packet.
             */
            virtual ISocketPacketPtr GetServerInfo() const = 0;

            /**
             * @brief Send data to the server.
             * @param data The data object to send.
             * @return true if passing the data was successful, false if the
             *  client is not connected.
             */
            virtual Bool Send(const ConstData& data) = 0;

            /**
             * @brief Get the maximum number of received packets the thread can store.
             * The default received packets queue length is 20.
             * @return The maximum number of received packets the thread can store.
             */
            virtual UInt32 GetMaxReceiveQueueLength() const = 0;
            /**
             * @brief Set the maximum number of received packet the thread can store.
             * Setting the maximum length clears the received packet queue.
             * If the given maximum length is smaller than the current maximum length,
             * the received packet queue is cleared.
             * If the received packet queue is full, the oldest packet is discarded.
             * @param maxLength The maximum number of received packets the thread can store.
             */
            virtual void SetMaxReceiveQueueLength(UInt32 maxLength) = 0;
            /**
             * @brief Clear the received packets queue.
             */
            virtual void ClearReceiveQueue() = 0;

            /**
             * @brief Get a received packet from a server.
             * The packet returned is removed from the received packets queue.
             * @return A received packet from a server or null
             *  if the received packets queue is empty.
             */
            virtual ISocketPacketPtr GetReceivedData() = 0;

            /**
             * @brief Set a message to send when a broadcast packet is received.
             * This is an optional feature for notifying a thread if necessary,
             * typically the app logic is checking GetServerBroadcast() each tick.
             * @param messageQueue The message queue to post the message
             *  or null to disable posting (default).
             * @param messageId The id of the message to post.
             */
            virtual void SetReceivedBroadcastMessage(Util::MessageQueue* messageQueue, UInt32 messageId) = 0;
            /**
             * @brief Set a message to send when the client is disconnected.
             * This is an optional feature for notifying a thread if necessary,
             * typically the app logic is checking IsConnected() each tick.
             * @param messageQueue The message queue to post the message
             *  or null to disable posting (default).
             * @param messageId The id of the message to post.
             */
            virtual void SetReceivedDisconnectMessage(Util::MessageQueue* messageQueue, UInt32 messageId) = 0;
            /**
             * @brief Set a message to send when a data packet is received.
             * This is an optional feature for notifying a thread if necessary,
             * typically the app logic is checking GetReceivedData() each tick.
             * @param messageQueue The message queue to post the message
             *  or null to disable posting (default).
             * @param messageId The id of the message to post.
             */
            virtual void SetReceivedDataMessage(Util::MessageQueue* messageQueue, UInt32 messageId) = 0;

        protected:
            virtual ~ISocketClient() {}
        };
    }
}

#endif  // __MURL_NET_I_SOCKET_CLIENT_H__
