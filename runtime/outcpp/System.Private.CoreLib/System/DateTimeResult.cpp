#include "DateTimeResult-dep.h"

namespace System::Private::CoreLib::System::DateTimeResultNamespace {
void DateTimeResult::Init(ReadOnlySpan<Char> originalDateTimeString) {
  return void();
};
void DateTimeResult::SetDate(Int32 year, Int32 month, Int32 day) {
  return void();
};
void DateTimeResult::SetBadFormatSpecifierFailure() {
  return void();
};
void DateTimeResult::SetBadFormatSpecifierFailure(ReadOnlySpan<Char> failedFormatSpecifier) {
  return void();
};
void DateTimeResult::SetBadDateTimeFailure() {
  return void();
};
void DateTimeResult::SetFailure(ParseFailureKind failure, String failureMessageID) {
  return void();
};
void DateTimeResult::SetFailure(ParseFailureKind failure, String failureMessageID, Object failureMessageFormatArgument) {
  return void();
};
void DateTimeResult::SetFailure(ParseFailureKind failure, String failureMessageID, Object failureMessageFormatArgument, String failureArgumentName) {
  return void();
};
} // namespace System::Private::CoreLib::System::DateTimeResultNamespace
