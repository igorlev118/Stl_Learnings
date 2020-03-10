// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_PROPERTY_H__
#define __MURL_GRAPH_PROPERTY_H__

#include "murl_graph_i_node.h"
#include "murl_graph_i_deserialize_attribute_tracker.h"
#include "murl_math_vector.h"
#include "murl_math_matrix.h"
#include "murl_math_quaternion.h"

/*
 Available properties:
 ---------------------

 BoolProperty
 BoolFieldProperty
 BoolArrayProperty

 SInt32Property
 SInt32FieldProperty
 SInt32ArrayProperty

 UInt32Property
 UInt32FieldProperty
 UInt32ArrayProperty

 UInt32MaskProperty
 UInt32MaskFieldProperty
 UInt32MaskArrayProperty

 RealProperty
 RealFieldProperty
 RealArrayProperty

 RealAngleProperty
 RealAngleFieldProperty
 RealAngleArrayProperty

 DoubleProperty
 DoubleFieldProperty
 DoubleArrayProperty

 DoubleAngleProperty
 DoubleAngleFieldProperty
 DoubleAngleArrayProperty

 VectorProperty
 VectorFieldProperty
 VectorArrayProperty

 MatrixProperty
 MatrixFieldProperty
 MatrixArrayProperty

 ColorProperty
 ColorFieldProperty
 ColorArrayProperty

 StringProperty
 StringFieldProperty
 StringArrayProperty

 EnumProperty
 EnumFieldProperty
 EnumArrayProperty

 EnumMaskProperty
 EnumMaskFieldProperty
 EnumMaskArrayProperty
 */

namespace Murl
{
    namespace Graph
    {
        class NullProperty
        {
        public:
            enum
            {
                COMPONENT_NONE = 0,
                ACCESS_NONE = 0,
                ELEMENT_NONE = 0
            };

            NullProperty();
            ~NullProperty();
            static const String& GetTypeName();
            static const PropertyInfo::Item* GetTypeInfo();
            static SInt32 GetId();
        };

        template<class DataType>
        class TypedProperty
        {
        public:
            enum
            {
                COMPONENT_NONE = 0,
                COMPONENT_SINGLE = (1 << 0),

                ACCESS_ALL = UInt32(-1),
                ACCESS_SINGLE = 0,

                ELEMENT_INDEX = UInt32(-2),
                ELEMENT_ALL = UInt32(-1),
                ELEMENT_SINGLE = 0
            };

            ~TypedProperty() {}
            static const String& GetTypeName();
            static const PropertyInfo::Item* GetTypeInfo() { return 0; }
        };

        template<class DataType>
        class TypedScalarProperty : public TypedProperty<DataType>
        {
        public:
            struct Value
            {
                UInt32 mId;
                DataType mValue;
            };

            typedef const Value& (*GetValueFunction)();

        public:
            explicit TypedScalarProperty(DataType value)
            : mValue(value)
            {
            }
            explicit TypedScalarProperty(const Value& v)
            : mValue(v.mValue)
            {
            }

            DataType& operator=(DataType const& rhs)
            {
                mValue = rhs;
                return mValue;
            }

            operator DataType&()
            {
                return mValue;
            }
            operator const DataType&() const
            {
                return mValue;
            }
            
            DataType* operator&()
            {
                return &mValue;
            }
            const DataType* operator&() const
            {
                return &mValue;
            }

            DataType& operator*()
            {
                return mValue;
            }
            const DataType& operator*() const
            {
                return mValue;
            }

            DataType mValue;
        };

        template<class DataType, UInt32 NUM_ELEMENTS>
        class TypedFieldProperty : public TypedProperty<DataType>
        {
        public:
            enum
            {
                ELEMENT_SELECTED = UInt32(-2),
            };

            struct Value
            {
                UInt32 mId;
                DataType mValue[NUM_ELEMENTS];
            };

            typedef const Value& (*GetValueFunction)();

        public:
            explicit TypedFieldProperty(DataType clearValue)
            {
                for (UInt32 i = 0; i < NUM_ELEMENTS; i++)
                {
                    mValue[i] = clearValue;
                }
            }
            explicit TypedFieldProperty(const Value& v)
            {
                for (UInt32 i = 0; i < NUM_ELEMENTS; i++)
                {
                    mValue[i] = v.mValue[i];
                }
            }

