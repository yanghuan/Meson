#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace ComImportAttributeNamespace {
CLASS(ComImportAttribute) {
  public: void Ctor();
};
} // namespace ComImportAttributeNamespace
using ComImportAttribute = ComImportAttributeNamespace::ComImportAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
