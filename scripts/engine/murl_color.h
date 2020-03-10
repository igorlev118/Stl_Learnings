// Copyright 2010-2015 Spraylight GmbH

#ifndef __MURL_COLOR_H__
#define __MURL_COLOR_H__

#include "murl_math.h"

namespace Murl
{
    /**
     * @ingroup MurlClasses
     * @brief A color class.
     * This class holds four individual 32bit floating point values representing
     * an RGBA color, each of them with a "regular" range of 0.0 (black) to 1.0 (full color).
     * Actual values may lie beyond that range (in both directions), to define oversaturated
     * colors or even "negative" ones.
     *
     * When specified as an attribute value in an XML file, there exist
     * a number of different notations. For specifying multiple components in one value,
     * the following ones can be used:
     * - A 6-digit hex string representing an unsigned 24bit integer RGB color value (100% alpha)
     * - An 8-digit hex string representing an unsigned 32bit integer ARGB color value
     *
     * For these, a trailing 'h' character defines the hex notation.
     * For specifying individual values, either 3 (RGB) or 4 (RGBA) values must be given
     * as a comma-separated string. Each of these values must be postfixed by one of the
     * following characters:
     * - 'f' to specify a floating point value that directly maps to the internal range
     * - 'i' to specify an integer value, which will be divided by 255
     * - 'h' to specify a hex string, which will be converted and divided by 255
     *
     * String-to-color conversion in the described way can also be done from code, by using the
     * Util::StringToColor() function.
     *
     * Examples:
     * - "ffc080h": 100% alpha (implicitly), 100% red, 75% green and 50% blue (RGB)
     * - "40ffc080h": 25% alpha, 100% red, 75% green and 50% blue (ARGB)
     * - "1f,1f,1f,0.5f": 100% white with 50% alpha (RGBA)
     * - "128i,64i,192i": 50% red, 25% green, 75% blue and (implicitly) 100% alpha (RGB)
     * - "00h,00h,00h,ffh": black with 100% alpha (RGBA)
     * - "0.5f,128i,80h": 50% grey with (implicitly) 100% alpha (RGB)
     */
    class Color
    {
    public:
        /**
         * @brief The default constructor.
         */
        Color()
        {
            mColor[RED] = Float(1.0);
            mColor[GREEN] = Float(1.0);
            mColor[BLUE] = Float(1.0);
            mColor[ALPHA] = Float(1.0);
        }

        /**
         * @brief Constructor to set all color components to a given value.
         * @param value The value for the red, green, blue and alpha component.
         */
        Color(Float value)
        {
            mColor[RED] = value;
            mColor[GREEN] = value;
            mColor[BLUE] = value;
            mColor[ALPHA] = value;
        }

        /**
         * @brief Constructor to initialize a color with given component values.
         * @param red The red component.
         * @param green The green component.
         * @param blue The blue component.
         * @param alpha The alpha component.
         */
        Color(Float red, Float green, Float blue, Float alpha)
        {
            mColor[RED] = red;
            mColor[GREEN] = green;
            mColor[BLUE] = blue;
            mColor[ALPHA] = alpha;
        }

        /**
         * @brief Named constructor to set all components to a set of given
         * integer component values.
         * The integer values are divided by 255.
         * @param red The red integer component.
         * @param green The green integer component.
         * @param blue The blue integer component.
         * @param alpha The alpha integer component.
         * @return The color object.
         */
        static Color FromInt(SInt32 red, SInt32 green, SInt32 blue, SInt32 alpha)
        {
            return Color(Float(red) / Float(255.0), Float(green) / Float(255.0),
                         Float(blue) / Float(255.0), Float(alpha) / Float(255.0));
        }

        /**
         * @brief Set all components of the color instance to a set of given component values.
         * @param red The red component.
         * @param green The green component.
         * @param blue The blue component.
         * @param alpha The alpha component.
         */
        void Set(Float red, Float green, Float blue, Float alpha)
        {
            mColor[RED] = red;
            mColor[GREEN] = green;
            mColor[BLUE] = blue;
            mColor[ALPHA] = alpha;
        }

