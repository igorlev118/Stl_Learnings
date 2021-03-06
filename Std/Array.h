#pragma once
#include <assert.h>
#include "Iterator.h"

namespace StlStd
{
	template<typename T, size_t size>
	class Array
	{
	public:
		using Iterator = RandomAccessIterator<T>;
		using ConstIterator = RandomAccessConstIterator<T>;

	public:
		Array()
		{}

		Array(const T& value)
		{
			for (size_t i = 0; i < size; ++i)
				m_Data[i] = value;
		}

		~Array()
		{}

		void Fill(const T& value)
		{
			for (size_t i = 0; i < size; ++i)
				m_Data[i] = value;
		}

		void Swap(Array& other)
		{
			StlStd::Swap((T*&)m_Data, (T*&)other.m_Data);
		}

		T& operator[](size_t index) { return m_Data[index]; }
		const T& operator[](size_t index) const { return m_Data[index]; }

		T& At(size_t index) { assert(index < size); return m_Data[index]; }
		const T& At(size_t index) const { assert(index < size); return m_Data[index]; }

		T& Front() { assert(size > 0);  return m_Data[0]; }
		T& Back() { assert(size > 0);  return m_Data[size - 1]; }

		T* Data() { return &m_Data[0]; }
		const T* Data() const { return &m_Data[0]; }

		Iterator begin() { return Iterator(m_Data); }
		Iterator end() { return Iterator(m_Data + size - 1); }
		ConstIterator begin() const { return ConstIterator(m_Data); }
		ConstIterator end() const { return ConstIterator(m_Data + size - 1); }

		Iterator Begin() { return Iterator(m_Data); }
		Iterator End() { return Iterator(m_Data + size - 1); }
		ConstIterator Begin() const { return ConstIterator(m_Data); }
		ConstIterator End() const { return ConstIterator(m_Data + size - 1); }

		constexpr size_t Size() const { return size; }
		constexpr size_t MaxSize() const { size_t nr = 0; nr = ~nr; return nr; }
		constexpr bool Empty() const { return size == 0; }

	private:
		T m_Data[size];
	};

	template<typename T, size_t size>
	inline void Swap(Array<T, size>& a, Array<T, size>& b)
	{
		a.Swap(b);
	}
}