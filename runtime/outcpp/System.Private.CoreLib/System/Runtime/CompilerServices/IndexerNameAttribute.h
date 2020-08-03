#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace IndexerNameAttributeNamespace {
CLASS(IndexerNameAttribute) : public Attribute::in {
  public: void Ctor(String indexerName);
};
} // namespace IndexerNameAttributeNamespace
using IndexerNameAttribute = IndexerNameAttributeNamespace::IndexerNameAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
