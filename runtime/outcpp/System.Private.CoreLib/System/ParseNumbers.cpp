#include "ParseNumbers-dep.h"

namespace System::Private::CoreLib::System::ParseNumbersNamespace {
Int64 ParseNumbers::StringToLong(ReadOnlySpan<Char> s, Int32 radix, Int32 flags) {
  return Int64();
};

Int64 ParseNumbers::StringToLong(ReadOnlySpan<Char> s, Int32 radix, Int32 flags, Int32& currPos) {
  return Int64();
};

Int32 ParseNumbers::StringToInt(ReadOnlySpan<Char> s, Int32 radix, Int32 flags) {
  return Int32();
};

Int32 ParseNumbers::StringToInt(ReadOnlySpan<Char> s, Int32 radix, Int32 flags, Int32& currPos) {
  return Int32();
};

String ParseNumbers::IntToString(Int32 n, Int32 radix, Int32 width, Char paddingChar, Int32 flags) {
  return nullptr;
};

String ParseNumbers::LongToString(Int64 n, Int32 radix, Int32 width, Char paddingChar, Int32 flags) {
  return nullptr;
};

void ParseNumbers::EatWhiteSpace(ReadOnlySpan<Char> s, Int32& i) {
};

Int64 ParseNumbers::GrabLongs(Int32 radix, ReadOnlySpan<Char> s, Int32& i, Boolean isUnsigned) {
  return Int64();
};

Int32 ParseNumbers::GrabInts(Int32 radix, ReadOnlySpan<Char> s, Int32& i, Boolean isUnsigned) {
  return Int32();
};

Boolean ParseNumbers::IsDigit(Char c, Int32 radix, Int32& result) {
  return Boolean();
};

} // namespace System::Private::CoreLib::System::ParseNumbersNamespace
