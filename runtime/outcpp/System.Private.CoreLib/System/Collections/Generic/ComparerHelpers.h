#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD(RuntimeType)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
namespace ComparerHelpersNamespace {
class ComparerHelpers : public Object::in {
  public: static Object CreateDefaultComparer(Type type);
  private: static Object TryCreateNullableComparer(RuntimeType nullableType);
  private: static Object TryCreateEnumComparer(RuntimeType enumType);
  public: static Object CreateDefaultEqualityComparer(Type type);
  private: static Object TryCreateNullableEqualityComparer(RuntimeType nullableType);
  private: static Object TryCreateEnumEqualityComparer(RuntimeType enumType);
};
} // namespace ComparerHelpersNamespace
using ComparerHelpers = ComparerHelpersNamespace::ComparerHelpers;
} // namespace System::Private::CoreLib::System::Collections::Generic
