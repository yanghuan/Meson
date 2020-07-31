#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace CallerFilePathAttributeNamespace {
CLASS(CallerFilePathAttribute) : public Attribute::in {
  public: void Ctor();
};
} // namespace CallerFilePathAttributeNamespace
using CallerFilePathAttribute = CallerFilePathAttributeNamespace::CallerFilePathAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
