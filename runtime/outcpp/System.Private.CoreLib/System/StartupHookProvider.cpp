#include "StartupHookProvider-dep.h"

#include <System.Private.CoreLib/System/AppContext-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/RuntimeEventSource-dep.h>
#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/IO/Path-dep.h>
#include <System.Private.CoreLib/System/MissingMethodException-dep.h>
#include <System.Private.CoreLib/System/ReadOnlySpan-dep.h>
#include <System.Private.CoreLib/System/Reflection/AmbiguousMatchException-dep.h>
#include <System.Private.CoreLib/System/Reflection/Assembly-dep.h>
#include <System.Private.CoreLib/System/Reflection/BindingFlags.h>
#include <System.Private.CoreLib/System/Reflection/MethodInfo-dep.h>
#include <System.Private.CoreLib/System/Runtime/Loader/AssemblyLoadContext-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/StartupHookProvider-dep.h>
#include <System.Private.CoreLib/System/StringComparison.h>
#include <System.Private.CoreLib/System/Type-dep.h>

namespace System::Private::CoreLib::System::StartupHookProviderNamespace {
using namespace System::Diagnostics::Tracing;
using namespace System::IO;
using namespace System::Reflection;
using namespace System::Runtime::Loader;

void StartupHookProvider::ProcessStartupHooks() {
  RuntimeEventSource::in::Initialize();
  String text = rt::as<String>(AppContext::GetData("STARTUP_HOOKS"));
  if (text == nullptr) {
    return;
  }
  Char as[4] = {};
  Span<Char> span = as;
  ReadOnlySpan<Char> readOnlySpan = span;
  Array<String> array = text->Split(Path::PathSeparator);
  Array<StartupHookNameOrPath> array2 = rt::newarr<Array<StartupHookNameOrPath>>(array->get_Length());
  for (Int32 i = 0; i < array->get_Length(); i++) {
    String text2 = array[i];
    if (String::in::IsNullOrEmpty(text2)) {
      continue;
    }
    if (Path::IsPathFullyQualified(text2)) {
      array2[i].Path = text2;
      continue;
    }
    for (Int32 j = 0; j < readOnlySpan.get_Length(); j++) {
      if (text2->Contains(readOnlySpan[j])) {
        rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_InvalidStartupHookSimpleAssemblyName(), text2));
      }
    }
    if (text2->EndsWith(".dll", StringComparison::OrdinalIgnoreCase)) {
      rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_InvalidStartupHookSimpleAssemblyName(), text2));
    }
    try {
      array2[i].AssemblyName = rt::newobj<AssemblyName>(text2);
    } catch (Exception innerException) {
      rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_InvalidStartupHookSimpleAssemblyName(), text2), innerException);
    }
  }
  Array<StartupHookNameOrPath> array3 = array2;
  for (StartupHookNameOrPath&& startupHook : *array3) {
    CallStartupHook(startupHook);
  }
}

void StartupHookProvider::CallStartupHook(StartupHookNameOrPath startupHook) {
  Assembly assembly;
  try {
    if (startupHook.Path != nullptr) {
      assembly = AssemblyLoadContext::in::get_Default()->LoadFromAssemblyPath(startupHook.Path);
    } else {
      if (startupHook.AssemblyName == nullptr) {
        return;
      }
      assembly = AssemblyLoadContext::in::get_Default()->LoadFromAssemblyName(startupHook.AssemblyName);
    }
  } catch (Exception innerException) {
    String as = startupHook.Path;
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_StartupHookAssemblyLoadFailed(), as != nullptr ? as : startupHook.AssemblyName->ToString()), innerException);
  }
  Type type = assembly->GetType("StartupHook", true);
  MethodInfo method = type->GetMethod("Initialize", BindingFlags::Static | BindingFlags::Public | BindingFlags::NonPublic, nullptr, Type::in::EmptyTypes, nullptr);
  Boolean flag = false;
  if (method == nullptr) {
    try {
      method = type->GetMethod("Initialize", BindingFlags::Instance | BindingFlags::Static | BindingFlags::Public | BindingFlags::NonPublic);
    } catch (AmbiguousMatchException) {
    }
    if (!(method != nullptr)) {
      rt::throw_exception<MissingMethodException>("StartupHook", "Initialize");
    }
    flag = true;
  } else if (method->get_ReturnType() != typeof<void>()) {
    flag = true;
  }

  if (flag) {
    String as = startupHook.Path;
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_InvalidStartupHookSignature(), "StartupHook" + Type::in::Delimiter + "Initialize", as != nullptr ? as : startupHook.AssemblyName->ToString()));
  }
  method->Invoke(nullptr, nullptr);
}

} // namespace System::Private::CoreLib::System::StartupHookProviderNamespace
