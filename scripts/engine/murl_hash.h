// Copyright 2010-2015 Spraylight

#ifndef __MURL_HASH_H__
#define __MURL_HASH_H__

#include "murl_array.h"
#include "murl_util_hash.h"

namespace Murl
{
    /**
     * @ingroup MurlContainerClasses
     * @brief A hash class.
     * The hash class stores indices accessable by a hash value.
     * \n This class is based on the NTL Hash container, see http://www.ultimatepp.org
     */
    class Hash
    {
    private:
        enum
        {
            UNSIGNED_HIBIT = 0x80000000
        };

    public:
        /**
         * @brief The default constructor.
         * Create an empty hash object.
         */
        Hash()
        : mMap(0)
        , mCount(0)
        , mAlloc(0)
        , mUnlinked(-1)
        {
        }

        /**
         * @brief The copy constructor.
         * @param hash The hash object to copy.
         */
        Hash(const Hash& hash)
        : mHash(hash.mHash)
        , mMap(0)
        , mCount(0)
        , mAlloc(0)
        , mUnlinked(-1)
        {
            Reindex();
        }

        /**
         * @brief The assignment operator.
         * @param hash The hash object to copy.
         */
        void operator=(const Hash& hash)
        {
            if (this != &hash)
            {
                mHash = hash.mHash;
                Reindex();
            }
        }

        /**
         * @brief The destructor.
         */
        ~Hash()
        {
            Free();
        }

        /**
         * @brief Clear the hash object.
         */
        void Clear()
        {
            mHash.Clear();
            ClearIndex();
        }

        /**
         * @brief Clear the index.
         */
        void ClearIndex()
        {
            mLink.Clear();
            mUnlinked = -1;
            Free();
        }

        /**
         * @brief Clear and rebuild the index for a given number of items.
         * @param n The number of items to rebuild.
         */
        void Reindex(SInt32 n)
        {
            UInt32 count = HashBound(n);
            if (count <= mAlloc)
            {
                mLink.Empty();
                mUnlinked = -1;
                mCount = count;
            }
            else
            {
                ClearIndex();
                mAlloc = count;
                mCount = count;
                mMap = new SInt32[count];
            }
            Util::Fill(mMap, mMap + count, -1);
            FinishIndex();
        }

        /**
         * @brief Clear and rebuild the index.
         */
        void Reindex()
        {
            Reindex(mHash.GetCount());
        }

        /**
         * @brief Shrink the hash object so that the underlying storage
         * is only as large as necessary.
         */
        void Shrink()
        {
            mHash.Shrink();
            if ((SInt32)HashBound(mHash.GetCount()) < mCount)
            {
                ClearIndex();
                DoIndex();
            }
            else
            {
                mLink.Shrink();
            }
        }

        /**
         * @brief Reduce the hash object to a given number of items.
         * @param n The new number of items in the hash object,
         *  must be smaller than the current item count.
         * @return true if successful.
         */
        Bool Trim(SInt32 n)
        {
            if (!MURL_VERIFY(n <= mHash.GetCount() && n >= 0))
            {
                return false;
            }
            for (SInt32 i = n; i < mLink.GetCount(); i++)
            {
                Unlink(i, mLink[i]);
            }
            mLink.Trim(n);
            mHash.SetCount(n);
            return true;
        }

        /**
         * @brief Reduce the hash object by removing a given number of items from the end.
         * @param n The number of items to remove from the end.
         * @return true if successful.
         */
        Bool Drop(SInt32 n)
        {
            return Trim(mHash.GetCount() - n);
        }

        /**
         * @brief Reserve storage space.
         * If the given size is less than the actual size, nothing is done.
         * @param n The number of items the underlying storage should hold.
         */
        void Reserve(SInt32 n)
        {
            mHash.Reserve(n);
            mLink.Reserve(n);
            if ((SInt32)HashBound(n) > mCount)
            {
                Reindex(n);
            }
        }

        /**
         * @brief Unlink a given index.
         * Unlinked items remain in the hash object, but are ignored by any search operations.
         * @param index The index to unlink.
         * @return true if successful.
         */
        Bool Unlink(SInt32 index)
        {
            if (!MURL_VERIFY(!IsUnlinked(index)))
            {
                return false;
            }
            mHash[index] |= UNSIGNED_HIBIT;
            if (index < mLink.GetCount())
            {
                Link& lnk = mLink[index];
                Unlink(index, lnk, Mapi(index));
                LinkTo(index, lnk, mUnlinked);
            }
            return true;
        }

        /**
         * @brief Check if the given index is unlinked.
         * @param index The index to check.
         * @return true if the specified item is unlinked.
         */
        Bool IsUnlinked(SInt32 index) const
        {
            return ((mHash[index] & UNSIGNED_HIBIT) != 0);
        }

        /**
         * @brief Get an array of unlinked indices.
         * @return The array of indices.
         */
        SInt32Array GetUnlinked() const
        {
            SInt32Array r;
            SInt32 q = mUnlinked;
            if (q >= 0)
            {
                do
                {
                    r.Add(q);
                    q = mLink[q].mNext;
                }
                while (q != mUnlinked);
            }
            return r;
        }

