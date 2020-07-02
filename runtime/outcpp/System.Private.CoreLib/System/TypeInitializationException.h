#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(String)
namespace TypeInitializationExceptionNamespace {
using namespace ::System::Private::CoreLib::System::Runtime::Serialization;
CLASS(TypeInitializationException) {
  public: String get_TypeName();
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  private: String _typeName;
};
} // namespace TypeInitializationExceptionNamespace
using TypeInitializationException = TypeInitializationExceptionNamespace::TypeInitializationException;
} // namespace System::Private::CoreLib::System
