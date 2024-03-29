#include "TypeLoadException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/StringHandleOnStack-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::TypeLoadExceptionNamespace {
using namespace System::Runtime::CompilerServices;

String TypeLoadException___::get_Message() {
  SetMessageField();
  return _message;
}

String TypeLoadException___::get_TypeName() {
  String as = _className;
  return as != nullptr ? as : String::in::Empty;
}

void TypeLoadException___::ctor(String className, String assemblyName, String messageArg, Int32 resourceId) {
  Exception::in::set_HResult(-2146233054);
  _className = className;
  _assemblyName = assemblyName;
  _messageArg = messageArg;
  _resourceId = resourceId;
  SetMessageField();
}

void TypeLoadException___::SetMessageField() {
  if (_message != nullptr) {
    return;
  }
  if (_className == nullptr && _resourceId == 0) {
    _message = SR::get_Arg_TypeLoadException();
    return;
  }
  if (_assemblyName == nullptr) {
    _assemblyName = SR::get_IO_UnknownFileName();
  }
  if (_className == nullptr) {
    _className = SR::get_IO_UnknownFileName();
  }
  String s = nullptr;
  GetTypeLoadExceptionMessage(_resourceId, StringHandleOnStack(s));
  _message = String::in::Format(s, _className, _assemblyName, _messageArg);
}

void TypeLoadException___::ctor() {
  Exception::in::set_HResult(-2146233054);
}

void TypeLoadException___::ctor(String message) {
  Exception::in::set_HResult(-2146233054);
}

void TypeLoadException___::ctor(String message, Exception inner) {
  Exception::in::set_HResult(-2146233054);
}

void TypeLoadException___::ctor(SerializationInfo info, StreamingContext context) {
  _className = info->GetString("TypeLoadClassName");
  _assemblyName = info->GetString("TypeLoadAssemblyName");
  _messageArg = info->GetString("TypeLoadMessageArg");
  _resourceId = info->GetInt32("TypeLoadResourceID");
}

void TypeLoadException___::GetObjectData(SerializationInfo info, StreamingContext context) {
  Exception::in::GetObjectData(info, context);
  info->AddValue("TypeLoadClassName", _className, typeof<String>());
  info->AddValue("TypeLoadAssemblyName", _assemblyName, typeof<String>());
  info->AddValue("TypeLoadMessageArg", _messageArg, typeof<String>());
  info->AddValue("TypeLoadResourceID", _resourceId);
}

} // namespace System::Private::CoreLib::System::TypeLoadExceptionNamespace
