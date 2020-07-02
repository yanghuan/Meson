#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/IntPtr.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class GCHandleType;
namespace GCHandleNamespace {
struct GCHandle {
  public: Object get_Target();
  public: void set_Target(Object value);
  public: Boolean get_IsAllocated();
  private: static IntPtr InternalAlloc(Object value, GCHandleType type);
  public: static void InternalFree(IntPtr handle);
  public: static Object InternalGet(IntPtr handle);
  private: static void InternalSet(IntPtr handle, Object value);
  public: static Object InternalCompareExchange(IntPtr handle, Object value, Object oldValue);
  public: static GCHandle Alloc(Object value);
  public: static GCHandle Alloc(Object value, GCHandleType type);
  public: void Free();
  public: IntPtr AddrOfPinnedObject();
  public: static GCHandle FromIntPtr(IntPtr value);
  public: static IntPtr ToIntPtr(GCHandle value);
  public: Int32 GetHashCode();
  public: Boolean Equals(Object o);
  private: static IntPtr GetHandleValue(IntPtr handle);
  private: static Boolean IsPinned(IntPtr handle);
  private: static void ThrowIfInvalid(IntPtr handle);
  private: IntPtr _handle;
};
} // namespace GCHandleNamespace
using GCHandle = GCHandleNamespace::GCHandle;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
