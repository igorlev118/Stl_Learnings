// Copyright 2010-2013 Spraylight GmbH

#ifndef __MURL_UTIL_ATTRIBUTES_BASE_H__
#define __MURL_UTIL_ATTRIBUTES_BASE_H__

#include "murl_i_attributes.h"

namespace Murl
{
    namespace Util
    {
        class Evaluator;

        /**
         * @ingroup MurlUtilClasses
         * @brief The attributes base class, see IAttributes.
         */
        class AttributesBase : public IAttributes
        {
        public:
            /**
             * @brief The default constructor.
             */
            AttributesBase();
            /**
             * @brief The destructor.
             */
            virtual ~AttributesBase();

            /**
             * @brief Evaluate the attribute values inside curly braces.
             * @param params The attributes for value substituion inside braces or null.
             * @param value The substituted string return value.
             * @param error The error return value is set to true if evaluation failed.
             * @return true if successful, false if the attribute has no value or if error is true.
             */
            Bool EvaluateParameters(const IAttributes* params, String& value, Bool& error) const;
            /**
             * @brief Evaluate the attribute values inside curly braces.
             * @param params The attributes for value substituion inside braces or null.
             * @param value The substituted string return value.
             * @param result An error message is appended to this object if evaluation failed.
             * @return true if successful, false if the attribute has no value or if error is true.
             */
            Bool EvaluateParameters(const IAttributes* params, String& value, Result& result) const;

            virtual Bool EvaluateExpression(const Char* expression, String& value, Bool& error) const;
            virtual Bool EvaluateExpression(const Char* expression, String& value, Result& result) const;

            virtual Bool GetValueByName(const Char* name, const IAttributes* params, String& value, Bool& error) const;
            virtual Bool GetValueByName(const Char* name, const IAttributes* params, Bool& value, Bool& error) const;
            virtual Bool GetValueByName(const Char* name, const IAttributes* params, UInt32& value, Bool& error) const;
            virtual Bool GetValueByName(const Char* name, const IAttributes* params, SInt32& value, Bool& error) const;
            virtual Bool GetValueByName(const Char* name, const IAttributes* params, Double& value, Bool& error) const;
            virtual Bool GetValueByName(const Char* name, const IAttributes* params, Float& value, Bool& error) const;
            virtual Bool GetValueByName(const Char* name, const IAttributes* params, Color& value, Bool& error) const;
            virtual Bool GetValueByName(const Char* name, const IAttributes* params, String& value, Result& result) const;
            virtual Bool GetValueByName(const Char* name, const IAttributes* params, Bool& value, Result& result) const;
            virtual Bool GetValueByName(const Char* name, const IAttributes* params, UInt32& value, Result& result) const;
            virtual Bool GetValueByName(const Char* name, const IAttributes* params, SInt32& value, Result& result) const;
            virtual Bool GetValueByName(const Char* name, const IAttributes* params, Double& value, Result& result) const;
            virtual Bool GetValueByName(const Char* name, const IAttributes* params, Float& value, Result& result) const;
            virtual Bool GetValueByName(const Char* name, const IAttributes* params, Color& value, Result& result) const;

            virtual Bool GetAngleValueByName(const Char* name, const IAttributes* params, Double& value, Bool& error) const;
            virtual Bool GetAngleValueByName(const Char* name, const IAttributes* params, Float& value, Bool& error) const;
            virtual Bool GetColorValueByName(const Char* name, const IAttributes* params, Float& value, Bool& error) const;
            virtual Bool GetAngleValueByName(const Char* name, const IAttributes* params, Double& value, Result& result) const;
            virtual Bool GetAngleValueByName(const Char* name, const IAttributes* params, Float& value, Result& result) const;
            virtual Bool GetColorValueByName(const Char* name, const IAttributes* params, Float& value, Result& result) const;

            virtual Bool GetValuesByName(const Char* name, const IAttributes* params, StringArray& values, Bool& error, Bool clear = true) const;
            virtual Bool GetValuesByName(const Char* name, const IAttributes* params, BoolArray& values, Bool& error, Bool clear = true) const;
            virtual Bool GetValuesByName(const Char* name, const IAttributes* params, UInt32Array& values, Bool& error, Bool clear = true) const;
            virtual Bool GetValuesByName(const Char* name, const IAttributes* params, SInt32Array& values, Bool& error, Bool clear = true) const;
            virtual Bool GetValuesByName(const Char* name, const IAttributes* params, DoubleArray& values, Bool& error, Bool clear = true) const;
            virtual Bool GetValuesByName(const Char* name, const IAttributes* params, FloatArray& values, Bool& error, Bool clear = true) const;
            virtual Bool GetValuesByName(const Char* name, const IAttributes* params, StringArray& values, Result& result, Bool clear = true) const;
            virtual Bool GetValuesByName(const Char* name, const IAttributes* params, BoolArray& values, Result& result, Bool clear = true) const;
            virtual Bool GetValuesByName(const Char* name, const IAttributes* params, UInt32Array& values, Result& result, Bool clear = true) const;
            virtual Bool GetValuesByName(const Char* name, const IAttributes* params, SInt32Array& values, Result& result, Bool clear = true) const;
            virtual Bool GetValuesByName(const Char* name, const IAttributes* params, DoubleArray& values, Result& result, Bool clear = true) const;
            virtual Bool GetValuesByName(const Char* name, const IAttributes* params, FloatArray& values, Result& result, Bool clear = true) const;

            virtual Bool GetAngleValuesByName(const Char* name, const IAttributes* params, DoubleArray& values, Bool& error, Bool clear = true) const;
            virtual Bool GetAngleValuesByName(const Char* name, const IAttributes* params, FloatArray& values, Bool& error, Bool clear = true) const;
            virtual Bool GetAngleValuesByName(const Char* name, const IAttributes* params, DoubleArray& values, Result& result, Bool clear = true) const;
            virtual Bool GetAngleValuesByName(const Char* name, const IAttributes* params, FloatArray& values, Result& result, Bool clear = true) const;

            virtual Bool GetBitsToSetByName(const Char* name, const IAttributes* params, UInt32& value, Bool& error) const;
            virtual Bool GetBitsToSetByName(const Char* name, const IAttributes* params, UInt32& value, Result& result) const;

        protected:
            mutable Evaluator* mEvaluator;
        };
    }
}

#endif // __MURL_UTIL_ATTRIBUTES_BASE_H__
