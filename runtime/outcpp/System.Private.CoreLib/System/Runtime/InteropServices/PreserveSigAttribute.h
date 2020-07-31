#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace PreserveSigAttributeNamespace {
CLASS(PreserveSigAttribute) : public Attribute::in {
  public: void Ctor();
};
} // namespace PreserveSigAttributeNamespace
using PreserveSigAttribute = PreserveSigAttributeNamespace::PreserveSigAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