        /**
         * @brief Set all components of the color instance to a set of given
         * integer component values.
         * The integer values are divided by 255.
         * @param red The red integer component.
         * @param green The green integer component.
         * @param blue The blue integer component.
         * @param alpha The alpha integer component.
         */
        void SetInt(SInt32 red, SInt32 green, SInt32 blue, SInt32 alpha)
        {
            mColor[RED] = Float(red) / Float(255.0);
            mColor[GREEN] = Float(green) / Float(255.0);
            mColor[BLUE] = Float(blue) / Float(255.0);
            mColor[ALPHA] = Float(alpha) / Float(255.0);
        }

        /**
         * @brief Get the red component.
         * @return The red component.
         */
        Float GetRed() const
        {
            return mColor[RED];
        }

        /**
         * @brief Set the red component.
         * @param red The red component.
         */
        void SetRed(Float red)
        {
            mColor[RED] = red;
        }

        /**
         * @brief Get the red integer component.
         * The component is multiplied by 255.
         * @return The red integer component.
         */
        SInt32 GetRedInt() const
        {
            return SInt32(Math::Round(mColor[RED] * Float(255.0)));
        }

        /**
         * @brief Set the red integer component.
         * The component is divided by 255.
         * @param red The red integer component.
         */
        void SetRedInt(SInt32 red)
        {
            mColor[RED] = Float(red) / Float(255.0);
        }

        /**
         * @brief Get the green component.
         * @return The green component.
         */
        Float GetGreen() const
        {
            return mColor[GREEN];
        }

        /**
         * @brief Set the green component.
         * @param green The green component.
         */
        void SetGreen(Float green)
        {
            mColor[GREEN] = green;
        }

        /**
         * @brief Get the green integer component.
         * The component is multiplied by 255.
         * @return The green integer component.
         */
        SInt32 GetGreenInt() const
        {
            return SInt32(Math::Round(mColor[GREEN] * Float(255.0)));
        }

        /**
         * @brief Set the green integer component.
         * The component is divided by 255.
         * @param green The green integer component.
         */
        void SetGreenInt(SInt32 green)
        {
            mColor[GREEN] = Float(green) / Float(255.0);
        }

        /**
         * @brief Get the blue component.
         * @return The blue component.
         */
        Float GetBlue() const
        {
            return mColor[BLUE];
        }

        /**
         *  Set the blue component.
         * @param blue The blue component.
         */
        void SetBlue(Float blue)
        {
            mColor[BLUE] = blue;
        }

        /**
         * @brief Get the blue integer component.
         * The component is multiplied by 255.
         * @return The blue integer component.
         */
        SInt32 GetBlueInt() const
        {
            return SInt32(Math::Round(mColor[BLUE] * Float(255.0)));
        }

        /**
         * @brief Set the blue integer component.
         * The component is divided by 255.
         * @param blue The blue integer component.
         */
        void SetBlueInt(SInt32 blue)
        {
            mColor[BLUE] = Float(blue) / Float(255.0);
        }

        /**
         * @brief Get the alpha component.
         * @return The alpha component.
         */
        Float GetAlpha() const
        {
            return mColor[ALPHA];
        }

        /**
         * @brief Set the alpha component.
         * @param alpha The alpha component.
         */
        void SetAlpha(Float alpha)
        {
            mColor[ALPHA] = alpha;
        }

        /**
         * @brief Get the alpha integer component.
         * The component is multiplied by 255.
         * @return The alpha integer component.
         */
        SInt32 GetAlphaInt() const
        {
            return SInt32(Math::Round(mColor[ALPHA] * Float(255.0)));
        }

        /**
         * @brief Set the alpha integer component.
         * The component is divided by 255.
         * @param alpha The alpha integer component.
         */
        void SetAlphaInt(SInt32 alpha)
        {
            mColor[ALPHA] = Float(alpha) / Float(255.0);
        }

        /**
         * @brief Get the luminance (gray scale) value calculated from R, G and B.
         * Luminance calculation uses the standard conversion factors defined by
         * the Rec 601 standard which can be found in PAL and NTSC color models.
         * @return The luminance (R * 0.2990 + G * 0.5864 + B * 0.1146).
         */
        Float GetLuminance() const
        {
            return (mColor[RED]   * GetLuminanceRedWeight() +
                    mColor[GREEN] * GetLuminanceGreenWeight() +
                    mColor[BLUE]  * GetLuminanceBlueWeight());
        }

