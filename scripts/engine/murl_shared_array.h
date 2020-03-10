// Copyright 2014-2015 Spraylight GmbH

#ifndef __MURL_SHARED_ARRAY_H__
#define __MURL_SHARED_ARRAY_H__

#include "murl_array.h"
#include "murl_shared_pointer.h"

namespace Murl
{
    /**
     * @ingroup MurlContainerClasses
     * @brief A proxy class contaning a shared pointer to an array.
     * The copy constructor copies the object itself (the shared pointer).
     * The assignment operator copies the content of the object.
     *
     * See #Murl::Array for method documentation.
     * @tparam DataType The value's data type of the array.
     */
    template<class DataType>
    class SharedArray
    {
    public:
        /** @brief The template parameter value type. */
        typedef DataType ValueType;

        /** @brief The array type definition. */
        typedef Array<DataType> ArrayType;

        /**
         * @brief Forward to Array::Array() constructor.
         */
        SharedArray()
        : mSharedArray(new ArrayType())
        {
        }

        /**
         * @brief Forward to Array::Array(const DataType& item) constructor.
         * @param item The item.
         */
        SharedArray(const DataType& item)
        : mSharedArray(new ArrayType(item))
        {
        }

        /**
         * @brief Forward to Array::Array(const DataType& item1, const DataType& item2) constructor.
         * @param item1 The first item.
         * @param item2 The second item.
         */
        SharedArray(const DataType& item1, const DataType& item2)
        : mSharedArray(new ArrayType(item1, item2))
        {
        }

        /**
         * @brief Forward to Array::Array(const DataType& item1, const DataType& item2, const DataType& item3) constructor.
         * @param item1 The first item.
         * @param item2 The second item.
         * @param item3 The third item.
         */
        SharedArray(const DataType& item1, const DataType& item2, const DataType& item3)
        : mSharedArray(new ArrayType(item1, item2, item3))
        {
        }

        /**
         * @brief Forward to Array::Clear() method.
         */
        void Clear()
        {
            mSharedArray->Clear();
        }

        /**
         * @brief Forward to Array::Empty() method.
         */
        void Empty()
        {
            mSharedArray->Empty();
        }

        /**
         * @brief Forward to Array::Shrink() method.
         */
        void Shrink()
        {
            mSharedArray->Shrink();
        }

        /**
         * @brief Forward to Array::Trim() method.
         * @param n The new number of items in the array.
         * @return true if successful.
         */
        Bool Trim(SInt32 n)
        {
            return mSharedArray->Trim(n);
        }

        /**
         * @brief Forward to Array::Drop() method.
         * @param n The number of items to remove from the end.
         * @return true if successful.
         */
        Bool Drop(SInt32 n = 1)
        {
            return mSharedArray->Drop(n);
        }

        /**
         * @brief Forward to Array::Reserve() method.
         * @param n The number of items the underlying storage should hold.
         */
        void Reserve(SInt32 n)
        {
            mSharedArray->Reserve(n);
        }

        /**
         * @brief Forward to Array::SetCount(SInt32 n) method.
         * @param n The new number of items in the array.
         * @return true if successful.
         */
        Bool SetCount(SInt32 n)
        {
            return mSharedArray->SetCount(n);
        }

        /**
         * @brief Forward to Array::SetCount(SInt32 n, const DataType& item) method.
         * @param n The new number of items in the array.
         * @param item The value to initialize any newly added items with.
         * @return true if successful.
         */
        Bool SetCount(SInt32 n, const DataType& item)
        {
            return mSharedArray->SetCount(n, item);
        }

        /**
         * @brief Forward to Array::SetCountAndReserve(SInt32 n) method.
         * @param n The new number of items in the array.
         * @return true if successful.
         */
        Bool SetCountAndReserve(SInt32 n)
        {
            return mSharedArray->SetCountAndReserve(n);
        }

        /**
         * @brief Forward to Array::SetCountAndReserve(SInt32 n, const DataType& item) method.
         * @param n The new number of items in the array.
         * @param item The value to initialize any newly added items with.
         * @return true if successful.
         */
        Bool SetCountAndReserve(SInt32 n, const DataType& item)
        {
            return mSharedArray->SetCountAndReserve(n, item);
        }

        /**
         * @brief Forward to Array::Set(SInt32 index, const DataType& item) method.
         * @param index The index of the item to set.
         * @param item The source item to copy.
         * @return A reference to the set item.
         */
        DataType& Set(SInt32 index, const DataType& item)
        {
            return mSharedArray->Set(index, item);
        }

        /**
         * @brief Forward to Array::Set(SInt32 index, const DataType& item, SInt32 count) method.
         * @param index The index of the first item to set.
         * @param item The source item to copy.
         * @param count The number of items to set.
         * @return true if successful.
         */
        Bool Set(SInt32 index, const DataType& item, SInt32 count)
        {
            return mSharedArray->Set(index, item, count);
        }

