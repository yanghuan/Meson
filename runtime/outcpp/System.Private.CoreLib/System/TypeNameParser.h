#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARDS(ObjectHandleOnStack)
FORWARDS(StringHandleOnStack)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System::Reflection {
FORWARD(AssemblyName)
FORWARD(Assembly)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Threading {
enum class StackCrawlMark;
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARDS(Boolean)
FORWARD(SafeTypeNameParserHandle)
FORWARD_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10)
FORWARD(Type)
FORWARD_(Array, T1, T2)
FORWARDS(Int32)
FORWARDS(Char)
namespace TypeNameParserNamespace {
using namespace ::System::Private::CoreLib::System::Reflection;
using namespace ::System::Private::CoreLib::System::Runtime::CompilerServices;
using namespace ::System::Private::CoreLib::System::Threading;
CLASS(TypeNameParser) {
  private: static void _CreateTypeNameParser(String typeName, ObjectHandleOnStack retHandle, Boolean throwOnError);
  private: static void _GetNames(SafeTypeNameParserHandle pTypeNameParser, ObjectHandleOnStack retArray);
  private: static void _GetTypeArguments(SafeTypeNameParserHandle pTypeNameParser, ObjectHandleOnStack retArray);
  private: static void _GetModifiers(SafeTypeNameParserHandle pTypeNameParser, ObjectHandleOnStack retArray);
  private: static void _GetAssemblyName(SafeTypeNameParserHandle pTypeNameParser, StringHandleOnStack retString);
  public: static Type GetType(String typeName, Func<AssemblyName, Assembly> assemblyResolver, Func<Assembly, String, Boolean, Type> typeResolver, Boolean throwOnError, Boolean ignoreCase, StackCrawlMark& stackMark);
  public: void Dispose();
  private: Type ConstructType(Func<AssemblyName, Assembly> assemblyResolver, Func<Assembly, String, Boolean, Type> typeResolver, Boolean throwOnError, Boolean ignoreCase, StackCrawlMark& stackMark);
  private: static Assembly ResolveAssembly(String asmName, Func<AssemblyName, Assembly> assemblyResolver, Boolean throwOnError, StackCrawlMark& stackMark);
  private: static Type ResolveType(Assembly assembly, Array<String> names, Func<Assembly, String, Boolean, Type> typeResolver, Boolean throwOnError, Boolean ignoreCase, StackCrawlMark& stackMark);
  private: static String EscapeTypeName(String name);
  private: static SafeTypeNameParserHandle CreateTypeNameParser(String typeName, Boolean throwOnError);
  private: Array<String> GetNames();
  private: Array<SafeTypeNameParserHandle> GetTypeArguments();
  private: Array<Int32> GetModifiers();
  private: String GetAssemblyName();
  private: SafeTypeNameParserHandle m_NativeParser;
  private: static Array<Char> SPECIAL_CHARS;
};
} // namespace TypeNameParserNamespace
using TypeNameParser = TypeNameParserNamespace::TypeNameParser;
} // namespace System::Private::CoreLib::System
