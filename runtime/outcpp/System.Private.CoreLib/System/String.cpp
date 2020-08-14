#include "String-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Buffer-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/ValueListBuilder-dep.h>
#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/ExceptionResource.h>
#include <System.Private.CoreLib/System/Globalization/CompareInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/Normalization-dep.h>
#include <System.Private.CoreLib/System/Globalization/TextInfo-dep.h>
#include <System.Private.CoreLib/System/IndexOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/Marvin-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/Numerics/BitOperations-dep.h>
#include <System.Private.CoreLib/System/Numerics/Vector-dep.h>
#include <System.Private.CoreLib/System/OutOfMemoryException-dep.h>
#include <System.Private.CoreLib/System/ParamsArray-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/SpanHelpers-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/String-dep.h>
#include <System.Private.CoreLib/System/StringComparer-dep.h>
#include <System.Private.CoreLib/System/StringComparison.h>
#include <System.Private.CoreLib/System/Text/ASCIIUtility-dep.h>
#include <System.Private.CoreLib/System/Text/NormalizationForm.h>
#include <System.Private.CoreLib/System/Text/TrimType.h>
#include <System.Private.CoreLib/System/Text/ValueStringBuilder-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>
#include <System.Private.CoreLib/System/UInt16-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>
#include <System.Private.CoreLib/System/UIntPtr-dep.h>

namespace System::Private::CoreLib::System::StringNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Collections::Generic;
using namespace System::Globalization;
using namespace System::Numerics;
using namespace System::Runtime::InteropServices;
using namespace System::Text;

String String___::Intern(String str) {
  if (str == nullptr) {
    rt::throw_exception<ArgumentNullException>("str");
  }
  return str->Intern();
}

String String___::IsInterned(String str) {
  if (str == nullptr) {
    rt::throw_exception<ArgumentNullException>("str");
  }
  return str->IsInterned();
}

void String___::InternalCopy(String src, IntPtr dest, Int32 len) {
  if (len != 0) {
    {
      Char* ptr = &src->_firstChar;
      Byte* src2 = (Byte*)ptr;
      Byte* dest2 = (Byte*)(void*)dest;
      Buffer::Memcpy(dest2, src2, len);
    }
  }
}

Int32 String___::GetBytesFromEncoding(Byte* pbNativeBuffer, Int32 cbNativeBuffer, Encoding encoding) {
  {
    Char* chars = &_firstChar;
    return encoding->GetBytes(chars, get_Length(), pbNativeBuffer, cbNativeBuffer);
  }
}

Boolean String___::EqualsHelper(String strA, String strB) {
  return SpanHelpers::SequenceEqual(Unsafe::As<Char, Byte>(strA->GetRawStringData()), Unsafe::As<Char, Byte>(strB->GetRawStringData()), (UIntPtr)strA->get_Length() * (?)2u);
}

Int32 String___::CompareOrdinalHelper(String strA, Int32 indexA, Int32 countA, String strB, Int32 indexB, Int32 countB) {
  return SpanHelpers::SequenceCompareTo(Unsafe::Add(strA->GetRawStringData(), indexA), countA, Unsafe::Add(strB->GetRawStringData(), indexB), countB);
}

Boolean String___::EqualsOrdinalIgnoreCase(String strA, String strB) {
  return CompareInfo::in::EqualsOrdinalIgnoreCase(strA->GetRawStringData(), strB->GetRawStringData(), strB->get_Length());
}

Int32 String___::CompareOrdinalHelper(String strA, String strB) {
  Int32 num = Math::Min(strA->get_Length(), strB->get_Length());
  {
    Char* ptr = &strA->_firstChar;
    {
      Char* ptr3 = &strB->_firstChar;
      Char* ptr2 = ptr;
      Char* ptr4 = ptr3;
      if (ptr2[1] == ptr4[1]) {
        num -= 2;
        ptr2 += 2;
        ptr4 += 2;
        while (true) {
          if (num >= 12) {
            if (*(Int64*)ptr2 == *(Int64*)ptr4) {
              if (*(Int64*)(ptr2 + 4) == *(Int64*)(ptr4 + 4)) {
                if (*(Int64*)(ptr2 + 8) == *(Int64*)(ptr4 + 8)) {
                  num -= 12;
                  ptr2 += 12;
                  ptr4 += 12;
                  continue;
                }
                ptr2 += 4;
                ptr4 += 4;
              }
              ptr2 += 4;
              ptr4 += 4;
            }
            if (*(Int32*)ptr2 == *(Int32*)ptr4) {
              ptr2 += 2;
              ptr4 += 2;
            }
            break;
          }
          while (true) {
            if (num > 0) {
              if (*(Int32*)ptr2 != *(Int32*)ptr4) {
                break;
              }
              num -= 2;
              ptr2 += 2;
              ptr4 += 2;
              continue;
            }
            return strA->get_Length() - strB->get_Length();
          }
          break;
        }
        if (*ptr2 != *ptr4) {
          return *ptr2 - *ptr4;
        }
      }
      return ptr2[1] - ptr4[1];
    }
  }
}

Int32 String___::Compare(String strA, String strB) {
  return Compare(strA, strB, StringComparison::CurrentCulture);
}

Int32 String___::Compare(String strA, String strB, Boolean ignoreCase) {
  StringComparison comparisonType = ignoreCase ? StringComparison::CurrentCultureIgnoreCase : StringComparison::CurrentCulture;
  return Compare(strA, strB, comparisonType);
}

Int32 String___::Compare(String strA, String strB, StringComparison comparisonType) {
  if ((Object)strA == strB) {
    CheckStringComparison(comparisonType);
    return 0;
  }
  if (strA == nullptr) {
    CheckStringComparison(comparisonType);
    return -1;
  }
  if (strB == nullptr) {
    CheckStringComparison(comparisonType);
    return 1;
  }
  switch (comparisonType) {
    case StringComparison::CurrentCulture:
    case StringComparison::CurrentCultureIgnoreCase:
      return CultureInfo::in::get_CurrentCulture()->get_CompareInfo()->Compare(strA, strB, GetCaseCompareOfComparisonCulture(comparisonType));
    case StringComparison::InvariantCulture:
    case StringComparison::InvariantCultureIgnoreCase:
      return CompareInfo::in::Invariant->Compare(strA, strB, GetCaseCompareOfComparisonCulture(comparisonType));
    case StringComparison::Ordinal:
      if (strA->_firstChar != strB->_firstChar) {
        return strA->_firstChar - strB->_firstChar;
      }
      return CompareOrdinalHelper(strA, strB);
    case StringComparison::OrdinalIgnoreCase:
      return CompareInfo::in::CompareOrdinalIgnoreCase(strA, strB);
    default:
      rt::throw_exception<ArgumentException>(SR::get_NotSupported_StringComparison(), "comparisonType");
  }
}

Int32 String___::Compare(String strA, String strB, CultureInfo culture, CompareOptions options) {
  auto default = culture;
  if (default != nullptr) default = CultureInfo::in::get_CurrentCulture();

  CultureInfo cultureInfo = default;
  return cultureInfo->get_CompareInfo()->Compare(strA, strB, options);
}

Int32 String___::Compare(String strA, String strB, Boolean ignoreCase, CultureInfo culture) {
  CompareOptions options = ignoreCase ? CompareOptions::IgnoreCase : CompareOptions::None;
  return Compare(strA, strB, culture, options);
}

Int32 String___::Compare(String strA, Int32 indexA, String strB, Int32 indexB, Int32 length) {
  return Compare(strA, indexA, strB, indexB, length, false);
}

Int32 String___::Compare(String strA, Int32 indexA, String strB, Int32 indexB, Int32 length, Boolean ignoreCase) {
  Int32 num = length;
  Int32 num2 = length;
  if (strA != nullptr) {
    num = Math::Min(num, strA->get_Length() - indexA);
  }
  if (strB != nullptr) {
    num2 = Math::Min(num2, strB->get_Length() - indexB);
  }
  CompareOptions options = ignoreCase ? CompareOptions::IgnoreCase : CompareOptions::None;
  return CultureInfo::in::get_CurrentCulture()->get_CompareInfo()->Compare(strA, indexA, num, strB, indexB, num2, options);
}

Int32 String___::Compare(String strA, Int32 indexA, String strB, Int32 indexB, Int32 length, Boolean ignoreCase, CultureInfo culture) {
  CompareOptions options = ignoreCase ? CompareOptions::IgnoreCase : CompareOptions::None;
  return Compare(strA, indexA, strB, indexB, length, culture, options);
}

Int32 String___::Compare(String strA, Int32 indexA, String strB, Int32 indexB, Int32 length, CultureInfo culture, CompareOptions options) {
  auto default = culture;
  if (default != nullptr) default = CultureInfo::in::get_CurrentCulture();

  CultureInfo cultureInfo = default;
  Int32 num = length;
  Int32 num2 = length;
  if (strA != nullptr) {
    num = Math::Min(num, strA->get_Length() - indexA);
  }
  if (strB != nullptr) {
    num2 = Math::Min(num2, strB->get_Length() - indexB);
  }
  return cultureInfo->get_CompareInfo()->Compare(strA, indexA, num, strB, indexB, num2, options);
}

Int32 String___::Compare(String strA, Int32 indexA, String strB, Int32 indexB, Int32 length, StringComparison comparisonType) {
  CheckStringComparison(comparisonType);
  if (strA == nullptr || strB == nullptr) {
    if ((Object)strA == strB) {
      return 0;
    }
    if (strA != nullptr) {
      return 1;
    }
    return -1;
  }
  if (length < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("length", SR::get_ArgumentOutOfRange_NegativeLength());
  }
  if (indexA < 0 || indexB < 0) {
    String paramName = (indexA < 0) ? "indexA" : "indexB";
    rt::throw_exception<ArgumentOutOfRangeException>(paramName, SR::get_ArgumentOutOfRange_Index());
  }
  if (strA->get_Length() - indexA < 0 || strB->get_Length() - indexB < 0) {
    String paramName2 = (strA->get_Length() - indexA < 0) ? "indexA" : "indexB";
    rt::throw_exception<ArgumentOutOfRangeException>(paramName2, SR::get_ArgumentOutOfRange_Index());
  }
  if (length == 0 || ((Object)strA == strB && indexA == indexB)) {
    return 0;
  }
  Int32 num = Math::Min(length, strA->get_Length() - indexA);
  Int32 num2 = Math::Min(length, strB->get_Length() - indexB);
  switch (comparisonType) {
    case StringComparison::CurrentCulture:
    case StringComparison::CurrentCultureIgnoreCase:
      return CultureInfo::in::get_CurrentCulture()->get_CompareInfo()->Compare(strA, indexA, num, strB, indexB, num2, GetCaseCompareOfComparisonCulture(comparisonType));
    case StringComparison::InvariantCulture:
    case StringComparison::InvariantCultureIgnoreCase:
      return CompareInfo::in::Invariant->Compare(strA, indexA, num, strB, indexB, num2, GetCaseCompareOfComparisonCulture(comparisonType));
    case StringComparison::Ordinal:
      return CompareOrdinalHelper(strA, indexA, num, strB, indexB, num2);
    default:
      return CompareInfo::in::CompareOrdinalIgnoreCase(strA, indexA, num, strB, indexB, num2);
  }
}