        /**
         * @brief Get the luminance (gray scale) integer value calculated from R, G and B.
         * Luminance calculation uses the standard conversion factors defined by the
         * Rec 601 standard which can be found in PAL and NTSC color models, multiplied by 255.
         * @return The integer luminance.
         */
        SInt32 GetLuminanceInt() const
        {
            return SInt32(Math::Round(GetLuminance() * Float(255.0)));
        }

        /**
         * @brief Get the 32 bit ABGR value of the color instance components.
         * @return The 32 bit ABGR value.
         */
        UInt32 ToUInt32() const
        {
            UInt32 red = UInt32(Math::Round(mColor[RED] * Float(255.0))) & 0xff;
            UInt32 green = UInt32(Math::Round(mColor[GREEN] * Float(255.0))) & 0xff;
            UInt32 blue = UInt32(Math::Round(mColor[BLUE] * Float(255.0))) & 0xff;
            UInt32 alpha = UInt32(Math::Round(mColor[ALPHA] * Float(255.0))) & 0xff;
            return red | (green << 8) | (blue << 16) | (alpha << 24);
        }

        /**
         * @brief Get the 32 bit ABGR value of the color instance components, clamped to the range [0..255].
         * @return The 32 bit ABGR value.
         */
        UInt32 ToUInt32Clamped() const
        {
            UInt32 red = Math::Clamp<SInt32>(Math::Round(mColor[RED] * Float(255.0)), 0, 255);
            UInt32 green = Math::Clamp<SInt32>(Math::Round(mColor[GREEN] * Float(255.0)), 0, 255);
            UInt32 blue = Math::Clamp<SInt32>(Math::Round(mColor[BLUE] * Float(255.0)), 0, 255);
            UInt32 alpha = Math::Clamp<SInt32>(Math::Round(mColor[ALPHA] * Float(255.0)), 0, 255);
            return red + (green << 8) + (blue << 16) + (alpha << 24);
        }

        /**
         * @brief Set the color instance components from a 32 bit ABGR value.
         * @param color The 32 bit ABGR value.
         */
        void FromUInt32(UInt32 color)
        {
            mColor[RED] = Float(color & 0xff) / Float(255.0);
            mColor[GREEN] = Float((color >> 8) & 0xff) / Float(255.0);
            mColor[BLUE] = Float((color >> 16) & 0xff) / Float(255.0);
            mColor[ALPHA] = Float(color >> 24) / Float(255.0);
        }

        /**
         * @brief Set the color instance components from a 32 bit ARGB value.
         * @param color The 32 bit ARBG value.
         */
        void FromUInt32ARGB(UInt32 color)
        {
            mColor[RED] = Float((color >> 16) & 0xff) / Float(255.0);
            mColor[GREEN] = Float((color >> 8) & 0xff) / Float(255.0);
            mColor[BLUE] = Float(color & 0xff) / Float(255.0);
            mColor[ALPHA] = Float(color >> 24) / Float(255.0);
        }

        /**
         * @brief Blend a given foreground color over this color using alpha blending
         *  in place.
         * @param foregroundColor The foreground color to blend.
         */
        void BlendSelf(const Color& foregroundColor)
        {
            Float fa = foregroundColor.mColor[ALPHA];
            if (fa != Float(0.0))
            {
                Float ba = mColor[ALPHA] * (Float(1.0) - fa);
                Float a = fa + ba;
                mColor[RED] = (foregroundColor.mColor[RED] * fa + mColor[RED] * ba) / a;
                mColor[GREEN] = (foregroundColor.mColor[GREEN] * fa + mColor[GREEN] * ba) / a;
                mColor[BLUE] = (foregroundColor.mColor[BLUE] * fa + mColor[BLUE] * ba) / a;
                mColor[ALPHA] = a;
            }
        }

        /**
         * @brief Blend a given foreground color over this color using alpha blending
         *  and return the blended color.
         * @param foregroundColor The foreground color to blend.
         * @return The alpha blended color.
         */
        Color Blend(const Color& foregroundColor) const
        {
            Color ret(*this);
            ret.BlendSelf(foregroundColor);
            return ret;
        }

