#include "PreAllocatedOverlapped-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/Threading/PreAllocatedOverlapped-dep.h>
#include <System.Private.CoreLib/System/Threading/ThreadPoolBoundHandleOverlapped-dep.h>

namespace System::Private::CoreLib::System::Threading::PreAllocatedOverlappedNamespace {
void PreAllocatedOverlapped___::ctor(IOCompletionCallback callback, Object state, Object pinData) {
  if (callback == nullptr) {
    rt::throw_exception<ArgumentNullException>("callback");
  }
  _overlapped = rt::newobj<ThreadPoolBoundHandleOverlapped>(callback, state, pinData, (PreAllocatedOverlapped)this);
}

Boolean PreAllocatedOverlapped___::AddRef() {
  return _lifetime.AddRef();
}

void PreAllocatedOverlapped___::Release() {
  _lifetime.Release((PreAllocatedOverlapped)this);
}

void PreAllocatedOverlapped___::Dispose() {
  _lifetime.Dispose((PreAllocatedOverlapped)this);
  GC::SuppressFinalize((PreAllocatedOverlapped)this);
}

void PreAllocatedOverlapped___::Finalize() {
  Dispose();
}

} // namespace System::Private::CoreLib::System::Threading::PreAllocatedOverlappedNamespace
