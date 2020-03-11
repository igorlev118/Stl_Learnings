// Copyright 2010-2015 Spraylight GmbH

#ifndef __MURL_MATH_BIG_INTEGER_H__
#define __MURL_MATH_BIG_INTEGER_H__

#include "murl_math_types.h"
#include "murl_data.h"

namespace Murl
{
    namespace Math
    {
        /**
         * @ingroup MurlMathClasses
         * @brief An integer of variable capacity.
         */
        class BigInteger
        {
        public:
            /**
             * @brief A predefined big-integer object with value zero.
             */
            static const BigInteger ZERO;
            /**
             * @brief A predefined big-integer object with value one.
             */
            static const BigInteger ONE;
            /**
             * @brief A predefined big-integer object with value two.
             */
            static const BigInteger TWO;

            /**
             * @brief Create a big-integer object from a data object.
             * Takes the bytes from the data object:
             *  - The first byte is the most significant byte.
             *  - The last byte is the least significant byte.
             *  - The sign is always positive.
             * @param data The data object.
             * @return The created big-integer object.
             */
            static BigInteger FromData(const ConstData& data);
            /**
             * @brief Create a big-integer object from a memory location.
             * Takes the bytes from the memory location:
             *  - The first byte is the most significant byte.
             *  - The last byte is the least significant byte.
             *  - The sign is always positive.
             * @param data The pointer to the memory location.
             * @param byteSize The number of bytes to read from the memory location.
             * @return The created big-integer object.
             */
            static BigInteger FromData(const UInt8* data, UInt32 byteSize);
            /**
             * @brief Create a big-integer object from a Hex character string.
             * The sign can be specified by a '+' or '-' prefix character.
             * @param str The Hex character string.
             * @return The created big-integer object.
             */
            static BigInteger FromHexString(const String& str);

            /**
             * @brief The default constuctor.
             * The value is set to zero.
             */
            BigInteger();
            /**
             * @brief Copy constructor with reserved digit count.
             * @param reservedDigits The number of digits to reserve.
             * @param other The big-integer object to copy.
             */
            BigInteger(const BigInteger& other, UInt32 reservedDigits);
            /**
             * @brief Copy constructor taking an unsigned 32 bit integer.
             * @param value The unsigned integer to copy.
             */
            BigInteger(UInt32 value);
            /**
             * @brief Copy constructor taking a signed 32 bit integer.
             * @param value The signed integer to copy.
             */
            BigInteger(SInt32 value);
            /**
             * @brief Copy constructor taking an unsigned 64 bit integer.
             * @param value The unsigned integer to copy.
             */
            BigInteger(UInt64 value);
            /**
             * @brief Copy constructor taking a signed 64 bit integer.
             * @param value The signed integer to copy.
             */
            BigInteger(SInt64 value);
            /**
             * @brief Copy constructor taking a decimal string.
             * The sign can be specified by a '+' or '-' prefix character.
             * @param value The decimal string to convert.
             */
            BigInteger(const String& value);

            /**
             * @brief Set the value to zero.
             */
            void Clear();

            /**
             * @brief Copy the value to from a big-integer object.
             * @param other The big-integer object to copy.
             */
            void Set(const BigInteger& other);
            /**
             * @brief Copy the value to from a big integer object and reserve digits.
             * @param reservedDigits The number of digits to reserve.
             * @param other The big-integer object to copy.
             */
            void Set(const BigInteger& other, UInt32 reservedDigits);
            /**
             * @brief Copy the value to from an signed 32 bit integer.
             * @param value The signed 32 bit integer to copy.
             */
            void SetSInt32(SInt32 value);
            /**
             * @brief Copy the value to from an unsigned 32 bit integer.
             * @param value The unsigned 32 bit integer to copy.
             */
            void SetUInt32(UInt32 value);
            /**
             * @brief Copy the value to from an signed 64 bit integer.
             * @param value The signed 64 bit integer to copy.
             */
            void SetSInt64(SInt64 value);
            /**
             * @brief Copy the value to from an unsigned 64 bit integer.
             * @param value The unsigned 64 bit integer to copy.
             */
            void SetUInt64(UInt64 value);
            /**
             * @brief Convert the value to from a decimal string.
             * The sign can be specified by a '+' or '-' prefix character.
             * @param value The decimal string to convert.
             */
            void SetString(const String& value);

