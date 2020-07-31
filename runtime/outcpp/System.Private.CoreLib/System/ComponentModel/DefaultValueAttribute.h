#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(Double)
FORWARDS(Int16)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARD(Object)
FORWARDS(SByte)
FORWARDS(Single)
FORWARD(String)
FORWARD(Type)
FORWARDS(UInt16)
FORWARDS(UInt32)
FORWARDS(UInt64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::ComponentModel {
namespace DefaultValueAttributeNamespace {
CLASS(DefaultValueAttribute) : public Attribute::in {
  public: Object get_Value();
  public: void Ctor(Type type, String value);
  public: void Ctor(Char value);
  public: void Ctor(Byte value);
  public: void Ctor(Int16 value);
  public: void Ctor(Int32 value);
  public: void Ctor(Int64 value);
  public: void Ctor(Single value);
  public: void Ctor(Double value);
  public: void Ctor(Boolean value);
  public: void Ctor(String value);
  public: void Ctor(Object value);
  public: void Ctor(SByte value);
  public: void Ctor(UInt16 value);
  public: void Ctor(UInt32 value);
  public: void Ctor(UInt64 value);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  protected: void SetValue(Object value);
  private: Object _value;
  private: static Object s_convertFromInvariantString;
};
} // namespace DefaultValueAttributeNamespace
using DefaultValueAttribute = DefaultValueAttributeNamespace::DefaultValueAttribute;
} // namespace System::Private::CoreLib::System::ComponentModel
