#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace PreserveDependencyAttributeNamespace {
CLASS(PreserveDependencyAttribute) {
  public: void Ctor(String memberSignature, String typeName);
  public: void Ctor(String memberSignature, String typeName, String assemblyName);
  private: String MemberSignature;
  private: String TypeName;
  private: String AssemblyName;
};
} // namespace PreserveDependencyAttributeNamespace
using PreserveDependencyAttribute = PreserveDependencyAttributeNamespace::PreserveDependencyAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
