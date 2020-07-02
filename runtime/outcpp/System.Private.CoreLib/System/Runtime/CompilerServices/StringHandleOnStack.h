#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/IntPtr.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace StringHandleOnStackNamespace {
struct StringHandleOnStack {
  private: IntPtr m_ptr;
};
} // namespace StringHandleOnStackNamespace
using StringHandleOnStack = StringHandleOnStackNamespace::StringHandleOnStack;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