            /**
             * @brief Compare a big-integer object to this.
             * @param other The big-integer object to compare.
             * @return 0 if equal, -1 if this is lesser than the other
             *  or 1 this is greater than the other.
             */
            SInt32 CompareTo(const BigInteger& other) const;
            /**
             * @brief Absolute compare a big-integer object to this.
             * @param other The big-integer object to compare.
             * @return 0 if equal, -1 if this is lesser than the other
             *  or 1 this is greater than the other.
             */
            SInt32 CompareToAbsolute(const BigInteger& other) const;

            /**
             * @brief Get the number of bytes used by the value.
             * @return The number of bytes used by the value.
             */
            UInt32 GetLength() const;

            /**
             * @brief Get a byte from the value at a specified index.
             * Index 0 is the least significant byte.
             * @param index The index of the byte in range [0 .. GetLength() - 1].
             * @return The byte from the value at the specified index
             *  or zero if the index is out of range.
             */
            UInt8 GetByteAt(UInt32 index) const;
            /**
             * @brief Set a byte of the value at a specified index.
             * The value is expanded if the index is out of range.
             * Index 0 is the least significant byte.
             * @param index The index of the byte.
             * @param byte The byte to set.
             * @return true if successful.
             */
            Bool SetByteAt(UInt32 index, UInt8 byte);

            /**
             * @brief Get a bit from the value at a specified index.
             * Index 0 is the least significant bit.
             * @param index The index of the bit in range [0 .. GetLength() * 8 - 1].
             * @return The bit from the value at the specified index
             *  or false if the index is out of range.
             */
            Bool GetBitAt(UInt32 index) const;
            /**
             * @brief Set a bit of the value at a specified index.
             * The value is expanded if the index is out of range.
             * Index 0 is the least significant bit.
             * @param index The index of the bit.
             * @param bit The bit to set.
             * @return true if successful.
             */
            Bool SetBitAt(UInt32 index, Bool bit);

            /**
             * @brief Check if the value is zero.
             * @return true if the value is zero.
             */
            Bool IsZero() const;
            /**
             * @brief Check if the value is one.
             * @return true if the value is one.
             */
            Bool IsOne() const;
            /**
             * @brief Check if the value is positive.
             * @return true if the value is positive.
             */
            Bool IsPositive() const;
            /**
             * @brief Check if the value is negative.
             * @return true if the value is negative.
             */
            Bool IsNegative() const;
            /**
             * @brief Check if the value is even.
             * @return true if the value is even.
             */
            Bool IsEven() const;
            /**
             * @brief Check if the value is odd.
             * @return true if the value is odd.
             */
            Bool IsOdd() const;

            /**
             * @brief Get the inverted value.
             * @return The inverted big-integer object.
             */
            BigInteger Invert() const;
            /**
             * @brief Get the absolute value.
             * @return The absolute big-integer object.
             */
            BigInteger Abs() const;

