#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics {
namespace DebuggerDisplayAttributeNamespace {
CLASS(DebuggerDisplayAttribute) : public Attribute::in {
  public: String get_Value() { return Value; }
  public: String get_Name() { return Name; }
  public: void set_Name(String value) { Name = value; }
  public: String get_Type() { return Type; }
  public: void set_Type(String value) { Type = value; }
  public: Type get_Target();
  public: void set_Target(Type value);
  public: String get_TargetTypeName() { return TargetTypeName; }
  public: void set_TargetTypeName(String value) { TargetTypeName = value; }
  public: void Ctor(String value);
  private: Type _target;
  private: String Value;
  private: String Name;
  private: String Type;
  private: String TargetTypeName;
};
} // namespace DebuggerDisplayAttributeNamespace
using DebuggerDisplayAttribute = DebuggerDisplayAttributeNamespace::DebuggerDisplayAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics
