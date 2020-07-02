#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(List, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Reflection {
FORWARD(MethodInfo)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Reflection::Emit {
FORWARD(TypeBuilder)
FORWARD(ModuleBuilder)
enum class AssemblyBuilderAccess;
FORWARD(InternalAssemblyBuilder)
namespace AssemblyBuilderDataNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
CLASS(AssemblyBuilderData) {
  public: void CheckTypeNameConflict(String strTypeName, TypeBuilder enclosingType);
  public: List<ModuleBuilder> _moduleBuilderList;
  public: AssemblyBuilderAccess _access;
  public: MethodInfo _entryPointMethod;
  private: InternalAssemblyBuilder _assembly;
};
} // namespace AssemblyBuilderDataNamespace
using AssemblyBuilderData = AssemblyBuilderDataNamespace::AssemblyBuilderData;
} // namespace System::Private::CoreLib::System::Reflection::Emit
