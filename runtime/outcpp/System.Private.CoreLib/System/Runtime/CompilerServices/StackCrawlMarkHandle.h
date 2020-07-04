#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace StackCrawlMarkHandleNamespace {
struct StackCrawlMarkHandle {
  private: void* _ptr;
};
} // namespace StackCrawlMarkHandleNamespace
using StackCrawlMarkHandle = StackCrawlMarkHandleNamespace::StackCrawlMarkHandle;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
