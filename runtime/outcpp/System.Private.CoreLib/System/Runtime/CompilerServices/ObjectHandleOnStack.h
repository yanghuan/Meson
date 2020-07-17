#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace ObjectHandleOnStackNamespace {
struct ObjectHandleOnStack {
  private: void Ctor(void* pObject);
  public: void Ctor();
  private: void* _ptr;
};
} // namespace ObjectHandleOnStackNamespace
using ObjectHandleOnStack = ObjectHandleOnStackNamespace::ObjectHandleOnStack;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