        /**
         * @brief Forward to Array::Fill() method.
         * @param item The source item to copy.
         */
        void Fill(const DataType& item)
        {
            mSharedArray->Fill(item);
        }

        /**
         * @brief Forward to Array::Swap() method.
         * @param index1 The index of the first item.
         * @param index2 The index of the second item.
         */
        void Swap(SInt32 index1, SInt32 index2)
        {
            mSharedArray->Swap(index1, index2);
        }

        /**
         * @brief Forward to Array::Add() method.
         * @return A reference to the newly created item.
         */
        DataType& Add()
        {
            return mSharedArray->Add();
        }

        /**
         * @brief Forward to Array::Add(const DataType& item) method.
         * @param item The given item to be inserted at the end of the array.
         * @return A reference to the newly created item.
         */
        DataType& Add(const DataType& item)
        {
            return mSharedArray->Add(item);
        }

        /**
         * @brief Forward to Array::AddN() method.
         * @param count The number of new items to be inserted at the end of the array.
         */
        void AddN(SInt32 count)
        {
            mSharedArray->AddN(count);
        }

        /**
         * @brief Forward to Array::Add(const Array& other) method.
         * @param other The given item array to be inserted.
         * @return true if successful.
         */
        Bool Add(const SharedArray& other)
        {
            return mSharedArray->Add(*other.mSharedArray);
        }

        /**
         * @brief Forward to Array::Add(const Array& other, int offset, int count) method.
         * @param other The given source item array.
         * @param offset The index into the source array specifying the first item to copy.
         * @param count The number of source array items to copy.
         * @return true if successful.
         */
        Bool Add(const SharedArray& other, int offset, int count)
        {
            return mSharedArray->Add(*other.mSharedArray, offset, count);
        }

        /**
         * @brief Forward to Array::Insert(SInt32 index) method.
         * @param index the zero-based index where the new item should be inserted.
         * @return A reference to the newly created item.
         */
        DataType& Insert(SInt32 index)
        {
            return mSharedArray->Insert(index);
        }

        /**
         * @brief Forward to Array::Insert(SInt32 index, const DataType& item) method.
         * @param index the zero-based index where the new item should be inserted.
         * @param item The given item to be inserted.
         * @return A reference to the newly created item.
         */
        DataType& Insert(SInt32 index, const DataType& item)
        {
            return mSharedArray->Insert(index, item);
        }

        /**
         * @brief Forward to Array::Insert(SInt32 index, const DataType& item, SInt32 count) method.
         * @param index the zero-based index where the new items should be inserted.
         * @param item The given item to be inserted.
         * @param count The number of copies of the given item to insert.
         * @return true if successful.
         */
        Bool Insert(SInt32 index, const DataType& item, SInt32 count)
        {
            return mSharedArray->Insert(index, item, count);
        }

        /**
         * @brief Forward to Array::InsertN(SInt32 index, SInt32 count = 1) method.
         * @param index the zero-based index where the new items should be inserted.
         * @param count The number of new items to be inserted.
         * @return true if successful.
         */
        Bool InsertN(SInt32 index, SInt32 count = 1)
        {
            return mSharedArray->InsertN(index, count);
        }

        /**
         * @brief Forward to Array::Insert(SInt32 index, const Array& other) method.
         * @param index the zero-based index where the new items should be inserted.
         * @param other The given item array to be inserted.
         * @return true if successful.
         */
        Bool Insert(SInt32 index, const SharedArray& other)
        {
            return mSharedArray->Insert(index, *other.mSharedArray);
        }

        /**
         * @brief Forward to Array::Insert(SInt32 index, const Array& other, SInt32 offset, SInt32 count) method.
         * @param index the zero-based index where the new items should be inserted.
         * @param other The given source item array.
         * @param offset The index into the source array specifying the first item to copy.
         * @param count The number of source array items to copy.
         * @return true if successful.
         */
        Bool Insert(SInt32 index, const SharedArray& other, SInt32 offset, SInt32 count)
        {
            return mSharedArray->Insert(index, *other.mSharedArray, offset, count);
        }

        /**
         * @brief Forward to Array::Remove(SInt32 index, SInt32 count = 1) method.
         * @param index The zero-based index from where to remove the items.
         * @param count The number of items to remove.
         * @return true if successful.
         */
        Bool Remove(SInt32 index, SInt32 count = 1)
        {
            return mSharedArray->Remove(index, count);
        }

