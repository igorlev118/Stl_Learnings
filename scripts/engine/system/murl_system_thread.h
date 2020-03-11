// Copyright 2010-2013 Spraylight GmbH

#ifndef __MURL_SYSTEM_THREAD_H__
#define __MURL_SYSTEM_THREAD_H__

#include "murl_string.h"

namespace Murl
{
    namespace System
    {
        class ThreadHandle;

        /**
         * @ingroup MurlSystemClasses
         * @brief The thread base class.
         * The implementation of a thread class must derive from the
         * thread base class and implement the Run() method.
         *
         * (!) Important: To avoid destroying the thread object while the thread
         *  is running, it is required to implement the destructor.
         * @code
         *  class MyThread : public System::Thread
         *  {
         *      virtual ~MyThread()
         *      {
         *          Stop();
         *          Join();
         *          // now it is safe to destroy objects and free memory.
         *      }
         *
         *      virtual Bool Run()
         *      {
         *          while (mIsRunning)
         *          {
         *              // do some stuff.
         *              Flush();
         *          }
         *          return true;
         *      }
         *  };
         * @endcode
         */
        class Thread : NonCopyable
        {
        public:
            /**
             * @brief Thread scheduling priority enumeration.
             */
            enum SchedulingPriority
            {
                /// Lowest priority.
                SCHEDULING_PRIORITY_LOWEST,
                /// Normal priority.
                SCHEDULING_PRIORITY_NORMAL,
                /// Highest priority.
                SCHEDULING_PRIORITY_HIGHEST
            };

            /**
             * @brief Thread scheduling policy enumeration.
             */
            enum SchedulingPolicy
            {
                /// Unspecified policy.
                SCHEDULING_POLICY_OTHER,
                /// FIFO policy.
                SCHEDULING_POLICY_FIFO,
                /// Round robin policy.
                SCHEDULING_POLICY_ROUND_ROBIN
            };

            /**
             * @brief The destructor.
             */
            virtual ~Thread();

            /**
             * @brief Create and start the thread.
             * Set the mIsRunning state to true.
             * @return true if successful,
             *  false if starting failed or the thread is already created.
             */
            virtual Bool Start();

            /**
             * @brief Stop the thread.
             * Set the mIsRunning state to false.
             * After calling Stop() it is required to call Join(), otherwise
             * it is not possible to call Start() again.
             */
            virtual void Stop();

            /**
             * @brief Join and destroy the thread.
             * Typically Stop() is called before to exit the main loop in the Run() method.
             */
            virtual void Join();

            /**
             * @brief Flush the autorelease memory pool.
             * Drain the AutoReleasePool on OSX/iOS systems.
             */
            virtual void Flush();

            /**
             * @brief Set the current thread's priority and scheduling policy.
             * @param priority One of the available thread priority enum values.
             * @param policy A hint to the scheduling policy to use.
             * @return true if successful.
             */
            static Bool SetCurrentPriority(SchedulingPriority priority, SchedulingPolicy policy = SCHEDULING_POLICY_OTHER);

            /**
             * @brief Set the current thread's CPU affinity mask.
             * @param mask A bit mask representing individual CPUs (or CPU cores)
             * @return true if successful.
             */
            static Bool SetCurrentAffinityMask(UInt32 mask);

            /**
             * @brief Get the current thread identifier.
             * The current thread identifier is not necessarily the identifier of
             * the thread class, notify the static declaration which means
             * System::Thread::GetCurrentId() can be called without a class context.
             * @return The current thread identifier.
             */
            static UInt64 GetCurrentId();

        protected:
            /**
             * @brief Constructor taking a thread name.
             * @param name The name of the thread.
             *  On OSX/iOS systems the thread name is truncated to 63 characters.
             */
            Thread(const String& name);

            /**
             * @brief The abstract run method for overloading.
             * On OSX/iOS systems an AutoReleasePool is created before calling Run().
             * @return true if successful.
             */
            virtual Bool Run() = 0;

            /** The running state of the thread. */
            Bool mIsRunning;

            /** The name of the thread. */
            String mName;

            /** The identifier of the thread. */
            UInt64 mThreadId;

            /** The anonymous thread handle for internal use only. */
            ThreadHandle* mHandle;
        };
    }
}

#endif  // __MURL_SYSTEM_THREAD_H__
