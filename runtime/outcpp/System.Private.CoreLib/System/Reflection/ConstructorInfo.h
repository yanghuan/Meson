#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Type)
FORWARD_(Array, T1, T2)
FORWARD(Object)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Reflection {
enum class MemberTypes;
enum class BindingFlags;
FORWARD(Binder)
namespace ConstructorInfoNamespace {
using namespace ::System::Private::CoreLib::System::Globalization;
CLASS(ConstructorInfo) {
  public: MemberTypes get_MemberType();
  public: Type GetReturnType();
  public: Object Invoke(Array<Object> parameters);
  public: Object Invoke(BindingFlags invokeAttr, Binder binder, Array<Object> parameters, CultureInfo culture);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  public: static String ConstructorName;
  public: static String TypeConstructorName;
};
} // namespace ConstructorInfoNamespace
using ConstructorInfo = ConstructorInfoNamespace::ConstructorInfo;
} // namespace System::Private::CoreLib::System::Reflection
