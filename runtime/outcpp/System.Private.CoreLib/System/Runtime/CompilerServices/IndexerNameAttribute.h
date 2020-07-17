#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace IndexerNameAttributeNamespace {
CLASS(IndexerNameAttribute) {
  public: void Ctor(String indexerName);
};
} // namespace IndexerNameAttributeNamespace
using IndexerNameAttribute = IndexerNameAttributeNamespace::IndexerNameAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
