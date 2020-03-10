// Copyright 2010-2016 Spraylight GmbH

#ifndef __MURL_SYSTEM_MUTEX_H__
#define __MURL_SYSTEM_MUTEX_H__

#include "murl_types.h"

namespace Murl
{
    namespace System
    {
        /**
         * @ingroup MurlSystemClasses
         * @brief The mutex class.
         * To protect a code block for multi-threaded access,
         * Lock() at the beginning of the block and Unlock()
         * at the end of the block.
         */
        class Mutex : NonCopyable
        {
        public:
            /**
             * @brief The default constructor.
             */
            Mutex();
            /**
             * @brief The destructor.
             */
            ~Mutex();

            /**
             * @brief Lock the mutex.
             * @return true if successful.
             */
            Bool Lock() const;
            /**
             * @brief Unlock the mutex.
             * @return true if successful.
             */
            Bool Unlock() const;

        protected:
            class MutexHandle;
            /** The anonymous mutex handle for internal use only. */
            mutable MutexHandle* mHandle;
        };

        /**
         * @ingroup MurlSystemClasses
         * @brief The locker class for scoped Mutex locking.
         * A local instance of the locker will Lock() a mutex at
         * object creation and automatically Unlock() the mutex
         * when the object goes out of scope.
         * @code
         *  Bool MyMethod()
         *  {
         *      Locker locker(mMyMutex);
         *      // protected code starts here
         *      if (somethingHappens)
         *      {
         *          return false;
         *      }
         *      return true;
         *  }
         * @endcode
         */
        class Locker : NonCopyable
        {
        public:
            /**
             * @brief The constructor.
             * @param mutex The mutex to Mutex::Lock().
             */
            Locker(const Mutex& mutex)
            : mMutex(mutex)
            {
                mMutex.Lock();
            }

            /**
             * @brief The destructor.
             * Mutex::Unlock() the mutex.
             */
            ~Locker()
            {
                mMutex.Unlock();
            }

        protected:
            /** @brief The reference to the mutex. */
            const Mutex& mMutex;
        };

        /**
         * @ingroup MurlSystemClasses
         * @brief The atomic integer class.
         * The atomic integer is a thread-safe integer.
         * On modern platforms the operations are supported by
         * intrinsic CPU commands without using a mutex.
         */
        class AtomicSInt32 : NonCopyable
        {
        public:
            /**
             * @brief The constructor.
             * @param value The initial value.
             */
            AtomicSInt32(SInt32 value)
            : mValue(value)
            {
            }

            /**
             * @brief Increment prefix operator.
             * @return The incremented value.
             */
            SInt32 operator++();
            /**
             * @brief Increment suffix operator.
             * @return The value before incrementation.
             */
            SInt32 operator++(int);

            /**
             * @brief Decrement prefix operator.
             * @return The decremented value.
             */
            SInt32 operator--();
            /**
             * @brief Decrement suffix operator.
             * @return The value before decrementation.
             */
            SInt32 operator--(int);

            /**
             * @brief Exchange and add a value.
             * @param valueToAdd The value to add.
             * @return The value before addition.
             */
            SInt32 ExchangeAndAdd(SInt32 valueToAdd);

            /**
             * @brief Conversion operator.
             * @return The value.
             */
            operator SInt32()
            {
                return ExchangeAndAdd(0);
            }

        protected:
            /** @brief The value store. */
#ifndef MURL_USE_STDATOMIC
            SInt32 mValue;
#else
            _Atomic(SInt32) mValue;
#endif
        };
    }
}

#endif  // __MURL_SYSTEM_MUTEX_H__
