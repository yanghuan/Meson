#pragma once

#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
namespace ByReferenceNamespace {
template <class T>
struct ByReference : public valueType<ByReference<T>> {
  public: T& get_Value();
  public: explicit ByReference(T& value);
  public: explicit ByReference() {}
  private: IntPtr _value;
};
} // namespace ByReferenceNamespace
template <class T>
using ByReference = ByReferenceNamespace::ByReference<T>;
} // namespace System::Private::CoreLib::System
