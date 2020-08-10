#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace SkipLocalsInitAttributeNamespace {
CLASS(SkipLocalsInitAttribute) : public Attribute::in {
  public: void ctor();
};
} // namespace SkipLocalsInitAttributeNamespace
using SkipLocalsInitAttribute = SkipLocalsInitAttributeNamespace::SkipLocalsInitAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
