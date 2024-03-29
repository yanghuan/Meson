#include "SerializationInfo-dep.h"

#include <System.Private.CoreLib/System/AppContext-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Array-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/Dictionary-dep.h>
#include <System.Private.CoreLib/System/LocalAppContextSwitches-dep.h>
#include <System.Private.CoreLib/System/Runtime/Serialization/DeserializationTracker-dep.h>
#include <System.Private.CoreLib/System/Runtime/Serialization/SerializationException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Threading/StackCrawlMark.h>
#include <System.Private.CoreLib/System/Threading/Thread-dep.h>

namespace System::Private::CoreLib::System::Runtime::Serialization::SerializationInfoNamespace {
using namespace System::Collections::Generic;
using namespace System::Threading;

String SerializationInfo___::get_FullTypeName() {
  return _rootTypeName;
}

void SerializationInfo___::set_FullTypeName(String value) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  _rootTypeName = value;
  IsFullTypeNameSetExplicit = true;
}

String SerializationInfo___::get_AssemblyName() {
  return _rootTypeAssemblyName;
}

void SerializationInfo___::set_AssemblyName(String value) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  _rootTypeAssemblyName = value;
  IsAssemblyNameSetExplicit = true;
}

Int32 SerializationInfo___::get_MemberCount() {
  return _count;
}

Type SerializationInfo___::get_ObjectType() {
  return _rootType;
}

Boolean SerializationInfo___::get_DeserializationInProgress() {
  if (AsyncDeserializationInProgress->get_Value()) {
    return true;
  }
  StackCrawlMark stackMark = StackCrawlMark::LookForMe;
  DeserializationTracker threadDeserializationTracker = Thread::in::GetThreadDeserializationTracker(stackMark);
  return threadDeserializationTracker->get_DeserializationInProgress();
}

void SerializationInfo___::ctor(Type type, IFormatterConverter converter) {
  if ((Object)type == nullptr) {
    rt::throw_exception<ArgumentNullException>("type");
  }
  if (converter == nullptr) {
    rt::throw_exception<ArgumentNullException>("converter");
  }
  _rootType = type;
  _rootTypeName = type->get_FullName();
  _rootTypeAssemblyName = type->get_Module()->get_Assembly()->get_FullName();
  _names = rt::newarr<Array<String>>(4);
  _values = rt::newarr<Array<Object>>(4);
  _types = rt::newarr<Array<Type>>(4);
  _nameToIndex = rt::newobj<Dictionary<String, Int32>>();
  _converter = converter;
}

void SerializationInfo___::ctor(Type type, IFormatterConverter converter, Boolean requireSameTokenInPartialTrust) {
}

void SerializationInfo___::SetType(Type type) {
  if ((Object)type == nullptr) {
    rt::throw_exception<ArgumentNullException>("type");
  }
  if ((Object)_rootType != type) {
    _rootType = type;
    _rootTypeName = type->get_FullName();
    _rootTypeAssemblyName = type->get_Module()->get_Assembly()->get_FullName();
    IsFullTypeNameSetExplicit = false;
    IsAssemblyNameSetExplicit = false;
  }
}

SerializationInfoEnumerator SerializationInfo___::GetEnumerator() {
  return rt::newobj<SerializationInfoEnumerator>(_names, _values, _types, _count);
}

void SerializationInfo___::ExpandArrays() {
  Int32 num = _count * 2;
  if (num < _count && Int32::MaxValue() > _count) {
    num = Int32::MaxValue();
  }
  Array<String> array = rt::newarr<Array<String>>(num);
  Array<Object> array2 = rt::newarr<Array<Object>>(num);
  Array<Type> array3 = rt::newarr<Array<Type>>(num);
  Array<>::in::Copy(_names, array, _count);
  Array<>::in::Copy(_values, array2, _count);
  Array<>::in::Copy(_types, array3, _count);
  _names = array;
  _values = array2;
  _types = array3;
}

void SerializationInfo___::AddValue(String name, Object value, Type type) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  if ((Object)type == nullptr) {
    rt::throw_exception<ArgumentNullException>("type");
  }
  AddValueInternal(name, value, type);
}

void SerializationInfo___::AddValue(String name, Object value) {
  if (value == nullptr) {
    AddValue(name, value, typeof<Object>());
  } else {
    AddValue(name, value, value->GetType());
  }
}

void SerializationInfo___::AddValue(String name, Boolean value) {
  AddValue(name, value, typeof<Boolean>());
}

void SerializationInfo___::AddValue(String name, Char value) {
  AddValue(name, value, typeof<Char>());
}

void SerializationInfo___::AddValue(String name, SByte value) {
  AddValue(name, value, typeof<SByte>());
}

void SerializationInfo___::AddValue(String name, Byte value) {
  AddValue(name, value, typeof<Byte>());
}

