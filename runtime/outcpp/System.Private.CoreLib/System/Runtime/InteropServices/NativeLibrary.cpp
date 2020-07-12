#include "NativeLibrary-dep.h"

namespace System::Private::CoreLib::System::Runtime::InteropServices::NativeLibraryNamespace {
IntPtr NativeLibrary::LoadLibraryByName(String libraryName, Assembly assembly, Nullable<DllImportSearchPath> searchPath, Boolean throwOnError) {
  return IntPtr();
};

IntPtr NativeLibrary::Load(String libraryPath) {
  return IntPtr();
};

Boolean NativeLibrary::TryLoad(String libraryPath, IntPtr& handle) {
  return Boolean();
};

IntPtr NativeLibrary::Load(String libraryName, Assembly assembly, Nullable<DllImportSearchPath> searchPath) {
  return IntPtr();
};

Boolean NativeLibrary::TryLoad(String libraryName, Assembly assembly, Nullable<DllImportSearchPath> searchPath, IntPtr& handle) {
  return Boolean();
};

void NativeLibrary::Free(IntPtr handle) {
};

IntPtr NativeLibrary::GetExport(IntPtr handle, String name) {
  return IntPtr();
};

Boolean NativeLibrary::TryGetExport(IntPtr handle, String name, IntPtr& address) {
  return Boolean();
};

void NativeLibrary::SetDllImportResolver(Assembly assembly, DllImportResolver resolver) {
};

IntPtr NativeLibrary::LoadLibraryCallbackStub(String libraryName, Assembly assembly, Boolean hasDllImportSearchPathFlags, UInt32 dllImportSearchPathFlags) {
  return IntPtr();
};

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::NativeLibraryNamespace
