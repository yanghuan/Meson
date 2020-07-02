#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Collections {
FORWARD(IDictionaryEnumerator)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System::Resources {
namespace IResourceReaderNamespace {
using namespace ::System::Private::CoreLib::System::Collections;
CLASS(IResourceReader) {
  public: void Close();
  public: IDictionaryEnumerator GetEnumerator();
};
} // namespace IResourceReaderNamespace
using IResourceReader = IResourceReaderNamespace::IResourceReader;
} // namespace System::Private::CoreLib::System::Resources
