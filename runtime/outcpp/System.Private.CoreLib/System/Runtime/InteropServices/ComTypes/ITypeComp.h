#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARDS(Int32)
FORWARDS(Int16)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
FORWARD(ITypeInfo)
enum class DESCKIND;
FORWARDS(BINDPTR)
namespace ITypeCompNamespace {
CLASS(ITypeComp) {
  public: void Bind(String szName, Int32 lHashVal, Int16 wFlags, ITypeInfo& ppTInfo, DESCKIND& pDescKind, BINDPTR& pBindPtr);
  public: void BindType(String szName, Int32 lHashVal, ITypeInfo& ppTInfo, ITypeComp& ppTComp);
};
} // namespace ITypeCompNamespace
using ITypeComp = ITypeCompNamespace::ITypeComp;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
