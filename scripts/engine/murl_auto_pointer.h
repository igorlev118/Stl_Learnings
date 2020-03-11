// Copyright 2011-2015 Spraylight GmbH

#ifndef __MURL_AUTO_POINTER_H__
#define __MURL_AUTO_POINTER_H__

#include "murl_types.h"

namespace Murl
{
    /**
     * @ingroup MurlClasses
     * @brief A wrapper class to provide AutoPointer with reference semantics.
     *
     * For example, an AutoPointer can be assigned (or constructed from)
     * the result of a function which returns an AutoPointer by value.
     *
     * All the AutoPointerRef stuff should happen behind the scenes.
     */
    template<class PointerType>
    class AutoPointerRef
    {
    public:
        PointerType* mPointer;

        explicit AutoPointerRef(PointerType* pointer)
        : mPointer(pointer)
        {
        }
    };

    /**
     * @ingroup MurlClasses
     * @brief A simple smart pointer providing strict ownership semantics.
     *
     * An AutoPointer owns the object it holds a pointer to.
     * Copying an AutoPointer copies the pointer and transfers ownership to the destination.
     * If more than one AutoPointer owns the same object at the same time
     * the behavior of the program is undefined.
     *
     * The uses of AutoPointer include providing passing ownership of dynamically allocated
     * memory to a function and returning dynamically allocated memory from a function.
     */
    template<class Type1>
    class AutoPointer
    {
    public:
        /** @brief The template parameter value type. */
        typedef Type1 ValueType;

        /**
         * @brief The default constructor.
         * Set a null pointer.
         */
        explicit AutoPointer()
        : mPointer(0)
        {
        }

        /**
         * @brief Constructor taking ownership of a memory location.
         * @param pointer The memory to take the ownership from.
         */
        explicit AutoPointer(Type1* pointer)
        : mPointer(pointer)
        {
        }

        /**
         * @brief Copy constructor.
         * Release() the memory pointer in the const autoPointer.
         * @param autoPointer The AutoPointer object to transfer.
         */
        AutoPointer(const AutoPointer& autoPointer)
        : mPointer(const_cast<AutoPointer&>(autoPointer).Release())
        {
        }

        /**
         * @brief Constructor for automatic downcast.
         * Release() the memory pointer in the const autoPointer.
         * @param autoPointer The AutoPointer object to transfer.
         */
        template<class Type2>
        explicit AutoPointer(const AutoPointer<Type2>& autoPointer)
        : mPointer(const_cast<AutoPointer<Type2>&>(autoPointer).Release())
        {
        }

        /**
         * @brief Assignment operator.
         * Release() the memory pointer in the const autoPointer.
         * @param autoPointer The AutoPointer object to transfer.
         * @return The object itself.
         */
        AutoPointer& operator=(const AutoPointer& autoPointer)
        {
            Reset(const_cast<AutoPointer&>(autoPointer).Release());
            return *this;
        }

        /**
         * @brief Assignment operator for an object of different type.
         * Release() the memory pointer in the const autoPointer.
         * @param autoPointer The AutoPointer object to transfer.
         * @return The object itself.
         */
        template<class Type2>
        AutoPointer& operator=(const AutoPointer<Type2>& autoPointer)
        {
            Reset(const_cast<AutoPointer<Type2>&>(autoPointer).Release());
            return *this;
        }

        /**
         * @brief The destructor.
         * Free (delete) the memory.
         */
        ~AutoPointer()
        {
            if (mPointer != 0)
            {
                delete mPointer;
            }
        }

        /**
         * @brief Check if the memory pointer is null.
         * @return True if pointer to memory is null.
         */
        Bool IsNull() const
        {
            return mPointer == 0;
        }

        /**
         * @brief Indirection operator.
         * @return The reference to the memory.
         */
        Type1& operator*() const
        {
            return *mPointer;
        }

        /**
         * @brief Dereference operator.
         * @return The pointer to the memory.
         */
        Type1* operator->() const
        {
            return mPointer;
        }

        /**
         * @brief Get the pointer to the memory.
         * @return The pointer to the memory.
         */
        Type1* Get() const
        {
            return mPointer;
        }

        /**
         * @brief Release the memory pointer.
         * The receiver of the memory returned takes the ownership.
         * The memory pointer of this object is set to 0.
         * @return The pointer to the memory.
         */
        Type1* Release()
        {
            Type1* pointer = mPointer;
            mPointer = 0;
            return pointer;
        }

        /**
         * @brief Take ownership of a memory location.
         * If the object already owns a memory, the memory is deleted.
         * @param pointer The memory to take the ownership from.
         */
        void Reset(Type1* pointer = 0)
        {
            if (pointer != mPointer)
            {
                if (mPointer != 0)
                {
                    delete mPointer;
                }
                mPointer = pointer;
            }
        }

        /**
         * @brief Conversion operator.
         * Transfer the memory ownership to an object of different type.
         * @return The Object of differen type.
         */
        template<class Type2>
        operator AutoPointer<Type2>()
        {
            return AutoPointer<Type2>(this->Release());
        }

        /**
         * @brief Automatic conversions.
         * These operations convert an AutoPointer into and from an AutoPointerRef
         * automatically as needed. This allows constructs such as:
         * @code
         *  AutoPointer<Derived> FuncReturningAutoPointer(...);
         *  ...
         *  AutoPointer<Base> pointer = FuncReturningAutoPointer(...);
         * @endcode
         * @param autoPointerRef The AutoPointer object to transfer.
         */
        AutoPointer(AutoPointerRef<Type1> autoPointerRef)
        : mPointer(autoPointerRef.mPointer)
        {
        }

        AutoPointer& operator=(AutoPointerRef<Type1> autoPointerRef)
        {
            if (autoPointerRef.mPointer != this->Get())
            {
                if (mPointer != 0)
                {
                    delete mPointer;
                }
                mPointer = autoPointerRef.mPointer;
            }
            return *this;
        }

        template<class Type2>
        operator AutoPointerRef<Type2>()
        {
            return AutoPointerRef<Type2>(this->Release());
        }

    protected:
        Type1* mPointer;
    };
}

#endif  // __MURL_AUTO_POINTER_H__
