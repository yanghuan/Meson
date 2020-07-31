#include "DateTimeResult-dep.h"

namespace System::Private::CoreLib::System::DateTimeResultNamespace {
void DateTimeResult::Init(ReadOnlySpan<Char> originalDateTimeString) {
}

void DateTimeResult::SetDate(Int32 year, Int32 month, Int32 day) {
}

void DateTimeResult::SetBadFormatSpecifierFailure() {
}

void DateTimeResult::SetBadFormatSpecifierFailure(ReadOnlySpan<Char> failedFormatSpecifier) {
}

void DateTimeResult::SetBadDateTimeFailure() {
}

void DateTimeResult::SetFailure(ParseFailureKind failure, String failureMessageID) {
}

void DateTimeResult::SetFailure(ParseFailureKind failure, String failureMessageID, Object failureMessageFormatArgument) {
}

void DateTimeResult::SetFailure(ParseFailureKind failure, String failureMessageID, Object failureMessageFormatArgument, String failureArgumentName) {
}

} // namespace System::Private::CoreLib::System::DateTimeResultNamespace
