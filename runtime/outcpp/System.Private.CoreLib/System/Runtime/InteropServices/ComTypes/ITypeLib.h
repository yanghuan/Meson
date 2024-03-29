#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Boolean)
FORWARDS(Guid)
FORWARDS(Int16)
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
enum class TYPEKIND : int32_t;
FORWARD(ITypeComp)
FORWARD(ITypeInfo)
namespace ITypeLibNamespace {
CLASS(ITypeLib) : public object {
  public: Int32 GetTypeInfoCount();
  public: void GetTypeInfo(Int32 index, ITypeInfo& ppTI);
  public: void GetTypeInfoType(Int32 index, TYPEKIND& pTKind);
  public: void GetTypeInfoOfGuid(Guid& guid, ITypeInfo& ppTInfo);
  public: void GetLibAttr(IntPtr& ppTLibAttr);
  public: void GetTypeComp(ITypeComp& ppTComp);
  public: void GetDocumentation(Int32 index, String& strName, String& strDocString, Int32& dwHelpContext, String& strHelpFile);
  public: Boolean IsName(String szNameBuf, Int32 lHashVal);
  public: void FindName(String szNameBuf, Int32 lHashVal, Array<ITypeInfo> ppTInfo, Array<Int32> rgMemId, Int16& pcFound);
  public: void ReleaseTLibAttr(IntPtr pTLibAttr);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace ITypeLibNamespace
using ITypeLib = ITypeLibNamespace::ITypeLib;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
