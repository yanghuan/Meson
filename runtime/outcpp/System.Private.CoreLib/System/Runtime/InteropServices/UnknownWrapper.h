#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace UnknownWrapperNamespace {
CLASS(UnknownWrapper) : public object {
  public: Object get_WrappedObject() { return WrappedObject; }
  public: void ctor(Object obj);
  private: Object WrappedObject;
};
} // namespace UnknownWrapperNamespace
using UnknownWrapper = UnknownWrapperNamespace::UnknownWrapper;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
