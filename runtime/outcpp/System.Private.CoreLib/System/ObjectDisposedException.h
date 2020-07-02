#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(String)
namespace ObjectDisposedExceptionNamespace {
using namespace ::System::Private::CoreLib::System::Runtime::Serialization;
CLASS(ObjectDisposedException) {
  public: String get_Message();
  public: String get_ObjectName();
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  private: String _objectName;
};
} // namespace ObjectDisposedExceptionNamespace
using ObjectDisposedException = ObjectDisposedExceptionNamespace::ObjectDisposedException;
} // namespace System::Private::CoreLib::System
