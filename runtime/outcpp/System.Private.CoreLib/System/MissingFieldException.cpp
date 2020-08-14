#include "MissingFieldException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::MissingFieldExceptionNamespace {
String MissingFieldException___::get_Message() {
  if (ClassName == nullptr) {
    return MissingMemberException::get_Message();
  }
  return SR::Format(SR::get_MissingField_Name(), ((Signature != nullptr) ? (MissingMemberException::in::FormatSignature(Signature) + " ") : "") + ClassName + "." + MemberName);
}

void MissingFieldException___::ctor() {
  Exception::set_HResult = -2146233071;
}

void MissingFieldException___::ctor(String message) {
  Exception::set_HResult = -2146233071;
}

void MissingFieldException___::ctor(String message, Exception inner) {
  Exception::set_HResult = -2146233071;
}

void MissingFieldException___::ctor(String className, String fieldName) {
  ClassName = className;
  MemberName = fieldName;
}

void MissingFieldException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::MissingFieldExceptionNamespace
