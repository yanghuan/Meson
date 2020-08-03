#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics {
namespace DebuggerVisualizerAttributeNamespace {
CLASS(DebuggerVisualizerAttribute) : public Attribute::in {
  public: String get_VisualizerObjectSourceTypeName() { return VisualizerObjectSourceTypeName; }
  public: String get_VisualizerTypeName() { return VisualizerTypeName; }
  public: String get_Description() { return Description; }
  public: void set_Description(String value) { Description = value; }
  public: Type get_Target();
  public: void set_Target(Type value);
  public: String get_TargetTypeName() { return TargetTypeName; }
  public: void set_TargetTypeName(String value) { TargetTypeName = value; }
  public: void Ctor(String visualizerTypeName);
  public: void Ctor(String visualizerTypeName, String visualizerObjectSourceTypeName);
  public: void Ctor(String visualizerTypeName, Type visualizerObjectSource);
  public: void Ctor(Type visualizer);
  public: void Ctor(Type visualizer, Type visualizerObjectSource);
  public: void Ctor(Type visualizer, String visualizerObjectSourceTypeName);
  private: Type _target;
  private: String VisualizerObjectSourceTypeName;
  private: String VisualizerTypeName;
  private: String Description;
  private: String TargetTypeName;
};
} // namespace DebuggerVisualizerAttributeNamespace
using DebuggerVisualizerAttribute = DebuggerVisualizerAttributeNamespace::DebuggerVisualizerAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics
