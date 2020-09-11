#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
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
FORWARD(ITypeLib)
namespace ITypeLib2Namespace {
CLASS(ITypeLib2) : public object {
  public: using interface = rt::TypeList<ITypeLib>;
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
  public: void GetCustData(Guid& guid, Object& pVarVal);
  public: void GetDocumentation2(Int32 index, String& pbstrHelpString, Int32& pdwHelpStringContext, String& pbstrHelpStringDll);
  public: void GetLibStatistics(IntPtr pcUniqueNames, Int32& pcchUniqueNames);
  public: void GetAllCustData(IntPtr pCustData);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace ITypeLib2Namespace
using ITypeLib2 = ITypeLib2Namespace::ITypeLib2;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
