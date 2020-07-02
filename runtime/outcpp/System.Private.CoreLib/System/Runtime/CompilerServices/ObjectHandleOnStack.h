#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/IntPtr.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace ObjectHandleOnStackNamespace {
struct ObjectHandleOnStack {
  private: IntPtr m_ptr;
};
} // namespace ObjectHandleOnStackNamespace
using ObjectHandleOnStack = ObjectHandleOnStackNamespace::ObjectHandleOnStack;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
