#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace CallerLineNumberAttributeNamespace {
CLASS(CallerLineNumberAttribute) : public Attribute::in {
  public: void ctor();
};
} // namespace CallerLineNumberAttributeNamespace
using CallerLineNumberAttribute = CallerLineNumberAttributeNamespace::CallerLineNumberAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
