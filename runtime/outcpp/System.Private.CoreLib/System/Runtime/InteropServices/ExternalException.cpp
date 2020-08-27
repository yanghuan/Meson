#include "ExternalException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::ExternalExceptionNamespace {
using namespace System::Globalization;

Int32 ExternalException___::get_ErrorCode() {
  return Exception::in::get_HResult();
}

void ExternalException___::ctor() {
  Exception::in::set_HResult(-2147467259);
}

void ExternalException___::ctor(String message) {
  Exception::in::set_HResult(-2147467259);
}

void ExternalException___::ctor(String message, Exception inner) {
  Exception::in::set_HResult(-2147467259);
}

void ExternalException___::ctor(String message, Int32 errorCode) {
  Exception::in::set_HResult(errorCode);
}

void ExternalException___::ctor(SerializationInfo info, StreamingContext context) {
}

String ExternalException___::ToString() {
  String message = get_Message();
  String str = GetType()->ToString();
  String text = str + " (0x" + Exception::in::get_HResult().ToString("X8", CultureInfo::in::get_InvariantCulture()) + ")";
  if (!String::in::IsNullOrEmpty(message)) {
    text = text + ": " + message;
  }
  Exception innerException = Exception::in::get_InnerException();
  if (innerException != nullptr) {
    text = text + "\r\n ---> " + innerException->ToString();
  }
  if (get_StackTrace() != nullptr) {
    text = text + "\r\n" + get_StackTrace();
  }
  return text;
}

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ExternalExceptionNamespace
