#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/SystemException.h>

namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(Object)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(AssemblyName)
FORWARD(MethodInfo)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Security {
namespace SecurityExceptionNamespace {
using namespace Reflection;
using namespace Runtime::Serialization;
CLASS(SecurityException) : public SystemException::in {
  public: Object get_Demanded() { return Demanded; }
  public: void set_Demanded(Object value) { Demanded = value; }
  public: Object get_DenySetInstance() { return DenySetInstance; }
  public: void set_DenySetInstance(Object value) { DenySetInstance = value; }
  public: AssemblyName get_FailedAssemblyInfo() { return FailedAssemblyInfo; }
  public: void set_FailedAssemblyInfo(AssemblyName value) { FailedAssemblyInfo = value; }
  public: String get_GrantedSet() { return GrantedSet; }
  public: void set_GrantedSet(String value) { GrantedSet = value; }
  public: MethodInfo get_Method() { return Method; }
  public: void set_Method(MethodInfo value) { Method = value; }
  public: String get_PermissionState() { return PermissionState; }
  public: void set_PermissionState(String value) { PermissionState = value; }
  public: Type get_PermissionType() { return PermissionType; }
  public: void set_PermissionType(Type value) { PermissionType = value; }
  public: Object get_PermitOnlySetInstance() { return PermitOnlySetInstance; }
  public: void set_PermitOnlySetInstance(Object value) { PermitOnlySetInstance = value; }
  public: String get_RefusedSet() { return RefusedSet; }
  public: void set_RefusedSet(String value) { RefusedSet = value; }
  public: String get_Url() { return Url; }
  public: void set_Url(String value) { Url = value; }
  public: void Ctor();
  public: void Ctor(String message);
  public: void Ctor(String message, Exception inner);
  public: void Ctor(String message, Type type);
  public: void Ctor(String message, Type type, String state);
  protected: void Ctor(SerializationInfo info, StreamingContext context);
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
