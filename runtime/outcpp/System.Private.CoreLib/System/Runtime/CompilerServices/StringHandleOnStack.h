#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace StringHandleOnStackNamespace {
struct StringHandleOnStack {
  private: void* _ptr;
};
} // namespace StringHandleOnStackNamespace
using StringHandleOnStack = StringHandleOnStackNamespace::StringHandleOnStack;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
