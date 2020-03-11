// Copyright 2010-2015 Spraylight

#ifndef __MURL_TYPES_H__
#define __MURL_TYPES_H__

#include "murl_defines.h"

/**
 * @ingroup MurlNamespaces
 * @brief The %Murl Engine main namespace.
 */
namespace Murl
{
    // Forward declarations
    class String;

    template<class DataType>
    class Array;

    template<class DataType>
    class AutoPointer;

    template<class DataType>
    class SharedPointer;

    template<class DataType, class HashFunc>
    class Index;

    template<class DataType>
    class Queue;

    template<class DataType>
    class StdHash;

    typedef float ResourceReal;  // Resources always use single-precision floats
    typedef float InputReal;
    typedef float OutputReal;

    // Emscripten
#ifdef MURL_COMPILER_EMCC

    typedef unsigned char       MurlUInt8;
    typedef signed   char       MurlSInt8;
    typedef unsigned short      MurlUInt16;
    typedef signed   short      MurlSInt16;
    typedef unsigned int        MurlUInt32;
    typedef signed   int        MurlSInt32;
    typedef unsigned long long  MurlUInt64;
    typedef signed   long long  MurlSInt64;

    typedef float AppReal;
    typedef float AudioReal;
    typedef float VideoReal;  // Note for OpenGL ES 2.0: No double data type available
    typedef float PhysicsReal;
    typedef float GraphReal;
    typedef float LogicReal;
    typedef float MurlReal;
    typedef float CoreReal;

#endif
    
    // Visual Studio
#ifdef MURL_COMPILER_VS

    typedef unsigned char       MurlUInt8;
    typedef signed   char       MurlSInt8;
    typedef unsigned short      MurlUInt16;
    typedef signed   short      MurlSInt16;
    typedef unsigned int        MurlUInt32;
    typedef signed   int        MurlSInt32;
    typedef unsigned __int64    MurlUInt64;
    typedef signed   __int64    MurlSInt64;

    typedef float AppReal;
    typedef float AudioReal;
    typedef float VideoReal;  // Note for OpenGL ES 2.0: No double data type available
    typedef float PhysicsReal;
    typedef float GraphReal;
    typedef float LogicReal;
    typedef float MurlReal;
    typedef float CoreReal;

#endif

    // GNU Compiler specific
#ifdef MURL_COMPILER_GCC

    typedef unsigned char       MurlUInt8;
    typedef signed   char       MurlSInt8;
    typedef unsigned short      MurlUInt16;
    typedef signed   short      MurlSInt16;
    typedef unsigned int        MurlUInt32;
    typedef signed   int        MurlSInt32;
    typedef unsigned long long  MurlUInt64;
    typedef signed   long long  MurlSInt64;

    typedef float AppReal;
    typedef float AudioReal;
    typedef float VideoReal;  // Note for OpenGL ES 2.0: No double data type available
    typedef float PhysicsReal;
    typedef float GraphReal;
    typedef float LogicReal;
    typedef float MurlReal;
    typedef float CoreReal;

#endif

    /**
     * @addtogroup MurlTypes
     * @brief The global types should be used to ensure multi-platform compatibility.
     * @{
     */

    /**
     * @brief Unsigned 8 bit integer data type
     */
    typedef MurlUInt8 UInt8;
    /**
     * @brief Signed 8 bit integer data type
     */
    typedef MurlSInt8 SInt8;
    /**
     * @brief Unsigned 16 bit integer data type
     */
    typedef MurlUInt16 UInt16;
    /**
     * @brief Signed 16 bit integer data type
     */
    typedef MurlSInt16 SInt16;
    /**
     * @brief Unsigned 32 bit integer data type
     */
    typedef MurlUInt32 UInt32;
    /**
     * @brief Signed 32 bit integer data type
     */
    typedef MurlSInt32 SInt32;
    /**
     * @brief Unsigned 64 bit integer data type
     */
    typedef MurlUInt64 UInt64;
    /**
     * @brief Signed 64 bit integer data type
     */
    typedef MurlSInt64 SInt64;

    /**
     * @brief Boolean data type
     * This typedef represents a boolean value (true or false). When specified
     * as an attribute value in an XML file, the following values are accepted
     * (case insensitive):
     * - "true", "on", "yes", "1" or any integer not equal to zero for true.
     * - "false", "off", "no" or "0" for false.
     */
    typedef bool Bool;

    /**
     * @brief Character data type
     */
    typedef char Char;

    /**
     * @brief Wide-Character data type
     */
    typedef wchar_t WChar;

    /**
     * @brief Explicit 32bit IEEE floating point data type
     */
    typedef float Float;
    /**
     * @brief Explicit 64bit IEEE floating point data type
     */
    typedef double Double;

    /**
     * @brief Generic floating point data type.
     * This data type is defined in a platform-specific way, to either 32 bit or 64 bit
     * floating point types.
     */
    typedef MurlReal Real;

    /**
     * @brief An unsigned integer data type which can hold a pointer.
     */
    typedef uintptr_t UIntPtr;

    /**
     * @brief String index container, with default hashing function.
     */
    typedef Index<String, StdHash<String> > StringIndex;

