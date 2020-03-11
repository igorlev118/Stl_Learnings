// Copyright 2012 Spraylight GmbH

#ifndef __MURL_SHARED_POINTER_COUNTER_H__
#define __MURL_SHARED_POINTER_COUNTER_H__

#include "murl_system_mutex.h"

namespace Murl
{
    namespace SharedPointerPrivate
    {
        /**
         * @brief The counter base class.
         */
        class CounterBase
        {
        public:
            /**
             * @brief Add a shared pointer reference to the counter.
             */
            void AddReference()
            {
                mSharedCounter++;
            }
            
            /**
             * @brief Release a shared pointer reference from the counter.
             * If this is the last reference the objects deletes itself.
             */
            void ReleaseReference()
            {
                if (--mSharedCounter == 0)
                {
                    DeleteObject();
                    ReleaseWeakReference();
                }
            }
            
            /**
             * @brief Get current usage count.
             * @return The number of shared pointer references.
             */
            UInt32 GetCount()
            {
                return mSharedCounter;
            }
            
            /**
             * @brief Add a weak pointer reference to the counter.
             */
            void AddWeakReference()
            {
                mWeakCounter++;
            }
            
            /**
             * @brief Release a weak pointer reference from the counter.
             * If this is the last reference the objects deletes itself.
             */
            void ReleaseWeakReference()
            {
                if (--mWeakCounter == 0)
                {
                    delete this;
                }
            }
            
        protected:
            /**
             * @brief Default constructor sets the reference counters to 1.
             */
            CounterBase()
            : mSharedCounter(1)
            , mWeakCounter(1)
            {
            }
            
            /**
             * @brief The destructor.
             */
            virtual ~CounterBase()
            {
            }
            
            /**
             * @brief The object delete method.
             */
            virtual void DeleteObject() = 0;
            
        private:
            System::AtomicSInt32 mSharedCounter;
            System::AtomicSInt32 mWeakCounter;
        };
        
        /** Counter class of a Specified pointer type. */
        template<class RawType, class DeleterType>
        class CounterType: public CounterBase
        {
        public:
            /** Construct the reference counter.
             * @param rawPointer The raw memory pointer.
             * @param deleter The deleter functor.
             */
            CounterType(RawType* rawPointer, DeleterType deleter)
            : mRawPointer(rawPointer)
            , mDeleter(deleter)
            {
            }
            
        protected:
            /**
             * @brief Call the deleter functor.
             */
            virtual void DeleteObject()
            {
                mDeleter(mRawPointer);
            }
            
        private:
            /** The raw pointer. */
            RawType* mRawPointer;
            /** The delete functor to delete the raw pointer. */
            DeleterType mDeleter;
        };
        
        class WeakCounter;
        
        /**
         * @brief The shared pointer counter class.
         */
        class SharedCounter
        {
        public:
            /**
             * @brief The default constructor.
             */
            SharedCounter()
            : mCounter(0)
            {
            }
            
            /**
             * @brief Construct with pointer and create a pointer specific counter.
             * @param rawPointer The raw memory pointer.
             * @param deleter The deleter functor.
             */
            template<class RawType, class DeleterType>
            SharedCounter(RawType* rawPointer, DeleterType deleter)
            {
                mCounter = new CounterType<RawType, DeleterType>(rawPointer, deleter);
            }
            
            /**
             * @brief Copy constructor adding a shared pointer reference.
             * @param counter The shared counter to copy.
             */
            explicit SharedCounter(const SharedCounter& counter)
            : mCounter(counter.mCounter)
            {
                if (mCounter != 0)
                {
                    mCounter->AddReference();
                }
            }
            
            /**
             * @brief Copy constructor with a weak pointer counter
             *  adding a shared pointer reference.
             * @param counter The weak counter to copy.
             */
            explicit SharedCounter(const WeakCounter& counter);
            
            /**
             * @brief Destructor releasing a shared pointer reference.
             */
            ~SharedCounter()
            {
                if (mCounter != 0)
                {
                    mCounter->ReleaseReference();
                    mCounter = 0;
                }
            }
            
            /**
             * @brief Assignment operator releasing the old shared pointer reference
             *  and adding a shared pointer reference to the new counter.
             * @param counter The shared counter to assign.
             * @return The object itself.
             */
            SharedCounter& operator=(const SharedCounter& counter)
            {
                if (mCounter != counter.mCounter)
                {
                    if (counter.mCounter != 0)
                    {
                        counter.mCounter->AddReference();
                    }
                    if (mCounter != 0)
                    {
                        mCounter->ReleaseReference();
                    }
                    mCounter = counter.mCounter;
                }
                return *this;
            }
            
