#include "DefaultValueAttribute-dep.h"

#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/ComponentModel/DefaultValueAttribute-dep.h>
#include <System.Private.CoreLib/System/Convert-dep.h>
#include <System.Private.CoreLib/System/Enum-dep.h>
#include <System.Private.CoreLib/System/Func-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/BindingFlags.h>
#include <System.Private.CoreLib/System/Reflection/MethodInfo-dep.h>
#include <System.Private.CoreLib/System/Threading/Volatile-dep.h>
#include <System.Private.CoreLib/System/TimeSpan-dep.h>

namespace System::Private::CoreLib::System::ComponentModel::DefaultValueAttributeNamespace {
using namespace System::Globalization;
using namespace System::Reflection;
using namespace System::Threading;

Object DefaultValueAttribute___::get_Value() {
  return _value;
}

void DefaultValueAttribute___::ctor(Type type, String value) {
  auto TryConvertFromInvariantString = [](Type typeToConvert, String stringValue, Object& conversionResult) -> Boolean {
    conversionResult = nullptr;
    if (s_convertFromInvariantString == nullptr) {
      Type type2 = Type::in::GetType("System.ComponentModel.TypeDescriptor, System.ComponentModel.TypeConverter", false);
      MethodInfo methodInfo = (((Object)type2 != nullptr) ? type2->GetMethod("ConvertFromInvariantString", BindingFlags::Static | BindingFlags::NonPublic) : nullptr);
      Volatile::Write(s_convertFromInvariantString, (methodInfo == nullptr) ? rt::newobj<Object>() : methodInfo->CreateDelegate(typeof<Func<Type, String, Object>>()));
    }
    Func<Type, String, Object> func = rt::as<Func<Type, String, Object>>(s_convertFromInvariantString);
    if (func == nullptr) {
      return false;
    }
    try {
      conversionResult = func(typeToConvert, stringValue);
    } catch (...) {
      return false;
    }
    return true;
  };
  if (type == nullptr) {
    return;
  }
  try {
    Object conversionResult2;
    if (TryConvertFromInvariantString(type, value, conversionResult2)) {
      _value = conversionResult2;
    } else if (type->IsSubclassOf(typeof<Enum>()) && value != nullptr) {
      _value = Enum::in::Parse(type, value, true);
    } else if (type == typeof<TimeSpan>() && value != nullptr) {
      _value = TimeSpan::Parse(value);
    } else {
      _value = Convert::ChangeType(value, type, CultureInfo::in::get_InvariantCulture());
    }


  } catch (...) {
  }
}

void DefaultValueAttribute___::ctor(Char value) {
  _value = value;
}

void DefaultValueAttribute___::ctor(Byte value) {
  _value = value;
}

void DefaultValueAttribute___::ctor(Int16 value) {
  _value = value;
}

void DefaultValueAttribute___::ctor(Int32 value) {
  _value = value;
}

void DefaultValueAttribute___::ctor(Int64 value) {
  _value = value;
}

void DefaultValueAttribute___::ctor(Single value) {
  _value = value;
}

void DefaultValueAttribute___::ctor(Double value) {
  _value = value;
}

void DefaultValueAttribute___::ctor(Boolean value) {
  _value = value;
}

void DefaultValueAttribute___::ctor(String value) {
  _value = value;
}

void DefaultValueAttribute___::ctor(Object value) {
  _value = value;
}

void DefaultValueAttribute___::ctor(SByte value) {
  _value = value;
}

void DefaultValueAttribute___::ctor(UInt16 value) {
  _value = value;
}

void DefaultValueAttribute___::ctor(UInt32 value) {
  _value = value;
}

void DefaultValueAttribute___::ctor(UInt64 value) {
  _value = value;
}

Boolean DefaultValueAttribute___::Equals(Object obj) {
  if (obj == (DefaultValueAttribute)this) {
    return true;
  }
  DefaultValueAttribute defaultValueAttribute = rt::as<DefaultValueAttribute>(obj);
  if (defaultValueAttribute == nullptr) {
    return false;
  }
  if (get_Value() == nullptr) {
    return defaultValueAttribute->get_Value() == nullptr;
  }
  return get_Value()->Equals(defaultValueAttribute->get_Value());
}

Int32 DefaultValueAttribute___::GetHashCode() {
  return Attribute::in::GetHashCode();
}

void DefaultValueAttribute___::SetValue(Object value) {
  _value = value;
}

Boolean DefaultValueAttribute___::_ctor_g__TryConvertFromInvariantString2_0(Type typeToConvert, String stringValue, Object& conversionResult) {
  conversionResult = nullptr;
  if (s_convertFromInvariantString == nullptr) {
    Type type = Type::in::GetType("System.ComponentModel.TypeDescriptor, System.ComponentModel.TypeConverter", false);
    MethodInfo methodInfo = (((Object)type != nullptr) ? type->GetMethod("ConvertFromInvariantString", BindingFlags::Static | BindingFlags::NonPublic) : nullptr);
    Volatile::Write(s_convertFromInvariantString, (methodInfo == nullptr) ? rt::newobj<Object>() : methodInfo->CreateDelegate(typeof<Func<Type, String, Object>>()));
  }
  Func<Type, String, Object> func = rt::as<Func<Type, String, Object>>(s_convertFromInvariantString);
  if (func == nullptr) {
    return false;
  }
  try {
    conversionResult = func(typeToConvert, stringValue);
  } catch (...) {
    return false;
  }
  return true;
}

} // namespace System::Private::CoreLib::System::ComponentModel::DefaultValueAttributeNamespace
