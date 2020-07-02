#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Guid)
FORWARDS(Int32)
FORWARD(String)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
namespace IPersistFileNamespace {
CLASS(IPersistFile) {
  public: void GetClassID(Guid& pClassID);
  public: Int32 IsDirty();
  public: void Load(String pszFileName, Int32 dwMode);
  public: void Save(String pszFileName, Boolean fRemember);
  public: void SaveCompleted(String pszFileName);
  public: void GetCurFile(String& ppszFileName);
};
} // namespace IPersistFileNamespace
using IPersistFile = IPersistFileNamespace::IPersistFile;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