            /**
             * @brief Add this and a big-integer object.
             * @param other The big-integer object to add.
             * @return The added big-integer object.
             */
            BigInteger Add(const BigInteger& other) const;
            /**
             * @brief Subtract this and a big-integer object.
             * @param other The big-integer object to subtract.
             * @return The subtracted big-integer object.
             */
            BigInteger Subtract(const BigInteger& other) const;
            /**
             * @brief Multiply this by a big-integer object.
             * @param other The big-integer object to multiply.
             * @return The multiplied big-integer object.
             */
            BigInteger Multiply(const BigInteger& other) const;
            /**
             * @brief Divide this by a big-integer object.
             * @param other The big-integer object to divide.
             * @return The divided big-integer object.
             */
            BigInteger Divide(const BigInteger& other) const;
            /**
             * @brief Divide this by a big-integer object.
             * @param other The big-integer object to divide.
             * @param remainder The remainder return value.
             * @return The divided big-integer object.
             */
            BigInteger Divide(const BigInteger& other, BigInteger& remainder) const;
            /**
             * @brief Divide this by a big-integer object and return the remainder.
             * @param other The big-integer object to divide.
             * @return The remainder big-integer object.
             */
            BigInteger Modulo(const BigInteger& other) const;
            /**
             * @brief Get this raised to the power of an integer exponent.
             * @param n The integer exponent.
             * @return The exponentiated big-integer object.
             */
            BigInteger Power(UInt32 n) const;
            /**
             * @brief Get this raised to the power of a big-integer exponent.
             * @param n The big-integer exponent.
             * @return The exponentiated big-integer object.
             */
            BigInteger Power(const BigInteger& n) const;
            /**
             * @brief Divide this raised to the power of a big-integer exponent
             *  by a big-integer object and return the remainder.
             * @param n The big-integer exponent.
             * @param m The big-integer object to divide.
             * @return The remainder big-integer object.
             */
            BigInteger PowerModulo(const BigInteger& n, const BigInteger& m) const;

            /**
             * @brief Multiply this by a big-integer object.
             * @param other The big-integer object to multiply.
             * @param result The multiplied big-integer object.
             */
            void Multiply(const BigInteger& other, BigInteger& result) const;

            /**
             * @brief Get the greatest common divisor of this.
             * @param other The big-integer object to divide.
             * @return Get the greatest common divisor of this.
             */
            BigInteger GreatestCommonDivisor(const BigInteger& other) const;

            /**
             * @brief Invert the big-integer value.
             */
            void InvertSelf();
            /**
             * @brief Make the big-integer value absolute.
             */
            void AbsSelf();

            /**
             * @brief Move left the bytes of the value.
             * @param bytes The number of bytes to move.
             */
            void MoveBytesLeftSelf(UInt32 bytes);
            /**
             * @brief Move right the bytes of the value.
             * @param bytes The number of bytes to move.
             */
            void MoveBytesRightSelf(UInt32 bytes);

            /**
             * @brief Add a big-integer object to this.
             * @param other The big-integer object to add.
             */
            void AddSelf(const BigInteger& other);
            /**
             * @brief Subtract a big-integer object to this.
             * @param other The big-integer object to subtract.
             */
            void SubtractSelf(const BigInteger& other);
            /**
             * @brief Multiply this by a big-integer object.
             * @param other The big-integer object to multiply.
             */
            void MultiplySelf(const BigInteger& other);
            /**
             * @brief Divide this by a big-integer object.
             * @param other The big-integer object to divide.
             */
            void DivideSelf(const BigInteger& other);
            /**
             * @brief Divide this by a big-integer object.
             * @param other The big-integer object to divide.
             * @param remainder The remainder return value.
             */
            void DivideSelf(const BigInteger& other, BigInteger& remainder);
            /**
             * @brief Divide this by a big-integer object and store the remainder.
             * @param other The big-integer object to divide.
             */
            void ModuloSelf(const BigInteger& other);
            /**
             * @brief Raise this to the power of an integer exponent.
             * @param n The integer exponent.
             */
            void PowerSelf(UInt32 n);
            /**
             * @brief Raise this to the power of a big-integer exponent.
             * @param n The big-integer exponent.
             */
            void PowerSelf(const BigInteger& n);
            /**
             * @brief Divide this raised to the power of a big-integer exponent
             *  by a big-integer object and store the remainder.
             * @param n The big-integer exponent.
             * @param m The big-integer object to divide.
             */
            void PowerModuloSelf(const BigInteger& n, const BigInteger& m);

