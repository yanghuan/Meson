#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Numerics {
FORWARDS_(Vector, T1, T2)
} // namespace System::Private::CoreLib::System::Numerics
namespace System::Private::CoreLib::System::Runtime::Intrinsics {
FORWARDS_(Vector128, T1, T2)
FORWARDS_(Vector256, T1, T2)
} // namespace System::Private::CoreLib::System::Runtime::Intrinsics
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARDS(ReadOnlySpan, T)
FORWARDS(UInt16)
FORWARDS(UInt32)
FORWARDS(UInt64)
FORWARDS(UIntPtr)
namespace SpanHelpersNamespace {
using namespace Numerics;
using namespace Runtime::Intrinsics;
class SpanHelpers {
  public: template <class T, class TComparer>
  struct ComparerComparable {
    public: explicit ComparerComparable(T value, TComparer comparer);
    public: Int32 CompareTo(T other);
    public: explicit ComparerComparable() {}
    private: T _value;
    private: TComparer _comparer;
  };
  public: template <class T, class TComparable>
  static Int32 BinarySearch(ReadOnlySpan<T> span, TComparable comparable);
  public: template <class T, class TComparable>
  static Int32 BinarySearch(T& spanStart, Int32 length, TComparable comparable);
  public: static Int32 IndexOf(Byte& searchSpace, Int32 searchSpaceLength, Byte& value, Int32 valueLength);
  public: static Int32 IndexOfAny(Byte& searchSpace, Int32 searchSpaceLength, Byte& value, Int32 valueLength);
  public: static Int32 LastIndexOfAny(Byte& searchSpace, Int32 searchSpaceLength, Byte& value, Int32 valueLength);
  public: static Boolean Contains(Byte& searchSpace, Byte value, Int32 length);
  public: static Int32 IndexOf(Byte& searchSpace, Byte value, Int32 length);
  public: static Int32 LastIndexOf(Byte& searchSpace, Int32 searchSpaceLength, Byte& value, Int32 valueLength);
  public: static Int32 LastIndexOf(Byte& searchSpace, Byte value, Int32 length);
  public: static Int32 IndexOfAny(Byte& searchSpace, Byte value0, Byte value1, Int32 length);
  public: static Int32 IndexOfAny(Byte& searchSpace, Byte value0, Byte value1, Byte value2, Int32 length);
  public: static Int32 LastIndexOfAny(Byte& searchSpace, Byte value0, Byte value1, Int32 length);
  public: static Int32 LastIndexOfAny(Byte& searchSpace, Byte value0, Byte value1, Byte value2, Int32 length);
  public: static Boolean SequenceEqual(Byte& first, Byte& second, UIntPtr length);
  private: static Int32 LocateFirstFoundByte(Vector<Byte> match);
  public: static Int32 SequenceCompareTo(Byte& first, Int32 firstLength, Byte& second, Int32 secondLength);
  private: static Int32 LocateLastFoundByte(Vector<Byte> match);
  private: static Int32 LocateFirstFoundByte(UInt64 match);
  private: static Int32 LocateLastFoundByte(UInt64 match);
  private: static UInt16 LoadUShort(Byte& start);
  private: static UInt32 LoadUInt(Byte& start);
  private: static UInt32 LoadUInt(Byte& start, UIntPtr offset);
  private: static UIntPtr LoadNUInt(Byte& start);
  private: static UIntPtr LoadNUInt(Byte& start, UIntPtr offset);
  private: static Vector<Byte> LoadVector(Byte& start, UIntPtr offset);
  private: static Vector128<Byte> LoadVector128(Byte& start, UIntPtr offset);
  private: static Vector256<Byte> LoadVector256(Byte& start, UIntPtr offset);
  private: static UIntPtr GetByteVectorSpanLength(UIntPtr offset, Int32 length);
  private: static UIntPtr GetByteVector128SpanLength(UIntPtr offset, Int32 length);
  private: static UIntPtr GetByteVector256SpanLength(UIntPtr offset, Int32 length);
  private: static UIntPtr UnalignedCountVector(Byte& searchSpace);
  private: static UIntPtr UnalignedCountVector128(Byte& searchSpace);
  private: static UIntPtr UnalignedCountVectorFromEnd(Byte& searchSpace, Int32 length);
  public: static Int32 IndexOf(Char& searchSpace, Int32 searchSpaceLength, Char& value, Int32 valueLength);
  public: static Int32 SequenceCompareTo(Char& first, Int32 firstLength, Char& second, Int32 secondLength);
  public: static Boolean Contains(Char& searchSpace, Char value, Int32 length);
  public: static Int32 IndexOf(Char& searchSpace, Char value, Int32 length);
  public: static Int32 IndexOfAny(Char& searchSpace, Char value0, Char value1, Int32 length);
  public: static Int32 IndexOfAny(Char& searchSpace, Char value0, Char value1, Char value2, Int32 length);
  public: static Int32 IndexOfAny(Char& searchSpace, Char value0, Char value1, Char value2, Char value3, Int32 length);
  public: static Int32 IndexOfAny(Char& searchSpace, Char value0, Char value1, Char value2, Char value3, Char value4, Int32 length);
  public: static Int32 LastIndexOf(Char& searchSpace, Char value, Int32 length);
  private: static Int32 LocateFirstFoundChar(Vector<UInt16> match);
  private: static Int32 LocateFirstFoundChar(UInt64 match);
  private: static Int32 LocateLastFoundChar(Vector<UInt16> match);
  private: static Int32 LocateLastFoundChar(UInt64 match);
  private: static Vector<UInt16> LoadVector(Char& start, IntPtr offset);
  private: static Vector128<UInt16> LoadVector128(Char& start, IntPtr offset);
  private: static Vector256<UInt16> LoadVector256(Char& start, IntPtr offset);
  private: static IntPtr GetCharVectorSpanLength(IntPtr offset, IntPtr length);
  private: static IntPtr GetCharVector128SpanLength(IntPtr offset, IntPtr length);
  private: static IntPtr GetCharVector256SpanLength(IntPtr offset, IntPtr length);
  private: static IntPtr UnalignedCountVector(Char& searchSpace);
  private: static IntPtr UnalignedCountVector128(Char& searchSpace);
  public: static void ClearWithoutReferences(Byte& b, UIntPtr byteLength);
  public: static void ClearWithReferences(IntPtr& ip, UIntPtr pointerSizeLength);
  public: template <class T>
  static Int32 IndexOf(T& searchSpace, Int32 searchSpaceLength, T& value, Int32 valueLength);
  public: template <class T>
  static Boolean Contains(T& searchSpace, T value, Int32 length);
  public: template <class T>
  static Int32 IndexOf(T& searchSpace, T value, Int32 length);
  public: template <class T>
  static Int32 IndexOfAny(T& searchSpace, T value0, T value1, Int32 length);
  public: template <class T>
  static Int32 IndexOfAny(T& searchSpace, T value0, T value1, T value2, Int32 length);
  public: template <class T>
  static Int32 IndexOfAny(T& searchSpace, Int32 searchSpaceLength, T& value, Int32 valueLength);
  public: template <class T>
  static Int32 LastIndexOf(T& searchSpace, Int32 searchSpaceLength, T& value, Int32 valueLength);
  public: template <class T>
  static Int32 LastIndexOf(T& searchSpace, T value, Int32 length);
  public: template <class T>
  static Int32 LastIndexOfAny(T& searchSpace, T value0, T value1, Int32 length);
  public: template <class T>
  static Int32 LastIndexOfAny(T& searchSpace, T value0, T value1, T value2, Int32 length);
  public: template <class T>
  static Int32 LastIndexOfAny(T& searchSpace, Int32 searchSpaceLength, T& value, Int32 valueLength);
  public: template <class T>
  static Boolean SequenceEqual(T& first, T& second, Int32 length);
  public: template <class T>
  static Int32 SequenceCompareTo(T& first, Int32 firstLength, T& second, Int32 secondLength);
};
} // namespace SpanHelpersNamespace
using SpanHelpers = SpanHelpersNamespace::SpanHelpers;
} // namespace System::Private::CoreLib::System
