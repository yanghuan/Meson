#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace CallerFilePathAttributeNamespace {
CLASS(CallerFilePathAttribute) : public Attribute::in {
  public: void ctor();
};
} // namespace CallerFilePathAttributeNamespace
using CallerFilePathAttribute = CallerFilePathAttributeNamespace::CallerFilePathAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
