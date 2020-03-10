// Copyright 2012-2015 Spraylight GmbH

#ifndef __MURL_UTIL_MESSAGE_CALLBACK_H__
#define __MURL_UTIL_MESSAGE_CALLBACK_H__

#include "murl_util_message.h"

#include "murl_debug_trace.h"
#include "murl_system.h"
#include <typeinfo>

namespace Murl
{
    namespace Util
    {
        /**
         * @ingroup MurlUtilMessageClasses
         * @brief The message callback base class is used by the MessageDispatch
         * class to deliver received messages by a callback method,
         * see MessageThread.
         */
        class MessageCallBack
        {
        public:
            /**
             * @brief Definition of the MessageCallBack class auto pointer.
             */
            typedef AutoPointer<MessageCallBack> AutoPtr;

            /**
             * @brief The destructor.
             */
            virtual ~MessageCallBack() {}

            /**
             * @brief The abstract callback to deliver a message for overloading.
             * @param message The message to deliver.
             * @return true if successful.
             */
            virtual Bool Execute(Message::AutoPtr& message) = 0;
        };

        /**
         * @ingroup MurlUtilMessageClasses
         * @brief The MessageMethod class delivers a message of a
         * specified type to a class method, see MessageThread.
         */
        template<class MessageClass, class ObjectClass>
        class MessageMethod : public MessageCallBack
        {
        public:
            /**
             * @brief Definition of the method pointer to call.
             */
            typedef void (ObjectClass::*Method)(AutoPointer<MessageClass>);

            /**
             * @brief The constructor.
             * @tparam MessageClass The type of the message class.
             * @tparam ObjectClass The type of the class to call the method.
             * @param instance The instance pointer of the class
             * to call the method.
             * @param method The method pointer to call.
             */
            MessageMethod(ObjectClass* instance, Method method)
            : mInstance(instance)
            , mMethod(method)
            {
            }

            /**
             * @brief The callback to deliver a message.
             * The method pointer of the ObjectClass instance which was
             * passed to the constructor is called with the message
             * parameter casted to the MessageClass type.
             * @param message The message to deliver.
             * @return true if successful.
             */
            virtual Bool Execute(Message::AutoPtr& message)
            {
                MessageClass* messageClass;
#ifdef MURL_DEBUG
                messageClass = dynamic_cast<MessageClass*>(message.Get());
                if (messageClass == 0)
                {
                    Message* anyMessage = message.Get();
                    Debug::Error("MessageMethod::Execute() Incorrect class type, expected \"%s\", received \"%s\"",
                                 System::DemangleTypeName(typeid(MessageClass).name()).Begin(),
                                 System::DemangleTypeName(typeid(*anyMessage).name()).Begin());
                    return false;
                }
#endif // MURL_DEBUG
                messageClass = reinterpret_cast<MessageClass*>(message.Release());
                (mInstance->*mMethod)(AutoPointer<MessageClass>(messageClass));
                return true;
            }

        protected:
            /** The instance pointer of the class to call. */
            ObjectClass* mInstance;
            /** The method pointer to call. */
            Method mMethod;
        };
    }
}

#endif // __MURL_UTIL_MESSAGE_CALLBACK_H__
