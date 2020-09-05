#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/SystemException.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
namespace AccessViolationExceptionNamespace {
using namespace System::Runtime::Serialization;
CLASS(AccessViolationException) : public SystemException::in {
  public: void ctor();
  public: void ctor(String message);
  public: void ctor(String message, Exception innerException);
  public: void ctor(SerializationInfo info, StreamingContext context);
  private: IntPtr _ip;
  private: IntPtr _target;
  private: Int32 _accessType;
};
} // namespace AccessViolationExceptionNamespace
using AccessViolationException = AccessViolationExceptionNamespace::AccessViolationException;
} // namespace System::Private::CoreLib::System
