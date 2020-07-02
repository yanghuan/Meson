#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Reflection {
namespace ReflectionTypeLoadExceptionNamespace {
using namespace ::System::Private::CoreLib::System::Runtime::Serialization;
CLASS(ReflectionTypeLoadException) {
  public: String get_Message();
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  public: String ToString();
  private: String CreateString(Boolean isMessage);
};
} // namespace ReflectionTypeLoadExceptionNamespace
using ReflectionTypeLoadException = ReflectionTypeLoadExceptionNamespace::ReflectionTypeLoadException;
} // namespace System::Private::CoreLib::System::Reflection
