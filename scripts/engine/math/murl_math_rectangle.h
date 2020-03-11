// Copyright 2010-2015 Spraylight GmbH

#ifndef __MURL_MATH_RECTANGLE_H__
#define __MURL_MATH_RECTANGLE_H__

#include "murl_math_types.h"
#include "murl_util_string.h"

namespace Murl
{
    namespace Math
    {
        /**
         * @ingroup MurlMathClasses
         * @brief A rectangle class with 2D coordinates.
         */
        template<class DataType>
        class Rectangle
        {
        public:
            /** @brief The template parameter value type. */
            typedef DataType ValueType;

            /**
             * @brief The default constructor.
             * Create an empty rectangle with the following properties:
             *  - The lower coordinates GetX1() and GetY1() contains the DataType's maximum value.
             *  - The higher coordinates GetX2() and GetY2() contains the DataType's minimum value.
             *  - In this case the dimension GetSizeX() and GetSizeY() returns zero.
             *
             * This allowes to Include() a point in an empty rectangle which
             * sets the lower and higher coordinates to the included point.
             */
            Rectangle()
            : mX1(DataType(Limits<DataType>::Max()))
            , mY1(DataType(Limits<DataType>::Max()))
            , mX2(DataType(Limits<DataType>::Min()))
            , mY2(DataType(Limits<DataType>::Min()))
            {
            }

            /**
             * @brief Constructor to initialize a rectangle with given coordinates.
             * Takes care of setting the lower and higher coordinates correctly.
             * @param x1 The X coordinate of the first point.
             * @param y1 The Y coordinate of the first point.
             * @param x2 The X coordinate of the second point.
             * @param y2 The Y coordinate of the second point.
             */
            Rectangle(DataType x1, DataType y1, DataType x2, DataType y2)
            {
                Set(x1, y1, x2, y2);
            }

            /**
             * @brief The copy constructor using a rectangle of different type.
             * @param r The rectangle to copy.
             */
            template<class DataType2>
            Rectangle(const Rectangle<DataType2>& r)
            : mX1(r.GetX1())
            , mY1(r.GetY1())
            , mX2(r.GetX2())
            , mY2(r.GetY2())
            {
            }

            /**
             * @brief Copy the content of a source rectangle to the rectangle instance.
             * @param other The rectangle to copy from.
             */
            void Set(const Rectangle& other)
            {
                mX1 = other.mX1;
                mY1 = other.mY1;
                mX2 = other.mX2;
                mY2 = other.mY2;
            }

            /**
             * @brief Set all coordinates of the rectangle instance to a set of given coordinates.
             * Takes care of setting the lower and higher coordinates correctly.
             * @param x1 The X coordinate of the first point.
             * @param y1 The Y coordinate of the first point.
             * @param x2 The X coordinate of the second point.
             * @param y2 The Y coordinate of the second point.
             */
            void Set(DataType x1, DataType y1, DataType x2, DataType y2)
            {
                if (x1 < x2)
                {
                    mX1 = x1;
                    mX2 = x2;
                }
                else
                {
                    mX1 = x2;
                    mX2 = x1;
                }

                if (y1 < y2)
                {
                    mY1 = y1;
                    mY2 = y2;
                }
                else
                {
                    mY1 = y2;
                    mY2 = y1;
                }
            }

            /**
             * @brief Set the horizontal start coordinate.
             * This sets the coordinate without taking care about lower and higher coordinates.
             * @param x1 The X coordinate of the first point.
             */
            void SetX1(DataType x1)
            {
                mX1 = x1;
            }

            /**
             * @brief Set the vertical start coordinate.
             * This sets the coordinate without taking care about lower and higher coordinates.
             * @param y1 The Y coordinate of the first point.
             */
            void SetY1(DataType y1)
            {
                mY1 = y1;
            }

            /**
             * @brief Set the horizontal end coordinate.
             * This sets the coordinate without taking care about lower and higher coordinates.
             * @param x2 The X coordinate of the second point.
             */
            void SetX2(DataType x2)
            {
                mX2 = x2;
            }

