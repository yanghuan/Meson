#include "TypeNameBuilder-dep.h"

#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/List-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/TypeNameBuilder-dep.h>
#include <System.Private.CoreLib/System/Text/StringBuilder-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::TypeNameBuilderNamespace {
using namespace System::Collections::Generic;
using namespace System::Text;

void TypeNameBuilder___::ctor() {
  _str = rt::newobj<StringBuilder>();
  _stack = rt::newobj<List<Int32>>();
  Object::in::ctor();
}

void TypeNameBuilder___::OpenGenericArguments() {
  _instNesting++;
  _firstInstArg = true;
  if (_useAngleBracketsForGenerics) {
    Append(60);
  } else {
    Append(91);
  }
}

void TypeNameBuilder___::CloseGenericArguments() {
  _instNesting--;
  if (_firstInstArg) {
    _str->Remove(_str->get_Length() - 1, 1);
  } else if (_useAngleBracketsForGenerics) {
    Append(62);
  } else {
    Append(93);
  }

}

void TypeNameBuilder___::OpenGenericArgument() {
  _nestedName = false;
  if (!_firstInstArg) {
    Append(44);
  }
  _firstInstArg = false;
  if (_useAngleBracketsForGenerics) {
    Append(60);
  } else {
    Append(91);
  }
  PushOpenGenericArgument();
}

void TypeNameBuilder___::CloseGenericArgument() {
  if (_hasAssemblySpec) {
    if (_useAngleBracketsForGenerics) {
      Append(62);
    } else {
      Append(93);
    }
  }
  PopOpenGenericArgument();
}

void TypeNameBuilder___::AddName(String name) {
  if (_nestedName) {
    Append(43);
  }
  _nestedName = true;
  EscapeName(name);
}

void TypeNameBuilder___::AddArray(Int32 rank) {
  if (rank == 1) {
    Append("[*]");
    return;
  }
  if (rank > 64) {
    _str->Append(91)->Append(rank)->Append(93);
    return;
  }
  Append(91);
  for (Int32 i = 1; i < rank; i++) {
    Append(44);
  }
  Append(93);
}

void TypeNameBuilder___::AddAssemblySpec(String assemblySpec) {
  if (assemblySpec != nullptr && !assemblySpec->Equals("")) {
    Append(", ");
    if (_instNesting > 0) {
      EscapeEmbeddedAssemblyName(assemblySpec);
    } else {
      EscapeAssemblyName(assemblySpec);
    }
    _hasAssemblySpec = true;
  }
}

String TypeNameBuilder___::ToString() {
  return _str->ToString();
}

Boolean TypeNameBuilder___::ContainsReservedChar(String name) {
  for (Char&& c : rt::each(name)) {
    if (c == 0) {
      break;
    }
    if (IsTypeNameReservedChar(c)) {
      return true;
    }
  }
  return false;
}

Boolean TypeNameBuilder___::IsTypeNameReservedChar(Char ch) {
  switch (ch.get()) {
    case 38:
    case 42:
    case 43:
    case 44:
    case 91:
    case 92:
    case 93:
      return true;
    default:
      return false;
  }
}

void TypeNameBuilder___::EscapeName(String name) {
  if (ContainsReservedChar(name)) {
    for (Char&& c : rt::each(name)) {
      if (c != 0) {
        if (IsTypeNameReservedChar(c)) {
          _str->Append(92);
        }
        _str->Append(c);
        continue;
      }
      break;
    }
  } else {
    Append(name);
  }
}

void TypeNameBuilder___::EscapeAssemblyName(String name) {
  Append(name);
}

void TypeNameBuilder___::EscapeEmbeddedAssemblyName(String name) {
  if (name->Contains(93)) {
    for (Char&& c : rt::each(name)) {
      if (c == 93) {
        Append(92);
      }
      Append(c);
    }
  } else {
    Append(name);
  }
}

void TypeNameBuilder___::PushOpenGenericArgument() {
  _stack->Add(_str->get_Length());
  _stackIdx++;
}

void TypeNameBuilder___::PopOpenGenericArgument() {
  Int32 num = _stack[--_stackIdx];
  _stack->RemoveAt(_stackIdx);
  if (!_hasAssemblySpec) {
    _str->Remove(num - 1, 1);
  }
  _hasAssemblySpec = false;
}

void TypeNameBuilder___::Append(String pStr) {
  for (Char&& c : rt::each(pStr)) {
    if (c != 0) {
      _str->Append(c);
      continue;
    }
    break;
  }
}

void TypeNameBuilder___::Append(Char c) {
  _str->Append(c);
}

String TypeNameBuilder___::ToString(Type type, Format format) {
  if ((format == Format::FullName || format == Format::AssemblyQualifiedName) && !type->get_IsGenericTypeDefinition() && type->get_ContainsGenericParameters()) {
    return nullptr;
  }
  TypeNameBuilder typeNameBuilder = rt::newobj<TypeNameBuilder>();
  typeNameBuilder->AddAssemblyQualifiedName(type, format);
  return typeNameBuilder->ToString();
}

void TypeNameBuilder___::AddElementType(Type type) {
  if (type->get_HasElementType()) {
    AddElementType(type->GetElementType());
    if (type->get_IsPointer()) {
      Append(42);
    } else if (type->get_IsByRef()) {
      Append(38);
    } else if (type->get_IsSZArray()) {
      Append("[]");
    } else if (type->get_IsArray()) {
      AddArray(type->GetArrayRank());
    }



  }
}

void TypeNameBuilder___::AddAssemblyQualifiedName(Type type, Format format) {
  Type type2 = type;
  while (type2->get_HasElementType()) {
    type2 = type2->GetElementType();
  }
  List<Type> list = rt::newobj<List<Type>>();
  Type type3 = type2;
  while (type3 != nullptr) {
    list->Add(type3);
    type3 = (type3->get_IsGenericParameter() ? nullptr : type3->get_DeclaringType());
  }
  for (Int32 num = list->get_Count() - 1; num >= 0; num--) {
    Type type4 = list[num];
    String text = type4->get_Name();
    if (num == list->get_Count() - 1 && type4->get_Namespace() != nullptr && type4->get_Namespace()->get_Length() != 0) {
      text = type4->get_Namespace() + "." + text;
    }
    AddName(text);
  }
  if (type2->get_IsGenericType() && (!type2->get_IsGenericTypeDefinition() || format == Format::ToString)) {
    Array<Type> genericArguments = type2->GetGenericArguments();
    OpenGenericArguments();
    for (Int32 i = 0; i < genericArguments->get_Length(); i++) {
      Format format2 = (format == Format::FullName) ? Format::AssemblyQualifiedName : format;
      OpenGenericArgument();
      AddAssemblyQualifiedName(genericArguments[i], format2);
      CloseGenericArgument();
    }
    CloseGenericArguments();
  }
  AddElementType(type);
  if (format == Format::AssemblyQualifiedName) {
    AddAssemblySpec(type->get_Module()->get_Assembly()->get_FullName());
  }
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::TypeNameBuilderNamespace
