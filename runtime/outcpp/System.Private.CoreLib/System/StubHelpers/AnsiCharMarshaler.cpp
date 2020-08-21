#include "AnsiCharMarshaler-dep.h"

#include <System.Private.CoreLib/System/ReadOnlySpan-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>
#include <System.Private.CoreLib/System/Text/Encoding-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::StubHelpers::AnsiCharMarshalerNamespace {
using namespace System::Runtime::InteropServices;
using namespace System::Text;

Array<Byte> AnsiCharMarshaler::DoAnsiConversion(String str, Boolean fBestFit, Boolean fThrowOnUnmappableChar, Int32& cbLength) {
  Array<Byte> array = rt::newarr<Array<Byte>>((str->get_Length() + 1) * Marshal::SystemMaxDBCSCharSize);
  {
    Byte* buffer = &array[0];
    cbLength = Marshal::StringToAnsiString(str, buffer, array->get_Length(), fBestFit, fThrowOnUnmappableChar);
  }
  return array;
}

Byte AnsiCharMarshaler::ConvertToNative(Char managedChar, Boolean fBestFit, Boolean fThrowOnUnmappableChar) {
  Int32 num = 2 * Marshal::SystemMaxDBCSCharSize;
  Byte as[(Int32)(UInt32)num] = {};
  Byte* ptr = as;
  Int32 num2 = Marshal::StringToAnsiString(managedChar.ToString(), ptr, num, fBestFit, fThrowOnUnmappableChar);
  return *ptr;
}

Char AnsiCharMarshaler::ConvertToManaged(Byte nativeChar) {
  ReadOnlySpan<Byte> bytes = ReadOnlySpan<Byte>(nativeChar, 1);
  String string = Encoding::in::get_Default()->GetString(bytes);
  return string[0];
}

} // namespace System::Private::CoreLib::System::StubHelpers::AnsiCharMarshalerNamespace
