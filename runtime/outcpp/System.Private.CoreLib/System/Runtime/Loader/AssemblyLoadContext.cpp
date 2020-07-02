#include "AssemblyLoadContext-dep.h"

#include <System.Private.CoreLib/System/Runtime/Loader/AssemblyLoadContext-dep.h>

namespace System::Private::CoreLib::System::Runtime::Loader::AssemblyLoadContextNamespace {
void AssemblyLoadContext___::ContextualReflectionScope::Dispose() {
  return void();
};
IEnumerable<Assembly> AssemblyLoadContext___::get_Assemblies() {
  return nullptr;
};
AssemblyLoadContext AssemblyLoadContext___::get_Default() {
  return nullptr;
};
Boolean AssemblyLoadContext___::get_IsCollectible() {
  return Boolean();
};
String AssemblyLoadContext___::get_Name() {
  return nullptr;
};
IEnumerable<AssemblyLoadContext> AssemblyLoadContext___::get_All() {
  return nullptr;
};
AssemblyLoadContext AssemblyLoadContext___::get_CurrentContextualReflectionContext() {
  return nullptr;
};
Assembly AssemblyLoadContext___::InternalLoadFromPath(String assemblyPath, String nativeImagePath) {
  return nullptr;
};
Assembly AssemblyLoadContext___::InternalLoad(ReadOnlySpan<Byte> arrAssembly, ReadOnlySpan<Byte> arrSymbols) {
  return nullptr;
};
Assembly AssemblyLoadContext___::LoadFromInMemoryModule(IntPtr moduleHandle) {
  return nullptr;
};
Assembly AssemblyLoadContext___::Resolve(IntPtr gchManagedAssemblyLoadContext, AssemblyName assemblyName) {
  return nullptr;
};
Assembly AssemblyLoadContext___::ResolveUsingResolvingEvent(IntPtr gchManagedAssemblyLoadContext, AssemblyName assemblyName) {
  return nullptr;
};
Assembly AssemblyLoadContext___::ResolveSatelliteAssembly(IntPtr gchManagedAssemblyLoadContext, AssemblyName assemblyName) {
  return nullptr;
};
Assembly AssemblyLoadContext___::GetFirstResolvedAssembly(AssemblyName assemblyName) {
  return nullptr;
};
Assembly AssemblyLoadContext___::ValidateAssemblyNameWithSimpleName(Assembly assembly, String requestedSimpleName) {
  return nullptr;
};
Assembly AssemblyLoadContext___::ResolveUsingLoad(AssemblyName assemblyName) {
  return nullptr;
};
Assembly AssemblyLoadContext___::ResolveUsingEvent(AssemblyName assemblyName) {
  return nullptr;
};
IntPtr AssemblyLoadContext___::ResolveUnmanagedDll(String unmanagedDllName, IntPtr gchManagedAssemblyLoadContext) {
  return IntPtr();
};
IntPtr AssemblyLoadContext___::ResolveUnmanagedDllUsingEvent(String unmanagedDllName, Assembly assembly, IntPtr gchManagedAssemblyLoadContext) {
  return IntPtr();
};
IntPtr AssemblyLoadContext___::GetResolvedUnmanagedDll(Assembly assembly, String unmanagedDllName) {
  return IntPtr();
};
Type AssemblyLoadContext___::LoadTypeForWinRTTypeNameInContext(String typeName) {
  return nullptr;
};
AssemblyLoadContext AssemblyLoadContext___::GetLoadContext(Assembly assembly) {
  return nullptr;
};
void AssemblyLoadContext___::SetProfileOptimizationRoot(String directoryPath) {
  return void();
};
void AssemblyLoadContext___::StartProfileOptimization(String profile) {
  return void();
};
void AssemblyLoadContext___::OnAssemblyLoad(RuntimeAssembly assembly) {
  return void();
};
RuntimeAssembly AssemblyLoadContext___::OnResourceResolve(RuntimeAssembly assembly, String resourceName) {
  return nullptr;
};
RuntimeAssembly AssemblyLoadContext___::OnTypeResolve(RuntimeAssembly assembly, String typeName) {
  return nullptr;
};
RuntimeAssembly AssemblyLoadContext___::OnAssemblyResolve(RuntimeAssembly assembly, String assemblyFullName) {
  return nullptr;
};
RuntimeAssembly AssemblyLoadContext___::InvokeResolveEvent(ResolveEventHandler eventHandler, RuntimeAssembly assembly, String name) {
  return nullptr;
};
RuntimeAssembly AssemblyLoadContext___::GetRuntimeAssembly(Assembly asm_) {
  return nullptr;
};
void AssemblyLoadContext___::Finalize() {
  return void();
};
void AssemblyLoadContext___::RaiseUnloadEvent() {
  return void();
};
void AssemblyLoadContext___::InitiateUnload() {
  return void();
};
String AssemblyLoadContext___::ToString() {
  return nullptr;
};
AssemblyName AssemblyLoadContext___::GetAssemblyName(String assemblyPath) {
  return nullptr;
};
Assembly AssemblyLoadContext___::Load(AssemblyName assemblyName) {
  return nullptr;
};
Assembly AssemblyLoadContext___::LoadFromAssemblyName(AssemblyName assemblyName) {
  return nullptr;
};
Assembly AssemblyLoadContext___::LoadFromAssemblyPath(String assemblyPath) {
  return nullptr;
};
Assembly AssemblyLoadContext___::LoadFromNativeImagePath(String nativeImagePath, String assemblyPath) {
  return nullptr;
};
Assembly AssemblyLoadContext___::LoadFromStream(Stream assembly) {
  return nullptr;
};
Assembly AssemblyLoadContext___::LoadFromStream(Stream assembly, Stream assemblySymbols) {
  return nullptr;
};
IntPtr AssemblyLoadContext___::LoadUnmanagedDllFromPath(String unmanagedDllPath) {
  return IntPtr();
};
IntPtr AssemblyLoadContext___::LoadUnmanagedDll(String unmanagedDllName) {
  return IntPtr();
};
void AssemblyLoadContext___::Unload() {
  return void();
};
void AssemblyLoadContext___::OnProcessExit() {
  return void();
};
void AssemblyLoadContext___::VerifyIsAlive() {
  return void();
};
void AssemblyLoadContext___::SetCurrentContextualReflectionContext(AssemblyLoadContext value) {
  return void();
};
AssemblyLoadContext::in::ContextualReflectionScope AssemblyLoadContext___::EnterContextualReflection() {
  return AssemblyLoadContext::in::ContextualReflectionScope();
};
AssemblyLoadContext::in::ContextualReflectionScope AssemblyLoadContext___::EnterContextualReflection(Assembly activating) {
  return AssemblyLoadContext::in::ContextualReflectionScope();
};
Assembly AssemblyLoadContext___::ResolveSatelliteAssembly(AssemblyName assemblyName) {
  return nullptr;
};
} // namespace System::Private::CoreLib::System::Runtime::Loader::AssemblyLoadContextNamespace
