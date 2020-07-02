#include "HStringMarshaler-dep.h"

namespace System::Private::CoreLib::System::StubHelpers::HStringMarshalerNamespace {
IntPtr HStringMarshaler::ConvertToNative(String managed) {
  return IntPtr();
};
IntPtr HStringMarshaler::ConvertToNativeReference(String managed, HSTRING_HEADER* hstringHeader) {
  return IntPtr();
};
String HStringMarshaler::ConvertToManaged(IntPtr hstring) {
  return nullptr;
};
void HStringMarshaler::ClearNative(IntPtr hstring) {
  return void();
};
} // namespace System::Private::CoreLib::System::StubHelpers::HStringMarshalerNamespace
