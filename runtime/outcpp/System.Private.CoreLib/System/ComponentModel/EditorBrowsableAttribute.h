#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::ComponentModel {
enum class EditorBrowsableState;
namespace EditorBrowsableAttributeNamespace {
CLASS(EditorBrowsableAttribute) {
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  private: EditorBrowsableState State;
};
} // namespace EditorBrowsableAttributeNamespace
using EditorBrowsableAttribute = EditorBrowsableAttributeNamespace::EditorBrowsableAttribute;
} // namespace System::Private::CoreLib::System::ComponentModel
