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
  auto default = _className;
  if (default != nullptr) default = String::in::Empty;

  return default;
}

void TypeLoadException___::ctor(String className, String assemblyName, String messageArg, Int32 resourceId) {
  Exception::set_HResult = -2146233054;
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
  Exception::set_HResult = -2146233054;
}

void TypeLoadException___::ctor(String message) {
  Exception::set_HResult = -2146233054;
}

void TypeLoadException___::ctor(String message, Exception inner) {
  Exception::set_HResult = -2146233054;
}

void TypeLoadException___::ctor(SerializationInfo info, StreamingContext context) {
  _className = info->GetString("TypeLoadClassName");
  _assemblyName = info->GetString("TypeLoadAssemblyName");
  _messageArg = info->GetString("TypeLoadMessageArg");
  _resourceId = info->GetInt32("TypeLoadResourceID");
}

void TypeLoadException___::GetObjectData(SerializationInfo info, StreamingContext context) {
  Exception::GetObjectData(info, context);
  info->AddValue("TypeLoadClassName", _className, rt::typeof<String>());
  info->AddValue("TypeLoadAssemblyName", _assemblyName, rt::typeof<String>());
  info->AddValue("TypeLoadMessageArg", _messageArg, rt::typeof<String>());
  info->AddValue("TypeLoadResourceID", _resourceId);
}

} // namespace System::Private::CoreLib::System::TypeLoadExceptionNamespace
