#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Reflection {
FORWARD(FieldInfo)
FORWARD(IReflect)
FORWARD(MemberInfo)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::Expando {
namespace IExpandoNamespace {
using namespace Reflection;
CLASS(IExpando) : public Object::in {
  public: using interface = rt::TypeList<IReflect>;
  public: FieldInfo AddField(String name);
  public: void RemoveMember(MemberInfo m);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IExpandoNamespace
using IExpando = IExpandoNamespace::IExpando;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::Expando