            /**
             * @brief Get the Hex character string of the value.
             * @return The Hex character string of the value.
             */
            String ToHexString() const;
            /**
             * @brief Get the data object of the value.
             * Stores the value bytes to a data object:
             *  - The first byte is the most significant byte.
             *  - The last byte is the least significant byte.
             *  - The sign is not stored.
             * @param length The number of bytes in the data object.
             *  Zero length adjusts the size of the data object to the number of bytes of the value.
             *  If the length is too small the most significant bytes are truncated.
             * @return The the data object of the value.
             */
            Data ToData(UInt32 length = 0) const;
            /**
             * @brief Get the 32 bit unsigned integer value.
             * @param start The index of the byte to start in range [0 .. GetLength() - 1].
             * @param count The number of bytes to get.
             * @return The 32 bit unsigned integer value.
             */
            UInt32 ToUInt32(UInt32 start, UInt32 count) const;
            /**
             * @brief Get the 64 bit unsigned integer value.
             * @param start The index of the byte to start in range [0 .. GetLength() - 1].
             * @param count The number of bytes to get.
             * @return The 64 bit unsigned integer value.
             */
            UInt64 ToUInt64(UInt32 start, UInt32 count) const;

            /**
             * @brief Equal to comparison operator.
             * @param rhs The right hand side big-integer object to compare.
             * @return true if the value and sign are equal.
             */
            bool operator==(const BigInteger& rhs) const;
            /**
             * @brief Not equal to comparison operator.
             * @param rhs The right hand side big-integer object to compare.
             * @return true if the value and sign are not equal.
             */
            bool operator!=(const BigInteger& rhs) const;
            /**
             * @brief Less than operator.
             * @param rhs The right hand side big-integer object to compare.
             * @return true if the left hand side (this) is
             * less than the right hand side.
             */
            bool operator<(const BigInteger& rhs) const;
            /**
             * @brief Greater than operator.
             * @param rhs The right hand side big-integer object to compare.
             * @return true if the left hand side (this) is
             * greater than the right hand side.
             */
            bool operator>(const BigInteger& rhs) const;
            /**
             * @brief Less than or equal to operator.
             * @param rhs The right hand side big-integer object to compare.
             * @return true if the left hand side (this) is
             * less than or equal to the right hand side.
             */
            bool operator<=(const BigInteger& rhs) const;
            /**
             * @brief Greater than or equal to operator.
             * @param rhs The right hand side big-integer object to compare.
             * @return true if the left hand side (this) is
             * greater than or equal to the right hand side.
             */
            bool operator>=(const BigInteger& rhs) const;

            /**
             * @brief Assignment operator for big-integer object.
             * @param value The value to assign.
             * @return The object itself.
             */
            BigInteger& operator=(const BigInteger& value);
            /**
             * @brief Assignment operator for signed 32 bit integer.
             * @param value The value to assign.
             * @return The object itself.
             */
            BigInteger& operator=(SInt32 value);
            /**
             * @brief Assignment operator for unsigned 32 bit integer.
             * @param value The value to assign.
             * @return The object itself.
             */
            BigInteger& operator=(UInt32 value);
            /**
             * @brief Assignment operator for signed 64 bit integer.
             * @param value The value to assign.
             * @return The object itself.
             */
            BigInteger& operator=(SInt64 value);
            /**
             * @brief Assignment operator for unsigned 64 bit integer.
             * @param value The value to assign.
             * @return The object itself.
             */
            BigInteger& operator=(UInt64 value);
            /**
             * @brief Assignment operator for decimal string.
             * The sign can be specified by a '+' or '-' prefix character.
             * @param value The value to assign.
             * @return The object itself.
             */
            BigInteger& operator=(const String& value);

            /**
             * @brief Unary plus operator.
             * @return A copy of the object.
             */
            BigInteger operator+() const;
            /**
             * @brief Unary minus operator.
             * @return A copy of the inverted object.
             */
            BigInteger operator-() const;

