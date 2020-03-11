// Copyright 2012 Spraylight GmbH

#ifndef __MURL_UTIL_MESSAGE_DISPATCH_H__
#define __MURL_UTIL_MESSAGE_DISPATCH_H__

#include "murl_util_message_callback.h"
#include "murl_map.h"

#include "murl_debug_trace.h"
#include "murl_system.h"
#include <typeinfo>

namespace Murl
{
    namespace Util
    {
        /**
         * @ingroup MurlUtilMessageClasses
         * @brief The message dispatch class is used to deliver
         * messages to a callback method by message identifier,
         * see MessageThread.
         */
        class MessageDispatch
        {
        public:
            /**
             * @brief The constructor.
             */
            MessageDispatch();
            /**
             * @brief The destructor.
             */
            virtual ~MessageDispatch();
            
            /**
             * @brief Register a method to call for a specified message identifier.
             * @tparam MessageClass The type of the message class.
             * @tparam ObjectClass The type of the class to call the method.
             * @param messageId The message identifier to register.
             * @param instance The instance pointer of the class
             * to call the method.
             * @param method The method pointer to call.
             * @return true if successful,
             *  false if the message identifier is already registered.
             */
            template<class MessageClass, class ObjectClass>
            Bool Register(UInt32 messageId, ObjectClass* instance,
                          void (ObjectClass::*method)(AutoPointer<MessageClass>))
            {
                MessageCallBack* callBack = new MessageMethod<MessageClass, ObjectClass>(instance, method);
                return Register(messageId, MessageCallBack::AutoPtr(callBack));
            }
            
            /**
             * @brief Register a default method to call for unknown message identifiers.
             * @tparam MessageClass The type of the message class.
             * @tparam ObjectClass The type of the class to call the method.
             * @param instance The instance pointer of the class
             * to call the method.
             * @param method The method pointer to call.
             * @return true if successful,
             *  false if the message identifier is already registered.
             */
            template<class MessageClass, class ObjectClass>
            Bool RegisterDefault(ObjectClass* instance,
                                 void (ObjectClass::*method)(AutoPointer<MessageClass>))
            {
                MessageCallBack* callBack = new MessageMethod<MessageClass, ObjectClass>(instance, method);
                return RegisterDefault(MessageCallBack::AutoPtr(callBack));
            }
            
            /**
             * @brief Register a method to call for timeout messages.
             * The timeout message is a Message object with identifier ID_TIMEOUT.
             * @tparam ObjectClass The type of the class to call the method.
             * @param instance The instance pointer of the class
             * to call the method.
             * @param method The method pointer to call.
             * @return true if successful,
             *  false if the message identifier is already registered.
             */
            template<class ObjectClass>
            Bool RegisterTimeout(ObjectClass* instance,
                                 void (ObjectClass::*method)(Message::AutoPtr))
            {
                MessageCallBack* callBack = new MessageMethod<Message, ObjectClass>(instance, method);
                return RegisterTimeout(MessageCallBack::AutoPtr(callBack));
            }
            
            /**
             * @brief Register a callback object for a specified message identifier.
             * A registered callback is executed by the Dispatch() method if
             * a message with the corresponding identifier is delivered.
             * @param messageId The message identifier to register.
             * @param callBack The callback object to register.
             * @return true if successful,
             *  false if the message identifier is already registered.
             */
            virtual Bool Register(UInt32 messageId, MessageCallBack::AutoPtr callBack);
            
            /**
             * @brief Register the default callback object.
             * The default callback is executed by the Dispatch() method if
             * a message with a not registered identifier is delivered.
             * @param callBack The callback object to register.
             * @return true if successful.
             */
            virtual Bool RegisterDefault(MessageCallBack::AutoPtr callBack);
            
            /**
             * @brief Register the timeout callback object.
             * @param callBack The callback object to register.
             * @return true if successful.
             */
            virtual Bool RegisterTimeout(MessageCallBack::AutoPtr callBack);
            
            /**
             * @brief Unregister a message identifier.
             * @param messageId The message identifier to unregister.
             * @return true if successful,
             *  false if the message identifier is not registered.
             */
            virtual Bool Unregister(UInt32 messageId);
            
            /**
             * @brief Dispatch a message by message identifier.
             * Execute the registered MessageCallBack of the corresponding
             * message identifier otherwise the default callback is executed.
             * @param message The message to deliver.
             * @return true if successful, false if message identifier
             *  is not registered or the callback execution failed.
             */
            virtual Bool Dispatch(Message::AutoPtr& message);
            
            /**
             * @brief Execute the timeout callback.
             * @return true if successful, false if the timeout callback
             *  is not registered or the callback execution failed.
             */
            virtual Bool ExecuteTimeout();
            
        protected:
            /** @brief The callback registry mapped by the message identifier. */
            Map<UInt32, MessageCallBack::AutoPtr> mMessageCallback;
            /** @brief The default callback. */
            MessageCallBack::AutoPtr mDefaultCallback;
            /** @brief The timeout callback. */
            MessageCallBack::AutoPtr mTimeoutCallback;
        };
    }
}

#endif // __MURL_UTIL_MESSAGE_DISPATCH_H__
