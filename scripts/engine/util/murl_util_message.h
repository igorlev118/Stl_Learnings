// Copyright 2012 Spraylight GmbH

#ifndef __MURL_UTIL_MESSAGE_H__
#define __MURL_UTIL_MESSAGE_H__

#include "murl_auto_pointer.h"
#include "murl_system_semaphore.h"

namespace Murl
{
    namespace Util
    {
        /**
         * @ingroup MurlUtilMessageClasses
         * @brief The message base class.
         * The Message class is used to send messages by the MessageQueue class.
         * The Message class can be sub-classed to add used defined members,
         * see MessageThread.
         *
         * To synchonize message delivery so called sync-messages are available:\n
         * The message sender waits until the message is delivered and processed.
         * The processing of a message ends when calling the Signal() method,
         * which is typically called by the message destructor.
         */
        class Message
        {
        public:
            /**
             * @brief Definition of the Message class auto pointer.
             */
            typedef AutoPointer<Message> AutoPtr;
            
            /**
             * @brief Enumeration of the message identifiers.
             */
            enum Id
            {
                /** @brief The used defined message identifier base. */
                ID_USER = 0,
                
                /** @brief The timeout message identifier. */
                ID_TIMEOUT = 0xfffffffd,
                /** @brief The quit message identifier. */
                ID_QUIT = 0xfffffffe,
                /** @brief The any message identifier. */
                ID_ANY = 0xffffffff
            };
            
            /**
             * @brief The constructor.
             * @param messageId The message identifier.
             */
            Message(UInt32 messageId);
            
            /**
             * @brief The destructor.
             * Calls Signal().
             */
            virtual ~Message();
            
            /**
             * @brief Get the message identifier.
             * @return The message identifier.
             */
            virtual UInt32 GetId() const;
            
            /**
             * @brief Set the sync-message semaphore.
             * For sending sync-messages a semaphore is used
             * to wait until the message is processed.
             * @param sync Pointer to the semaphore.
             * @return true if successful.
             */
            Bool SetSignal(System::Semaphore* sync);
            
            /**
             * @brief Signal the sync-message semaphore, which means
             *  the processing of the message is finished.
             * This is typically done at Message object destruction.
             * @return true if successful.
             */
            Bool Signal();
            
        protected:
            /** @brief The message identifier. */
            UInt32 mMessageId;
            
        private:
            /** @brief The sync-message semaphore. */
            System::Semaphore* mSyncSignal;
        };
    }
}

#endif // __MURL_UTIL_MESSAGE_H__
