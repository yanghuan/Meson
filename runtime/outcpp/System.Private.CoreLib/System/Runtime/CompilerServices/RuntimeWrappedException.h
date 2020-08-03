#pragma once

#include <System.Private.CoreLib/System/Exception.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace RuntimeWrappedExceptionNamespace {
using namespace Serialization;
CLASS(RuntimeWrappedException) : public Exception::in {
  public: Object get_WrappedException();
  public: void Ctor(Object thrownObject);
  private: void Ctor(SerializationInfo info, StreamingContext context);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  private: Object _wrappedException;
};
} // namespace RuntimeWrappedExceptionNamespace
using RuntimeWrappedException = RuntimeWrappedExceptionNamespace::RuntimeWrappedException;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
