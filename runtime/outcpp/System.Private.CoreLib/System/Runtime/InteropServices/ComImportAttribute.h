#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace ComImportAttributeNamespace {
CLASS(ComImportAttribute) : public Attribute::in {
  public: void Ctor();
};
} // namespace ComImportAttributeNamespace
using ComImportAttribute = ComImportAttributeNamespace::ComImportAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
