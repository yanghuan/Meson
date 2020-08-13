#include "Boolean-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Boolean-dep.h>
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
      destination[0] = 84;
      destination[1] = 114;
      destination[2] = 117;
      destination[3] = 101;
      charsWritten = 4;
      return true;
    }
  } else if ((UInt32)destination.get_Length() > 4u) {
    destination[0] = 70;
    destination[1] = 97;
    destination[2] = 108;
    destination[3] = 115;
    destination[4] = 101;
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
  if (value.get_Length() == 4 && (value[0] == 116 || value[0] == 84) && (value[1] == 114 || value[1] == 82) && (value[2] == 117 || value[2] == 85)) {
    if (value[3] != 101) {
      return value[3] == 69;
    }
    return true;
  }
  return false;
}

Boolean Boolean::IsFalseStringIgnoreCase(ReadOnlySpan<Char> value) {
  if (value.get_Length() == 5 && (value[0] == 102 || value[0] == 70) && (value[1] == 97 || value[1] == 65) && (value[2] == 108 || value[2] == 76) && (value[3] == 115 || value[3] == 83)) {
    if (value[4] != 101) {
      return value[4] == 69;
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
  for (i = 0; i < value.get_Length() && (Char::IsWhiteSpace(value[i]) || value[i] == 0); i++) {
  }
  Int32 num = value.get_Length() - 1;
  while (num >= i && (Char::IsWhiteSpace(value[num]) || value[num] == 0)) {
    num--;
  }
  return value.Slice(i, num - i + 1);
}

TypeCode Boolean::GetTypeCode() {
  return TypeCode::Boolean;
}

void Boolean::ctor_static() {
  TrueString = "True";
  FalseString = "False";
}

} // namespace System::Private::CoreLib::System::BooleanNamespace
