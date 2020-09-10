#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections {
FORWARD(IDictionaryEnumerator)
FORWARD(IEnumerable)
FORWARD(IEnumerator)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARD(IDisposable)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Resources {
namespace IResourceReaderNamespace {
using namespace System::Collections;
CLASS(IResourceReader) : public object {
  public: using interface = rt::TypeList<IEnumerable, IDisposable>;
  public: IEnumerator GetEnumerator();
  public: void Dispose();
  public: void Close();
  public: IDictionaryEnumerator GetEnumerator();
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IResourceReaderNamespace
using IResourceReader = IResourceReaderNamespace::IResourceReader;
} // namespace System::Private::CoreLib::System::Resources
