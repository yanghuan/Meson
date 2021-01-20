#include "Version-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/NumberStyles.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/StringBuilder-dep.h>
#include <System.Private.CoreLib/System/Text/StringBuilderCache-dep.h>
#include <System.Private.CoreLib/System/Version-dep.h>

namespace System::Private::CoreLib::System::VersionNamespace {
using namespace System::Globalization;
using namespace System::Text;

Int32 Version___::get_Major() {
  return _Major;
}

Int32 Version___::get_Minor() {
  return _Minor;
}

Int32 Version___::get_Build() {
  return _Build;
}

Int32 Version___::get_Revision() {
  return _Revision;
}

Int16 Version___::get_MajorRevision() {
  return (Int16)(_Revision >> 16);
}

Int16 Version___::get_MinorRevision() {
  return (Int16)(_Revision & 65535);
}

Int32 Version___::get_DefaultFormatFieldCount() {
  if (_Build != -1) {
    if (_Revision != -1) {
      return 4;
    }
    return 3;
  }
  return 2;
}

void Version___::ctor(Int32 major, Int32 minor, Int32 build, Int32 revision) {
  if (major < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("major", SR::get_ArgumentOutOfRange_Version());
  }
  if (minor < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("minor", SR::get_ArgumentOutOfRange_Version());
  }
  if (build < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("build", SR::get_ArgumentOutOfRange_Version());
  }
  if (revision < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("revision", SR::get_ArgumentOutOfRange_Version());
  }
  _Major = major;
  _Minor = minor;
  _Build = build;
  _Revision = revision;
}

void Version___::ctor(Int32 major, Int32 minor, Int32 build) {
  if (major < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("major", SR::get_ArgumentOutOfRange_Version());
  }
  if (minor < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("minor", SR::get_ArgumentOutOfRange_Version());
  }
  if (build < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("build", SR::get_ArgumentOutOfRange_Version());
  }
  _Major = major;
  _Minor = minor;
  _Build = build;
  _Revision = -1;
}

void Version___::ctor(Int32 major, Int32 minor) {
  if (major < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("major", SR::get_ArgumentOutOfRange_Version());
  }
  if (minor < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("minor", SR::get_ArgumentOutOfRange_Version());
  }
  _Major = major;
  _Minor = minor;
  _Build = -1;
  _Revision = -1;
}

void Version___::ctor(String version) {
  Version version2 = Parse(version);
  _Major = version2->get_Major();
  _Minor = version2->get_Minor();
  _Build = version2->get_Build();
  _Revision = version2->get_Revision();
}

void Version___::ctor() {
  _Build = -1;
  _Revision = -1;
}

void Version___::ctor(Version version) {
  _Major = version->_Major;
  _Minor = version->_Minor;
  _Build = version->_Build;
  _Revision = version->_Revision;
}

Object Version___::Clone() {
  return rt::newobj<Version>((Version)this);
}

Int32 Version___::CompareTo(Object version) {
  if (version == nullptr) {
    return 1;
  }
  Version version2 = rt::as<Version>(version);
  if ((Object)version2 != nullptr) {
    return CompareTo(version2);
  }
  rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeVersion());
}

Int32 Version___::CompareTo(Version value) {
  if ((Object)value != (Version)this) {
    if ((Object)value != nullptr) {
      if (_Major == value->_Major) {
        if (_Minor == value->_Minor) {
          if (_Build == value->_Build) {
            if (_Revision == value->_Revision) {
              return 0;
            }
            if (_Revision <= value->_Revision) {
              return -1;
            }
            return 1;
          }
          if (_Build <= value->_Build) {
            return -1;
          }
          return 1;
        }
        if (_Minor <= value->_Minor) {
          return -1;
        }
        return 1;
      }
      if (_Major <= value->_Major) {
        return -1;
      }
      return 1;
    }
    return 1;
  }
  return 0;
}

Boolean Version___::Equals(Object obj) {
  return Equals(rt::as<Version>(obj));
}

