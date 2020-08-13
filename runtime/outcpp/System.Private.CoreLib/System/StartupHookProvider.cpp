#include "StartupHookProvider-dep.h"

#include <System.Private.CoreLib/System/AppContext-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/RuntimeEventSource-dep.h>
#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/IO/Path-dep.h>
#include <System.Private.CoreLib/System/Reflection/Assembly-dep.h>
#include <System.Private.CoreLib/System/Reflection/BindingFlags.h>
#include <System.Private.CoreLib/System/Reflection/MethodInfo-dep.h>
#include <System.Private.CoreLib/System/Runtime/Loader/AssemblyLoadContext-dep.h>
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
  Array<Char> array = rt::newarr<Array<Char>>(4);
  Array<String> array2 = text->Split(Path::PathSeparator);
  Array<StartupHookNameOrPath> array3 = rt::newarr<Array<StartupHookNameOrPath>>(array2->get_Length());
  for (Int32 i = 0; i < array2->get_Length(); i++) {
    String text2 = array2[i];
    if (String::in::IsNullOrEmpty(text2)) {
    }
    if (Path::IsPathFullyQualified(text2)) {
      array3[i].Path = text2;
    }
    for (Int32 j = 0; j < array->get_Length(); j++) {
      if (text2->Contains(array[j])) {
        rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_InvalidStartupHookSimpleAssemblyName(), text2));
      }
    }
    if (text2->EndsWith(".dll", StringComparison::OrdinalIgnoreCase)) {
      rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_InvalidStartupHookSimpleAssemblyName(), text2));
    }
    try{
      array3[i].AssemblyName = rt::newobj<AssemblyName>(text2);
    } catch (Exception innerException) {
    }
  }
  Array<StartupHookNameOrPath> array4 = array3;
}

void StartupHookProvider::CallStartupHook(StartupHookNameOrPath startupHook) {
  Assembly assembly;
  try{
    if (startupHook.Path != nullptr) {
      assembly = AssemblyLoadContext::in::get_Default()->LoadFromAssemblyPath(startupHook.Path);
    } else {
      if (startupHook.AssemblyName == nullptr) {
        return;
      }
      assembly = AssemblyLoadContext::in::get_Default()->LoadFromAssemblyName(startupHook.AssemblyName);
    }
  } catch (Exception innerException) {
  }
  Type type = assembly->GetType("StartupHook", true);
}

} // namespace System::Private::CoreLib::System::StartupHookProviderNamespace
