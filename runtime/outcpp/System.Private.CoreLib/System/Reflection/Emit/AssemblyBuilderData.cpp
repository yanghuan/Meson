#include "AssemblyBuilderData-dep.h"

#include <System.Private.CoreLib/System/Collections/Generic/List-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/ModuleBuilder-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::AssemblyBuilderDataNamespace {
using namespace System::Collections::Generic;

void AssemblyBuilderData___::ctor(InternalAssemblyBuilder assembly, AssemblyBuilderAccess access) {
  _assembly = assembly;
  _access = access;
  _moduleBuilderList = rt::newobj<List<ModuleBuilder>>();
}

void AssemblyBuilderData___::CheckTypeNameConflict(String strTypeName, TypeBuilder enclosingType) {
  for (Int32 i = 0; i < _moduleBuilderList->get_Count(); i++) {
    ModuleBuilder moduleBuilder = _moduleBuilderList[i];
    moduleBuilder->CheckTypeNameConflict(strTypeName, enclosingType);
  }
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::AssemblyBuilderDataNamespace