            /**
             * @brief Set the vertical end coordinate.
             * This sets the coordinate without taking care about lower and higher coordinates.
             * @param y2 The Y coordinate of the second point.
             */
            void SetY2(DataType y2)
            {
                mY2 = y2;
            }

            /**
             * @brief Set the x / y coordinate and the horizontal / vertical size of the rectangle.
             * @param x The X coordinate of the first point.
             * @param y The Y coordinate of the first point.
             * @param sizeX The horizontal size of the rectangle.
             * @param sizeY The vertical size of the rectangle.
             */
            void SetPositionAndSize(DataType x, DataType y, DataType sizeX, DataType sizeY)
            {
                mX1 = x;
                mY1 = y;
                mX2 = x + sizeX;
                mY2 = y + sizeY;
            }

            /**
             * @brief Set the horizontal and vertical size of the rectangle.
             * @param sizeX The horizontal size of the rectangle.
             * @param sizeY The vertical size of the rectangle.
             */
            void SetSize(DataType sizeX, DataType sizeY)
            {
                mX2 = mX1 + sizeX;
                mY2 = mY1 + sizeY;
            }

            /**
             * @brief Set the horizontal size of the rectangle.
             * @param size The horizontal size of the rectangle.
             */
            void SetSizeX(DataType size)
            {
                mX2 = mX1 + size;
            }

            /**
             * @brief Set the vertical size of the rectangle.
             * @param size The vertical size of the rectangle.
             */
            void SetSizeY(DataType size)
            {
                mY2 = mY1 + size;
            }

            /**
             * @brief Get the lower X coordinate.
             * @return The lower X coordinate.
             */
            DataType GetX1() const
            {
                return mX1;
            }

            /**
             * @brief Get the lower Y coordinate.
             * @return The lower Y coordinate.
             */
            DataType GetY1() const
            {
                return mY1;
            }

            /**
             * @brief Get the higher X coordinate.
             * @return The higher X coordinate.
             */
            DataType GetX2() const
            {
                return mX2;
            }

            /**
             * @brief Get the higher Y coordinate.
             * @return The higher Y coordinate.
             */
            DataType GetY2() const
            {
                return mY2;
            }

            /**
             * @brief Get the horizontal size of the rectangle.
             * @return The horizontal size of the rectangle or zero
             *  if the lower coordinate is greater than the higher coordinated.
             */
            DataType GetSizeX() const
            {
                return Max(mX2 - mX1, DataType(0));
            }

            /**
             * @brief Get the vertical size of the rectangle.
             * @return The vertical size of the rectangle or zero
             *  if the lower coordinate is greater than the higher coordinated.
             */
            DataType GetSizeY() const
            {
                return Max(mY2 - mY1, DataType(0));
            }

            /**
             * @brief Get the area occupied by the rectangle.
             * @return The area, i.e. GetSizeX() * GetSizeY();
             */
            DataType GetArea() const
            {
                return GetSizeX() * GetSizeY();
            }

            /**
             * @brief Unite this rectangle with another rectangle.
             * @param other The other rectangle to unite.
             */
            void Unite(const Rectangle& other)
            {
                mX1 = Min(mX1, other.mX1);
                mY1 = Min(mY1, other.mY1);
                mX2 = Max(mX2, other.mX2);
                mY2 = Max(mY2, other.mY2);
            }

            /**
             * @brief Intersect this rectangle with another rectangle.
             * @param other The other rectangle to intersect.
             */
            void Intersect(const Rectangle& other)
            {
                mX1 = Max(mX1, other.mX1);
                mY1 = Max(mY1, other.mY1);
                mX2 = Min(mX2, other.mX2);
                mY2 = Min(mY2, other.mY2);
                mX2 = Max(mX2, mX1);
                mY2 = Max(mY2, mY1);
            }

