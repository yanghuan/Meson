#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Char.h>
#include <System.Private.CoreLib/System/DateTime.h>
#include <System.Private.CoreLib/System/Double.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/ReadOnlySpan.h>
#include <System.Private.CoreLib/System/TimeSpan.h>

namespace System::Private::CoreLib::System::Globalization {
FORWARD(Calendar)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System {
enum class ParseFailureKind;
FORWARD(String)
FORWARD(Object)
enum class ParseFlags;
namespace DateTimeResultNamespace {
using namespace ::System::Private::CoreLib::System::Globalization;
struct DateTimeResult {
  public: void Init(ReadOnlySpan<Char> originalDateTimeString);
  public: void SetDate(Int32 year, Int32 month, Int32 day);
  public: void SetBadFormatSpecifierFailure();
  public: void SetBadFormatSpecifierFailure(ReadOnlySpan<Char> failedFormatSpecifier);
  public: void SetBadDateTimeFailure();
  public: void SetFailure(ParseFailureKind failure, String failureMessageID);
  public: void SetFailure(ParseFailureKind failure, String failureMessageID, Object failureMessageFormatArgument);
  public: void SetFailure(ParseFailureKind failure, String failureMessageID, Object failureMessageFormatArgument, String failureArgumentName);
  public: Int32 Year;
  public: Int32 Month;
  public: Int32 Day;
  public: Int32 Hour;
  public: Int32 Minute;
  public: Int32 Second;
  public: Double fraction;
  public: Int32 era;
  public: ParseFlags flags;
  public: TimeSpan timeZoneOffset;
  public: Calendar calendar;
  public: DateTime parsedDate;
  public: ParseFailureKind failure;
  public: String failureMessageID;
  public: Object failureMessageFormatArgument;
  public: String failureArgumentName;
  public: ReadOnlySpan<Char> originalDateTimeString;
  public: ReadOnlySpan<Char> failedFormatSpecifier;
};
} // namespace DateTimeResultNamespace
using DateTimeResult = DateTimeResultNamespace::DateTimeResult;
} // namespace System::Private::CoreLib::System
