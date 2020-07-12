#include "IPv6AddressHelper-dep.h"

namespace System::Private::Uri::System::IPv6AddressHelperNamespace {
String IPv6AddressHelper::ParseCanonicalName(String str, Int32 start, Boolean& isLoopback, String& scopeId) {
  return nullptr;
};

Boolean IPv6AddressHelper::IsLoopback(ReadOnlySpan<UInt16> numbers) {
  return Boolean();
};

Boolean IPv6AddressHelper::InternalIsValid(Char* name, Int32 start, Int32& end, Boolean validateStrictAddress) {
  return Boolean();
};

Boolean IPv6AddressHelper::IsValid(Char* name, Int32 start, Int32& end) {
  return Boolean();
};

ValueTuple<> IPv6AddressHelper::FindCompressionRange(ReadOnlySpan<UInt16> numbers) {
  return ValueTuple<>();
};

Boolean IPv6AddressHelper::ShouldHaveIpv4Embedded(ReadOnlySpan<UInt16> numbers) {
  return Boolean();
};

void IPv6AddressHelper::Parse(ReadOnlySpan<Char> address, Span<UInt16> numbers, Int32 start, String& scopeId) {
};

} // namespace System::Private::Uri::System::IPv6AddressHelperNamespace
