#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Char)
FORWARDS(Int32)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
FORWARD(String)
FORWARDS(UInt16)
FORWARDS_(ValueTuple)
} // namespace System::Private::CoreLib::System
namespace System::Private::Uri::System {
namespace IPv6AddressHelperNamespace {
using namespace ::System::Private::CoreLib::System;
class IPv6AddressHelper {
  public: static String ParseCanonicalName(String str, Int32 start, Boolean& isLoopback, String& scopeId);
  private: static Boolean IsLoopback(ReadOnlySpan<UInt16> numbers);
  private: static Boolean InternalIsValid(Char* name, Int32 start, Int32& end, Boolean validateStrictAddress);
  public: static Boolean IsValid(Char* name, Int32 start, Int32& end);
  public: static ValueTuple<Int32, Int32> FindCompressionRange(ReadOnlySpan<UInt16> numbers);
  public: static Boolean ShouldHaveIpv4Embedded(ReadOnlySpan<UInt16> numbers);
  public: static void Parse(ReadOnlySpan<Char> address, Span<UInt16> numbers, Int32 start, String& scopeId);
};
} // namespace IPv6AddressHelperNamespace
using IPv6AddressHelper = IPv6AddressHelperNamespace::IPv6AddressHelper;
} // namespace System::Private::Uri::System
