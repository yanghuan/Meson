#pragma once

#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace ParameterModifierNamespace {
struct ParameterModifier : public valueType<ParameterModifier> {
  public: Boolean get_Item(Int32 index);
  public: void set_Item(Int32 index, Boolean value);
  public: Array<Boolean> get_IsByRefArray();
  public: explicit ParameterModifier(Int32 parameterCount);
  public: explicit ParameterModifier() {}
  private: Array<Boolean> _byRef;
};
} // namespace ParameterModifierNamespace
using ParameterModifier = ParameterModifierNamespace::ParameterModifier;
} // namespace System::Private::CoreLib::System::Reflection
