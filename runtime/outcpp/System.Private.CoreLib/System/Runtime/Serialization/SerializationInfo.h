#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/Threading/AsyncLocal.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(DateTime)
FORWARDS(Decimal)
FORWARDS(Double)
FORWARDS(Int16)
FORWARDS(Int64)
FORWARDS(SByte)
FORWARDS(Single)
FORWARD(String)
FORWARD(Type)
FORWARDS(UInt16)
FORWARDS(UInt32)
FORWARDS(UInt64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(Dictionary, TKey, TValue)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARDS(DeserializationToken)
FORWARD(IFormatterConverter)
FORWARD(SerializationInfoEnumerator)
namespace SerializationInfoNamespace {
using namespace Collections::Generic;
using namespace Threading;
CLASS(SerializationInfo) : public Object::in {
  public: static AsyncLocal<Boolean> get_AsyncDeserializationInProgress() { return AsyncDeserializationInProgress; }
  public: static Boolean get_DeserializationInProgress();
  public: String get_FullTypeName();
  public: void set_FullTypeName(String value);
  public: String get_AssemblyName();
  public: void set_AssemblyName(String value);
  public: Boolean get_IsFullTypeNameSetExplicit() { return IsFullTypeNameSetExplicit; }
  private: void set_IsFullTypeNameSetExplicit(Boolean value) { IsFullTypeNameSetExplicit = value; }
  public: Boolean get_IsAssemblyNameSetExplicit() { return IsAssemblyNameSetExplicit; }
  private: void set_IsAssemblyNameSetExplicit(Boolean value) { IsAssemblyNameSetExplicit = value; }
  public: Int32 get_MemberCount();
  public: Type get_ObjectType();
  public: static void ThrowIfDeserializationInProgress();
  public: static void ThrowIfDeserializationInProgress(String switchSuffix, Int32& cachedValue);
  public: static DeserializationToken StartDeserialization();
  public: void Ctor(Type type, IFormatterConverter converter);
  public: void Ctor(Type type, IFormatterConverter converter, Boolean requireSameTokenInPartialTrust);
  public: void SetType(Type type);
  public: SerializationInfoEnumerator GetEnumerator();
  private: void ExpandArrays();
  public: void AddValue(String name, Object value, Type type);
  public: void AddValue(String name, Object value);
  public: void AddValue(String name, Boolean value);
  public: void AddValue(String name, Char value);
  public: void AddValue(String name, SByte value);
  public: void AddValue(String name, Byte value);
  public: void AddValue(String name, Int16 value);
  public: void AddValue(String name, UInt16 value);
  public: void AddValue(String name, Int32 value);
  public: void AddValue(String name, UInt32 value);
  public: void AddValue(String name, Int64 value);
  public: void AddValue(String name, UInt64 value);
  public: void AddValue(String name, Single value);
  public: void AddValue(String name, Double value);
  public: void AddValue(String name, Decimal value);
  public: void AddValue(String name, DateTime value);
  public: void AddValueInternal(String name, Object value, Type type);
  public: void UpdateValue(String name, Object value, Type type);
  private: Int32 FindElement(String name);
  private: Object GetElement(String name, Type& foundType);
  private: Object GetElementNoThrow(String name, Type& foundType);
  public: Object GetValue(String name, Type type);
  public: Object GetValueNoThrow(String name, Type type);
  public: Boolean GetBoolean(String name);
  public: Char GetChar(String name);
  public: SByte GetSByte(String name);
  public: Byte GetByte(String name);
  public: Int16 GetInt16(String name);
  public: UInt16 GetUInt16(String name);
  public: Int32 GetInt32(String name);
  public: UInt32 GetUInt32(String name);
  public: Int64 GetInt64(String name);
  public: UInt64 GetUInt64(String name);
  public: Single GetSingle(String name);
  public: Double GetDouble(String name);
  public: Decimal GetDecimal(String name);
  public: DateTime GetDateTime(String name);
  public: String GetString(String name);
  private: static void SCtor();
  private: Array<String> _names;
  private: Array<Object> _values;
  private: Array<Type> _types;
  private: Int32 _count;
  private: Dictionary<String, Int32> _nameToIndex;
  private: IFormatterConverter _converter;
  private: String _rootTypeName;
  private: String _rootTypeAssemblyName;
  private: Type _rootType;
  private: static AsyncLocal<Boolean> AsyncDeserializationInProgress;
  private: Boolean IsFullTypeNameSetExplicit;
  private: Boolean IsAssemblyNameSetExplicit;
};
} // namespace SerializationInfoNamespace
using SerializationInfo = SerializationInfoNamespace::SerializationInfo;
} // namespace System::Private::CoreLib::System::Runtime::Serialization
