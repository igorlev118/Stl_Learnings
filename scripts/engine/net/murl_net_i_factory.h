// Copyright 2012-2014 Spraylight GmbH

#ifndef __MURL_NET_I_FACTORY_H__
#define __MURL_NET_I_FACTORY_H__

#include "murl_net_i_socket.h"
#include "murl_net_i_socket_address.h"

namespace Murl
{
    /**
     * @ingroup MurlNetNamespaces
     * @brief Networking classes and functions.
     */
    namespace Net
    {
        class ISocketClient;
        class ISocketPacket;
        class ISocketSender;
        class ISocketServer;

        /**
         * @ingroup MurlNetInterfaces
         * @interface IFactory
         * @brief The net IFactory interface.
         */
        class IFactory
        {
        public:
            /**
             * @brief Initialize the factory.
             * @return true if successful.
             */
            virtual Bool Init() = 0;
            /**
             * @brief Deinitialize the factory.
             * @return true if successful.
             */
            virtual Bool DeInit() = 0;

            /**
             * @brief Create a socket SharedPointer object.
             * @return The created socket SharedPointer object.
             */
            virtual ISocket::SharedPtr CreateSocket() = 0;
            /**
             * @brief Create a socket object.
             * @return The created socket object, or null if failed.
             */
            virtual ISocket* CreateRawSocket() = 0;
            /**
             * @brief Destroy a socket object.
             * @param socket A reference to the socket object pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            virtual Bool DestroyRawSocket(ISocket*& socket) = 0;

            /**
             * @brief Create a socket address SharedPointer object.
             * @return The created socket address SharedPointer object.
             */
            virtual ISocketAddressPtr CreateSocketAddress() = 0;
            /**
             * @brief Create a socket address object.
             * @return The created socket address object, or null if failed.
             */
            virtual ISocketAddress* CreateRawSocketAddress() = 0;
            /**
             * @brief Destroy a socket address object.
             * Alternatively the ISocketAddress object can be destroyed by using delete.
             * @param socketAddress A reference to the socket address object pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            virtual Bool DestroyRawSocketAddress(ISocketAddress*& socketAddress) = 0;

            /**
             * @brief Create a socket client object.
             * @param clientName The name of the client.
             * @param uniqueId The unique identifer of the client.
             * @return The created socket client object, or null if failed.
             */
            virtual ISocketClient* CreateSocketClient(const String& clientName, const String& uniqueId) = 0;
            /**
             * @brief Destroy a socket client object.
             * @param socketClient A reference to the socket client object pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            virtual Bool DestroySocketClient(ISocketClient*& socketClient) = 0;

            /**
             * @brief Create a socket packet object.
             * @return The created socket packet object, or null if failed.
             */
            virtual ISocketPacket* CreateSocketPacket() = 0;
            /**
             * @brief Destroy a socket packet object.
             * Alternatively the ISocketPacket object can be destroyed by using delete.
             * @param socketPacket A reference to the socket packet object pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            virtual Bool DestroySocketPacket(ISocketPacket*& socketPacket) = 0;

            /**
             * @brief Create a socket server object.
             * @param serverName The name of the server.
             * @param uniqueId The unique identifer of the server.
             * @return The created socket server object, or null if failed.
             */
            virtual ISocketServer* CreateSocketServer(const String& serverName, const String& uniqueId) = 0;
            /**
             * @brief Destroy a socket server object.
             * @param socketServer A reference to the socket server object pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            virtual Bool DestroySocketServer(ISocketServer*& socketServer) = 0;

        protected:
            virtual ~IFactory() {}
        };

        /**
         * @ingroup MurlNetClasses
         * @brief The StaticFactory class to create the IFactory object.
         * The StaticFactory is used by the engine's core only.
         */
        class StaticFactory
        {
        public:
            /**
             * @brief Create the net factory object.
             * @return The created net factory object, or null if failed.
             */
            static IFactory* CreateFactory();
            /**
             * @brief Destroy the net factory object.
             * @param factory A reference to the net factory pointer.
             *  After destruction the pointer is set to null.
             * @return true if successful.
             */
            static Bool DestroyFactory(IFactory*& factory);
        };
    }
}

#endif  // __MURL_NET_I_FACTORY_H__
