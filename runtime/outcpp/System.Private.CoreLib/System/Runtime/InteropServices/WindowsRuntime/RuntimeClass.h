#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARD(Object)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
namespace RuntimeClassNamespace {
CLASS(RuntimeClass) {
  public: IntPtr GetRedirectedGetHashCodeMD();
  public: Int32 RedirectGetHashCode(IntPtr pMD);
  public: Int32 GetHashCode();
  public: IntPtr GetRedirectedToStringMD();
  public: String RedirectToString(IntPtr pMD);
  public: String ToString();
  public: IntPtr GetRedirectedEqualsMD();
  public: Boolean RedirectEquals(Object obj, IntPtr pMD);
  public: Boolean Equals(Object obj);
};
} // namespace RuntimeClassNamespace
using RuntimeClass = RuntimeClassNamespace::RuntimeClass;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
