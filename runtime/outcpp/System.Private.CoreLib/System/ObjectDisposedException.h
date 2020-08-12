#pragma once

#include <System.Private.CoreLib/System/InvalidOperationException.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
namespace ObjectDisposedExceptionNamespace {
using namespace System::Runtime::Serialization;
CLASS(ObjectDisposedException) : public InvalidOperationException::in {
  public: String get_Message();
  public: String get_ObjectName();
  private: void ctor();
  public: void ctor(String objectName);
  public: void ctor(String objectName, String message);
  public: void ctor(String message, Exception innerException);
  protected: void ctor(SerializationInfo info, StreamingContext context);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  private: String _objectName;
};
} // namespace ObjectDisposedExceptionNamespace
using ObjectDisposedException = ObjectDisposedExceptionNamespace::ObjectDisposedException;
} // namespace System::Private::CoreLib::System
