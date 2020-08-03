#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::ComponentModel {
enum class EditorBrowsableState;
namespace EditorBrowsableAttributeNamespace {
CLASS(EditorBrowsableAttribute) : public Attribute::in {
  public: EditorBrowsableState get_State() { return State; }
  public: void Ctor(EditorBrowsableState state);
  public: void Ctor();
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  private: EditorBrowsableState State;
};
} // namespace EditorBrowsableAttributeNamespace
using EditorBrowsableAttribute = EditorBrowsableAttributeNamespace::EditorBrowsableAttribute;
} // namespace System::Private::CoreLib::System::ComponentModel