            Bool DeserializeValues(IDeserializeAttributeTracker* tracker)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                tracker->GetAttributeValues(mValue, NUM_ELEMENTS);
                return true;
            }
            Bool DeserializeValues(IDeserializeAttributeTracker* tracker, UInt32 numElements)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                if (numElements > NUM_ELEMENTS)
                {
                    return false;
                }
                tracker->GetAttributeValues(mValue, numElements);
                return true;
            }
            Bool DeserializeValue(IDeserializeAttributeTracker* tracker, UInt32 index)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                if (index >= NUM_ELEMENTS)
                {
                    return false;
                }
                tracker->GetAttributeValue(mValue[index]);
                return true;
            }
            Bool DeserializeBaseIndexValue(IDeserializeAttributeTracker* tracker)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                UInt32 index;
                if (!Util::StringToUInt32(tracker->GetBaseAttributeName(), index))
                {
                    return false;
                }
                if (index >= NUM_ELEMENTS)
                {
                    return false;
                }
                tracker->GetAttributeValue(mValue[index]);
                return true;
            }

            DataType& operator[](SInt32 index)
            {
                return mValue[index];
            }
            const DataType& operator[](SInt32 index) const
            {
                return mValue[index];
            }

            DataType* operator&()
            {
                return mValue;
            }
            const DataType* operator&() const
            {
                return mValue;
            }

            DataType& operator*()
            {
                return mValue[0];
            }
            const DataType& operator*() const
            {
                return mValue[0];
            }

            UInt32 GetCount() const
            {
                return NUM_ELEMENTS;
            }

            DataType mValue[NUM_ELEMENTS];
        };
        

        template<class DataType, UInt32 MIN_NUMBER_OF_ELEMENTS, UInt32 MAX_NUMBER_OF_ELEMENTS, UInt32 RESERVED_NUMBER_OF_ELEMENTS>
        class TypedArrayProperty : public TypedProperty<DataType>
        {
        public:
            enum
            {
                ELEMENT_SELECTED = UInt32(-2),
            };

            struct Value
            {
                UInt32 mId;
                DataType mValue[MAX_NUMBER_OF_ELEMENTS];
            };

            typedef const Value& (*GetValueFunction)();

        public:
            explicit TypedArrayProperty(const Value& v)
            {
                if (RESERVED_NUMBER_OF_ELEMENTS > 0)
                {
                    mValue.SetCount(RESERVED_NUMBER_OF_ELEMENTS);
                    for (UInt32 i = 0; i < RESERVED_NUMBER_OF_ELEMENTS; i++)
                    {
                        mValue[i] = v.mValue[i];
                    }
                }
            }

            Bool DeserializeValues(IDeserializeAttributeTracker* tracker)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                tracker->GetAttributeValues(mValue);
                return true;
            }
            Bool DeserializeValue(IDeserializeAttributeTracker* tracker, UInt32 index)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                if (index >= MAX_NUMBER_OF_ELEMENTS)
                {
                    return false;
                }
                if (index >= mValue.GetCount())
                {
                    mValue.SetCount(index + 1, 0);
                }
                tracker->GetAttributeValue(mValue[index]);
                return true;
            }
            Bool DeserializeBaseIndexValue(IDeserializeAttributeTracker* tracker)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                UInt32 index;
                if (!Util::StringToUInt32(tracker->GetBaseAttributeName(), index))
                {
                    return false;
                }
                if (index >= MAX_NUMBER_OF_ELEMENTS)
                {
                    return false;
                }
                if (index >= mValue.GetCount())
                {
                    mValue.SetCount(index + 1, 0);
                }
                tracker->GetAttributeValue(mValue[index]);
                return true;
            }

            DataType& operator[](SInt32 index)
            {
                return mValue[index];
            }
            const DataType& operator[](SInt32 index) const
            {
                return mValue[index];
            }

            DataType* operator&()
            {
                return mValue;
            }
            const DataType* operator&() const
            {
                return mValue;
            }

            DataType& operator*()
            {
                return mValue[0];
            }
            const DataType& operator*() const
            {
                return mValue[0];
            }

            UInt32 GetCount() const
            {
                return mValue.GetCount();
            }
            
            Array<DataType> mValue;
        };




        template<class DataType>
        class TypedScalarValueProperty : public TypedScalarProperty<DataType>
        {
        public:
            explicit TypedScalarValueProperty(DataType value)
            : TypedScalarProperty<DataType>(value)
            {
            }
            explicit TypedScalarValueProperty(const typename TypedScalarProperty<DataType>::Value& v)
            : TypedScalarProperty<DataType>(v)
            {
            }

            Bool DeserializeValue(IDeserializeAttributeTracker* tracker)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                tracker->GetAttributeValue(TypedScalarProperty<DataType>::mValue);
                return true;
            }
        };

        template<class DataType>
        class TypedScalarMaskProperty : public TypedScalarProperty<DataType>
        {
        public:
            explicit TypedScalarMaskProperty(DataType value)
            : TypedScalarProperty<DataType>(value)
            {
            }

            Bool DeserializeBitsToSet(IDeserializeAttributeTracker* tracker)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                tracker->GetAttributeBitsToSet(TypedScalarProperty<DataType>::mValue);
                return true;
            }
            Bool DeserializeFlagToSet(IDeserializeAttributeTracker* tracker, DataType mask)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                tracker->GetAttributeFlagToSet(mask, TypedScalarProperty<DataType>::mValue);
                return true;
            }
            Bool DeserializeFlagToClear(IDeserializeAttributeTracker* tracker, DataType mask)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                tracker->GetAttributeFlagToClear(mask, TypedScalarProperty<DataType>::mValue);
                return true;
            }
        };

        template<class DataType>
        class TypedScalarAngleProperty : public TypedScalarProperty<DataType>
        {
        public:
            explicit TypedScalarAngleProperty(DataType value)
            : TypedScalarProperty<DataType>(value)
            {
            }
            Bool DeserializeAngleValue(IDeserializeAttributeTracker* tracker)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                tracker->GetAttributeAngleValue(TypedScalarProperty<DataType>::mValue);
                return true;
            }
        };

        template<class DataType, UInt32 NUM_ELEMENTS>
        class TypedValueFieldProperty : public TypedFieldProperty<DataType, NUM_ELEMENTS>
        {
        public:
            explicit TypedValueFieldProperty(DataType value)
            : TypedFieldProperty<DataType, NUM_ELEMENTS>(value)
            {
            }
            explicit TypedValueFieldProperty(const typename TypedFieldProperty<DataType, NUM_ELEMENTS>::Value& v)
            : TypedFieldProperty<DataType, NUM_ELEMENTS>(v)
            {
            }
        };

        template<class DataType, UInt32 MIN_NUMBER_OF_ELEMENTS, UInt32 MAX_NUMBER_OF_ELEMENTS, UInt32 RESERVED_NUMBER_OF_ELEMENTS>
        class TypedValueArrayProperty : public TypedArrayProperty<DataType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>
        {
        public:
            explicit TypedValueArrayProperty(DataType value)
            : TypedArrayProperty<DataType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>(value)
            {
            }
            explicit TypedValueArrayProperty(const typename TypedArrayProperty<DataType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::Value& v)
            : TypedArrayProperty<DataType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>(v)
            {
            }
        };

        template<class DataType, UInt32 NUM_ELEMENTS>
        class TypedMaskFieldProperty : public TypedFieldProperty<DataType, NUM_ELEMENTS>
        {
        public:
            explicit TypedMaskFieldProperty(DataType value)
            : TypedFieldProperty<DataType, NUM_ELEMENTS>(value)
            {
            }
            explicit TypedMaskFieldProperty(const typename TypedFieldProperty<DataType, NUM_ELEMENTS>::Value& v)
            : TypedFieldProperty<DataType, NUM_ELEMENTS>(v)
            {
            }

            Bool DeserializeBitsToSet(IDeserializeAttributeTracker* tracker, UInt32 index)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                if (index >= NUM_ELEMENTS)
                {
                    return false;
                }
                tracker->GetAttributeBitsToSet(TypedFieldProperty<DataType, NUM_ELEMENTS>::mValue[index]);
                return true;
            }
            Bool DeserializeFlagToSet(IDeserializeAttributeTracker* tracker, DataType mask, UInt32 index)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                if (index >= NUM_ELEMENTS)
                {
                    return false;
                }
                tracker->GetAttributeFlagToSet(mask, TypedFieldProperty<DataType, NUM_ELEMENTS>::mValue[index]);
                return true;
            }
            Bool DeserializeFlagToClear(IDeserializeAttributeTracker* tracker, DataType mask, UInt32 index)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                if (index >= NUM_ELEMENTS)
                {
                    return false;
                }
                tracker->GetAttributeFlagToClear(mask, TypedFieldProperty<DataType, NUM_ELEMENTS>::mValue[index]);
                return true;
            }

            Bool DeserializeBaseIndexBitsToSet(IDeserializeAttributeTracker* tracker)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                UInt32 index;
                if (!Util::StringToUInt32(tracker->GetBaseAttributeName(), index))
                {
                    return false;
                }
                if (index >= NUM_ELEMENTS)
                {
                    return false;
                }
                tracker->GetAttributeBitsToSet(TypedFieldProperty<DataType, NUM_ELEMENTS>::mValue[index]);
                return true;
            }
            Bool DeserializeBaseIndexFlagToSet(IDeserializeAttributeTracker* tracker, DataType mask)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                UInt32 index;
                if (!Util::StringToUInt32(tracker->GetBaseAttributeName(), index))
                {
                    return false;
                }
                if (index >= NUM_ELEMENTS)
                {
                    return false;
                }
                tracker->GetAttributeFlagToSet(mask, TypedFieldProperty<DataType, NUM_ELEMENTS>::mValue[index]);
                return true;
            }
            Bool DeserializeBaseIndexFlagToClear(IDeserializeAttributeTracker* tracker, DataType mask)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                UInt32 index;
                if (!Util::StringToUInt32(tracker->GetBaseAttributeName(), index))
                {
                    return false;
                }
                if (index >= NUM_ELEMENTS)
                {
                    return false;
                }
                tracker->GetAttributeFlagToClear(mask, TypedFieldProperty<DataType, NUM_ELEMENTS>::mValue[index]);
                return true;
            }
        };

        template<class DataType, UInt32 MIN_NUMBER_OF_ELEMENTS, UInt32 MAX_NUMBER_OF_ELEMENTS, UInt32 RESERVED_NUMBER_OF_ELEMENTS>
        class TypedMaskArrayProperty : public TypedArrayProperty<DataType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>
        {
        public:
            explicit TypedMaskArrayProperty(DataType value)
            : TypedArrayProperty<DataType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>(value)
            {
            }
            explicit TypedMaskArrayProperty(const typename TypedArrayProperty<DataType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::Value& v)
            : TypedArrayProperty<DataType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>(v)
            {
            }

            Bool DeserializeBitsToSet(IDeserializeAttributeTracker* tracker, UInt32 index)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                if (index >= TypedArrayProperty<DataType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue.GetCount())
                {
                    TypedArrayProperty<DataType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue.SetCount(index + 1, 0);
                }
                tracker->GetAttributeBitsToSet(TypedArrayProperty<DataType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue[index]);
                return true;
            }
            Bool DeserializeFlagToSet(IDeserializeAttributeTracker* tracker, DataType mask, UInt32 index)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                if (index >= TypedArrayProperty<DataType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue.GetCount())
                {
                    TypedArrayProperty<DataType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue.SetCount(index + 1, 0);
                }
                tracker->GetAttributeFlagToSet(mask, TypedArrayProperty<DataType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue[index]);
                return true;
            }
            Bool DeserializeFlagToClear(IDeserializeAttributeTracker* tracker, DataType mask, UInt32 index)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                if (index >= TypedArrayProperty<DataType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue.GetCount())
                {
                    TypedArrayProperty<DataType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue.SetCount(index + 1, 0);
                }
                tracker->GetAttributeFlagToClear(mask, TypedArrayProperty<DataType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue[index]);
                return true;
            }

            Bool DeserializeBaseIndexBitsToSet(IDeserializeAttributeTracker* tracker)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                UInt32 index;
                if (!Util::StringToUInt32(tracker->GetBaseAttributeName(), index))
                {
                    return false;
                }
                if (index >= MAX_NUMBER_OF_ELEMENTS)
                {
                    return false;
                }
                if (index >= TypedArrayProperty<DataType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue.GetCount())
                {
                    TypedArrayProperty<DataType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue.SetCount(index + 1, 0);
                }
                tracker->GetAttributeBitsToSet(TypedArrayProperty<DataType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue[index]);
                return true;
            }
            Bool DeserializeBaseIndexFlagToSet(IDeserializeAttributeTracker* tracker, DataType mask)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                UInt32 index;
                if (!Util::StringToUInt32(tracker->GetBaseAttributeName(), index))
                {
                    return false;
                }
                if (index >= MAX_NUMBER_OF_ELEMENTS)
                {
                    return false;
                }
                if (index >= TypedArrayProperty<DataType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue.GetCount())
                {
                    TypedArrayProperty<DataType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue.SetCount(index + 1, 0);
                }
                tracker->GetAttributeFlagToSet(mask, TypedArrayProperty<DataType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue[index]);
                return true;
            }
            Bool DeserializeBaseIndexFlagToClear(IDeserializeAttributeTracker* tracker, DataType mask)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                UInt32 index;
                if (!Util::StringToUInt32(tracker->GetBaseAttributeName(), index))
                {
                    return false;
                }
                if (index >= MAX_NUMBER_OF_ELEMENTS)
                {
                    return false;
                }
                if (index >= TypedArrayProperty<DataType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue.GetCount())
                {
                    TypedArrayProperty<DataType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue.SetCount(index + 1, 0);
                }
                tracker->GetAttributeFlagToClear(mask, TypedArrayProperty<DataType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue[index]);
                return true;
            }
        };


        template<class DataType, UInt32 NUM_ELEMENTS>
        class TypedAngleFieldProperty : public TypedFieldProperty<DataType, NUM_ELEMENTS>
        {
        public:
            explicit TypedAngleFieldProperty(DataType value)
            : TypedFieldProperty<DataType, NUM_ELEMENTS>(value)
            {
            }
            explicit TypedAngleFieldProperty(const typename TypedFieldProperty<DataType, NUM_ELEMENTS>::Value& v)
            : TypedFieldProperty<DataType, NUM_ELEMENTS>(v)
            {
            }

            Bool DeserializeAngleValues(IDeserializeAttributeTracker* tracker)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                tracker->GetAttributeAngleValues(TypedFieldProperty<DataType, NUM_ELEMENTS>::mValue, NUM_ELEMENTS);
                return true;
            }
            Bool DeserializeAngleValues(IDeserializeAttributeTracker* tracker, UInt32 numElements)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                tracker->GetAttributeAngleValues(TypedFieldProperty<DataType, NUM_ELEMENTS>::mValue, numElements);
                return true;
            }
            Bool DeserializeAngleValue(IDeserializeAttributeTracker* tracker, UInt32 index)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                if (index >= NUM_ELEMENTS)
                {
                    return false;
                }
                tracker->GetAttributeAngleValue(TypedFieldProperty<DataType, NUM_ELEMENTS>::mValue[index]);
                return true;
            }
            Bool DeserializeBaseIndexAngleValue(IDeserializeAttributeTracker* tracker)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                UInt32 index;
                if (!Util::StringToUInt32(tracker->GetBaseAttributeName(), index))
                {
                    return false;
                }
                if (index >= NUM_ELEMENTS)
                {
                    return false;
                }
                tracker->GetAttributeAngleValue(TypedFieldProperty<DataType, NUM_ELEMENTS>::mValue[index]);
                return true;
            }
        };

        template<class DataType, UInt32 MIN_NUMBER_OF_ELEMENTS, UInt32 MAX_NUMBER_OF_ELEMENTS, UInt32 RESERVED_NUMBER_OF_ELEMENTS>
        class TypedAngleArrayProperty : public TypedArrayProperty<DataType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>
        {
        public:
            explicit TypedAngleArrayProperty(DataType value)
            : TypedArrayProperty<DataType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>(value)
            {
            }
            explicit TypedAngleArrayProperty(const typename TypedArrayProperty<DataType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::Value& v)
            : TypedArrayProperty<DataType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>(v)
            {
            }

            Bool DeserializeAngleValues(IDeserializeAttributeTracker* tracker)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                tracker->GetAttributeAngleValues(TypedArrayProperty<DataType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue);
                return true;
            }
            Bool DeserializeAngleValues(IDeserializeAttributeTracker* tracker, UInt32 numElements)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                tracker->GetAttributeAngleValues(TypedArrayProperty<DataType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue, numElements);
                return true;
            }
            Bool DeserializeAngleValue(IDeserializeAttributeTracker* tracker, UInt32 index)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                if (index >= TypedArrayProperty<DataType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue.GetCount())
                {
                    TypedArrayProperty<DataType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue.SetCount(index + 1, 0);
                }
                tracker->GetAttributeAngleValue(TypedArrayProperty<DataType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue[index]);
                return true;
            }
            Bool DeserializeBaseIndexAngleValue(IDeserializeAttributeTracker* tracker)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                UInt32 index;
                if (!Util::StringToUInt32(tracker->GetBaseAttributeName(), index))
                {
                    return false;
                }
                if (index >= TypedArrayProperty<DataType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue.GetCount())
                {
                    TypedArrayProperty<DataType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue.SetCount(index + 1, 0);
                }
                tracker->GetAttributeAngleValue(TypedArrayProperty<DataType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue[index]);
                return true;
            }
        };
        

        template<class DataType>
        class TypedVectorProperty : public TypedProperty<DataType>
        {
        public:
            enum
            {
                COMPONENT_NONE  = Math::Vector<DataType>::MASK_NONE,

                COMPONENT_X     = Math::Vector<DataType>::MASK_X,
                COMPONENT_Y     = Math::Vector<DataType>::MASK_Y,
                COMPONENT_Z     = Math::Vector<DataType>::MASK_Z,
                COMPONENT_W     = Math::Vector<DataType>::MASK_W,

                COMPONENT_XY    = Math::Vector<DataType>::MASK_XY,
                COMPONENT_XZ    = Math::Vector<DataType>::MASK_XZ,
                COMPONENT_YZ    = Math::Vector<DataType>::MASK_YZ,
                COMPONENT_XYZ   = Math::Vector<DataType>::MASK_XYZ,

                COMPONENT_ALL   = Math::Vector<DataType>::MASK_ALL
            };

            struct Value
            {
                UInt32 mId;
                Math::Vector<DataType> mValue;
            };

            typedef const Value& (*GetValueFunction)();

        public:
            explicit TypedVectorProperty(const Math::Vector<DataType>& value)
            : mValue(value)
            {
            }
            explicit TypedVectorProperty(const Value& v)
            : mValue(v.mValue)
            {
            }

            /* TODO: Directly deserialize comma-separated list of vector components as a single vector?
            Bool DeserializeValue(IDeserializeAttributeTracker* tracker)
            {
            }
             */
            Bool DeserializeValue(IDeserializeAttributeTracker* tracker, UInt32 component)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                if (component >= Math::Vector<DataType>::NUM_COMPONENTS)
                {
                    return false;
                }
                tracker->GetAttributeValue(mValue.mComponents[component]);
                return true;
            }
            Bool DeserializeValueX(IDeserializeAttributeTracker* tracker)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                tracker->GetAttributeValue(mValue.x);
                return true;
            }
            Bool DeserializeValueY(IDeserializeAttributeTracker* tracker)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                tracker->GetAttributeValue(mValue.y);
                return true;
            }
            Bool DeserializeValueZ(IDeserializeAttributeTracker* tracker)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                tracker->GetAttributeValue(mValue.z);
                return true;
            }
            Bool DeserializeValueW(IDeserializeAttributeTracker* tracker)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                tracker->GetAttributeValue(mValue.w);
                return true;
            }

            Math::Vector<DataType>& operator=(Math::Vector<DataType> const& rhs)
            {
                mValue = rhs;
                return mValue;
            }

            operator Math::Vector<DataType>&()
            {
                return mValue;
            }
            operator const Math::Vector<DataType>&() const
            {
                return mValue;
            }

            Math::Vector<DataType>& operator*()
            {
                return mValue;
            }
            const Math::Vector<DataType>& operator*() const
            {
                return mValue;
            }

            Math::Vector<DataType>* operator&()
            {
                return &mValue;
            }
            const Math::Vector<DataType>* operator&() const
            {
                return &mValue;
            }

            Math::Vector<DataType>* operator->()
            {
                return &mValue;
            }
            const Math::Vector<DataType>* operator->() const
            {
                return &mValue;
            }
            
            Math::Vector<DataType> mValue;
        };

        template<class DataType, UInt32 NUM_ELEMENTS>
        class TypedVectorFieldProperty : public TypedProperty<DataType>
        {
        public:
            enum
            {
                COMPONENT_NONE  = Math::Vector<DataType>::MASK_NONE,

                COMPONENT_X     = Math::Vector<DataType>::MASK_X,
                COMPONENT_Y     = Math::Vector<DataType>::MASK_Y,
                COMPONENT_Z     = Math::Vector<DataType>::MASK_Z,
                COMPONENT_W     = Math::Vector<DataType>::MASK_W,

                COMPONENT_XY    = Math::Vector<DataType>::MASK_XY,
                COMPONENT_XZ    = Math::Vector<DataType>::MASK_XZ,
                COMPONENT_YZ    = Math::Vector<DataType>::MASK_YZ,
                COMPONENT_XYZ   = Math::Vector<DataType>::MASK_XYZ,

                COMPONENT_ALL   = Math::Vector<DataType>::MASK_ALL
            };
            
            enum
            {
                ELEMENT_SELECTED = UInt32(-2),
            };

            struct Value
            {
                UInt32 mId;
                Math::Vector<DataType> mValue[NUM_ELEMENTS];
            };

            typedef const Value& (*GetValueFunction)();

        public:
            explicit TypedVectorFieldProperty(const Value& v)
            {
                for (UInt32 i = 0; i < NUM_ELEMENTS; i++)
                {
                    mValue[i] = v.mValue[i];
                }
            }

            /* TODO: Directly deserialize comma-separated list(s) of vector components?
            Bool DeserializeValues(IDeserializeAttributeTracker* tracker)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                tracker->GetAttributeValues(mValue, NUM_ELEMENTS);
                return true;
            }
            Bool DeserializeValues(IDeserializeAttributeTracker* tracker, UInt32 numElements)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                if (numElements > NUM_ELEMENTS)
                {
                    return false;
                }
                tracker->GetAttributeValues(mValue, numElements);
                return true;
            }
            Bool DeserializeValue(IDeserializeAttributeTracker* tracker, UInt32 index)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                if (index >= NUM_ELEMENTS)
                {
                    return false;
                }
                tracker->GetAttributeValue(mValue[index]);
                return true;
            }
            Bool DeserializeBaseIndexValue(IDeserializeAttributeTracker* tracker)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                UInt32 index;
                if (!Util::StringToUInt32(tracker->GetBaseAttributeName(), index))
                {
                    return false;
                }
                if (index >= NUM_ELEMENTS)
                {
                    return false;
                }
                tracker->GetAttributeValue(mValue[index]);
                return true;
            }
             */

            Bool DeserializeValue(IDeserializeAttributeTracker* tracker, UInt32 index, UInt32 component)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                if (component >= Math::Vector<DataType>::NUM_COMPONENTS)
                {
                    return false;
                }
                if (index >= NUM_ELEMENTS)
                {
                    return false;
                }
                tracker->GetAttributeValue(mValue[index].mComponents[component]);
                return true;
            }
            Bool DeserializeBaseIndexValue(IDeserializeAttributeTracker* tracker, UInt32 component)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                if (component >= Math::Vector<DataType>::NUM_COMPONENTS)
                {
                    return false;
                }
                UInt32 index;
                if (!Util::StringToUInt32(tracker->GetBaseAttributeName(), index))
                {
                    return false;
                }
                if (index >= NUM_ELEMENTS)
                {
                    return false;
                }
                tracker->GetAttributeValue(mValue[index].mComponents[component]);
                return true;
            }

            Bool DeserializeValueX(IDeserializeAttributeTracker* tracker, UInt32 index)
            {
                return DeserializeValue(tracker, index, Math::Vector<DataType>::X);
            }
            Bool DeserializeValueY(IDeserializeAttributeTracker* tracker, UInt32 index)
            {
                return DeserializeValue(tracker, index, Math::Vector<DataType>::Y);
            }
            Bool DeserializeValueZ(IDeserializeAttributeTracker* tracker, UInt32 index)
            {
                return DeserializeValue(tracker, index, Math::Vector<DataType>::Z);
            }
            Bool DeserializeValueW(IDeserializeAttributeTracker* tracker, UInt32 index)
            {
                return DeserializeValue(tracker, index, Math::Vector<DataType>::W);
            }

            Bool DeserializeBaseIndexValueX(IDeserializeAttributeTracker* tracker)
            {
                return DeserializeBaseIndexValue(tracker, Math::Vector<DataType>::X);
            }
            Bool DeserializeBaseIndexValueY(IDeserializeAttributeTracker* tracker)
            {
                return DeserializeBaseIndexValue(tracker, Math::Vector<DataType>::Y);
            }
            Bool DeserializeBaseIndexValueZ(IDeserializeAttributeTracker* tracker)
            {
                return DeserializeBaseIndexValue(tracker, Math::Vector<DataType>::Z);
            }
            Bool DeserializeBaseIndexValueW(IDeserializeAttributeTracker* tracker)
            {
                return DeserializeBaseIndexValue(tracker, Math::Vector<DataType>::W);
            }

            Math::Vector<DataType>& operator[](SInt32 index)
            {
                return mValue[index];
            }
            const Math::Vector<DataType>& operator[](SInt32 index) const
            {
                return mValue[index];
            }

            Math::Vector<DataType>& operator*()
            {
                return mValue[0];
            }
            const Math::Vector<DataType>& operator*() const
            {
                return mValue[0];
            }
            
            UInt32 GetCount() const
            {
                return NUM_ELEMENTS;
            }

            Math::Vector<DataType> mValue[NUM_ELEMENTS];
        };

        template<class DataType, UInt32 MIN_NUMBER_OF_ELEMENTS, UInt32 MAX_NUMBER_OF_ELEMENTS, UInt32 RESERVED_NUMBER_OF_ELEMENTS>
        class TypedVectorArrayProperty : public TypedProperty<DataType>
        {
        public:
            enum
            {
                COMPONENT_NONE  = Math::Vector<DataType>::MASK_NONE,

                COMPONENT_X     = Math::Vector<DataType>::MASK_X,
                COMPONENT_Y     = Math::Vector<DataType>::MASK_Y,
                COMPONENT_Z     = Math::Vector<DataType>::MASK_Z,
                COMPONENT_W     = Math::Vector<DataType>::MASK_W,

                COMPONENT_XY    = Math::Vector<DataType>::MASK_XY,
                COMPONENT_XZ    = Math::Vector<DataType>::MASK_XZ,
                COMPONENT_YZ    = Math::Vector<DataType>::MASK_YZ,
                COMPONENT_XYZ   = Math::Vector<DataType>::MASK_XYZ,

                COMPONENT_ALL   = Math::Vector<DataType>::MASK_ALL
            };

            enum
            {
                ELEMENT_SELECTED = UInt32(-2),
            };

            struct Value
            {
                UInt32 mId;
                Math::Vector<DataType> mValue[MAX_NUMBER_OF_ELEMENTS];
            };

            typedef const Value& (*GetValueFunction)();

        public:
            explicit TypedVectorArrayProperty(const Value& v)
            {
                if (RESERVED_NUMBER_OF_ELEMENTS > 0)
                {
                    mValue.SetCount(RESERVED_NUMBER_OF_ELEMENTS);
                    for (UInt32 i = 0; i < RESERVED_NUMBER_OF_ELEMENTS; i++)
                    {
                        mValue[i] = v.mValue[i];
                    }
                }
            }

            /* TODO: Directly deserialize comma-separated list(s) of vector components?
            Bool DeserializeValues(IDeserializeAttributeTracker* tracker)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                tracker->GetAttributeValues(mValue);
                return true;
            }
            Bool DeserializeValue(IDeserializeAttributeTracker* tracker, UInt32 index)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                if (index >= MAX_NUMBER_OF_ELEMENTS)
                {
                    return false;
                }
                if (index >= mValue.GetCount())
                {
                    mValue.SetCount(index + 1, Math::Vector<DataType>(Math::Vector<DataType>::ZERO_DIRECTION));
                }
                tracker->GetAttributeValue(mValue[index]);
                return true;
            }
            Bool DeserializeBaseIndexValue(IDeserializeAttributeTracker* tracker)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                UInt32 index;
                if (!Util::StringToUInt32(tracker->GetBaseAttributeName(), index))
                {
                    return false;
                }
                if (index >= MAX_NUMBER_OF_ELEMENTS)
                {
                    return false;
                }
                if (index >= mValue.GetCount())
                {
                    mValue.SetCount(index + 1, Math::Vector<DataType>(Math::Vector<DataType>::ZERO_DIRECTION));
                }
                tracker->GetAttributeValue(mValue[index]);
                return true;
            }
             */

            Bool DeserializeValue(IDeserializeAttributeTracker* tracker, UInt32 index, UInt32 component)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                if (component >= Math::Vector<DataType>::NUM_COMPONENTS)
                {
                    return false;
                }
                if (index >= MAX_NUMBER_OF_ELEMENTS)
                {
                    return false;
                }
                if (index >= mValue.GetCount())
                {
                    mValue.SetCount(index + 1, Math::Vector<DataType>(Math::Vector<DataType>::ZERO_DIRECTION));
                }
                tracker->GetAttributeValue(mValue[index].mComponents[component]);
                return true;
            }
            Bool DeserializeBaseIndexValue(IDeserializeAttributeTracker* tracker, UInt32 component)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                if (component >= Math::Vector<DataType>::NUM_COMPONENTS)
                {
                    return false;
                }
                UInt32 index;
                if (!Util::StringToUInt32(tracker->GetBaseAttributeName(), index))
                {
                    return false;
                }
                if (index >= MAX_NUMBER_OF_ELEMENTS)
                {
                    return false;
                }
                if (index >= mValue.GetCount())
                {
                    mValue.SetCount(index + 1, Math::Vector<DataType>(Math::Vector<DataType>::ZERO_DIRECTION));
                }
                tracker->GetAttributeValue(mValue[index].mComponents[component]);
                return true;
            }

            Bool DeserializeValueX(IDeserializeAttributeTracker* tracker, UInt32 index)
            {
                return DeserializeValue(tracker, index, Math::Vector<DataType>::X);
            }
            Bool DeserializeValueY(IDeserializeAttributeTracker* tracker, UInt32 index)
            {
                return DeserializeValue(tracker, index, Math::Vector<DataType>::Y);
            }
            Bool DeserializeValueZ(IDeserializeAttributeTracker* tracker, UInt32 index)
            {
                return DeserializeValue(tracker, index, Math::Vector<DataType>::Z);
            }
            Bool DeserializeValueW(IDeserializeAttributeTracker* tracker, UInt32 index)
            {
                return DeserializeValue(tracker, index, Math::Vector<DataType>::W);
            }

            Bool DeserializeBaseIndexValueX(IDeserializeAttributeTracker* tracker)
            {
                return DeserializeBaseIndexValue(tracker, Math::Vector<DataType>::X);
            }
            Bool DeserializeBaseIndexValueY(IDeserializeAttributeTracker* tracker)
            {
                return DeserializeBaseIndexValue(tracker, Math::Vector<DataType>::Y);
            }
            Bool DeserializeBaseIndexValueZ(IDeserializeAttributeTracker* tracker)
            {
                return DeserializeBaseIndexValue(tracker, Math::Vector<DataType>::Z);
            }
            Bool DeserializeBaseIndexValueW(IDeserializeAttributeTracker* tracker)
            {
                return DeserializeBaseIndexValue(tracker, Math::Vector<DataType>::W);
            }

            Math::Vector<DataType>& operator[](SInt32 index)
            {
                return mValue[index];
            }
            const Math::Vector<DataType>& operator[](SInt32 index) const
            {
                return mValue[index];
            }

            Math::Vector<DataType>& operator*()
            {
                return mValue[0];
            }
            const Math::Vector<DataType>& operator*() const
            {
                return mValue[0];
            }

            UInt32 GetCount() const
            {
                return mValue.GetCount();
            }
            
            Array<Math::Vector<DataType> > mValue;
        };


        template<class DataType>
        class TypedVectorAngleProperty : public TypedProperty<DataType>
        {
        public:
            enum
            {
                COMPONENT_NONE  = Math::Vector<DataType>::MASK_NONE,

                COMPONENT_X     = Math::Vector<DataType>::MASK_X,
                COMPONENT_Y     = Math::Vector<DataType>::MASK_Y,
                COMPONENT_Z     = Math::Vector<DataType>::MASK_Z,
                COMPONENT_W     = Math::Vector<DataType>::MASK_W,

                COMPONENT_XY    = Math::Vector<DataType>::MASK_XY,
                COMPONENT_XZ    = Math::Vector<DataType>::MASK_XZ,
                COMPONENT_YZ    = Math::Vector<DataType>::MASK_YZ,
                COMPONENT_XYZ   = Math::Vector<DataType>::MASK_XYZ,

                COMPONENT_ALL   = Math::Vector<DataType>::MASK_ALL
            };

            struct Value
            {
                UInt32 mId;
                Math::Vector<DataType> mValue;
            };

            typedef const Value& (*GetValueFunction)();

        public:
            explicit TypedVectorAngleProperty(const Math::Vector<DataType>& value)
            : mValue(value)
            {
            }
            explicit TypedVectorAngleProperty(const Value& v)
            : mValue(v.mValue)
            {
            }

            /* TODO: Directly deserialize comma-separated list of vector components as a single vector?
             Bool DeserializeValue(IDeserializeAttributeTracker* tracker)
             {
             }
             */
            Bool DeserializeAngleValue(IDeserializeAttributeTracker* tracker, UInt32 component)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                if (component >= Math::Vector<DataType>::NUM_COMPONENTS)
                {
                    return false;
                }
                tracker->GetAttributeAngleValue(mValue.mComponents[component]);
                return true;
            }
            Bool DeserializeAngleValueX(IDeserializeAttributeTracker* tracker)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                tracker->GetAttributeAngleValue(mValue.x);
                return true;
            }
            Bool DeserializeAngleValueY(IDeserializeAttributeTracker* tracker)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                tracker->GetAttributeAngleValue(mValue.y);
                return true;
            }
            Bool DeserializeAngleValueZ(IDeserializeAttributeTracker* tracker)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                tracker->GetAttributeAngleValue(mValue.z);
                return true;
            }
            Bool DeserializeAngleValueW(IDeserializeAttributeTracker* tracker)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                tracker->GetAttributeAngleValue(mValue.w);
                return true;
            }

            Math::Vector<DataType>& operator=(Math::Vector<DataType> const& rhs)
            {
                mValue = rhs;
                return mValue;
            }

            operator Math::Vector<DataType>&()
            {
                return mValue;
            }
            operator const Math::Vector<DataType>&() const
            {
                return mValue;
            }

            Math::Vector<DataType>& operator*()
            {
                return mValue;
            }
            const Math::Vector<DataType>& operator*() const
            {
                return mValue;
            }

            Math::Vector<DataType>* operator&()
            {
                return &mValue;
            }
            const Math::Vector<DataType>* operator&() const
            {
                return &mValue;
            }

            Math::Vector<DataType>* operator->()
            {
                return &mValue;
            }
            const Math::Vector<DataType>* operator->() const
            {
                return &mValue;
            }

            Math::Vector<DataType> mValue;
        };


        template<class DataType>
        class TypedMatrixProperty : public TypedProperty<DataType>
        {
        public:
            enum
            {
                COMPONENT_NONE   = Math::Matrix<DataType>::MASK_NONE,

                COMPONENT_XX     = Math::Matrix<DataType>::MASK_XX,
                COMPONENT_YX     = Math::Matrix<DataType>::MASK_YX,
                COMPONENT_ZX     = Math::Matrix<DataType>::MASK_ZX,
                COMPONENT_WX     = Math::Matrix<DataType>::MASK_WX,

                COMPONENT_XY     = Math::Matrix<DataType>::MASK_XY,
                COMPONENT_YY     = Math::Matrix<DataType>::MASK_YY,
                COMPONENT_ZY     = Math::Matrix<DataType>::MASK_ZY,
                COMPONENT_WY     = Math::Matrix<DataType>::MASK_WY,

                COMPONENT_XZ     = Math::Matrix<DataType>::MASK_XZ,
                COMPONENT_YZ     = Math::Matrix<DataType>::MASK_YZ,
                COMPONENT_ZZ     = Math::Matrix<DataType>::MASK_ZZ,
                COMPONENT_WZ     = Math::Matrix<DataType>::MASK_WZ,

                COMPONENT_XW     = Math::Matrix<DataType>::MASK_XW,
                COMPONENT_YW     = Math::Matrix<DataType>::MASK_YW,
                COMPONENT_ZW     = Math::Matrix<DataType>::MASK_ZW,
                COMPONENT_WW     = Math::Matrix<DataType>::MASK_WW,

                COMPONENT_ALL    = Math::Matrix<DataType>::MASK_ALL
            };

            struct Value
            {
                UInt32 mId;
                Math::Matrix<DataType> mValue;
            };

            typedef const Value& (*GetValueFunction)();

        public:
            explicit TypedMatrixProperty(const Math::Matrix<DataType>& value)
            : mValue(value)
            {
            }
            explicit TypedMatrixProperty(const Value& v)
            : mValue(v.mValue)
            {
            }

            Bool DeserializeValue(IDeserializeAttributeTracker* tracker, UInt32 component)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                if (component >= Math::Matrix<DataType>::NUM_COMPONENTS)
                {
                    return false;
                }
                typename Math::Matrix<DataType>::Component c = static_cast<typename Math::Matrix<DataType>::Component>(component);
                tracker->GetAttributeValue(mValue.GetElement(c));
                return true;
            }

            Math::Matrix<DataType>& operator=(Math::Matrix<DataType> const& rhs)
            {
                mValue = rhs;
                return mValue;
            }

            operator Math::Matrix<DataType>&()
            {
                return mValue;
            }
            operator const Math::Matrix<DataType>&() const
            {
                return mValue;
            }

            Math::Matrix<DataType>& operator*()
            {
                return mValue;
            }
            const Math::Matrix<DataType>& operator*() const
            {
                return mValue;
            }

            Math::Matrix<DataType>* operator->()
            {
                return &mValue;
            }
            const Math::Matrix<DataType>* operator->() const
            {
                return &mValue;
            }
            
            Math::Matrix<DataType> mValue;
        };

        template<class DataType, UInt32 NUM_ELEMENTS>
        class TypedMatrixFieldProperty : public TypedProperty<DataType>
        {
        public:
            enum
            {
                COMPONENT_NONE   = Math::Matrix<DataType>::MASK_NONE,

                COMPONENT_XX     = Math::Matrix<DataType>::MASK_XX,
                COMPONENT_YX     = Math::Matrix<DataType>::MASK_YX,
                COMPONENT_ZX     = Math::Matrix<DataType>::MASK_ZX,
                COMPONENT_WX     = Math::Matrix<DataType>::MASK_WX,

                COMPONENT_XY     = Math::Matrix<DataType>::MASK_XY,
                COMPONENT_YY     = Math::Matrix<DataType>::MASK_YY,
                COMPONENT_ZY     = Math::Matrix<DataType>::MASK_ZY,
                COMPONENT_WY     = Math::Matrix<DataType>::MASK_WY,

                COMPONENT_XZ     = Math::Matrix<DataType>::MASK_XZ,
                COMPONENT_YZ     = Math::Matrix<DataType>::MASK_YZ,
                COMPONENT_ZZ     = Math::Matrix<DataType>::MASK_ZZ,
                COMPONENT_WZ     = Math::Matrix<DataType>::MASK_WZ,

                COMPONENT_XW     = Math::Matrix<DataType>::MASK_XW,
                COMPONENT_YW     = Math::Matrix<DataType>::MASK_YW,
                COMPONENT_ZW     = Math::Matrix<DataType>::MASK_ZW,
                COMPONENT_WW     = Math::Matrix<DataType>::MASK_WW,

                COMPONENT_ALL    = Math::Matrix<DataType>::MASK_ALL
            };

            enum
            {
                ELEMENT_SELECTED = UInt32(-2),
            };

            struct Value
            {
                UInt32 mId;
                Math::Matrix<DataType> mValue[NUM_ELEMENTS];
            };

            typedef const Value& (*GetValueFunction)();

        public:
            explicit TypedMatrixFieldProperty(const Value& v)
            {
                for (UInt32 i = 0; i < NUM_ELEMENTS; i++)
                {
                    mValue[i] = v.mValue[i];
                }
            }

            Bool DeserializeValue(IDeserializeAttributeTracker* tracker, UInt32 index, UInt32 component)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                if (component >= Math::Matrix<DataType>::NUM_COMPONENTS)
                {
                    return false;
                }
                if (index >= NUM_ELEMENTS)
                {
                    return false;
                }
                typename Math::Matrix<DataType>::Component c = static_cast<typename Math::Matrix<DataType>::Component>(component);
                tracker->GetAttributeValue(mValue[index].GetElement(c));
                return true;
            }
            Bool DeserializeBaseIndexValue(IDeserializeAttributeTracker* tracker, UInt32 component)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                if (component >= Math::Matrix<DataType>::NUM_COMPONENTS)
                {
                    return false;
                }
                UInt32 index;
                if (!Util::StringToUInt32(tracker->GetBaseAttributeName(), index))
                {
                    return false;
                }
                if (index >= NUM_ELEMENTS)
                {
                    return false;
                }
                typename Math::Matrix<DataType>::Component c = static_cast<typename Math::Matrix<DataType>::Component>(component);
                tracker->GetAttributeValue(mValue[index].GetElement(c));
                return true;
            }

            Math::Matrix<DataType>& operator[](SInt32 index)
            {
                return mValue[index];
            }
            const Math::Matrix<DataType>& operator[](SInt32 index) const
            {
                return mValue[index];
            }

            Math::Matrix<DataType>& operator*()
            {
                return mValue[0];
            }
            const Math::Matrix<DataType>& operator*() const
            {
                return mValue[0];
            }

            UInt32 GetCount() const
            {
                return NUM_ELEMENTS;
            }
            
            Math::Matrix<DataType> mValue[NUM_ELEMENTS];
        };
        
        template<class DataType, UInt32 MIN_NUMBER_OF_ELEMENTS, UInt32 MAX_NUMBER_OF_ELEMENTS, UInt32 RESERVED_NUMBER_OF_ELEMENTS>
        class TypedMatrixArrayProperty : public TypedProperty<DataType>
        {
        public:
            enum
            {
                COMPONENT_NONE   = Math::Matrix<DataType>::MASK_NONE,

                COMPONENT_XX     = Math::Matrix<DataType>::MASK_XX,
                COMPONENT_YX     = Math::Matrix<DataType>::MASK_YX,
                COMPONENT_ZX     = Math::Matrix<DataType>::MASK_ZX,
                COMPONENT_WX     = Math::Matrix<DataType>::MASK_WX,

                COMPONENT_XY     = Math::Matrix<DataType>::MASK_XY,
                COMPONENT_YY     = Math::Matrix<DataType>::MASK_YY,
                COMPONENT_ZY     = Math::Matrix<DataType>::MASK_ZY,
                COMPONENT_WY     = Math::Matrix<DataType>::MASK_WY,

                COMPONENT_XZ     = Math::Matrix<DataType>::MASK_XZ,
                COMPONENT_YZ     = Math::Matrix<DataType>::MASK_YZ,
                COMPONENT_ZZ     = Math::Matrix<DataType>::MASK_ZZ,
                COMPONENT_WZ     = Math::Matrix<DataType>::MASK_WZ,

                COMPONENT_XW     = Math::Matrix<DataType>::MASK_XW,
                COMPONENT_YW     = Math::Matrix<DataType>::MASK_YW,
                COMPONENT_ZW     = Math::Matrix<DataType>::MASK_ZW,
                COMPONENT_WW     = Math::Matrix<DataType>::MASK_WW,

                COMPONENT_ALL    = Math::Matrix<DataType>::MASK_ALL
            };

            enum
            {
                ELEMENT_SELECTED = UInt32(-2),
            };

            struct Value
            {
                UInt32 mId;
                Math::Matrix<DataType> mValue[MAX_NUMBER_OF_ELEMENTS];
            };

            typedef const Value& (*GetValueFunction)();

        public:
            explicit TypedMatrixArrayProperty(const Value& v)
            {
                if (RESERVED_NUMBER_OF_ELEMENTS > 0)
                {
                    mValue.SetCount(RESERVED_NUMBER_OF_ELEMENTS);
                    for (UInt32 i = 0; i < RESERVED_NUMBER_OF_ELEMENTS; i++)
                    {
                        mValue[i] = v.mValue[i];
                    }
                }
            }

            Bool DeserializeValue(IDeserializeAttributeTracker* tracker, UInt32 index, UInt32 component)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                if (component >= Math::Matrix<DataType>::NUM_COMPONENTS)
                {
                    return false;
                }
                if (index >= MAX_NUMBER_OF_ELEMENTS)
                {
                    return false;
                }
                if (index >= mValue.GetCount())
                {
                    mValue.SetCount(index + 1, Math::Matrix<DataType>(Math::Matrix<DataType>::IDENTITY));
                }
                typename Math::Matrix<DataType>::Component c = static_cast<typename Math::Matrix<DataType>::Component>(component);
                tracker->GetAttributeValue(mValue[index].GetElement(c));
                return true;
            }
            Bool DeserializeBaseIndexValue(IDeserializeAttributeTracker* tracker, UInt32 component)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                if (component >= Math::Matrix<DataType>::NUM_COMPONENTS)
                {
                    return false;
                }
                UInt32 index;
                if (!Util::StringToUInt32(tracker->GetBaseAttributeName(), index))
                {
                    return false;
                }
                if (index >= MAX_NUMBER_OF_ELEMENTS)
                {
                    return false;
                }
                if (index >= mValue.GetCount())
                {
                    mValue.SetCount(index + 1, Math::Matrix<DataType>(Math::Matrix<DataType>::IDENTITY));
                }
                typename Math::Matrix<DataType>::Component c = static_cast<typename Math::Matrix<DataType>::Component>(component);
                tracker->GetAttributeValue(mValue[index].GetElement(c));
                return true;
            }

            Math::Matrix<DataType>& operator[](SInt32 index)
            {
                return mValue[index];
            }
            const Math::Matrix<DataType>& operator[](SInt32 index) const
            {
                return mValue[index];
            }

            Math::Matrix<DataType>& operator*()
            {
                return mValue[0];
            }
            const Math::Matrix<DataType>& operator*() const
            {
                return mValue[0];
            }

            UInt32 GetCount() const
            {
                return mValue.GetCount();
            }

            Array<Math::Matrix<DataType> > mValue;
        };
        


        class TypedColorProperty : public TypedProperty<Color>
        {
        public:
            struct Value
            {
                UInt32 mId;
                Color mValue;
            };

            typedef const Value& (*GetValueFunction)();

        public:
            explicit TypedColorProperty(const Color& value)
            : mValue(value)
            {
            }
            explicit TypedColorProperty(const Value& v)
            : mValue(v.mValue)
            {
            }

            Bool DeserializeValue(IDeserializeAttributeTracker* tracker)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                tracker->GetAttributeValue(mValue);
                return true;
            }

            Color& operator=(Color const& rhs)
            {
                mValue = rhs;
                return mValue;
            }

            operator Color&()
            {
                return mValue;
            }
            operator const Color&() const
            {
                return mValue;
            }

            Color& operator*()
            {
                return mValue;
            }
            const Color& operator*() const
            {
                return mValue;
            }

            Color* operator->()
            {
                return &mValue;
            }
            const Color* operator->() const
            {
                return &mValue;
            }
            
            Color mValue;
        };

        template<UInt32 NUM_ELEMENTS>
        class TypedColorFieldProperty : public TypedProperty<Color>
        {
        public:
            enum
            {
                ELEMENT_SELECTED = UInt32(-2),
            };

            struct Value
            {
                UInt32 mId;
                Color mValue[NUM_ELEMENTS];
            };

            typedef const Value& (*GetValueFunction)();

        public:
            explicit TypedColorFieldProperty(const Value& v)
            {
                for (UInt32 i = 0; i < NUM_ELEMENTS; i++)
                {
                    mValue[i] = v.mValue[i];
                }
            }

            Bool DeserializeValue(IDeserializeAttributeTracker* tracker, UInt32 index)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                if (index >= NUM_ELEMENTS)
                {
                    return false;
                }
                tracker->GetAttributeValue(mValue[index]);
                return true;
            }
            Bool DeserializeBaseIndexValue(IDeserializeAttributeTracker* tracker)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                UInt32 index;
                if (!Util::StringToUInt32(tracker->GetBaseAttributeName(), index))
                {
                    return false;
                }
                if (index >= NUM_ELEMENTS)
                {
                    return false;
                }
                tracker->GetAttributeValue(mValue[index]);
                return true;
            }

            Color& operator[](SInt32 index)
            {
                return mValue[index];
            }
            const Color& operator[](SInt32 index) const
            {
                return mValue[index];
            }

            Color& operator*()
            {
                return mValue[0];
            }
            const Color& operator*() const
            {
                return mValue[0];
            }
            
            UInt32 GetCount() const
            {
                return NUM_ELEMENTS;
            }

            Color mValue[NUM_ELEMENTS];
        };

        template<UInt32 MIN_NUMBER_OF_ELEMENTS, UInt32 MAX_NUMBER_OF_ELEMENTS, UInt32 RESERVED_NUMBER_OF_ELEMENTS>
        class TypedColorArrayProperty : public TypedProperty<Color>
        {
        public:
            enum
            {
                ELEMENT_SELECTED = UInt32(-2),
            };

            struct Value
            {
                UInt32 mId;
                Color mValue[MAX_NUMBER_OF_ELEMENTS];
            };

            typedef const Value& (*GetValueFunction)();

        public:
            explicit TypedColorArrayProperty(const Value& v)
            {
                if (RESERVED_NUMBER_OF_ELEMENTS > 0)
                {
                    mValue.SetCount(RESERVED_NUMBER_OF_ELEMENTS);
                    for (UInt32 i = 0; i < RESERVED_NUMBER_OF_ELEMENTS; i++)
                    {
                        mValue[i] = v.mValue[i];
                    }
                }
            }

            Bool DeserializeValue(IDeserializeAttributeTracker* tracker, UInt32 index)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                if (index >= MAX_NUMBER_OF_ELEMENTS)
                {
                    return false;
                }
                if (index >= mValue.GetCount())
                {
                    mValue.SetCount(index + 1, Color());
                }
                tracker->GetAttributeValue(mValue[index]);
                return true;
            }
            Bool DeserializeBaseIndexValue(IDeserializeAttributeTracker* tracker)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                UInt32 index;
                if (!Util::StringToUInt32(tracker->GetBaseAttributeName(), index))
                {
                    return false;
                }
                if (index >= MAX_NUMBER_OF_ELEMENTS)
                {
                    return false;
                }
                if (index >= mValue.GetCount())
                {
                    mValue.SetCount(index + 1, Color());
                }
                tracker->GetAttributeValue(mValue[index]);
                return true;
            }

            Color& operator[](SInt32 index)
            {
                return mValue[index];
            }
            const Color& operator[](SInt32 index) const
            {
                return mValue[index];
            }

            Color& operator*()
            {
                return mValue[0];
            }
            const Color& operator*() const
            {
                return mValue[0];
            }

            UInt32 GetCount() const
            {
                return mValue.GetCount();
            }
            
            Array<Color> mValue;
        };
        


        class TypedStringProperty : public TypedProperty<String>
        {
        public:
            struct Value
            {
                UInt32 mId;
                String mValue;
            };

            typedef const Value& (*GetValueFunction)();

        public:
            explicit TypedStringProperty(const String& value)
            : mValue(value)
            {
            }
            explicit TypedStringProperty(const Value& v)
            : mValue(v.mValue)
            {
            }

            Bool DeserializeValue(IDeserializeAttributeTracker* tracker)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                tracker->GetAttributeValue(mValue);
                return true;
            }

            String& operator=(String const& rhs)
            {
                mValue = rhs;
                return mValue;
            }

            const Char* Begin() const
            {
                return mValue.Begin();
            }

            operator String&()
            {
                return mValue;
            }
            operator const String&() const
            {
                return mValue;
            }


            String& operator*()
            {
                return mValue;
            }
            const String& operator*() const
            {
                return mValue;
            }

            String* operator->()
            {
                return &mValue;
            }
            const String* operator->() const
            {
                return &mValue;
            }
            
            String mValue;
        };
        
        template<UInt32 NUM_ELEMENTS>
        class TypedStringFieldProperty : public TypedProperty<String>
        {
        public:
            enum
            {
                ELEMENT_SELECTED = UInt32(-2),
            };

            struct Value
            {
                UInt32 mId;
                String mValue[NUM_ELEMENTS];
            };

            typedef const Value& (*GetValueFunction)();

        public:
            explicit TypedStringFieldProperty(const Value& v)
            {
                for (UInt32 i = 0; i < NUM_ELEMENTS; i++)
                {
                    mValue[i] = v.mValue[i];
                }
            }

            Bool DeserializeValues(IDeserializeAttributeTracker* tracker)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                tracker->GetAttributeValues(mValue, NUM_ELEMENTS);
                return true;
            }
            Bool DeserializeValues(IDeserializeAttributeTracker* tracker, UInt32 numElements)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                tracker->GetAttributeValues(mValue, numElements);
                return true;
            }
            Bool DeserializeValue(IDeserializeAttributeTracker* tracker, UInt32 index)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                tracker->GetAttributeValue(mValue[index]);
                return true;
            }
            Bool DeserializeBaseIndexValue(IDeserializeAttributeTracker* tracker)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                UInt32 index;
                if (!Util::StringToUInt32(tracker->GetBaseAttributeName(), index))
                {
                    return false;
                }
                if (index >= NUM_ELEMENTS)
                {
                    return false;
                }
                tracker->GetAttributeValue(mValue[index]);
                return true;
            }

            String& operator[](SInt32 index)
            {
                return mValue[index];
            }
            const String& operator[](SInt32 index) const
            {
                return mValue[index];
            }

            String& operator*()
            {
                return mValue[0];
            }
            const String& operator*() const
            {
                return mValue[0];
            }

            UInt32 GetCount() const
            {
                return NUM_ELEMENTS;
            }
            
            String mValue[NUM_ELEMENTS];
        };
        

        template<UInt32 MIN_NUMBER_OF_ELEMENTS, UInt32 MAX_NUMBER_OF_ELEMENTS, UInt32 RESERVED_NUMBER_OF_ELEMENTS>
        class TypedStringArrayProperty : public TypedProperty<String>
        {
        public:
            enum
            {
                ELEMENT_SELECTED = UInt32(-2),
            };

            struct Value
            {
                UInt32 mId;
                String mValue[MAX_NUMBER_OF_ELEMENTS];
            };

            typedef const Value& (*GetValueFunction)();

        public:
            explicit TypedStringArrayProperty(const Value& v)
            {
                if (RESERVED_NUMBER_OF_ELEMENTS > 0)
                {
                    mValue.SetCount(RESERVED_NUMBER_OF_ELEMENTS);
                    for (UInt32 i = 0; i < RESERVED_NUMBER_OF_ELEMENTS; i++)
                    {
                        mValue[i] = v.mValue[i];
                    }
                }
            }

            Bool DeserializeValues(IDeserializeAttributeTracker* tracker)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                tracker->GetAttributeValues(mValue);
                return true;
            }
            Bool DeserializeValue(IDeserializeAttributeTracker* tracker, UInt32 index)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                if (index >= MAX_NUMBER_OF_ELEMENTS)
                {
                    return false;
                }
                if (index >= mValue.GetCount())
                {
                    mValue.SetCount(index + 1);
                }
                tracker->GetAttributeValue(mValue[index]);
                return true;
            }
            Bool DeserializeBaseIndexValue(IDeserializeAttributeTracker* tracker)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                UInt32 index;
                if (!Util::StringToUInt32(tracker->GetBaseAttributeName(), index))
                {
                    return false;
                }
                if (index >= MAX_NUMBER_OF_ELEMENTS)
                {
                    return false;
                }
                if (index >= mValue.GetCount())
                {
                    mValue.SetCount(index + 1);
                }
                tracker->GetAttributeValue(mValue[index]);
                return true;
            }

            String& operator[](SInt32 index)
            {
                return mValue[index];
            }
            const String& operator[](SInt32 index) const
            {
                return mValue[index];
            }

            String& operator*()
            {
                return mValue[0];
            }
            const String& operator*() const
            {
                return mValue[0];
            }

            UInt32 GetCount() const
            {
                return mValue.GetCount();
            }
            
            StringArray mValue;
        };
        


        
        template<class EnumType>
        class TypedEnumProperty : public TypedProperty<EnumType>
        {
        public:
            ~TypedEnumProperty() {}
            static const Enum<EnumType>& GetEnum();
            static const Enum<SInt32>& GetSInt32Enum();
            static const String& GetTypeName();
        };

        

        

        // ========== Bool ==========

        // BoolProperty
        typedef TypedScalarValueProperty<Bool> BoolPropertyBase;

        template<const BoolPropertyBase::GetValueFunction DEFAULT>
        class BoolProperty : public BoolPropertyBase
        {
        public:
            explicit BoolProperty()
            : BoolPropertyBase(DEFAULT().mValue)
            {
            }
            void Reset()
            {
                BoolPropertyBase::mValue = DEFAULT().mValue;
            }
            Bool& operator=(Bool const& rhs)
            {
                BoolPropertyBase::mValue = rhs;
                return BoolPropertyBase::mValue;
            }
            static const PropertyInfo::Item* GetTypeInfo()
            {
                static PropertyInfo::Item p =
                {
                    DEFAULT().mId,
                    TypedProperty<Bool>::GetTypeName(),
                    IEnums::PROPERTY_SEMANTIC_VALUE,
                    1,
                    1,
                    1,
                    0,
                    1,
                    GetDefaultStrings()
                };
                return &p;
            }
            static SInt32 GetId()
            {
                return DEFAULT().mId;
            }
            static Array<Array<String> > GetDefaultStrings()
            {
                Array<Array<String> > a;
                a.SetCount(1);
                a[0].Add(Util::BoolToString(DEFAULT().mValue));
                return a;
            }
        };
        
        // BoolFieldProperty
        template<UInt32 NUM_ELEMENTS>
        class BoolFieldPropertyBase : public TypedValueFieldProperty<Bool, NUM_ELEMENTS>
        {
        public:
            explicit BoolFieldPropertyBase(Bool value)
            : TypedValueFieldProperty<Bool, NUM_ELEMENTS>(value)
            {
            }
            explicit BoolFieldPropertyBase(const typename TypedValueFieldProperty<Bool, NUM_ELEMENTS>::Value& v)
            : TypedValueFieldProperty<Bool, NUM_ELEMENTS>(v)
            {
            }
        };

        template<UInt32 NUM_ELEMENTS, const typename BoolFieldPropertyBase<NUM_ELEMENTS>::GetValueFunction DEFAULT>
        class BoolFieldProperty : public BoolFieldPropertyBase<NUM_ELEMENTS>
        {
        public:
            explicit BoolFieldProperty()
            : BoolFieldPropertyBase<NUM_ELEMENTS>(DEFAULT())
            {
            }
            void Reset()
            {
                Util::MemCopy(BoolFieldPropertyBase<NUM_ELEMENTS>::mValue, DEFAULT().mValue, sizeof(DEFAULT().mValue));
            }
            static const PropertyInfo::Item* GetTypeInfo()
            {
                static PropertyInfo::Item p =
                {
                    DEFAULT().mId,
                    TypedProperty<Bool>::GetTypeName(),
                    IEnums::PROPERTY_SEMANTIC_VALUE,
                    1,
                    NUM_ELEMENTS,
                    NUM_ELEMENTS,
                    0,
                    NUM_ELEMENTS,
                    GetDefaultStrings()
                };
                return &p;
            }
            static SInt32 GetId()
            {
                return DEFAULT().mId;
            }
            static Array<Array<String> > GetDefaultStrings()
            {
                Array<Array<String> > a;
                a.SetCount(NUM_ELEMENTS);
                for (UInt32 i = 0; i < NUM_ELEMENTS; i++)
                {
                    Array<String>& b = a[i];
                    b.Add(Util::BoolToString(DEFAULT().mValue[i]));
                }
                return a;
            }
        };
        
        // BoolArrayProperty
        template<UInt32 MIN_NUMBER_OF_ELEMENTS, UInt32 MAX_NUMBER_OF_ELEMENTS, UInt32 RESERVED_NUMBER_OF_ELEMENTS>
        class BoolArrayPropertyBase : public TypedValueArrayProperty<Bool, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>
        {
        public:
            explicit BoolArrayPropertyBase(Bool value)
            : TypedValueArrayProperty<Bool, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>(value)
            {
            }
            explicit BoolArrayPropertyBase(const typename TypedValueArrayProperty<Bool, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::Value& v)
            : TypedValueArrayProperty<Bool, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>(v)
            {
            }
        };

        template<UInt32 MIN_NUMBER_OF_ELEMENTS, UInt32 MAX_NUMBER_OF_ELEMENTS, UInt32 RESERVED_NUMBER_OF_ELEMENTS, const typename BoolArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::GetValueFunction DEFAULT>
        class BoolArrayProperty : public BoolArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>
        {
        public:
            explicit BoolArrayProperty()
            : BoolArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>(DEFAULT())
            {
            }
            void Reset()
            {
                BoolArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue.SetCount(RESERVED_NUMBER_OF_ELEMENTS);
                for (UInt32 i = 0; i < RESERVED_NUMBER_OF_ELEMENTS; i++)
                {
                    BoolArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue[i] = DEFAULT().mValue[i];
                }
            }
            static const PropertyInfo::Item* GetTypeInfo()
            {
                static PropertyInfo::Item p =
                {
                    DEFAULT().mId,
                    TypedProperty<Bool>::GetTypeName(),
                    IEnums::PROPERTY_SEMANTIC_VALUE,
                    1,
                    MIN_NUMBER_OF_ELEMENTS,
                    MAX_NUMBER_OF_ELEMENTS,
                    MIN_NUMBER_OF_ELEMENTS,
                    MAX_NUMBER_OF_ELEMENTS,
                    GetDefaultStrings()
                };
                return &p;
            }
            static SInt32 GetId()
            {
                return DEFAULT().mId;
            }
            static Array<Array<String> > GetDefaultStrings()
            {
                Array<Array<String> > a;
                a.SetCount(MAX_NUMBER_OF_ELEMENTS);
                for (UInt32 i = 0; i < MAX_NUMBER_OF_ELEMENTS; i++)
                {
                    Array<String>& b = a[i];
                    b.Add(Util::BoolToString(DEFAULT().mValue[i]));
                }
                return a;
            }
        };


        // ========== SInt32 ==========

        // SInt32Property
        typedef TypedScalarValueProperty<SInt32> SInt32PropertyBase;

        template<const SInt32PropertyBase::GetValueFunction DEFAULT>
        class SInt32Property : public SInt32PropertyBase
        {
        public:
            explicit SInt32Property()
            : SInt32PropertyBase(DEFAULT().mValue)
            {
            }
            void Reset()
            {
                SInt32PropertyBase::mValue = DEFAULT().mValue;
            }
            SInt32& operator=(SInt32 const& rhs)
            {
                SInt32PropertyBase::mValue = rhs;
                return SInt32PropertyBase::mValue;
            }
            static const PropertyInfo::Item* GetTypeInfo()
            {
                static PropertyInfo::Item p =
                {
                    DEFAULT().mId,
                    TypedProperty<SInt32>::GetTypeName(),
                    IEnums::PROPERTY_SEMANTIC_VALUE,
                    1,
                    1,
                    1,
                    0,
                    1,
                    GetDefaultStrings()
                };
                return &p;
            }
            static SInt32 GetId()
            {
                return DEFAULT().mId;
            }
            static Array<Array<String> > GetDefaultStrings()
            {
                Array<Array<String> > a;
                a.SetCount(1);
                a[0].Add(Util::SInt32ToString(DEFAULT().mValue));
                return a;
            }
        };
        
        // SInt32FieldProperty
        template<UInt32 NUM_ELEMENTS>
        class SInt32FieldPropertyBase : public TypedValueFieldProperty<SInt32, NUM_ELEMENTS>
        {
        public:
            explicit SInt32FieldPropertyBase(SInt32 value)
            : TypedValueFieldProperty<SInt32, NUM_ELEMENTS>(value)
            {
            }
            explicit SInt32FieldPropertyBase(const typename TypedValueFieldProperty<SInt32, NUM_ELEMENTS>::Value& v)
            : TypedValueFieldProperty<SInt32, NUM_ELEMENTS>(v)
            {
            }
        };

        template<UInt32 NUM_ELEMENTS, const typename SInt32FieldPropertyBase<NUM_ELEMENTS>::GetValueFunction DEFAULT>
        class SInt32FieldProperty : public SInt32FieldPropertyBase<NUM_ELEMENTS>
        {
        public:
            explicit SInt32FieldProperty()
            : SInt32FieldPropertyBase<NUM_ELEMENTS>(DEFAULT())
            {
            }
            void Reset()
            {
                Util::MemCopy(SInt32FieldPropertyBase<NUM_ELEMENTS>::mValue, DEFAULT().mValue, sizeof(DEFAULT().mValue));
            }
            static const PropertyInfo::Item* GetTypeInfo()
            {
                static PropertyInfo::Item p =
                {
                    DEFAULT().mId,
                    TypedProperty<SInt32>::GetTypeName(),
                    IEnums::PROPERTY_SEMANTIC_VALUE,
                    1,
                    NUM_ELEMENTS,
                    NUM_ELEMENTS,
                    0,
                    NUM_ELEMENTS,
                    GetDefaultStrings()
                };
                return &p;
            }
            static SInt32 GetId()
            {
                return DEFAULT().mId;
            }
            static Array<Array<String> > GetDefaultStrings()
            {
                Array<Array<String> > a;
                a.SetCount(NUM_ELEMENTS);
                for (UInt32 i = 0; i < NUM_ELEMENTS; i++)
                {
                    Array<String>& b = a[i];
                    b.Add(Util::SInt32ToString(DEFAULT().mValue[i]));
                }
                return a;
            }
        };

        // SInt32ArrayProperty
        template<UInt32 MIN_NUMBER_OF_ELEMENTS, UInt32 MAX_NUMBER_OF_ELEMENTS, UInt32 RESERVED_NUMBER_OF_ELEMENTS>
        class SInt32ArrayPropertyBase : public TypedValueArrayProperty<SInt32, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>
        {
        public:
            explicit SInt32ArrayPropertyBase(SInt32 value)
            : TypedValueArrayProperty<SInt32, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>(value)
            {
            }
            explicit SInt32ArrayPropertyBase(const typename TypedValueArrayProperty<SInt32, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::Value& v)
            : TypedValueArrayProperty<SInt32, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>(v)
            {
            }
        };

        template<UInt32 MIN_NUMBER_OF_ELEMENTS, UInt32 MAX_NUMBER_OF_ELEMENTS, UInt32 RESERVED_NUMBER_OF_ELEMENTS, const typename SInt32ArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::GetValueFunction DEFAULT>
        class SInt32ArrayProperty : public SInt32ArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>
        {
        public:
            explicit SInt32ArrayProperty()
            : SInt32ArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>(DEFAULT())
            {
            }
            void Reset()
            {
                SInt32ArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue.SetCount(RESERVED_NUMBER_OF_ELEMENTS);
                for (UInt32 i = 0; i < RESERVED_NUMBER_OF_ELEMENTS; i++)
                {
                    SInt32ArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue[i] = DEFAULT().mValue[i];
                }
            }
            static const PropertyInfo::Item* GetTypeInfo()
            {
                static PropertyInfo::Item p =
                {
                    DEFAULT().mId,
                    TypedProperty<SInt32>::GetTypeName(),
                    IEnums::PROPERTY_SEMANTIC_VALUE,
                    1,
                    MIN_NUMBER_OF_ELEMENTS,
                    MAX_NUMBER_OF_ELEMENTS,
                    MIN_NUMBER_OF_ELEMENTS,
                    MAX_NUMBER_OF_ELEMENTS,
                    GetDefaultStrings()
                };
                return &p;
            }
            static SInt32 GetId()
            {
                return DEFAULT().mId;
            }
            static Array<Array<String> > GetDefaultStrings()
            {
                Array<Array<String> > a;
                a.SetCount(MAX_NUMBER_OF_ELEMENTS);
                for (UInt32 i = 0; i < MAX_NUMBER_OF_ELEMENTS; i++)
                {
                    Array<String>& b = a[i];
                    b.Add(Util::SInt32ToString(DEFAULT().mValue[i]));
                }
                return a;
            }
        };
        

        // ========== UInt32 ==========

        // UInt32Property
        typedef TypedScalarValueProperty<UInt32> UInt32PropertyBase;

        template<const UInt32PropertyBase::GetValueFunction DEFAULT>
        class UInt32Property : public UInt32PropertyBase
        {
        public:
            explicit UInt32Property()
            : UInt32PropertyBase(DEFAULT().mValue)
            {
            }
            void Reset()
            {
                UInt32PropertyBase::mValue = DEFAULT().mValue;
            }
            UInt32& operator=(UInt32 const& rhs)
            {
                UInt32PropertyBase::mValue = rhs;
                return UInt32PropertyBase::mValue;
            }
            static const PropertyInfo::Item* GetTypeInfo()
            {
                static PropertyInfo::Item p =
                {
                    DEFAULT().mId,
                    TypedProperty<UInt32>::GetTypeName(),
                    IEnums::PROPERTY_SEMANTIC_VALUE,
                    1,
                    1,
                    1,
                    0,
                    1,
                    GetDefaultStrings()
                };
                return &p;
            }
            static SInt32 GetId()
            {
                return DEFAULT().mId;
            }
            static Array<Array<String> > GetDefaultStrings()
            {
                Array<Array<String> > a;
                a.SetCount(1);
                a[0].Add(Util::UInt32ToString(DEFAULT().mValue));
                return a;
            }
        };

        // UInt32FieldProperty
        template<UInt32 NUM_ELEMENTS>
        class UInt32FieldPropertyBase : public TypedValueFieldProperty<UInt32, NUM_ELEMENTS>
        {
        public:
            explicit UInt32FieldPropertyBase(UInt32 value)
            : TypedValueFieldProperty<UInt32, NUM_ELEMENTS>(value)
            {
            }
            explicit UInt32FieldPropertyBase(const typename TypedValueFieldProperty<UInt32, NUM_ELEMENTS>::Value& v)
            : TypedValueFieldProperty<UInt32, NUM_ELEMENTS>(v)
            {
            }
        };

        template<UInt32 NUM_ELEMENTS, const typename UInt32FieldPropertyBase<NUM_ELEMENTS>::GetValueFunction DEFAULT>
        class UInt32FieldProperty : public UInt32FieldPropertyBase<NUM_ELEMENTS>
        {
        public:
            explicit UInt32FieldProperty()
            : UInt32FieldPropertyBase<NUM_ELEMENTS>(DEFAULT())
            {
            }
            void Reset()
            {
                Util::MemCopy(UInt32FieldPropertyBase<NUM_ELEMENTS>::mValue, DEFAULT().mValue, sizeof(DEFAULT().mValue));
            }
            static const PropertyInfo::Item* GetTypeInfo()
            {
                static PropertyInfo::Item p =
                {
                    DEFAULT().mId,
                    TypedProperty<UInt32>::GetTypeName(),
                    IEnums::PROPERTY_SEMANTIC_VALUE,
                    1,
                    NUM_ELEMENTS,
                    NUM_ELEMENTS,
                    0,
                    NUM_ELEMENTS,
                    GetDefaultStrings()
                };
                return &p;
            }
            static SInt32 GetId()
            {
                return DEFAULT().mId;
            }
            static Array<Array<String> > GetDefaultStrings()
            {
                Array<Array<String> > a;
                a.SetCount(NUM_ELEMENTS);
                for (UInt32 i = 0; i < NUM_ELEMENTS; i++)
                {
                    Array<String>& b = a[i];
                    b.Add(Util::UInt32ToString(DEFAULT().mValue[i]));
                }
                return a;
            }
        };
        
        // UInt32ArrayProperty
        template<UInt32 MIN_NUMBER_OF_ELEMENTS, UInt32 MAX_NUMBER_OF_ELEMENTS, UInt32 RESERVED_NUMBER_OF_ELEMENTS>
        class UInt32ArrayPropertyBase : public TypedValueArrayProperty<UInt32, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>
        {
        public:
            explicit UInt32ArrayPropertyBase(UInt32 value)
            : TypedValueArrayProperty<UInt32, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>(value)
            {
            }
            explicit UInt32ArrayPropertyBase(const typename TypedValueArrayProperty<UInt32, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::Value& v)
            : TypedValueArrayProperty<UInt32, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>(v)
            {
            }
        };

        template<UInt32 MIN_NUMBER_OF_ELEMENTS, UInt32 MAX_NUMBER_OF_ELEMENTS, UInt32 RESERVED_NUMBER_OF_ELEMENTS, const typename UInt32ArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::GetValueFunction DEFAULT>
        class UInt32ArrayProperty : public UInt32ArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>
        {
        public:
            explicit UInt32ArrayProperty()
            : UInt32ArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>(DEFAULT())
            {
            }
            void Reset()
            {
                UInt32ArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue.SetCount(RESERVED_NUMBER_OF_ELEMENTS);
                for (UInt32 i = 0; i < RESERVED_NUMBER_OF_ELEMENTS; i++)
                {
                    UInt32ArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue[i] = DEFAULT().mValue[i];
                }
            }
            static const PropertyInfo::Item* GetTypeInfo()
            {
                static PropertyInfo::Item p =
                {
                    DEFAULT().mId,
                    TypedProperty<UInt32>::GetTypeName(),
                    IEnums::PROPERTY_SEMANTIC_VALUE,
                    1,
                    MIN_NUMBER_OF_ELEMENTS,
                    MAX_NUMBER_OF_ELEMENTS,
                    MIN_NUMBER_OF_ELEMENTS,
                    MAX_NUMBER_OF_ELEMENTS,
                    GetDefaultStrings()
                };
                return &p;
            }
            static SInt32 GetId()
            {
                return DEFAULT().mId;
            }
            static Array<Array<String> > GetDefaultStrings()
            {
                Array<Array<String> > a;
                a.SetCount(MAX_NUMBER_OF_ELEMENTS);
                for (UInt32 i = 0; i < MAX_NUMBER_OF_ELEMENTS; i++)
                {
                    Array<String>& b = a[i];
                    b.Add(Util::UInt32ToString(DEFAULT().mValue[i]));
                }
                return a;
            }
        };


        // ========== UInt32Mask ==========

        // UInt32MaskProperty
        typedef TypedScalarMaskProperty<UInt32> UInt32MaskPropertyBase;

        template<const UInt32MaskPropertyBase::GetValueFunction DEFAULT>
        class UInt32MaskProperty : public UInt32MaskPropertyBase
        {
        public:
            explicit UInt32MaskProperty()
            : UInt32MaskPropertyBase(DEFAULT().mValue)
            {
            }
            void Reset()
            {
                UInt32MaskPropertyBase::mValue = DEFAULT().mValue;
            }
            UInt32& operator=(UInt32 const& rhs)
            {
                UInt32MaskPropertyBase::mValue = rhs;
                return UInt32MaskPropertyBase::mValue;
            }
            static const PropertyInfo::Item* GetTypeInfo()
            {
                static PropertyInfo::Item p =
                {
                    DEFAULT().mId,
                    TypedProperty<UInt32>::GetTypeName(),
                    IEnums::PROPERTY_SEMANTIC_MASK,
                    1,
                    1,
                    1,
                    0,
                    1,
                    GetDefaultStrings()
                };
                return &p;
            }
            static SInt32 GetId()
            {
                return DEFAULT().mId;
            }
            static Array<Array<String> > GetDefaultStrings()
            {
                Array<Array<String> > a;
                a.SetCount(1);
                a[0].Add(Util::UInt32ToString(DEFAULT().mValue));
                return a;
            }
        };

        // UInt32MaskFieldProperty
        template<UInt32 NUM_ELEMENTS>
        class UInt32MaskFieldPropertyBase : public TypedMaskFieldProperty<UInt32, NUM_ELEMENTS>
        {
        public:
            explicit UInt32MaskFieldPropertyBase(UInt32 value)
            : TypedMaskFieldProperty<UInt32, NUM_ELEMENTS>(value)
            {
            }
            explicit UInt32MaskFieldPropertyBase(const typename TypedMaskFieldProperty<UInt32, NUM_ELEMENTS>::Value& v)
            : TypedMaskFieldProperty<UInt32, NUM_ELEMENTS>(v)
            {
            }
        };

        template<UInt32 NUM_ELEMENTS, const typename UInt32MaskFieldPropertyBase<NUM_ELEMENTS>::GetValueFunction DEFAULT>
        class UInt32MaskFieldProperty : public UInt32MaskFieldPropertyBase<NUM_ELEMENTS>
        {
        public:
            explicit UInt32MaskFieldProperty()
            : UInt32MaskFieldPropertyBase<NUM_ELEMENTS>(DEFAULT())
            {
            }
            void Reset()
            {
                Util::MemCopy(UInt32MaskFieldPropertyBase<NUM_ELEMENTS>::mValue, DEFAULT().mValue, sizeof(DEFAULT().mValue));
            }
            static const PropertyInfo::Item* GetTypeInfo()
            {
                static PropertyInfo::Item p =
                {
                    DEFAULT().mId,
                    TypedProperty<UInt32>::GetTypeName(),
                    IEnums::PROPERTY_SEMANTIC_MASK,
                    1,
                    NUM_ELEMENTS,
                    NUM_ELEMENTS,
                    0,
                    NUM_ELEMENTS,
                    GetDefaultStrings()
                };
                return &p;
            }
            static SInt32 GetId()
            {
                return DEFAULT().mId;
            }
            static Array<Array<String> > GetDefaultStrings()
            {
                Array<Array<String> > a;
                a.SetCount(NUM_ELEMENTS);
                for (UInt32 i = 0; i < NUM_ELEMENTS; i++)
                {
                    Array<String>& b = a[i];
                    b.Add(Util::UInt32ToString(DEFAULT().mValue[i]));
                }
                return a;
            }
        };

        // UInt32MaskArrayProperty
        template<UInt32 MIN_NUMBER_OF_ELEMENTS, UInt32 MAX_NUMBER_OF_ELEMENTS, UInt32 RESERVED_NUMBER_OF_ELEMENTS>
        class UInt32MaskArrayPropertyBase : public TypedMaskArrayProperty<UInt32, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>
        {
        public:
            explicit UInt32MaskArrayPropertyBase(UInt32 value)
            : TypedMaskArrayProperty<UInt32, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>(value)
            {
            }
            explicit UInt32MaskArrayPropertyBase(const typename TypedMaskArrayProperty<UInt32, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::Value& v)
            : TypedMaskArrayProperty<UInt32, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>(v)
            {
            }
        };

        template<UInt32 MIN_NUMBER_OF_ELEMENTS, UInt32 MAX_NUMBER_OF_ELEMENTS, UInt32 RESERVED_NUMBER_OF_ELEMENTS, const typename UInt32MaskArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::GetValueFunction DEFAULT>
        class UInt32MaskArrayProperty : public UInt32MaskArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>
        {
        public:
            explicit UInt32MaskArrayProperty()
            : UInt32MaskArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>(DEFAULT())
            {
            }
            void Reset()
            {
                UInt32MaskArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue.SetCount(RESERVED_NUMBER_OF_ELEMENTS);
                for (UInt32 i = 0; i < RESERVED_NUMBER_OF_ELEMENTS; i++)
                {
                    UInt32MaskArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue[i] = DEFAULT().mValue[i];
                }
            }
            static const PropertyInfo::Item* GetTypeInfo()
            {
                static PropertyInfo::Item p =
                {
                    DEFAULT().mId,
                    TypedProperty<UInt32>::GetTypeName(),
                    IEnums::PROPERTY_SEMANTIC_MASK,
                    1,
                    MIN_NUMBER_OF_ELEMENTS,
                    MAX_NUMBER_OF_ELEMENTS,
                    MIN_NUMBER_OF_ELEMENTS,
                    MAX_NUMBER_OF_ELEMENTS,
                    GetDefaultStrings()
                };
                return &p;
            }
            static SInt32 GetId()
            {
                return DEFAULT().mId;
            }
            static Array<Array<String> > GetDefaultStrings()
            {
                Array<Array<String> > a;
                a.SetCount(MAX_NUMBER_OF_ELEMENTS);
                for (UInt32 i = 0; i < MAX_NUMBER_OF_ELEMENTS; i++)
                {
                    Array<String>& b = a[i];
                    b.Add(Util::UInt32ToString(DEFAULT().mValue[i]));
                }
                return a;
            }
        };


        // ========== Real ==========

        // RealProperty
        typedef TypedScalarValueProperty<Real> RealPropertyBase;

        template<const RealPropertyBase::GetValueFunction DEFAULT>
        class RealProperty : public RealPropertyBase
        {
        public:
            explicit RealProperty()
            : RealPropertyBase(DEFAULT().mValue)
            {
            }
            void Reset()
            {
                RealPropertyBase::mValue = DEFAULT().mValue;
            }
            Real& operator=(Real const& rhs)
            {
                RealPropertyBase::mValue = rhs;
                return RealPropertyBase::mValue;
            }
            static const PropertyInfo::Item* GetTypeInfo()
            {
                static PropertyInfo::Item p =
                {
                    DEFAULT().mId,
                    TypedProperty<Real>::GetTypeName(),
                    IEnums::PROPERTY_SEMANTIC_VALUE,
                    1,
                    1,
                    1,
                    0,
                    1,
                    GetDefaultStrings()
                };
                return &p;
            }
            static SInt32 GetId()
            {
                return DEFAULT().mId;
            }
            static Array<Array<String> > GetDefaultStrings()
            {
                Array<Array<String> > a;
                a.SetCount(1);
                a[0].Add(Util::DoubleToString(DEFAULT().mValue));
                return a;
            }
        };

        // RealFieldProperty
        template<UInt32 NUM_ELEMENTS>
        class RealFieldPropertyBase : public TypedValueFieldProperty<Real, NUM_ELEMENTS>
        {
        public:
            explicit RealFieldPropertyBase(Real value)
            : TypedValueFieldProperty<Real, NUM_ELEMENTS>(value)
            {
            }
            explicit RealFieldPropertyBase(const typename TypedValueFieldProperty<Real, NUM_ELEMENTS>::Value& v)
            : TypedValueFieldProperty<Real, NUM_ELEMENTS>(v)
            {
            }
        };

        template<UInt32 NUM_ELEMENTS, const typename RealFieldPropertyBase<NUM_ELEMENTS>::GetValueFunction DEFAULT>
        class RealFieldProperty : public RealFieldPropertyBase<NUM_ELEMENTS>
        {
        public:
            explicit RealFieldProperty()
            : RealFieldPropertyBase<NUM_ELEMENTS>(DEFAULT())
            {
            }
            void Reset()
            {
                Util::MemCopy(RealFieldPropertyBase<NUM_ELEMENTS>::mValue, DEFAULT().mValue, sizeof(DEFAULT().mValue));
            }
            static const PropertyInfo::Item* GetTypeInfo()
            {
                static PropertyInfo::Item p =
                {
                    DEFAULT().mId,
                    TypedProperty<Real>::GetTypeName(),
                    IEnums::PROPERTY_SEMANTIC_VALUE,
                    1,
                    NUM_ELEMENTS,
                    NUM_ELEMENTS,
                    0,
                    NUM_ELEMENTS,
                    GetDefaultStrings()
                };
                return &p;
            }
            static SInt32 GetId()
            {
                return DEFAULT().mId;
            }
            static Array<Array<String> > GetDefaultStrings()
            {
                Array<Array<String> > a;
                a.SetCount(NUM_ELEMENTS);
                for (UInt32 i = 0; i < NUM_ELEMENTS; i++)
                {
                    Array<String>& b = a[i];
                    b.Add(Util::DoubleToString(DEFAULT().mValue[i]));
                }
                return a;
            }
        };

        // RealArrayProperty
        template<UInt32 MIN_NUMBER_OF_ELEMENTS, UInt32 MAX_NUMBER_OF_ELEMENTS, UInt32 RESERVED_NUMBER_OF_ELEMENTS>
        class RealArrayPropertyBase : public TypedValueArrayProperty<Real, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>
        {
        public:
            explicit RealArrayPropertyBase(Real value)
            : TypedValueArrayProperty<Real, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>(value)
            {
            }
            explicit RealArrayPropertyBase(const typename TypedValueArrayProperty<Real, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::Value& v)
            : TypedValueArrayProperty<Real, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>(v)
            {
            }
        };

        template<UInt32 MIN_NUMBER_OF_ELEMENTS, UInt32 MAX_NUMBER_OF_ELEMENTS, UInt32 RESERVED_NUMBER_OF_ELEMENTS, const typename RealArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::GetValueFunction DEFAULT>
        class RealArrayProperty : public RealArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>
        {
        public:
            explicit RealArrayProperty()
            : RealArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>(DEFAULT())
            {
            }
            void Reset()
            {
                RealArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue.SetCount(RESERVED_NUMBER_OF_ELEMENTS);
                for (UInt32 i = 0; i < RESERVED_NUMBER_OF_ELEMENTS; i++)
                {
                    RealArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue[i] = DEFAULT().mValue[i];
                }
            }
            static const PropertyInfo::Item* GetTypeInfo()
            {
                static PropertyInfo::Item p =
                {
                    DEFAULT().mId,
                    TypedProperty<Real>::GetTypeName(),
                    IEnums::PROPERTY_SEMANTIC_VALUE,
                    1,
                    MIN_NUMBER_OF_ELEMENTS,
                    MAX_NUMBER_OF_ELEMENTS,
                    MIN_NUMBER_OF_ELEMENTS,
                    MAX_NUMBER_OF_ELEMENTS,
                    GetDefaultStrings()
                };
                return &p;
            }
            static SInt32 GetId()
            {
                return DEFAULT().mId;
            }
            static Array<Array<String> > GetDefaultStrings()
            {
                Array<Array<String> > a;
                a.SetCount(MAX_NUMBER_OF_ELEMENTS);
                for (UInt32 i = 0; i < MAX_NUMBER_OF_ELEMENTS; i++)
                {
                    Array<String>& b = a[i];
                    b.Add(Util::DoubleToString(DEFAULT().mValue[i]));
                }
                return a;
            }
        };
        

        // ========== RealAngle ==========

        // RealAngleProperty
        typedef TypedScalarAngleProperty<Real> RealAnglePropertyBase;

        template<const RealAnglePropertyBase::GetValueFunction DEFAULT>
        class RealAngleProperty : public RealAnglePropertyBase
        {
        public:
            explicit RealAngleProperty()
            : RealAnglePropertyBase(DEFAULT().mValue)
            {
            }
            void Reset()
            {
                RealAnglePropertyBase::mValue = DEFAULT().mValue;
            }
            Real& operator=(Real const& rhs)
            {
                RealAnglePropertyBase::mValue = rhs;
                return RealAnglePropertyBase::mValue;
            }
            static const PropertyInfo::Item* GetTypeInfo()
            {
                static PropertyInfo::Item p =
                {
                    DEFAULT().mId,
                    TypedProperty<Real>::GetTypeName(),
                    IEnums::PROPERTY_SEMANTIC_ANGLE,
                    1,
                    1,
                    1,
                    0,
                    1,
                    GetDefaultStrings()
                };
                return &p;
            }
            static SInt32 GetId()
            {
                return DEFAULT().mId;
            }
            static Array<Array<String> > GetDefaultStrings()
            {
                Array<Array<String> > a;
                a.SetCount(1);
                a[0].Add(Util::DoubleToString(DEFAULT().mValue) + "rad");
                return a;
            }
        };

        // RealAngleFieldProperty
        template<UInt32 NUM_ELEMENTS>
        class RealAngleFieldPropertyBase : public TypedAngleFieldProperty<Real, NUM_ELEMENTS>
        {
        public:
            explicit RealAngleFieldPropertyBase(Real value)
            : TypedAngleFieldProperty<Real, NUM_ELEMENTS>(value)
            {
            }
            explicit RealAngleFieldPropertyBase(const typename TypedAngleFieldProperty<Real, NUM_ELEMENTS>::Value& v)
            : TypedAngleFieldProperty<Real, NUM_ELEMENTS>(v)
            {
            }
        };

        template<UInt32 NUM_ELEMENTS, const typename RealAngleFieldPropertyBase<NUM_ELEMENTS>::GetValueFunction DEFAULT>
        class RealAngleFieldProperty : public RealAngleFieldPropertyBase<NUM_ELEMENTS>
        {
        public:
            explicit RealAngleFieldProperty()
            : RealAngleFieldPropertyBase<NUM_ELEMENTS>(DEFAULT())
            {
            }
            void Reset()
            {
                Util::MemCopy(RealAngleFieldPropertyBase<NUM_ELEMENTS>::mValue, DEFAULT().mValue, sizeof(DEFAULT().mValue));
            }
            static const PropertyInfo::Item* GetTypeInfo()
            {
                static PropertyInfo::Item p =
                {
                    DEFAULT().mId,
                    TypedProperty<Real>::GetTypeName(),
                    IEnums::PROPERTY_SEMANTIC_ANGLE,
                    1,
                    NUM_ELEMENTS,
                    NUM_ELEMENTS,
                    0,
                    NUM_ELEMENTS,
                    GetDefaultStrings()
                };
                return &p;
            }
            static SInt32 GetId()
            {
                return DEFAULT().mId;
            }
            static Array<Array<String> > GetDefaultStrings()
            {
                Array<Array<String> > a;
                a.SetCount(NUM_ELEMENTS);
                for (UInt32 i = 0; i < NUM_ELEMENTS; i++)
                {
                    Array<String>& b = a[i];
                    b.Add(Util::DoubleToString(DEFAULT().mValue[i]) + "rad");
                }
                return a;
            }
        };
        
        // RealAngleArrayProperty
        template<UInt32 MIN_NUMBER_OF_ELEMENTS, UInt32 MAX_NUMBER_OF_ELEMENTS, UInt32 RESERVED_NUMBER_OF_ELEMENTS>
        class RealAngleArrayPropertyBase : public TypedAngleArrayProperty<Real, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>
        {
        public:
            explicit RealAngleArrayPropertyBase(Real value)
            : TypedAngleArrayProperty<Real, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>(value)
            {
            }
            explicit RealAngleArrayPropertyBase(const typename TypedAngleArrayProperty<Real, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::Value& v)
            : TypedAngleArrayProperty<Real, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>(v)
            {
            }
        };

        template<UInt32 MIN_NUMBER_OF_ELEMENTS, UInt32 MAX_NUMBER_OF_ELEMENTS, UInt32 RESERVED_NUMBER_OF_ELEMENTS, const typename RealAngleArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::GetValueFunction DEFAULT>
        class RealAngleArrayProperty : public RealAngleArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>
        {
        public:
            explicit RealAngleArrayProperty()
            : RealAngleArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>(DEFAULT())
            {
            }
            void Reset()
            {
                RealAngleArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue.SetCount(RESERVED_NUMBER_OF_ELEMENTS);
                for (UInt32 i = 0; i < RESERVED_NUMBER_OF_ELEMENTS; i++)
                {
                    RealAngleArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue[i] = DEFAULT().mValue[i];
                }
            }
            static const PropertyInfo::Item* GetTypeInfo()
            {
                static PropertyInfo::Item p =
                {
                    DEFAULT().mId,
                    TypedProperty<Real>::GetTypeName(),
                    IEnums::PROPERTY_SEMANTIC_ANGLE,
                    1,
                    MIN_NUMBER_OF_ELEMENTS,
                    MAX_NUMBER_OF_ELEMENTS,
                    MIN_NUMBER_OF_ELEMENTS,
                    MAX_NUMBER_OF_ELEMENTS,
                    GetDefaultStrings()
                };
                return &p;
            }
            static SInt32 GetId()
            {
                return DEFAULT().mId;
            }
            static Array<Array<String> > GetDefaultStrings()
            {
                Array<Array<String> > a;
                a.SetCount(MAX_NUMBER_OF_ELEMENTS);
                for (UInt32 i = 0; i < MAX_NUMBER_OF_ELEMENTS; i++)
                {
                    Array<String>& b = a[i];
                    b.Add(Util::DoubleToString(DEFAULT().mValue[i]) + "rad");
                }
                return a;
            }
        };


        // ========== Double ==========

        // DoubleProperty
        typedef TypedScalarValueProperty<Double> DoublePropertyBase;

        template<const DoublePropertyBase::GetValueFunction DEFAULT>
        class DoubleProperty : public DoublePropertyBase
        {
        public:
            explicit DoubleProperty()
            : DoublePropertyBase(DEFAULT().mValue)
            {
            }
            void Reset()
            {
                DoublePropertyBase::mValue = DEFAULT().mValue;
            }
            Double& operator=(Double const& rhs)
            {
                DoublePropertyBase::mValue = rhs;
                return DoublePropertyBase::mValue;
            }
            static const PropertyInfo::Item* GetTypeInfo()
            {
                static PropertyInfo::Item p =
                {
                    DEFAULT().mId,
                    TypedProperty<Double>::GetTypeName(),
                    IEnums::PROPERTY_SEMANTIC_VALUE,
                    1,
                    1,
                    1,
                    0,
                    1,
                    GetDefaultStrings()
                };
                return &p;
            }
            static SInt32 GetId()
            {
                return DEFAULT().mId;
            }
            static Array<Array<String> > GetDefaultStrings()
            {
                Array<Array<String> > a;
                a.SetCount(1);
                a[0].Add(Util::DoubleToString(DEFAULT().mValue));
                return a;
            }
        };

        // DoubleFieldProperty
        template<UInt32 NUM_ELEMENTS>
        class DoubleFieldPropertyBase : public TypedValueFieldProperty<Double, NUM_ELEMENTS>
        {
        public:
            explicit DoubleFieldPropertyBase(Double value)
            : TypedValueFieldProperty<Double, NUM_ELEMENTS>(value)
            {
            }
            explicit DoubleFieldPropertyBase(const typename TypedValueFieldProperty<Double, NUM_ELEMENTS>::Value& v)
            : TypedValueFieldProperty<Double, NUM_ELEMENTS>(v)
            {
            }
        };

        template<UInt32 NUM_ELEMENTS, const typename DoubleFieldPropertyBase<NUM_ELEMENTS>::GetValueFunction DEFAULT>
        class DoubleFieldProperty : public DoubleFieldPropertyBase<NUM_ELEMENTS>
        {
        public:
            explicit DoubleFieldProperty()
            : DoubleFieldPropertyBase<NUM_ELEMENTS>(DEFAULT())
            {
            }
            void Reset()
            {
                Util::MemCopy(DoubleFieldPropertyBase<NUM_ELEMENTS>::mValue, DEFAULT().mValue, sizeof(DEFAULT().mValue));
            }
            static const PropertyInfo::Item* GetTypeInfo()
            {
                static PropertyInfo::Item p =
                {
                    DEFAULT().mId,
                    TypedProperty<Double>::GetTypeName(),
                    IEnums::PROPERTY_SEMANTIC_VALUE,
                    1,
                    NUM_ELEMENTS,
                    NUM_ELEMENTS,
                    0,
                    NUM_ELEMENTS,
                    GetDefaultStrings()
                };
                return &p;
            }
            static SInt32 GetId()
            {
                return DEFAULT().mId;
            }
            static Array<Array<String> > GetDefaultStrings()
            {
                Array<Array<String> > a;
                a.SetCount(NUM_ELEMENTS);
                for (UInt32 i = 0; i < NUM_ELEMENTS; i++)
                {
                    Array<String>& b = a[i];
                    b.Add(Util::DoubleToString(DEFAULT().mValue[i]));
                }
                return a;
            }
        };

        // DoubleArrayProperty
        template<UInt32 MIN_NUMBER_OF_ELEMENTS, UInt32 MAX_NUMBER_OF_ELEMENTS, UInt32 RESERVED_NUMBER_OF_ELEMENTS>
        class DoubleArrayPropertyBase : public TypedValueArrayProperty<Double, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>
        {
        public:
            explicit DoubleArrayPropertyBase(Double value)
            : TypedValueArrayProperty<Double, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>(value)
            {
            }
            explicit DoubleArrayPropertyBase(const typename TypedValueArrayProperty<Double, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::Value& v)
            : TypedValueArrayProperty<Double, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>(v)
            {
            }
        };

        template<UInt32 MIN_NUMBER_OF_ELEMENTS, UInt32 MAX_NUMBER_OF_ELEMENTS, UInt32 RESERVED_NUMBER_OF_ELEMENTS, const typename DoubleArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::GetValueFunction DEFAULT>
        class DoubleArrayProperty : public DoubleArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>
        {
        public:
            explicit DoubleArrayProperty()
            : DoubleArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>(DEFAULT())
            {
            }
            void Reset()
            {
                DoubleArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue.SetCount(RESERVED_NUMBER_OF_ELEMENTS);
                for (UInt32 i = 0; i < RESERVED_NUMBER_OF_ELEMENTS; i++)
                {
                    DoubleArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue[i] = DEFAULT().mValue[i];
                }
            }
            static const PropertyInfo::Item* GetTypeInfo()
            {
                static PropertyInfo::Item p =
                {
                    DEFAULT().mId,
                    TypedProperty<Double>::GetTypeName(),
                    IEnums::PROPERTY_SEMANTIC_VALUE,
                    1,
                    MIN_NUMBER_OF_ELEMENTS,
                    MAX_NUMBER_OF_ELEMENTS,
                    MIN_NUMBER_OF_ELEMENTS,
                    MAX_NUMBER_OF_ELEMENTS,
                    GetDefaultStrings()
                };
                return &p;
            }
            static SInt32 GetId()
            {
                return DEFAULT().mId;
            }
            static Array<Array<String> > GetDefaultStrings()
            {
                Array<Array<String> > a;
                a.SetCount(MAX_NUMBER_OF_ELEMENTS);
                for (UInt32 i = 0; i < MAX_NUMBER_OF_ELEMENTS; i++)
                {
                    Array<String>& b = a[i];
                    b.Add(Util::DoubleToString(DEFAULT().mValue[i]));
                }
                return a;
            }
        };


        // ========== DoubleAngle ==========

        // DoubleAngleProperty
        typedef TypedScalarAngleProperty<Double> DoubleAnglePropertyBase;

        template<const DoubleAnglePropertyBase::GetValueFunction DEFAULT>
        class DoubleAngleProperty : public DoubleAnglePropertyBase
        {
        public:
            explicit DoubleAngleProperty()
            : DoubleAnglePropertyBase(DEFAULT().mValue)
            {
            }
            void Reset()
            {
                DoubleAnglePropertyBase::mValue = DEFAULT().mValue;
            }
            Double& operator=(Double const& rhs)
            {
                DoubleAnglePropertyBase::mValue = rhs;
                return DoubleAnglePropertyBase::mValue;
            }
            static const PropertyInfo::Item* GetTypeInfo()
            {
                static PropertyInfo::Item p =
                {
                    DEFAULT().mId,
                    TypedProperty<Double>::GetTypeName(),
                    IEnums::PROPERTY_SEMANTIC_ANGLE,
                    1,
                    1,
                    1,
                    0,
                    1,
                    GetDefaultStrings()
                };
                return &p;
            }
            static SInt32 GetId()
            {
                return DEFAULT().mId;
            }
            static Array<Array<String> > GetDefaultStrings()
            {
                Array<Array<String> > a;
                a.SetCount(1);
                a[0].Add(Util::DoubleToString(DEFAULT().mValue) + "rad");
                return a;
            }
        };

        // DoubleAngleFieldProperty
        template<UInt32 NUM_ELEMENTS>
        class DoubleAngleFieldPropertyBase : public TypedAngleFieldProperty<Double, NUM_ELEMENTS>
        {
        public:
            explicit DoubleAngleFieldPropertyBase(Double value)
            : TypedAngleFieldProperty<Double, NUM_ELEMENTS>(value)
            {
            }
            explicit DoubleAngleFieldPropertyBase(const typename TypedAngleFieldProperty<Double, NUM_ELEMENTS>::Value& v)
            : TypedAngleFieldProperty<Double, NUM_ELEMENTS>(v)
            {
            }
        };

        template<UInt32 NUM_ELEMENTS, const typename DoubleAngleFieldPropertyBase<NUM_ELEMENTS>::GetValueFunction DEFAULT>
        class DoubleAngleFieldProperty : public DoubleAngleFieldPropertyBase<NUM_ELEMENTS>
        {
        public:
            explicit DoubleAngleFieldProperty()
            : DoubleAngleFieldPropertyBase<NUM_ELEMENTS>(DEFAULT())
            {
            }
            void Reset()
            {
                Util::MemCopy(DoubleAngleFieldPropertyBase<NUM_ELEMENTS>::mValue, DEFAULT().mValue, sizeof(DEFAULT().mValue));
            }
            static const PropertyInfo::Item* GetTypeInfo()
            {
                static PropertyInfo::Item p =
                {
                    DEFAULT().mId,
                    TypedProperty<Double>::GetTypeName(),
                    IEnums::PROPERTY_SEMANTIC_ANGLE,
                    1,
                    NUM_ELEMENTS,
                    NUM_ELEMENTS,
                    0,
                    NUM_ELEMENTS,
                    GetDefaultStrings()
                };
                return &p;
            }
            static SInt32 GetId()
            {
                return DEFAULT().mId;
            }
            static Array<Array<String> > GetDefaultStrings()
            {
                Array<Array<String> > a;
                a.SetCount(NUM_ELEMENTS);
                for (UInt32 i = 0; i < NUM_ELEMENTS; i++)
                {
                    Array<String>& b = a[i];
                    b.Add(Util::DoubleToString(DEFAULT().mValue[i]) + "rad");
                }
                return a;
            }
        };

        // DoubleAngleArrayProperty
        template<UInt32 MIN_NUMBER_OF_ELEMENTS, UInt32 MAX_NUMBER_OF_ELEMENTS, UInt32 RESERVED_NUMBER_OF_ELEMENTS>
        class DoubleAngleArrayPropertyBase : public TypedAngleArrayProperty<Double, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>
        {
        public:
            explicit DoubleAngleArrayPropertyBase(Double value)
            : TypedAngleArrayProperty<Double, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>(value)
            {
            }
            explicit DoubleAngleArrayPropertyBase(const typename TypedAngleArrayProperty<Double, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::Value& v)
            : TypedAngleArrayProperty<Double, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>(v)
            {
            }
        };

        template<UInt32 MIN_NUMBER_OF_ELEMENTS, UInt32 MAX_NUMBER_OF_ELEMENTS, UInt32 RESERVED_NUMBER_OF_ELEMENTS, const typename DoubleAngleArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::GetValueFunction DEFAULT>
        class DoubleAngleArrayProperty : public DoubleAngleArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>
        {
        public:
            explicit DoubleAngleArrayProperty()
            : DoubleAngleArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>(DEFAULT())
            {
            }
            void Reset()
            {
                DoubleAngleArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue.SetCount(RESERVED_NUMBER_OF_ELEMENTS);
                for (UInt32 i = 0; i < RESERVED_NUMBER_OF_ELEMENTS; i++)
                {
                    DoubleAngleArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue[i] = DEFAULT().mValue[i];
                }
            }
            static const PropertyInfo::Item* GetTypeInfo()
            {
                static PropertyInfo::Item p =
                {
                    DEFAULT().mId,
                    TypedProperty<Double>::GetTypeName(),
                    IEnums::PROPERTY_SEMANTIC_ANGLE,
                    1,
                    MIN_NUMBER_OF_ELEMENTS,
                    MAX_NUMBER_OF_ELEMENTS,
                    MIN_NUMBER_OF_ELEMENTS,
                    MAX_NUMBER_OF_ELEMENTS,
                    GetDefaultStrings()
                };
                return &p;
            }
            static SInt32 GetId()
            {
                return DEFAULT().mId;
            }
            static Array<Array<String> > GetDefaultStrings()
            {
                Array<Array<String> > a;
                a.SetCount(MAX_NUMBER_OF_ELEMENTS);
                for (UInt32 i = 0; i < MAX_NUMBER_OF_ELEMENTS; i++)
                {
                    Array<String>& b = a[i];
                    b.Add(Util::DoubleToString(DEFAULT().mValue[i]) + "rad");
                }
                return a;
            }
        };
        
        
        // ========== Vector ==========

        // VectorProperty
        typedef TypedVectorProperty<Real> VectorPropertyBase;

        template<const VectorPropertyBase::GetValueFunction DEFAULT>
        class VectorProperty : public VectorPropertyBase
        {
        public:
            explicit VectorProperty()
            : VectorPropertyBase(DEFAULT().mValue)
            {
            }
            void Reset()
            {
                VectorPropertyBase::mValue = DEFAULT().mValue;
            }
            Vector& operator=(Vector const& rhs)
            {
                VectorPropertyBase::mValue = rhs;
                return VectorPropertyBase::mValue;
            }
            static const PropertyInfo::Item* GetTypeInfo()
            {
                static PropertyInfo::Item p =
                {
                    DEFAULT().mId,
                    "Murl::Graph::Vector",
                    IEnums::PROPERTY_SEMANTIC_VALUE,
                    Vector::NUM_COMPONENTS,
                    1,
                    1,
                    0,
                    1,
                    GetDefaultStrings()
                };
                return &p;
            }
            static SInt32 GetId()
            {
                return DEFAULT().mId;
            }
            static Array<Array<String> > GetDefaultStrings()
            {
                Array<Array<String> > a;
                a.SetCount(1);
                Array<String>& b = a[0];
                for (UInt32 i = 0; i < Vector::NUM_COMPONENTS; i++)
                {
                    b.Add(Util::DoubleToString(DEFAULT().mValue.GetPointer()[i]));
                }
                return a;
            }
        };

        // VectorFieldProperty
        template<UInt32 NUM_ELEMENTS>
        class VectorFieldPropertyBase : public TypedVectorFieldProperty<Real, NUM_ELEMENTS>
        {
        public:
            explicit VectorFieldPropertyBase(const typename TypedVectorFieldProperty<Real, NUM_ELEMENTS>::Value& v)
            : TypedVectorFieldProperty<Real, NUM_ELEMENTS>(v)
            {
            }
        };

        template<UInt32 NUM_ELEMENTS, const typename VectorFieldPropertyBase<NUM_ELEMENTS>::GetValueFunction DEFAULT>
        class VectorFieldProperty : public VectorFieldPropertyBase<NUM_ELEMENTS>
        {
        public:
            explicit VectorFieldProperty()
            : VectorFieldPropertyBase<NUM_ELEMENTS>(DEFAULT())
            {
            }
            void Reset()
            {
                for (UInt32 i = 0; i < NUM_ELEMENTS; i++)
                {
                    VectorFieldPropertyBase<NUM_ELEMENTS>::mValue[i] = DEFAULT().mValue[i];
                }
            }
            static const PropertyInfo::Item* GetTypeInfo()
            {
                static PropertyInfo::Item p =
                {
                    DEFAULT().mId,
                    "Murl::Graph::Vector",
                    IEnums::PROPERTY_SEMANTIC_VALUE,
                    Vector::NUM_COMPONENTS,
                    NUM_ELEMENTS,
                    NUM_ELEMENTS,
                    0,
                    NUM_ELEMENTS,
                    GetDefaultStrings()
                };
                return &p;
            }
            static SInt32 GetId()
            {
                return DEFAULT().mId;
            }
            static Array<Array<String> > GetDefaultStrings()
            {
                Array<Array<String> > a;
                a.SetCount(NUM_ELEMENTS);
                for (UInt32 j = 0; j < NUM_ELEMENTS; j++)
                {
                    Array<String>& b = a[j];
                    for (UInt32 i = 0; i < Vector::NUM_COMPONENTS; i++)
                    {
                        b.Add(Util::DoubleToString(DEFAULT().mValue[j].GetPointer()[i]));
                    }
                }
                return a;
            }
        };

        // VectorArrayProperty
        template<UInt32 MIN_NUMBER_OF_ELEMENTS, UInt32 MAX_NUMBER_OF_ELEMENTS, UInt32 RESERVED_NUMBER_OF_ELEMENTS>
        class VectorArrayPropertyBase : public TypedVectorArrayProperty<Real, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>
        {
        public:
            explicit VectorArrayPropertyBase(const typename TypedVectorArrayProperty<Real, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::Value& v)
            : TypedVectorArrayProperty<Real, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>(v)
            {
            }
        };

        template<UInt32 MIN_NUMBER_OF_ELEMENTS, UInt32 MAX_NUMBER_OF_ELEMENTS, UInt32 RESERVED_NUMBER_OF_ELEMENTS, const typename VectorArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::GetValueFunction DEFAULT>
        class VectorArrayProperty : public VectorArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>
        {
        public:
            explicit VectorArrayProperty()
            : VectorArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>(DEFAULT())
            {
            }
            void Reset()
            {
                VectorArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue.SetCount(RESERVED_NUMBER_OF_ELEMENTS);
                for (UInt32 i = 0; i < RESERVED_NUMBER_OF_ELEMENTS; i++)
                {
                    VectorArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue[i] = DEFAULT().mValue[i];
                }
            }
            static const PropertyInfo::Item* GetTypeInfo()
            {
                static PropertyInfo::Item p =
                {
                    DEFAULT().mId,
                    "Murl::Graph::Vector",
                    IEnums::PROPERTY_SEMANTIC_VALUE,
                    Math::Vector<Real>::NUM_COMPONENTS,
                    MIN_NUMBER_OF_ELEMENTS,
                    MAX_NUMBER_OF_ELEMENTS,
                    MIN_NUMBER_OF_ELEMENTS,
                    MAX_NUMBER_OF_ELEMENTS,
                    GetDefaultStrings()
                };
                return &p;
            }
            static SInt32 GetId()
            {
                return DEFAULT().mId;
            }
            static Array<Array<String> > GetDefaultStrings()
            {
                Array<Array<String> > a;
                a.SetCount(MAX_NUMBER_OF_ELEMENTS);
                for (UInt32 j = 0; j < MAX_NUMBER_OF_ELEMENTS; j++)
                {
                    Array<String>& b = a[j];
                    for (UInt32 i = 0; i < Vector::NUM_COMPONENTS; i++)
                    {
                        b.Add(Util::DoubleToString(DEFAULT().mValue[j].GetPointer()[i]));
                    }
                }
                return a;
            }
        };


        // ========== VectorAngle ==========

        // VectorAngleProperty
        typedef TypedVectorAngleProperty<Real> VectorAnglePropertyBase;

        template<const VectorAnglePropertyBase::GetValueFunction DEFAULT>
        class VectorAngleProperty : public VectorAnglePropertyBase
        {
        public:
            explicit VectorAngleProperty()
            : VectorAnglePropertyBase(DEFAULT().mValue)
            {
            }
            void Reset()
            {
                VectorAnglePropertyBase::mValue = DEFAULT().mValue;
            }
            Vector& operator=(Vector const& rhs)
            {
                VectorAnglePropertyBase::mValue = rhs;
                return VectorAnglePropertyBase::mValue;
            }
            static const PropertyInfo::Item* GetTypeInfo()
            {
                static PropertyInfo::Item p =
                {
                    DEFAULT().mId,
                    "Murl::Graph::Vector",
                    IEnums::PROPERTY_SEMANTIC_ANGLE,
                    Vector::NUM_COMPONENTS,
                    1,
                    1,
                    0,
                    1,
                    GetDefaultStrings()
                };
                return &p;
            }
            static SInt32 GetId()
            {
                return DEFAULT().mId;
            }
            static Array<Array<String> > GetDefaultStrings()
            {
                Array<Array<String> > a;
                a.SetCount(1);
                Array<String>& b = a[0];
                for (UInt32 i = 0; i < Vector::NUM_COMPONENTS; i++)
                {
                    b.Add(Util::DoubleToString(DEFAULT().mValue.GetPointer()[i]) + "rad");
                }
                return a;
            }
        };


        // ========== Matrix ==========

        // MatrixProperty
        typedef TypedMatrixProperty<Real> MatrixPropertyBase;

        template<const MatrixPropertyBase::GetValueFunction DEFAULT>
        class MatrixProperty : public MatrixPropertyBase
        {
        public:
            explicit MatrixProperty()
            : MatrixPropertyBase(DEFAULT().mValue)
            {
            }
            void Reset()
            {
                MatrixPropertyBase::mValue = DEFAULT().mValue;
            }
            Matrix& operator=(Matrix const& rhs)
            {
                MatrixPropertyBase::mValue = rhs;
                return MatrixPropertyBase::mValue;
            }
            static const PropertyInfo::Item* GetTypeInfo()
            {
                static PropertyInfo::Item p =
                {
                    DEFAULT().mId,
                    "Murl::Graph::Matrix",
                    IEnums::PROPERTY_SEMANTIC_VALUE,
                    Matrix::NUM_COMPONENTS,
                    1,
                    1,
                    0,
                    1,
                    GetDefaultStrings()
                };
                return &p;
            }
            static SInt32 GetId()
            {
                return DEFAULT().mId;
            }
            static Array<Array<String> > GetDefaultStrings()
            {
                Array<Array<String> > a;
                a.SetCount(1);
                Array<String>& b = a[0];
                for (UInt32 i = 0; i < Matrix::NUM_COMPONENTS; i++)
                {
                    b.Add(Util::DoubleToString(DEFAULT().mValue.GetPointer()[i]));
                }
                return a;
            }
        };

        // MatrixFieldProperty
        template<UInt32 NUM_ELEMENTS>
        class MatrixFieldPropertyBase : public TypedMatrixFieldProperty<Real, NUM_ELEMENTS>
        {
        public:
            explicit MatrixFieldPropertyBase(const typename TypedMatrixFieldProperty<Real, NUM_ELEMENTS>::Value& v)
            : TypedMatrixFieldProperty<Real, NUM_ELEMENTS>(v)
            {
            }
        };

        template<UInt32 NUM_ELEMENTS, const typename MatrixFieldPropertyBase<NUM_ELEMENTS>::GetValueFunction DEFAULT>
        class MatrixFieldProperty : public MatrixFieldPropertyBase<NUM_ELEMENTS>
        {
        public:
            explicit MatrixFieldProperty()
            : MatrixFieldPropertyBase<NUM_ELEMENTS>(DEFAULT())
            {
            }
            void Reset()
            {
                for (UInt32 i = 0; i < NUM_ELEMENTS; i++)
                {
                    MatrixFieldPropertyBase<NUM_ELEMENTS>::mValue[i] = DEFAULT().mValue[i];
                }
            }
            static const PropertyInfo::Item* GetTypeInfo()
            {
                static PropertyInfo::Item p =
                {
                    DEFAULT().mId,
                    "Murl::Graph::Matrix",
                    IEnums::PROPERTY_SEMANTIC_VALUE,
                    Matrix::NUM_COMPONENTS,
                    NUM_ELEMENTS,
                    NUM_ELEMENTS,
                    0,
                    NUM_ELEMENTS,
                    GetDefaultStrings()
                };
                return &p;
            }
            static SInt32 GetId()
            {
                return DEFAULT().mId;
            }
            static Array<Array<String> > GetDefaultStrings()
            {
                Array<Array<String> > a;
                a.SetCount(NUM_ELEMENTS);
                for (UInt32 j = 0; j < NUM_ELEMENTS; j++)
                {
                    Array<String>& b = a[j];
                    for (UInt32 i = 0; i < Matrix::NUM_COMPONENTS; i++)
                    {
                        b.Add(Util::DoubleToString(DEFAULT().mValue[j].GetPointer()[i]));
                    }
                }
                return a;
            }
        };

        // MatrixArrayProperty
        template<UInt32 MIN_NUMBER_OF_ELEMENTS, UInt32 MAX_NUMBER_OF_ELEMENTS, UInt32 RESERVED_NUMBER_OF_ELEMENTS>
        class MatrixArrayPropertyBase : public TypedMatrixArrayProperty<Real, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>
        {
        public:
            explicit MatrixArrayPropertyBase(const typename TypedMatrixArrayProperty<Real, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::Value& v)
            : TypedMatrixArrayProperty<Real, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>(v)
            {
            }
        };

        template<UInt32 MIN_NUMBER_OF_ELEMENTS, UInt32 MAX_NUMBER_OF_ELEMENTS, UInt32 RESERVED_NUMBER_OF_ELEMENTS, const typename MatrixArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::GetValueFunction DEFAULT>
        class MatrixArrayProperty : public MatrixArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>
        {
        public:
            explicit MatrixArrayProperty()
            : MatrixArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>(DEFAULT())
            {
            }
            void Reset()
            {
                MatrixArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue.SetCount(RESERVED_NUMBER_OF_ELEMENTS);
                for (UInt32 i = 0; i < RESERVED_NUMBER_OF_ELEMENTS; i++)
                {
                    MatrixArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue[i] = DEFAULT().mValue[i];
                }
            }
            static const PropertyInfo::Item* GetTypeInfo()
            {
                static PropertyInfo::Item p =
                {
                    DEFAULT().mId,
                    "Murl::Graph::Matrix",
                    IEnums::PROPERTY_SEMANTIC_VALUE,
                    Math::Matrix<Real>::NUM_COMPONENTS,
                    MIN_NUMBER_OF_ELEMENTS,
                    MAX_NUMBER_OF_ELEMENTS,
                    MIN_NUMBER_OF_ELEMENTS,
                    MAX_NUMBER_OF_ELEMENTS,
                    GetDefaultStrings()
                };
                return &p;
            }
            static SInt32 GetId()
            {
                return DEFAULT().mId;
            }
            static Array<Array<String> > GetDefaultStrings()
            {
                Array<Array<String> > a;
                a.SetCount(MAX_NUMBER_OF_ELEMENTS);
                for (UInt32 j = 0; j < MAX_NUMBER_OF_ELEMENTS; j++)
                {
                    Array<String>& b = a[j];
                    for (UInt32 i = 0; i < Matrix::NUM_COMPONENTS; i++)
                    {
                        b.Add(Util::DoubleToString(DEFAULT().mValue[j].GetPointer()[i]));
                    }
                }
                return a;
            }
        };


        // ========== Color ==========

        // ColorProperty
        typedef TypedColorProperty ColorPropertyBase;

        template<const ColorPropertyBase::GetValueFunction DEFAULT>
        class ColorProperty : public ColorPropertyBase
        {
        public:
            explicit ColorProperty()
            : ColorPropertyBase(DEFAULT().mValue)
            {
            }
            void Reset()
            {
                ColorPropertyBase::mValue = DEFAULT().mValue;
            }
            Color& operator=(Color const& rhs)
            {
                ColorPropertyBase::mValue = rhs;
                return ColorPropertyBase::mValue;
            }
            static const PropertyInfo::Item* GetTypeInfo()
            {
                static PropertyInfo::Item p =
                {
                    DEFAULT().mId,
                    "Murl::Color",
                    IEnums::PROPERTY_SEMANTIC_VALUE,
                    1,
                    1,
                    1,
                    0,
                    1,
                    GetDefaultStrings()
                };
                return &p;
            }
            static SInt32 GetId()
            {
                return DEFAULT().mId;
            }
            static Array<Array<String> > GetDefaultStrings()
            {
                Array<Array<String> > a;
                a.SetCount(1);
                a[0].Add(DEFAULT().mValue.ToString());
                return a;
            }
        };

        // ColorFieldProperty
        template<UInt32 NUM_ELEMENTS>
        class ColorFieldPropertyBase : public TypedColorFieldProperty<NUM_ELEMENTS>
        {
        public:
            explicit ColorFieldPropertyBase(const typename TypedColorFieldProperty<NUM_ELEMENTS>::Value& v)
            : TypedColorFieldProperty<NUM_ELEMENTS>(v)
            {
            }
        };

        template<UInt32 NUM_ELEMENTS, const typename ColorFieldPropertyBase<NUM_ELEMENTS>::GetValueFunction DEFAULT>
        class ColorFieldProperty : public ColorFieldPropertyBase<NUM_ELEMENTS>
        {
        public:
            explicit ColorFieldProperty()
            : ColorFieldPropertyBase<NUM_ELEMENTS>(DEFAULT())
            {
            }
            void Reset()
            {
                for (UInt32 i = 0; i < NUM_ELEMENTS; i++)
                {
                    ColorFieldPropertyBase<NUM_ELEMENTS>::mValue[i] = DEFAULT().mValue[i];
                }
            }
            static const PropertyInfo::Item* GetTypeInfo()
            {
                static PropertyInfo::Item p =
                {
                    DEFAULT().mId,
                    "Murl::Color",
                    IEnums::PROPERTY_SEMANTIC_VALUE,
                    1,
                    NUM_ELEMENTS,
                    NUM_ELEMENTS,
                    0,
                    NUM_ELEMENTS,
                    GetDefaultStrings()
                };
                return &p;
            }
            static SInt32 GetId()
            {
                return DEFAULT().mId;
            }
            static Array<Array<String> > GetDefaultStrings()
            {
                Array<Array<String> > a;
                a.SetCount(NUM_ELEMENTS);
                for (UInt32 i = 0; i < NUM_ELEMENTS; i++)
                {
                    Array<String>& b = a[i];
                    b.Add(DEFAULT().mValue[i].ToString());
                }
                return a;
            }
        };

        // ColorArrayProperty
        template<UInt32 MIN_NUMBER_OF_ELEMENTS, UInt32 MAX_NUMBER_OF_ELEMENTS, UInt32 RESERVED_NUMBER_OF_ELEMENTS>
        class ColorArrayPropertyBase : public TypedColorArrayProperty<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>
        {
        public:
            explicit ColorArrayPropertyBase(const typename TypedColorArrayProperty<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::Value& v)
            : TypedColorArrayProperty<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>(v)
            {
            }
        };

        template<UInt32 MIN_NUMBER_OF_ELEMENTS, UInt32 MAX_NUMBER_OF_ELEMENTS, UInt32 RESERVED_NUMBER_OF_ELEMENTS, const typename ColorArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::GetValueFunction DEFAULT>
        class ColorArrayProperty : public ColorArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>
        {
        public:
            explicit ColorArrayProperty()
            : ColorArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>(DEFAULT())
            {
            }
            void Reset()
            {
                ColorArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue.SetCount(RESERVED_NUMBER_OF_ELEMENTS);
                for (UInt32 i = 0; i < RESERVED_NUMBER_OF_ELEMENTS; i++)
                {
                    ColorArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue[i] = DEFAULT().mValue[i];
                }
            }
            static const PropertyInfo::Item* GetTypeInfo()
            {
                static PropertyInfo::Item p =
                {
                    DEFAULT().mId,
                    "Murl::Color",
                    IEnums::PROPERTY_SEMANTIC_VALUE,
                    1,
                    MIN_NUMBER_OF_ELEMENTS,
                    MAX_NUMBER_OF_ELEMENTS,
                    MIN_NUMBER_OF_ELEMENTS,
                    MAX_NUMBER_OF_ELEMENTS,
                    GetDefaultStrings()
                };
                return &p;
            }
            static SInt32 GetId()
            {
                return DEFAULT().mId;
            }
            static Array<Array<String> > GetDefaultStrings()
            {
                Array<Array<String> > a;
                a.SetCount(MAX_NUMBER_OF_ELEMENTS);
                for (UInt32 i = 0; i < MAX_NUMBER_OF_ELEMENTS; i++)
                {
                    Array<String>& b = a[i];
                    b.Add(DEFAULT().mValue[i].ToString());
                }
                return a;
            }
        };


        // ========== String ==========

        // StringProperty
        typedef TypedStringProperty StringPropertyBase;

        template<const StringPropertyBase::GetValueFunction DEFAULT>
        class StringProperty : public StringPropertyBase
        {
        public:
            explicit StringProperty()
            : StringPropertyBase(DEFAULT().mValue)
            {
            }
            void Reset()
            {
                StringPropertyBase::mValue = DEFAULT().mValue;
            }
            String& operator=(String const& rhs)
            {
                StringPropertyBase::mValue = rhs;
                return StringPropertyBase::mValue;
            }
            static const PropertyInfo::Item* GetTypeInfo()
            {
                static PropertyInfo::Item p =
                {
                    DEFAULT().mId,
                    "Murl::String",
                    IEnums::PROPERTY_SEMANTIC_VALUE,
                    1,
                    1,
                    1,
                    0,
                    1,
                    GetDefaultStrings()
                };
                return &p;
            }
            static SInt32 GetId()
            {
                return DEFAULT().mId;
            }
            static Array<Array<String> > GetDefaultStrings()
            {
                Array<Array<String> > a;
                a.SetCount(1);
                a[0].Add(DEFAULT().mValue);
                return a;
            }
        };
        
        // StringFieldProperty
        template<UInt32 NUM_ELEMENTS>
        class StringFieldPropertyBase : public TypedStringFieldProperty<NUM_ELEMENTS>
        {
        public:
            explicit StringFieldPropertyBase(const typename TypedStringFieldProperty<NUM_ELEMENTS>::Value& v)
            : TypedStringFieldProperty<NUM_ELEMENTS>(v)
            {
            }
        };

        template<UInt32 NUM_ELEMENTS, const typename StringFieldPropertyBase<NUM_ELEMENTS>::GetValueFunction DEFAULT>
        class StringFieldProperty : public StringFieldPropertyBase<NUM_ELEMENTS>
        {
        public:
            explicit StringFieldProperty()
            : StringFieldPropertyBase<NUM_ELEMENTS>(DEFAULT())
            {
            }
            void Reset()
            {
                for (UInt32 i = 0; i < NUM_ELEMENTS; i++)
                {
                    StringFieldPropertyBase<NUM_ELEMENTS>::mValue[i] = DEFAULT().mValue[i];
                }
            }
            static const PropertyInfo::Item* GetTypeInfo()
            {
                static PropertyInfo::Item p =
                {
                    DEFAULT().mId,
                    "Murl::String",
                    IEnums::PROPERTY_SEMANTIC_VALUE,
                    1,
                    NUM_ELEMENTS,
                    NUM_ELEMENTS,
                    0,
                    NUM_ELEMENTS,
                    GetDefaultStrings()
                };
                return &p;
            }
            static SInt32 GetId()
            {
                return DEFAULT().mId;
            }
            static Array<Array<String> > GetDefaultStrings()
            {
                Array<Array<String> > a;
                a.SetCount(NUM_ELEMENTS);
                for (UInt32 i = 0; i < NUM_ELEMENTS; i++)
                {
                    Array<String>& b = a[i];
                    b.Add(DEFAULT().mValue[i]);
                }
                return a;
            }
        };

        // StringArrayProperty
        template<UInt32 MIN_NUMBER_OF_ELEMENTS, UInt32 MAX_NUMBER_OF_ELEMENTS, UInt32 RESERVED_NUMBER_OF_ELEMENTS>
        class StringArrayPropertyBase : public TypedStringArrayProperty<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>
        {
        public:
            explicit StringArrayPropertyBase(const typename TypedStringArrayProperty<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::Value& v)
            : TypedStringArrayProperty<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>(v)
            {
            }
        };

        template<UInt32 MIN_NUMBER_OF_ELEMENTS, UInt32 MAX_NUMBER_OF_ELEMENTS, UInt32 RESERVED_NUMBER_OF_ELEMENTS, const typename StringArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::GetValueFunction DEFAULT>
        class StringArrayProperty : public StringArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>
        {
        public:
            explicit StringArrayProperty()
            : StringArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>(DEFAULT())
            {
            }
            void Reset()
            {
                StringArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue.SetCount(RESERVED_NUMBER_OF_ELEMENTS);
                for (UInt32 i = 0; i < RESERVED_NUMBER_OF_ELEMENTS; i++)
                {
                    StringArrayPropertyBase<MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue[i] = DEFAULT().mValue[i];
                }
            }
            static const PropertyInfo::Item* GetTypeInfo()
            {
                static PropertyInfo::Item p =
                {
                    DEFAULT().mId,
                    "Murl::String",
                    IEnums::PROPERTY_SEMANTIC_VALUE,
                    1,
                    MIN_NUMBER_OF_ELEMENTS,
                    MAX_NUMBER_OF_ELEMENTS,
                    MIN_NUMBER_OF_ELEMENTS,
                    MAX_NUMBER_OF_ELEMENTS,
                    GetDefaultStrings()
                };
                return &p;
            }
            static SInt32 GetId()
            {
                return DEFAULT().mId;
            }
            static Array<Array<String> > GetDefaultStrings()
            {
                Array<Array<String> > a;
                a.SetCount(MAX_NUMBER_OF_ELEMENTS);
                for (UInt32 i = 0; i < MAX_NUMBER_OF_ELEMENTS; i++)
                {
                    Array<String>& b = a[i];
                    b.Add(DEFAULT().mValue[i]);
                }
                return a;
            }
        };


        // ========== ID ==========

        // IdProperty
        typedef TypedStringProperty IdPropertyBase;

        template<const IdPropertyBase::GetValueFunction DEFAULT>
        class IdProperty : public IdPropertyBase
        {
        public:
            explicit IdProperty()
            : IdPropertyBase(DEFAULT().mValue)
            {
            }
            void Reset()
            {
                IdPropertyBase::mValue = DEFAULT().mValue;
            }
            String& operator=(String const& rhs)
            {
                IdPropertyBase::mValue = rhs;
                return IdPropertyBase::mValue;
            }
            static const PropertyInfo::Item* GetTypeInfo()
            {
                static PropertyInfo::Item p =
                {
                    DEFAULT().mId,
                    "Murl::String",
                    IEnums::PROPERTY_SEMANTIC_ID,
                    1,
                    1,
                    1,
                    0,
                    1,
                    GetDefaultStrings()
                };
                return &p;
            }
            static SInt32 GetId()
            {
                return DEFAULT().mId;
            }
            static Array<Array<String> > GetDefaultStrings()
            {
                Array<Array<String> > a;
                a.SetCount(1);
                a[0].Add(DEFAULT().mValue);
                return a;
            }
        };
        

        // ========== Enum ==========

        // EnumProperty
        template<class EnumType>
        class EnumPropertyBase : public TypedEnumProperty<EnumType>
        {
        public:
            struct Value
            {
                UInt32 mId;
                EnumType mValue;
            };

            typedef const Value& (*GetValueFunction)();

        public:
            explicit EnumPropertyBase(EnumType value)
            : mValue(value)
            {
            }
            explicit EnumPropertyBase(const Value& v)
            : mValue(v.mValue)
            {
            }

            static const PropertyInfo::Item* GetTypeInfo()
            {
                static const PropertyInfo::Item ti = { TypedEnumProperty<EnumType>::GetTypeName(), IEnums::PROPERTY_SEMANTIC_VALUE, 1, 1, 0, 1 };
                return &ti;
            }

            Bool DeserializeEnumValue(IDeserializeAttributeTracker* tracker)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                tracker->GetAttributeEnumValue(TypedEnumProperty<EnumType>::GetEnum(), mValue);
                return true;
            }

            EnumType& operator=(EnumType const& rhs)
            {
                mValue = rhs;
                return mValue;
            }

            EnumType Get() const
            {
                return mValue;
            }

            operator const EnumType&() const
            {
                return mValue;
            }
            operator EnumType&()
            {
                return mValue;
            }

            EnumType mValue;
        };

        template<class EnumType, const typename EnumPropertyBase<EnumType>::GetValueFunction DEFAULT>
        class EnumProperty : public EnumPropertyBase<EnumType>
        {
        public:
            explicit EnumProperty()
            : EnumPropertyBase<EnumType>(DEFAULT().mValue)
            {
            }
            void Reset()
            {
                EnumPropertyBase<EnumType>::mValue = DEFAULT().mValue;
            }
            EnumType& operator=(EnumType const& rhs)
            {
                EnumPropertyBase<EnumType>::mValue = rhs;
                return EnumPropertyBase<EnumType>::mValue;
            }
            static const PropertyInfo::Item* GetTypeInfo()
            {
                static PropertyInfo::Item p =
                {
                    DEFAULT().mId,
                    TypedEnumProperty<EnumType>::GetTypeName(),
                    IEnums::PROPERTY_SEMANTIC_VALUE,
                    1,
                    1,
                    1,
                    0,
                    1,
                    GetDefaultStrings(),
                    &TypedEnumProperty<EnumType>::GetSInt32Enum()
                };
                return &p;
            }
            static SInt32 GetId()
            {
                return DEFAULT().mId;
            }
            static Array<Array<String> > GetDefaultStrings()
            {
                Array<Array<String> > a;
                a.SetCount(1);
                String s = TypedEnumProperty<EnumType>::GetEnum().GetEnumNameByValue(DEFAULT().mValue);
                a[0].Add(s);
                return a;
            }
        };

        // EnumFieldProperty
        template<class EnumType, UInt32 NUM_ELEMENTS>
        class EnumFieldPropertyBase : public TypedEnumProperty<EnumType>
        {
        public:
            struct Value
            {
                UInt32 mId;
                EnumType mValue[NUM_ELEMENTS];
            };

            typedef const Value& (*GetValueFunction)();

        public:
            explicit EnumFieldPropertyBase(const Value& v)
            {
                for (UInt32 i = 0; i < NUM_ELEMENTS; i++)
                {
                    mValue[i] = v.mValue[i];
                }
            }

            Bool DeserializeEnumValues(IDeserializeAttributeTracker* tracker)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                tracker->GetAttributeEnumValues(TypedEnumProperty<EnumType>::GetEnum(), mValue, NUM_ELEMENTS);
                return true;
            }
            Bool DeserializeEnumValues(IDeserializeAttributeTracker* tracker, UInt32 numElements)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                if (numElements > NUM_ELEMENTS)
                {
                    return false;
                }
                tracker->GetAttributeEnumValues(TypedEnumProperty<EnumType>::GetEnum(), mValue, numElements);
                return true;
            }
            Bool DeserializeEnumValue(IDeserializeAttributeTracker* tracker, UInt32 index)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                if (index >= NUM_ELEMENTS)
                {
                    return false;
                }
                tracker->GetAttributeEnumValue(TypedEnumProperty<EnumType>::GetEnum(), mValue[index]);
                return true;
            }
            Bool DeserializeBaseIndexEnumValue(IDeserializeAttributeTracker* tracker)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                UInt32 index;
                if (!Util::StringToUInt32(tracker->GetBaseAttributeName(), index))
                {
                    return false;
                }
                if (index >= NUM_ELEMENTS)
                {
                    return false;
                }
                tracker->GetAttributeEnumValue(TypedEnumProperty<EnumType>::GetEnum(), mValue[index]);
                return true;
            }

            EnumType& operator[](SInt32 index)
            {
                return mValue[index];
            }
            const EnumType& operator[](SInt32 index) const
            {
                return mValue[index];
            }

            EnumType* operator&()
            {
                return mValue;
            }
            const EnumType* operator&() const
            {
                return mValue;
            }

            EnumType& operator*()
            {
                return mValue[0];
            }
            const EnumType& operator*() const
            {
                return mValue[0];
            }

            UInt32 GetCount() const
            {
                return NUM_ELEMENTS;
            }

            EnumType mValue[NUM_ELEMENTS];
        };

        template<class EnumType, UInt32 NUM_ELEMENTS, const typename EnumFieldPropertyBase<EnumType, NUM_ELEMENTS>::GetValueFunction DEFAULT>
        class EnumFieldProperty : public EnumFieldPropertyBase<EnumType, NUM_ELEMENTS>
        {
        public:
            explicit EnumFieldProperty()
            : EnumFieldPropertyBase<EnumType, NUM_ELEMENTS>(DEFAULT())
            {
            }
            void Reset()
            {
                Util::MemCopy(EnumFieldPropertyBase<EnumType, NUM_ELEMENTS>::mValue, DEFAULT().mValue, sizeof(DEFAULT().mValue));
            }
            static const PropertyInfo::Item* GetTypeInfo()
            {
                static PropertyInfo::Item p =
                {
                    DEFAULT().mId,
                    TypedEnumProperty<EnumType>::GetTypeName(),
                    IEnums::PROPERTY_SEMANTIC_VALUE,
                    1,
                    NUM_ELEMENTS,
                    NUM_ELEMENTS,
                    0,
                    NUM_ELEMENTS,
                    GetDefaultStrings(),
                    &EnumFieldPropertyBase<EnumType, NUM_ELEMENTS>::GetSInt32Enum()
                };
                return &p;
            }
            static SInt32 GetId()
            {
                return DEFAULT().mId;
            }
            static Array<Array<String> > GetDefaultStrings()
            {
                Array<Array<String> > a;
                a.SetCount(NUM_ELEMENTS);
                for (UInt32 i = 0; i < NUM_ELEMENTS; i++)
                {
                    Array<String>& b = a[i];
                    String s = TypedEnumProperty<EnumType>::GetEnum().GetEnumNameByValue(DEFAULT().mValue[i]);
                    b.Add(s);
                }
                return a;
            }
        };
        
        // EnumArrayProperty
        template<class EnumType, UInt32 MIN_NUMBER_OF_ELEMENTS, UInt32 MAX_NUMBER_OF_ELEMENTS, UInt32 RESERVED_NUMBER_OF_ELEMENTS>
        class EnumArrayPropertyBase : public TypedEnumProperty<EnumType>
        {
        public:
            struct Value
            {
                UInt32 mId;
                EnumType mValue[MAX_NUMBER_OF_ELEMENTS];
            };

            typedef const Value& (*GetValueFunction)();

        public:
            explicit EnumArrayPropertyBase(const Value& v)
            {
                if (RESERVED_NUMBER_OF_ELEMENTS > 0)
                {
                    mValue.SetCount(RESERVED_NUMBER_OF_ELEMENTS);
                    for (UInt32 i = 0; i < RESERVED_NUMBER_OF_ELEMENTS; i++)
                    {
                        mValue[i] = v.mValue[i];
                    }
                }
            }

            Bool DeserializeEnumValues(IDeserializeAttributeTracker* tracker)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                tracker->GetAttributeEnumValues(TypedEnumProperty<EnumType>::GetEnum(), mValue);
                return true;
            }
            Bool DeserializeEnumValue(IDeserializeAttributeTracker* tracker, UInt32 index)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                if (index >= mValue.GetCount())
                {
                    mValue.SetCount(index + 1, TypedEnumProperty<EnumType>::GetEnum().GetDefaultValue());
                }
                tracker->GetAttributeEnumValue(TypedEnumProperty<EnumType>::GetEnum(), mValue[index]);
                return true;
            }
            Bool DeserializeBaseIndexEnumValue(IDeserializeAttributeTracker* tracker)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                UInt32 index;
                if (!Util::StringToUInt32(tracker->GetBaseAttributeName(), index))
                {
                    return false;
                }
                if (index >= MAX_NUMBER_OF_ELEMENTS)
                {
                    return false;
                }
                if (index >= mValue.GetCount())
                {
                    mValue.SetCount(index + 1, TypedEnumProperty<EnumType>::GetEnum().GetDefaultValue());
                }
                tracker->GetAttributeEnumValue(TypedEnumProperty<EnumType>::GetEnum(), mValue[index]);
                return true;
            }

            EnumType& operator[](SInt32 index)
            {
                return mValue[index];
            }
            const EnumType& operator[](SInt32 index) const
            {
                return mValue[index];
            }

            EnumType* operator&()
            {
                return mValue;
            }
            const EnumType* operator&() const
            {
                return mValue;
            }

            EnumType& operator*()
            {
                return mValue[0];
            }
            const EnumType& operator*() const
            {
                return mValue[0];
            }

            UInt32 GetCount() const
            {
                return mValue.GetCount();
            }

            Array<EnumType> mValue;
        };

        template<class EnumType, UInt32 MIN_NUMBER_OF_ELEMENTS, UInt32 MAX_NUMBER_OF_ELEMENTS, UInt32 RESERVED_NUMBER_OF_ELEMENTS, const typename EnumArrayPropertyBase<EnumType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::GetValueFunction DEFAULT>
        class EnumArrayProperty : public EnumArrayPropertyBase<EnumType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>
        {
        public:
            explicit EnumArrayProperty()
            : EnumArrayPropertyBase<EnumType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>(DEFAULT())
            {
            }
            void Reset()
            {
                EnumArrayPropertyBase<EnumType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue.SetCount(RESERVED_NUMBER_OF_ELEMENTS);
                for (UInt32 i = 0; i < RESERVED_NUMBER_OF_ELEMENTS; i++)
                {
                    EnumArrayPropertyBase<EnumType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue[i] = DEFAULT().mValue[i];
                }

            }
            static const PropertyInfo::Item* GetTypeInfo()
            {
                static PropertyInfo::Item p =
                {
                    DEFAULT().mId,
                    TypedEnumProperty<EnumType>::GetTypeName(),
                    IEnums::PROPERTY_SEMANTIC_VALUE,
                    1,
                    MIN_NUMBER_OF_ELEMENTS,
                    MAX_NUMBER_OF_ELEMENTS,
                    MIN_NUMBER_OF_ELEMENTS,
                    MAX_NUMBER_OF_ELEMENTS,
                    GetDefaultStrings(),
                    &EnumArrayPropertyBase<EnumType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::GetSInt32Enum()
                };
                return &p;
            }
            static SInt32 GetId()
            {
                return DEFAULT().mId;
            }
            static Array<Array<String> > GetDefaultStrings()
            {
                Array<Array<String> > a;
                a.SetCount(MAX_NUMBER_OF_ELEMENTS);
                for (UInt32 i = 0; i < MAX_NUMBER_OF_ELEMENTS; i++)
                {
                    Array<String>& b = a[i];
                    String s = TypedEnumProperty<EnumType>::GetEnum().GetEnumNameByValue(DEFAULT().mValue[i]);
                    b.Add(s);
                }
                return a;
            }
        };
        
        
        // ========== EnumMask ==========

        // EnumMaskProperty
        template<class EnumType>
        class EnumMaskPropertyBase : public TypedEnumProperty<EnumType>
        {
        public:
            struct Value
            {
                UInt32 mId;
                UInt32 mValue;
            };

            typedef const Value& (*GetValueFunction)();

        public:
            explicit EnumMaskPropertyBase(UInt32 value)
            : mValue(value)
            {
            }
            explicit EnumMaskPropertyBase(const Value& v)
            : mValue(v.mValue)
            {
            }

            static const PropertyInfo::Item* GetTypeInfo()
            {
                static const PropertyInfo::Item ti = { TypedEnumProperty<EnumType>::GetTypeName(), IEnums::PROPERTY_SEMANTIC_VALUE, 1, 1, 0, 1 };
                return &ti;
            }

            Bool DeserializeEnumBitsToSet(IDeserializeAttributeTracker* tracker)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                tracker->GetAttributeEnumBitsToSet(TypedEnumProperty<EnumType>::GetEnum(), mValue);
                return true;
            }

            UInt32& operator=(UInt32 rhs)
            {
                mValue = rhs;
                return mValue;
            }

            operator UInt32&()
            {
                return mValue;
            }
            operator const UInt32&() const
            {
                return mValue;
            }

            UInt32& operator*()
            {
                return mValue;
            }
            const UInt32& operator*() const
            {
                return mValue;
            }

            UInt32 mValue;
        };

        template<class EnumType, const typename EnumMaskPropertyBase<EnumType>::GetValueFunction DEFAULT>
        class EnumMaskProperty : public EnumMaskPropertyBase<EnumType>
        {
        public:
            explicit EnumMaskProperty()
            : EnumMaskPropertyBase<EnumType>(DEFAULT().mValue)
            {
            }
            void Reset()
            {
                EnumMaskPropertyBase<EnumType>::mValue = DEFAULT().mValue;
            }
            UInt32& operator=(UInt32 const& rhs)
            {
                EnumMaskPropertyBase<EnumType>::mValue = rhs;
                return EnumMaskPropertyBase<EnumType>::mValue;
            }
            static const PropertyInfo::Item* GetTypeInfo()
            {
                static PropertyInfo::Item p =
                {
                    DEFAULT().mId,
                    TypedEnumProperty<EnumType>::GetTypeName(),
                    IEnums::PROPERTY_SEMANTIC_MASK,
                    1,
                    1,
                    1,
                    0,
                    1,
                    GetDefaultStrings(),
                    &EnumMaskPropertyBase<EnumType>::GetSInt32Enum()
                };
                return &p;
            }
            static SInt32 GetId()
            {
                return DEFAULT().mId;
            }
            static Array<Array<String> > GetDefaultStrings()
            {
                Array<Array<String> > a;
                a.SetCount(1);
                a[0].Add(Util::UInt32ToString(DEFAULT().mValue));
                return a;
            }
        };

        // EnumMaskFieldProperty
        template<class EnumType, UInt32 NUM_ELEMENTS>
        class EnumMaskFieldPropertyBase : public TypedEnumProperty<EnumType>
        {
        public:
            enum
            {
                ELEMENT_SELECTED = UInt32(-2),
            };

            struct Value
            {
                UInt32 mId;
                EnumType mValue[NUM_ELEMENTS];
            };

            typedef const Value& (*GetValueFunction)();

        public:
            explicit EnumMaskFieldPropertyBase(UInt32 clearValue)
            {
                for (UInt32 i = 0; i < NUM_ELEMENTS; i++)
                {
                    mValue[i] = clearValue;
                }
            }
            explicit EnumMaskFieldPropertyBase(const Value& v)
            {
                for (UInt32 i = 0; i < NUM_ELEMENTS; i++)
                {
                    mValue[i] = v.mValue[i];
                }
            }

            Bool DeserializeEnumBitsToSet(IDeserializeAttributeTracker* tracker, UInt32 index)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                if (index >= NUM_ELEMENTS)
                {
                    return false;
                }
                tracker->GetAttributeEnumBitsToSet(TypedEnumProperty<EnumType>::GetEnum(), mValue[index]);
                return true;
            }

            Bool DeserializeBaseIndexEnumBitsToSet(IDeserializeAttributeTracker* tracker)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                UInt32 index;
                if (!Util::StringToUInt32(tracker->GetBaseAttributeName(), index))
                {
                    return false;
                }
                if (index >= NUM_ELEMENTS)
                {
                    return false;
                }
                tracker->GetAttributeEnumBitsToSet(TypedEnumProperty<EnumType>::GetEnum(), mValue[index]);
                return true;
            }

            UInt32& operator[](SInt32 index)
            {
                return mValue[index];
            }
            const UInt32& operator[](SInt32 index) const
            {
                return mValue[index];
            }

            UInt32& operator*()
            {
                return mValue[0];
            }
            const UInt32& operator*() const
            {
                return mValue[0];
            }

            UInt32 GetCount() const
            {
                return NUM_ELEMENTS;
            }

            UInt32 mValue[NUM_ELEMENTS];
        };

        template<class EnumType, UInt32 NUM_ELEMENTS, const typename EnumMaskFieldPropertyBase<EnumType, NUM_ELEMENTS>::GetValueFunction DEFAULT>
        class EnumMaskFieldProperty : public EnumMaskFieldPropertyBase<EnumType, NUM_ELEMENTS>
        {
        public:
            explicit EnumMaskFieldProperty()
            : EnumMaskFieldPropertyBase<EnumType, NUM_ELEMENTS>(DEFAULT())
            {
            }
            void Reset()
            {
                Util::MemCopy(EnumMaskFieldPropertyBase<EnumType, NUM_ELEMENTS>::mValue, DEFAULT().mValue, sizeof(DEFAULT().mValue));
            }
            static const PropertyInfo::Item* GetTypeInfo()
            {
                static PropertyInfo::Item p =
                {
                    DEFAULT().mId,
                    TypedEnumProperty<EnumType>::GetTypeName(),
                    IEnums::PROPERTY_SEMANTIC_MASK,
                    1,
                    NUM_ELEMENTS,
                    NUM_ELEMENTS,
                    0,
                    NUM_ELEMENTS,
                    GetDefaultStrings()
                };
                return &p;
            }
            static SInt32 GetId()
            {
                return DEFAULT().mId;
            }
            static Array<Array<String> > GetDefaultStrings()
            {
                Array<Array<String> > a;
                a.SetCount(NUM_ELEMENTS);
                for (UInt32 i = 0; i < NUM_ELEMENTS; i++)
                {
                    Array<String>& b = a[i];
                    b.Add(Util::UInt32ToString(DEFAULT().mValue[i]));
                }
                return a;
            }
        };

        // EnumMaskArrayProperty
        template<class EnumType, UInt32 MIN_NUMBER_OF_ELEMENTS, UInt32 MAX_NUMBER_OF_ELEMENTS, UInt32 RESERVED_NUMBER_OF_ELEMENTS>
        class EnumMaskArrayPropertyBase : public TypedEnumProperty<EnumType>
        {
        public:
            enum
            {
                ELEMENT_SELECTED = UInt32(-2),
            };

            struct Value
            {
                UInt32 mId;
                EnumType mValue[MAX_NUMBER_OF_ELEMENTS];
            };

            typedef const Value& (*GetValueFunction)();

        public:
            explicit EnumMaskArrayPropertyBase(const Value& v)
            {
                if (RESERVED_NUMBER_OF_ELEMENTS > 0)
                {
                    mValue.SetCount(RESERVED_NUMBER_OF_ELEMENTS);
                    for (UInt32 i = 0; i < RESERVED_NUMBER_OF_ELEMENTS; i++)
                    {
                        mValue[i] = v.mValue[i];
                    }
                }
            }

            Bool DeserializeEnumBitsToSet(IDeserializeAttributeTracker* tracker, UInt32 index)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                if (index >= MAX_NUMBER_OF_ELEMENTS)
                {
                    return false;
                }
                if (index >= mValue.GetCount())
                {
                    mValue.SetCount(index + 1, 0);
                }
                tracker->GetAttributeEnumBitsToSet(TypedEnumProperty<EnumType>::GetEnum(), mValue[index]);
                return true;
            }

            Bool DeserializeBaseIndexEnumBitsToSet(IDeserializeAttributeTracker* tracker)
            {
                if (!tracker->HasAttributeValue())
                {
                    return true;
                }
                UInt32 index;
                if (!Util::StringToUInt32(tracker->GetBaseAttributeName(), index))
                {
                    return false;
                }
                if (index >= MAX_NUMBER_OF_ELEMENTS)
                {
                    return false;
                }
                if (index >= mValue.GetCount())
                {
                    mValue.SetCount(index + 1, 0);
                }
                tracker->GetAttributeEnumBitsToSet(TypedEnumProperty<EnumType>::GetEnum(), mValue[index]);
                return true;
            }

            UInt32& operator[](SInt32 index)
            {
                return mValue[index];
            }
            const UInt32& operator[](SInt32 index) const
            {
                return mValue[index];
            }

            UInt32& operator*()
            {
                return mValue[0];
            }
            const UInt32& operator*() const
            {
                return mValue[0];
            }

            UInt32 GetCount() const
            {
                return mValue.GetCount();
            }

            Array<UInt32> mValue;
        };

        template<class EnumType, UInt32 MIN_NUMBER_OF_ELEMENTS, UInt32 MAX_NUMBER_OF_ELEMENTS, UInt32 RESERVED_NUMBER_OF_ELEMENTS, const typename EnumMaskArrayPropertyBase<EnumType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::GetValueFunction DEFAULT>
        class EnumMaskArrayProperty : public EnumMaskArrayPropertyBase<EnumType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>
        {
        public:
            explicit EnumMaskArrayProperty()
            : EnumMaskArrayPropertyBase<EnumType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>(DEFAULT())
            {
            }
            void Reset()
            {
                EnumMaskArrayPropertyBase<EnumType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue.SetCount(RESERVED_NUMBER_OF_ELEMENTS);
                for (UInt32 i = 0; i < RESERVED_NUMBER_OF_ELEMENTS; i++)
                {
                    EnumMaskArrayPropertyBase<EnumType, MIN_NUMBER_OF_ELEMENTS, MAX_NUMBER_OF_ELEMENTS, RESERVED_NUMBER_OF_ELEMENTS>::mValue[i] = DEFAULT().mValue[i];
                }
            }
            static const PropertyInfo::Item* GetTypeInfo()
            {
                static PropertyInfo::Item p =
                {
                    DEFAULT().mId,
                    TypedEnumProperty<EnumType>::GetTypeName(),
                    IEnums::PROPERTY_SEMANTIC_MASK,
                    1,
                    MIN_NUMBER_OF_ELEMENTS,
                    MAX_NUMBER_OF_ELEMENTS,
                    MIN_NUMBER_OF_ELEMENTS,
                    MAX_NUMBER_OF_ELEMENTS,
                    GetDefaultStrings()
                };
                return &p;
            }
            static SInt32 GetId()
            {
                return DEFAULT().mId;
            }
            static Array<Array<String> > GetDefaultStrings()
            {
                Array<Array<String> > a;
                a.SetCount(MAX_NUMBER_OF_ELEMENTS);
                for (UInt32 i = 0; i < MAX_NUMBER_OF_ELEMENTS; i++)
                {
                    Array<String>& b = a[i];
                    b.Add(Util::UInt32ToString(DEFAULT().mValue[i]));
                }
                return a;
            }
        };
        

    }
}

#endif // __MURL_GRAPH_PROPERTY_H__
