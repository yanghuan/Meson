#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Boolean)
FORWARDS(Char)
FORWARDS(Int32)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
FORWARDS(UInt16)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
namespace OrdinalCasingNamespace {
class OrdinalCasing {
  public: static Char ToUpper(Char c);
  public: static Char ToUpperInvariantMode(Char c);
  public: static void ToUpperInvariantMode(ReadOnlySpan<Char> source, Span<Char> destination);
  public: static void ToUpperOrdinal(ReadOnlySpan<Char> source, Span<Char> destination);
  public: static void ToUpperSurrogate(UInt16 h, UInt16 l, UInt16& hr, UInt16& lr);
  private: static Boolean EqualSurrogate(Char h1, Char l1, Char h2, Char l2);
  public: static Int32 CompareStringIgnoreCase(Char& strA, Int32 lengthA, Char& strB, Int32 lengthB);
  public: static Int32 IndexOf(ReadOnlySpan<Char> source, ReadOnlySpan<Char> value);
  public: static Int32 LastIndexOf(ReadOnlySpan<Char> source, ReadOnlySpan<Char> value);
  private: static Array<UInt16> InitOrdinalCasingPage(Int32 pageNumber);
  public: static void cctor();
  private: static Array<UInt16> s_noCasingPage;
  private: static Array<UInt16> s_basicLatin;
  private: static Array<Array<UInt16>> s_casingTable;
};
} // namespace OrdinalCasingNamespace
using OrdinalCasing = OrdinalCasingNamespace::OrdinalCasing;
} // namespace System::Private::CoreLib::System::Globalization
