#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARDS(ReadOnlySpan, T)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::Uri::System {
namespace IPv4AddressHelperNamespace {
using namespace ::System::Private::CoreLib::System;
class IPv4AddressHelper : public Object::in {
  public: static String ParseCanonicalName(String str, Int32 start, Int32 end, Boolean& isLoopback);
  private: static Boolean Parse(String name, Byte* numbers, Int32 start, Int32 end);
  public: static Int32 ParseHostNumber(ReadOnlySpan<Char> str, Int32 start, Int32 end);
  public: static Boolean IsValid(Char* name, Int32 start, Int32& end, Boolean allowIPv6, Boolean notImplicitFile, Boolean unknownScheme);
  private: static Boolean ParseCanonical(ReadOnlySpan<Char> name, Byte* numbers, Int32 start, Int32 end);
  public: static Boolean IsValidCanonical(Char* name, Int32 start, Int32& end, Boolean allowIPv6, Boolean notImplicitFile);
  public: static Int64 ParseNonCanonical(Char* name, Int32 start, Int32& end, Boolean notImplicitFile);
};
} // namespace IPv4AddressHelperNamespace
using IPv4AddressHelper = IPv4AddressHelperNamespace::IPv4AddressHelper;
} // namespace System::Private::Uri::System
