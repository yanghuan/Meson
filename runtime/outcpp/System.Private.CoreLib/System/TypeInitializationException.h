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
namespace TypeInitializationExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(TypeInitializationException) : public SystemException::in {
  public: String get_TypeName();
  private: void Ctor();
  public: void Ctor(String fullTypeName, Exception innerException);
  public: void Ctor(String message);
  public: void Ctor(String fullTypeName, String message, Exception innerException);
  private: void Ctor(SerializationInfo info, StreamingContext context);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  private: String _typeName;
};
} // namespace TypeInitializationExceptionNamespace
using TypeInitializationException = TypeInitializationExceptionNamespace::TypeInitializationException;
} // namespace System::Private::CoreLib::System
