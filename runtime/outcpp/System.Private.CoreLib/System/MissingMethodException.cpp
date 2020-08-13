#include "MissingMethodException-dep.h"

#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::MissingMethodExceptionNamespace {
String MissingMethodException___::get_Message() {
  if (ClassName != nullptr) {
    return SR::Format(SR::get_MissingMethod_Name(), ClassName + "." + MemberName + ((Signature != nullptr) ? (" " + MissingMemberException::in::FormatSignature(Signature)) : String::in::Empty));
  }
}

void MissingMethodException___::ctor() {
}

void MissingMethodException___::ctor(String message) {
}

void MissingMethodException___::ctor(String message, Exception inner) {
}

void MissingMethodException___::ctor(String className, String methodName) {
  ClassName = className;
  MemberName = methodName;
}

void MissingMethodException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::MissingMethodExceptionNamespace
