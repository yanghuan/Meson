#include "Interop-dep.h"

namespace System::Console::InteropNamespace {
Int32 Interop::Kernel32::GetLeadByteRanges(Int32 codePage, Array<Byte> leadByteRanges) {
  return Int32();
};
String Interop::Kernel32::GetMessage(Int32 errorCode) {
  return nullptr;
};
String Interop::Kernel32::GetMessage(Int32 errorCode, IntPtr moduleHandle) {
  return nullptr;
};
String Interop::Kernel32::GetAndTrimString(Span<Char> buffer) {
  return nullptr;
};
Boolean Interop::Kernel32::IsGetConsoleModeCallSuccessful(IntPtr handle) {
  return Boolean();
};
} // namespace System::Console::InteropNamespace
