#include "ExternalException-dep.h"

#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::ExternalExceptionNamespace {
using namespace System::Globalization;

Int32 ExternalException___::get_ErrorCode() {
}

void ExternalException___::ctor() {
}

void ExternalException___::ctor(String message) {
}

void ExternalException___::ctor(String message, Exception inner) {
}

void ExternalException___::ctor(String message, Int32 errorCode) {
}

void ExternalException___::ctor(SerializationInfo info, StreamingContext context) {
}

String ExternalException___::ToString() {
  String message = get_Message();
  String str = GetType()->ToString();
}

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ExternalExceptionNamespace
