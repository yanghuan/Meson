#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Guid)
FORWARDS(Int16)
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
enum class IMPLTYPEFLAGS : int32_t;
enum class INVOKEKIND : int32_t;
FORWARDS(DISPPARAMS)
FORWARD(ITypeComp)
FORWARD(ITypeLib)
namespace ITypeInfoNamespace {
CLASS(ITypeInfo) : public object {
  public: void GetTypeAttr(IntPtr& ppTypeAttr);
  public: void GetTypeComp(ITypeComp& ppTComp);
  public: void GetFuncDesc(Int32 index, IntPtr& ppFuncDesc);
  public: void GetVarDesc(Int32 index, IntPtr& ppVarDesc);
  public: void GetNames(Int32 memid, Array<String> rgBstrNames, Int32 cMaxNames, Int32& pcNames);
  public: void GetRefTypeOfImplType(Int32 index, Int32& href);
  public: void GetImplTypeFlags(Int32 index, IMPLTYPEFLAGS& pImplTypeFlags);
  public: void GetIDsOfNames(Array<String> rgszNames, Int32 cNames, Array<Int32> pMemId);
  public: void Invoke(Object pvInstance, Int32 memid, Int16 wFlags, DISPPARAMS& pDispParams, IntPtr pVarResult, IntPtr pExcepInfo, Int32& puArgErr);
  public: void GetDocumentation(Int32 index, String& strName, String& strDocString, Int32& dwHelpContext, String& strHelpFile);
  public: void GetDllEntry(Int32 memid, INVOKEKIND invKind, IntPtr pBstrDllName, IntPtr pBstrName, IntPtr pwOrdinal);
  public: void GetRefTypeInfo(Int32 hRef, ITypeInfo& ppTI);
  public: void AddressOfMember(Int32 memid, INVOKEKIND invKind, IntPtr& ppv);
  public: void CreateInstance(Object pUnkOuter, Guid& riid, Object& ppvObj);
  public: void GetMops(Int32 memid, String& pBstrMops);
  public: void GetContainingTypeLib(ITypeLib& ppTLB, Int32& pIndex);
  public: void ReleaseTypeAttr(IntPtr pTypeAttr);
  public: void ReleaseFuncDesc(IntPtr pFuncDesc);
  public: void ReleaseVarDesc(IntPtr pVarDesc);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace ITypeInfoNamespace
using ITypeInfo = ITypeInfoNamespace::ITypeInfo;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
