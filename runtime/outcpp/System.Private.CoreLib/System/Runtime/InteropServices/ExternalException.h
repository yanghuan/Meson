#pragma once

#include <System.Private.CoreLib/System/SystemException.h>

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
namespace ExternalExceptionNamespace {
using namespace System::Runtime::Serialization;
CLASS(ExternalException) : public SystemException::in {
  public: Int32 get_ErrorCode();
  public: void ctor();
  public: void ctor(String message);
  public: void ctor(String message, Exception inner);
  public: void ctor(String message, Int32 errorCode);
  public: void ctor(SerializationInfo info, StreamingContext context);
  public: String ToString();
};
} // namespace ExternalExceptionNamespace
using ExternalException = ExternalExceptionNamespace::ExternalException;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