        /**
         * @brief Forward to Array::Remove(const SInt32* sortedIndices, SInt32 count) method.
         * @param sortedIndices A pointer to sorted indices where to remove the items.
         * @param count The number of items to remove, i.e. the number of indices.
         */
        void Remove(const SInt32* sortedIndices, SInt32 count)
        {
            mSharedArray->Remove(sortedIndices, count);
        }

        /**
         * @brief Forward to Array::Remove(const SInt32Array& sortedIndices) method.
         * @param sortedIndices A sorted array of indices where to remove the items.
         */
        void Remove(const SInt32Array& sortedIndices)
        {
            mSharedArray->Remove(sortedIndices);
        }

        /**
         * @brief Forward to Array::Find(const DataType& item) const method.
         * @param item The item to find.
         * @return The index of the item, or -1 if the item was not found.
         */
        SInt32 Find(const DataType& item) const
        {
            return mSharedArray->Find(item);
        }

        /**
         * @brief Forward to Array::Find(const DataType& item, SInt32 firstIndex) const method.
         * @param item The item to find.
         * @param firstIndex The index where to start searching.
         * @return The index of the item, or -1 if the item was not found.
         */
        SInt32 Find(const DataType& item, SInt32 firstIndex) const
        {
            return mSharedArray->Find(item, firstIndex);
        }

        /**
         * @brief Forward to Array::FindLast(const DataType& item) const method.
         * @param item The item to find.
         * @return The index of the item, or -1 if the item was not found.
         */
        SInt32 FindLast(const DataType& item) const
        {
            return mSharedArray->FindLast(item);
        }

        /**
         * @brief Forward to Array::FindLast(const DataType& item, SInt32 lastIndex) const method.
         * @param item The item to find.
         * @param lastIndex The index where to start searching.
         * @return The index of the item, or -1 if the item was not found.
         */
        SInt32 FindLast(const DataType& item, SInt32 lastIndex) const
        {
            return mSharedArray->FindLast(item, lastIndex);
        }

        /**
         * @brief Forward to Array::Bottom() method.
         * @return A reference to the first item.
         */
        DataType& Bottom()
        {
            return mSharedArray->Bottom();
        }

        /**
         * @brief Forward to Array::Bottom() const method.
         * @return A const reference to the first item.
         */
        const DataType& Bottom() const
        {
            return mSharedArray->Bottom();
        }

        /**
         * @brief Forward to Array::Top() method.
         * @return A reference to the last item.
         */
        DataType& Top()
        {
            return mSharedArray->Top();
        }

        /**
         * @brief Forward to Array::Top() const method.
         * @return A const reference to the last item.
         */
        const DataType& Top() const
        {
            return mSharedArray->Top();
        }

        /**
         * @brief Forward to Array::Pop() method.
         * @return A copy of the removed item.
         */
        DataType Pop()
        {
            return mSharedArray->Pop();
        }

        /**
         * @brief Forward to Array::At(SInt32 index) method.
         * @param index The zero-based index of the item to retrieve.
         * @return A reference to the specified item.
         */
        DataType& At(SInt32 index)
        {
            return mSharedArray->At(index);
        }

        /**
         * @brief Forward to Array::At(SInt32 index, const DataType& item) method.
         * @param index The zero-based index of the item to retrieve.
         * @param item The reference item used for initialization.
         * @return A reference to the specified item.
         */
        DataType& At(SInt32 index, const DataType& item)
        {
            return mSharedArray->At(index, item);
        }

        /**
         * @brief Forward to Array::GetCount() method.
         * @return The number of items.
         */
        SInt32 GetCount() const
        {
            return mSharedArray->GetCount();
        }

        /**
         * @brief Forward to Array::IsEmpty() method.
         * @return true if the array is empty, false otherwise.
         */
        Bool IsEmpty() const
        {
            return mSharedArray->IsEmpty();
        }

        /**
         * @brief Forward to Array::GetAlloc() method.
         * @return The number of allocated items.
         */
        SInt32 GetAlloc() const
        {
            return mSharedArray->GetAlloc();
        }

        /**
         * @brief Forward to Array::IsEqual() method.
         * @param other The array to compare.
         * @return true if both arrays have identical contents.
         */
        Bool IsEqual(const SharedArray& other) const
        {
            return mSharedArray->IsEqual(*other.mSharedArray);
        }

        /**
         * @brief Forward to Array::operator==() method.
         * @param rhs The right hand side array to compare.
         * @return true if both arrays have identical contents.
         */
        bool operator==(const SharedArray& rhs) const
        {
            return mSharedArray->IsEqual(*rhs.mSharedArray);
        }

        /**
         * @brief Forward to Array::operator!=() method.
         * @param rhs The right hand side array to compare.
         * @return true if both arrays do not have identical contents.
         */
        bool operator!=(const SharedArray& rhs) const
        {
            return !mSharedArray->IsEqual(*rhs.mSharedArray);
        }

