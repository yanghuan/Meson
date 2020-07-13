#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
FORWARD(IDispatch)
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerator)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::CustomMarshalers {
namespace EnumerableViewOfDispatchNamespace {
using namespace Collections;
CLASS(EnumerableViewOfDispatch) {
  private: IDispatch get_Dispatch();
  public: IEnumerator GetEnumerator();
  public: Object GetUnderlyingObject();
  private: static constexpr Int32 DISPID_NEWENUM = -4;
  private: static constexpr Int32 LCID_DEFAULT = 1;
  private: Object _dispatch;
};
} // namespace EnumerableViewOfDispatchNamespace
using EnumerableViewOfDispatch = EnumerableViewOfDispatchNamespace::EnumerableViewOfDispatch;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::CustomMarshalers