Int32 String___::CompareOrdinal(String strA, String strB) {
  if ((Object)strA == strB) {
    return 0;
  }
  if (strA == nullptr) {
    return -1;
  }
  if (strB == nullptr) {
    return 1;
  }
  if (strA->_firstChar != strB->_firstChar) {
    return strA->_firstChar - strB->_firstChar;
  }
  return CompareOrdinalHelper(strA, strB);
}

Int32 String___::CompareOrdinal(ReadOnlySpan<Char> strA, ReadOnlySpan<Char> strB) {
  return SpanHelpers::SequenceCompareTo(MemoryMarshal::GetReference(strA), strA.get_Length(), MemoryMarshal::GetReference(strB), strB.get_Length());
}

Int32 String___::CompareOrdinal(String strA, Int32 indexA, String strB, Int32 indexB, Int32 length) {
  if (strA == nullptr || strB == nullptr) {
    if ((Object)strA == strB) {
      return 0;
    }
    if (strA != nullptr) {
      return 1;
    }
    return -1;
  }
  if (length < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("length", SR::get_ArgumentOutOfRange_NegativeCount());
  }
  if (indexA < 0 || indexB < 0) {
    String paramName = (indexA < 0) ? "indexA" : "indexB";
    rt::throw_exception<ArgumentOutOfRangeException>(paramName, SR::get_ArgumentOutOfRange_Index());
  }
  Int32 num = Math::Min(length, strA->get_Length() - indexA);
  Int32 num2 = Math::Min(length, strB->get_Length() - indexB);
  if (num < 0 || num2 < 0) {
    String paramName2 = (num < 0) ? "indexA" : "indexB";
    rt::throw_exception<ArgumentOutOfRangeException>(paramName2, SR::get_ArgumentOutOfRange_Index());
  }
  if (length == 0 || ((Object)strA == strB && indexA == indexB)) {
    return 0;
  }
  return CompareOrdinalHelper(strA, indexA, num, strB, indexB, num2);
}

Int32 String___::CompareTo(Object value) {
  if (value == nullptr) {
    return 1;
  }
  String text = rt::as<String>(value);
  if (text == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeString());
  }
  return CompareTo(text);
}

Int32 String___::CompareTo(String strB) {
  return Compare((String)this, strB, StringComparison::CurrentCulture);
}

Boolean String___::EndsWith(String value) {
  return EndsWith(value, StringComparison::CurrentCulture);
}

Boolean String___::EndsWith(String value, StringComparison comparisonType) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  if ((Object)(String)this == value) {
    CheckStringComparison(comparisonType);
    return true;
  }
  if (value->get_Length() == 0) {
    CheckStringComparison(comparisonType);
    return true;
  }
  switch (comparisonType) {
    case StringComparison::CurrentCulture:
    case StringComparison::CurrentCultureIgnoreCase:
      return CultureInfo::in::get_CurrentCulture()->get_CompareInfo()->IsSuffix((String)this, value, GetCaseCompareOfComparisonCulture(comparisonType));
    case StringComparison::InvariantCulture:
    case StringComparison::InvariantCultureIgnoreCase:
      return CompareInfo::in::Invariant->IsSuffix((String)this, value, GetCaseCompareOfComparisonCulture(comparisonType));
    case StringComparison::Ordinal:
      {
        Int32 num = get_Length() - value->get_Length();
        if ((UInt32)num <= (UInt32)get_Length()) {
          return MemoryExtensions::SequenceEqual(MemoryExtensions::AsSpan((String)this, num), value);
        }
        return false;
      }case StringComparison::OrdinalIgnoreCase:
      if (get_Length() >= value->get_Length()) {
        return CompareInfo::in::CompareOrdinalIgnoreCase((String)this, get_Length() - value->get_Length(), value->get_Length(), value, 0, value->get_Length()) == 0;
      }
      return false;
    default:
      rt::throw_exception<ArgumentException>(SR::get_NotSupported_StringComparison(), "comparisonType");
  }
}

Boolean String___::EndsWith(String value, Boolean ignoreCase, CultureInfo culture) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  if ((Object)(String)this == value) {
    return true;
  }
  auto default = culture;
  if (default != nullptr) default = CultureInfo::in::get_CurrentCulture();

  CultureInfo cultureInfo = default;
  return cultureInfo->get_CompareInfo()->IsSuffix((String)this, value, ignoreCase ? CompareOptions::IgnoreCase : CompareOptions::None);
}

Boolean String___::EndsWith(Char value) {
  Int32 num = get_Length() - 1;
  if ((UInt32)num < (UInt32)get_Length()) {
    return (String)this[num] == value;
  }
  return false;
}

Boolean String___::Equals(Object obj) {
  if ((String)this == obj) {
    return true;
  }
  String text = rt::as<String>(obj);
  if (text == nullptr) {
    return false;
  }
  if (get_Length() != text->get_Length()) {
    return false;
  }
  return EqualsHelper((String)this, text);
}

Boolean String___::Equals(String value) {
  if ((Object)(String)this == value) {
    return true;
  }
  if (value == nullptr) {
    return false;
  }
  if (get_Length() != value->get_Length()) {
    return false;
  }
  return EqualsHelper((String)this, value);
}

Boolean String___::Equals(String value, StringComparison comparisonType) {
  if ((Object)(String)this == value) {
    CheckStringComparison(comparisonType);
    return true;
  }
  if (value == nullptr) {
    CheckStringComparison(comparisonType);
    return false;
  }
  switch (comparisonType) {
    case StringComparison::CurrentCulture:
    case StringComparison::CurrentCultureIgnoreCase:
      return CultureInfo::in::get_CurrentCulture()->get_CompareInfo()->Compare((String)this, value, GetCaseCompareOfComparisonCulture(comparisonType)) == 0;
    case StringComparison::InvariantCulture:
    case StringComparison::InvariantCultureIgnoreCase:
      return CompareInfo::in::Invariant->Compare((String)this, value, GetCaseCompareOfComparisonCulture(comparisonType)) == 0;
    case StringComparison::Ordinal:
      if (get_Length() != value->get_Length()) {
        return false;
      }
      return EqualsHelper((String)this, value);
    case StringComparison::OrdinalIgnoreCase:
      if (get_Length() != value->get_Length()) {
        return false;
      }
      return EqualsOrdinalIgnoreCase((String)this, value);
    default:
      rt::throw_exception<ArgumentException>(SR::get_NotSupported_StringComparison(), "comparisonType");
  }
}

Boolean String___::Equals(String a, String b) {
  if ((Object)a == b) {
    return true;
  }
  if (a == nullptr || b == nullptr || a->get_Length() != b->get_Length()) {
    return false;
  }
  return EqualsHelper(a, b);
}

Boolean String___::Equals(String a, String b, StringComparison comparisonType) {
  if ((Object)a == b) {
    CheckStringComparison(comparisonType);
    return true;
  }
  if (a == nullptr || b == nullptr) {
    CheckStringComparison(comparisonType);
    return false;
  }
  switch (comparisonType) {
    case StringComparison::CurrentCulture:
    case StringComparison::CurrentCultureIgnoreCase:
      return CultureInfo::in::get_CurrentCulture()->get_CompareInfo()->Compare(a, b, GetCaseCompareOfComparisonCulture(comparisonType)) == 0;
    case StringComparison::InvariantCulture:
    case StringComparison::InvariantCultureIgnoreCase:
      return CompareInfo::in::Invariant->Compare(a, b, GetCaseCompareOfComparisonCulture(comparisonType)) == 0;
    case StringComparison::Ordinal:
      if (a->get_Length() != b->get_Length()) {
        return false;
      }
      return EqualsHelper(a, b);
    case StringComparison::OrdinalIgnoreCase:
      if (a->get_Length() != b->get_Length()) {
        return false;
      }
      return EqualsOrdinalIgnoreCase(a, b);
    default:
      rt::throw_exception<ArgumentException>(SR::get_NotSupported_StringComparison(), "comparisonType");
  }
}

Boolean String___::op_Equality(String a, String b) {
  return Equals(a, b);
}

Boolean String___::op_Inequality(String a, String b) {
  return !Equals(a, b);
}

Int32 String___::GetHashCode() {
  UInt64 defaultSeed = Marvin::get_DefaultSeed();
  return Marvin::ComputeHash32(Unsafe::As<Char, Byte>(_firstChar), (UInt32)(_stringLength * 2), (UInt32)defaultSeed, (UInt32)(defaultSeed >> 32));
}

Int32 String___::GetHashCode(StringComparison comparisonType) {
  return StringComparer::in::FromComparison(comparisonType)->GetHashCode((String)this);
}

Int32 String___::GetHashCodeOrdinalIgnoreCase() {
  UInt64 defaultSeed = Marvin::get_DefaultSeed();
  return Marvin::ComputeHash32OrdinalIgnoreCase(_firstChar, _stringLength, (UInt32)defaultSeed, (UInt32)(defaultSeed >> 32));
}

Int32 String___::GetHashCode(ReadOnlySpan<Char> value) {
  UInt64 defaultSeed = Marvin::get_DefaultSeed();
  return Marvin::ComputeHash32(Unsafe::As<Char, Byte>(MemoryMarshal::GetReference(value)), (UInt32)(value.get_Length() * 2), (UInt32)defaultSeed, (UInt32)(defaultSeed >> 32));
}

Int32 String___::GetHashCode(ReadOnlySpan<Char> value, StringComparison comparisonType) {
  switch (comparisonType) {
    case StringComparison::CurrentCulture:
    case StringComparison::CurrentCultureIgnoreCase:
      return CultureInfo::in::get_CurrentCulture()->get_CompareInfo()->GetHashCode(value, GetCaseCompareOfComparisonCulture(comparisonType));
    case StringComparison::InvariantCulture:
    case StringComparison::InvariantCultureIgnoreCase:
      return CompareInfo::in::Invariant->GetHashCode(value, GetCaseCompareOfComparisonCulture(comparisonType));
    case StringComparison::Ordinal:
      return GetHashCode(value);
    case StringComparison::OrdinalIgnoreCase:
      return GetHashCodeOrdinalIgnoreCase(value);
    default:
      ThrowHelper::ThrowArgumentException(ExceptionResource::NotSupported_StringComparison, ExceptionArgument::comparisonType);
      return 0;
  }
}

Int32 String___::GetHashCodeOrdinalIgnoreCase(ReadOnlySpan<Char> value) {
  UInt64 defaultSeed = Marvin::get_DefaultSeed();
  return Marvin::ComputeHash32OrdinalIgnoreCase(MemoryMarshal::GetReference(value), value.get_Length(), (UInt32)defaultSeed, (UInt32)(defaultSeed >> 32));
}

