#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace StringHandleOnStackNamespace {
struct StringHandleOnStack {
  public: void Ctor(String& s);
  public: void Ctor();
  private: void* _ptr;
};
} // namespace StringHandleOnStackNamespace
using StringHandleOnStack = StringHandleOnStackNamespace::StringHandleOnStack;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
