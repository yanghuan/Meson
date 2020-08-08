#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
FORWARD(ICustomAdapter)
FORWARD(IDispatch)
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerable)
FORWARD(IEnumerator)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System::Runtime::InteropServices::CustomMarshalers {
namespace EnumerableViewOfDispatchNamespace {
using namespace Collections;
CLASS(EnumerableViewOfDispatch) : public Object::in {
  using interface = rt::TypeList<ICustomAdapter, IEnumerable>;
  private: IDispatch get_Dispatch();
  public: void Ctor(Object dispatch);
  public: IEnumerator GetEnumerator();
  public: Object GetUnderlyingObject();
  private: static constexpr Int32 DISPID_NEWENUM = -4;
  private: static constexpr Int32 LCID_DEFAULT = 1;
  private: Object _dispatch;
};
} // namespace EnumerableViewOfDispatchNamespace
using EnumerableViewOfDispatch = EnumerableViewOfDispatchNamespace::EnumerableViewOfDispatch;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::CustomMarshalers
