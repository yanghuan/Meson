#pragma once

#include <System.Private.CoreLib/System/Exception.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Threading::System::Threading {
namespace BarrierPostPhaseExceptionNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Runtime::Serialization;
CLASS(BarrierPostPhaseException) : public Exception::in {
  public: void ctor();
  public: void ctor(Exception innerException);
  public: void ctor(String message);
  public: void ctor(String message, Exception innerException);
  protected: void ctor(SerializationInfo info, StreamingContext context);
};
} // namespace BarrierPostPhaseExceptionNamespace
using BarrierPostPhaseException = BarrierPostPhaseExceptionNamespace::BarrierPostPhaseException;
} // namespace System::Threading::System::Threading