Int32 String___::GetNonRandomizedHashCode() {
  {
    Char* ptr = &_firstChar;
    UInt32 num = 352654597u;
    UInt32 num2 = num;
    UInt32* ptr2 = (UInt32*)ptr;
    Int32 num3 = get_Length();
    while (num3 > 2) {
      num3 -= 4;
      num = ((BitOperations::RotateLeft(num, 5) + num) ^ *ptr2);
      num2 = ((BitOperations::RotateLeft(num2, 5) + num2) ^ ptr2[1]);
      ptr2 += 2;
    }
    if (num3 > 0) {
      num2 = ((BitOperations::RotateLeft(num2, 5) + num2) ^ *ptr2);
    }
    return (Int32)(num + num2 * 1566083941);
  }
}

Boolean String___::StartsWith(String value) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  return StartsWith(value, StringComparison::CurrentCulture);
}

Boolean String___::StartsWith(String value, StringComparison comparisonType) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  if ((Object)(String)this == value) {
    CheckStringComparison(comparisonType);
    return true;
  }
  if (value->get_Length() == 0) {
    CheckStringComparison(comparisonType);
    return true;
  }
  switch (comparisonType) {
    case StringComparison::CurrentCulture:
    case StringComparison::CurrentCultureIgnoreCase:
      return CultureInfo::in::get_CurrentCulture()->get_CompareInfo()->IsPrefix((String)this, value, GetCaseCompareOfComparisonCulture(comparisonType));
    case StringComparison::InvariantCulture:
    case StringComparison::InvariantCultureIgnoreCase:
      return CompareInfo::in::Invariant->IsPrefix((String)this, value, GetCaseCompareOfComparisonCulture(comparisonType));
    case StringComparison::Ordinal:
      if (get_Length() < value->get_Length() || _firstChar != value->_firstChar) {
        return false;
      }
      if (value->get_Length() != 1) {
        return SpanHelpers::SequenceEqual(Unsafe::As<Char, Byte>(GetRawStringData()), Unsafe::As<Char, Byte>(value->GetRawStringData()), (UIntPtr)value->get_Length() * (?)2u);
      }
      return true;
    case StringComparison::OrdinalIgnoreCase:
      if (get_Length() < value->get_Length()) {
        return false;
      }
      return CompareInfo::in::EqualsOrdinalIgnoreCase(GetRawStringData(), value->GetRawStringData(), value->get_Length());
    default:
      rt::throw_exception<ArgumentException>(SR::get_NotSupported_StringComparison(), "comparisonType");
  }
}

Boolean String___::StartsWith(String value, Boolean ignoreCase, CultureInfo culture) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  if ((Object)(String)this == value) {
    return true;
  }
  auto default = culture;
  if (default != nullptr) default = CultureInfo::in::get_CurrentCulture();

  CultureInfo cultureInfo = default;
  return cultureInfo->get_CompareInfo()->IsPrefix((String)this, value, ignoreCase ? CompareOptions::IgnoreCase : CompareOptions::None);
}

Boolean String___::StartsWith(Char value) {
  if (get_Length() != 0) {
    return _firstChar == value;
  }
  return false;
}

void String___::CheckStringComparison(StringComparison comparisonType) {
  if ((UInt32)comparisonType > 5u) {
    ThrowHelper::ThrowArgumentException(ExceptionResource::NotSupported_StringComparison, ExceptionArgument::comparisonType);
  }
}

CompareOptions String___::GetCaseCompareOfComparisonCulture(StringComparison comparisonType) {
  return (CompareOptions)(comparisonType & StringComparison::CurrentCultureIgnoreCase);
}

CompareOptions String___::GetCompareOptionsFromOrdinalStringComparison(StringComparison comparisonType) {
  return (CompareOptions)(((Int32)comparisonType & (0 - comparisonType)) << 28);
}

String String___::Ctor(Array<Char> value) {
  if (value == nullptr || value->get_Length() == 0) {
    return Empty;
  }
  String text = FastAllocateString(value->get_Length());
  UIntPtr elementCount = (UInt32)text->get_Length();
  Buffer::Memmove(text->_firstChar, MemoryMarshal::GetArrayDataReference(value), elementCount);
  return text;
}

String String___::Ctor(Array<Char> value, Int32 startIndex, Int32 length) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  if (startIndex < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("startIndex", SR::get_ArgumentOutOfRange_StartIndex());
  }
  if (length < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("length", SR::get_ArgumentOutOfRange_NegativeLength());
  }
  if (startIndex > value->get_Length() - length) {
    rt::throw_exception<ArgumentOutOfRangeException>("startIndex", SR::get_ArgumentOutOfRange_Index());
  }
  if (length == 0) {
    return Empty;
  }
  String text = FastAllocateString(length);
  UIntPtr elementCount = (UInt32)text->get_Length();
  Buffer::Memmove(text->_firstChar, Unsafe::Add(MemoryMarshal::GetArrayDataReference(value), startIndex), elementCount);
  return text;
}

String String___::Ctor(Char* ptr) {
  if (ptr == nullptr) {
    return Empty;
  }
  Int32 num = wcslen(ptr);
  if (num == 0) {
    return Empty;
  }
  String text = FastAllocateString(num);
  UIntPtr elementCount = (UInt32)text->get_Length();
  Buffer::Memmove(text->_firstChar, *ptr, elementCount);
  return text;
}

String String___::Ctor(Char* ptr, Int32 startIndex, Int32 length) {
  if (length < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("length", SR::get_ArgumentOutOfRange_NegativeLength());
  }
  if (startIndex < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("startIndex", SR::get_ArgumentOutOfRange_StartIndex());
  }
  Char* ptr2 = ptr + startIndex;
  if (ptr2 < ptr) {
    rt::throw_exception<ArgumentOutOfRangeException>("startIndex", SR::get_ArgumentOutOfRange_PartialWCHAR());
  }
  if (length == 0) {
    return Empty;
  }
  if (ptr == nullptr) {
    rt::throw_exception<ArgumentOutOfRangeException>("ptr", SR::get_ArgumentOutOfRange_PartialWCHAR());
  }
  String text = FastAllocateString(length);
  UIntPtr elementCount = (UInt32)text->get_Length();
  Buffer::Memmove(text->_firstChar, *ptr2, elementCount);
  return text;
}

String String___::Ctor(SByte* value) {
  if (value == nullptr) {
    return Empty;
  }
  Int32 numBytes = strlen((Byte*)value);
  return CreateStringForSByteConstructor((Byte*)value, numBytes);
}

String String___::Ctor(SByte* value, Int32 startIndex, Int32 length) {
  if (startIndex < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("startIndex", SR::get_ArgumentOutOfRange_StartIndex());
  }
  if (length < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("length", SR::get_ArgumentOutOfRange_NegativeLength());
  }
  if (value == nullptr) {
    if (length == 0) {
      return Empty;
    }
    rt::throw_exception<ArgumentNullException>("value");
  }
  Byte* ptr = (Byte*)(value + startIndex);
  if (ptr < value) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", SR::get_ArgumentOutOfRange_PartialWCHAR());
  }
  return CreateStringForSByteConstructor(ptr, length);
}

String String___::CreateStringForSByteConstructor(Byte* pb, Int32 numBytes) {
  if (numBytes == 0) {
    return Empty;
  }
  Int32 num = Interop::Kernel32::MultiByteToWideChar(0u, 1u, pb, numBytes, nullptr, 0);
  if (num == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_InvalidANSIString());
  }
  String text = FastAllocateString(num);
  {
    Char* lpWideCharStr = &text->_firstChar;
    num = Interop::Kernel32::MultiByteToWideChar(0u, 1u, pb, numBytes, lpWideCharStr, num);
  }
  if (num == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_InvalidANSIString());
  }
  return text;
}

String String___::Ctor(SByte* value, Int32 startIndex, Int32 length, Encoding enc) {
  if (enc == nullptr) {
    return rt::newobj<String>(value, startIndex, length);
  }
  if (length < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("length", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (startIndex < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("startIndex", SR::get_ArgumentOutOfRange_StartIndex());
  }
  if (value == nullptr) {
    if (length == 0) {
      return Empty;
    }
    rt::throw_exception<ArgumentNullException>("value");
  }
  Byte* ptr = (Byte*)(value + startIndex);
  if (ptr < value) {
    rt::throw_exception<ArgumentOutOfRangeException>("startIndex", SR::get_ArgumentOutOfRange_PartialWCHAR());
  }
  return enc->GetString(ReadOnlySpan<Byte>(ptr, length));
}

String String___::Ctor(Char c, Int32 count) {
  if (count <= 0) {
    if (count == 0) {
      return Empty;
    }
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NegativeCount());
  }
  String text = FastAllocateString(count);
  if (c != 0) {
    {
      Char* ptr = &text->_firstChar;
      UInt32 num = ((UInt32)c << 16) | c;
      UInt32* ptr2 = (UInt32*)ptr;
      if (count >= 4) {
        count -= 4;
        do {
          *ptr2 = num;
          ptr2[1] = num;
          ptr2 += 2;
          count -= 4;
        } while (count >= 0)
      }
      if ((count & 2) != 0) {
        *ptr2 = num;
        ptr2++;
      }
      if ((count & 1) != 0) {
        *(Char*)ptr2 = c;
      }
    }
  }
  return text;
}

String String___::Ctor(ReadOnlySpan<Char> value) {
  if (value.get_Length() == 0) {
    return Empty;
  }
  String text = FastAllocateString(value.get_Length());
  Buffer::Memmove(text->_firstChar, MemoryMarshal::GetReference(value), (UInt32)value.get_Length());
  return text;
}

ReadOnlySpan<Char> String___::op_Implicit(String value) {
  if (value == nullptr) {
    return ReadOnlySpan<T>();
  }
  return ReadOnlySpan<Char>(value->GetRawStringData(), value->get_Length());
}

Boolean String___::TryGetSpan(Int32 startIndex, Int32 count, ReadOnlySpan<Char>& slice) {
  if ((UInt64)((Int64)(UInt32)startIndex + (Int64)(UInt32)count) > (UInt64)(UInt32)get_Length()) {
    slice = ReadOnlySpan<T>();
    return false;
  }
  slice = ReadOnlySpan<Char>(Unsafe::Add(_firstChar, startIndex), count);
  return true;
}

Object String___::Clone() {
  return (String)this;
}

String String___::Copy(String str) {
  if (str == nullptr) {
    rt::throw_exception<ArgumentNullException>("str");
  }
  String text = FastAllocateString(str->get_Length());
  UIntPtr elementCount = (UInt32)text->get_Length();
  Buffer::Memmove(text->_firstChar, str->_firstChar, elementCount);
  return text;
}

void String___::CopyTo(Int32 sourceIndex, Array<Char> destination, Int32 destinationIndex, Int32 count) {
  if (destination == nullptr) {
    rt::throw_exception<ArgumentNullException>("destination");
  }
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NegativeCount());
  }
  if (sourceIndex < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("sourceIndex", SR::get_ArgumentOutOfRange_Index());
  }
  if (count > get_Length() - sourceIndex) {
    rt::throw_exception<ArgumentOutOfRangeException>("sourceIndex", SR::get_ArgumentOutOfRange_IndexCount());
  }
  if (destinationIndex > destination->get_Length() - count || destinationIndex < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("destinationIndex", SR::get_ArgumentOutOfRange_IndexCount());
  }
  Buffer::Memmove(Unsafe::Add(MemoryMarshal::GetArrayDataReference(destination), destinationIndex), Unsafe::Add(_firstChar, sourceIndex), (UInt32)count);
}

