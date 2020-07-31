#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Reflection/RuntimeAssembly.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::IO {
FORWARD(FileStream)
FORWARD(Stream)
} // namespace System::Private::CoreLib::System::IO
namespace System::Private::CoreLib::System::Reflection {
FORWARD(ManifestResourceInfo)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Reflection::Emit {
namespace InternalAssemblyBuilderNamespace {
using namespace IO;
CLASS(InternalAssemblyBuilder) : public RuntimeAssembly::in {
  public: String get_Location();
  public: String get_CodeBase();
  public: String get_ImageRuntimeVersion();
  private: void Ctor();
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  public: Array<String> GetManifestResourceNames();
  public: FileStream GetFile(String name);
  public: Array<FileStream> GetFiles(Boolean getResourceModules);
  public: Stream GetManifestResourceStream(Type type, String name);
  public: Stream GetManifestResourceStream(String name);
  public: ManifestResourceInfo GetManifestResourceInfo(String resourceName);
  public: Array<Type> GetExportedTypes();
};
} // namespace InternalAssemblyBuilderNamespace
using InternalAssemblyBuilder = InternalAssemblyBuilderNamespace::InternalAssemblyBuilder;
} // namespace System::Private::CoreLib::System::Reflection::Emit
