#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(String)
namespace ArgumentExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(ArgumentException) {
  public: String get_Message();
  public: String get_ParamName();
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  private: void SetMessageField();
  private: String _paramName;
};
} // namespace ArgumentExceptionNamespace
using ArgumentException = ArgumentExceptionNamespace::ArgumentException;
} // namespace System::Private::CoreLib::System
