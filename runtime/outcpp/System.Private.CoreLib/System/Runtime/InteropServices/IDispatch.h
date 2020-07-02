#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARDS(Guid)
FORWARD_(Array, T1, T2)
FORWARD(String)
FORWARDS(IntPtr)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
FORWARD(ITypeInfo)
FORWARDS(DISPPARAMS)
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class InvokeFlags : int16_t;
namespace IDispatchNamespace {
using namespace ::System::Private::CoreLib::System::Runtime::InteropServices::ComTypes;
CLASS(IDispatch) {
  public: Int32 GetTypeInfoCount();
  public: ITypeInfo GetTypeInfo(Int32 iTInfo, Int32 lcid);
  public: void GetIDsOfNames(Guid& riid, Array<String> rgszNames, Int32 cNames, Int32 lcid, Array<Int32> rgDispId);
  public: void Invoke(Int32 dispIdMember, Guid& riid, Int32 lcid, InvokeFlags wFlags, DISPPARAMS& pDispParams, IntPtr pVarResult, IntPtr pExcepInfo, IntPtr puArgErr);
};
} // namespace IDispatchNamespace
using IDispatch = IDispatchNamespace::IDispatch;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
