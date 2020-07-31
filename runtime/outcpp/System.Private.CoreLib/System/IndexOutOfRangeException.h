#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/SystemException.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
namespace IndexOutOfRangeExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(IndexOutOfRangeException) : public SystemException::in {
  public: void Ctor();
  public: void Ctor(String message);
  public: void Ctor(String message, Exception innerException);
  private: void Ctor(SerializationInfo info, StreamingContext context);
};
} // namespace IndexOutOfRangeExceptionNamespace
using IndexOutOfRangeException = IndexOutOfRangeExceptionNamespace::IndexOutOfRangeException;
} // namespace System::Private::CoreLib::System
