#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
FORWARDS(BIND_OPTS)
FORWARD(IEnumString)
FORWARD(IRunningObjectTable)
namespace IBindCtxNamespace {
CLASS(IBindCtx) : public Object::in {
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
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IBindCtxNamespace
using IBindCtx = IBindCtxNamespace::IBindCtx;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
