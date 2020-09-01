#include "TypeNameParser-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/IO/FileNotFoundException-dep.h>
#include <System.Private.CoreLib/System/Reflection/BindingFlags.h>
#include <System.Private.CoreLib/System/Reflection/RuntimeAssembly-dep.h>
#include <System.Private.CoreLib/System/Runtime/Loader/AssemblyLoadContext-dep.h>
#include <System.Private.CoreLib/System/RuntimeType-dep.h>
#include <System.Private.CoreLib/System/RuntimeTypeHandle-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/ValueStringBuilder-dep.h>
#include <System.Private.CoreLib/System/TypeLoadException-dep.h>
#include <System.Private.CoreLib/System/TypeNameParser-dep.h>

namespace System::Private::CoreLib::System::TypeNameParserNamespace {
using namespace System::IO;
using namespace System::Reflection;
using namespace System::Runtime::Loader;
using namespace System::Text;

Type TypeNameParser___::GetType(String typeName, Func<AssemblyName, Assembly> assemblyResolver, Func<Assembly, String, Boolean, Type> typeResolver, Boolean throwOnError, Boolean ignoreCase, StackCrawlMark& stackMark) {
  if (typeName == nullptr) {
    rt::throw_exception<ArgumentNullException>("typeName");
  }
  if (typeName->get_Length() > 0 && typeName[0] == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Format_StringZeroLength());
  }
  Type result = nullptr;
  SafeTypeNameParserHandle safeTypeNameParserHandle = CreateTypeNameParser(typeName, throwOnError);
  if (safeTypeNameParserHandle != nullptr) {
    {
      TypeNameParser typeNameParser = rt::newobj<TypeNameParser>(safeTypeNameParserHandle);
      rt::Using(typeNameParser);
      return typeNameParser->ConstructType(assemblyResolver, typeResolver, throwOnError, ignoreCase, stackMark);
    }
  }
  return result;
}

void TypeNameParser___::ctor(SafeTypeNameParserHandle handle) {
  m_NativeParser = handle;
}

void TypeNameParser___::Dispose() {
  m_NativeParser->Dispose();
}

Type TypeNameParser___::ConstructType(Func<AssemblyName, Assembly> assemblyResolver, Func<Assembly, String, Boolean, Type> typeResolver, Boolean throwOnError, Boolean ignoreCase, StackCrawlMark& stackMark) {
  Assembly assembly = nullptr;
  String assemblyName = GetAssemblyName();
  if (assemblyName->get_Length() > 0) {
    assembly = ResolveAssembly(assemblyName, assemblyResolver, throwOnError, stackMark);
    if (assembly == nullptr) {
      return nullptr;
    }
  }
  Array<String> names = GetNames();
  if (names == nullptr) {
    if (throwOnError) {
      rt::throw_exception<TypeLoadException>(SR::get_Arg_TypeLoadNullStr());
    }
    return nullptr;
  }
  Type type = ResolveType(assembly, names, typeResolver, throwOnError, ignoreCase, stackMark);
  if (type == nullptr) {
    return nullptr;
  }
  Array<SafeTypeNameParserHandle> typeArguments = GetTypeArguments();
  Array<Type> array = nullptr;
  if (typeArguments != nullptr) {
    array = rt::newarr<Array<Type>>(typeArguments->get_Length());
    for (Int32 i = 0; i < typeArguments->get_Length(); i++) {
      {
        TypeNameParser typeNameParser = rt::newobj<TypeNameParser>(typeArguments[i]);
        rt::Using(typeNameParser);
        array[i] = typeNameParser->ConstructType(assemblyResolver, typeResolver, throwOnError, ignoreCase, stackMark);
      }
      if (array[i] == nullptr) {
        return nullptr;
      }
    }
  }
  Array<Int32> modifiers = GetModifiers();
  {
    Int32* value = modifiers;
    IntPtr pModifiers = IntPtr(value);
    return RuntimeTypeHandle::GetTypeHelper(type, array, pModifiers, (modifiers != nullptr) ? modifiers->get_Length() : 0);
  }
}