        /**
         * @brief Replace the index for a specified hash value.
         * @param index The index to set.
         * @param hash The hash value to set.
         */
        void Set(SInt32 index, UInt32 hash)
        {
            if (mMap != 0)
            {
                Link& lnk = mLink[index];
                Unlink(index, lnk);
                SInt32& mi = Maph(hash & ~UNSIGNED_HIBIT);
                SInt32 ii = mi;
                if (ii < 0)
                {
                    mi = lnk.mPrev = lnk.mNext = index;
                }
                else
                {
                    if (index < ii)
                    {
                        LinkBefore(index, lnk, ii);
                        mi = index;
                    }
                    else
                    {
                        SInt32 l = ii;
                        SInt32 h = mLink[ii].mPrev;
                        if (h - index < index - l)
                        {
                            while (index < h)
                            {
                                h = mLink[h].mPrev;
                            }
                            LinkBefore(index, lnk, mLink[h].mNext);
                        }
                        else
                        {
                            l = mLink[l].mNext;
                            while (index > l && l != ii)
                            {
                                l = mLink[l].mNext;
                            }
                            LinkBefore(index, lnk, l);
                        }
                    }
                }
            }
            mHash[index] = hash & ~UNSIGNED_HIBIT;
        }

        /**
         * @brief Replace the hash value at a specified index without
         *  consideration of multiple entries per hash value.
         * @param index The index to set.
         * @param hash The hash value to set.
         */
        void SetUn(SInt32 index, UInt32 hash)
        {
            if (mMap != 0)
            {
                Link& lnk = mLink[index];
                Unlink(index, lnk);
                LinkTo(index, lnk, Maph(hash & ~UNSIGNED_HIBIT));
            }
            mHash[index] = hash & ~UNSIGNED_HIBIT;
        }

        /**
         * @brief Add a hash value.
         * @param hash The hash value to add.
         */
        void Add(UInt32 hash)
        {
            mHash.Add(hash & ~UNSIGNED_HIBIT);
            DoIndex();
        }

        /**
         * @brief Put a hash value by replacing an unlinked index if present.
         * @param hash The hash value to add.
         * @return The index of the hash value or -1 if no unlinked index is available.
         */
        SInt32 Put(UInt32 hash)
        {
            if (mUnlinked < 0)
            {
                return -1;
            }
            Link& l = mLink[mUnlinked];
            SInt32 i = mUnlinked;
            mUnlinked = mLink[mUnlinked].mNext;
            if (i == mUnlinked)
            {
                mUnlinked = -1;
            }
            else
            {
                mLink[l.mNext].mPrev = l.mPrev;
                mLink[l.mPrev].mNext = l.mNext;
            }
            LinkTo(i, l, Maph(hash & ~UNSIGNED_HIBIT));
            mHash[i] = hash & ~UNSIGNED_HIBIT;
            return i;
        }

        /**
         * @brief Insert an index for a given hash value.
         * @param index The index to insert.
         * @param hash The hash value to insert.
         */
        void Insert(SInt32 index, UInt32 hash)
        {
            mHash.Insert(index, hash & ~UNSIGNED_HIBIT);
            ClearIndex();
            Reindex();
        }

        /**
         * @brief Remove the hash value at a given position.
         * @param index The index from where to remove the hash value.
         */
        void Remove(SInt32 index)
        {
            mHash.Remove(index);
            ClearIndex();
            Reindex();
        }

        /**
         * @brief Remove a number of hash values at a given starting position.
         * @param index The index from where to start removing the hash values.
         * @param count The number of subsequent hash values to remove.
         */
        void Remove(SInt32 index, SInt32 count)
        {
            mHash.Remove(index, count);
            ClearIndex();
            Reindex();
        }

        /**
         * @brief Remove a number of hash values at given positions.
         * @param sortedIndices A pointer to sorted indices where to remove the hash values.
         * @param count The number of hash values to remove, i.e. the number of indices.
         */
        void Remove(const SInt32* sortedIndices, SInt32 count)
        {
            mHash.Remove(sortedIndices, count);
            ClearIndex();
            Reindex();
        }

        /**
         * @brief Find the first index of a given hash value.
         * @param hash The hash value to search for.
         * @return The index of the hash value, or -1 if not found.
         */
        SInt32 Find(UInt32 hash) const
        {
            if (mHash.GetCount() == 0)
            {
                return -1;
            }
            return Maph(hash);
        }

        /**
         * @brief Find the next occurrence of a hash value that is specified by a given index.
         * @param index The index of the hash value to search for.
         * @return The index of the next hash value, or -1 if not found.
         */
        SInt32 FindNext(SInt32 index) const
        {
            SInt32 q = mLink[index].mNext;
            return (q == Mapi(index)) ? -1 : q;
        }

        /**
         * @brief Find the previous occurrence of a hash value that is specified by a given index.
         * @param index The index of the hash value to search for.
         * @return The index of the previous hash value, or -1 if not found.
         */
        SInt32 FindPrev(SInt32 index) const
        {
            SInt32 q = mLink[index].mPrev;
            return (q == mLink[Mapi(index)].mPrev) ? -1 : q;
        }

