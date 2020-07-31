#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections {
FORWARD(IDictionaryEnumerator)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System::Resources {
namespace IResourceReaderNamespace {
using namespace Collections;
CLASS(IResourceReader) : public Object::in {
  public: void Close();
  public: IDictionaryEnumerator GetEnumerator();
};
} // namespace IResourceReaderNamespace
using IResourceReader = IResourceReaderNamespace::IResourceReader;
} // namespace System::Private::CoreLib::System::Resources
