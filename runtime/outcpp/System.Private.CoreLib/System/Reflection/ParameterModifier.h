#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARDS(Boolean)
FORWARD_(Array, T1, T2)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace ParameterModifierNamespace {
struct ParameterModifier {
  public: Boolean get_Item(Int32 index);
  public: void set_Item(Int32 index, Boolean value);
  public: Array<Boolean> get_IsByRefArray();
  private: Array<Boolean> _byRef;
};
} // namespace ParameterModifierNamespace
using ParameterModifier = ParameterModifierNamespace::ParameterModifier;
} // namespace System::Private::CoreLib::System::Reflection