            /**
             * @brief Include a point in this rectangle.
             * Sets the lower and higher coordinates to the included point
             * if the rectangle is empty, see default constructor Rectangle().
             * @param x The x-position of the point to include.
             * @param y The y-position of the point to include.
             */
            void Include(DataType x, DataType y)
            {
                mX1 = Min(mX1, x);
                mY1 = Min(mY1, y);
                mX2 = Max(mX2, x);
                mY2 = Max(mY2, y);
            }

            /**
             * @brief Check if a given rectangle is intersecting this rectangle.
             * @param other The other rectangle to check.
             * @return true if the other rectangle is intersecting this rectangle.
             */
            Bool IsIntersecting(const Rectangle& other) const
            {
                if (mX2 < other.mX1)
                {
                    return false;
                }
                if (mY2 < other.mY1)
                {
                    return false;
                }

                if (mX1 > other.mX2)
                {
                    return false;
                }
                if (mY1 > other.mY2)
                {
                    return false;
                }

                return true;
            }

            /**
             * @brief Check if a given rectangle is empty, i.e. its area is zero.
             * @return true if the rectangle is empty.
             */
            Bool IsEmpty() const
            {
                return (GetArea() <= DataType(0));
            }

            /**
             * @brief Check if the rectangle instance is equal to a given second rectangle.
             * Compares all values within the default epsilon range Limits::Epsilon().
             * @param r The rectangle to compare.
             * @return true if equal to the compared rectangle.
             */
            Bool IsEqual(const Rectangle& r) const
            {
                return IsEqual(r, Limits<DataType>::Epsilon());
            }

            /**
             * @brief Check if the rectangle instance is equal to a given second rectangle.
             * Compares all values within a given epsilon range.
             * @param r The rectangle to compare.
             * @param epsilon The epsilon to compare.
             * @return true if equal to the compared rectangle.
             */
            Bool IsEqual(const Rectangle& r, DataType epsilon) const
            {
                return ((Math::Abs(mX1 - r.mX1) < epsilon) && (Math::Abs(mY1 - r.mY1) < epsilon) &&
                        (Math::Abs(mX2 - r.mX2) < epsilon) && (Math::Abs(mY2 - r.mY2) < epsilon));
            }

            /**
             * @brief Equal to comparison operator.
             * Performs a test without an epsilon range, which can be used
             * for detecting changes i.e. DoubleBuffer<Rectangle> class.
             * To compare within an epsilon range use Rectangle::IsEqual().
             * @param lhs The left hand side rectangle to compare.
             * @param rhs The right hand side rectangle to compare.
             * @return true if all components are exactly the same.
             */
            friend bool operator==(const Rectangle<DataType>& lhs, const Rectangle<DataType>& rhs)
            {
                return ((lhs.mX1 == rhs.mX1) && (lhs.mY1 == rhs.mY1) &&
                        (lhs.mX2 == rhs.mX2) && (lhs.mY2 == rhs.mY2));
            }

            /**
             * @brief Not equal to comparison operator.
             * Performs a test without an epsilon range, which can be used
             * for detecting changes i.e. DoubleBuffer<Rectangle> class.
             * To compare within an epsilon range use Rectangle::IsEqual().
             * @param lhs The left hand side rectangle to compare.
             * @param rhs The right hand side rectangle to compare.
             * @return true if all components are not exactly the same.
             */
            friend bool operator!=(const Rectangle<DataType>& lhs, const Rectangle<DataType>& rhs)
            {
                return !operator==(lhs, rhs);
            }

            /**
             * @brief Get the string representation of the object.
             * @return The string representation of the object.
             */
            String ToString() const
            {
                return Util::PrintToString("%f, %f - %f, %f",
                                           Double(mX1), Double(mY1), Double(mX2), Double(mY2));
            }

        protected:
            /** @brief The lower X coordinate. */
            DataType mX1;
            /** @brief The lower Y coordinate. */
            DataType mY1;
            /** @brief The higher X coordinate. */
            DataType mX2;
            /** @brief The higher Y coordinate. */
            DataType mY2;
        };
    }
}

#endif // __MURL_MATH_RECTANGLE_H__
