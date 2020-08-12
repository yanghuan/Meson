#pragma once

#include <System.Private.CoreLib/System/SystemException.h>
#include <System.Private.CoreLib/System/Threading/CancellationToken.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
namespace OperationCanceledExceptionNamespace {
using namespace System::Runtime::Serialization;
using namespace System::Threading;
CLASS(OperationCanceledException) : public SystemException::in {
  public: CancellationToken get_CancellationToken();
  private: void set_CancellationToken(CancellationToken value);
  public: void ctor();
  public: void ctor(String message);
  public: void ctor(String message, Exception innerException);
  public: void ctor(CancellationToken token);
  public: void ctor(String message, CancellationToken token);
  public: void ctor(String message, Exception innerException, CancellationToken token);
  protected: void ctor(SerializationInfo info, StreamingContext context);
  private: CancellationToken _cancellationToken;
};
} // namespace OperationCanceledExceptionNamespace
using OperationCanceledException = OperationCanceledExceptionNamespace::OperationCanceledException;
} // namespace System::Private::CoreLib::System
