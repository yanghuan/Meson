#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Char)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(StringBuilder)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(List, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Reflection::Emit {
namespace TypeNameBuilderNamespace {
using namespace System::Collections::Generic;
using namespace System::Text;
CLASS(TypeNameBuilder) : public object {
  public: enum class Format : int32_t {
    ToString = 0,
    FullName = 1,
    AssemblyQualifiedName = 2,
  };
  public: void ctor();
  private: void OpenGenericArguments();
  private: void CloseGenericArguments();
  private: void OpenGenericArgument();
  private: void CloseGenericArgument();
  private: void AddName(String name);
  private: void AddArray(Int32 rank);
  private: void AddAssemblySpec(String assemblySpec);
  public: String ToString();
  private: static Boolean ContainsReservedChar(String name);
  private: static Boolean IsTypeNameReservedChar(Char ch);
  private: void EscapeName(String name);
  private: void EscapeAssemblyName(String name);
  private: void EscapeEmbeddedAssemblyName(String name);
  private: void PushOpenGenericArgument();
  private: void PopOpenGenericArgument();
  private: void Append(String pStr);
  private: void Append(Char c);
  public: static String ToString(Type type, Format format);
  private: void AddElementType(Type type);
  private: void AddAssemblyQualifiedName(Type type, Format format);
  private: StringBuilder _str;
  private: Int32 _instNesting;
  private: Boolean _firstInstArg;
  private: Boolean _nestedName;
  private: Boolean _hasAssemblySpec;
  private: Boolean _useAngleBracketsForGenerics;
  private: List<Int32> _stack;
  private: Int32 _stackIdx;
};
} // namespace TypeNameBuilderNamespace
using TypeNameBuilder = TypeNameBuilderNamespace::TypeNameBuilder;
} // namespace System::Private::CoreLib::System::Reflection::Emit
