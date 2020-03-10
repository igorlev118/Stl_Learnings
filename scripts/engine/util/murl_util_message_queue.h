// Copyright 2012-2013 Spraylight GmbH

#ifndef __MURL_UTIL_MESSAGE_QUEUE_H__
#define __MURL_UTIL_MESSAGE_QUEUE_H__

#include "murl_util_message.h"
#include "murl_system_mutex.h"
#include "murl_array.h"

namespace Murl
{
    namespace Util
    {
        /**
         * @ingroup MurlUtilMessageClasses
         * @brief The message queue class is used to send
         * and wait for Message objects, see MessageThread.
         */
        class MessageQueue
        {
        public:
            /**
             * @brief The default constructor.
             * Set the message queue length to 1000.
             */
            MessageQueue();

            /**
             * @brief The destructor.
             */
            virtual ~MessageQueue();

            /**
             * @brief Enumeration of the message queue results.
             */
            enum Result
            {
                /** @brief Receiving a message failed. */
                FAILED = 0,
                /** @brief Received a message. */
                RECEIVED = 1,
                /** @brief Timeout receiving a message. */
                TIMEOUT = 2,
                /** @brief Received the quit message. */
                QUIT = 3
            };

            /**
             * @brief Get the maximum number of messages the queue can store.
             * The default message queue length is 1000.
             * @return The maximum number of messages the queue can store.
             */
            UInt32 GetMaxMessageQueueLength() const;

            /**
             * @brief Set the maximum number of messages the queue can store.
             * @param maxLength The maximum number of messages the queue can store.
             */
            void SetMaxMessageQueueLength(UInt32 maxLength);

            /**
             * @brief Clear the message queue.
             */
            void ClearMessageQueue();

            /**
             * @brief Add a message to the message queue.
             * @param message The message to send.
             * @return true if successful,
             * false if the maximum message queue length is reached.
             */
            Bool SendMessage(Message::AutoPtr message);

            /**
             * @brief Add a message the the message queue and wait until the
             * message is delivered and processed, see Message.
             * @param message The message to send.
             * @return true if successful,
             * false if the maximum message queue length is reached.
             */
            Bool SendSyncMessage(Message::AutoPtr message);

            /**
             * @brief Wait for a message.
             * @param message The message return value.
             *  The message returned is removed from the message queue.
             * @param msgIdStart Message identifier range start.
             *  Use Message::ID_ANY to receive any message (set msgIdEnd to zero).
             * @param msgIdEnd Message identifier range end.
             * @return The message queue result.
             */
            Result WaitMessage(Message::AutoPtr& message, UInt32 msgIdStart, UInt32 msgIdEnd);

            /**
             * @brief Wait for a message with time out.
             * @param message The message return value.
             *  The message returned is removed from the message queue.
             * @param timeout The maximum time to wait.
             * @param msgIdStart Message identifier range start.
             *  Use Message::ID_ANY to receive any message (set msgIdEnd to zero).
             * @param msgIdEnd Message identifier range end.
             * @return The message queue result.
             */
            Result WaitMessage(Message::AutoPtr& message, const System::Time& timeout,
                               UInt32 msgIdStart, UInt32 msgIdEnd);

            /**
             * @brief Get a message from the message queue.
             * @param message The message return value.
             *  The message returned is removed from the message queue.
             * @param msgIdStart Message identifier range start.
             *  Use Message::ID_ANY to receive any message (set msgIdEnd to zero).
             * @param msgIdEnd Message identifier range end.
             * @return The message queue result.
             */
            Result GetMessage(Message::AutoPtr& message, UInt32 msgIdStart, UInt32 msgIdEnd);

            /**
             * @brief Peek a message from the message queue.
             * Checks if a message is in the message queue but does not remove
             * the message from the message queue.
             * @param message The message return value.
             * @param msgIdStart Message identifier range start.
             *  Use Message::ID_ANY to receive any message (set msgIdEnd to zero).
             * @param msgIdEnd Message identifier range end.
             * @return The message queue result.
             */
            Result PeekMessage(const Message*& message, UInt32 msgIdStart, UInt32 msgIdEnd);

        protected:
            /**
             * @brief Get a message raw pointer from the message queue.
             * @param message The message return value.
             * @param msgIdStart Message identifier range start.
             *  Use Message::ID_ANY to receive any message (set msgIdEnd to zero).
             * @param msgIdEnd Message identifier range end.
             * @param remove If true remove the message from the queue.
             * @return The message queue result.
             */
            Result GetMessage(Message*& message, UInt32 msgIdStart, UInt32 msgIdEnd, Bool remove);

            /** @brief The message class mutex. */
            System::Mutex mMutex;
            /** @brief The message queue semaphore. */
            System::Semaphore mMessageArrived;
            /** @brief The maximum message queue length. */
            UInt32 mMaxMessageQueueLength;
            /** @brief The message queue. */
            Array<Message::AutoPtr> mMessages;
        };
    }
}

#endif // __MURL_UTIL_MESSAGE_QUEUE_H__