Array<Char> String___::ToCharArray() {
  if (get_Length() == 0) {
    return Array<>::in::Empty<Char>();
  }
  Array<Char> array = rt::newarr<Array<Char>>(get_Length());
  Buffer::Memmove(MemoryMarshal::GetArrayDataReference(array), _firstChar, (UInt32)get_Length());
  return array;
}

Array<Char> String___::ToCharArray(Int32 startIndex, Int32 length) {
  if (startIndex < 0 || startIndex > get_Length() || startIndex > get_Length() - length) {
    rt::throw_exception<ArgumentOutOfRangeException>("startIndex", SR::get_ArgumentOutOfRange_Index());
  }
  if (length <= 0) {
    if (length == 0) {
      return Array<>::in::Empty<Char>();
    }
    rt::throw_exception<ArgumentOutOfRangeException>("length", SR::get_ArgumentOutOfRange_Index());
  }
  Array<Char> array = rt::newarr<Array<Char>>(length);
  Buffer::Memmove(MemoryMarshal::GetArrayDataReference(array), Unsafe::Add(_firstChar, startIndex), (UInt32)length);
  return array;
}

Boolean String___::IsNullOrEmpty(String value) {
  if (value != nullptr && 0u < (UInt32)value->get_Length()) {
    return false;
  }
  return true;
}

Boolean String___::IsNullOrWhiteSpace(String value) {
  if (value == nullptr) {
    return true;
  }
  for (Int32 i = 0; i < value->get_Length(); i++) {
    if (!Char::IsWhiteSpace(value[i])) {
      return false;
    }
  }
  return true;
}

Char& String___::GetPinnableReference() {
  return _firstChar;
}

Char& String___::GetRawStringData() {
  return _firstChar;
}

String String___::CreateStringFromEncoding(Byte* bytes, Int32 byteLength, Encoding encoding) {
  Int32 charCount = encoding->GetCharCount(bytes, byteLength);
  if (charCount == 0) {
    return Empty;
  }
  String text = FastAllocateString(charCount);
  {
    Char* chars = &text->_firstChar;
    Int32 chars2 = encoding->GetChars(bytes, byteLength, chars, charCount);
  }
  return text;
}

String String___::CreateFromChar(Char c) {
  String text = FastAllocateString(1);
  text->_firstChar = c;
  return text;
}

String String___::CreateFromChar(Char c1, Char c2) {
  String text = FastAllocateString(2);
  text->_firstChar = c1;
  Unsafe::Add(text->_firstChar, 1) = c2;
  return text;
}

void String___::wstrcpy(Char* dmem, Char* smem, Int32 charCount) {
  Buffer::Memmove((Byte*)dmem, (Byte*)smem, (UInt32)(charCount * 2));
}

String String___::ToString() {
  return (String)this;
}

String String___::ToString(IFormatProvider provider) {
  return (String)this;
}

CharEnumerator String___::GetEnumerator() {
  return rt::newobj<CharEnumerator>((String)this);
}

StringRuneEnumerator String___::EnumerateRunes() {
  return StringRuneEnumerator((String)this);
}

Int32 String___::wcslen(Char* ptr) {
  Int32 num = SpanHelpers::IndexOf(*ptr, 0, Int32::MaxValue);
  if (num < 0) {
    ThrowMustBeNullTerminatedString();
  }
  return num;
}

Int32 String___::strlen(Byte* ptr) {
  Int32 num = SpanHelpers::IndexOf(*ptr, 0, Int32::MaxValue);
  if (num < 0) {
    ThrowMustBeNullTerminatedString();
  }
  return num;
}

void String___::ThrowMustBeNullTerminatedString() {
  rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeNullTerminatedString());
}

TypeCode String___::GetTypeCode() {
  return TypeCode::String;
}

Boolean String___::IsNormalized() {
  return IsNormalized(NormalizationForm::FormC);
}

Boolean String___::IsNormalized(NormalizationForm normalizationForm) {
  if (IsAscii() && (normalizationForm == NormalizationForm::FormC || normalizationForm == NormalizationForm::FormKC || normalizationForm == NormalizationForm::FormD || normalizationForm == NormalizationForm::FormKD)) {
    return true;
  }
  return Normalization::IsNormalized((String)this, normalizationForm);
}

String String___::Normalize() {
  return Normalize(NormalizationForm::FormC);
}

String String___::Normalize(NormalizationForm normalizationForm) {
  if (IsAscii() && (normalizationForm == NormalizationForm::FormC || normalizationForm == NormalizationForm::FormKC || normalizationForm == NormalizationForm::FormD || normalizationForm == NormalizationForm::FormKD)) {
    return (String)this;
  }
  return Normalization::Normalize((String)this, normalizationForm);
}

Boolean String___::IsAscii() {
  {
    Char* pBuffer = &_firstChar;
    return ASCIIUtility::GetIndexOfFirstNonAsciiChar(pBuffer, (UInt32)get_Length()) == (UInt32)get_Length();
  }
}

void String___::FillStringChecked(String dest, Int32 destPos, String src) {
  if (src->get_Length() > dest->get_Length() - destPos) {
    rt::throw_exception<IndexOutOfRangeException>();
  }
  Buffer::Memmove(Unsafe::Add(dest->_firstChar, destPos), src->_firstChar, (UInt32)src->get_Length());
}

String String___::Concat(Object arg0) {
}

String String___::Concat(Object arg0, Object arg1) {
  if (arg0 == nullptr) {
    arg0 = Empty;
  }
  if (arg1 == nullptr) {
    arg1 = Empty;
  }
  return arg0->ToString() + arg1->ToString();
}

String String___::Concat(Object arg0, Object arg1, Object arg2) {
  if (arg0 == nullptr) {
    arg0 = Empty;
  }
  if (arg1 == nullptr) {
    arg1 = Empty;
  }
  if (arg2 == nullptr) {
    arg2 = Empty;
  }
  return arg0->ToString() + arg1->ToString() + arg2->ToString();
}

String String___::Concat(Array<Object> args) {
  if (args == nullptr) {
    rt::throw_exception<ArgumentNullException>("args");
  }
  if (args->get_Length() <= 1) {
    Object obj;
    if (args->get_Length() != 0) {
    } else {
      obj = Empty;
    }
    return (String)obj;
  }
  Array<String> array = rt::newarr<Array<String>>(args->get_Length());
  Int32 num = 0;
  for (Int32 i = 0; i < args->get_Length(); i++) {
  }
  if (num == 0) {
    return Empty;
  }
  String text = FastAllocateString(num);
  Int32 num2 = 0;
}

String String___::Concat(IEnumerable_<String> values) {
  if (values == nullptr) {
    rt::throw_exception<ArgumentNullException>("values");
  }
}

String String___::Concat(String str0, String str1) {
  if (IsNullOrEmpty(str0)) {
    if (IsNullOrEmpty(str1)) {
      return Empty;
    }
    return str1;
  }
  if (IsNullOrEmpty(str1)) {
    return str0;
  }
  Int32 length = str0->get_Length();
  String text = FastAllocateString(length + str1->get_Length());
  FillStringChecked(text, 0, str0);
  FillStringChecked(text, length, str1);
  return text;
}

String String___::Concat(String str0, String str1, String str2) {
  if (IsNullOrEmpty(str0)) {
    return str1 + str2;
  }
  if (IsNullOrEmpty(str1)) {
    return str0 + str2;
  }
  if (IsNullOrEmpty(str2)) {
    return str0 + str1;
  }
  Int32 length = str0->get_Length() + str1->get_Length() + str2->get_Length();
  String text = FastAllocateString(length);
  FillStringChecked(text, 0, str0);
  FillStringChecked(text, str0->get_Length(), str1);
  FillStringChecked(text, str0->get_Length() + str1->get_Length(), str2);
  return text;
}

String String___::Concat(String str0, String str1, String str2, String str3) {
  if (IsNullOrEmpty(str0)) {
    return str1 + str2 + str3;
  }
  if (IsNullOrEmpty(str1)) {
    return str0 + str2 + str3;
  }
  if (IsNullOrEmpty(str2)) {
    return str0 + str1 + str3;
  }
  if (IsNullOrEmpty(str3)) {
    return str0 + str1 + str2;
  }
  Int32 length = str0->get_Length() + str1->get_Length() + str2->get_Length() + str3->get_Length();
  String text = FastAllocateString(length);
  FillStringChecked(text, 0, str0);
  FillStringChecked(text, str0->get_Length(), str1);
  FillStringChecked(text, str0->get_Length() + str1->get_Length(), str2);
  FillStringChecked(text, str0->get_Length() + str1->get_Length() + str2->get_Length(), str3);
  return text;
}

String String___::Concat(ReadOnlySpan<Char> str0, ReadOnlySpan<Char> str1) {
  Int32 num = str0.get_Length() + str1.get_Length();
  if (num == 0) {
    return Empty;
  }
  String text = FastAllocateString(num);
  Span<Char> destination = Span<Char>(text->GetRawStringData(), text->get_Length());
  str0.CopyTo(destination);
  str1.CopyTo(destination.Slice(str0.get_Length()));
  return text;
}

String String___::Concat(ReadOnlySpan<Char> str0, ReadOnlySpan<Char> str1, ReadOnlySpan<Char> str2) {
  Int32 num = str0.get_Length() + str1.get_Length() + str2.get_Length();
  if (num == 0) {
    return Empty;
  }
  String text = FastAllocateString(num);
  Span<Char> destination = Span<Char>(text->GetRawStringData(), text->get_Length());
  str0.CopyTo(destination);
  destination = destination.Slice(str0.get_Length());
  str1.CopyTo(destination);
  destination = destination.Slice(str1.get_Length());
  str2.CopyTo(destination);
  return text;
}

String String___::Concat(ReadOnlySpan<Char> str0, ReadOnlySpan<Char> str1, ReadOnlySpan<Char> str2, ReadOnlySpan<Char> str3) {
  Int32 num = str0.get_Length() + str1.get_Length() + str2.get_Length() + str3.get_Length();
  if (num == 0) {
    return Empty;
  }
  String text = FastAllocateString(num);
  Span<Char> destination = Span<Char>(text->GetRawStringData(), text->get_Length());
  str0.CopyTo(destination);
  destination = destination.Slice(str0.get_Length());
  str1.CopyTo(destination);
  destination = destination.Slice(str1.get_Length());
  str2.CopyTo(destination);
  destination = destination.Slice(str2.get_Length());
  str3.CopyTo(destination);
  return text;
}

