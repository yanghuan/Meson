#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARDS(Guid)
FORWARDS(IntPtr)
FORWARD(String)
FORWARDS(Boolean)
FORWARD_(Array, T1, T2)
FORWARDS(Int16)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
FORWARD(ITypeInfo)
enum class TYPEKIND;
FORWARD(ITypeComp)
namespace ITypeLibNamespace {
CLASS(ITypeLib) {
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
};
} // namespace ITypeLibNamespace
using ITypeLib = ITypeLibNamespace::ITypeLib;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
