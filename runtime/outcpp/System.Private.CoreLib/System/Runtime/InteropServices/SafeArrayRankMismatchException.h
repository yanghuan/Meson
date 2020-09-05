#pragma once

#include <System.Private.CoreLib/System/SystemException.h>

namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace SafeArrayRankMismatchExceptionNamespace {
using namespace System::Runtime::Serialization;
CLASS(SafeArrayRankMismatchException) : public SystemException::in {
  public: void ctor();
  public: void ctor(String message);
  public: void ctor(String message, Exception inner);
  public: void ctor(SerializationInfo info, StreamingContext context);
};
} // namespace SafeArrayRankMismatchExceptionNamespace
using SafeArrayRankMismatchException = SafeArrayRankMismatchExceptionNamespace::SafeArrayRankMismatchException;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