String String___::Concat(Array<String> values) {
  if (values == nullptr) {
    rt::throw_exception<ArgumentNullException>("values");
  }
  if (values->get_Length() <= 1) {
    Object obj;
    if (values->get_Length() != 0) {
      obj = values[0];
      if (obj == nullptr) {
        return Empty;
      }
    } else {
      obj = Empty;
    }
    return (String)obj;
  }
  Int64 num = 0;
}

String String___::Format(String format, Object arg0) {
  return FormatHelper(nullptr, format, ParamsArray(arg0));
}

String String___::Format(String format, Object arg0, Object arg1) {
  return FormatHelper(nullptr, format, ParamsArray(arg0, arg1));
}

String String___::Format(String format, Object arg0, Object arg1, Object arg2) {
  return FormatHelper(nullptr, format, ParamsArray(arg0, arg1, arg2));
}

String String___::Format(String format, Array<Object> args) {
  if (args == nullptr) {
    rt::throw_exception<ArgumentNullException>((format == nullptr) ? "format" : "args");
  }
  return FormatHelper(nullptr, format, ParamsArray(args));
}

String String___::Format(IFormatProvider provider, String format, Object arg0) {
  return FormatHelper(provider, format, ParamsArray(arg0));
}

String String___::Format(IFormatProvider provider, String format, Object arg0, Object arg1) {
  return FormatHelper(provider, format, ParamsArray(arg0, arg1));
}

String String___::Format(IFormatProvider provider, String format, Object arg0, Object arg1, Object arg2) {
  return FormatHelper(provider, format, ParamsArray(arg0, arg1, arg2));
}

String String___::Format(IFormatProvider provider, String format, Array<Object> args) {
  if (args == nullptr) {
    rt::throw_exception<ArgumentNullException>((format == nullptr) ? "format" : "args");
  }
  return FormatHelper(provider, format, ParamsArray(args));
}

String String___::FormatHelper(IFormatProvider provider, String format, ParamsArray args) {
  if (format == nullptr) {
    rt::throw_exception<ArgumentNullException>("format");
  }
  Char default[256] = {};
  Span<Char> initialBuffer = default;
  ValueStringBuilder valueStringBuilder = ValueStringBuilder(initialBuffer);
  valueStringBuilder.EnsureCapacity(format->get_Length() + args.get_Length() * 8);
  valueStringBuilder.AppendFormatHelper(provider, format, args);
  return valueStringBuilder.ToString();
}

String String___::Insert(Int32 startIndex, String value) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  if (startIndex < 0 || startIndex > get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("startIndex");
  }
  Int32 length = get_Length();
  Int32 length2 = value->get_Length();
  if (length == 0) {
    return value;
  }
  if (length2 == 0) {
    return (String)this;
  }
  Int32 length3 = length + length2;
  String text = FastAllocateString(length3);
  {
    Char* ptr2 = &_firstChar;
    {
      Char* smem = &value->_firstChar;
      {
        Char* ptr = &text->_firstChar;
        wstrcpy(ptr, ptr2, startIndex);
        wstrcpy(ptr + startIndex, smem, length2);
        wstrcpy(ptr + startIndex + length2, ptr2 + startIndex, length - startIndex);
      }
    }
  }
  return text;
}

String String___::Join(Char separator, Array<String> value) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  return Join(separator, value, 0, value->get_Length());
}

String String___::Join(Char separator, Array<Object> values) {
  return JoinCore(&separator, 1, values);
}

String String___::Join(Char separator, Array<String> value, Int32 startIndex, Int32 count) {
  return JoinCore(&separator, 1, value, startIndex, count);
}

String String___::Join(String separator, Array<String> value) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  return Join(separator, value, 0, value->get_Length());
}

String String___::Join(String separator, Array<Object> values) {
  if (separator == nullptr) {
    separator = Empty;
  }
  {
    Char* separator2 = &separator->_firstChar;
    return JoinCore(separator2, separator->get_Length(), values);
  }
}

String String___::Join(String separator, IEnumerable_<String> values) {
  if (values == nullptr) {
    rt::throw_exception<ArgumentNullException>("values");
  }
}

String String___::Join(String separator, Array<String> value, Int32 startIndex, Int32 count) {
  if (separator == nullptr) {
    separator = Empty;
  }
  {
    Char* separator2 = &separator->_firstChar;
    return JoinCore(separator2, separator->get_Length(), value, startIndex, count);
  }
}

String String___::JoinCore(Char* separator, Int32 separatorLength, Array<Object> values) {
  if (values == nullptr) {
    rt::throw_exception<ArgumentNullException>("values");
  }
  if (values->get_Length() == 0) {
    return Empty;
  }
}

String String___::JoinCore(Char* separator, Int32 separatorLength, Array<String> value, Int32 startIndex, Int32 count) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  if (startIndex < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("startIndex", SR::get_ArgumentOutOfRange_StartIndex());
  }
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NegativeCount());
  }
  if (startIndex > value->get_Length() - count) {
    rt::throw_exception<ArgumentOutOfRangeException>("startIndex", SR::get_ArgumentOutOfRange_IndexCountBuffer());
  }
  if (count <= 1) {
    Object obj;
    if (count != 0) {
      obj = value[startIndex];
      if (obj == nullptr) {
        return Empty;
      }
    } else {
      obj = Empty;
    }
    return (String)obj;
  }
  Int64 num = (Int64)(count - 1) * (Int64)separatorLength;
  if (num > Int32::MaxValue) {
    rt::throw_exception<OutOfMemoryException>();
  }
  Int32 num2 = (Int32)num;
  Int32 i = startIndex;
  for (Int32 num3 = startIndex + count; i < num3; i++) {
    String text = value[i];
    if (text != nullptr) {
      num2 += text->get_Length();
      if (num2 < 0) {
        rt::throw_exception<OutOfMemoryException>();
      }
    }
  }
  String text2 = FastAllocateString(num2);
  Int32 num4 = 0;
  Int32 j = startIndex;
  for (Int32 num5 = startIndex + count; j < num5; j++) {
    String text3 = value[j];
    if (text3 != nullptr) {
      Int32 length = text3->get_Length();
      if (length > num2 - num4) {
        num4 = -1;
        break;
      }
      FillStringChecked(text2, num4, text3);
      num4 += length;
    }
    if (j >= num5 - 1) {
      continue;
    }
    {
      Char* ptr = &text2->_firstChar;
      if (separatorLength == 1) {
        ptr[num4] = *separator;
      } else {
        wstrcpy(ptr + num4, separator, separatorLength);
      }
    }
    num4 += separatorLength;
  }
  if (num4 != num2) {
    return JoinCore(separator, separatorLength, (Array<String>)value->Clone(), startIndex, count);
  }
  return text2;
}

String String___::PadLeft(Int32 totalWidth) {
  return PadLeft(totalWidth, 32);
}

String String___::PadLeft(Int32 totalWidth, Char paddingChar) {
  if (totalWidth < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("totalWidth", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  Int32 length = get_Length();
  Int32 num = totalWidth - length;
  if (num <= 0) {
    return (String)this;
  }
  String text = FastAllocateString(totalWidth);
  {
    Char* ptr = &text->_firstChar;
    for (Int32 i = 0; i < num; i++) {
      ptr[i] = paddingChar;
    }
    {
      Char* smem = &_firstChar;
      wstrcpy(ptr + num, smem, length);
    }
  }
  return text;
}

String String___::PadRight(Int32 totalWidth) {
  return PadRight(totalWidth, 32);
}

String String___::PadRight(Int32 totalWidth, Char paddingChar) {
  if (totalWidth < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("totalWidth", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  Int32 length = get_Length();
  Int32 num = totalWidth - length;
  if (num <= 0) {
    return (String)this;
  }
  String text = FastAllocateString(totalWidth);
  {
    Char* ptr = &text->_firstChar;
    {
      Char* smem = &_firstChar;
      wstrcpy(ptr, smem, length);
    }
    for (Int32 i = 0; i < num; i++) {
      ptr[length + i] = paddingChar;
    }
  }
  return text;
}

String String___::Remove(Int32 startIndex, Int32 count) {
  if (startIndex < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("startIndex", SR::get_ArgumentOutOfRange_StartIndex());
  }
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NegativeCount());
  }
  Int32 length = get_Length();
  if (count > length - startIndex) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_IndexCount());
  }
  if (count == 0) {
    return (String)this;
  }
  Int32 num = length - count;
  if (num == 0) {
    return Empty;
  }
  String text = FastAllocateString(num);
  {
    Char* ptr2 = &_firstChar;
    {
      Char* ptr = &text->_firstChar;
      wstrcpy(ptr, ptr2, startIndex);
      wstrcpy(ptr + startIndex, ptr2 + startIndex + count, num - startIndex);
    }
  }
  return text;
}

String String___::Remove(Int32 startIndex) {
  if (startIndex < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("startIndex", SR::get_ArgumentOutOfRange_StartIndex());
  }
  if (startIndex >= get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("startIndex", SR::get_ArgumentOutOfRange_StartIndexLessThanLength());
  }
  return Substring(0, startIndex);
}

String String___::Replace(String oldValue, String newValue, Boolean ignoreCase, CultureInfo culture) {
}

String String___::Replace(String oldValue, String newValue, StringComparison comparisonType) {
  switch (comparisonType) {
    case StringComparison::CurrentCulture:
    case StringComparison::CurrentCultureIgnoreCase:
      return ReplaceCore(oldValue, newValue, CultureInfo::in::get_CurrentCulture()->get_CompareInfo(), GetCaseCompareOfComparisonCulture(comparisonType));
    case StringComparison::InvariantCulture:
    case StringComparison::InvariantCultureIgnoreCase:
      return ReplaceCore(oldValue, newValue, CompareInfo::in::Invariant, GetCaseCompareOfComparisonCulture(comparisonType));
    case StringComparison::Ordinal:
      return Replace(oldValue, newValue);
    case StringComparison::OrdinalIgnoreCase:
      return ReplaceCore(oldValue, newValue, CompareInfo::in::Invariant, CompareOptions::OrdinalIgnoreCase);
    default:
      rt::throw_exception<ArgumentException>(SR::get_NotSupported_StringComparison(), "comparisonType");
  }
}

String String___::ReplaceCore(String oldValue, String newValue, CompareInfo ci, CompareOptions options) {
  if (oldValue == nullptr) {
    rt::throw_exception<ArgumentNullException>("oldValue");
  }
  if (oldValue->get_Length() == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_StringZeroLength(), "oldValue");
  }
  auto default = ci;
  if (default != nullptr) default = CultureInfo::in::get_CurrentCulture()->get_CompareInfo();

  auto extern = ReplaceCore((String)this, MemoryExtensions::AsSpan(oldValue), MemoryExtensions::AsSpan(newValue), default, options);
  if (extern != nullptr) extern = (String)this;

  return extern;
}

