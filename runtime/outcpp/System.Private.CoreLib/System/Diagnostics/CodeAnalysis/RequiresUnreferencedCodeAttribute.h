#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis {
namespace RequiresUnreferencedCodeAttributeNamespace {
CLASS(RequiresUnreferencedCodeAttribute) : public Attribute::in {
  public: String get_Message() { return Message; }
  public: String get_Url() { return Url; }
  public: void set_Url(String value) { Url = value; }
  public: void ctor(String message);
  private: String Message;
  private: String Url;
};
} // namespace RequiresUnreferencedCodeAttributeNamespace
using RequiresUnreferencedCodeAttribute = RequiresUnreferencedCodeAttributeNamespace::RequiresUnreferencedCodeAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis
