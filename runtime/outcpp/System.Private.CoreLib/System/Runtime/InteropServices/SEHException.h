#pragma once

#include <System.Private.CoreLib/System/Runtime/InteropServices/ExternalException.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Exception)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace SEHExceptionNamespace {
using namespace Serialization;
CLASS(SEHException) : public ExternalException::in {
  public: void Ctor();
  public: void Ctor(String message);
  public: void Ctor(String message, Exception inner);
  protected: void Ctor(SerializationInfo info, StreamingContext context);
  public: Boolean CanResume();
};
} // namespace SEHExceptionNamespace
using SEHException = SEHExceptionNamespace::SEHException;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
