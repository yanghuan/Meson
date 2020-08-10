#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace TypeIdentifierAttributeNamespace {
CLASS(TypeIdentifierAttribute) : public Attribute::in {
  public: String get_Scope() { return Scope; }
  public: String get_Identifier() { return Identifier; }
  public: void ctor();
  public: void ctor(String scope, String identifier);
  private: String Scope;
  private: String Identifier;
};
} // namespace TypeIdentifierAttributeNamespace
using TypeIdentifierAttribute = TypeIdentifierAttributeNamespace::TypeIdentifierAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
