#include "Double-dep.h"

#include <System.Private.CoreLib/System/Double-dep.h>

namespace System::Private::CoreLib::System::DoubleNamespace {
Boolean Double::IsFinite(Double d) {
  return Boolean();
};
Boolean Double::IsInfinity(Double d) {
  return Boolean();
};
Boolean Double::IsNaN(Double d) {
  return Boolean();
};
Boolean Double::IsNegative(Double d) {
  return Boolean();
};
Boolean Double::IsNegativeInfinity(Double d) {
  return Boolean();
};
Boolean Double::IsNormal(Double d) {
  return Boolean();
};
Boolean Double::IsPositiveInfinity(Double d) {
  return Boolean();
};
Boolean Double::IsSubnormal(Double d) {
  return Boolean();
};
Int32 Double::ExtractExponentFromBits(UInt64 bits) {
  return Int32();
};
UInt64 Double::ExtractSignificandFromBits(UInt64 bits) {
  return UInt64();
};
Int32 Double::CompareTo(Object value) {
  return Int32();
};
Int32 Double::CompareTo(Double value) {
  return Int32();
};
Boolean Double::Equals(Object obj) {
  return Boolean();
};
Boolean Double::Equals(Double obj) {
  return Boolean();
};
Int32 Double::GetHashCode() {
  return Int32();
};
String Double::ToString() {
  return nullptr;
};
String Double::ToString(String format) {
  return nullptr;
};
String Double::ToString(IFormatProvider provider) {
  return nullptr;
};
String Double::ToString(String format, IFormatProvider provider) {
  return nullptr;
};
Boolean Double::TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider provider) {
  return Boolean();
};
Double Double::Parse(String s) {
  return Double();
};
Double Double::Parse(String s, NumberStyles style) {
  return Double();
};
Double Double::Parse(String s, IFormatProvider provider) {
  return Double();
};
Double Double::Parse(String s, NumberStyles style, IFormatProvider provider) {
  return Double();
};
Double Double::Parse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider) {
  return Double();
};
Boolean Double::TryParse(String s, Double& result) {
  return Boolean();
};
Boolean Double::TryParse(ReadOnlySpan<Char> s, Double& result) {
  return Boolean();
};
Boolean Double::TryParse(String s, NumberStyles style, IFormatProvider provider, Double& result) {
  return Boolean();
};
Boolean Double::TryParse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider, Double& result) {
  return Boolean();
};
Boolean Double::TryParse(ReadOnlySpan<Char> s, NumberStyles style, NumberFormatInfo info, Double& result) {
  return Boolean();
};
TypeCode Double::GetTypeCode() {
  return TypeCode();
};
} // namespace System::Private::CoreLib::System::DoubleNamespace
