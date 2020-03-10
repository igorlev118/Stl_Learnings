// Copyright 2012-2014 Spraylight GmbH

#ifndef __MURL_NET_I_SOCKET_SERVER_H__
#define __MURL_NET_I_SOCKET_SERVER_H__

#include "murl_net_i_socket_address.h"
#include "murl_net_i_socket_packet.h"
#include "murl_change_controller.h"

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
         * @interface ISocketServer
         * @brief The socket server thread interface.
         * The socket server implements a thread for network communication
         * which can be commanded by a logic implementation.
         *
         * The server supports sending broadcasts for client connections
         * and can hold connections to any number of ISocketClients.
         *
         * If the server is connected to a client, data can be transfered
         * from an to the client simultaneously via the network.
         */
        class ISocketServer
        {
        public:
            /**
             * @brief Get the name of the server.
             * @return The name of the server.
             */
            virtual const String& GetServerName() const = 0;

            /**
             * @brief Get the unique identifier of the server.
             * @return The unique identifier of the server.
             */
            virtual const String& GetUniqueIdentifier() const = 0;

            /**
             * @brief Start listening for incoming ISocketClient connections.
             * @param address The address to bind for listening.
             * @return true if passing the address was successful.
             */
            virtual Bool StartListen(ISocketAddressCPtr address) = 0;
            /**
             * @brief Stop listening for incomming ISocketClient connections.
             * @return true if passing the command was successful.
             */
            virtual Bool StopListen() = 0;

            /**
             * @brief Start sending broadcasts.
             * Before starting broadcasts the listen address must be set by StartListen().
             * @param address The address to send the broadcast.
             * @return true if passing the address was successful.
             */
            virtual Bool StartSendBroadcast(ISocketAddressCPtr address) = 0;
            /**
             * @brief Stop sending broadcasts.
             * @return true if passing the address was successful.
             */
            virtual Bool StopSendBroadcast() = 0;
            /**
             * @brief Set the broacast clock time.
             * The default clock time is 1 second.
             * Every clockTime seconds one broadcast packet is sent.
             * @param clockTime The broacast send clock time in seconds.
             */
            virtual void SetBroadcastClock(Double clockTime) = 0;

            /**
             * @brief Get the maximum number of accept packets the thread can store.
             * The default accept packets queue length is 50.
             * @return The maximum number of accept packets the thread can store.
             */
            virtual UInt32 GetMaxAcceptQueueLength() const = 0;
            /**
             * @brief Set the maximum number of accept packet the thread can store.
             * If the given maximum length is smaller than the current maximum length,
             * the accept packet queue is cleared.
             * If the accept packet queue is full, the client is denied.
             * @param maxLength The maximum number of accept packets the thread can store.
             */
            virtual void SetMaxAcceptQueueLength(UInt32 maxLength) = 0;
            /**
             * @brief Clear the accept packets queue.
             */
            virtual void ClearAcceptQueue() = 0;

            /**
             * @brief Get an accept packet from a client.
             * If the packet returned is not null, the logic can decide
             * depending on the packet information if the server should
             * accept or deny the client.
             * The logic must call AcceptClient() or DenyClient() to remove the
             * packet from the accept queue.
             * @return An accept packet from a client or null
             *  if the accept packet queue is empty.
             */
            virtual ISocketPacketCPtr GetClientToAccept() = 0;
            /**
             * @brief Accept a client connection.
             * @param clientToAccept The accept packet received by GetClientToAccept().
             * @return true if accepting the client was successful.
             */
            virtual Bool AcceptClient(ISocketPacketCPtr clientToAccept) = 0;
            /**
             * @brief Deny a client accept packet.
             * @param clientToDeny The accept packet received by GetClientToAccept().
             * @return true if removing the packet from the accept queue was successful.
             */
            virtual Bool DenyClient(ISocketPacketCPtr clientToDeny) = 0;

            /**
             * @brief Get the number of connected clients.
             * The number of connected clients includes all accepted clients plus the
             * number of clients waiting in the accept queue.
             * @return The number of connected clients.
             */
            virtual UInt32 GetNumberOfConnectedClients() const = 0;
            /**
             * @brief Check if the accepted clients list has changed.
             * @param inspector The inspector to check.
             * @return true if the accepted clients list has changed.
             */
            virtual Bool HasAcceptedClientsChanged(ChangeInspector& inspector) const = 0;
            /**
             * @brief Get the unique identifiers of all accepted clients.
             * Use HasAcceptedClientsChanged() to check for changes.
             * @param clientIds The identifier string array return value.
             */
            virtual void GetAcceptedClients(StringArray& clientIds) const = 0;
            /**
             * @brief Get detailed information of a connected client.
             * The GetAcceptedClients() method returns all accepted client identifiers.
             * @param clientId The unique identifier of the client.
             * @return The client information packet or null
             *  if the identifier is not found.
             */
            virtual ISocketPacketPtr GetClientInfo(const String& clientId) const = 0;
            /**
             * @brief Disconnect a client.
             * The GetAcceptedClients() method returns all accepted client identifiers.
             * @param clientId The unique identifier of the client.
             * @return true if passing the command was successful,
             *  false if the client is not found.
             */
            virtual Bool Disconnect(const String& clientId) = 0;

            /**
             * @brief Send data to a client.
             * The GetAcceptedClients() method returns all accepted client identifiers.
             * @param data The data object to send.
             * @param clientId The unique identifier of the client.
             * @return true if passing the data was successful, false if the
             *  client is not found.
             */
            virtual Bool Send(const ConstData& data, const String& clientId) = 0;

            /**
             * @brief Get the maximum number of received packets the thread can store.
             * The default received packets queue length is 50.
             * @return The maximum number of received packets the thread can store.
             */
            virtual UInt32 GetMaxReceiveQueueLength() const = 0;
            /**
             * @brief Set the maximum number of received packet the thread can store.
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
             * @brief Get a received packet from a client.
             * The packet returned is removed from the received packets queue.
             * @return A received packet from a client or null
             *  if the received packets queue is empty.
             */
            virtual ISocketPacketPtr GetReceivedData() = 0;

            /**
             * @brief Set a message to send when a client to accept packet is received.
             * This is an optional feature for notifying a thread if necessary,
             * typically the app logic is checking GetClientToAccept() each tick.
             * @param messageQueue The message queue to post the message
             *  or null to disable posting (default).
             * @param messageId The id of the message to post.
             */
            virtual void SetReceivedClientToAcceptMessage(Util::MessageQueue* messageQueue, UInt32 messageId) = 0;
            /**
             * @brief Set a message to send when a client is disconnected.
             * This is an optional feature for notifying a thread if necessary,
             * typically the app logic is checking HasAcceptedClientsChanged() each tick.
             * @param messageQueue The message queue to post the message
             *  or null to disable posting (default).
             * @param messageId The id of the message to post.
             */
            virtual void SetReceivedClientDisconnectMessage(Util::MessageQueue* messageQueue, UInt32 messageId) = 0;
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
            virtual ~ISocketServer() {}
        };
    }
}

#endif  // __MURL_NET_I_SOCKET_SERVER_H__
