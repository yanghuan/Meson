#pragma once

#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace StringHandleOnStackNamespace {
struct StringHandleOnStack : public valueType<StringHandleOnStack> {
  public: explicit StringHandleOnStack(String& s);
  public: explicit StringHandleOnStack() {}
  private: void* _ptr;
};
} // namespace StringHandleOnStackNamespace
using StringHandleOnStack = StringHandleOnStackNamespace::StringHandleOnStack;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
