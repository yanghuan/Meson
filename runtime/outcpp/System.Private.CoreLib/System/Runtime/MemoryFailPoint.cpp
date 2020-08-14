#include "MemoryFailPoint-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/Double-dep.h>
#include <System.Private.CoreLib/System/Environment-dep.h>
#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/InsufficientMemoryException-dep.h>
#include <System.Private.CoreLib/System/IO/Win32Marshal-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/Runtime/MemoryFailPoint-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>
#include <System.Private.CoreLib/System/Threading/Volatile-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/UIntPtr-dep.h>

namespace System::Private::CoreLib::System::Runtime::MemoryFailPointNamespace {
using namespace System::IO;
using namespace System::Threading;

Int64 MemoryFailPoint___::get_LastKnownFreeAddressSpace() {
  return Volatile::Read(s_hiddenLastKnownFreeAddressSpace);
}

void MemoryFailPoint___::set_LastKnownFreeAddressSpace(Int64 value) {
  Volatile::Write(s_hiddenLastKnownFreeAddressSpace, value);
}

Int64 MemoryFailPoint___::get_LastTimeCheckingAddressSpace() {
  return Volatile::Read(s_hiddenLastTimeCheckingAddressSpace);
}

void MemoryFailPoint___::set_LastTimeCheckingAddressSpace(Int64 value) {
  Volatile::Write(s_hiddenLastTimeCheckingAddressSpace, value);
}

UInt64 MemoryFailPoint___::get_MemoryFailPointReservedMemory() {
  return (UInt64)Volatile::Read(s_failPointReservedMemory);
}

void MemoryFailPoint___::AddToLastKnownFreeAddressSpace(Int64 addend) {
  Interlocked::Add(s_hiddenLastKnownFreeAddressSpace, addend);
}

void MemoryFailPoint___::ctor(Int32 sizeInMegabytes) {
  if (sizeInMegabytes <= 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("sizeInMegabytes", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  UInt64 num = _reservedMemory = (UInt64)((Int64)sizeInMegabytes << 20);
  UInt64 num2 = (UInt64)(Math::Ceiling((Double)num / (Double)s_GCSegmentSize) * (Double)s_GCSegmentSize);
  if (num2 >= s_topOfMemory) {
    rt::throw_exception<InsufficientMemoryException>(SR::get_InsufficientMemory_MemFailPoint_TooBig());
  }
  UInt64 num3 = (UInt64)(Math::Ceiling((Double)sizeInMegabytes / 16) * 16);
  num3 <<= 20;
  for (Int32 i = 0; i < 3; i++) {
    UInt64 availPageFile;
    UInt64 totalAddressSpaceFree;
    if (!CheckForAvailableMemory(availPageFile, totalAddressSpaceFree)) {
      return;
    }
    UInt64 memoryFailPointReservedMemory = get_MemoryFailPointReservedMemory();
    UInt64 num4 = num2 + memoryFailPointReservedMemory;
    Boolean flag = num4 < num2 || num4 < memoryFailPointReservedMemory;
    Boolean flag2 = availPageFile < num3 + memoryFailPointReservedMemory + 16777216 || flag;
    Boolean flag3 = totalAddressSpaceFree < num4 || flag;
    Int64 num5 = Environment::get_TickCount();
    if (num5 > get_LastTimeCheckingAddressSpace() + 10000 || num5 < get_LastTimeCheckingAddressSpace() || get_LastKnownFreeAddressSpace() < (Int64)num2) {
      CheckForFreeAddressSpace(num2, false);
    }
    Boolean flag4 = (UInt64)get_LastKnownFreeAddressSpace() < num2;
    if (!flag2 && !flag3 && !flag4) {
      break;
    }
    switch (i.get()) {
      case 0:
        GC::Collect();
        break;
      case 1:
        if (flag2) {
          UIntPtr numBytes = UIntPtr(num2);
          GrowPageFileIfNecessaryAndPossible(numBytes);
        }
        break;
      case 2:
        if (flag2 || flag3) {
          InsufficientMemoryException ex = rt::newobj<InsufficientMemoryException>(SR::get_InsufficientMemory_MemFailPoint());
          rt::throw_exception(ex);
        }
        if (flag4) {
          InsufficientMemoryException ex2 = rt::newobj<InsufficientMemoryException>(SR::get_InsufficientMemory_MemFailPoint_VAFrag());
          rt::throw_exception(ex2);
        }
        break;
    }
  }
  AddToLastKnownFreeAddressSpace((Int64)(0 - num));
  if (get_LastKnownFreeAddressSpace() < 0) {
    CheckForFreeAddressSpace(num2, true);
  }
  AddMemoryFailPointReservation((Int64)num);
  _mustSubtractReservation = true;
}

void MemoryFailPoint___::Finalize() {
  Dispose(false);
}

void MemoryFailPoint___::Dispose() {
  Dispose(true);
  GC::SuppressFinalize((MemoryFailPoint)this);
}

void MemoryFailPoint___::Dispose(Boolean disposing) {
  if (_mustSubtractReservation) {
    AddMemoryFailPointReservation((Int64)(0 - _reservedMemory));
    _mustSubtractReservation = false;
  }
}

Int64 MemoryFailPoint___::AddMemoryFailPointReservation(Int64 size) {
  return Interlocked::Add(s_failPointReservedMemory, size);
}

UInt64 MemoryFailPoint___::GetTopOfMemory() {
  Interop::Kernel32::SYSTEM_INFO lpSystemInfo;
  Interop::Kernel32::GetSystemInfo(lpSystemInfo);
  return (UInt64)(Int64)lpSystemInfo.lpMaximumApplicationAddress;
}

Boolean MemoryFailPoint___::CheckForAvailableMemory(UInt64& availPageFile, UInt64& totalAddressSpaceFree) {
  Interop::Kernel32::MEMORYSTATUSEX lpBuffer = Interop::Kernel32::MEMORYSTATUSEX();
  lpBuffer.dwLength = (UInt32)sizeof(Interop::Kernel32::MEMORYSTATUSEX);
  if (!Interop::Kernel32::GlobalMemoryStatusEx(lpBuffer)) {
    availPageFile = 0;
    totalAddressSpaceFree = 0;
    return false;
  }
  availPageFile = lpBuffer.ullAvailPageFile;
  totalAddressSpaceFree = lpBuffer.ullAvailVirtual;
  return true;
}

void MemoryFailPoint___::CheckForFreeAddressSpace(UInt64 size, Boolean shouldThrow) {
  UInt64 num2 = (UInt64)(get_LastKnownFreeAddressSpace() = (Int64)MemFreeAfterAddress(nullptr, size));
  get_LastTimeCheckingAddressSpace() = Environment::get_TickCount();
  if (num2 < size && shouldThrow) {
    rt::throw_exception<InsufficientMemoryException>(SR::get_InsufficientMemory_MemFailPoint_VAFrag());
  }
}

UInt64 MemoryFailPoint___::MemFreeAfterAddress(void* address, UInt64 size) {
  if (size >= s_topOfMemory) {
    return 0;
  }
  UInt64 num = 0;
  Interop::Kernel32::MEMORY_BASIC_INFORMATION lpBuffer = Interop::Kernel32::MEMORY_BASIC_INFORMATION();
  UIntPtr dwLength = (UIntPtr)(UInt64)sizeof(Interop::Kernel32::MEMORY_BASIC_INFORMATION);
  while ((UInt64)((Int64)address + (Int64)size) < s_topOfMemory) {
    UIntPtr value = Interop::Kernel32::VirtualQuery(address, lpBuffer, dwLength);
    if (value == UIntPtr::Zero) {
      rt::throw_exception(Win32Marshal::GetExceptionForLastWin32Error());
    }
    UInt64 num2 = lpBuffer.RegionSize.ToUInt64();
    if (lpBuffer.State == 65536) {
      if (num2 >= size) {
        return num2;
      }
      num = Math::Max(num, num2);
    }
    address = (void*)((UInt64)address + num2);
  }
  return num;
}

void MemoryFailPoint___::GrowPageFileIfNecessaryAndPossible(UIntPtr numBytes) {
  void* ptr = Interop::Kernel32::VirtualAlloc(nullptr, numBytes, 4096, 4);
  if (ptr != nullptr && !Interop::Kernel32::VirtualFree(ptr, UIntPtr::Zero, 32768)) {
    rt::throw_exception(Win32Marshal::GetExceptionForLastWin32Error());
  }
}

void MemoryFailPoint___::cctor() {
  s_topOfMemory = GetTopOfMemory();
  s_hiddenLastKnownFreeAddressSpace = 0;
  s_hiddenLastTimeCheckingAddressSpace = 0;
  s_GCSegmentSize = GC::GetSegmentSize();
}

} // namespace System::Private::CoreLib::System::Runtime::MemoryFailPointNamespace
