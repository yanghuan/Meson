#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(RuntimeType)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
enum class BindingFlags : int32_t;
FORWARDS(MetadataImport)
FORWARD(MethodInfo)
FORWARD(RuntimeMethodInfo)
namespace AssociatesNamespace {
class Associates {
  public: enum class Attributes : int32_t {
    ComposedOfAllVirtualMethods = 1,
    ComposedOfAllPrivateMethods = 2,
    ComposedOfNoPublicMembers = 4,
    ComposedOfNoStaticMembers = 8,
  };
  public: static Boolean IncludeAccessor(MethodInfo associate, Boolean nonPublic);
  private: static RuntimeMethodInfo AssignAssociates(Int32 tkMethod, RuntimeType declaredType, RuntimeType reflectedType);
  public: static void AssignAssociates(MetadataImport scope, Int32 mdPropEvent, RuntimeType declaringType, RuntimeType reflectedType, RuntimeMethodInfo& addOn, RuntimeMethodInfo& removeOn, RuntimeMethodInfo& fireOn, RuntimeMethodInfo& getter, RuntimeMethodInfo& setter, Array<MethodInfo>& other, Boolean& composedOfAllPrivateMethods, BindingFlags& bindingFlags);
};
} // namespace AssociatesNamespace
using Associates = AssociatesNamespace::Associates;
} // namespace System::Private::CoreLib::System::Reflection
