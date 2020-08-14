#include "COMException-dep.h"

#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/Text/StringBuilder-dep.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::COMExceptionNamespace {
using namespace System::Globalization;
using namespace System::Text;

void COMException___::ctor() {
}

void COMException___::ctor(String message) {
}

void COMException___::ctor(String message, Exception inner) {
}

void COMException___::ctor(String message, Int32 errorCode) {
}

void COMException___::ctor(SerializationInfo info, StreamingContext context) {
}

String COMException___::ToString() {
  StringBuilder stringBuilder = rt::newobj<StringBuilder>();
  String value = GetType()->ToString();
}

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::COMExceptionNamespace
