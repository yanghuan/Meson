#pragma once

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
  public: void ctor(Type type, String value);
  public: void ctor(Char value);
  public: void ctor(Byte value);
  public: void ctor(Int16 value);
  public: void ctor(Int32 value);
  public: void ctor(Int64 value);
  public: void ctor(Single value);
  public: void ctor(Double value);
  public: void ctor(Boolean value);
  public: void ctor(String value);
  public: void ctor(Object value);
  public: void ctor(SByte value);
  public: void ctor(UInt16 value);
  public: void ctor(UInt32 value);
  public: void ctor(UInt64 value);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  protected: void SetValue(Object value);
  private: Object _value;
  private: static Object s_convertFromInvariantString;
};
} // namespace DefaultValueAttributeNamespace
using DefaultValueAttribute = DefaultValueAttributeNamespace::DefaultValueAttribute;
} // namespace System::Private::CoreLib::System::ComponentModel
