#include "NotFiniteNumberException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::NotFiniteNumberExceptionNamespace {
Double NotFiniteNumberException___::get_OffendingNumber() {
  return _offendingNumber;
}

void NotFiniteNumberException___::ctor() {
  _offendingNumber = 0;
  Exception::set_HResult = -2146233048;
}

void NotFiniteNumberException___::ctor(Double offendingNumber) {
  _offendingNumber = offendingNumber;
  Exception::set_HResult = -2146233048;
}

void NotFiniteNumberException___::ctor(String message) {
  _offendingNumber = 0;
  Exception::set_HResult = -2146233048;
}

void NotFiniteNumberException___::ctor(String message, Double offendingNumber) {
  _offendingNumber = offendingNumber;
  Exception::set_HResult = -2146233048;
}

void NotFiniteNumberException___::ctor(String message, Exception innerException) {
  Exception::set_HResult = -2146233048;
}

void NotFiniteNumberException___::ctor(String message, Double offendingNumber, Exception innerException) {
  _offendingNumber = offendingNumber;
  Exception::set_HResult = -2146233048;
}

void NotFiniteNumberException___::ctor(SerializationInfo info, StreamingContext context) {
  _offendingNumber = info->GetDouble("OffendingNumber");
}

void NotFiniteNumberException___::GetObjectData(SerializationInfo info, StreamingContext context) {
  Exception::GetObjectData(info, context);
  info->AddValue("OffendingNumber", _offendingNumber, rt::typeof<Double>());
}

} // namespace System::Private::CoreLib::System::NotFiniteNumberExceptionNamespace
