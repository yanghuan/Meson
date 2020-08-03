#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Guid)
FORWARDS(Int32)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
namespace IPersistFileNamespace {
CLASS(IPersistFile) : public Object::in {
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
