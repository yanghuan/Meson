#include "OperationCanceledException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::OperationCanceledExceptionNamespace {
CancellationToken OperationCanceledException___::get_CancellationToken() {
  return _cancellationToken;
}

void OperationCanceledException___::set_CancellationToken(CancellationToken value) {
  _cancellationToken = value;
}

void OperationCanceledException___::ctor() {
  Exception::set_HResult = -2146233029;
}

void OperationCanceledException___::ctor(String message) {
  Exception::set_HResult = -2146233029;
}

void OperationCanceledException___::ctor(String message, Exception innerException) {
  Exception::set_HResult = -2146233029;
}

void OperationCanceledException___::ctor(CancellationToken token) {
  get_CancellationToken() = token;
}

void OperationCanceledException___::ctor(String message, CancellationToken token) {
  get_CancellationToken() = token;
}

void OperationCanceledException___::ctor(String message, Exception innerException, CancellationToken token) {
  get_CancellationToken() = token;
}

void OperationCanceledException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::OperationCanceledExceptionNamespace
