#include "Single-dep.h"

#include <System.Private.CoreLib/System/Single-dep.h>

namespace System::Private::CoreLib::System::SingleNamespace {
Boolean Single::IsFinite(Single f) {
  return Boolean();
}

Boolean Single::IsInfinity(Single f) {
  return Boolean();
}

Boolean Single::IsNaN(Single f) {
  return Boolean();
}

Boolean Single::IsNegative(Single f) {
  return Boolean();
}

Boolean Single::IsNegativeInfinity(Single f) {
  return Boolean();
}

Boolean Single::IsNormal(Single f) {
  return Boolean();
}

Boolean Single::IsPositiveInfinity(Single f) {
  return Boolean();
}

Boolean Single::IsSubnormal(Single f) {
  return Boolean();
}

Int32 Single::ExtractExponentFromBits(UInt32 bits) {
  return Int32();
}

UInt32 Single::ExtractSignificandFromBits(UInt32 bits) {
  return UInt32();
}

Int32 Single::CompareTo(Object value) {
  return Int32();
}

Int32 Single::CompareTo(Single value) {
  return Int32();
}

Boolean Single::op_Equality(Single left, Single right) {
  return Boolean();
}

Boolean Single::op_Inequality(Single left, Single right) {
  return Boolean();
}

Boolean Single::op_LessThan(Single left, Single right) {
  return Boolean();
}

Boolean Single::op_GreaterThan(Single left, Single right) {
  return Boolean();
}

Boolean Single::op_LessThanOrEqual(Single left, Single right) {
  return Boolean();
}

Boolean Single::op_GreaterThanOrEqual(Single left, Single right) {
  return Boolean();
}

Boolean Single::Equals(Object obj) {
  return Boolean();
}

Boolean Single::Equals(Single obj) {
  return Boolean();
}

Int32 Single::GetHashCode() {
  return Int32();
}

String Single::ToString() {
  return nullptr;
}

String Single::ToString(IFormatProvider provider) {
  return nullptr;
}

String Single::ToString(String format) {
  return nullptr;
}

String Single::ToString(String format, IFormatProvider provider) {
  return nullptr;
}

Boolean Single::TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider provider) {
  return Boolean();
}

Single Single::Parse(String s) {
  return Single();
}

Single Single::Parse(String s, NumberStyles style) {
  return Single();
}

Single Single::Parse(String s, IFormatProvider provider) {
  return Single();
}

Single Single::Parse(String s, NumberStyles style, IFormatProvider provider) {
  return Single();
}

Single Single::Parse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider) {
  return Single();
}

Boolean Single::TryParse(String s, Single& result) {
  return Boolean();
}

Boolean Single::TryParse(ReadOnlySpan<Char> s, Single& result) {
  return Boolean();
}

Boolean Single::TryParse(String s, NumberStyles style, IFormatProvider provider, Single& result) {
  return Boolean();
}

Boolean Single::TryParse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider, Single& result) {
  return Boolean();
}

Boolean Single::TryParse(ReadOnlySpan<Char> s, NumberStyles style, NumberFormatInfo info, Single& result) {
  return Boolean();
}

TypeCode Single::GetTypeCode() {
  return TypeCode::String;
}

} // namespace System::Private::CoreLib::System::SingleNamespace
