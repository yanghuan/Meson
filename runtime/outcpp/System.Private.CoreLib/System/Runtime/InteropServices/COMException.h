#pragma once

#include <System.Private.CoreLib/System/Runtime/InteropServices/ExternalException.h>

namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARDS(Int32)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace COMExceptionNamespace {
using namespace System::Runtime::Serialization;
CLASS(COMException) : public ExternalException::in {
  public: void ctor();
  public: void ctor(String message);
  public: void ctor(String message, Exception inner);
  public: void ctor(String message, Int32 errorCode);
  public: void ctor(SerializationInfo info, StreamingContext context);
  public: String ToString();
};
} // namespace COMExceptionNamespace
using COMException = COMExceptionNamespace::COMException;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
