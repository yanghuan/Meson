#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
namespace ObjectDisposedExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(ObjectDisposedException) {
  public: String get_Message();
  public: String get_ObjectName();
  private: void Ctor();
  public: void Ctor(String objectName);
  public: void Ctor(String objectName, String message);
  public: void Ctor(String message, Exception innerException);
  protected: void Ctor(SerializationInfo info, StreamingContext context);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  private: String _objectName;
};
} // namespace ObjectDisposedExceptionNamespace
using ObjectDisposedException = ObjectDisposedExceptionNamespace::ObjectDisposedException;
} // namespace System::Private::CoreLib::System
