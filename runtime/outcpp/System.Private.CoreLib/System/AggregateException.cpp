#include "AggregateException-dep.h"

#include <System.Private.CoreLib/System/AggregateException-dep.h>

namespace System::Private::CoreLib::System::AggregateExceptionNamespace {
ReadOnlyCollection<Exception> AggregateException___::get_InnerExceptions() {
  return nullptr;
}

String AggregateException___::get_Message() {
  return nullptr;
}

Int32 AggregateException___::get_InnerExceptionCount() {
  return Int32();
}

void AggregateException___::Ctor() {
}

void AggregateException___::Ctor(String message) {
}

void AggregateException___::Ctor(String message, Exception innerException) {
}

void AggregateException___::Ctor(IEnumerable<Exception> innerExceptions) {
}

void AggregateException___::Ctor(Array<Exception> innerExceptions) {
}

void AggregateException___::Ctor(String message, IEnumerable<Exception> innerExceptions) {
}

void AggregateException___::Ctor(String message, Array<Exception> innerExceptions) {
}

void AggregateException___::Ctor(String message, IList<Exception> innerExceptions) {
}

void AggregateException___::Ctor(IEnumerable<ExceptionDispatchInfo> innerExceptionInfos) {
}

void AggregateException___::Ctor(String message, IEnumerable<ExceptionDispatchInfo> innerExceptionInfos) {
}

void AggregateException___::Ctor(String message, IList<ExceptionDispatchInfo> innerExceptionInfos) {
}

void AggregateException___::Ctor(SerializationInfo info, StreamingContext context) {
}

void AggregateException___::GetObjectData(SerializationInfo info, StreamingContext context) {
}

Exception AggregateException___::GetBaseException() {
  return nullptr;
}

void AggregateException___::Handle(Func<Exception, Boolean> predicate) {
}

AggregateException AggregateException___::Flatten() {
  return nullptr;
}

String AggregateException___::ToString() {
  return nullptr;
}

} // namespace System::Private::CoreLib::System::AggregateExceptionNamespace
