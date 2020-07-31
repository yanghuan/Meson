#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace UnknownWrapperNamespace {
CLASS(UnknownWrapper) : public Object::in {
  public: Object get_WrappedObject() { return WrappedObject; }
  public: void Ctor(Object obj);
  private: Object WrappedObject;
};
} // namespace UnknownWrapperNamespace
using UnknownWrapper = UnknownWrapperNamespace::UnknownWrapper;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
