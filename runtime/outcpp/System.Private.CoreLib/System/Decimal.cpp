#include "Decimal-dep.h"

#include <System.Private.CoreLib/System/Decimal-dep.h>

namespace System::Private::CoreLib::System::DecimalNamespace {
UInt64 Decimal::DecCalc::Buf24::get_Low64() {
  return UInt64();
};
void Decimal::DecCalc::Buf24::set_Low64(UInt64 value) {
  return void();
};
void Decimal::DecCalc::Buf24::set_Mid64(UInt64 value) {
  return void();
};
void Decimal::DecCalc::Buf24::set_High64(UInt64 value) {
  return void();
};
UInt64 Decimal::DecCalc::Buf12::get_Low64() {
  return UInt64();
};
void Decimal::DecCalc::Buf12::set_Low64(UInt64 value) {
  return void();
};
UInt64 Decimal::DecCalc::Buf12::get_High64() {
  return UInt64();
};
void Decimal::DecCalc::Buf12::set_High64(UInt64 value) {
  return void();
};
UInt64 Decimal::DecCalc::Buf16::get_Low64() {
  return UInt64();
};
void Decimal::DecCalc::Buf16::set_Low64(UInt64 value) {
  return void();
};
UInt64 Decimal::DecCalc::Buf16::get_High64() {
  return UInt64();
};
void Decimal::DecCalc::Buf16::set_High64(UInt64 value) {
  return void();
};
UInt32 Decimal::DecCalc::get_High() {
  return UInt32();
};
void Decimal::DecCalc::set_High(UInt32 value) {
  return void();
};
UInt32 Decimal::DecCalc::get_Low() {
  return UInt32();
};
void Decimal::DecCalc::set_Low(UInt32 value) {
  return void();
};
UInt32 Decimal::DecCalc::get_Mid() {
  return UInt32();
};
void Decimal::DecCalc::set_Mid(UInt32 value) {
  return void();
};
Boolean Decimal::DecCalc::get_IsNegative() {
  return Boolean();
};
Int32 Decimal::DecCalc::get_Scale() {
  return Int32();
};
UInt64 Decimal::DecCalc::get_Low64() {
  return UInt64();
};
void Decimal::DecCalc::set_Low64(UInt64 value) {
  return void();
};
UInt32 Decimal::DecCalc::GetExponent(Single f) {
  return UInt32();
};
UInt32 Decimal::DecCalc::GetExponent(Double d) {
  return UInt32();
};
UInt64 Decimal::DecCalc::UInt32x32To64(UInt32 a, UInt32 b) {
  return UInt64();
};
void Decimal::DecCalc::UInt64x64To128(UInt64 a, UInt64 b, DecCalc& result) {
  return void();
};
UInt32 Decimal::DecCalc::Div96By32(Buf12& bufNum, UInt32 den) {
  return UInt32();
};
Boolean Decimal::DecCalc::Div96ByConst(UInt64& high64, UInt32& low, UInt32 pow) {
  return Boolean();
};
void Decimal::DecCalc::Unscale(UInt32& low, UInt64& high64, Int32& scale) {
  return void();
};
UInt32 Decimal::DecCalc::Div96By64(Buf12& bufNum, UInt64 den) {
  return UInt32();
};
UInt32 Decimal::DecCalc::Div128By96(Buf16& bufNum, Buf12& bufDen) {
  return UInt32();
};
UInt32 Decimal::DecCalc::IncreaseScale(Buf12& bufNum, UInt32 power) {
  return UInt32();
};
void Decimal::DecCalc::IncreaseScale64(Buf12& bufNum, UInt32 power) {
  return void();
};
Int32 Decimal::DecCalc::ScaleResult(Buf24* bufRes, UInt32 hiRes, Int32 scale) {
  return Int32();
};
UInt32 Decimal::DecCalc::DivByConst(UInt32* result, UInt32 hiRes, UInt32& quotient, UInt32& remainder, UInt32 power) {
  return UInt32();
};
Int32 Decimal::DecCalc::OverflowUnscale(Buf12& bufQuo, Int32 scale, Boolean sticky) {
  return Int32();
};
Int32 Decimal::DecCalc::SearchScale(Buf12& bufQuo, Int32 scale) {
  return Int32();
};
Boolean Decimal::DecCalc::Add32To96(Buf12& bufNum, UInt32 value) {
  return Boolean();
};
void Decimal::DecCalc::DecAddSub(DecCalc& d1, DecCalc& d2, Boolean sign) {
  return void();
};
Int64 Decimal::DecCalc::VarCyFromDec(DecCalc& pdecIn) {
  return Int64();
};
Int32 Decimal::DecCalc::VarDecCmp(Decimal& d1, Decimal& d2) {
  return Int32();
};
Int32 Decimal::DecCalc::VarDecCmpSub(Decimal& d1, Decimal& d2) {
  return Int32();
};
void Decimal::DecCalc::VarDecMul(DecCalc& d1, DecCalc& d2) {
  return void();
};
void Decimal::DecCalc::VarDecFromR4(Single input, DecCalc& result) {
  return void();
};
void Decimal::DecCalc::VarDecFromR8(Double input, DecCalc& result) {
  return void();
};
Single Decimal::DecCalc::VarR4FromDec(Decimal& value) {
  return Single();
};
Double Decimal::DecCalc::VarR8FromDec(Decimal& value) {
  return Double();
};
Int32 Decimal::DecCalc::GetHashCode(Decimal& d) {
  return Int32();
};
void Decimal::DecCalc::VarDecDiv(DecCalc& d1, DecCalc& d2) {
  return void();
};
void Decimal::DecCalc::VarDecMod(DecCalc& d1, DecCalc& d2) {
  return void();
};
void Decimal::DecCalc::VarDecModFull(DecCalc& d1, DecCalc& d2, Int32 scale) {
  return void();
};
void Decimal::DecCalc::InternalRound(DecCalc& d, UInt32 scale, MidpointRounding mode) {
  return void();
};
UInt32 Decimal::DecCalc::DecDivMod1E9(DecCalc& value) {
  return UInt32();
};
UInt32 Decimal::get_High() {
  return UInt32();
};
UInt32 Decimal::get_Low() {
  return UInt32();
};
UInt32 Decimal::get_Mid() {
  return UInt32();
};
Boolean Decimal::get_IsNegative() {
  return Boolean();
};
Int32 Decimal::get_Scale() {
  return Int32();
};
UInt64 Decimal::get_Low64() {
  return UInt64();
};
Decimal Decimal::FromOACurrency(Int64 cy) {
  return Decimal();
};
Int64 Decimal::ToOACurrency(Decimal value) {
  return Int64();
};
Boolean Decimal::IsValid(Int32 flags) {
  return Boolean();
};
Decimal Decimal::Abs(Decimal& d) {
  return Decimal();
};
Decimal Decimal::Add(Decimal d1, Decimal d2) {
  return Decimal();
};
Decimal Decimal::Ceiling(Decimal d) {
  return Decimal();
};
Int32 Decimal::Compare(Decimal d1, Decimal d2) {
  return Int32();
};
Int32 Decimal::CompareTo(Object value) {
  return Int32();
};
Int32 Decimal::CompareTo(Decimal value) {
  return Int32();
};
Decimal Decimal::Divide(Decimal d1, Decimal d2) {
  return Decimal();
};
Boolean Decimal::Equals(Object value) {
  return Boolean();
};
Boolean Decimal::Equals(Decimal value) {
  return Boolean();
};
Int32 Decimal::GetHashCode() {
  return Int32();
};
Boolean Decimal::Equals(Decimal d1, Decimal d2) {
  return Boolean();
};
Decimal Decimal::Floor(Decimal d) {
  return Decimal();
};
String Decimal::ToString() {
  return nullptr;
};
String Decimal::ToString(String format) {
  return nullptr;
};
String Decimal::ToString(IFormatProvider provider) {
  return nullptr;
};
String Decimal::ToString(String format, IFormatProvider provider) {
  return nullptr;
};
Boolean Decimal::TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider provider) {
  return Boolean();
};
Decimal Decimal::Parse(String s) {
  return Decimal();
};
Decimal Decimal::Parse(String s, NumberStyles style) {
  return Decimal();
};
Decimal Decimal::Parse(String s, IFormatProvider provider) {
  return Decimal();
};
Decimal Decimal::Parse(String s, NumberStyles style, IFormatProvider provider) {
  return Decimal();
};
Decimal Decimal::Parse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider) {
  return Decimal();
};
Boolean Decimal::TryParse(String s, Decimal& result) {
  return Boolean();
};
Boolean Decimal::TryParse(ReadOnlySpan<Char> s, Decimal& result) {
  return Boolean();
};
Boolean Decimal::TryParse(String s, NumberStyles style, IFormatProvider provider, Decimal& result) {
  return Boolean();
};
Boolean Decimal::TryParse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider, Decimal& result) {
  return Boolean();
};
Array<Int32> Decimal::GetBits(Decimal d) {
  return Array<Int32>();
};
void Decimal::GetBytes(Decimal& d, Array<Byte> buffer) {
  return void();
};
Decimal Decimal::ToDecimal(ReadOnlySpan<Byte> span) {
  return Decimal();
};
Decimal Decimal::Remainder(Decimal d1, Decimal d2) {
  return Decimal();
};
Decimal Decimal::Multiply(Decimal d1, Decimal d2) {
  return Decimal();
};
Decimal Decimal::Negate(Decimal d) {
  return Decimal();
};
Decimal Decimal::Round(Decimal d) {
  return Decimal();
};
Decimal Decimal::Round(Decimal d, Int32 decimals) {
  return Decimal();
};
Decimal Decimal::Round(Decimal d, MidpointRounding mode) {
  return Decimal();
};
Decimal Decimal::Round(Decimal d, Int32 decimals, MidpointRounding mode) {
  return Decimal();
};
Decimal Decimal::Round(Decimal& d, Int32 decimals, MidpointRounding mode) {
  return Decimal();
};
Int32 Decimal::Sign(Decimal& d) {
  return Int32();
};
Decimal Decimal::Subtract(Decimal d1, Decimal d2) {
  return Decimal();
};
Byte Decimal::ToByte(Decimal value) {
  return Byte();
};
SByte Decimal::ToSByte(Decimal value) {
  return SByte();
};
Int16 Decimal::ToInt16(Decimal value) {
  return Int16();
};
Double Decimal::ToDouble(Decimal d) {
  return Double();
};
Int32 Decimal::ToInt32(Decimal d) {
  return Int32();
};
Int64 Decimal::ToInt64(Decimal d) {
  return Int64();
};
UInt16 Decimal::ToUInt16(Decimal value) {
  return UInt16();
};
UInt32 Decimal::ToUInt32(Decimal d) {
  return UInt32();
};
UInt64 Decimal::ToUInt64(Decimal d) {
  return UInt64();
};
Single Decimal::ToSingle(Decimal d) {
  return Single();
};
Decimal Decimal::Truncate(Decimal d) {
  return Decimal();
};
void Decimal::Truncate(Decimal& d) {
  return void();
};
TypeCode Decimal::GetTypeCode() {
  return TypeCode();
};
UInt32 Decimal::DecDivMod1E9(Decimal& value) {
  return UInt32();
};
} // namespace System::Private::CoreLib::System::DecimalNamespace