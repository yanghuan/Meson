#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Runtime/ConstrainedExecution/CriticalFinalizerObject.h>
#include <System.Private.CoreLib/System/UInt64.h>

namespace System::Private::CoreLib::System {
FORWARD(IDisposable)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARDS(UIntPtr)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime {
namespace MemoryFailPointNamespace {
using namespace ConstrainedExecution;
CLASS(MemoryFailPoint) : public CriticalFinalizerObject::in {
  using interface = rt::TypeList<IDisposable>;
  private: static Int64 get_LastKnownFreeAddressSpace();
  private: static void set_LastKnownFreeAddressSpace(Int64 value);
  private: static Int64 get_LastTimeCheckingAddressSpace();
  private: static void set_LastTimeCheckingAddressSpace(Int64 value);
  public: static UInt64 get_MemoryFailPointReservedMemory();
  private: static void AddToLastKnownFreeAddressSpace(Int64 addend);
  public: void Ctor(Int32 sizeInMegabytes);
  protected: void Finalize();
  public: void Dispose();
  private: void Dispose(Boolean disposing);
  public: static Int64 AddMemoryFailPointReservation(Int64 size);
  private: static UInt64 GetTopOfMemory();
  private: static Boolean CheckForAvailableMemory(UInt64& availPageFile, UInt64& totalAddressSpaceFree);
  private: static void CheckForFreeAddressSpace(UInt64 size, Boolean shouldThrow);
  private: static UInt64 MemFreeAfterAddress(void* address, UInt64 size);
  private: static void GrowPageFileIfNecessaryAndPossible(UIntPtr numBytes);
  private: static void SCtor();
  private: static UInt64 s_topOfMemory;
  private: static Int64 s_hiddenLastKnownFreeAddressSpace;
  private: static Int64 s_hiddenLastTimeCheckingAddressSpace;
  private: static UInt64 s_GCSegmentSize;
  private: static Int64 s_failPointReservedMemory;
  private: UInt64 _reservedMemory;
  private: Boolean _mustSubtractReservation;
};
} // namespace MemoryFailPointNamespace
using MemoryFailPoint = MemoryFailPointNamespace::MemoryFailPoint;
} // namespace System::Private::CoreLib::System::Runtime
