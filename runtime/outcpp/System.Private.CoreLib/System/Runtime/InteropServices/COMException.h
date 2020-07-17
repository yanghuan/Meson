#pragma once

#include <rt/GCObject.h>

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
using namespace Serialization;
CLASS(COMException) {
  public: void Ctor();
  public: void Ctor(String message);
  public: void Ctor(String message, Exception inner);
  public: void Ctor(String message, Int32 errorCode);
  protected: void Ctor(SerializationInfo info, StreamingContext context);
  public: String ToString();
};
} // namespace COMExceptionNamespace
using COMException = COMExceptionNamespace::COMException;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
