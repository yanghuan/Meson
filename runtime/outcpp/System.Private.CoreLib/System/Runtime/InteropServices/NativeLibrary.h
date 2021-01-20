#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(IntPtr)
FORWARDS_(Nullable)
FORWARD(String)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(Assembly)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARD(ConditionalWeakTable, TKey, TValue)
FORWARDS(QCallAssembly)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class DllImportSearchPath : int32_t;
FORWARD(DllImportResolver)
namespace NativeLibraryNamespace {
using namespace System::Reflection;
using namespace System::Runtime::CompilerServices;
class NativeLibrary {
  public: static IntPtr LoadLibraryByName(String libraryName, Assembly assembly, Nullable<DllImportSearchPath> searchPath, Boolean throwOnError);
  public: static IntPtr LoadFromPath(String libraryName, Boolean throwOnError);
  public: static IntPtr LoadByName(String libraryName, QCallAssembly callingAssembly, Boolean hasDllImportSearchPathFlag, UInt32 dllImportSearchPathFlag, Boolean throwOnError);
  public: static void FreeLib(IntPtr handle);
  public: static IntPtr GetSymbol(IntPtr handle, String symbolName, Boolean throwOnError);
  public: static IntPtr Load(String libraryPath);
  public: static Boolean TryLoad(String libraryPath, IntPtr& handle);
  public: static IntPtr Load(String libraryName, Assembly assembly, Nullable<DllImportSearchPath> searchPath);
  public: static Boolean TryLoad(String libraryName, Assembly assembly, Nullable<DllImportSearchPath> searchPath, IntPtr& handle);
  public: static void Free(IntPtr handle);
  public: static IntPtr GetExport(IntPtr handle, String name);
  public: static Boolean TryGetExport(IntPtr handle, String name, IntPtr& address);
  public: static void SetDllImportResolver(Assembly assembly, DllImportResolver resolver);
  public: static IntPtr LoadLibraryCallbackStub(String libraryName, Assembly assembly, Boolean hasDllImportSearchPathFlags, UInt32 dllImportSearchPathFlags);
  private: static ConditionalWeakTable<Assembly, DllImportResolver> s_nativeDllResolveMap;
};
} // namespace NativeLibraryNamespace
using NativeLibrary = NativeLibraryNamespace::NativeLibrary;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