            /**
             * @brief Increment prefix operator.
             * @return The incremented object itself.
             */
            BigInteger& operator++();
            /**
             * @brief Increment suffix operator.
             * @return A copy of the object before incrementation.
             */
            BigInteger operator++(SInt32);
            /**
             * @brief Decrement prefix operator.
             * @return The decremented object itself.
             */
            BigInteger& operator--();
            /**
             * @brief Decrement suffix operator.
             * @return A copy of the object before decrementation.
             */
            BigInteger operator--(SInt32);

            /**
             * @brief Bitwise left shift operator.
             * @param bits The number of bits to shift.
             * @return The shifted object.
             */
            BigInteger operator<<(UInt32 bits) const;
            /**
             * @brief Bitwise right shift operator.
             * @param bits The number of bits to shift.
             * @return The shifted object.
             */
            BigInteger operator>>(UInt32 bits) const;

            /**
             * @brief Addition operator.
             * @param rhs The right hand side big-integer object to add.
             * @return The added big-integer object.
             */
            BigInteger operator+(const BigInteger& rhs) const;
            /**
             * @brief Subtraction operator.
             * @param rhs The right hand side big-integer object to subtract.
             * @return The subtracted big-integer object.
             */
            BigInteger operator-(const BigInteger& rhs) const;
            /**
             * @brief Multiplication operator.
             * @param rhs The right hand side big-integer object to multiply.
             * @return The multiplied big-integer object.
             */
            BigInteger operator*(const BigInteger& rhs) const;
            /**
             * @brief Division operator.
             * @param rhs The right hand side big-integer object to divide.
             * @return The divided big-integer object.
             */
            BigInteger operator/(const BigInteger& rhs) const;
            /**
             * @brief Modulo operator.
             * @param rhs The right hand side big-integer object to divide.
             * @return The remainder big-integer object.
             */
            BigInteger operator%(const BigInteger& rhs) const;

            /**
             * @brief In-place bitwise left shift operator.
             * @param bits The number of bits to shift.
             * @return The object itself.
             */
            BigInteger& operator<<=(UInt32 bits);
            /**
             * @brief In-place bitwise right shift operator.
             * @param bits The number of bits to shift.
             * @return The object itself.
             */
            BigInteger& operator>>=(UInt32 bits);

            /**
             * @brief In-place addition operator.
             * @param other The big-integer object to add.
             * @return The object itself.
             */
            BigInteger& operator+=(const BigInteger& other);
            /**
             * @brief In-place subtraction operator.
             * @param other The big-integer object to subtract.
             * @return The object itself.
             */
            BigInteger& operator-=(const BigInteger& other);
            /**
             * @brief In-place multiplication operator.
             * @param other The big-integer object to multiply.
             * @return The object itself.
             */
            BigInteger& operator*=(const BigInteger& other);
            /**
             * @brief In-place division operator.
             * @param other The big-integer object to divide.
             * @return The object itself.
             */
            BigInteger& operator/=(const BigInteger& other);
            /**
             * @brief In-place modulo operator.
             * @param other The big-integer object to divide.
             * @return The object itself.
             */
            BigInteger& operator%=(const BigInteger& other);

        private:
            BigInteger DoDivide(const BigInteger& other, BigInteger* remainder) const;

            BigInteger MultiplySlow(const BigInteger& other) const;
            BigInteger MultiplyFast(const BigInteger& other) const;

            void DoAdd(UInt8* shorter, UInt32 nShorter, UInt8* longer, UInt32 nLonger, UInt8* result, SInt32 nResult, bool doFill) const;
            UInt32 DoAddFast(UInt8* a, UInt8* b, UInt32 n) const;
            void DoSubtractFast(UInt8* a, UInt8* b, UInt8* end, UInt32 n) const;
            void DoMultiplyFast(UInt8* a, UInt8* b, UInt32 n, UInt8* buf1) const;

            void AdjustLength();

            UInt8Array mDigits;
            Bool mIsPositive;
        };
    }
}

#endif // __MURL_MATH_BIG_INTEGER_H__
