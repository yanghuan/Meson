#include "NumberFormatInfo-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Globalization/CharUnicodeInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/NumberFormatInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/UnicodeCategory.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Globalization::NumberFormatInfoNamespace {
Boolean NumberFormatInfo___::get_HasInvariantNumberSigns() {
  return _hasInvariantNumberSigns;
}

NumberFormatInfo NumberFormatInfo___::get_InvariantInfo() {
  Object obj = s_invariantInfo;
  if (obj == nullptr) {
    obj = rt::newobj<NumberFormatInfo>();
    s_invariantInfo = (NumberFormatInfo)obj;
  }
  return (NumberFormatInfo)obj;
}

Int32 NumberFormatInfo___::get_CurrencyDecimalDigits() {
  return _currencyDecimalDigits;
}

void NumberFormatInfo___::set_CurrencyDecimalDigits(Int32 value) {
  if (value < 0 || value > 99) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", value, SR::Format(SR::get_ArgumentOutOfRange_Range(), 0, 99));
  }
  VerifyWritable();
  _currencyDecimalDigits = value;
}

String NumberFormatInfo___::get_CurrencyDecimalSeparator() {
  return _currencyDecimalSeparator;
}

void NumberFormatInfo___::set_CurrencyDecimalSeparator(String value) {
  VerifyWritable();
  VerifyDecimalSeparator(value, "value");
  _currencyDecimalSeparator = value;
}

Boolean NumberFormatInfo___::get_IsReadOnly() {
  return _isReadOnly;
}

Array<Int32> NumberFormatInfo___::get_CurrencyGroupSizes() {
  return (Array<Int32>)_currencyGroupSizes->Clone();
}

void NumberFormatInfo___::set_CurrencyGroupSizes(Array<Int32> value) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  VerifyWritable();
  Array<Int32> array = (Array<Int32>)value->Clone();
  CheckGroupSize("value", array);
  _currencyGroupSizes = array;
}

Array<Int32> NumberFormatInfo___::get_NumberGroupSizes() {
  return (Array<Int32>)_numberGroupSizes->Clone();
}

void NumberFormatInfo___::set_NumberGroupSizes(Array<Int32> value) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  VerifyWritable();
  Array<Int32> array = (Array<Int32>)value->Clone();
  CheckGroupSize("value", array);
  _numberGroupSizes = array;
}

Array<Int32> NumberFormatInfo___::get_PercentGroupSizes() {
  return (Array<Int32>)_percentGroupSizes->Clone();
}

void NumberFormatInfo___::set_PercentGroupSizes(Array<Int32> value) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  VerifyWritable();
  Array<Int32> array = (Array<Int32>)value->Clone();
  CheckGroupSize("value", array);
  _percentGroupSizes = array;
}

String NumberFormatInfo___::get_CurrencyGroupSeparator() {
  return _currencyGroupSeparator;
}

void NumberFormatInfo___::set_CurrencyGroupSeparator(String value) {
  VerifyWritable();
  VerifyGroupSeparator(value, "value");
  _currencyGroupSeparator = value;
}

String NumberFormatInfo___::get_CurrencySymbol() {
  return _currencySymbol;
}

void NumberFormatInfo___::set_CurrencySymbol(String value) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  VerifyWritable();
  _currencySymbol = value;
}

NumberFormatInfo NumberFormatInfo___::get_CurrentInfo() {
  CultureInfo currentCulture = CultureInfo::in::get_CurrentCulture();
  if (!currentCulture->_isInherited) {
    NumberFormatInfo numInfo = currentCulture->_numInfo;
    if (numInfo != nullptr) {
      return numInfo;
    }
  }
  return (NumberFormatInfo)currentCulture->GetFormat(rt::typeof<NumberFormatInfo>());
}

String NumberFormatInfo___::get_NaNSymbol() {
  return _nanSymbol;
}

void NumberFormatInfo___::set_NaNSymbol(String value) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  VerifyWritable();
  _nanSymbol = value;
}

