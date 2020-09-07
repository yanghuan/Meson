#pragma once

#include <System.Private.CoreLib/System/FormatException.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(ISerializable)
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::Uri::System {
namespace UriFormatExceptionNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Runtime::Serialization;
CLASS(UriFormatException) : public FormatException::in {
  public: using interface = rt::TypeList<ISerializable>;
  public: void ctor();
  public: void ctor(String textString);
  public: void ctor(String textString, Exception e);
  public: void ctor(SerializationInfo serializationInfo, StreamingContext streamingContext);
  private: void GetObjectDataOfISerializable(SerializationInfo serializationInfo, StreamingContext streamingContext);
};
} // namespace UriFormatExceptionNamespace
using UriFormatException = UriFormatExceptionNamespace::UriFormatException;
} // namespace System::Private::Uri::System