    /**
     * @brief UInt8 index container, with default hashing function.
     */
    typedef Index<UInt8, StdHash<UInt8> > UInt8Index;
    /**
     * @brief SInt8 index container, with default hashing function.
     */
    typedef Index<SInt8, StdHash<SInt8> > SInt8Index;
    /**
     * @brief UInt16 index container, with default hashing function.
     */
    typedef Index<UInt16, StdHash<UInt16> > UInt16Index;
    /**
     * @brief SInt16 index container, with default hashing function.
     */
    typedef Index<SInt16, StdHash<SInt16> > SInt16Index;
    /**
     * @brief UInt32 index container, with default hashing function.
     */
    typedef Index<UInt32, StdHash<UInt32> > UInt32Index;
    /**
     * @brief SInt32 index container, with default hashing function.
     */
    typedef Index<SInt32, StdHash<SInt32> > SInt32Index;
    /**
     * @brief UInt64 index container, with default hashing function.
     */
    typedef Index<UInt64, StdHash<UInt64> > UInt64Index;
    /**
     * @brief SInt64 index container, with default hashing function.
     */
    typedef Index<SInt64, StdHash<SInt64> > SInt64Index;

    /**
     * @brief Real index container, with default hashing function.
     */
    typedef Index<Real, StdHash<Real> > RealIndex;
    /**
     * @brief Float index container, with default hashing function.
     */
    typedef Index<Float, StdHash<Float> > FloatIndex;
    /**
     * @brief Double index container, with default hashing function.
     */
    typedef Index<Double, StdHash<Double> > DoubleIndex;

    /**
     * @brief A string array.
     */
    typedef Array<String> StringArray;
    /**
     * @brief A wide-character array.
     */
    typedef Array<WChar> WCharArray;

    /**
     * @brief An unsigned 8 bit integer array.
     */
    typedef Array<UInt8> UInt8Array;
    /**
     * @brief A signed 8 bit integer array.
     */
    typedef Array<SInt8> SInt8Array;
    /**
     * @brief An unsigned 16 bit integer array.
     */
    typedef Array<UInt16> UInt16Array;
    /**
     * @brief A signed 16 bit integer array.
     */
    typedef Array<SInt16> SInt16Array;
    /**
     * @brief An unsigned 32 bit integer array.
     */
    typedef Array<UInt32> UInt32Array;
    /**
     * @brief A signed 32 bit integer array.
     */
    typedef Array<SInt32> SInt32Array;
    /**
     * @brief An unsigned 64 bit integer array.
     */
    typedef Array<UInt64> UInt64Array;
    /**
     * @brief A signed 64 bit integer array.
     */
    typedef Array<SInt64> SInt64Array;

    /**
     * @brief Generic floating point array.
     * This data type is defined in a platform-specific way, to either 32 bit or 64 bit
     * floating point types.
     */
    typedef Array<Real> RealArray;
    /**
     * @brief Explicit 32bit IEEE floating point array.
     */
    typedef Array<Float> FloatArray;
    /**
     * @brief Explicit 64bit IEEE floating point array.
     */
    typedef Array<Double> DoubleArray;

    /**
     * @brief An array of boolean values.
     */
    typedef Array<Bool> BoolArray;

    /**
     * @brief A string queue.
     */
    typedef Queue<String> StringQueue;

    /**
     * @brief An unsigned 8 bit integer queue.
     */
    typedef Queue<UInt8> UInt8Queue;
    /**
     * @brief A signed 8 bit integer queue.
     */
    typedef Queue<SInt8> SInt8Queue;
    /**
     * @brief An unsigned 16 bit integer queue.
     */
    typedef Queue<UInt16> UInt16Queue;
    /**
     * @brief A signed 16 bit integer queue.
     */
    typedef Queue<SInt16> SInt16Queue;
    /**
     * @brief An unsigned 32 bit integer queue.
     */
    typedef Queue<UInt32> UInt32Queue;
    /**
     * @brief A signed 32 bit integer queue.
     */
    typedef Queue<SInt32> SInt32Queue;
    /**
     * @brief An unsigned 64 bit integer queue.
     */
    typedef Queue<UInt64> UInt64Queue;
    /**
     * @brief A signed 64 bit integer queue.
     */
    typedef Queue<SInt64> SInt64Queue;

    /**
     * @brief Generic floating point queue.
     * This data type is defined in a platform-specific way, to either 32 bit or 64 bit
     * floating point types.
     */
    typedef Queue<Real> RealQueue;
    /**
     * @brief Explicit 32bit IEEE floating point queue.
     */
    typedef Queue<Float> FloatQueue;
    /**
     * @brief Explicit 64bit IEEE floating point queue.
     */
    typedef Queue<Double> DoubleQueue;

    /**
     * @brief A queue of boolean values.
     */
    typedef Queue<Bool> BoolQueue;

    /**
     * @brief An array of AutoPointer<AutoPointerType> objects.
     * Usage:
     * @code
     *  typedef AutoPointerArray<MyClass>::Type MyClassArray;
     * @endcode
     */
    template<class AutoPointerType>
    struct AutoPointerArray
    {
        typedef Array<AutoPointer<AutoPointerType> > Type;
    };

    /**
     * @brief An array of SharedPointer<SharedPointerType> objects.
     * Usage:
     * @code
     *  typedef SharedPointerArray<MyClass>::Type MyClassArray;
     * @endcode
     */
    template<class SharedPointerType>
    struct SharedPointerArray
    {
        typedef Array<SharedPointer<SharedPointerType> > Type;
    };

    /**
     * @brief A base class for implementing non-copyable objects.
     * Declares a private copy constructor and assignment operator.
     */
    class NonCopyable
    {
    public:
        /** The default constructor. */
        NonCopyable()
        {
        }

    private:
        NonCopyable(const NonCopyable&);
        void operator=(const NonCopyable&);
    };

    /** @} */
}

#endif  // __MURL_TYPES_H__
