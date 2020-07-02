#include "TimeSpan-dep.h"

#include <System.Private.CoreLib/System/TimeSpan-dep.h>

namespace System::Private::CoreLib::System::TimeSpanNamespace {
Int64 TimeSpan::get_Ticks() {
  return Int64();
};
Int32 TimeSpan::get_Days() {
  return Int32();
};
Int32 TimeSpan::get_Hours() {
  return Int32();
};
Int32 TimeSpan::get_Milliseconds() {
  return Int32();
};
Int32 TimeSpan::get_Minutes() {
  return Int32();
};
Int32 TimeSpan::get_Seconds() {
  return Int32();
};
Double TimeSpan::get_TotalDays() {
  return Double();
};
Double TimeSpan::get_TotalHours() {
  return Double();
};
Double TimeSpan::get_TotalMilliseconds() {
  return Double();
};
Double TimeSpan::get_TotalMinutes() {
  return Double();
};
Double TimeSpan::get_TotalSeconds() {
  return Double();
};
TimeSpan TimeSpan::Add(TimeSpan ts) {
  return TimeSpan();
};
Int32 TimeSpan::Compare(TimeSpan t1, TimeSpan t2) {
  return Int32();
};
Int32 TimeSpan::CompareTo(Object value) {
  return Int32();
};
Int32 TimeSpan::CompareTo(TimeSpan value) {
  return Int32();
};
TimeSpan TimeSpan::FromDays(Double value) {
  return TimeSpan();
};
TimeSpan TimeSpan::Duration() {
  return TimeSpan();
};
Boolean TimeSpan::Equals(Object value) {
  return Boolean();
};
Boolean TimeSpan::Equals(TimeSpan obj) {
  return Boolean();
};
Boolean TimeSpan::Equals(TimeSpan t1, TimeSpan t2) {
  return Boolean();
};
Int32 TimeSpan::GetHashCode() {
  return Int32();
};
TimeSpan TimeSpan::FromHours(Double value) {
  return TimeSpan();
};
TimeSpan TimeSpan::Interval(Double value, Double scale) {
  return TimeSpan();
};
TimeSpan TimeSpan::FromMilliseconds(Double value) {
  return TimeSpan();
};
TimeSpan TimeSpan::FromMinutes(Double value) {
  return TimeSpan();
};
TimeSpan TimeSpan::Negate() {
  return TimeSpan();
};
TimeSpan TimeSpan::FromSeconds(Double value) {
  return TimeSpan();
};
TimeSpan TimeSpan::Subtract(TimeSpan ts) {
  return TimeSpan();
};
TimeSpan TimeSpan::Multiply(Double factor) {
  return TimeSpan();
};
TimeSpan TimeSpan::Divide(Double divisor) {
  return TimeSpan();
};
Double TimeSpan::Divide(TimeSpan ts) {
  return Double();
};
TimeSpan TimeSpan::FromTicks(Int64 value) {
  return TimeSpan();
};
Int64 TimeSpan::TimeToTicks(Int32 hour, Int32 minute, Int32 second) {
  return Int64();
};
void TimeSpan::ValidateStyles(TimeSpanStyles style, String parameterName) {
  return void();
};
TimeSpan TimeSpan::Parse(String s) {
  return TimeSpan();
};
TimeSpan TimeSpan::Parse(String input, IFormatProvider formatProvider) {
  return TimeSpan();
};
TimeSpan TimeSpan::Parse(ReadOnlySpan<Char> input, IFormatProvider formatProvider) {
  return TimeSpan();
};
TimeSpan TimeSpan::ParseExact(String input, String format, IFormatProvider formatProvider) {
  return TimeSpan();
};
TimeSpan TimeSpan::ParseExact(String input, Array<String> formats, IFormatProvider formatProvider) {
  return TimeSpan();
};
TimeSpan TimeSpan::ParseExact(String input, String format, IFormatProvider formatProvider, TimeSpanStyles styles) {
  return TimeSpan();
};
TimeSpan TimeSpan::ParseExact(ReadOnlySpan<Char> input, ReadOnlySpan<Char> format, IFormatProvider formatProvider, TimeSpanStyles styles) {
  return TimeSpan();
};
TimeSpan TimeSpan::ParseExact(String input, Array<String> formats, IFormatProvider formatProvider, TimeSpanStyles styles) {
  return TimeSpan();
};
TimeSpan TimeSpan::ParseExact(ReadOnlySpan<Char> input, Array<String> formats, IFormatProvider formatProvider, TimeSpanStyles styles) {
  return TimeSpan();
};
Boolean TimeSpan::TryParse(String s, TimeSpan& result) {
  return Boolean();
};
Boolean TimeSpan::TryParse(ReadOnlySpan<Char> s, TimeSpan& result) {
  return Boolean();
};
Boolean TimeSpan::TryParse(String input, IFormatProvider formatProvider, TimeSpan& result) {
  return Boolean();
};
Boolean TimeSpan::TryParse(ReadOnlySpan<Char> input, IFormatProvider formatProvider, TimeSpan& result) {
  return Boolean();
};
Boolean TimeSpan::TryParseExact(String input, String format, IFormatProvider formatProvider, TimeSpan& result) {
  return Boolean();
};
Boolean TimeSpan::TryParseExact(ReadOnlySpan<Char> input, ReadOnlySpan<Char> format, IFormatProvider formatProvider, TimeSpan& result) {
  return Boolean();
};
Boolean TimeSpan::TryParseExact(String input, Array<String> formats, IFormatProvider formatProvider, TimeSpan& result) {
  return Boolean();
};
Boolean TimeSpan::TryParseExact(ReadOnlySpan<Char> input, Array<String> formats, IFormatProvider formatProvider, TimeSpan& result) {
  return Boolean();
};
Boolean TimeSpan::TryParseExact(String input, String format, IFormatProvider formatProvider, TimeSpanStyles styles, TimeSpan& result) {
  return Boolean();
};
Boolean TimeSpan::TryParseExact(ReadOnlySpan<Char> input, ReadOnlySpan<Char> format, IFormatProvider formatProvider, TimeSpanStyles styles, TimeSpan& result) {
  return Boolean();
};
Boolean TimeSpan::TryParseExact(String input, Array<String> formats, IFormatProvider formatProvider, TimeSpanStyles styles, TimeSpan& result) {
  return Boolean();
};
Boolean TimeSpan::TryParseExact(ReadOnlySpan<Char> input, Array<String> formats, IFormatProvider formatProvider, TimeSpanStyles styles, TimeSpan& result) {
  return Boolean();
};
String TimeSpan::ToString() {
  return nullptr;
};
String TimeSpan::ToString(String format) {
  return nullptr;
};
String TimeSpan::ToString(String format, IFormatProvider formatProvider) {
  return nullptr;
};
Boolean TimeSpan::TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider formatProvider) {
  return Boolean();
};
} // namespace System::Private::CoreLib::System::TimeSpanNamespace
