#include "COMException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/Text/StringBuilder-dep.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::COMExceptionNamespace {
using namespace System::Globalization;
using namespace System::Text;

void COMException___::ctor() {
  Exception::in::set_HResult = -2147467259;
}

void COMException___::ctor(String message) {
  Exception::in::set_HResult = -2147467259;
}

void COMException___::ctor(String message, Exception inner) {
  Exception::in::set_HResult = -2147467259;
}

void COMException___::ctor(String message, Int32 errorCode) {
  Exception::in::set_HResult = errorCode;
}

void COMException___::ctor(SerializationInfo info, StreamingContext context) {
}

String COMException___::ToString() {
  StringBuilder stringBuilder = rt::newobj<StringBuilder>();
  String value = GetType()->ToString();
  stringBuilder->Append(value)->Append(" (0x")->Append(Exception::in::get_HResult().ToString("X8", CultureInfo::in::get_InvariantCulture()))->Append(41);
  String message = get_Message();
  if (!String::in::IsNullOrEmpty(message)) {
    stringBuilder->Append(": ")->Append(message);
  }
  Exception innerException = Exception::in::get_InnerException();
  if (innerException != nullptr) {
    stringBuilder->Append("
 ---> ")->Append(innerException->ToString());
  }
  String stackTrace = get_StackTrace();
  if (stackTrace != nullptr) {
    stringBuilder->AppendLine()->Append(stackTrace);
  }
  return stringBuilder->ToString();
}

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::COMExceptionNamespace