        /**
         * @brief In-place addition operator.
         * @param color The color to add.
         * @return The object itself.
         */
        Color& operator+=(const Color& color)
        {
            mColor[RED] += color.mColor[RED];
            mColor[GREEN] += color.mColor[GREEN];
            mColor[BLUE] += color.mColor[BLUE];
            mColor[ALPHA] += color.mColor[ALPHA];
            return *this;
        }

        /**
         * @brief In-place subtraction operator.
         * @param color The color to subtract.
         * @return The object itself.
         */
        Color& operator-=(const Color& color)
        {
            mColor[RED] -= color.mColor[RED];
            mColor[GREEN] -= color.mColor[GREEN];
            mColor[BLUE] -= color.mColor[BLUE];
            mColor[ALPHA] -= color.mColor[ALPHA];
            return *this;
        }

        /**
         * @brief In-place multiplication operator.
         * @param color The color to multiply.
         * @return The object itself.
         */
        Color& operator*=(const Color& color)
        {
            mColor[RED] *= color.mColor[RED];
            mColor[GREEN] *= color.mColor[GREEN];
            mColor[BLUE] *= color.mColor[BLUE];
            mColor[ALPHA] *= color.mColor[ALPHA];
            return *this;
        }

        /**
         * @brief In-place multiplication operator.
         * @param value The value to multiply.
         * @return The object itself.
         */
        Color& operator*=(Float value)
        {
            mColor[RED] *= value;
            mColor[GREEN] *= value;
            mColor[BLUE] *= value;
            mColor[ALPHA] *= value;
            return *this;
        }

        /**
         * @brief In-place division operator.
         * @param color The color to divide.
         * @return The object itself.
         */
        Color& operator/=(const Color& color)
        {
            mColor[RED] /= color.mColor[RED];
            mColor[GREEN] /= color.mColor[GREEN];
            mColor[BLUE] /= color.mColor[BLUE];
            mColor[ALPHA] /= color.mColor[ALPHA];
            return *this;
        }

        /**
         * @brief In-place division operator.
         * @param value The value to divide.
         * @return The object itself.
         */
        Color& operator/=(Float value)
        {
            mColor[RED] /= value;
            mColor[GREEN] /= value;
            mColor[BLUE] /= value;
            mColor[ALPHA] /= value;
            return *this;
        }

        /**
         * @brief Addition operator.
         * @param color The right hand side color.
         * @return The added color.
         */
        Color operator+(const Color& color) const
        {
            Color ret = *this;
            ret += color;
            return ret;
        }

        /**
         * @brief Subtraction operator.
         * @param color The right hand side color.
         * @return The subtracted color.
         */
        Color operator-(const Color& color) const
        {
            Color ret = *this;
            ret -= color;
            return ret;
        }

        /**
         * @brief Multiplication operator.
         * @param color The right hand side color.
         * @return The multiplied color.
         */
        Color operator*(const Color& color) const
        {
            Color ret = *this;
            ret *= color;
            return ret;
        }

        /**
         * @brief Multiplication operator.
         * @param value The right hand side value.
         * @return The multiplied color.
         */
        Color operator*(Float value) const
        {
            Color ret = *this;
            ret *= value;
            return ret;
        }

        /**
         * @brief Division operator.
         * @param color The right hand side color.
         * @return The divided color.
         */
        Color operator/(const Color& color) const
        {
            Color ret = *this;
            ret /= color;
            return ret;
        }

        /**
         * @brief Division operator.
         * @param value The right hand side value.
         * @return The divided color.
         */
        Color operator/(Float value) const
        {
            Color ret = *this;
            ret /= value;
            return ret;
        }

        /**
         * @brief Check if the color instance is equal to a given second color.
         * Compares all values within the default epsilon range Limits::Epsilon().
         * @param color The color to compare.
         * @return true if all components are equal.
         */
        Bool IsEqual(const Color& color) const
        {
            return IsEqual(color, Math::Limits<Float>::Epsilon());
        }

