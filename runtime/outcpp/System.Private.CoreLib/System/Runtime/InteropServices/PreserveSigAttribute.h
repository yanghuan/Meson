#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace PreserveSigAttributeNamespace {
CLASS(PreserveSigAttribute) {
  public: void Ctor();
};
} // namespace PreserveSigAttributeNamespace
using PreserveSigAttribute = PreserveSigAttributeNamespace::PreserveSigAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