void SerializationInfo___::AddValue(String name, Int16 value) {
  AddValue(name, value, typeof<Int16>());
}

void SerializationInfo___::AddValue(String name, UInt16 value) {
  AddValue(name, value, typeof<UInt16>());
}

void SerializationInfo___::AddValue(String name, Int32 value) {
  AddValue(name, value, typeof<Int32>());
}

void SerializationInfo___::AddValue(String name, UInt32 value) {
  AddValue(name, value, typeof<UInt32>());
}

void SerializationInfo___::AddValue(String name, Int64 value) {
  AddValue(name, value, typeof<Int64>());
}

void SerializationInfo___::AddValue(String name, UInt64 value) {
  AddValue(name, value, typeof<UInt64>());
}

void SerializationInfo___::AddValue(String name, Single value) {
  AddValue(name, value, typeof<Single>());
}

void SerializationInfo___::AddValue(String name, Double value) {
  AddValue(name, value, typeof<Double>());
}

void SerializationInfo___::AddValue(String name, Decimal value) {
  AddValue(name, value, typeof<Decimal>());
}

void SerializationInfo___::AddValue(String name, DateTime value) {
  AddValue(name, value, typeof<DateTime>());
}

void SerializationInfo___::AddValueInternal(String name, Object value, Type type) {
  if (_nameToIndex->ContainsKey(name)) {
    rt::throw_exception<SerializationException>(SR::get_Serialization_SameNameTwice());
  }
  _nameToIndex->Add(name, _count);
  if (_count >= _names->get_Length()) {
    ExpandArrays();
  }
  _names[_count] = name;
  _values[_count] = value;
  _types[_count] = type;
  _count++;
}

void SerializationInfo___::UpdateValue(String name, Object value, Type type) {
  Int32 num = FindElement(name);
  if (num < 0) {
    AddValueInternal(name, value, type);
    return;
  }
  _values[num] = value;
  _types[num] = type;
}

Int32 SerializationInfo___::FindElement(String name) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  Int32 value;
  if (_nameToIndex->TryGetValue(name, value)) {
    return value;
  }
  return -1;
}

Object SerializationInfo___::GetElement(String name, Type& foundType) {
  Int32 num = FindElement(name);
  if (num == -1) {
    rt::throw_exception<SerializationException>(SR::Format(SR::get_Serialization_NotFound(), name));
  }
  foundType = _types[num];
  return _values[num];
}

Object SerializationInfo___::GetElementNoThrow(String name, Type& foundType) {
  Int32 num = FindElement(name);
  if (num == -1) {
    foundType = nullptr;
    return nullptr;
  }
  foundType = _types[num];
  return _values[num];
}

Object SerializationInfo___::GetValue(String name, Type type) {
  if ((Object)type == nullptr) {
    rt::throw_exception<ArgumentNullException>("type");
  }
  if (!type->IsRuntimeImplemented()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_MustBeRuntimeType());
  }
  Type foundType;
  Object element = GetElement(name, foundType);
  if ((Object)foundType == type || type->IsAssignableFrom(foundType) || element == nullptr) {
    return element;
  }
  return _converter->Convert(element, type);
}

Object SerializationInfo___::GetValueNoThrow(String name, Type type) {
  Type foundType;
  Object elementNoThrow = GetElementNoThrow(name, foundType);
  if (elementNoThrow == nullptr) {
    return nullptr;
  }
  if ((Object)foundType == type || type->IsAssignableFrom(foundType)) {
    return elementNoThrow;
  }
  return _converter->Convert(elementNoThrow, type);
}

Boolean SerializationInfo___::GetBoolean(String name) {
  Type foundType;
  Object element = GetElement(name, foundType);
  if ((Object)foundType != typeof<Boolean>()) {
    return _converter->ToBoolean(element);
  }
  return (Boolean)element;
}

Char SerializationInfo___::GetChar(String name) {
  Type foundType;
  Object element = GetElement(name, foundType);
  if ((Object)foundType != typeof<Char>()) {
    return _converter->ToChar(element);
  }
  return (Char)element;
}

SByte SerializationInfo___::GetSByte(String name) {
  Type foundType;
  Object element = GetElement(name, foundType);
  if ((Object)foundType != typeof<SByte>()) {
    return _converter->ToSByte(element);
  }
  return (SByte)element;
}

Byte SerializationInfo___::GetByte(String name) {
  Type foundType;
  Object element = GetElement(name, foundType);
  if ((Object)foundType != typeof<Byte>()) {
    return _converter->ToByte(element);
  }
  return (Byte)element;
}

Int16 SerializationInfo___::GetInt16(String name) {
  Type foundType;
  Object element = GetElement(name, foundType);
  if ((Object)foundType != typeof<Int16>()) {
    return _converter->ToInt16(element);
  }
  return (Int16)element;
}

