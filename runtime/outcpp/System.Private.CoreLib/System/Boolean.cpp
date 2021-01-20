#include "Boolean-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/Convert-dep.h>
#include <System.Private.CoreLib/System/FormatException-dep.h>
#include <System.Private.CoreLib/System/InvalidCastException-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::BooleanNamespace {
Int32 Boolean::GetHashCode() {
  if (!*this) {
    return 0;
  }
  return 1;
}

String Boolean::ToString() {
  if (!*this) {
    return "False";
  }
  return "True";
}

String Boolean::ToString(IFormatProvider provider) {
  return ToString();
}

Boolean Boolean::TryFormat(Span<Char> destination, Int32& charsWritten) {
  if (*this) {
    if ((UInt32)destination.get_Length() > 3u) {
      destination[0] = u'T';
      destination[1] = u'r';
      destination[2] = u'u';
      destination[3] = u'e';
      charsWritten = 4;
      return true;
    }
  } else if ((UInt32)destination.get_Length() > 4u) {
    destination[0] = u'F';
    destination[1] = u'a';
    destination[2] = u'l';
    destination[3] = u's';
    destination[4] = u'e';
    charsWritten = 5;
    return true;
  }

  charsWritten = 0;
  return false;
}

Boolean Boolean::Equals(Object obj) {
  if (!rt::is<Boolean>(obj)) {
    return false;
  }
  return *this == (Boolean)obj;
}

Boolean Boolean::Equals(Boolean obj) {
  return *this == obj;
}

Int32 Boolean::CompareTo(Object obj) {
  if (obj == nullptr) {
    return 1;
  }
  if (!rt::is<Boolean>(obj)) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeBoolean());
  }
  if (*this == (Boolean)obj) {
    return 0;
  }
  if (!*this) {
    return -1;
  }
  return 1;
}

Int32 Boolean::CompareTo(Boolean value) {
  if (*this == value) {
    return 0;
  }
  if (!*this) {
    return -1;
  }
  return 1;
}

Boolean Boolean::IsTrueStringIgnoreCase(ReadOnlySpan<Char> value) {
  if (value.get_Length() == 4 && (value[0] == u't' || value[0] == u'T') && (value[1] == u'r' || value[1] == u'R') && (value[2] == u'u' || value[2] == u'U')) {
    if (value[3] != u'e') {
      return value[3] == u'E';
    }
    return true;
  }
  return false;
}

Boolean Boolean::IsFalseStringIgnoreCase(ReadOnlySpan<Char> value) {
  if (value.get_Length() == 5 && (value[0] == u'f' || value[0] == u'F') && (value[1] == u'a' || value[1] == u'A') && (value[2] == u'l' || value[2] == u'L') && (value[3] == u's' || value[3] == u'S')) {
    if (value[4] != u'e') {
      return value[4] == u'E';
    }
    return true;
  }
  return false;
}

Boolean Boolean::Parse(String value) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  return Parse(MemoryExtensions::AsSpan(value));
}

Boolean Boolean::Parse(ReadOnlySpan<Char> value) {
  Boolean result;
  if (!TryParse(value, result)) {
    rt::throw_exception<FormatException>(SR::Format(SR::get_Format_BadBoolean(), rt::newstr<String>(value)));
  }
  return result;
}

Boolean Boolean::TryParse(String value, Boolean& result) {
  if (value == nullptr) {
    result = false;
    return false;
  }
  return TryParse(MemoryExtensions::AsSpan(value), result);
}

Boolean Boolean::TryParse(ReadOnlySpan<Char> value, Boolean& result) {
  if (IsTrueStringIgnoreCase(value)) {
    result = true;
    return true;
  }
  if (IsFalseStringIgnoreCase(value)) {
    result = false;
    return true;
  }
  value = TrimWhiteSpaceAndNull(value);
  if (IsTrueStringIgnoreCase(value)) {
    result = true;
    return true;
  }
  if (IsFalseStringIgnoreCase(value)) {
    result = false;
    return true;
  }
  result = false;
  return false;
}

ReadOnlySpan<Char> Boolean::TrimWhiteSpaceAndNull(ReadOnlySpan<Char> value) {
  Int32 i;
  for (i = 0; i < value.get_Length() && (Char::IsWhiteSpace(value[i]) || value[i] == u'\0'); i++) {
  }
  Int32 num = value.get_Length() - 1;
  while (num >= i && (Char::IsWhiteSpace(value[num]) || value[num] == u'\0')) {
    num--;
  }
  return value.Slice(i, num - i + 1);
}

TypeCode Boolean::GetTypeCode() {
  return TypeCode::Boolean;
}

Boolean Boolean::ToBooleanOfIConvertible(IFormatProvider provider) {
  return *this;
}

Char Boolean::ToCharOfIConvertible(IFormatProvider provider) {
  rt::throw_exception<InvalidCastException>(SR::Format(SR::get_InvalidCast_FromTo(), "Boolean", "Char"));
}

SByte Boolean::ToSByteOfIConvertible(IFormatProvider provider) {
  return Convert::ToSByte(*this);
}

Byte Boolean::ToByteOfIConvertible(IFormatProvider provider) {
  return Convert::ToByte(*this);
}

Int16 Boolean::ToInt16OfIConvertible(IFormatProvider provider) {
  return Convert::ToInt16(*this);
}

UInt16 Boolean::ToUInt16OfIConvertible(IFormatProvider provider) {
  return Convert::ToUInt16(*this);
}

Int32 Boolean::ToInt32OfIConvertible(IFormatProvider provider) {
  return Convert::ToInt32(*this);
}

UInt32 Boolean::ToUInt32OfIConvertible(IFormatProvider provider) {
  return Convert::ToUInt32(*this);
}

Int64 Boolean::ToInt64OfIConvertible(IFormatProvider provider) {
  return Convert::ToInt64(*this);
}

UInt64 Boolean::ToUInt64OfIConvertible(IFormatProvider provider) {
  return Convert::ToUInt64(*this);
}

Single Boolean::ToSingleOfIConvertible(IFormatProvider provider) {
  return Convert::ToSingle(*this);
}

Double Boolean::ToDoubleOfIConvertible(IFormatProvider provider) {
  return Convert::ToDouble(*this);
}

Decimal Boolean::ToDecimalOfIConvertible(IFormatProvider provider) {
  return Convert::ToDecimal(*this);
}

DateTime Boolean::ToDateTimeOfIConvertible(IFormatProvider provider) {
  rt::throw_exception<InvalidCastException>(SR::Format(SR::get_InvalidCast_FromTo(), "Boolean", "DateTime"));
}

Object Boolean::ToTypeOfIConvertible(Type type, IFormatProvider provider) {
  return Convert::DefaultToType(*this, type, provider);
}

void Boolean::cctor() {
  TrueString = "True";
  FalseString = "False";
}

} // namespace System::Private::CoreLib::System::BooleanNamespace
