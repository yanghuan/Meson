#include "ComponentActivator-dep.h"

namespace System::Private::CoreLib::Internal::Runtime::InteropServices::ComponentActivatorNamespace {
String ComponentActivator::MarshalToString(IntPtr arg, String argName) {
  return nullptr;
};
Int32 ComponentActivator::LoadAssemblyAndGetFunctionPointer(IntPtr assemblyPathNative, IntPtr typeNameNative, IntPtr methodNameNative, IntPtr delegateTypeNative, IntPtr reserved, IntPtr functionHandle) {
  return Int32();
};
Delegate ComponentActivator::CreateDelegate(String assemblyPath, String typeName, String methodName, String delegateTypeName) {
  return nullptr;
};
IsolatedComponentLoadContext ComponentActivator::GetIsolatedComponentLoadContext(String assemblyPath) {
  return nullptr;
};
} // namespace System::Private::CoreLib::Internal::Runtime::InteropServices::ComponentActivatorNamespace