        /**
         * @brief Forward to Array::operator[](SInt32 index) method.
         * @param index The zero-based index of the item to retrieve.
         * @return A reference to the specified item.
         */
        DataType& operator[](SInt32 index)
        {
            return mSharedArray->operator[](index);
        }

        /**
         * @brief Forward to Array::operator[](SInt32 index) const method.
         * @param index The zero-based index of the item to retrieve.
         * @return A const reference to the specified item.
         */
        const DataType& operator[](SInt32 index) const
        {
            return mSharedArray->operator[](index);
        }

        /**
         * @brief Forward to Array::Get(SInt32 index) method.
         * @param index The zero-based index of the item to retrieve.
         * @return A reference to the specified item.
         */
        DataType& Get(SInt32 index)
        {
            return mSharedArray->Get(index);
        }

        /**
         * @brief Forward to Array::Get(SInt32 index) const method.
         * @param index The zero-based index of the item to retrieve.
         * @return A const reference to the specified item.
         */
        const DataType& Get(SInt32 index) const
        {
            return mSharedArray->Get(index);
        }

        /**
         * @brief Forward to Array::operator DataType*() method.
         * @return A pointer to the raw array.
         */
        operator DataType*()
        {
            return *mSharedArray.Get();
        }

        /**
         * @brief Forward to Array::operator const DataType*() method.
         * @return A pointer to the constant raw array.
         */
        operator const DataType*() const
        {
            return *mSharedArray.Get();
        }

        /**
         * @brief Forward to Array::GetByteSize() method.
         * @return The number of bytes of the underlying raw array.
         */
        UInt32 GetByteSize() const
        {
            return mSharedArray->GetByteSize();
        }

        /**
         * @brief Forward to Array::Begin() const method.
         * @return The const iterator to the first item.
         */
        typename ArrayType::ConstIterator Begin() const
        {
            return mSharedArray->Begin();
        }

        /**
         * @brief Forward to Array::End() const method.
         * @return The const iterator next to the last item.
         */
        typename ArrayType::ConstIterator End() const
        {
            return mSharedArray->End();
        }

        /**
         * @brief Forward to Array::GetIter(SInt32 index) const method.
         * @param index The index for the iterator.
         * @return The const iterator or null if the index is out of range.
         */
        typename ArrayType::ConstIterator GetIter(SInt32 index) const
        {
            return mSharedArray->GetIter(index);
        }

        /**
         * @brief Forward to Array::GetIterIndex() method.
         * @param iterator The iterator of the item.
         * @return The index of the item, or -1 if the iterator is invalid.
         */
        SInt32 GetIterIndex(typename ArrayType::ConstIterator iterator) const
        {
            return mSharedArray->GetIterIndex(iterator);
        }

        /**
         * @brief Forward to Array::Begin() method.
         * @return The iterator to the first item.
         */
        typename ArrayType::Iterator Begin()
        {
            return mSharedArray->Begin();
        }

        /**
         * @brief Forward to Array::End() method.
         * @return The iterator next to the last item.
         */
        typename ArrayType::Iterator End()
        {
            return mSharedArray->End();
        }

        /**
         * @brief Forward to Array::GetIter(SInt32 index) method.
         * @param index The index for the iterator.
         * @return The iterator or null if the index is out of range.
         */
        typename ArrayType::Iterator GetIter(SInt32 index)
        {
            return mSharedArray->GetIter(index);
        }

        /**
         * @brief Get a copy of the internal Array object.
         * @return A copy of the array object.
         */
        ArrayType GetArray() const
        {
            return *mSharedArray.Get();
        }

        /**
         * @brief Conversion operator to the internal Array object.
         * @return A reference to the array object.
         */
        operator ArrayType&() const
        {
            return *mSharedArray.Get();
        }

        /**
         * @brief Dereference operator to the internal Array object.
         * @return A pointer to the array object.
         */
        ArrayType* operator->() const
        {
            return mSharedArray.Get();
        }

        /**
         * @brief Copy constructor taking an Array object.
         * @param array The array to copy.
         */
        SharedArray(const ArrayType& array)
        : mSharedArray(new ArrayType(array))
        {
        }

        /**
         * @brief Copy constructor taking a shared array object.
         * @param array The shared array to share.
         */
        explicit SharedArray(const SharedArray& array)
        : mSharedArray(array.mSharedArray)
        {
        }

        /**
         * @brief The assignment operator copying the internal Array.
         * @param array The shared array object to assign.
         */
        void operator=(const SharedArray& array)
        {
            *mSharedArray.Get() = *array.mSharedArray.Get();
        }

    protected:
        SharedPointer<ArrayType> mSharedArray;
    };
}

#endif // __MURL_SHARED_ARRAY_H__
