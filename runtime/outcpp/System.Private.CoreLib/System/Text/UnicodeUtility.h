#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Char)
FORWARDS(Int32)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
namespace UnicodeUtilityNamespace {
class UnicodeUtility : public Object::in {
  public: static Int32 GetPlane(UInt32 codePoint);
  public: static UInt32 GetScalarFromUtf16SurrogatePair(UInt32 highSurrogateCodePoint, UInt32 lowSurrogateCodePoint);
  public: static Int32 GetUtf16SequenceLength(UInt32 value);
  public: static void GetUtf16SurrogatesFromSupplementaryPlaneScalar(UInt32 value, Char& highSurrogateCodePoint, Char& lowSurrogateCodePoint);
  public: static Int32 GetUtf8SequenceLength(UInt32 value);
  public: static Boolean IsAsciiCodePoint(UInt32 value);
  public: static Boolean IsBmpCodePoint(UInt32 value);
  public: static Boolean IsHighSurrogateCodePoint(UInt32 value);
  public: static Boolean IsInRangeInclusive(UInt32 value, UInt32 lowerBound, UInt32 upperBound);
  public: static Boolean IsLowSurrogateCodePoint(UInt32 value);
  public: static Boolean IsSurrogateCodePoint(UInt32 value);
  public: static Boolean IsValidCodePoint(UInt32 codePoint);
  public: static Boolean IsValidUnicodeScalar(UInt32 value);
};
} // namespace UnicodeUtilityNamespace
using UnicodeUtility = UnicodeUtilityNamespace::UnicodeUtility;
} // namespace System::Private::CoreLib::System::Text
