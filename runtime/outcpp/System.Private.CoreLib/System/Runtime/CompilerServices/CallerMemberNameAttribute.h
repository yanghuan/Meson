#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace CallerMemberNameAttributeNamespace {
CLASS(CallerMemberNameAttribute) : public Attribute::in {
  public: void ctor();
};
} // namespace CallerMemberNameAttributeNamespace
using CallerMemberNameAttribute = CallerMemberNameAttributeNamespace::CallerMemberNameAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
