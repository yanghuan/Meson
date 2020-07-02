#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARD(String)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
FORWARDS(BIND_OPTS)
FORWARD(IRunningObjectTable)
FORWARD(IEnumString)
namespace IBindCtxNamespace {
CLASS(IBindCtx) {
  public: void RegisterObjectBound(Object punk);
  public: void RevokeObjectBound(Object punk);
  public: void ReleaseBoundObjects();
  public: void SetBindOptions(BIND_OPTS& pbindopts);
  public: void GetBindOptions(BIND_OPTS& pbindopts);
  public: void GetRunningObjectTable(IRunningObjectTable& pprot);
  public: void RegisterObjectParam(String pszKey, Object punk);
  public: void GetObjectParam(String pszKey, Object& ppunk);
  public: void EnumObjectParam(IEnumString& ppenum);
  public: Int32 RevokeObjectParam(String pszKey);
};
} // namespace IBindCtxNamespace
using IBindCtx = IBindCtxNamespace::IBindCtx;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
