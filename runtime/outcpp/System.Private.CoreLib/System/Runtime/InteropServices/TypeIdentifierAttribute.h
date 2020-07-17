#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace TypeIdentifierAttributeNamespace {
CLASS(TypeIdentifierAttribute) {
  public: String get_Scope() { return Scope; }
  public: String get_Identifier() { return Identifier; }
  public: void Ctor();
  public: void Ctor(String scope, String identifier);
  private: String Scope;
  private: String Identifier;
};
} // namespace TypeIdentifierAttributeNamespace
using TypeIdentifierAttribute = TypeIdentifierAttributeNamespace::TypeIdentifierAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
