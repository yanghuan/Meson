#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(FieldInfo)
FORWARD(MemberInfo)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Runtime::InteropServices::Expando {
namespace IExpandoNamespace {
using namespace Reflection;
CLASS(IExpando) : public Object::in {
  public: FieldInfo AddField(String name);
  public: void RemoveMember(MemberInfo m);
};
} // namespace IExpandoNamespace
using IExpando = IExpandoNamespace::IExpando;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::Expando
