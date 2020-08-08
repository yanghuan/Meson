#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(IEquatable, T)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection::Emit {
namespace LabelNamespace {
struct Label : public valueType<Label> {
  public: using interface = rt::TypeList<IEquatable<Label>>;
  public: explicit Label(Int32 label);
  public: Int32 GetLabelValue();
  public: Int32 GetHashCode();
  public: Boolean Equals(Object obj);
  public: Boolean Equals(Label obj);
  public: static Boolean op_Equality(Label a, Label b);
  public: static Boolean op_Inequality(Label a, Label b);
  public: explicit Label() {}
  public: Int32 m_label;
};
} // namespace LabelNamespace
using Label = LabelNamespace::Label;
} // namespace System::Private::CoreLib::System::Reflection::Emit
