#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(IFormatProvider)
FORWARD(Object)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
enum class DigitShapes;
enum class NumberStyles;
FORWARD(CultureData)
namespace NumberFormatInfoNamespace {
CLASS(NumberFormatInfo) {
  public: Boolean get_HasInvariantNumberSigns();
  public: static NumberFormatInfo get_InvariantInfo();
  public: Int32 get_CurrencyDecimalDigits();
  public: void set_CurrencyDecimalDigits(Int32 value);
  public: String get_CurrencyDecimalSeparator();
  public: void set_CurrencyDecimalSeparator(String value);
  public: Boolean get_IsReadOnly();
  public: Array<Int32> get_CurrencyGroupSizes();
  public: void set_CurrencyGroupSizes(Array<Int32> value);
  public: Array<Int32> get_NumberGroupSizes();
  public: void set_NumberGroupSizes(Array<Int32> value);
  public: Array<Int32> get_PercentGroupSizes();
  public: void set_PercentGroupSizes(Array<Int32> value);
  public: String get_CurrencyGroupSeparator();
  public: void set_CurrencyGroupSeparator(String value);
  public: String get_CurrencySymbol();
  public: void set_CurrencySymbol(String value);
  public: static NumberFormatInfo get_CurrentInfo();
  public: String get_NaNSymbol();
  public: void set_NaNSymbol(String value);
  public: Int32 get_CurrencyNegativePattern();
  public: void set_CurrencyNegativePattern(Int32 value);
  public: Int32 get_NumberNegativePattern();
  public: void set_NumberNegativePattern(Int32 value);
  public: Int32 get_PercentPositivePattern();
  public: void set_PercentPositivePattern(Int32 value);
  public: Int32 get_PercentNegativePattern();
  public: void set_PercentNegativePattern(Int32 value);
  public: String get_NegativeInfinitySymbol();
  public: void set_NegativeInfinitySymbol(String value);
  public: String get_NegativeSign();
  public: void set_NegativeSign(String value);
  public: Int32 get_NumberDecimalDigits();
  public: void set_NumberDecimalDigits(Int32 value);
  public: String get_NumberDecimalSeparator();
  public: void set_NumberDecimalSeparator(String value);
  public: String get_NumberGroupSeparator();
  public: void set_NumberGroupSeparator(String value);
  public: Int32 get_CurrencyPositivePattern();
  public: void set_CurrencyPositivePattern(Int32 value);
  public: String get_PositiveInfinitySymbol();
  public: void set_PositiveInfinitySymbol(String value);
  public: String get_PositiveSign();
  public: void set_PositiveSign(String value);
  public: Int32 get_PercentDecimalDigits();
  public: void set_PercentDecimalDigits(Int32 value);
  public: String get_PercentDecimalSeparator();
  public: void set_PercentDecimalSeparator(String value);
  public: String get_PercentGroupSeparator();
  public: void set_PercentGroupSeparator(String value);
  public: String get_PercentSymbol();
  public: void set_PercentSymbol(String value);
  public: String get_PerMilleSymbol();
  public: void set_PerMilleSymbol(String value);
  public: Array<String> get_NativeDigits();
  public: void set_NativeDigits(Array<String> value);
  public: DigitShapes get_DigitSubstitution();
  public: void set_DigitSubstitution(DigitShapes value);
  public: void Ctor();
  private: static void VerifyDecimalSeparator(String decSep, String propertyName);
  private: static void VerifyGroupSeparator(String groupSep, String propertyName);
  private: static void VerifyNativeDigits(Array<String> nativeDig, String propertyName);
  private: static void VerifyDigitSubstitution(DigitShapes digitSub, String propertyName);
  private: void UpdateHasInvariantNumberSigns();
  public: void Ctor(CultureData cultureData);
  private: void VerifyWritable();
  public: static NumberFormatInfo GetInstance(IFormatProvider formatProvider);
  public: Object Clone();
  public: static void CheckGroupSize(String propName, Array<Int32> groupSize);
  public: Object GetFormat(Type formatType);
  public: static NumberFormatInfo ReadOnly(NumberFormatInfo nfi);
  public: static void ValidateParseStyleInteger(NumberStyles style);
  public: static void ValidateParseStyleFloatingPoint(NumberStyles style);
  private: static NumberFormatInfo s_invariantInfo;
  public: Array<Int32> _numberGroupSizes;
  public: Array<Int32> _currencyGroupSizes;
  public: Array<Int32> _percentGroupSizes;
  public: String _positiveSign;
  public: String _negativeSign;
  public: String _numberDecimalSeparator;
  public: String _numberGroupSeparator;
  public: String _currencyGroupSeparator;
  public: String _currencyDecimalSeparator;
  public: String _currencySymbol;
  public: String _nanSymbol;
  public: String _positiveInfinitySymbol;
  public: String _negativeInfinitySymbol;
  public: String _percentDecimalSeparator;
  public: String _percentGroupSeparator;
  public: String _percentSymbol;
  public: String _perMilleSymbol;
  public: Array<String> _nativeDigits;
  public: Int32 _numberDecimalDigits;
  public: Int32 _currencyDecimalDigits;
  public: Int32 _currencyPositivePattern;
  public: Int32 _currencyNegativePattern;
  public: Int32 _numberNegativePattern;
  public: Int32 _percentPositivePattern;
  public: Int32 _percentNegativePattern;
  public: Int32 _percentDecimalDigits;
  public: Int32 _digitSubstitution;
  public: Boolean _isReadOnly;
  private: Boolean _hasInvariantNumberSigns;
};
} // namespace NumberFormatInfoNamespace
using NumberFormatInfo = NumberFormatInfoNamespace::NumberFormatInfo;
} // namespace System::Private::CoreLib::System::Globalization
