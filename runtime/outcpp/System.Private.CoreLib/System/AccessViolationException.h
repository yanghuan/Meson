#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/IntPtr.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
namespace AccessViolationExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(AccessViolationException) {
  public: void Ctor();
  public: void Ctor(String message);
  public: void Ctor(String message, Exception innerException);
  protected: void Ctor(SerializationInfo info, StreamingContext context);
  private: IntPtr _ip;
  private: IntPtr _target;
  private: Int32 _accessType;
};
} // namespace AccessViolationExceptionNamespace
using AccessViolationException = AccessViolationExceptionNamespace::AccessViolationException;
} // namespace System::Private::CoreLib::System
