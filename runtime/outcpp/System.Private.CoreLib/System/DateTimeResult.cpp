#include "DateTimeResult-dep.h"

#include <System.Private.CoreLib/System/ParseFailureKind.h>

namespace System::Private::CoreLib::System::DateTimeResultNamespace {
void DateTimeResult::Init(ReadOnlySpan<Char> originalDateTimeString) {
  this->originalDateTimeString = originalDateTimeString;
  Year = -1;
  Month = -1;
  Day = -1;
  fraction = -1;
  era = -1;
}

void DateTimeResult::SetDate(Int32 year, Int32 month, Int32 day) {
  Year = year;
  Month = month;
  Day = day;
}

void DateTimeResult::SetBadFormatSpecifierFailure() {
  SetBadFormatSpecifierFailure(ReadOnlySpan<Char>::get_Empty());
}

void DateTimeResult::SetBadFormatSpecifierFailure(ReadOnlySpan<Char> failedFormatSpecifier) {
  failure = ParseFailureKind::FormatWithFormatSpecifier;
  failureMessageID = "Format_BadFormatSpecifier";
  this->failedFormatSpecifier = failedFormatSpecifier;
}

void DateTimeResult::SetBadDateTimeFailure() {
  failure = ParseFailureKind::FormatWithOriginalDateTime;
  failureMessageID = "Format_BadDateTime";
  failureMessageFormatArgument = nullptr;
}

void DateTimeResult::SetFailure(ParseFailureKind failure, String failureMessageID) {
  this->failure = failure;
  this->failureMessageID = failureMessageID;
  failureMessageFormatArgument = nullptr;
}

void DateTimeResult::SetFailure(ParseFailureKind failure, String failureMessageID, Object failureMessageFormatArgument) {
  this->failure = failure;
  this->failureMessageID = failureMessageID;
  this->failureMessageFormatArgument = failureMessageFormatArgument;
}

void DateTimeResult::SetFailure(ParseFailureKind failure, String failureMessageID, Object failureMessageFormatArgument, String failureArgumentName) {
  this->failure = failure;
  this->failureMessageID = failureMessageID;
  this->failureMessageFormatArgument = failureMessageFormatArgument;
  this->failureArgumentName = failureArgumentName;
}

} // namespace System::Private::CoreLib::System::DateTimeResultNamespace
