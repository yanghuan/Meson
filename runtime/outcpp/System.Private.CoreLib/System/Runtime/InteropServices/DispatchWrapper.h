#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace DispatchWrapperNamespace {
CLASS(DispatchWrapper) : public object {
  public: Object get_WrappedObject() { return WrappedObject; }
  public: void ctor(Object obj);
  private: Object WrappedObject;
};
} // namespace DispatchWrapperNamespace
using DispatchWrapper = DispatchWrapperNamespace::DispatchWrapper;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
