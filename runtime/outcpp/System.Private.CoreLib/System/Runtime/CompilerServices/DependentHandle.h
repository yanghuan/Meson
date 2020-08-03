#pragma once

#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace DependentHandleNamespace {
struct DependentHandle : public valueType<DependentHandle> {
  public: Boolean get_IsAllocated();
  public: explicit DependentHandle(Object primary, Object secondary);
  public: Object GetPrimary();
  public: Object GetPrimaryAndSecondary(Object& secondary);
  public: void SetPrimary(Object primary);
  public: void SetSecondary(Object secondary);
  public: void Free();
  private: static IntPtr nInitialize(Object primary, Object secondary);
  private: static Object nGetPrimary(IntPtr dependentHandle);
  private: static Object nGetPrimaryAndSecondary(IntPtr dependentHandle, Object& secondary);
  private: static void nSetPrimary(IntPtr dependentHandle, Object primary);
  private: static void nSetSecondary(IntPtr dependentHandle, Object secondary);
  private: static void nFree(IntPtr dependentHandle);
  public: explicit DependentHandle() {}
  private: IntPtr _handle;
};
} // namespace DependentHandleNamespace
using DependentHandle = DependentHandleNamespace::DependentHandle;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
