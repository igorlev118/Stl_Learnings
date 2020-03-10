// Copyright 2010-2013 Spraylight GmbH

#ifndef __MURL_SYSTEM_SEMAPHORE_H__
#define __MURL_SYSTEM_SEMAPHORE_H__

#include "murl_system_time.h"

namespace Murl
{
    namespace System
    {
        class SemaphoreHandle;

        /**
         * @ingroup MurlSystemClasses
         * @brief The semaphore class for thread synchronization.
         * One thread can Wait() for a signal until
         * another thread is sending the Signal().
         */
        class Semaphore : NonCopyable
        {
        public:
            /**
             * @brief The default constructor.
             */
            Semaphore();
            /**
             * @brief The destructor.
             */
            ~Semaphore();

            /**
             * @brief Signal the semaphore.
             * @return true if successful.
             */
            Bool Signal();

            /**
             * @brief Check the signal.
             * @return true if the semaphore was signalled.
             */
            Bool Try();

            /**
             * @brief Wait for the signal.
             * @return true when the signal arrived.
             */
            Bool Wait();

            /**
             * @brief Wait for the signal with timeout.
             * @param timeout The maximum time to wait for the signal.
             * @return true when the signal arrived, false if the timeout elapsed.
             */
            Bool Wait(System::Time timeout);

        protected:
            /** The anonymous semaphore handle for internal use only. */
            SemaphoreHandle* mHandle;
        };
    }
}

#endif  // __MURL_SYSTEM_SEMAPHORE_H__
