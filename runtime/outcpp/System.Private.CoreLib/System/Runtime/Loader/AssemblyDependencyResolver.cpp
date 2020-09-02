#include "AssemblyDependencyResolver-dep.h"

#include <System.Private.CoreLib/Internal/IO/File-dep.h>
#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/Dictionary-dep.h>
#include <System.Private.CoreLib/System/DllNotFoundException-dep.h>
#include <System.Private.CoreLib/System/EntryPointNotFoundException-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/IO/Path-dep.h>
#include <System.Private.CoreLib/System/Runtime/Loader/LibraryNameVariation-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/StringComparer-dep.h>
#include <System.Private.CoreLib/System/StringComparison.h>
#include <System.Private.CoreLib/System/StringSplitOptions.h>
#include <System.Private.CoreLib/System/Text/StringBuilder-dep.h>

namespace System::Private::CoreLib::System::Runtime::Loader::AssemblyDependencyResolverNamespace {
using namespace Internal::IO;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace System::Text;

void AssemblyDependencyResolver___::ctor(String componentAssemblyPath) {
  if (componentAssemblyPath == nullptr) {
    rt::throw_exception<ArgumentNullException>("componentAssemblyPath");
  }
  String assemblyPathsList = nullptr;
  String nativeSearchPathsList = nullptr;
  String resourceSearchPathsList = nullptr;
  Int32 num = 0;
  StringBuilder errorMessage = rt::newobj<StringBuilder>();
  try {
  } catch (EntryPointNotFoundException innerException) {
    rt::throw_exception<InvalidOperationException>(SR::get_AssemblyDependencyResolver_FailedToLoadHostpolicy(), innerException);
  } catch (DllNotFoundException innerException2) {
    rt::throw_exception<InvalidOperationException>(SR::get_AssemblyDependencyResolver_FailedToLoadHostpolicy(), innerException2);
  }
  if (num != 0) {
    rt::throw_exception<InvalidOperationException>(SR::Format(SR::get_AssemblyDependencyResolver_FailedToResolveDependencies(), componentAssemblyPath, num, errorMessage));
  }
  Array<String> array = SplitPathsList(assemblyPathsList);
  _assemblyPaths = rt::newobj<Dictionary<String, String>>(StringComparer::in::get_OrdinalIgnoreCase());
  Array<String> array2 = array;
  for (String&& text : rt::each(array2)) {
    _assemblyPaths->Add(Path::GetFileNameWithoutExtension(text), text);
  }
  _nativeSearchPaths = SplitPathsList(nativeSearchPathsList);
  _resourceSearchPaths = SplitPathsList(resourceSearchPathsList);
  _assemblyDirectorySearchPaths = rt::newarr<Array<String>>(1);
}

String AssemblyDependencyResolver___::ResolveAssemblyToPath(AssemblyName assemblyName) {
  if (assemblyName == nullptr) {
    rt::throw_exception<ArgumentNullException>("assemblyName");
  }
  String value;
  if (!String::in::IsNullOrEmpty(assemblyName->get_CultureName()) && !String::in::Equals(assemblyName->get_CultureName(), "neutral", StringComparison::OrdinalIgnoreCase)) {
    Array<String> resourceSearchPaths = _resourceSearchPaths;
    for (String&& path : rt::each(resourceSearchPaths)) {
      String text = Path::Combine(path, assemblyName->get_CultureName(), assemblyName->get_Name() + ".dll");
      if (File::Exists(text)) {
        return text;
      }
    }
  } else if (assemblyName->get_Name() != nullptr && _assemblyPaths->TryGetValue(assemblyName->get_Name(), value) && File::Exists(value)) {
    return value;
  }

  return nullptr;
}

String AssemblyDependencyResolver___::ResolveUnmanagedDllToPath(String unmanagedDllName) {
  if (unmanagedDllName == nullptr) {
    rt::throw_exception<ArgumentNullException>("unmanagedDllName");
  }
  Array<String> array = (!unmanagedDllName->Contains(Path::DirectorySeparatorChar)) ? _nativeSearchPaths : _assemblyDirectorySearchPaths;
  Boolean isRelativePath = !Path::IsPathFullyQualified(unmanagedDllName);
  for (LibraryNameVariation&& item : rt::each(LibraryNameVariation::DetermineLibraryNameVariations(unmanagedDllName, isRelativePath))) {
    String path = item.Prefix + unmanagedDllName + item.Suffix;
    Array<String> array2 = array;
    for (String&& path2 : rt::each(array2)) {
      String text = Path::Combine(path2, path);
      if (File::Exists(text)) {
        return text;
      }
    }
  }
  return nullptr;
}

Array<String> AssemblyDependencyResolver___::SplitPathsList(String pathsList) {
  if (pathsList == nullptr) {
    return Array<>::in::Empty<String>();
  }
  return pathsList->Split(Path::PathSeparator, StringSplitOptions::RemoveEmptyEntries);
}

} // namespace System::Private::CoreLib::System::Runtime::Loader::AssemblyDependencyResolverNamespace
