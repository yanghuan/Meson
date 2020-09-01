#include "NativeLibrary-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/Reflection/RuntimeAssembly-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/ConditionalWeakTable-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/QCallAssembly-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::NativeLibraryNamespace {
using namespace System::Reflection;
using namespace System::Runtime::CompilerServices;
using namespace System::Threading;

IntPtr NativeLibrary::LoadLibraryByName(String libraryName, Assembly assembly, Nullable<DllImportSearchPath> searchPath, Boolean throwOnError) {
  RuntimeAssembly assembly2 = (RuntimeAssembly)assembly;
  return LoadByName(libraryName, QCallAssembly(assembly2), searchPath.get_HasValue(), (UInt32)searchPath.GetValueOrDefault(), throwOnError);
}

IntPtr NativeLibrary::Load(String libraryPath) {
  if (libraryPath == nullptr) {
    rt::throw_exception<ArgumentNullException>("libraryPath");
  }
  return LoadFromPath(libraryPath, true);
}

Boolean NativeLibrary::TryLoad(String libraryPath, IntPtr& handle) {
  if (libraryPath == nullptr) {
    rt::throw_exception<ArgumentNullException>("libraryPath");
  }
  handle = LoadFromPath(libraryPath, false);
  return handle != IntPtr::Zero;
}

IntPtr NativeLibrary::Load(String libraryName, Assembly assembly, Nullable<DllImportSearchPath> searchPath) {
  if (libraryName == nullptr) {
    rt::throw_exception<ArgumentNullException>("libraryName");
  }
  if (assembly == nullptr) {
    rt::throw_exception<ArgumentNullException>("assembly");
  }
  if (!assembly->IsRuntimeImplemented()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_MustBeRuntimeAssembly());
  }
  return LoadLibraryByName(libraryName, assembly, searchPath, true);
}

Boolean NativeLibrary::TryLoad(String libraryName, Assembly assembly, Nullable<DllImportSearchPath> searchPath, IntPtr& handle) {
  if (libraryName == nullptr) {
    rt::throw_exception<ArgumentNullException>("libraryName");
  }
  if (assembly == nullptr) {
    rt::throw_exception<ArgumentNullException>("assembly");
  }
  if (!assembly->IsRuntimeImplemented()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_MustBeRuntimeAssembly());
  }
  handle = LoadLibraryByName(libraryName, assembly, searchPath, false);
  return handle != IntPtr::Zero;
}

void NativeLibrary::Free(IntPtr handle) {
  if (!(handle == IntPtr::Zero)) {
    FreeLib(handle);
  }
}

IntPtr NativeLibrary::GetExport(IntPtr handle, String name) {
  if (handle == IntPtr::Zero) {
    rt::throw_exception<ArgumentNullException>("handle");
  }
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  return GetSymbol(handle, name, true);
}

Boolean NativeLibrary::TryGetExport(IntPtr handle, String name, IntPtr& address) {
  if (handle == IntPtr::Zero) {
    rt::throw_exception<ArgumentNullException>("handle");
  }
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  address = GetSymbol(handle, name, false);
  return address != IntPtr::Zero;
}

void NativeLibrary::SetDllImportResolver(Assembly assembly, DllImportResolver resolver) {
  if (assembly == nullptr) {
    rt::throw_exception<ArgumentNullException>("assembly");
  }
  if (resolver == nullptr) {
    rt::throw_exception<ArgumentNullException>("resolver");
  }
  if (!assembly->IsRuntimeImplemented()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_MustBeRuntimeAssembly());
  }
  if (s_nativeDllResolveMap == nullptr) {
    Interlocked::CompareExchange(s_nativeDllResolveMap, rt::newobj<ConditionalWeakTable<Assembly, DllImportResolver>>(), (ConditionalWeakTable<Assembly, DllImportResolver>)nullptr);
  }
  try {
    s_nativeDllResolveMap->Add(assembly, resolver);
  } catch (ArgumentException) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_CannotRegisterSecondResolver());
  }
}

IntPtr NativeLibrary::LoadLibraryCallbackStub(String libraryName, Assembly assembly, Boolean hasDllImportSearchPathFlags, UInt32 dllImportSearchPathFlags) {
  if (s_nativeDllResolveMap == nullptr) {
    return IntPtr::Zero;
  }
  DllImportResolver value;
  if (!s_nativeDllResolveMap->TryGetValue(assembly, value)) {
    return IntPtr::Zero;
  }
  return value(libraryName, assembly, hasDllImportSearchPathFlags ? Nullable<DllImportSearchPath>((DllImportSearchPath)dllImportSearchPathFlags) : nullptr);
}

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::NativeLibraryNamespace
