#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/IntPtr.h>

namespace System::Private::CoreLib::System {
namespace ByReferenceNamespace {
template <class T>
struct ByReference {
  public: T& get_Value();
  private: IntPtr _value;
};
} // namespace ByReferenceNamespace
template <class T>
using ByReference = ByReferenceNamespace::ByReference<T>;
} // namespace System::Private::CoreLib::System
