#include "DataMisalignedException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::DataMisalignedExceptionNamespace {
void DataMisalignedException___::ctor() {
  Exception::set_HResult = -2146233023;
}

void DataMisalignedException___::ctor(String message) {
  Exception::set_HResult = -2146233023;
}

void DataMisalignedException___::ctor(String message, Exception innerException) {
  Exception::set_HResult = -2146233023;
}

void DataMisalignedException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::DataMisalignedExceptionNamespace
