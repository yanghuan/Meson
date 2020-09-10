#include "FrameworkName-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/ReadOnlySpan-dep.h>
#include <System.Private.CoreLib/System/Runtime/Versioning/FrameworkName-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/StringComparison.h>

namespace System::Private::CoreLib::System::Runtime::Versioning::FrameworkNameNamespace {
String FrameworkName___::get_Identifier() {
  return _identifier;
}

Version FrameworkName___::get_Version() {
  return _version;
}

String FrameworkName___::get_Profile() {
  return _profile;
}

String FrameworkName___::get_FullName() {
  if (_fullName == nullptr) {
    if (String::in::IsNullOrEmpty(get_Profile())) {
      _fullName = get_Identifier() + ",Version=v" + get_Version()->ToString();
    } else {
      _fullName = get_Identifier() + ",Version=v" + get_Version()->ToString() + ",Profile=" + get_Profile();
    }
  }
  return _fullName;
}

Boolean FrameworkName___::Equals(Object obj) {
  return Equals(rt::as<FrameworkName>(obj));
}

Boolean FrameworkName___::Equals(FrameworkName other) {
  if ((Object)other == nullptr) {
    return false;
  }
  if (get_Identifier() == other->get_Identifier() && get_Version() == other->get_Version()) {
    return get_Profile() == other->get_Profile();
  }
  return false;
}

Int32 FrameworkName___::GetHashCode() {
  return get_Identifier()->GetHashCode() ^ get_Version()->GetHashCode() ^ get_Profile()->GetHashCode();
}

String FrameworkName___::ToString() {
  return get_FullName();
}

void FrameworkName___::ctor(String identifier, Version version) {
}

void FrameworkName___::ctor(String identifier, Version version, String profile) {
  if (identifier == nullptr) {
    rt::throw_exception<ArgumentNullException>("identifier");
  }
  identifier = identifier->Trim();
  if (identifier->get_Length() == 0) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_net_emptystringcall(), "identifier"), "identifier");
  }
  if (version == nullptr) {
    rt::throw_exception<ArgumentNullException>("version");
  }
  _identifier = identifier;
  _version = version;
  _profile = ((profile == nullptr) ? String::in::Empty : profile->Trim());
}

void FrameworkName___::ctor(String frameworkName) {
  if (frameworkName == nullptr) {
    rt::throw_exception<ArgumentNullException>("frameworkName");
  }
  if (frameworkName->get_Length() == 0) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_net_emptystringcall(), "frameworkName"), "frameworkName");
  }
  Array<String> array = frameworkName->Split(',');
  if (array->get_Length() < 2 || array->get_Length() > 3) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_FrameworkNameTooShort(), "frameworkName");
  }
  _identifier = array[0]->Trim();
  if (_identifier->get_Length() == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_FrameworkNameInvalid(), "frameworkName");
  }
  Boolean flag = false;
  _profile = String::in::Empty;
  for (Int32 i = 1; i < array->get_Length(); i++) {
    String text = array[i];
    Int32 num = text->IndexOf('=');
    if (num == -1 || num != text->LastIndexOf('=')) {
      rt::throw_exception<ArgumentException>(SR::get_Argument_FrameworkNameInvalid(), "frameworkName");
    }
    ReadOnlySpan<Char> span = MemoryExtensions::Trim(MemoryExtensions::AsSpan(text, 0, num));
    ReadOnlySpan<Char> input = MemoryExtensions::Trim(MemoryExtensions::AsSpan(text, num + 1));
    if (MemoryExtensions::Equals(MemoryExtensions, span, "Version", StringComparison::OrdinalIgnoreCase)) {
      flag = true;
      if (input.get_Length() > 0 && (input[0] == 'v' || input[0] == 'V')) {
        input = input.Slice(1);
      }
      try {
        _version = Version::in::Parse(input);
      } catch (Exception innerException) {
        rt::throw_exception<ArgumentException>(SR::get_Argument_FrameworkNameInvalidVersion(), "frameworkName", innerException);
      }
    } else {
      if (!MemoryExtensions::Equals(MemoryExtensions, span, "Profile", StringComparison::OrdinalIgnoreCase)) {
        rt::throw_exception<ArgumentException>(SR::get_Argument_FrameworkNameInvalid(), "frameworkName");
      }
      if (input.get_Length() > 0) {
        _profile = input.ToString();
      }
    }
  }
  if (!flag) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_FrameworkNameMissingVersion(), "frameworkName");
  }
}

Boolean FrameworkName___::op_Equality(FrameworkName left, FrameworkName right) {
  if ((Object)left == nullptr) {
    return (Object)right == nullptr;
  }
  return left->Equals(right);
}

Boolean FrameworkName___::op_Inequality(FrameworkName left, FrameworkName right) {
  return !(left == right);
}

} // namespace System::Private::CoreLib::System::Runtime::Versioning::FrameworkNameNamespace
