#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace BStrWrapperNamespace {
CLASS(BStrWrapper) : public object {
  public: String get_WrappedObject() { return WrappedObject; }
  public: void ctor(String value);
  public: void ctor(Object value);
  private: String WrappedObject;
};
} // namespace BStrWrapperNamespace
using BStrWrapper = BStrWrapperNamespace::BStrWrapper;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
