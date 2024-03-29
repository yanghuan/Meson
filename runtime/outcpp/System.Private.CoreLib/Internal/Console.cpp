#include "Console-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/Microsoft/Win32/SafeHandles/SafeFileHandle-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/Text/Encoding-dep.h>

namespace System::Private::CoreLib::Internal::ConsoleNamespace {
using namespace Microsoft::Win32::SafeHandles;
using namespace System;
using namespace System::Text;

void Console::Write(String s) {
  Array<Byte> bytes = Encoding::in::get_UTF8()->GetBytes(s);
  {
    Byte* bytes2 = rt::fixed(bytes);
    Int32 numBytesWritten;
    Interop::Kernel32::WriteFile(_outputHandle, bytes2, bytes->get_Length(), numBytesWritten, IntPtr::Zero);
  }
}

void Console::WriteLine(String s) {
  Write(s + "\r\n");
}

void Console::WriteLine() {
  Write("\r\n");
}

void Console::cctor() {
  _outputHandle = rt::newobj<SafeFileHandle>(Interop::Kernel32::GetStdHandle(-11), false);
}

} // namespace System::Private::CoreLib::Internal::ConsoleNamespace
