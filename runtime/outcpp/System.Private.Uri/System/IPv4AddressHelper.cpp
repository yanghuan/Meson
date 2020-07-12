#include "IPv4AddressHelper-dep.h"

namespace System::Private::Uri::System::IPv4AddressHelperNamespace {
String IPv4AddressHelper::ParseCanonicalName(String str, Int32 start, Int32 end, Boolean& isLoopback) {
  return nullptr;
};

Boolean IPv4AddressHelper::Parse(String name, Byte* numbers, Int32 start, Int32 end) {
  return Boolean();
};

Int32 IPv4AddressHelper::ParseHostNumber(ReadOnlySpan<Char> str, Int32 start, Int32 end) {
  return Int32();
};

Boolean IPv4AddressHelper::IsValid(Char* name, Int32 start, Int32& end, Boolean allowIPv6, Boolean notImplicitFile, Boolean unknownScheme) {
  return Boolean();
};

Boolean IPv4AddressHelper::ParseCanonical(ReadOnlySpan<Char> name, Byte* numbers, Int32 start, Int32 end) {
  return Boolean();
};

Boolean IPv4AddressHelper::IsValidCanonical(Char* name, Int32 start, Int32& end, Boolean allowIPv6, Boolean notImplicitFile) {
  return Boolean();
};

Int64 IPv4AddressHelper::ParseNonCanonical(Char* name, Int32 start, Int32& end, Boolean notImplicitFile) {
  return Int64();
};

} // namespace System::Private::Uri::System::IPv4AddressHelperNamespace
