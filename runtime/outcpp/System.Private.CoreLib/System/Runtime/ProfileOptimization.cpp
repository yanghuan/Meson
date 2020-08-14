#include "ProfileOptimization-dep.h"

#include <System.Private.CoreLib/System/Runtime/Loader/AssemblyLoadContext-dep.h>

namespace System::Private::CoreLib::System::Runtime::ProfileOptimizationNamespace {
using namespace System::Runtime::Loader;

void ProfileOptimization::SetProfileRoot(String directoryPath) {
  AssemblyLoadContext::in::get_Default()->SetProfileOptimizationRoot(directoryPath);
}

void ProfileOptimization::StartProfile(String profile) {
  AssemblyLoadContext::in::get_Default()->StartProfileOptimization(profile);
}

} // namespace System::Private::CoreLib::System::Runtime::ProfileOptimizationNamespace