            /**
             * @brief Get current usage count.
             * @return The number of shared pointer references.
             */
            UInt32 GetCount() const
            {
                if (mCounter != 0)
                {
                    return mCounter->GetCount();
                }
                return 0;
            }
            
            /**
             * @brief Swap with anoter shared counter.
             * @param counter The shared counter to swap with.
             */
            void Swap(SharedCounter& counter)
            {
                CounterBase* temp = mCounter;
                mCounter = counter.mCounter;
                counter.mCounter = temp;
            }
            
            /**
             * @brief Less than operator.
             * @param rhs The right hand side SharedCounter to compare.
             * @return true if the left hand side (this) is less than the right hand side.
             */
            bool operator<(const SharedCounter& rhs) const
            {
                return (mCounter < rhs.mCounter);
            }
            
        private:
            CounterBase* mCounter;
            
            friend class SharedPointerPrivate::WeakCounter;
        };
        
        /**
         * @brief The weak pointer counter class.
         */
        class WeakCounter
        {
        public:
            /**
             * @brief The default constructor.
             */
            WeakCounter()
            : mCounter(0)
            {
            }
            
            /**
             * @brief Copy constructor adding a weak counter reference.
             * @param counter The weak counter to copy.
             */
            explicit WeakCounter(const WeakCounter& counter)
            : mCounter(counter.mCounter)
            {
                if (mCounter != 0)
                {
                    mCounter->AddWeakReference();
                }
            }
            
            /**
             * @brief Copy constructor with a shared pointer counter
             *  adding a weak pointer reference.
             * @param counter The shared counter to copy.
             */
            explicit WeakCounter(const SharedCounter& counter)
            : mCounter(counter.mCounter)
            {
                if (mCounter != 0)
                {
                    mCounter->AddWeakReference();
                }
            }
            
            /**
             * @brief Destructor releasing a weak counter reference.
             */
            ~WeakCounter()
            {
                if (mCounter != 0)
                {
                    mCounter->ReleaseWeakReference();
                    mCounter = 0;
                }
            }
            
            /**
             * @brief Assignment operator with a shared pointer counter
             *  releasing the old weak pointer reference and
             *  adding a weak pointer reference to the new counter.
             * @param counter The shared counter to assign.
             * @return The object itself.
             */
            WeakCounter& operator=(const SharedCounter& counter)
            {
                if (mCounter != counter.mCounter)
                {
                    if (counter.mCounter != 0)
                    {
                        counter.mCounter->AddWeakReference();
                    }
                    if (mCounter != 0)
                    {
                        mCounter->ReleaseWeakReference();
                    }
                    mCounter = counter.mCounter;
                }
                return *this;
            }
            
            /**
             * @brief Assignment operator releasing the old weak pointer reference
             *  and adding a weak pointer reference to the new counter.
             * @param counter The weak counter to assign.
             * @return The object itself.
             */
            WeakCounter& operator=(const WeakCounter& counter)
            {
                if (mCounter != counter.mCounter)
                {
                    if (counter.mCounter != 0)
                    {
                        counter.mCounter->AddWeakReference();
                    }
                    if (mCounter != 0)
                    {
                        mCounter->ReleaseWeakReference();
                    }
                    mCounter = counter.mCounter;
                }
                return *this;
            }
            
            /**
             * @brief Get current usage count.
             * @return The number of shared pointer references.
             */
            UInt32 GetCount() const
            {
                if (mCounter != 0)
                {
                    return mCounter->GetCount();
                }
                return 0;
            }
            
            /**
             * @brief Swap with anoter shared counter.
             * @param counter The weak counter to swap with.
             */
            void Swap(WeakCounter& counter)
            {
                CounterBase* temp = mCounter;
                mCounter = counter.mCounter;
                counter.mCounter = temp;
            }
            
            /**
             * @brief Less than operator.
             * @param rhs The right hand side WeakCounter to compare.
             * @return true if the left hand side (this) is less than the right hand side.
             */
            bool operator<(const WeakCounter& rhs) const
            {
                return (mCounter < rhs.mCounter);
            }
            
        private:
            CounterBase* mCounter;
            
            friend class SharedPointerPrivate::SharedCounter;
        };
        
        inline SharedCounter::SharedCounter(const WeakCounter& counter)
        : mCounter(counter.mCounter)
        {
            if (mCounter != 0)
            {
                mCounter->AddReference();
            }
        }
    }
}

#endif  // __MURL_SHARED_POINTER_COUNTER_H__
