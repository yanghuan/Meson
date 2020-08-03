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
using namespace Runtime::Serialization;
using namespace Threading;
CLASS(OperationCanceledException) : public SystemException::in {
  public: CancellationToken get_CancellationToken();
  private: void set_CancellationToken(CancellationToken value);
  public: void Ctor();
  public: void Ctor(String message);
  public: void Ctor(String message, Exception innerException);
  public: void Ctor(CancellationToken token);
  public: void Ctor(String message, CancellationToken token);
  public: void Ctor(String message, Exception innerException, CancellationToken token);
  protected: void Ctor(SerializationInfo info, StreamingContext context);
  private: CancellationToken _cancellationToken;
};
} // namespace OperationCanceledExceptionNamespace
using OperationCanceledException = OperationCanceledExceptionNamespace::OperationCanceledException;
} // namespace System::Private::CoreLib::System
