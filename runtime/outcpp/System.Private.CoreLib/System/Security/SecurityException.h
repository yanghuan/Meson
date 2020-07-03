#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Reflection {
FORWARD(AssemblyName)
FORWARD(MethodInfo)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Security {
namespace SecurityExceptionNamespace {
using namespace ::System::Private::CoreLib::System::Reflection;
using namespace ::System::Private::CoreLib::System::Runtime::Serialization;
CLASS(SecurityException) {
  public: String ToString();
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  private: Object Demanded;
  private: Object DenySetInstance;
  private: AssemblyName FailedAssemblyInfo;
  private: String GrantedSet;
  private: MethodInfo Method;
  private: String PermissionState;
  private: Type PermissionType;
  private: Object PermitOnlySetInstance;
  private: String RefusedSet;
  private: String Url;
};
} // namespace SecurityExceptionNamespace
using SecurityException = SecurityExceptionNamespace::SecurityException;
} // namespace System::Private::CoreLib::System::Security