UInt16 SerializationInfo___::GetUInt16(String name) {
  Type foundType;
  Object element = GetElement(name, foundType);
  if ((Object)foundType != typeof<UInt16>()) {
    return _converter->ToUInt16(element);
  }
  return (UInt16)element;
}

Int32 SerializationInfo___::GetInt32(String name) {
  Type foundType;
  Object element = GetElement(name, foundType);
  if ((Object)foundType != typeof<Int32>()) {
    return _converter->ToInt32(element);
  }
  return (Int32)element;
}

UInt32 SerializationInfo___::GetUInt32(String name) {
  Type foundType;
  Object element = GetElement(name, foundType);
  if ((Object)foundType != typeof<UInt32>()) {
    return _converter->ToUInt32(element);
  }
  return (UInt32)element;
}

Int64 SerializationInfo___::GetInt64(String name) {
  Type foundType;
  Object element = GetElement(name, foundType);
  if ((Object)foundType != typeof<Int64>()) {
    return _converter->ToInt64(element);
  }
  return (Int64)element;
}

UInt64 SerializationInfo___::GetUInt64(String name) {
  Type foundType;
  Object element = GetElement(name, foundType);
  if ((Object)foundType != typeof<UInt64>()) {
    return _converter->ToUInt64(element);
  }
  return (UInt64)element;
}

Single SerializationInfo___::GetSingle(String name) {
  Type foundType;
  Object element = GetElement(name, foundType);
  if ((Object)foundType != typeof<Single>()) {
    return _converter->ToSingle(element);
  }
  return (Single)element;
}

Double SerializationInfo___::GetDouble(String name) {
  Type foundType;
  Object element = GetElement(name, foundType);
  if ((Object)foundType != typeof<Double>()) {
    return _converter->ToDouble(element);
  }
  return (Double)element;
}

Decimal SerializationInfo___::GetDecimal(String name) {
  Type foundType;
  Object element = GetElement(name, foundType);
  if ((Object)foundType != typeof<Decimal>()) {
    return _converter->ToDecimal(element);
  }
  return (Decimal)element;
}

DateTime SerializationInfo___::GetDateTime(String name) {
  Type foundType;
  Object element = GetElement(name, foundType);
  if ((Object)foundType != typeof<DateTime>()) {
    return _converter->ToDateTime(element);
  }
  return (DateTime)element;
}

String SerializationInfo___::GetString(String name) {
  Type foundType;
  Object element = GetElement(name, foundType);
  if ((Object)foundType != typeof<String>() && element != nullptr) {
    return _converter->ToString(element);
  }
  return (String)element;
}

void SerializationInfo___::ThrowIfDeserializationInProgress() {
  if (get_DeserializationInProgress()) {
    rt::throw_exception<SerializationException>(SR::get_Serialization_DangerousDeserialization());
  }
}

void SerializationInfo___::ThrowIfDeserializationInProgress(String switchSuffix, Int32& cachedValue) {
  if (switchSuffix == nullptr) {
    rt::throw_exception<ArgumentNullException>("switchSuffix");
  }
  if (String::in::IsNullOrWhiteSpace(switchSuffix)) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_EmptyName(), "switchSuffix");
  }
  if (cachedValue == 0) {
    Boolean isEnabled;
    if (AppContext::TryGetSwitch("Switch.System.Runtime.Serialization.SerializationGuard." + switchSuffix, isEnabled) && isEnabled) {
      cachedValue = 1;
    } else {
      cachedValue = -1;
    }
  }
  if (cachedValue != 1) {
    if (cachedValue != -1) {
      rt::throw_exception<ArgumentOutOfRangeException>("cachedValue");
    }
    if (get_DeserializationInProgress()) {
      rt::throw_exception<SerializationException>(SR::Format(SR::get_Serialization_DangerousDeserialization_Switch(), "Switch.System.Runtime.Serialization.SerializationGuard." + switchSuffix));
    }
  }
}

DeserializationToken SerializationInfo___::StartDeserialization() {
  if (LocalAppContextSwitches::get_SerializationGuard()) {
    StackCrawlMark stackMark = StackCrawlMark::LookForMe;
    DeserializationTracker threadDeserializationTracker = Thread::in::GetThreadDeserializationTracker(stackMark);
    if (!threadDeserializationTracker->get_DeserializationInProgress()) {
      {
        rt::lock(threadDeserializationTracker);
        if (!threadDeserializationTracker->get_DeserializationInProgress()) {
          AsyncDeserializationInProgress->set_Value(true);
          threadDeserializationTracker->set_DeserializationInProgress(true);
          return DeserializationToken(threadDeserializationTracker);
        }
      }
    }
  }
  return DeserializationToken(nullptr);
}

void SerializationInfo___::cctor() {
  AsyncDeserializationInProgress = rt::newobj<AsyncLocal<Boolean>>();
}

} // namespace System::Private::CoreLib::System::Runtime::Serialization::SerializationInfoNamespace
