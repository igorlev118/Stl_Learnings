// Copyright 2012-2013 Spraylight GmbH

#ifndef __MURL_UTIL_MESSAGE_THREAD_H__
#define __MURL_UTIL_MESSAGE_THREAD_H__

#include "murl_util_message_dispatch.h"
#include "murl_util_message_queue.h"
#include "murl_system_thread.h"

namespace Murl
{
    namespace Util
    {
        /**
         * @ingroup MurlUtilMessageClasses
         * @brief The MessageThread class implements a thread with
         * a ready to use MessageQueue and MessageDispatch class.
         *
         * Example for sending data to different methods:
         * @code
         *  #include "murl_util_message_thread.h"
         *
         *  class MyMessage1 : public Util::Message
         *  {
         *  public:
         *      MyMessage1(UInt32 messageId, UInt32 data)
         *      : Util::Message(messageId)
         *      , mData(data)
         *      {
         *      }
         *
         *      UInt32 mData;
         *  };
         *
         *  class MyMessage2 : public Util::Message
         *  {
         *  public:
         *      MyMessage2(UInt32 messageId, UInt32 data1, UInt32 data2)
         *      : Util::Message(messageId)
         *      {
         *          mData.Add(data1);
         *          mData.Add(data2);
         *      }
         *
         *      Array<UInt32> mData;
         *  };
         *
         *  class MyThread : public Util::MessageThread
         *  {
         *  public:
         *      enum MyMessageIds
         *      {
         *          MY_MESSAGE_1,
         *          MY_MESSAGE_2
         *      };
         *
         *      MyThread()
         *      : MessageThread("MyThread")
         *      {
         *          Util::MessageDispatch& disp = GetMessageDispatch();
         *          disp.Register<MyMessage1>(MY_MESSAGE_1, this, &MyThread::Receive1);
         *          disp.Register<MyMessage2>(MY_MESSAGE_2, this, &MyThread::Receive2);
         *      }
         *
         *      virtual ~MyThread()
         *      {
         *          Stop();
         *          Join();
         *      }
         *
         *      void Send1(UInt32 data)
         *      {
         *          Debug::Trace(("%s Message1(%d) Send\n"), mName.Begin(), data);
         *          SendMessage(AutoPointer<MyMessage1>(new MyMessage1(MY_MESSAGE_1, data)));
         *      }
         *
         *      void Send2(UInt32 data1, UInt32 data2)
         *      {
         *          Debug::Trace(("%s Message2(%d, %d) SendSync\n"), mName.Begin(), data1, data2);
         *          SendSyncMessage(AutoPointer<MyMessage2>(new MyMessage2(MY_MESSAGE_2, data1, data2)));
         *          Debug::Trace(("%s Message2(%d, %d) returned\n"), mName.Begin(), data1, data2);
         *      }
         *
         *  protected:
         *      void Receive1(AutoPointer<MyMessage1> message)
         *      {
         *          Debug::Trace(("%s Message1(%d) received\n"), mName.Begin(), message->mData);
         *      }
         *
         *      void Receive2(AutoPointer<MyMessage2> message)
         *      {
         *          Debug::Trace(("%s Message2(%d, %d) received\n"), mName.Begin(), message->mData[0], message->mData[1]);
         *      }
         *  };
         *
         *  void MyMain()
         *  {
         *      MyThread myThread;
         *      myThread.Start();
         *
         *      myThread.Send2(16, 17);
         *      myThread.Send1(42);
         *      myThread.Send2(19, 18);
         *      myThread.Send1(43);
         *
         *      myThread.SendQuit();
         *      myThread.Join();
         *  }
         * @endcode
         */
        class MessageThread : public System::Thread
        {
        public:
            /**
             * @brief The default constructor.
             */
            MessageThread();

            /**
             * @brief Constructor taking a thread name.
             * @param name The thread name.
             */
            MessageThread(const String& name);

            /**
             * @brief The destructor.
             * Calls Stop() and System::Thread::Join().
             */
            virtual ~MessageThread();

            /**
             * @brief Create and start the thread.
             * @return System::Thread::Start().
             */
            virtual Bool Start();

            /**
             * @brief Create and start the thread,
             *  run the message loop with timeout.
             * If a timeout occurs the message dispatcher timeout method is
             * called which executes the MessageDispatch::RegisterTimeout()
             * callback object.
             * @param timeout The maximum time to wait for messages.
             * @return System::Thread::Start().
             */
            virtual Bool Start(const System::Time& timeout);

            /**
             * @brief Stop the thread.
             * Calls SendQuit() and System::Thread::Stop().
             */
            virtual void Stop();

