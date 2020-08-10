#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace PreserveSigAttributeNamespace {
CLASS(PreserveSigAttribute) : public Attribute::in {
  public: void ctor();
};
} // namespace PreserveSigAttributeNamespace
using PreserveSigAttribute = PreserveSigAttributeNamespace::PreserveSigAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