Int32 NumberFormatInfo___::get_CurrencyNegativePattern() {
  return _currencyNegativePattern;
}

void NumberFormatInfo___::set_CurrencyNegativePattern(Int32 value) {
  if (value < 0 || value > 15) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", value, SR::Format(SR::get_ArgumentOutOfRange_Range(), 0, 15));
  }
  VerifyWritable();
  _currencyNegativePattern = value;
}

Int32 NumberFormatInfo___::get_NumberNegativePattern() {
  return _numberNegativePattern;
}

void NumberFormatInfo___::set_NumberNegativePattern(Int32 value) {
  if (value < 0 || value > 4) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", value, SR::Format(SR::get_ArgumentOutOfRange_Range(), 0, 4));
  }
  VerifyWritable();
  _numberNegativePattern = value;
}

Int32 NumberFormatInfo___::get_PercentPositivePattern() {
  return _percentPositivePattern;
}

void NumberFormatInfo___::set_PercentPositivePattern(Int32 value) {
  if (value < 0 || value > 3) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", value, SR::Format(SR::get_ArgumentOutOfRange_Range(), 0, 3));
  }
  VerifyWritable();
  _percentPositivePattern = value;
}

Int32 NumberFormatInfo___::get_PercentNegativePattern() {
  return _percentNegativePattern;
}

void NumberFormatInfo___::set_PercentNegativePattern(Int32 value) {
  if (value < 0 || value > 11) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", value, SR::Format(SR::get_ArgumentOutOfRange_Range(), 0, 11));
  }
  VerifyWritable();
  _percentNegativePattern = value;
}

String NumberFormatInfo___::get_NegativeInfinitySymbol() {
  return _negativeInfinitySymbol;
}

void NumberFormatInfo___::set_NegativeInfinitySymbol(String value) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  VerifyWritable();
  _negativeInfinitySymbol = value;
}

String NumberFormatInfo___::get_NegativeSign() {
  return _negativeSign;
}

void NumberFormatInfo___::set_NegativeSign(String value) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  VerifyWritable();
  _negativeSign = value;
  UpdateHasInvariantNumberSigns();
}

Int32 NumberFormatInfo___::get_NumberDecimalDigits() {
  return _numberDecimalDigits;
}

void NumberFormatInfo___::set_NumberDecimalDigits(Int32 value) {
  if (value < 0 || value > 99) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", value, SR::Format(SR::get_ArgumentOutOfRange_Range(), 0, 99));
  }
  VerifyWritable();
  _numberDecimalDigits = value;
}

String NumberFormatInfo___::get_NumberDecimalSeparator() {
  return _numberDecimalSeparator;
}

void NumberFormatInfo___::set_NumberDecimalSeparator(String value) {
  VerifyWritable();
  VerifyDecimalSeparator(value, "value");
  _numberDecimalSeparator = value;
}

String NumberFormatInfo___::get_NumberGroupSeparator() {
  return _numberGroupSeparator;
}

void NumberFormatInfo___::set_NumberGroupSeparator(String value) {
  VerifyWritable();
  VerifyGroupSeparator(value, "value");
  _numberGroupSeparator = value;
}

Int32 NumberFormatInfo___::get_CurrencyPositivePattern() {
  return _currencyPositivePattern;
}

void NumberFormatInfo___::set_CurrencyPositivePattern(Int32 value) {
  if (value < 0 || value > 3) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", value, SR::Format(SR::get_ArgumentOutOfRange_Range(), 0, 3));
  }
  VerifyWritable();
  _currencyPositivePattern = value;
}

String NumberFormatInfo___::get_PositiveInfinitySymbol() {
  return _positiveInfinitySymbol;
}

void NumberFormatInfo___::set_PositiveInfinitySymbol(String value) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  VerifyWritable();
  _positiveInfinitySymbol = value;
}

String NumberFormatInfo___::get_PositiveSign() {
  return _positiveSign;
}

void NumberFormatInfo___::set_PositiveSign(String value) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  VerifyWritable();
  _positiveSign = value;
  UpdateHasInvariantNumberSigns();
}

