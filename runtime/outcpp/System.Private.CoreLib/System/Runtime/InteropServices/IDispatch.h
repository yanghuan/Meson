#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Guid)
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
FORWARDS(DISPPARAMS)
FORWARD(ITypeInfo)
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class InvokeFlags : int16_t;
namespace IDispatchNamespace {
using namespace System::Runtime::InteropServices::ComTypes;
CLASS(IDispatch) : public Object::in {
  public: Int32 GetTypeInfoCount();
  public: ITypeInfo GetTypeInfo(Int32 iTInfo, Int32 lcid);
  public: void GetIDsOfNames(Guid& riid, Array<String> rgszNames, Int32 cNames, Int32 lcid, Array<Int32> rgDispId);
  public: void Invoke(Int32 dispIdMember, Guid& riid, Int32 lcid, InvokeFlags wFlags, DISPPARAMS& pDispParams, IntPtr pVarResult, IntPtr pExcepInfo, IntPtr puArgErr);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IDispatchNamespace
using IDispatch = IDispatchNamespace::IDispatch;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