            /**
             * @brief Set the message loop timeout.
             * @param timeout The maximum time to wait for messages.
             */
            void SetTimeout(const System::Time& timeout);

            /**
             * @brief Get the message loop timeout.
             * @return The message loop timeout.
             */
            const System::Time& GetTimeout() const;

            /**
             * @brief Get the thread's message queue object.
             * @return The thread's message queue object.
             */
            MessageQueue& GetMessageQueue();

            /**
             * @brief Get the thread's message dispatch object.
             * @return The thread's message dispatch object.
             */
            MessageDispatch& GetMessageDispatch();

            /**
             * @brief Send the ID_QUIT message to the thread.
             * @return true if successful.
             */
            virtual Bool SendQuit();

            /**
             * @brief Send the Message object to the thread.
             * @param messageId The message identifier to send.
             * @return true if successful.
             */
            virtual Bool SendId(UInt32 messageId);

            /**
             * @brief Send a message object to the thread.
             * @param message The message object to send.
             * @return true if successful.
             */
            virtual Bool SendMessage(Message::AutoPtr message);

            /**
             * @brief Send a message object to the thread and wait
             * until the message is delivered and processed.
             * If this method is called from it's own thread context
             * the message is dispatched immediately.
             * @param message The message object to send.
             * @return true if successful.
             */
            virtual Bool SendSyncMessage(Message::AutoPtr message);

        protected:
            /**
             * @brief Wait for a message (using Message::ID_ANY).
             * @param message The message return value.
             *  The message returned is removed from the message queue.
             * @return The message queue result.
             */
            virtual MessageQueue::Result WaitMessage(Message::AutoPtr& message);

            /**
             * @brief Wait for a message with timeout (using Message::ID_ANY).
             * @param message The message return value.
             *  The message returned is removed from the message queue.
             * @param timeout The maximum time to wait.
             * @return The message queue result.
             */
            virtual MessageQueue::Result WaitMessage(Message::AutoPtr& message, const System::Time& timeout);

            /**
             * @brief Get a message from the message queue (using Message::ID_ANY).
             * @param message The message return value.
             *  The message returned is removed from the message queue.
             * @return The message queue result.
             */
            virtual MessageQueue::Result GetMessage(Message::AutoPtr& message);

            /**
             * @brief Peek a message from the message queue (using Message::ID_ANY).
             * Checks if a message is in the message queue but does not remove
             * the message from the message queue.
             * @param message The message return value.
             * @return The message queue result.
             */
            virtual MessageQueue::Result PeekMessage(const Message*& message);

            /**
             * @brief The System::Thread::Run() method implementation.
             * Implements the message loop:
             * @code
             *  Bool Util::MessageThread::Run()
             *  {
             *      while (mIsRunning)
             *      {
             *          Message::AutoPtr message;
             *          MessageQueue::Result result = MessageQueue::FAILED;
             *          if (mTimeout.IsInfinite())
             *          {
             *              result = DispatchMessage(message);
             *          }
             *          else
             *          {
             *              result = DispatchMessage(message, mTimeout);
             *          }
             *          if (result == MessageQueue::RECEIVED)
             *          {
             *              if (!message.IsNull())
             *              {
             *                  Debug::Error("MessageThread '%s': Non-dispatched message id %d received",
             *                  mName.Begin(), message->GetId());
             *              }
             *          }
             *          else if (result == MessageQueue::TIMEOUT)
             *          {
             *              mMessageDispatch.ExecuteTimeout();
             *          }
             *          else if (result == MessageQueue::QUIT)
             *          {
             *              Thread::Stop();
             *          }
             *          Flush();
             *      }
             *      return true;
             *  }
             * @endcode
             * @return true if successful.
             */
            virtual Bool Run();

            /**
             * @brief Wait for a message and dispatch the message.
             * @param message The message return value.
             * @return The wait message queue result.
             */
            virtual MessageQueue::Result DispatchMessage(Message::AutoPtr& message);

            /**
             * @brief Wait for a message and dispatch the message with timeout.
             * @param message The message return value.
             * @param timeout The maximum time to wait.
             * @return The wait message queue result.
             */
            virtual MessageQueue::Result DispatchMessage(Message::AutoPtr& message, const System::Time& timeout);

            /** @brief The message queue instance. */
            MessageQueue mMessageQueue;
            /** @brief The message dispatch instance. */
            MessageDispatch mMessageDispatch;
            /** @brief The message loop timeout. */
            System::Time mTimeout;
        };
    }
}

#endif // __MURL_UTIL_MESSAGE_THREAD_H__