Int32 NumberFormatInfo___::get_PercentDecimalDigits() {
  return _percentDecimalDigits;
}

void NumberFormatInfo___::set_PercentDecimalDigits(Int32 value) {
  if (value < 0 || value > 99) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", value, SR::Format(SR::get_ArgumentOutOfRange_Range(), 0, 99));
  }
  VerifyWritable();
  _percentDecimalDigits = value;
}

String NumberFormatInfo___::get_PercentDecimalSeparator() {
  return _percentDecimalSeparator;
}

void NumberFormatInfo___::set_PercentDecimalSeparator(String value) {
  VerifyWritable();
  VerifyDecimalSeparator(value, "value");
  _percentDecimalSeparator = value;
}

String NumberFormatInfo___::get_PercentGroupSeparator() {
  return _percentGroupSeparator;
}

void NumberFormatInfo___::set_PercentGroupSeparator(String value) {
  VerifyWritable();
  VerifyGroupSeparator(value, "value");
  _percentGroupSeparator = value;
}

String NumberFormatInfo___::get_PercentSymbol() {
  return _percentSymbol;
}

void NumberFormatInfo___::set_PercentSymbol(String value) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  VerifyWritable();
  _percentSymbol = value;
}

String NumberFormatInfo___::get_PerMilleSymbol() {
  return _perMilleSymbol;
}

void NumberFormatInfo___::set_PerMilleSymbol(String value) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  VerifyWritable();
  _perMilleSymbol = value;
}

Array<String> NumberFormatInfo___::get_NativeDigits() {
  return (Array<String>)_nativeDigits->Clone();
}

void NumberFormatInfo___::set_NativeDigits(Array<String> value) {
  VerifyWritable();
  VerifyNativeDigits(value, "value");
  _nativeDigits = value;
}

DigitShapes NumberFormatInfo___::get_DigitSubstitution() {
  return (DigitShapes)_digitSubstitution;
}

void NumberFormatInfo___::set_DigitSubstitution(DigitShapes value) {
  VerifyWritable();
  VerifyDigitSubstitution(value, "value");
  _digitSubstitution = (Int32)value;
}

void NumberFormatInfo___::ctor() {
  _numberGroupSizes = rt::newarr<Array<Int32>>(1);
  _currencyGroupSizes = rt::newarr<Array<Int32>>(1);
  _percentGroupSizes = rt::newarr<Array<Int32>>(1);
  _positiveSign = "+";
  _negativeSign = "-";
  _numberDecimalSeparator = ".";
  _numberGroupSeparator = ",";
  _currencyGroupSeparator = ",";
  _currencyDecimalSeparator = ".";
  _currencySymbol = "¤";
  _nanSymbol = "NaN";
  _positiveInfinitySymbol = "Infinity";
  _negativeInfinitySymbol = "-Infinity";
  _percentDecimalSeparator = ".";
  _percentGroupSeparator = ",";
  _percentSymbol = "%";
  _perMilleSymbol = "‰";
  _nativeDigits = rt::newarr<Array<String>>(10);
  _numberDecimalDigits = 2;
  _currencyDecimalDigits = 2;
  _numberNegativePattern = 1;
  _percentDecimalDigits = 2;
  _digitSubstitution = 1;
  _hasInvariantNumberSigns = true;
  Object::in::ctor();
}

void NumberFormatInfo___::VerifyDecimalSeparator(String decSep, String propertyName) {
  if (decSep == nullptr) {
    rt::throw_exception<ArgumentNullException>(propertyName);
  }
  if (decSep->get_Length() == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_EmptyDecString(), propertyName);
  }
}

void NumberFormatInfo___::VerifyGroupSeparator(String groupSep, String propertyName) {
  if (groupSep == nullptr) {
    rt::throw_exception<ArgumentNullException>(propertyName);
  }
}

