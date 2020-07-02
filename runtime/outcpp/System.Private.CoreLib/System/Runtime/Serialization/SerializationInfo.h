#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(String)
FORWARD(Type)
FORWARD(Object)
FORWARDS(Char)
FORWARDS(SByte)
FORWARDS(Byte)
FORWARDS(Int16)
FORWARDS(UInt16)
FORWARDS(UInt32)
FORWARDS(Int64)
FORWARDS(UInt64)
FORWARDS(Single)
FORWARDS(Double)
FORWARDS(Decimal)
FORWARDS(DateTime)
FORWARD_(Array, T1, T2)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(Dictionary, TKey, TValue)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARDS(DeserializationToken)
FORWARD(SerializationInfoEnumerator)
FORWARD(IFormatterConverter)
namespace SerializationInfoNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
CLASS(SerializationInfo) {
  public: static Boolean get_DeserializationInProgress();
  public: String get_FullTypeName();
  public: void set_FullTypeName(String value);
  public: String get_AssemblyName();
  public: void set_AssemblyName(String value);
  public: Int32 get_MemberCount();
  public: Type get_ObjectType();
  public: static void ThrowIfDeserializationInProgress();
  public: static void ThrowIfDeserializationInProgress(String switchSuffix, Int32& cachedValue);
  public: static DeserializationToken StartDeserialization();
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
  private: Array<String> _names;
  private: Array<Object> _values;
  private: Array<Type> _types;
  private: Int32 _count;
  private: Dictionary<String, Int32> _nameToIndex;
  private: IFormatterConverter _converter;
  private: String _rootTypeName;
  private: String _rootTypeAssemblyName;
  private: Type _rootType;
};
} // namespace SerializationInfoNamespace
using SerializationInfo = SerializationInfoNamespace::SerializationInfo;
} // namespace System::Private::CoreLib::System::Runtime::Serialization