Assembly TypeNameParser___::ResolveAssembly(String asmName, Func<AssemblyName, Assembly> assemblyResolver, Boolean throwOnError, StackCrawlMark& stackMark) {
  Assembly assembly;
  if (assemblyResolver == nullptr) {
    if (!throwOnError) {
      try {
        return RuntimeAssembly::in::InternalLoad(asmName, stackMark, AssemblyLoadContext::in::get_CurrentContextualReflectionContext());
      } catch (FileNotFoundException) {
        return nullptr;
      }
    }
    assembly = RuntimeAssembly::in::InternalLoad(asmName, stackMark, AssemblyLoadContext::in::get_CurrentContextualReflectionContext());
  } else {
    assembly = assemblyResolver(rt::newobj<AssemblyName>(asmName));
    if (assembly == nullptr && throwOnError) {
      rt::throw_exception<FileNotFoundException>(SR::Format(SR::get_FileNotFound_ResolveAssembly(), asmName));
    }
  }
  return assembly;
}

Type TypeNameParser___::ResolveType(Assembly assembly, Array<String> names, Func<Assembly, String, Boolean, Type> typeResolver, Boolean throwOnError, Boolean ignoreCase, StackCrawlMark& stackMark) {
  String text = EscapeTypeName(names[0]);
  Type type;
  if (typeResolver == nullptr) {
    type = ((!(assembly == nullptr)) ? assembly->GetType(text, throwOnError, ignoreCase) : RuntimeType::in::GetType(text, throwOnError, ignoreCase, stackMark));
  } else {
    type = typeResolver(assembly, text, ignoreCase);
    if (type == nullptr && throwOnError) {
      String message = (assembly == nullptr) ? SR::Format(SR::get_TypeLoad_ResolveType(), text) : SR::Format(SR::get_TypeLoad_ResolveTypeFromAssembly(), text, assembly->get_FullName());
      rt::throw_exception<TypeLoadException>(message);
    }
  }
  if (type != nullptr) {
    BindingFlags bindingFlags = BindingFlags::Public | BindingFlags::NonPublic;
    if (ignoreCase) {
      bindingFlags |= BindingFlags::IgnoreCase;
    }
    for (Int32 i = 1; i < names->get_Length(); i++) {
      type = type->GetNestedType(names[i], bindingFlags);
      if (type == nullptr) {
        if (!throwOnError) {
          break;
        }
        rt::throw_exception<TypeLoadException>(SR::Format(SR::get_TypeLoad_ResolveNestedType(), names[i], names[i - 1]));
      }
    }
  }
  return type;
}

String TypeNameParser___::EscapeTypeName(String name) {
  if (name->IndexOfAny(SPECIAL_CHARS) < 0) {
    return name;
  }
  Char as[64] = {};
  Span<Char> initialBuffer = as;
  ValueStringBuilder valueStringBuilder = ValueStringBuilder(initialBuffer);
  for (Char& c : rt::each(name)) {
    if (Array<>::in::IndexOf(SPECIAL_CHARS, c) >= 0) {
      valueStringBuilder.Append(92);
    }
    valueStringBuilder.Append(c);
  }
  return valueStringBuilder.ToString();
}

SafeTypeNameParserHandle TypeNameParser___::CreateTypeNameParser(String typeName, Boolean throwOnError) {
  SafeTypeNameParserHandle o = nullptr;
  _CreateTypeNameParser(typeName, ObjectHandleOnStack::Create(o), throwOnError);
  return o;
}

Array<String> TypeNameParser___::GetNames() {
  Array<String> o = nullptr;
  _GetNames(m_NativeParser, ObjectHandleOnStack::Create(o));
  return o;
}

Array<SafeTypeNameParserHandle> TypeNameParser___::GetTypeArguments() {
  Array<SafeTypeNameParserHandle> o = nullptr;
  _GetTypeArguments(m_NativeParser, ObjectHandleOnStack::Create(o));
  return o;
}

Array<Int32> TypeNameParser___::GetModifiers() {
  Array<Int32> o = nullptr;
  _GetModifiers(m_NativeParser, ObjectHandleOnStack::Create(o));
  return o;
}

String TypeNameParser___::GetAssemblyName() {
  String s = nullptr;
  _GetAssemblyName(m_NativeParser, StringHandleOnStack(s));
  return s;
}

void TypeNameParser___::cctor() {
  SPECIAL_CHARS = rt::newarr<Array<Char>>(7);
}

} // namespace System::Private::CoreLib::System::TypeNameParserNamespace
