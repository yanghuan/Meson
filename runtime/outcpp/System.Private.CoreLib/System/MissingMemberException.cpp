#include "MissingMemberException-dep.h"

#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::MissingMemberExceptionNamespace {
String MissingMemberException___::get_Message() {
  if (ClassName == nullptr) {
  }
  return SR::Format(SR::get_MissingMember_Name(), ClassName + "." + MemberName + ((Signature != nullptr) ? (" " + FormatSignature(Signature)) : String::in::Empty));
}

void MissingMemberException___::ctor() {
}

void MissingMemberException___::ctor(String message) {
}

void MissingMemberException___::ctor(String message, Exception inner) {
}

void MissingMemberException___::ctor(String className, String memberName) {
  ClassName = className;
  MemberName = memberName;
}

void MissingMemberException___::ctor(SerializationInfo info, StreamingContext context) {
  ClassName = info->GetString("MMClassName");
  MemberName = info->GetString("MMMemberName");
}

void MissingMemberException___::GetObjectData(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::MissingMemberExceptionNamespace
