#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/IntPtr.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Object)
namespace WeakReferenceNamespace {
CLASS_FORWARD(WeakReference, T1, T2)
CLASS_(WeakReference) {
  public: Boolean get_IsAlive();
  public: Boolean get_TrackResurrection();
  public: Object get_Target();
  public: void set_Target(Object value);
  public: IntPtr m_handle;
};
CLASS_(WeakReference, T) {
  private: T get_Target();
  private: void set_Target(T value);
  public: IntPtr m_handle;
};
} // namespace WeakReferenceNamespace
template <class T1 = void, class T2 = void>
using WeakReference = WeakReferenceNamespace::WeakReference<T1, T2>;
} // namespace System::Private::CoreLib::System
