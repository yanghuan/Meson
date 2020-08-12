#pragma once

#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Reflection {
FORWARD(RuntimeAssembly)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace QCallAssemblyNamespace {
using namespace System::Reflection;
struct QCallAssembly : public valueType<QCallAssembly> {
  public: explicit QCallAssembly(RuntimeAssembly& assembly);
  public: explicit QCallAssembly() {}
  private: void* _ptr;
  private: IntPtr _assembly;
};
} // namespace QCallAssemblyNamespace
using QCallAssembly = QCallAssemblyNamespace::QCallAssembly;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
