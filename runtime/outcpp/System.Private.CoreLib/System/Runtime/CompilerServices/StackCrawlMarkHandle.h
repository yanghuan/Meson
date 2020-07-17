#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Threading {
enum class StackCrawlMark;
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace StackCrawlMarkHandleNamespace {
using namespace Threading;
struct StackCrawlMarkHandle {
  public: void Ctor(StackCrawlMark& stackMark);
  public: void Ctor();
  private: void* _ptr;
};
} // namespace StackCrawlMarkHandleNamespace
using StackCrawlMarkHandle = StackCrawlMarkHandleNamespace::StackCrawlMarkHandle;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
