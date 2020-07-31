#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/FormatException.h>

namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::Uri::System {
namespace UriFormatExceptionNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Runtime::Serialization;
CLASS(UriFormatException) : public FormatException::in {
  public: void Ctor();
  public: void Ctor(String textString);
  public: void Ctor(String textString, Exception e);
  protected: void Ctor(SerializationInfo serializationInfo, StreamingContext streamingContext);
};
} // namespace UriFormatExceptionNamespace
using UriFormatException = UriFormatExceptionNamespace::UriFormatException;
} // namespace System::Private::Uri::System
