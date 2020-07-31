#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Guid.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
FORWARD(IConnectionPoint)
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
namespace System::Private::CoreLib::System::Runtime::InteropServices {
FORWARD(ComEventsMethod)
FORWARDS(Variant)
namespace ComEventsSinkNamespace {
using namespace ComTypes;
CLASS(ComEventsSink) : public Object::in {
  public: void Ctor(Object rcw, Guid iid);
  public: static ComEventsSink Find(ComEventsSink sinks, Guid& iid);
  public: static ComEventsSink Add(ComEventsSink sinks, ComEventsSink sink);
  public: static ComEventsSink RemoveAll(ComEventsSink sinks);
  public: static ComEventsSink Remove(ComEventsSink sinks, ComEventsSink sink);
  public: ComEventsMethod RemoveMethod(ComEventsMethod method);
  public: ComEventsMethod FindMethod(Int32 dispid);
  public: ComEventsMethod AddMethod(Int32 dispid);
  private: static Variant& GetVariant(Variant& pSrc);
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