String String___::ReplaceCore(ReadOnlySpan<Char> searchSpace, ReadOnlySpan<Char> oldValue, ReadOnlySpan<Char> newValue, CompareInfo compareInfo, CompareOptions options) {
  Char default[256] = {};
  Span<Char> initialBuffer = default;
  ValueStringBuilder valueStringBuilder = ValueStringBuilder(initialBuffer);
  valueStringBuilder.EnsureCapacity(searchSpace.get_Length());
  Int32 num = 0;
  Boolean flag = false;
  while (true) {
    Int32 num2 = compareInfo->IndexOf(searchSpace, oldValue, &num, options, true);
    if (num2 < 0 || num == 0) {
      break;
    }
    valueStringBuilder.Append(searchSpace.Slice(0, num2));
    valueStringBuilder.Append(newValue);
    searchSpace = searchSpace.Slice(num2 + num);
    flag = true;
  }
  if (!flag) {
    valueStringBuilder.Dispose();
    return nullptr;
  }
  valueStringBuilder.Append(searchSpace);
  return valueStringBuilder.ToString();
}

String String___::Replace(Char oldChar, Char newChar) {
  if (oldChar == newChar) {
    return (String)this;
  }
  Int32 num = IndexOf(oldChar);
  if (num < 0) {
    return (String)this;
  }
  Int32 num2 = get_Length() - num;
  String text = FastAllocateString(get_Length());
  Int32 num3 = num;
  if (num3 > 0) {
    Buffer::Memmove(text->_firstChar, _firstChar, (UInt32)num3);
  }
  UInt16& reference = Unsafe::Add(Unsafe::As<Char, UInt16>(_firstChar), num3);
  UInt16& reference2 = Unsafe::Add(Unsafe::As<Char, UInt16>(text->_firstChar), num3);
  if (Vector::get_IsHardwareAccelerated() && num2 >= Vector<UInt16>::get_Count()) {
    Vector<UInt16> right = Vector<UInt16>(oldChar);
    Vector<UInt16> left = Vector<UInt16>(newChar);
    do {
      Vector<UInt16> vector = Unsafe::ReadUnaligned<Vector<UInt16>>(Unsafe::As<UInt16, Byte>(reference));
      Vector<UInt16> condition = Vector::Equals(vector, right);
      Vector<UInt16> value = Vector::ConditionalSelect(condition, left, vector);
      Unsafe::WriteUnaligned(Unsafe::As<UInt16, Byte>(reference2), value);
      reference = Unsafe::Add(reference, Vector<UInt16>::get_Count());
      reference2 = Unsafe::Add(reference2, Vector<UInt16>::get_Count());
      num2 -= Vector<UInt16>::get_Count();
    } while (num2 >= Vector<UInt16>::get_Count())
  }
  while (num2 > 0) {
    UInt16 num4 = reference;
    reference2 = ((num4 == oldChar) ? newChar : num4);
    reference = Unsafe::Add(reference, 1);
    reference2 = Unsafe::Add(reference2, 1);
    num2--;
  }
  return text;
}

String String___::Replace(String oldValue, String newValue) {
  if (oldValue == nullptr) {
    rt::throw_exception<ArgumentNullException>("oldValue");
  }
  if (oldValue->get_Length() == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_StringZeroLength(), "oldValue");
  }
  if (newValue == nullptr) {
    newValue = Empty;
  }
  Int32 default[128] = {};
  Span<Int32> initialSpan = default;
  ValueListBuilder<Int32> valueListBuilder = ValueListBuilder<Int32>(initialSpan);
  {
    Char* ptr = &_firstChar;
    Int32 num = 0;
    Int32 num2 = get_Length() - oldValue->get_Length();
    while (num <= num2) {
      Char* ptr2 = ptr + num;
      Int32 num3 = 0;
      while (true) {
        if (num3 < oldValue->get_Length()) {
          if (ptr2[num3] == oldValue[num3]) {
            num3++;
            continue;
          }
          num++;
          break;
        }
        valueListBuilder.Append(num);
        num += oldValue->get_Length();
        break;
      }
    }
  }
  if (valueListBuilder.get_Length() == 0) {
    return (String)this;
  }
  String result = ReplaceHelper(oldValue->get_Length(), newValue, valueListBuilder.AsSpan());
  valueListBuilder.Dispose();
  return result;
}

String String___::ReplaceHelper(Int32 oldValueLength, String newValue, ReadOnlySpan<Int32> indices) {
  Int64 num = get_Length() + (Int64)(newValue->get_Length() - oldValueLength) * (Int64)indices.get_Length();
  if (num > Int32::MaxValue) {
    rt::throw_exception<OutOfMemoryException>();
  }
  String text = FastAllocateString((Int32)num);
  Span<Char> span = Span<Char>(text->GetRawStringData(), text->get_Length());
  Int32 num2 = 0;
  Int32 num3 = 0;
}

Array<String> String___::Split(Char separator, StringSplitOptions options) {
  return SplitInternal(ReadOnlySpan<Char>(separator, 1), Int32::MaxValue, options);
}

Array<String> String___::Split(Char separator, Int32 count, StringSplitOptions options) {
  return SplitInternal(ReadOnlySpan<Char>(separator, 1), count, options);
}

Array<String> String___::Split(Array<Char> separator) {
  return SplitInternal(separator, Int32::MaxValue, StringSplitOptions::None);
}

Array<String> String___::Split(Array<Char> separator, Int32 count) {
  return SplitInternal(separator, count, StringSplitOptions::None);
}

Array<String> String___::Split(Array<Char> separator, StringSplitOptions options) {
  return SplitInternal(separator, Int32::MaxValue, options);
}

Array<String> String___::Split(Array<Char> separator, Int32 count, StringSplitOptions options) {
  return SplitInternal(separator, count, options);
}

Array<String> String___::SplitInternal(ReadOnlySpan<Char> separators, Int32 count, StringSplitOptions options) {
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NegativeCount());
  }
  if (options < StringSplitOptions::None || options > StringSplitOptions::RemoveEmptyEntries) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Arg_EnumIllegalVal(), options));
  }
  Boolean flag = options == StringSplitOptions::RemoveEmptyEntries;
  if (count == 0 || (flag && get_Length() == 0)) {
    return Array<>::in::Empty<String>();
  }
  if (count == 1) {
    return rt::newarr<Array<String>>(1);
  }
  Int32 default[128] = {};
  Span<Int32> initialSpan = default;
  ValueListBuilder<Int32> sepListBuilder = ValueListBuilder<Int32>(initialSpan);
  MakeSeparatorList(separators, sepListBuilder);
  ReadOnlySpan<Int32> sepList = sepListBuilder.AsSpan();
  if (sepList.get_Length() == 0) {
    return rt::newarr<Array<String>>(1);
  }
  Array<String> result = flag ? SplitOmitEmptyEntries(sepList, ReadOnlySpan<T>(), 1, count) : SplitKeepEmptyEntries(sepList, ReadOnlySpan<T>(), 1, count);
  sepListBuilder.Dispose();
  return result;
}

Array<String> String___::Split(String separator, StringSplitOptions options) {
  auto default = separator;
  if (default != nullptr) default = Empty;

  return SplitInternal(default, nullptr, Int32::MaxValue, options);
}

Array<String> String___::Split(String separator, Int32 count, StringSplitOptions options) {
  auto default = separator;
  if (default != nullptr) default = Empty;

  return SplitInternal(default, nullptr, count, options);
}

Array<String> String___::Split(Array<String> separator, StringSplitOptions options) {
  return SplitInternal(nullptr, separator, Int32::MaxValue, options);
}

Array<String> String___::Split(Array<String> separator, Int32 count, StringSplitOptions options) {
  return SplitInternal(nullptr, separator, count, options);
}

Array<String> String___::SplitInternal(String separator, Array<String> separators, Int32 count, StringSplitOptions options) {
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NegativeCount());
  }
  if (options < StringSplitOptions::None || options > StringSplitOptions::RemoveEmptyEntries) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Arg_EnumIllegalVal(), (Int32)options));
  }
  Boolean flag = options == StringSplitOptions::RemoveEmptyEntries;
  Boolean flag2 = separator != nullptr;
  if (!flag2 && (separators == nullptr || separators->get_Length() == 0)) {
    return SplitInternal(ReadOnlySpan<T>(), count, options);
  }
  if (count == 0 || (flag && get_Length() == 0)) {
    return Array<>::in::Empty<String>();
  }
  if (count == 1 || (flag2 && separator->get_Length() == 0)) {
    return rt::newarr<Array<String>>(1);
  }
  if (flag2) {
    return SplitInternal(separator, count, options);
  }
  Int32 default[128] = {};
  Span<Int32> initialSpan = default;
  ValueListBuilder<Int32> sepListBuilder = ValueListBuilder<Int32>(initialSpan);
  Int32 extern[128] = {};
  initialSpan = extern;
  ValueListBuilder<Int32> lengthListBuilder = ValueListBuilder<Int32>(initialSpan);
  MakeSeparatorList(separators, sepListBuilder, lengthListBuilder);
  ReadOnlySpan<Int32> sepList = sepListBuilder.AsSpan();
  ReadOnlySpan<Int32> lengthList = lengthListBuilder.AsSpan();
  if (sepList.get_Length() == 0) {
    return rt::newarr<Array<String>>(1);
  }
  Array<String> result = flag ? SplitOmitEmptyEntries(sepList, lengthList, 0, count) : SplitKeepEmptyEntries(sepList, lengthList, 0, count);
  sepListBuilder.Dispose();
  lengthListBuilder.Dispose();
  return result;
}

Array<String> String___::SplitInternal(String separator, Int32 count, StringSplitOptions options) {
  Int32 default[128] = {};
  Span<Int32> initialSpan = default;
  ValueListBuilder<Int32> sepListBuilder = ValueListBuilder<Int32>(initialSpan);
  MakeSeparatorList(separator, sepListBuilder);
  ReadOnlySpan<Int32> sepList = sepListBuilder.AsSpan();
  if (sepList.get_Length() == 0) {
    return rt::newarr<Array<String>>(1);
  }
  Array<String> result = (options == StringSplitOptions::RemoveEmptyEntries) ? SplitOmitEmptyEntries(sepList, ReadOnlySpan<T>(), separator->get_Length(), count) : SplitKeepEmptyEntries(sepList, ReadOnlySpan<T>(), separator->get_Length(), count);
  sepListBuilder.Dispose();
  return result;
}