        /**
         * @brief Find the last occurrence of a hash value.
         * @param hash The hash value to search for.
         * @return The index of the item, or -1 if not found.
         */
        SInt32 FindLast(UInt32 hash) const
        {
            if (mHash.GetCount() == 0)
            {
                return - 1;
            }
            SInt32 i = Find(hash & ~UNSIGNED_HIBIT);
            return (i >= 0) ? mLink[i].mPrev : -1;
        }

        /**
         * @brief Get the hash value for a given index.
         * If the index is out of range, the behaviour is undefined.
         * @param index The index of the hash value to retrieve.
         * @return The hash value of the requested index.
         */
        UInt32 operator[](SInt32 index) const
        {
            return mHash[index];
        }

        /**
         * @brief Get the number of items.
         * @return The number of items.
         */
        SInt32 GetCount() const
        {
            return mHash.GetCount();
        }

        /**
         * @brief Exchange the content of the hash object with a given second one.
         * @param other The second hash object.
         */
        void Swap(Hash& other)
        {
            mHash.Swap(other.mHash);
            mLink.Swap(other.mLink);
            Util::Swap(mMap, other.mMap);
            Util::Swap(mCount, other.mCount);
            Util::Swap(mAlloc, other.mAlloc);
            Util::Swap(mUnlinked, other.mUnlinked);
        }

    private:
        struct Link
        {
            SInt32 mNext;
            SInt32 mPrev;
        };

        void LinkBefore(SInt32 i, Link& l, SInt32 bi)
        {
            Link& bl = mLink[bi];
            l.mNext = bi;
            l.mPrev = bl.mPrev;
            bl.mPrev = i;
            mLink[l.mPrev].mNext = i;
        }

        void LinkTo(SInt32 i, Link& l, SInt32& m)
        {
            if (m >= 0)
            {
                Link& bl = mLink[m];
                l.mNext = m;
                l.mPrev = bl.mPrev;
                bl.mPrev = i;
                mLink[l.mPrev].mNext = i;
            }
            else
            {
                m = l.mPrev = l.mNext = i;
            }
        }

        void Unlink(SInt32 i, Link& l, SInt32& m)
        {
            if (i == m)
            {
                if (l.mNext == i)
                {
                    m = -1;
                    return;
                }
                m = l.mNext;
            }
            mLink[l.mNext].mPrev = l.mPrev;
            mLink[l.mPrev].mNext = l.mNext;
        }

        void Unlink(SInt32 i, Link& l)
        {
            Unlink(i, l, (mHash[i] & UNSIGNED_HIBIT) ? mUnlinked : Mapi(i));
        }

        SInt32& Maph(UInt32 hash) const
        {
            UInt32 h = hash & ~UNSIGNED_HIBIT;
            return mMap[(mCount - 1) & (((h >> 23) - (h >> 15) - (h >> 7) - h))];
        }

        SInt32& Mapi(SInt32 i) const
        {
            return Maph(mHash[i]);
        }

        void FinishIndex()
        {
            SInt32 q = mLink.GetCount();
            mLink.Reserve(mHash.GetAlloc());
            mLink.AddN(mHash.GetCount() - q);
            for (SInt32 i = q; i < mHash.GetCount(); i++)
            {
                LinkTo(i, mLink[i], (mHash[i] & UNSIGNED_HIBIT) ? mUnlinked : Mapi(i));
            }
        }

        void DoIndex()
        {
            if (mHash.GetCount() < mCount)
            {
                FinishIndex();
            }
            else
            {
                Reindex();
            }
        }

        void Free()
        {
            Util::ReleaseArray(mMap);
            mCount = 0;
            mAlloc = 0;
        }

        UInt32 HashBound(UInt32 i)
        {
            UInt32 n = 1;
            while (n < i)
            {
                n <<= 1;
                if (n == 0)
                {
                    return 1 << 31;
                }
            }
            return n;
        }

        Array<UInt32> mHash;
        Array<Link> mLink;
        SInt32* mMap;
        SInt32 mCount;
        SInt32 mAlloc;
        SInt32 mUnlinked;
    };

    /**
     * @ingroup MurlClasses
     * @brief The default hash functor for objects.
     */
    template<class DataType>
    class StdHash
    {
    public:
        /** @brief The template parameter value type. */
        typedef DataType ValueType;

        /**
         * @brief Calculate the hash for an object of specified type.
         * @param x The reference to the object.
         * @return The hash value.
         */
        UInt32 operator()(const DataType& x) const
        {
            return Util::Hash::GetHashValue(x);
        }
    };

    /**
     * @ingroup MurlClasses
     * @brief The default hash functor for pointers.
     */
    class PtrHash
    {
    public:
        /**
         * @brief Calculate the hash for a pointer.
         * @param x The pointer to calculate the hash for.
         * @return The hash value.
         */
        UInt32 operator()(const void* x) const
        {
            return Util::Hash::GetPointerHashValue(x);
        }
    };
}

#endif // __MURL_HASH_H__
