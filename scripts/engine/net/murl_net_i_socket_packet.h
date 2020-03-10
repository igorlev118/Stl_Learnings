// Copyright 2012-2014 Spraylight GmbH

#ifndef __MURL_NET_I_SOCKET_PACKET_H__
#define __MURL_NET_I_SOCKET_PACKET_H__

#include "murl_net_i_socket_address.h"
#include "murl_data.h"

namespace Murl
{
    namespace Net
    {
        /**
         * @ingroup MurlNetInterfaces
         * @interface ISocketPacket
         * @brief The socket packet interface.
         * Packets are used to transfer network data from and to the
         * Net::SocketClient and Net::SocketServer interfaces.
         */
        class ISocketPacket
        {
        public:
            /**
             * @brief Get the sender name.
             * @return The sender name.
             */
            virtual const String& GetSenderName() const = 0;

            /**
             * @brief Get the sender unique identifier.
             * @return The sender unique identifier.
             */
            virtual const String& GetUniqueIdentifier() const = 0;

            /**
             * @brief Get the sender address object.
             * @return The sender address object.
             */
            virtual ISocketAddressCPtr GetAddress() const = 0;

            /**
             * @brief Get the const sender data object.
             * @return The const sender data object.
             */
            virtual const Data& GetData() const = 0;
            /**
             * @brief Get the sender data object.
             * @return The sender data object.
             */
            virtual Data& GetData() = 0;

            /**
             * @brief Set the sender name.
             * @param senderName The sender name.
             */
            virtual void SetSenderName(const String& senderName) = 0;

            /**
             * @brief Set the sender unique identifier.
             * @param uniqueId The sender unique identifier.
             */
            virtual void SetUniqueIdentifier(const String& uniqueId) = 0;

            /**
             * @brief Set the sender address.
             * @param address The sender address.
             */
            virtual void SetAddress(ISocketAddressCPtr address) = 0;

            /**
             * @brief Set the sender data object.
             * @param data The sender data to copy.
             */
            virtual void SetData(const ConstData& data) = 0;

            /**
             * @brief Obtain the sender data object.
             * @param data The sender data object to obtain.
             */
            virtual void ObtainData(Data& data) = 0;

            /**
             * @brief Get the number of bytes to send.
             * @return The number of bytes to send.
             */
            virtual UInt64 GetBytesToSend() const = 0;
            /**
             * @brief Get the number of sent bytes.
             * @return The number of bytes to send.
             */
            virtual UInt64 GetBytesSent() const = 0;
            /**
             * @brief Get the number of bytes to receive.
             * @return The number of bytes to receive.
             */
            virtual UInt64 GetBytesToReceive() const = 0;
            /**
             * @brief Get the number of received bytes.
             * @return The number of received bytes.
             */
            virtual UInt64 GetBytesReceived() const = 0;

            /**
             * @brief Set the number of bytes to send.
             * @param numberOfBytes The number of bytes to send.
             */
            virtual void SetBytesToSend(UInt64 numberOfBytes) = 0;
            /**
             * @brief Set the number of sent bytes.
             * @param numberOfBytes The number of bytes to send.
             */
            virtual void SetBytesSent(UInt64 numberOfBytes) = 0;
            /**
             * @brief Set the number of bytes to receive.
             * @param numberOfBytes The number of bytes to receive.
             */
            virtual void SetBytesToReceive(UInt64 numberOfBytes) = 0;
            /**
             * @brief Set the number of received bytes.
             * @param numberOfBytes The number of received bytes.
             */
            virtual void SetBytesReceived(UInt64 numberOfBytes) = 0;

            virtual ~ISocketPacket() {}
        };

        /** @brief The ISocketPacket shared pointer type. */
        typedef SharedPointer<ISocketPacket> ISocketPacketPtr;

        /** @brief The ISocketPacket const shared pointer type. */
        typedef SharedPointer<ISocketPacket const> ISocketPacketCPtr;
        
    }
}

#endif  // __MURL_NET_I_SOCKET_PACKET_H__
