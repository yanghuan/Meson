#include "AnsiCharMarshaler-dep.h"

namespace System::Private::CoreLib::System::StubHelpers::AnsiCharMarshalerNamespace {
Array<Byte> AnsiCharMarshaler::DoAnsiConversion(String str, Boolean fBestFit, Boolean fThrowOnUnmappableChar, Int32& cbLength) {
  return Array<Byte>();
};

Byte AnsiCharMarshaler::ConvertToNative(Char managedChar, Boolean fBestFit, Boolean fThrowOnUnmappableChar) {
  return Byte();
};

Char AnsiCharMarshaler::ConvertToManaged(Byte nativeChar) {
  return Char();
};

} // namespace System::Private::CoreLib::System::StubHelpers::AnsiCharMarshalerNamespace