        /**
         * @brief Check if the color instance is equal to a given second color.
         * Compares all values within a given epsilon range.
         * @param color The color to compare.
         * @param epsilon The epsilon to compare.
         * @return true if all components are equal.
         */
        Bool IsEqual(const Color& color, Float epsilon) const
        {
            return ((Math::Abs(mColor[RED] - color.mColor[RED]) < epsilon) &&
                    (Math::Abs(mColor[GREEN] - color.mColor[GREEN]) < epsilon) &&
                    (Math::Abs(mColor[BLUE] - color.mColor[BLUE]) < epsilon) &&
                    (Math::Abs(mColor[ALPHA] - color.mColor[ALPHA]) < epsilon));
        }

        /**
         * @brief Equal to comparison operator.
         * Performs a test without an epsilon range, which can be used
         * for detecting changes i.e. DoubleBuffer<Color> class.
         * To compare within an epsilon range use Color::IsEqual().
         * @param lhs The left hand side color to compare.
         * @param rhs The right hand side color to compare.
         * @return true if all components are exactly the same.
         */
        friend bool operator==(const Color& lhs, const Color& rhs)
        {
            return ((lhs.mColor[RED]   == rhs.mColor[RED])   &&
                    (lhs.mColor[GREEN] == rhs.mColor[GREEN]) &&
                    (lhs.mColor[BLUE]  == rhs.mColor[BLUE])  &&
                    (lhs.mColor[ALPHA] == rhs.mColor[ALPHA]));
        }

        /**
         * @brief Not equal to comparison operator.
         * Performs a test without an epsilon range, which can be used
         * for detecting changes i.e. DoubleBuffer<Color> class.
         * To compare within an epsilon range use Color::IsEqual().
         * @param lhs The left hand side color to compare.
         * @param rhs The right hand side color to compare.
         * @return true if all components are exactly the same.
         */
        friend bool operator!=(const Color& lhs, const Color& rhs)
        {
            return !operator==(lhs, rhs);
        }

        /**
         * @brief Get a const pointer to the raw components data.
         * @return Const pointer to the raw data.
         */
        const Float* GetRawComponents() const
        {
            return mColor;
        }

        /**
         * @brief Get a pointer to the raw components data.
         * @return Pointer to the raw data.
         */
        Float* GetRawComponents()
        {
            return mColor;
        }

        /**
         * @brief Get the string representation of the object.
         * @return The string representation of the object.
         */
        String ToString() const;

        /**
         * @brief Get the red component's weight for luminance conversion,
         * according to the ITU-R BT.601 standard.
         * @return The weight of the red component.
         */
        static Float GetLuminanceRedWeight()
        {
            return 0.2990f;
        }
        /**
         * @brief Get the green component's weight for luminance conversion,
         * according to the ITU-R BT.601 standard.
         * @return The weight of the green component.
         */
        static Float GetLuminanceGreenWeight()
        {
            return 0.5864f;
        }
        /**
         * @brief Get the blue component's weight for luminance conversion,
         * according to the ITU-R BT.601 standard.
         * @return The weight of the blue component.
         */
        static Float GetLuminanceBlueWeight()
        {
            return 0.1146f;
        }

        /**
         * @brief Enumeration of the components raw data.
         */
        enum Components
        {
            /** Index to the red component */
            RED = 0,
            /** Index to the green component */
            GREEN,
            /** Index to the blue component */
            BLUE,
            /** Index to the alpha component */
            ALPHA,

            /** Number of components */
            NUM_COMPONENTS
        };

        /**
         * @brief String formats
         */
        enum StringFormat
        {
            /** Unknown format */
            STRING_FORMAT_UNKNOWN,

            /** Float format, e.g. "0.75f,0.5f,0.25f,1f" (RGBA) */
            STRING_FORMAT_FLOAT,
            /** Integer format, e.g. "192i,128i,64i,255i" (RGBA) */
            STRING_FORMAT_INT,
            /** Hex format, e.g. "ffc08040h" (ARGB) */
            STRING_FORMAT_HEX,
            
            /** String contains different format identifiers  */
            STRING_FORMAT_MIXED,
            /** String does not contain a format identifier for all components */
            STRING_FORMAT_INCOMPLETE,
            
            /** Number of formats */
            NUM_STRING_FORMATS
        };

    protected:
        Float mColor[NUM_COMPONENTS];
    };
}

#endif  // __MURL_COLOR_H__