Boolean Version___::Equals(Version obj) {
  if ((Object)obj != (Version)this) {
    if ((Object)obj != nullptr && _Major == obj->_Major && _Minor == obj->_Minor && _Build == obj->_Build) {
      return _Revision == obj->_Revision;
    }
    return false;
  }
  return true;
}

Int32 Version___::GetHashCode() {
  Int32 num = 0;
  num |= (_Major & 15) << 28;
  num |= (_Minor & 255) << 20;
  num |= (_Build & 255) << 12;
  return num | (_Revision & 4095);
}

String Version___::ToString() {
  return ToString(get_DefaultFormatFieldCount());
}

String Version___::ToString(Int32 fieldCount) {
}

Boolean Version___::TryFormat(Span<Char> destination, Int32& charsWritten) {
  return TryFormat(destination, get_DefaultFormatFieldCount(), charsWritten);
}

Boolean Version___::TryFormat(Span<Char> destination, Int32 fieldCount, Int32& charsWritten) {
  switch (fieldCount.get()) {
    case 0:
      charsWritten = 0;
      return true;
    case 1:
      return _Major.TryFormat(destination, charsWritten);
    default:
      {
        StringBuilder stringBuilder = ToCachedStringBuilder(fieldCount);
        if (stringBuilder->get_Length() <= destination.get_Length()) {
          stringBuilder->CopyTo(0, destination, stringBuilder->get_Length());
          StringBuilderCache::Release(stringBuilder);
          charsWritten = stringBuilder->set_Length();
          return true;
        }
        StringBuilderCache::Release(stringBuilder);
        charsWritten = 0;
        return false;
      }}
}

Boolean Version___::TryFormatOfISpanFormattable(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider provider) {
  return TryFormat(destination, charsWritten);
}

StringBuilder Version___::ToCachedStringBuilder(Int32 fieldCount) {
  if (fieldCount == 2) {
    StringBuilder stringBuilder = StringBuilderCache::Acquire();
    stringBuilder->Append(_Major);
    stringBuilder->Append((Char)u'.');
    stringBuilder->Append(_Minor);
    return stringBuilder;
  }
  if (_Build == -1) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_ArgumentOutOfRange_Bounds_Lower_Upper(), "0", "2"), "fieldCount");
  }
  if (fieldCount == 3) {
    StringBuilder stringBuilder2 = StringBuilderCache::Acquire();
    stringBuilder2->Append(_Major);
    stringBuilder2->Append((Char)u'.');
    stringBuilder2->Append(_Minor);
    stringBuilder2->Append((Char)u'.');
    stringBuilder2->Append(_Build);
    return stringBuilder2;
  }
  if (_Revision == -1) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_ArgumentOutOfRange_Bounds_Lower_Upper(), "0", "3"), "fieldCount");
  }
  if (fieldCount == 4) {
    StringBuilder stringBuilder3 = StringBuilderCache::Acquire();
    stringBuilder3->Append(_Major);
    stringBuilder3->Append((Char)u'.');
    stringBuilder3->Append(_Minor);
    stringBuilder3->Append((Char)u'.');
    stringBuilder3->Append(_Build);
    stringBuilder3->Append((Char)u'.');
    stringBuilder3->Append(_Revision);
    return stringBuilder3;
  }
  rt::throw_exception<ArgumentException>(SR::Format(SR::get_ArgumentOutOfRange_Bounds_Lower_Upper(), "0", "4"), "fieldCount");
}

Version Version___::Parse(String input) {
  if (input == nullptr) {
    rt::throw_exception<ArgumentNullException>("input");
  }
  return ParseVersion(MemoryExtensions::AsSpan(input), true);
}

Version Version___::Parse(ReadOnlySpan<Char> input) {
  return ParseVersion(input, true);
}

Boolean Version___::TryParse(String input, Version& result) {
  if (input == nullptr) {
    result = nullptr;
    return false;
  }
  return (result = ParseVersion(MemoryExtensions::AsSpan(input), false)) != nullptr;
}

Boolean Version___::TryParse(ReadOnlySpan<Char> input, Version& result) {
  return (result = ParseVersion(input, false)) != nullptr;
}

