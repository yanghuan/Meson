#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace ObjectHandleOnStackNamespace {
struct ObjectHandleOnStack {
  private: explicit ObjectHandleOnStack(void* pObject);
  public: template <class T>
  static ObjectHandleOnStack Create(T& o);
  public: explicit ObjectHandleOnStack() {}
  private: void* _ptr;
};
} // namespace ObjectHandleOnStackNamespace
using ObjectHandleOnStack = ObjectHandleOnStackNamespace::ObjectHandleOnStack;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