void NumberFormatInfo___::VerifyNativeDigits(Array<String> nativeDig, String propertyName) {
  if (nativeDig == nullptr) {
    rt::throw_exception<ArgumentNullException>(propertyName, SR::get_ArgumentNull_Array());
  }
  if (nativeDig->get_Length() != 10) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidNativeDigitCount(), propertyName);
  }
  for (Int32 i = 0; i < nativeDig->get_Length(); i++) {
    if (nativeDig[i] == nullptr) {
      rt::throw_exception<ArgumentNullException>(propertyName, SR::get_ArgumentNull_ArrayValue());
    }
    if (nativeDig[i]->get_Length() != 1) {
      if (nativeDig[i]->get_Length() != 2) {
        rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidNativeDigitValue(), propertyName);
      }
      if (!Char::IsSurrogatePair(nativeDig[i][0], nativeDig[i][1])) {
        rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidNativeDigitValue(), propertyName);
      }
    }
    if (CharUnicodeInfo::GetDecimalDigitValue(nativeDig[i], 0) != i && CharUnicodeInfo::GetUnicodeCategory(nativeDig[i], 0) != UnicodeCategory::PrivateUse) {
      rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidNativeDigitValue(), propertyName);
    }
  }
}

void NumberFormatInfo___::VerifyDigitSubstitution(DigitShapes digitSub, String propertyName) {
  if ((UInt32)digitSub > 2u) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidDigitSubstitution(), propertyName);
  }
}

void NumberFormatInfo___::UpdateHasInvariantNumberSigns() {
  _hasInvariantNumberSigns = (_positiveSign == "+" && _negativeSign == "-");
}

void NumberFormatInfo___::ctor(CultureData cultureData) {
  _numberGroupSizes = rt::newarr<Array<Int32>>(1);
  _currencyGroupSizes = rt::newarr<Array<Int32>>(1);
  _percentGroupSizes = rt::newarr<Array<Int32>>(1);
  _positiveSign = "+";
  _negativeSign = "-";
  _numberDecimalSeparator = ".";
  _numberGroupSeparator = ",";
  _currencyGroupSeparator = ",";
  _currencyDecimalSeparator = ".";
  _currencySymbol = "¤";
  _nanSymbol = "NaN";
  _positiveInfinitySymbol = "Infinity";
  _negativeInfinitySymbol = "-Infinity";
  _percentDecimalSeparator = ".";
  _percentGroupSeparator = ",";
  _percentSymbol = "%";
  _perMilleSymbol = "‰";
  _nativeDigits = rt::newarr<Array<String>>(10);
  _numberDecimalDigits = 2;
  _currencyDecimalDigits = 2;
  _numberNegativePattern = 1;
  _percentDecimalDigits = 2;
  _digitSubstitution = 1;
  _hasInvariantNumberSigns = true;
  Object::in::ctor();
  if (cultureData != nullptr) {
    cultureData->GetNFIValues((NumberFormatInfo)this);
    UpdateHasInvariantNumberSigns();
  }
}

void NumberFormatInfo___::VerifyWritable() {
  if (_isReadOnly) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_ReadOnly());
  }
}

NumberFormatInfo NumberFormatInfo___::GetInstance(IFormatProvider formatProvider) {
  auto GetProviderNonNull = [](IFormatProvider provider) -> NumberFormatInfo {
    CultureInfo cultureInfo = rt::as<CultureInfo>(provider);
    if (cultureInfo != nullptr && !cultureInfo->_isInherited) {
      NumberFormatInfo as = cultureInfo->_numInfo;
      return as != nullptr ? as : cultureInfo->get_NumberFormat();
    }
    ? as = (rt::as<NumberFormatInfo>(provider->GetFormat(rt::typeof<NumberFormatInfo>())));
    ? as = (rt::as<NumberFormatInfo>(provider));
    return as != nullptr ? as : as != nullptr ? as : get_CurrentInfo();
  };
  if (formatProvider != nullptr) {
    return GetProviderNonNull(formatProvider);
  }
  return get_CurrentInfo();
}

