#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/IntPtr.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARDS(Int32)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARDS(StringHandleOnStack)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System::Reflection::Emit {
namespace TypeNameBuilderNamespace {
using namespace ::System::Private::CoreLib::System::Runtime::CompilerServices;
CLASS(TypeNameBuilder) {
  public: enum class Format {
    ToString = 0,
    FullName = 1,
    AssemblyQualifiedName = 2,
  };
  private: static IntPtr CreateTypeNameBuilder();
  private: static void ReleaseTypeNameBuilder(IntPtr pAQN);
  private: static void OpenGenericArguments(IntPtr tnb);
  private: static void CloseGenericArguments(IntPtr tnb);
  private: static void OpenGenericArgument(IntPtr tnb);
  private: static void CloseGenericArgument(IntPtr tnb);
  private: static void AddName(IntPtr tnb, String name);
  private: static void AddPointer(IntPtr tnb);
  private: static void AddByRef(IntPtr tnb);
  private: static void AddSzArray(IntPtr tnb);
  private: static void AddArray(IntPtr tnb, Int32 rank);
  private: static void AddAssemblySpec(IntPtr tnb, String assemblySpec);
  private: static void ToString(IntPtr tnb, StringHandleOnStack retString);
  private: static void Clear(IntPtr tnb);
  public: static String ToString(Type type, Format format);
  public: void Dispose();
  private: void AddElementType(Type elementType);
  private: void ConstructAssemblyQualifiedNameWorker(Type type, Format format);
  private: void OpenGenericArguments();
  private: void CloseGenericArguments();
  private: void OpenGenericArgument();
  private: void CloseGenericArgument();
  private: void AddName(String name);
  private: void AddPointer();
  private: void AddByRef();
  private: void AddSzArray();
  private: void AddArray(Int32 rank);
  private: void AddAssemblySpec(String assemblySpec);
  public: String ToString();
  private: void Clear();
  private: IntPtr m_typeNameBuilder;
};
} // namespace TypeNameBuilderNamespace
using TypeNameBuilder = TypeNameBuilderNamespace::TypeNameBuilder;
} // namespace System::Private::CoreLib::System::Reflection::Emit
