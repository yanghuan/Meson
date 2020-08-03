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
namespace System::Private::CoreLib::System::IO {
namespace IOExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(IOException) : public SystemException::in {
  public: void Ctor();
  public: void Ctor(String message);
  public: void Ctor(String message, Int32 hresult);
  public: void Ctor(String message, Exception innerException);
  protected: void Ctor(SerializationInfo info, StreamingContext context);
};
} // namespace IOExceptionNamespace
using IOException = IOExceptionNamespace::IOException;
} // namespace System::Private::CoreLib::System::IO