Object NumberFormatInfo___::Clone() {
  NumberFormatInfo numberFormatInfo = (NumberFormatInfo)MemberwiseClone();
  numberFormatInfo->_isReadOnly = false;
  return numberFormatInfo;
}

void NumberFormatInfo___::CheckGroupSize(String propName, Array<Int32> groupSize) {
  for (Int32 i = 0; i < groupSize->get_Length(); i++) {
    if (groupSize[i] < 1) {
      if (i == groupSize->get_Length() - 1 && groupSize[i] == 0) {
        break;
      }
      rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidGroupSize(), propName);
    }
    if (groupSize[i] > 9) {
      rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidGroupSize(), propName);
    }
  }
}

Object NumberFormatInfo___::GetFormat(Type formatType) {
  if (!(formatType == rt::typeof<NumberFormatInfo>())) {
    return nullptr;
  }
  return (NumberFormatInfo)this;
}

NumberFormatInfo NumberFormatInfo___::ReadOnly(NumberFormatInfo nfi) {
  if (nfi == nullptr) {
    rt::throw_exception<ArgumentNullException>("nfi");
  }
  if (nfi->get_IsReadOnly()) {
    return nfi;
  }
  NumberFormatInfo numberFormatInfo = (NumberFormatInfo)nfi->MemberwiseClone();
  numberFormatInfo->_isReadOnly = true;
  return numberFormatInfo;
}

void NumberFormatInfo___::ValidateParseStyleInteger(NumberStyles style) {
  auto throwInvalid = [](NumberStyles value) -> void {
    if ((value & ~(NumberStyles::AllowLeadingWhite | NumberStyles::AllowTrailingWhite | NumberStyles::AllowLeadingSign | NumberStyles::AllowTrailingSign | NumberStyles::AllowParentheses | NumberStyles::AllowDecimalPoint | NumberStyles::AllowThousands | NumberStyles::AllowExponent | NumberStyles::AllowCurrencySymbol | NumberStyles::AllowHexSpecifier)) != 0) {
      rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidNumberStyles(), "style");
    }
    rt::throw_exception<ArgumentException>(SR::get_Arg_InvalidHexStyle());
  };
  if ((style & ~(NumberStyles::AllowLeadingWhite | NumberStyles::AllowTrailingWhite | NumberStyles::AllowLeadingSign | NumberStyles::AllowTrailingSign | NumberStyles::AllowParentheses | NumberStyles::AllowDecimalPoint | NumberStyles::AllowThousands | NumberStyles::AllowExponent | NumberStyles::AllowCurrencySymbol)) != 0 && (style & ~(NumberStyles::AllowLeadingWhite | NumberStyles::AllowTrailingWhite | NumberStyles::AllowHexSpecifier)) != 0) {
    throwInvalid(style);
  }
}

void NumberFormatInfo___::ValidateParseStyleFloatingPoint(NumberStyles style) {
  auto throwInvalid = [](NumberStyles value) -> void {
    if ((value & ~(NumberStyles::AllowLeadingWhite | NumberStyles::AllowTrailingWhite | NumberStyles::AllowLeadingSign | NumberStyles::AllowTrailingSign | NumberStyles::AllowParentheses | NumberStyles::AllowDecimalPoint | NumberStyles::AllowThousands | NumberStyles::AllowExponent | NumberStyles::AllowCurrencySymbol | NumberStyles::AllowHexSpecifier)) != 0) {
      rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidNumberStyles(), "style");
    }
    rt::throw_exception<ArgumentException>(SR::get_Arg_HexStyleNotSupported());
  };
  if ((style & ~(NumberStyles::AllowLeadingWhite | NumberStyles::AllowTrailingWhite | NumberStyles::AllowLeadingSign | NumberStyles::AllowTrailingSign | NumberStyles::AllowParentheses | NumberStyles::AllowDecimalPoint | NumberStyles::AllowThousands | NumberStyles::AllowExponent | NumberStyles::AllowCurrencySymbol)) != 0) {
    throwInvalid(style);
  }
}

} // namespace System::Private::CoreLib::System::Globalization::NumberFormatInfoNamespace
