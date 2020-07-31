#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Reflection/MethodBase.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Reflection {
enum class BindingFlags;
enum class MemberTypes;
FORWARD(Binder)
namespace ConstructorInfoNamespace {
using namespace Globalization;
CLASS(ConstructorInfo) : public MethodBase::in {
  public: MemberTypes get_MemberType();
  public: Type GetReturnType();
  protected: void Ctor();
  public: Object Invoke(Array<Object> parameters);
  public: Object Invoke(BindingFlags invokeAttr, Binder binder, Array<Object> parameters, CultureInfo culture);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  public: static Boolean op_Equality(ConstructorInfo left, ConstructorInfo right);
  public: static Boolean op_Inequality(ConstructorInfo left, ConstructorInfo right);
  private: static void SCtor();
  public: static String ConstructorName;
  public: static String TypeConstructorName;
};
} // namespace ConstructorInfoNamespace
using ConstructorInfo = ConstructorInfoNamespace::ConstructorInfo;
} // namespace System::Private::CoreLib::System::Reflection
