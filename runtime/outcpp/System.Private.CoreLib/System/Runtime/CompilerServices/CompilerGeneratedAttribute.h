#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace CompilerGeneratedAttributeNamespace {
CLASS(CompilerGeneratedAttribute) : public Attribute::in {
  public: void Ctor();
};
} // namespace CompilerGeneratedAttributeNamespace
using CompilerGeneratedAttribute = CompilerGeneratedAttributeNamespace::CompilerGeneratedAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
