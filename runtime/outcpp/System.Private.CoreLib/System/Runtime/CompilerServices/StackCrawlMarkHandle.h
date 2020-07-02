#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/IntPtr.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace StackCrawlMarkHandleNamespace {
struct StackCrawlMarkHandle {
  private: IntPtr m_ptr;
};
} // namespace StackCrawlMarkHandleNamespace
using StackCrawlMarkHandle = StackCrawlMarkHandleNamespace::StackCrawlMarkHandle;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
