#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int16)
FORWARDS(Int32)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
enum class DESCKIND;
FORWARDS(BINDPTR)
FORWARD(ITypeInfo)
namespace ITypeCompNamespace {
CLASS(ITypeComp) : public Object::in {
  public: void Bind(String szName, Int32 lHashVal, Int16 wFlags, ITypeInfo& ppTInfo, DESCKIND& pDescKind, BINDPTR& pBindPtr);
  public: void BindType(String szName, Int32 lHashVal, ITypeInfo& ppTInfo, ITypeComp& ppTComp);
};
} // namespace ITypeCompNamespace
using ITypeComp = ITypeCompNamespace::ITypeComp;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
