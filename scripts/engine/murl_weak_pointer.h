// Copyright 2012-2015 Spraylight GmbH

#ifndef __MURL_WEAK_POINTER_H__
#define __MURL_WEAK_POINTER_H__

#include "murl_shared_pointer.h"

namespace Murl
{
    /**
     * @ingroup MurlClasses
     * @brief The WeakPointer class.
     * The WeakPointer holds a reference to a shared pointer for obtaining
     * temporary Sharedpointer instances by using the Lock() method.
     * If the SharedPointer do no longer exist, the Lock() method returns
     * a SharedPointer object which holds a null pointer.
     */
    template<class DataType>
    class WeakPointer
    {
    public:
        /** @brief The template parameter value type. */
        typedef DataType ValueType;

        /**
         * @brief The default constructor creating a null pointer.
         */
        WeakPointer()
        : mRawPointer(0)
        {
        }

        /**
         * @brief Constructor for automatic downcast.
         * @param weakPointer The WeakPointer object.
         */
        template<class RawType>
        WeakPointer(const WeakPointer<RawType>& weakPointer)
        : mRawPointer(weakPointer.Lock().mRawPointer)
        , mReferenceCounter(weakPointer.mReferenceCounter)
        {
        }

        /**
         * @brief Constructor taking a SharedPointer.
         * @param sharedPointer The SharedPointer object.
         */
        template<class RawType>
        WeakPointer(const SharedPointer<RawType>& sharedPointer)
        : mRawPointer(sharedPointer.mRawPointer)
        , mReferenceCounter(sharedPointer.mReferenceCounter)
        {
        }

        /**
         * @brief Get the SharedPointer from the WeakPointer.
         * @return The SharedPointer object.
         *  The SharedPointer's pointer is null if the SharedPointer is expired.
         */
        SharedPointer<DataType> Lock() const
        {
            if (IsExpired())
            {
                return SharedPointer<DataType>();
            }
            return SharedPointer<DataType>(*this);
        }

        /**
         * @brief Get the SharedPointer's usage counter.
         * @return The number of SharePointer instances referencing
         *  to the same memory pointer.
         */
        UInt32 GetCount() const
        {
            return mReferenceCounter.GetCount();
        }

        /**
         * @brief Check if the SharedPointer is expired.
         * @return true if the SharedPointer is expired.
         */
        Bool IsExpired() const
        {
            return (mReferenceCounter.GetCount() == 0);
        }

        /**
         * @brief Release the reference from the WeakPointer
         * and set the memory pointer to null.
         */
        void Clear()
        {
            WeakPointer<DataType> temp;
            temp.Swap(*this);
        }

        /**
         * @brief Swap with another WeakPointer.
         * @param weakPointer The WeakPointer to swap with.
         */
        void Swap(WeakPointer<DataType>& weakPointer)
        {
            DataType* temp = mRawPointer;
            mRawPointer = weakPointer.mRawPointer;
            weakPointer.mRawPointer = temp;
            mReferenceCounter.Swap(weakPointer.mReferenceCounter);
        }

        /**
         * @brief Equal to comparison operator.
         * @param rhs The right hand side WeakPointer to compare.
         * @return true if the memory pointers are equal.
         */
        template<class RawType>
        bool operator==(const WeakPointer<RawType>& rhs) const
        {
            return (mRawPointer == rhs.mRawPointer);
        }

        /**
         * @brief Not equal to comparison operator.
         * @param rhs The right hand side WeakPointer to compare.
         * @return true if the memory pointers are not equal.
         */
        template<class RawType>
        bool operator!=(const WeakPointer<RawType>& rhs) const
        {
            return (mRawPointer != rhs.mRawPointer);
        }

        /**
         * @brief Less than operator.
         * @param rhs The right hand side WeakPointer to compare.
         * @return true if the left hand side (this) is less than the right hand side.
         */
        template<class RawType>
        bool operator<(const WeakPointer<RawType>& rhs) const
        {
            return (mReferenceCounter < rhs.mReferenceCounter);
        }

    private:
        DataType* mRawPointer;
        SharedPointerPrivate::WeakCounter mReferenceCounter;

        template<class AnyType> friend class SharedPointer;
        template<class AnyType> friend class WeakPointer;
    };
}

#endif  // __MURL_WEAK_POINTER_H__
