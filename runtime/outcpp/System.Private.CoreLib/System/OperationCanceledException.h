#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Threading/CancellationToken.h>

namespace System::Private::CoreLib::System {
namespace OperationCanceledExceptionNamespace {
using namespace ::System::Private::CoreLib::System::Threading;
CLASS(OperationCanceledException) {
  public: CancellationToken get_CancellationToken();
  private: void set_CancellationToken(CancellationToken value);
  private: CancellationToken _cancellationToken;
};
} // namespace OperationCanceledExceptionNamespace
using OperationCanceledException = OperationCanceledExceptionNamespace::OperationCanceledException;
} // namespace System::Private::CoreLib::System
