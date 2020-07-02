#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection::Emit {
namespace LabelNamespace {
struct Label {
  public: Int32 GetLabelValue();
  public: Int32 GetHashCode();
  public: Boolean Equals(Object obj);
  public: Boolean Equals(Label obj);
  public: Int32 m_label;
};
} // namespace LabelNamespace
using Label = LabelNamespace::Label;
} // namespace System::Private::CoreLib::System::Reflection::Emit