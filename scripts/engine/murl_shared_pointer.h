// Copyright 2012-2015 Spraylight GmbH

#ifndef __MURL_SHARED_POINTER_H__
#define __MURL_SHARED_POINTER_H__

#include "murl_deleter.h"
#include "murl_shared_pointer_private.h"

namespace Murl
{
    template<class DataType> class WeakPointer;

    /**
     * @ingroup MurlClasses
     * @brief The SharedPointer class.
     * The SharedPointer holds a reference counted memory pointer,
     * which is deleted when the last reference is removed.
     * To avoid cross-references a WeakPointer can be used.
     */
    template<class DataType>
    class SharedPointer
    {
    public:
        /** @brief The template parameter value type. */
        typedef DataType ValueType;

        /**
         * @brief The default constructor creating a null pointer.
         */
        SharedPointer()
        : mRawPointer(0)
        {
        }

        /**
         * @brief Constructor taking a pointer to a specified object.
         * @param rawPointer The pointer to the object.
         */
        template<class RawType>
        explicit SharedPointer(RawType* rawPointer)
        : mRawPointer(rawPointer)
        , mReferenceCounter(rawPointer, Deleter())
        {
        }

        /**
         * @brief Constructor taking a pointer to a specified object
         *  and a corresponding deleter functor object.
         * @param rawPointer The pointer to the object.
         * @param deleter The deleter functor.
         */
        template<class RawType, class DeleterType>
        SharedPointer(RawType* rawPointer, DeleterType deleter)
        : mRawPointer(rawPointer)
        , mReferenceCounter(rawPointer, deleter)
        {
        }

        /**
         * @brief Constructor taking the ownership of an AutoPointer.
         * @param autoPointer The AutoPointer object to take over.
         */
        template<class RawType>
        SharedPointer(AutoPointer<RawType> autoPointer)
        : mRawPointer(autoPointer.Release())
        , mReferenceCounter(mRawPointer, Deleter())
        {
        }

        /**
         * @brief Constructor taking a WeakPointer.
         * @param weakPointer The WeakPointer object.
         */
        template<class RawType>
        explicit SharedPointer(const WeakPointer<RawType>& weakPointer)
        : mRawPointer(weakPointer.mRawPointer)
        , mReferenceCounter(weakPointer.mReferenceCounter)
        {
        }

        /**
         * @brief Constructor for automatic downcast.
         * @param sharedPointer The SharedPointer object.
         */
        template<class RawType>
        SharedPointer(const SharedPointer<RawType>& sharedPointer)
        : mRawPointer(sharedPointer.mRawPointer)
        , mReferenceCounter(sharedPointer.mReferenceCounter)
        {
        }

        /**
         * @brief Indirection operator.
         * @return The reference to the memory.
         */
        DataType& operator*() const
        {
            return *mRawPointer;
        }

        /**
         * @brief Dereference operator.
         * @return The pointer to the memory.
         */
        DataType* operator->() const
        {
            return mRawPointer;
        }

        typedef DataType* SharedPointer<DataType>::*UnspecifiedBoolType;
        /**
         * @brief User define conversion to support statements like
         * @code if (sharedPointer) @endcode
         * @return Pointer to the memory pointer or null.
         */
        operator UnspecifiedBoolType() const
        {
            if (mRawPointer == 0)
            {
                return 0;
            }
            return &SharedPointer<DataType>::mRawPointer;
        }

        /**
         * @brief User define conversion to support statements like
         * @code if (!sharedPointer) @endcode
         * @return true if the memory pointer is null.
         */
        bool operator !() const
        {
            return mRawPointer == 0;
        }

