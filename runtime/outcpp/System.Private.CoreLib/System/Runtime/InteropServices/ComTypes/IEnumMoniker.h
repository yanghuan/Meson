#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Int32)
FORWARDS(IntPtr)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
FORWARD(IMoniker)
namespace IEnumMonikerNamespace {
CLASS(IEnumMoniker) : public object {
  public: Int32 Next(Int32 celt, Array<IMoniker> rgelt, IntPtr pceltFetched);
  public: Int32 Skip(Int32 celt);
  public: void Reset();
  public: void Clone(IEnumMoniker& ppenum);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IEnumMonikerNamespace
using IEnumMoniker = IEnumMonikerNamespace::IEnumMoniker;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
