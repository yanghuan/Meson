#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace EnumeratorCancellationAttributeNamespace {
CLASS(EnumeratorCancellationAttribute) : public Attribute::in {
  public: void ctor();
};
} // namespace EnumeratorCancellationAttributeNamespace
using EnumeratorCancellationAttribute = EnumeratorCancellationAttributeNamespace::EnumeratorCancellationAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