        /**
         * @brief Check if the memory pointer is null.
         * @return true if the memory pointer is null.
         */
        Bool IsNull() const
        {
            return mRawPointer == 0;
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
         * @brief Check if the SharedPointer is the only one instance which is
         * referencing the memory pointer.
         * @return true if the SharedPointer's usage counter is 1.
         */
        Bool IsUnique() const
        {
            return (mReferenceCounter.GetCount() == 1);
        }

        /**
         * @brief Release the reference from the SharedPointer
         * and set the memory pointer to null.
         */
        void Reset()
        {
            SharedPointer<DataType> temp;
            temp.Swap(*this);
        }

        /**
         * @brief Set the memory pointer to a new object.
         * @param rawPointer The pointer to the object.
         */
        template<class RawType>
        void Reset(RawType* rawPointer)
        {
            SharedPointer<DataType> temp(rawPointer);
            temp.Swap(*this);
        }

        /**
         * @brief Set the memory pointer to a new object
         *  and a corresponding deleter functor object.
         * @param rawPointer The pointer to the object.
         * @param deleter The deleter functor.
         */
        template<class RawType, class DeleterType>
        void Reset(RawType* rawPointer, DeleterType deleter)
        {
            SharedPointer<RawType> temp(rawPointer, deleter);
            temp.Swap(*this);
        }

        /**
         * @brief Swap with another SharedPointer.
         * @param sharedPointer The SharedPointer to swap with.
         */
        void Swap(SharedPointer<DataType>& sharedPointer)
        {
            DataType* temp = mRawPointer;
            mRawPointer = sharedPointer.mRawPointer;
            sharedPointer.mRawPointer = temp;
            mReferenceCounter.Swap(sharedPointer.mReferenceCounter);
        }

        /**
         * @brief Equal to comparison operator.
         * @param rhs The right hand side SharedPointer to compare.
         * @return true if the memory pointers are equal.
         */
        template<class RawType>
        bool operator==(const SharedPointer<RawType>& rhs) const
        {
            return (mRawPointer == rhs.mRawPointer);
        }

        /**
         * @brief Not equal to comparison operator.
         * @param rhs The right hand side SharedPointer to compare.
         * @return true if the memory pointers are not equal.
         */
        template<class RawType>
        bool operator!=(const SharedPointer<RawType>& rhs) const
        {
            return (mRawPointer != rhs.mRawPointer);
        }

        /**
         * @brief Less than operator.
         * @param rhs The right hand side SharedPointer to compare.
         * @return true if the left hand side (this) is less than the right hand side.
         */
        template<class RawType>
        bool operator<(const SharedPointer<RawType>& rhs) const
        {
            return (mReferenceCounter < rhs.mReferenceCounter);
        }

        /**
         * @brief Equal to comparison operator with an unspecified pointer type.
         * @param rhs The right hand side memory pointer to compare.
         * @return true if the memory pointers are equal.
         */
        bool operator==(void* rhs) const
        {
            return mRawPointer == rhs;
        }

        /**
         * @brief Not equal to comparison operator with an unspecified pointer type.
         * @param rhs The right hand side memory pointer to compare.
         * @return true if the memory pointers are equal.
         */
        bool operator!=(void* rhs) const
        {
            return mRawPointer != rhs;
        }

        /**
         * @brief Get the pointer to the memory.
         * The memory pointer should be used within local scope only!
         * If the SharedPointer object goes out-of-scope, the validity
         * of the memory location it is no longer guaranteed.
         * @return The pointer to the memory.
         */
        DataType* Get() const
        {
            return mRawPointer;
        }

        /**
         * @brief Create a SharedPointer from a SharedPointer of different type
         * using the dynamic_cast for transfering the memory pointer.
         * @param source The SharedPointer to cast the memory from.
         * @return A SmartPointer containing the source memory pointer with own type.
         */
        template<class RawType>
        static SharedPointer<DataType> DynamicCast(const SharedPointer<RawType>& source)
        {
            SharedPointer<DataType> destination;
            destination.mRawPointer = dynamic_cast<DataType*>(source.mRawPointer);
            if (destination.mRawPointer != 0)
            {
                destination.mReferenceCounter = source.mReferenceCounter;
            }
            return destination;
        }

        /**
         * @brief Create a SharedPointer from a SharedPointer of different type
         * using the static_cast for transfering the memory pointer.
         * @param source The SharedPointer to cast the memory from.
         * @return A SmartPointer containing the source memory pointer with own type.
         */
        template<class RawType>
        static SharedPointer<DataType> StaticCast(const SharedPointer<RawType>& source)
        {
            SharedPointer<DataType> destination;
            destination.mRawPointer = static_cast<DataType*>(source.mRawPointer);
            destination.mReferenceCounter = source.mReferenceCounter;
            return destination;
        }

        /**
         * @brief Create a SharedPointer from a SharedPointer of different type
         * using the const_cast for transfering the memory pointer.
         * @param source The SharedPointer to cast the memory from.
         * @return A SmartPointer containing the source memory pointer with own type.
         */
        template<class RawType>
        static SharedPointer<DataType> ConstCast(const SharedPointer<RawType>& source)
        {
            SharedPointer<DataType> destination;
            destination.mRawPointer = const_cast<DataType*>(source.mRawPointer);
            destination.mReferenceCounter = source.mReferenceCounter;
            return destination;
        }

    private:
        DataType* mRawPointer;
        SharedPointerPrivate::SharedCounter mReferenceCounter;

        template<class AnyType> friend class SharedPointer;
        template<class AnyType> friend class WeakPointer;
    };
}

#endif  // __MURL_SHARED_POINTER_H__
