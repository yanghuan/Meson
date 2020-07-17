#include "NumberFormatInfo-dep.h"

#include <System.Private.CoreLib/System/Globalization/NumberFormatInfo-dep.h>

namespace System::Private::CoreLib::System::Globalization::NumberFormatInfoNamespace {
Boolean NumberFormatInfo___::get_HasInvariantNumberSigns() {
  return Boolean();
};

NumberFormatInfo NumberFormatInfo___::get_InvariantInfo() {
  return nullptr;
};

Int32 NumberFormatInfo___::get_CurrencyDecimalDigits() {
  return Int32();
};

void NumberFormatInfo___::set_CurrencyDecimalDigits(Int32 value) {
};

String NumberFormatInfo___::get_CurrencyDecimalSeparator() {
  return nullptr;
};

void NumberFormatInfo___::set_CurrencyDecimalSeparator(String value) {
};

Boolean NumberFormatInfo___::get_IsReadOnly() {
  return Boolean();
};

Array<Int32> NumberFormatInfo___::get_CurrencyGroupSizes() {
  return Array<Int32>();
};

void NumberFormatInfo___::set_CurrencyGroupSizes(Array<Int32> value) {
};

Array<Int32> NumberFormatInfo___::get_NumberGroupSizes() {
  return Array<Int32>();
};

void NumberFormatInfo___::set_NumberGroupSizes(Array<Int32> value) {
};

Array<Int32> NumberFormatInfo___::get_PercentGroupSizes() {
  return Array<Int32>();
};

void NumberFormatInfo___::set_PercentGroupSizes(Array<Int32> value) {
};

String NumberFormatInfo___::get_CurrencyGroupSeparator() {
  return nullptr;
};

void NumberFormatInfo___::set_CurrencyGroupSeparator(String value) {
};

String NumberFormatInfo___::get_CurrencySymbol() {
  return nullptr;
};

void NumberFormatInfo___::set_CurrencySymbol(String value) {
};

NumberFormatInfo NumberFormatInfo___::get_CurrentInfo() {
  return nullptr;
};

String NumberFormatInfo___::get_NaNSymbol() {
  return nullptr;
};

void NumberFormatInfo___::set_NaNSymbol(String value) {
};

Int32 NumberFormatInfo___::get_CurrencyNegativePattern() {
  return Int32();
};

void NumberFormatInfo___::set_CurrencyNegativePattern(Int32 value) {
};

Int32 NumberFormatInfo___::get_NumberNegativePattern() {
  return Int32();
};

void NumberFormatInfo___::set_NumberNegativePattern(Int32 value) {
};

Int32 NumberFormatInfo___::get_PercentPositivePattern() {
  return Int32();
};

void NumberFormatInfo___::set_PercentPositivePattern(Int32 value) {
};

Int32 NumberFormatInfo___::get_PercentNegativePattern() {
  return Int32();
};

void NumberFormatInfo___::set_PercentNegativePattern(Int32 value) {
};

String NumberFormatInfo___::get_NegativeInfinitySymbol() {
  return nullptr;
};

void NumberFormatInfo___::set_NegativeInfinitySymbol(String value) {
};

String NumberFormatInfo___::get_NegativeSign() {
  return nullptr;
};

void NumberFormatInfo___::set_NegativeSign(String value) {
};

Int32 NumberFormatInfo___::get_NumberDecimalDigits() {
  return Int32();
};

void NumberFormatInfo___::set_NumberDecimalDigits(Int32 value) {
};

String NumberFormatInfo___::get_NumberDecimalSeparator() {
  return nullptr;
};

void NumberFormatInfo___::set_NumberDecimalSeparator(String value) {
};

String NumberFormatInfo___::get_NumberGroupSeparator() {
  return nullptr;
};

void NumberFormatInfo___::set_NumberGroupSeparator(String value) {
};

Int32 NumberFormatInfo___::get_CurrencyPositivePattern() {
  return Int32();
};

void NumberFormatInfo___::set_CurrencyPositivePattern(Int32 value) {
};

String NumberFormatInfo___::get_PositiveInfinitySymbol() {
  return nullptr;
};

void NumberFormatInfo___::set_PositiveInfinitySymbol(String value) {
};

String NumberFormatInfo___::get_PositiveSign() {
  return nullptr;
};

void NumberFormatInfo___::set_PositiveSign(String value) {
};

Int32 NumberFormatInfo___::get_PercentDecimalDigits() {
  return Int32();
};

void NumberFormatInfo___::set_PercentDecimalDigits(Int32 value) {
};

String NumberFormatInfo___::get_PercentDecimalSeparator() {
  return nullptr;
};

void NumberFormatInfo___::set_PercentDecimalSeparator(String value) {
};

String NumberFormatInfo___::get_PercentGroupSeparator() {
  return nullptr;
};

void NumberFormatInfo___::set_PercentGroupSeparator(String value) {
};

String NumberFormatInfo___::get_PercentSymbol() {
  return nullptr;
};

void NumberFormatInfo___::set_PercentSymbol(String value) {
};

String NumberFormatInfo___::get_PerMilleSymbol() {
  return nullptr;
};

void NumberFormatInfo___::set_PerMilleSymbol(String value) {
};

Array<String> NumberFormatInfo___::get_NativeDigits() {
  return Array<String>();
};

void NumberFormatInfo___::set_NativeDigits(Array<String> value) {
};

DigitShapes NumberFormatInfo___::get_DigitSubstitution() {
  return DigitShapes::NativeNational;
};

void NumberFormatInfo___::set_DigitSubstitution(DigitShapes value) {
};

void NumberFormatInfo___::Ctor() {
};

void NumberFormatInfo___::VerifyDecimalSeparator(String decSep, String propertyName) {
};

void NumberFormatInfo___::VerifyGroupSeparator(String groupSep, String propertyName) {
};

void NumberFormatInfo___::VerifyNativeDigits(Array<String> nativeDig, String propertyName) {
};

void NumberFormatInfo___::VerifyDigitSubstitution(DigitShapes digitSub, String propertyName) {
};

void NumberFormatInfo___::UpdateHasInvariantNumberSigns() {
};

void NumberFormatInfo___::Ctor(CultureData cultureData) {
};

void NumberFormatInfo___::VerifyWritable() {
};

NumberFormatInfo NumberFormatInfo___::GetInstance(IFormatProvider formatProvider) {
  return nullptr;
};

Object NumberFormatInfo___::Clone() {
  return nullptr;
};

void NumberFormatInfo___::CheckGroupSize(String propName, Array<Int32> groupSize) {
};

Object NumberFormatInfo___::GetFormat(Type formatType) {
  return nullptr;
};

NumberFormatInfo NumberFormatInfo___::ReadOnly(NumberFormatInfo nfi) {
  return nullptr;
};

void NumberFormatInfo___::ValidateParseStyleInteger(NumberStyles style) {
};

void NumberFormatInfo___::ValidateParseStyleFloatingPoint(NumberStyles style) {
};

} // namespace System::Private::CoreLib::System::Globalization::NumberFormatInfoNamespace
