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
FORWARDS(Int32)
FORWARDS(Byte)
FORWARDS(UInt64)
FORWARDS(IntPtr)
FORWARDS(Boolean)
FORWARDS(UIntPtr)
FORWARDS(Char)
FORWARDS(UInt16)
FORWARDS(Int64)
namespace SpanHelpersNamespace {
using namespace ::System::Private::CoreLib::System::Numerics;
using namespace ::System::Private::CoreLib::System::Runtime::Intrinsics;
class SpanHelpers {
  public: template <class T, class TComparer>
  struct ComparerComparable {
    public: Int32 CompareTo(T other);
    private: T _value;
    private: TComparer _comparer;
  };
  public: static void ClearWithoutReferences(Byte& b, UInt64 byteLength);
  public: static void ClearWithReferences(IntPtr& ip, UInt64 pointerSizeLength);
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
  public: static Boolean SequenceEqual(Byte& first, Byte& second, UInt64 length);
  private: static Int32 LocateFirstFoundByte(Vector<Byte> match);
  public: static Int32 SequenceCompareTo(Byte& first, Int32 firstLength, Byte& second, Int32 secondLength);
  private: static Int32 LocateLastFoundByte(Vector<Byte> match);
  private: static Int32 LocateFirstFoundByte(UInt64 match);
  private: static Int32 LocateLastFoundByte(UInt64 match);
  private: static UIntPtr LoadUIntPtr(Byte& start, IntPtr offset);
  private: static Vector<Byte> LoadVector(Byte& start, IntPtr offset);
  private: static Vector128<Byte> LoadVector128(Byte& start, IntPtr offset);
  private: static Vector256<Byte> LoadVector256(Byte& start, IntPtr offset);
  private: static IntPtr GetByteVectorSpanLength(IntPtr offset, Int32 length);
  private: static IntPtr GetByteVector128SpanLength(IntPtr offset, Int32 length);
  private: static IntPtr GetByteVector256SpanLength(IntPtr offset, Int32 length);
  private: static IntPtr UnalignedCountVector(Byte& searchSpace);
  private: static IntPtr UnalignedCountVector128(Byte& searchSpace);
  private: static IntPtr UnalignedCountVectorFromEnd(Byte& searchSpace, Int32 length);
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
  private: static Vector<UInt16> LoadVector(Char& start, Int64 offset);
  private: static Vector128<UInt16> LoadVector128(Char& start, Int64 offset);
  private: static Vector256<UInt16> LoadVector256(Char& start, Int64 offset);
  private: static Int64 GetCharVectorSpanLength(Int64 offset, Int64 length);
  private: static Int64 GetCharVector128SpanLength(Int64 offset, Int64 length);
  private: static Int64 GetCharVector256SpanLength(Int64 offset, Int64 length);
  private: static Int64 UnalignedCountVector(Char& searchSpace);
  private: static Int64 UnalignedCountVector128(Char& searchSpace);
};
} // namespace SpanHelpersNamespace
using SpanHelpers = SpanHelpersNamespace::SpanHelpers;
} // namespace System::Private::CoreLib::System
