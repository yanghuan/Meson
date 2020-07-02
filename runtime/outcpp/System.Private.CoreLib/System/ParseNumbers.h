#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(ReadOnlySpan, T)
FORWARDS(Char)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARD(String)
FORWARDS(Boolean)
namespace ParseNumbersNamespace {
class ParseNumbers {
  public: static Int64 StringToLong(ReadOnlySpan<Char> s, Int32 radix, Int32 flags);
  public: static Int64 StringToLong(ReadOnlySpan<Char> s, Int32 radix, Int32 flags, Int32& currPos);
  public: static Int32 StringToInt(ReadOnlySpan<Char> s, Int32 radix, Int32 flags);
  public: static Int32 StringToInt(ReadOnlySpan<Char> s, Int32 radix, Int32 flags, Int32& currPos);
  public: static String IntToString(Int32 n, Int32 radix, Int32 width, Char paddingChar, Int32 flags);
  public: static String LongToString(Int64 n, Int32 radix, Int32 width, Char paddingChar, Int32 flags);
  private: static void EatWhiteSpace(ReadOnlySpan<Char> s, Int32& i);
  private: static Int64 GrabLongs(Int32 radix, ReadOnlySpan<Char> s, Int32& i, Boolean isUnsigned);
  private: static Int32 GrabInts(Int32 radix, ReadOnlySpan<Char> s, Int32& i, Boolean isUnsigned);
  private: static Boolean IsDigit(Char c, Int32 radix, Int32& result);
};
} // namespace ParseNumbersNamespace
using ParseNumbers = ParseNumbersNamespace::ParseNumbers;
} // namespace System::Private::CoreLib::System