Array<String> String___::SplitKeepEmptyEntries(ReadOnlySpan<Int32> sepList, ReadOnlySpan<Int32> lengthList, Int32 defaultLength, Int32 count) {
  Int32 num = 0;
  Int32 num2 = 0;
  count--;
  Int32 num3 = (sepList.get_Length() < count) ? sepList.get_Length() : count;
  Array<String> array = rt::newarr<Array<String>>(num3 + 1);
  for (Int32 i = 0; i < num3; i++) {
    if (num >= get_Length()) {
      break;
    }
    array[num2++] = Substring(num, sepList[i] - num);
    num = sepList[i] + (lengthList.get_IsEmpty() ? defaultLength : lengthList[i]);
  }
  if (num < get_Length() && num3 >= 0) {
    array[num2] = Substring(num);
  } else if (num2 == num3) {
    array[num2] = Empty;
  }

  return array;
}

Array<String> String___::SplitOmitEmptyEntries(ReadOnlySpan<Int32> sepList, ReadOnlySpan<Int32> lengthList, Int32 defaultLength, Int32 count) {
  Int32 length = sepList.get_Length();
  Int32 num = (length < count) ? (length + 1) : count;
  Array<String> array = rt::newarr<Array<String>>(num);
  Int32 num2 = 0;
  Int32 num3 = 0;
  for (Int32 i = 0; i < length; i++) {
    if (num2 >= get_Length()) {
      break;
    }
    if (sepList[i] - num2 > 0) {
      array[num3++] = Substring(num2, sepList[i] - num2);
    }
    num2 = sepList[i] + (lengthList.get_IsEmpty() ? defaultLength : lengthList[i]);
    if (num3 == count - 1) {
      while (i < length - 1 && num2 == sepList[++i]) {
        num2 += (lengthList.get_IsEmpty() ? defaultLength : lengthList[i]);
      }
      break;
    }
  }
  if (num2 < get_Length()) {
    array[num3++] = Substring(num2);
  }
  Array<String> array2 = array;
  if (num3 != num) {
    array2 = rt::newarr<Array<String>>(num3);
    for (Int32 j = 0; j < num3; j++) {
      array2[j] = array[j];
    }
  }
  return array2;
}

void String___::MakeSeparatorList(ReadOnlySpan<Char> separators, ValueListBuilder<Int32>& sepListBuilder) {
  switch (separators.get_Length().get()) {
    case 0:
      {
        for (Int32 i = 0; i < get_Length(); i++) {
          if (Char::IsWhiteSpace((String)this[i])) {
            sepListBuilder.Append(i);
          }
        }
        return;
      }case 1:
      {
        Char c = separators[0];
        for (Int32 k = 0; k < get_Length(); k++) {
          if ((String)this[k] == c) {
            sepListBuilder.Append(k);
          }
        }
        return;
      }case 2:
      {
        Char c = separators[0];
        Char c2 = separators[1];
        for (Int32 l = 0; l < get_Length(); l++) {
          Char c5 = (String)this[l];
          if (c5 == c || c5 == c2) {
            sepListBuilder.Append(l);
          }
        }
        return;
      }case 3:
      {
        Char c = separators[0];
        Char c2 = separators[1];
        Char c3 = separators[2];
        for (Int32 j = 0; j < get_Length(); j++) {
          Char c4 = (String)this[j];
          if (c4 == c || c4 == c2 || c4 == c3) {
            sepListBuilder.Append(j);
          }
        }
        return;
      }}
  ProbabilisticMap probabilisticMap = ProbabilisticMap();
  UInt32* charMap = (UInt32*)(&probabilisticMap);
  InitializeProbabilisticMap(charMap, separators);
  for (Int32 m = 0; m < get_Length(); m++) {
    Char c6 = (String)this[m];
    if (IsCharBitSet(charMap, (Byte)c6) && IsCharBitSet(charMap, (Byte)((Int32)c6 >> 8)) && MemoryExtensions::Contains(separators, c6)) {
      sepListBuilder.Append(m);
    }
  }
}

void String___::MakeSeparatorList(String separator, ValueListBuilder<Int32>& sepListBuilder) {
  Int32 length = separator->get_Length();
  for (Int32 i = 0; i < get_Length(); i++) {
    if ((String)this[i] == separator[0] && length <= get_Length() - i && (length == 1 || MemoryExtensions::SequenceEqual(MemoryExtensions::AsSpan((String)this, i, length), separator))) {
      sepListBuilder.Append(i);
      i += length - 1;
    }
  }
}

void String___::MakeSeparatorList(Array<String> separators, ValueListBuilder<Int32>& sepListBuilder, ValueListBuilder<Int32>& lengthListBuilder) {
  for (Int32 i = 0; i < get_Length(); i++) {
  }
}

String String___::Substring(Int32 startIndex) {
  return Substring(startIndex, get_Length() - startIndex);
}

String String___::Substring(Int32 startIndex, Int32 length) {
  if (startIndex < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("startIndex", SR::get_ArgumentOutOfRange_StartIndex());
  }
  if (startIndex > get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("startIndex", SR::get_ArgumentOutOfRange_StartIndexLargerThanLength());
  }
  if (length < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("length", SR::get_ArgumentOutOfRange_NegativeLength());
  }
  if (startIndex > get_Length() - length) {
    rt::throw_exception<ArgumentOutOfRangeException>("length", SR::get_ArgumentOutOfRange_IndexLength());
  }
  if (length == 0) {
    return Empty;
  }
  if (startIndex == 0 && length == get_Length()) {
    return (String)this;
  }
  return InternalSubString(startIndex, length);
}

String String___::InternalSubString(Int32 startIndex, Int32 length) {
  String text = FastAllocateString(length);
  UIntPtr elementCount = (UInt32)text->get_Length();
  Buffer::Memmove(text->_firstChar, Unsafe::Add(_firstChar, startIndex), elementCount);
  return text;
}

String String___::ToLower() {
  return ToLower(nullptr);
}

String String___::ToLower(CultureInfo culture) {
  auto default = culture;
  if (default != nullptr) default = CultureInfo::in::get_CurrentCulture();

  CultureInfo cultureInfo = default;
  return cultureInfo->get_TextInfo()->ToLower((String)this);
}

String String___::ToLowerInvariant() {
  return TextInfo::in::Invariant->ToLower((String)this);
}

String String___::ToUpper() {
  return ToUpper(nullptr);
}

String String___::ToUpper(CultureInfo culture) {
  auto default = culture;
  if (default != nullptr) default = CultureInfo::in::get_CurrentCulture();

  CultureInfo cultureInfo = default;
  return cultureInfo->get_TextInfo()->ToUpper((String)this);
}

String String___::ToUpperInvariant() {
  return TextInfo::in::Invariant->ToUpper((String)this);
}

String String___::Trim() {
  return TrimWhiteSpaceHelper(TrimType::Both);
}

String String___::Trim(Char trimChar) {
  return TrimHelper(&trimChar, 1, TrimType::Both);
}

String String___::Trim(Array<Char> trimChars) {
  if (trimChars == nullptr || trimChars->get_Length() == 0) {
    return TrimWhiteSpaceHelper(TrimType::Both);
  }
  {
    Char* trimChars2 = &trimChars[0];
    return TrimHelper(trimChars2, trimChars->get_Length(), TrimType::Both);
  }
}

String String___::TrimStart() {
  return TrimWhiteSpaceHelper(TrimType::Head);
}

String String___::TrimStart(Char trimChar) {
  return TrimHelper(&trimChar, 1, TrimType::Head);
}

String String___::TrimStart(Array<Char> trimChars) {
  if (trimChars == nullptr || trimChars->get_Length() == 0) {
    return TrimWhiteSpaceHelper(TrimType::Head);
  }
  {
    Char* trimChars2 = &trimChars[0];
    return TrimHelper(trimChars2, trimChars->get_Length(), TrimType::Head);
  }
}

String String___::TrimEnd() {
  return TrimWhiteSpaceHelper(TrimType::Tail);
}

String String___::TrimEnd(Char trimChar) {
  return TrimHelper(&trimChar, 1, TrimType::Tail);
}

String String___::TrimEnd(Array<Char> trimChars) {
  if (trimChars == nullptr || trimChars->get_Length() == 0) {
    return TrimWhiteSpaceHelper(TrimType::Tail);
  }
  {
    Char* trimChars2 = &trimChars[0];
    return TrimHelper(trimChars2, trimChars->get_Length(), TrimType::Tail);
  }
}

String String___::TrimWhiteSpaceHelper(TrimType trimType) {
  Int32 num = get_Length() - 1;
  Int32 i = 0;
  if ((trimType & TrimType::Head) != 0) {
    for (i = 0; i < get_Length() && Char::IsWhiteSpace((String)this[i]); i++) {
    }
  }
  if ((trimType & TrimType::Tail) != 0) {
    num = get_Length() - 1;
    while (num >= i && Char::IsWhiteSpace((String)this[num])) {
      num--;
    }
  }
  return CreateTrimmedString(i, num);
}

String String___::TrimHelper(Char* trimChars, Int32 trimCharsLength, TrimType trimType) {
  Int32 num = get_Length() - 1;
  Int32 i = 0;
  if ((trimType & TrimType::Head) != 0) {
    for (i = 0; i < get_Length(); i++) {
      Int32 num2 = 0;
      Char c = (String)this[i];
      for (num2 = 0; num2 < trimCharsLength && trimChars[num2] != c; num2++) {
      }
      if (num2 == trimCharsLength) {
        break;
      }
    }
  }
  if ((trimType & TrimType::Tail) != 0) {
    for (num = get_Length() - 1; num >= i; num--) {
      Int32 num3 = 0;
      Char c2 = (String)this[num];
      for (num3 = 0; num3 < trimCharsLength && trimChars[num3] != c2; num3++) {
      }
      if (num3 == trimCharsLength) {
        break;
      }
    }
  }
  return CreateTrimmedString(i, num);
}

String String___::CreateTrimmedString(Int32 start, Int32 end) {
  Int32 num = end - start + 1;
  if (num != get_Length()) {
    if (num != 0) {
      return InternalSubString(start, num);
    }
    return Empty;
  }
  return (String)this;
}

Boolean String___::Contains(String value) {
  if (value == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::value);
  }
  return SpanHelpers::IndexOf(_firstChar, get_Length(), value->_firstChar, value->get_Length()) >= 0;
}

Boolean String___::Contains(String value, StringComparison comparisonType) {
  return IndexOf(value, comparisonType) >= 0;
}

Boolean String___::Contains(Char value) {
  return SpanHelpers::Contains(_firstChar, value, get_Length());
}

Boolean String___::Contains(Char value, StringComparison comparisonType) {
  return IndexOf(value, comparisonType) != -1;
}

Int32 String___::IndexOf(Char value) {
  return SpanHelpers::IndexOf(_firstChar, value, get_Length());
}

Int32 String___::IndexOf(Char value, Int32 startIndex) {
  return IndexOf(value, startIndex, get_Length() - startIndex);
}

