#include "Interop-dep.h"

#include <System.Console/Interop-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>

namespace System::Console::InteropNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Runtime::InteropServices;

Int32 Interop::Kernel32::GetLeadByteRanges(Int32 codePage, Array<Byte> leadByteRanges) {
  Int32 num = 0;
  CPINFOEXW cPINFOEXW;
  if (GetCPInfoExW((UInt32)codePage, 0u, &cPINFOEXW) != 0) {
    for (Int32 i = 0; i < 10 && leadByteRanges[i] != 0; i += 2) {
      leadByteRanges[i] = cPINFOEXW.LeadByte[i];
      leadByteRanges[i + 1] = cPINFOEXW.LeadByte[i + 1];
      num++;
    }
  }
  return num;
}

String Interop::Kernel32::GetMessage(Int32 errorCode) {
  return GetMessage(errorCode, IntPtr::Zero);
}

String Interop::Kernel32::GetMessage(Int32 errorCode, IntPtr moduleHandle) {
  Int32 num = 12800;
  if (moduleHandle != IntPtr::Zero) {
    num |= 2048;
  }
  Char default[256] = {};
  Span<Char> span = default;
  {
    Char* lpBuffer = span;
    Int32 num2 = FormatMessage(num, moduleHandle, (UInt32)errorCode, 0, lpBuffer, span.get_Length(), IntPtr::Zero);
    if (num2 > 0) {
      return GetAndTrimString(span.Slice(0, num2));
    }
  }
  if (Marshal::GetLastWin32Error() == 122) {
    IntPtr intPtr = IntPtr();
    try{
      Int32 num3 = FormatMessage(num | 256, moduleHandle, (UInt32)errorCode, 0, &intPtr, 0, IntPtr::Zero);
      if (num3 > 0) {
        return GetAndTrimString(Span<Char>((void*)intPtr, num3));
      }
    } finally: {
      Marshal::FreeHGlobal(intPtr);
    }
  }
  return String::in::Format("Unknown error (0x{0:x})", errorCode);
}

String Interop::Kernel32::GetAndTrimString(Span<Char> buffer) {
  Int32 num = buffer.get_Length();
  while (num > 0 && buffer[num - 1] <= 32) {
    num--;
  }
  return buffer.Slice(0, num).ToString();
}

Boolean Interop::Kernel32::IsGetConsoleModeCallSuccessful(IntPtr handle) {
  Int32 mode;
  return GetConsoleMode(handle, mode);
}

} // namespace System::Console::InteropNamespace