Version Version___::ParseVersion(ReadOnlySpan<Char> input, Boolean throwOnFailure) {
  Int32 num = MemoryExtensions::IndexOf(input, u'.');
  if (num < 0) {
    if (throwOnFailure) {
      rt::throw_exception<ArgumentException>(SR::get_Arg_VersionString(), "input");
    }
    return nullptr;
  }
  Int32 num2 = -1;
  Int32 num3 = MemoryExtensions::IndexOf(input.Slice(num + 1), u'.');
  if (num3 != -1) {
    num3 += num + 1;
    num2 = MemoryExtensions::IndexOf(input.Slice(num3 + 1), u'.');
    if (num2 != -1) {
      num2 += num3 + 1;
      if (MemoryExtensions::Contains(input.Slice(num2 + 1), u'.')) {
        if (throwOnFailure) {
          rt::throw_exception<ArgumentException>(SR::get_Arg_VersionString(), "input");
        }
        return nullptr;
      }
    }
  }
  Int32 parsedComponent;
  if (!TryParseComponent(input.Slice(0, num), "input", throwOnFailure, parsedComponent)) {
    return nullptr;
  }
  Int32 parsedComponent2;
  if (num3 != -1) {
    if (!TryParseComponent(input.Slice(num + 1, num3 - num - 1), "input", throwOnFailure, parsedComponent2)) {
      return nullptr;
    }
    Int32 parsedComponent3;
    if (num2 != -1) {
      Int32 parsedComponent4;
      if (!TryParseComponent(input.Slice(num3 + 1, num2 - num3 - 1), "build", throwOnFailure, parsedComponent3) || !TryParseComponent(input.Slice(num2 + 1), "revision", throwOnFailure, parsedComponent4)) {
        return nullptr;
      }
      return rt::newobj<Version>(parsedComponent, parsedComponent2, parsedComponent3, parsedComponent4);
    }
    if (!TryParseComponent(input.Slice(num3 + 1), "build", throwOnFailure, parsedComponent3)) {
      return nullptr;
    }
    return rt::newobj<Version>(parsedComponent, parsedComponent2, parsedComponent3);
  }
  if (!TryParseComponent(input.Slice(num + 1), "input", throwOnFailure, parsedComponent2)) {
    return nullptr;
  }
  return rt::newobj<Version>(parsedComponent, parsedComponent2);
}

Boolean Version___::TryParseComponent(ReadOnlySpan<Char> component, String componentName, Boolean throwOnFailure, Int32& parsedComponent) {
  if (throwOnFailure) {
    if ((parsedComponent = Int32::Parse(component, NumberStyles::Integer, CultureInfo::in::get_InvariantCulture())) < 0) {
      rt::throw_exception<ArgumentOutOfRangeException>(componentName, SR::get_ArgumentOutOfRange_Version());
    }
    return true;
  }
  if (Int32::TryParse(component, NumberStyles::Integer, CultureInfo::in::get_InvariantCulture(), parsedComponent)) {
    return parsedComponent >= 0;
  }
  return false;
}

Boolean Version___::op_Equality(Version v1, Version v2) {
  if ((Object)v2 == nullptr) {
    if ((Object)v1 != nullptr) {
      return false;
    }
    return true;
  }
  if ((Object)v2 != v1) {
    return v2->Equals(v1);
  }
  return true;
}

Boolean Version___::op_Inequality(Version v1, Version v2) {
  return !(v1 == v2);
}

Boolean Version___::op_LessThan(Version v1, Version v2) {
  if ((Object)v1 == nullptr) {
    return (Object)v2 != nullptr;
  }
  return v1->CompareTo(v2) < 0;
}

Boolean Version___::op_LessThanOrEqual(Version v1, Version v2) {
  if ((Object)v1 == nullptr) {
    return true;
  }
  return v1->CompareTo(v2) <= 0;
}

Boolean Version___::op_GreaterThan(Version v1, Version v2) {
  return v2 < v1;
}

Boolean Version___::op_GreaterThanOrEqual(Version v1, Version v2) {
  return v2 <= v1;
}

} // namespace System::Private::CoreLib::System::VersionNamespace
