#include "MissingMemberException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::MissingMemberExceptionNamespace {
String MissingMemberException___::get_Message() {
  if (ClassName == nullptr) {
    return Exception::in::get_Message();
  }
  return SR::Format(SR::get_MissingMember_Name(), ClassName + "." + MemberName + ((Signature != nullptr) ? (" " + FormatSignature(Signature)) : String::in::Empty));
}

void MissingMemberException___::ctor() {
  Exception::in::set_HResult(-2146233070);
}

void MissingMemberException___::ctor(String message) {
  Exception::in::set_HResult(-2146233070);
}

void MissingMemberException___::ctor(String message, Exception inner) {
  Exception::in::set_HResult(-2146233070);
}

void MissingMemberException___::ctor(String className, String memberName) {
  ClassName = className;
  MemberName = memberName;
}

void MissingMemberException___::ctor(SerializationInfo info, StreamingContext context) {
  ClassName = info->GetString("MMClassName");
  MemberName = info->GetString("MMMemberName");
  Signature = (Array<Byte>)info->GetValue("MMSignature", typeof<Array<Byte>>());
}

void MissingMemberException___::GetObjectData(SerializationInfo info, StreamingContext context) {
  Exception::in::GetObjectData(info, context);
  info->AddValue("MMClassName", ClassName, typeof<String>());
  info->AddValue("MMMemberName", MemberName, typeof<String>());
  info->AddValue("MMSignature", Signature, typeof<Array<Byte>>());
}

} // namespace System::Private::CoreLib::System::MissingMemberExceptionNamespace