Int32 String___::IndexOf(Char value, StringComparison comparisonType) {
  switch (comparisonType) {
    case StringComparison::CurrentCulture:
    case StringComparison::CurrentCultureIgnoreCase:
      return CultureInfo::in::get_CurrentCulture()->get_CompareInfo()->IndexOf((String)this, value, GetCaseCompareOfComparisonCulture(comparisonType));
    case StringComparison::InvariantCulture:
    case StringComparison::InvariantCultureIgnoreCase:
      return CompareInfo::in::Invariant->IndexOf((String)this, value, GetCaseCompareOfComparisonCulture(comparisonType));
    case StringComparison::Ordinal:
      return IndexOf(value);
    case StringComparison::OrdinalIgnoreCase:
      return CompareInfo::in::Invariant->IndexOf((String)this, value, CompareOptions::OrdinalIgnoreCase);
    default:
      rt::throw_exception<ArgumentException>(SR::get_NotSupported_StringComparison(), "comparisonType");
  }
}

Int32 String___::IndexOf(Char value, Int32 startIndex, Int32 count) {
  if ((UInt32)startIndex > (UInt32)get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("startIndex", SR::get_ArgumentOutOfRange_Index());
  }
  if ((UInt32)count > (UInt32)(get_Length() - startIndex)) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_Count());
  }
  Int32 num = SpanHelpers::IndexOf(Unsafe::Add(_firstChar, startIndex), value, count);
  if (num != -1) {
    return num + startIndex;
  }
  return num;
}

Int32 String___::IndexOfAny(Array<Char> anyOf) {
  return IndexOfAny(anyOf, 0, get_Length());
}

Int32 String___::IndexOfAny(Array<Char> anyOf, Int32 startIndex) {
  return IndexOfAny(anyOf, startIndex, get_Length() - startIndex);
}

Int32 String___::IndexOfAny(Array<Char> anyOf, Int32 startIndex, Int32 count) {
  if (anyOf == nullptr) {
    rt::throw_exception<ArgumentNullException>("anyOf");
  }
  if ((UInt32)startIndex > (UInt32)get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("startIndex", SR::get_ArgumentOutOfRange_Index());
  }
  if ((UInt32)count > (UInt32)(get_Length() - startIndex)) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_Count());
  }
  if (anyOf->get_Length() != 0 && anyOf->get_Length() <= 5) {
    Int32 num = MemoryExtensions::IndexOfAny(ReadOnlySpan<Char>(Unsafe::Add(_firstChar, startIndex), count), anyOf);
    if (num != -1) {
      return num + startIndex;
    }
    return num;
  }
  if (anyOf->get_Length() > 5) {
    return IndexOfCharArray(anyOf, startIndex, count);
  }
  return -1;
}

Int32 String___::IndexOfCharArray(Array<Char> anyOf, Int32 startIndex, Int32 count) {
  ProbabilisticMap probabilisticMap = ProbabilisticMap();
  UInt32* charMap = (UInt32*)(&probabilisticMap);
  InitializeProbabilisticMap(charMap, anyOf);
  {
    Char* ptr = &_firstChar;
    Char* ptr2 = ptr + startIndex;
    while (count > 0) {
      Int32 num = *ptr2;
      if (IsCharBitSet(charMap, (Byte)num) && IsCharBitSet(charMap, (Byte)(num >> 8)) && ArrayContains((Char)num, anyOf)) {
        return (Int32)(ptr2 - ptr);
      }
      count--;
      ptr2++;
    }
    return -1;
  }
}

void String___::InitializeProbabilisticMap(UInt32* charMap, ReadOnlySpan<Char> anyOf) {
  Boolean flag = false;
  for (Int32 i = 0; i < anyOf.get_Length(); i++) {
    Int32 num = anyOf[i];
    SetCharBit(charMap, (Byte)num);
    num >>= 8;
    if (num == 0) {
      flag = true;
    } else {
      SetCharBit(charMap, (Byte)num);
    }
  }
  if (flag) {
    *charMap |= 1u;
  }
}

Boolean String___::ArrayContains(Char searchChar, Array<Char> anyOf) {
  for (Int32 i = 0; i < anyOf->get_Length(); i++) {
    if (anyOf[i] == searchChar) {
      return true;
    }
  }
  return false;
}

Boolean String___::IsCharBitSet(UInt32* charMap, Byte value) {
  return ((Int32)charMap[value & 7] & (1 << (value >> 3))) != 0;
}

void String___::SetCharBit(UInt32* charMap, Byte value) {
  charMap[value & 7] |= (UInt32)(1 << (value >> 3));
}

Int32 String___::IndexOf(String value) {
  return IndexOf(value, StringComparison::CurrentCulture);
}

Int32 String___::IndexOf(String value, Int32 startIndex) {
  return IndexOf(value, startIndex, StringComparison::CurrentCulture);
}

Int32 String___::IndexOf(String value, Int32 startIndex, Int32 count) {
  return IndexOf(value, startIndex, count, StringComparison::CurrentCulture);
}

Int32 String___::IndexOf(String value, StringComparison comparisonType) {
  return IndexOf(value, 0, get_Length(), comparisonType);
}

Int32 String___::IndexOf(String value, Int32 startIndex, StringComparison comparisonType) {
  return IndexOf(value, startIndex, get_Length() - startIndex, comparisonType);
}

Int32 String___::IndexOf(String value, Int32 startIndex, Int32 count, StringComparison comparisonType) {
  switch (comparisonType) {
    case StringComparison::CurrentCulture:
    case StringComparison::CurrentCultureIgnoreCase:
      return CultureInfo::in::get_CurrentCulture()->get_CompareInfo()->IndexOf((String)this, value, startIndex, count, GetCaseCompareOfComparisonCulture(comparisonType));
    case StringComparison::InvariantCulture:
    case StringComparison::InvariantCultureIgnoreCase:
      return CompareInfo::in::Invariant->IndexOf((String)this, value, startIndex, count, GetCaseCompareOfComparisonCulture(comparisonType));
    case StringComparison::Ordinal:
    case StringComparison::OrdinalIgnoreCase:
      return CompareInfo::in::Invariant->IndexOf((String)this, value, startIndex, count, GetCompareOptionsFromOrdinalStringComparison(comparisonType));
    default:
      rt::throw_exception((value == nullptr) ? rt::newobj<ArgumentNullException>("value") : rt::newobj<ArgumentException>(SR::get_NotSupported_StringComparison(), "comparisonType"));
  }
}

Int32 String___::LastIndexOf(Char value) {
  return SpanHelpers::LastIndexOf(_firstChar, value, get_Length());
}

Int32 String___::LastIndexOf(Char value, Int32 startIndex) {
  return LastIndexOf(value, startIndex, startIndex + 1);
}

Int32 String___::LastIndexOf(Char value, Int32 startIndex, Int32 count) {
  if (get_Length() == 0) {
    return -1;
  }
  if ((UInt32)startIndex >= (UInt32)get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("startIndex", SR::get_ArgumentOutOfRange_Index());
  }
  if ((UInt32)count > (UInt32)(startIndex + 1)) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_Count());
  }
  Int32 num = startIndex + 1 - count;
  Int32 num2 = SpanHelpers::LastIndexOf(Unsafe::Add(_firstChar, num), value, count);
  if (num2 != -1) {
    return num2 + num;
  }
  return num2;
}

Int32 String___::LastIndexOfAny(Array<Char> anyOf) {
  return LastIndexOfAny(anyOf, get_Length() - 1, get_Length());
}

Int32 String___::LastIndexOfAny(Array<Char> anyOf, Int32 startIndex) {
  return LastIndexOfAny(anyOf, startIndex, startIndex + 1);
}

Int32 String___::LastIndexOfAny(Array<Char> anyOf, Int32 startIndex, Int32 count) {
  if (anyOf == nullptr) {
    rt::throw_exception<ArgumentNullException>("anyOf");
  }
  if (get_Length() == 0) {
    return -1;
  }
  if ((UInt32)startIndex >= (UInt32)get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("startIndex", SR::get_ArgumentOutOfRange_Index());
  }
  if (count < 0 || count - 1 > startIndex) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_Count());
  }
  if (anyOf->get_Length() > 1) {
    return LastIndexOfCharArray(anyOf, startIndex, count);
  }
  if (anyOf->get_Length() == 1) {
    return LastIndexOf(anyOf[0], startIndex, count);
  }
  return -1;
}

Int32 String___::LastIndexOfCharArray(Array<Char> anyOf, Int32 startIndex, Int32 count) {
  ProbabilisticMap probabilisticMap = ProbabilisticMap();
  UInt32* charMap = (UInt32*)(&probabilisticMap);
  InitializeProbabilisticMap(charMap, anyOf);
  {
    Char* ptr = &_firstChar;
    Char* ptr2 = ptr + startIndex;
    while (count > 0) {
      Int32 num = *ptr2;
      if (IsCharBitSet(charMap, (Byte)num) && IsCharBitSet(charMap, (Byte)(num >> 8)) && ArrayContains((Char)num, anyOf)) {
        return (Int32)(ptr2 - ptr);
      }
      count--;
      ptr2--;
    }
    return -1;
  }
}

Int32 String___::LastIndexOf(String value) {
  return LastIndexOf(value, get_Length() - 1, get_Length(), StringComparison::CurrentCulture);
}

Int32 String___::LastIndexOf(String value, Int32 startIndex) {
  return LastIndexOf(value, startIndex, startIndex + 1, StringComparison::CurrentCulture);
}

Int32 String___::LastIndexOf(String value, Int32 startIndex, Int32 count) {
  return LastIndexOf(value, startIndex, count, StringComparison::CurrentCulture);
}

Int32 String___::LastIndexOf(String value, StringComparison comparisonType) {
  return LastIndexOf(value, get_Length() - 1, get_Length(), comparisonType);
}

Int32 String___::LastIndexOf(String value, Int32 startIndex, StringComparison comparisonType) {
  return LastIndexOf(value, startIndex, startIndex + 1, comparisonType);
}

Int32 String___::LastIndexOf(String value, Int32 startIndex, Int32 count, StringComparison comparisonType) {
  switch (comparisonType) {
    case StringComparison::CurrentCulture:
    case StringComparison::CurrentCultureIgnoreCase:
      return CultureInfo::in::get_CurrentCulture()->get_CompareInfo()->LastIndexOf((String)this, value, startIndex, count, GetCaseCompareOfComparisonCulture(comparisonType));
    case StringComparison::InvariantCulture:
    case StringComparison::InvariantCultureIgnoreCase:
      return CompareInfo::in::Invariant->LastIndexOf((String)this, value, startIndex, count, GetCaseCompareOfComparisonCulture(comparisonType));
    case StringComparison::Ordinal:
    case StringComparison::OrdinalIgnoreCase:
      return CompareInfo::in::Invariant->LastIndexOf((String)this, value, startIndex, count, GetCompareOptionsFromOrdinalStringComparison(comparisonType));
    default:
      rt::throw_exception((value == nullptr) ? rt::newobj<ArgumentNullException>("value") : rt::newobj<ArgumentException>(SR::get_NotSupported_StringComparison(), "comparisonType"));
  }
}

} // namespace System::Private::CoreLib::System::StringNamespace
