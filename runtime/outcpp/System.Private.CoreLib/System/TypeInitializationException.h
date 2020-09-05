#pragma once

#include <System.Private.CoreLib/System/SystemException.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
namespace TypeInitializationExceptionNamespace {
using namespace System::Runtime::Serialization;
CLASS(TypeInitializationException) : public SystemException::in {
  public: String get_TypeName();
  public: void ctor();
  public: void ctor(String fullTypeName, Exception innerException);
  public: void ctor(String message);
  public: void ctor(String fullTypeName, String message, Exception innerException);
  public: void ctor(SerializationInfo info, StreamingContext context);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  private: String _typeName;
};
} // namespace TypeInitializationExceptionNamespace
using TypeInitializationException = TypeInitializationExceptionNamespace::TypeInitializationException;
} // namespace System::Private::CoreLib::System
