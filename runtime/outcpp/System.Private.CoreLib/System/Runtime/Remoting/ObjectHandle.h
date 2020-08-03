#pragma once

#include <System.Private.CoreLib/System/MarshalByRefObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Remoting {
namespace ObjectHandleNamespace {
CLASS(ObjectHandle) : public MarshalByRefObject::in {
  public: void Ctor(Object o);
  public: Object Unwrap();
  private: Object _wrappedObject;
};
} // namespace ObjectHandleNamespace
using ObjectHandle = ObjectHandleNamespace::ObjectHandle;
} // namespace System::Private::CoreLib::System::Runtime::Remoting
