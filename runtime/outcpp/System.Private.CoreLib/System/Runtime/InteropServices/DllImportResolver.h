#pragma once

#include <System.Private.CoreLib/System/MulticastDelegate.h>

namespace System::Private::CoreLib::System {
FORWARD(AsyncCallback)
FORWARD(IAsyncResult)
FORWARDS(IntPtr)
FORWARDS_(Nullable, T1, T2)
FORWARD(Object)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(Assembly)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class DllImportSearchPath;
namespace DllImportResolverNamespace {
using namespace Reflection;
CLASS(DllImportResolver) : public MulticastDelegate::in {
  public: void Ctor(Object object, IntPtr method);
  public: IntPtr Invoke(String libraryName, Assembly assembly, Nullable<DllImportSearchPath> searchPath);
  public: IAsyncResult BeginInvoke(String libraryName, Assembly assembly, Nullable<DllImportSearchPath> searchPath, AsyncCallback callback, Object object);
  public: IntPtr EndInvoke(IAsyncResult result);
};
} // namespace DllImportResolverNamespace
using DllImportResolver = DllImportResolverNamespace::DllImportResolver;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
