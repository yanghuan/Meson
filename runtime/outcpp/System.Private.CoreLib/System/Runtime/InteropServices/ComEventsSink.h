#pragma once

#include <System.Private.CoreLib/System/Guid.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
FORWARDS(DISPPARAMS)
FORWARD(IConnectionPoint)
FORWARD(ITypeInfo)
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(IntPtr)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class CustomQueryInterfaceResult : int32_t;
enum class InvokeFlags : int16_t;
FORWARD(ComEventsMethod)
FORWARD(ICustomQueryInterface)
FORWARD(IDispatch)
FORWARDS(Variant)
namespace ComEventsSinkNamespace {
using namespace System::Runtime::InteropServices::ComTypes;
using Variant = InteropServices::Variant;
CLASS(ComEventsSink) : public object {
  public: using interface = rt::TypeList<IDispatch, ICustomQueryInterface>;
  public: void ctor(Object rcw, Guid iid);
  public: static ComEventsSink Find(ComEventsSink sinks, Guid& iid);
  public: static ComEventsSink Add(ComEventsSink sinks, ComEventsSink sink);
  public: static ComEventsSink RemoveAll(ComEventsSink sinks);
  public: static ComEventsSink Remove(ComEventsSink sinks, ComEventsSink sink);
  public: ComEventsMethod RemoveMethod(ComEventsMethod method);
  public: ComEventsMethod FindMethod(Int32 dispid);
  public: ComEventsMethod AddMethod(Int32 dispid);
  private: Int32 GetTypeInfoCountOfIDispatch();
  private: ITypeInfo GetTypeInfoOfIDispatch(Int32 iTInfo, Int32 lcid);
  private: void GetIDsOfNamesOfIDispatch(Guid& iid, Array<String> names, Int32 cNames, Int32 lcid, Array<Int32> rgDispId);
  private: static Variant& GetVariant(Variant& pSrc);
  private: void InvokeOfIDispatch(Int32 dispid, Guid& riid, Int32 lcid, InvokeFlags wFlags, DISPPARAMS& pDispParams, IntPtr pVarResult, IntPtr pExcepInfo, IntPtr puArgErr);
  private: CustomQueryInterfaceResult GetInterfaceOfICustomQueryInterface(Guid& iid, IntPtr& ppv);
  private: void Advise(Object rcw);
  private: void Unadvise();
  private: Guid _iidSourceItf;
  private: IConnectionPoint _connectionPoint;
  private: Int32 _cookie;
  private: ComEventsMethod _methods;
  private: ComEventsSink _next;
};
} // namespace ComEventsSinkNamespace
using ComEventsSink = ComEventsSinkNamespace::ComEventsSink;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
