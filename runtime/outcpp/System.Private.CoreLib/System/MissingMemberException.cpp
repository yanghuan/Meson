#include "MissingMemberException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::MissingMemberExceptionNamespace {
String MissingMemberException___::get_Message() {
  if (ClassName == nullptr) {
    return Exception::get_Message();
  }
  return SR::Format(SR::get_MissingMember_Name(), ClassName + "." + MemberName + ((Signature != nullptr) ? (" " + FormatSignature(Signature)) : String::in::Empty));
}

void MissingMemberException___::ctor() {
  Exception::set_HResult = -2146233070;
}

void MissingMemberException___::ctor(String message) {
  Exception::set_HResult = -2146233070;
}

void MissingMemberException___::ctor(String message, Exception inner) {
  Exception::set_HResult = -2146233070;
}

void MissingMemberException___::ctor(String className, String memberName) {
  ClassName = className;
  MemberName = memberName;
}

void MissingMemberException___::ctor(SerializationInfo info, StreamingContext context) {
  ClassName = info->GetString("MMClassName");
  MemberName = info->GetString("MMMemberName");
  Signature = (Array<Byte>)info->GetValue("MMSignature", rt::typeof<Array<Byte>>());
}

void MissingMemberException___::GetObjectData(SerializationInfo info, StreamingContext context) {
  Exception::GetObjectData(info, context);
  info->AddValue("MMClassName", ClassName, rt::typeof<String>());
  info->AddValue("MMMemberName", MemberName, rt::typeof<String>());
  info->AddValue("MMSignature", Signature, rt::typeof<Array<Byte>>());
}

} // namespace System::Private::CoreLib::System::MissingMemberExceptionNamespace
