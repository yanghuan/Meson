#include "Activator-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/PlatformNotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Reflection/Assembly-dep.h>
#include <System.Private.CoreLib/System/Reflection/AssemblyContentType.h>
#include <System.Private.CoreLib/System/Reflection/AssemblyName-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/TypeBuilder-dep.h>
#include <System.Private.CoreLib/System/Reflection/RuntimeAssembly-dep.h>
#include <System.Private.CoreLib/System/Runtime/Loader/AssemblyLoadContext-dep.h>
#include <System.Private.CoreLib/System/RuntimeType-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Threading/StackCrawlMark.h>

namespace System::Private::CoreLib::System::ActivatorNamespace {
using namespace System::Reflection;
using namespace System::Reflection::Emit;
using namespace System::Runtime::Loader;
using namespace System::Threading;

Object Activator::CreateInstance(Type type, BindingFlags bindingAttr, Binder binder, Array<Object> args, CultureInfo culture) {
  return CreateInstance(type, bindingAttr, binder, args, culture, nullptr);
}

Object Activator::CreateInstance(Type type, Array<Object> args) {
  return CreateInstance(type, BindingFlags::Instance | BindingFlags::Public | BindingFlags::CreateInstance, nullptr, args, nullptr, nullptr);
}

Object Activator::CreateInstance(Type type, Array<Object> args, Array<Object> activationAttributes) {
  return CreateInstance(type, BindingFlags::Instance | BindingFlags::Public | BindingFlags::CreateInstance, nullptr, args, nullptr, activationAttributes);
}

Object Activator::CreateInstance(Type type) {
  return CreateInstance(type, false);
}

ObjectHandle Activator::CreateInstanceFrom(String assemblyFile, String typeName) {
  return CreateInstanceFrom(assemblyFile, typeName, false, BindingFlags::Instance | BindingFlags::Public | BindingFlags::CreateInstance, nullptr, nullptr, nullptr, nullptr);
}

ObjectHandle Activator::CreateInstanceFrom(String assemblyFile, String typeName, Array<Object> activationAttributes) {
  return CreateInstanceFrom(assemblyFile, typeName, false, BindingFlags::Instance | BindingFlags::Public | BindingFlags::CreateInstance, nullptr, nullptr, nullptr, activationAttributes);
}

ObjectHandle Activator::CreateInstanceFrom(String assemblyFile, String typeName, Boolean ignoreCase, BindingFlags bindingAttr, Binder binder, Array<Object> args, CultureInfo culture, Array<Object> activationAttributes) {
  Assembly assembly = Assembly::in::LoadFrom(assemblyFile);
  Type type = assembly->GetType(typeName, true, ignoreCase);
  Object obj = CreateInstance(type, bindingAttr, binder, args, culture, activationAttributes);
  if (obj == nullptr) {
    return nullptr;
  }
  return rt::newobj<ObjectHandle>(obj);
}

Object Activator::CreateInstance(Type type, BindingFlags bindingAttr, Binder binder, Array<Object> args, CultureInfo culture, Array<Object> activationAttributes) {
  if ((Object)type == nullptr) {
    rt::throw_exception<ArgumentNullException>("type");
  }
  if (rt::is<TypeBuilder>(type)) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_CreateInstanceWithTypeBuilder());
  }
  if ((bindingAttr & (BindingFlags)255) == 0) {
    bindingAttr |= (BindingFlags::Instance | BindingFlags::Public | BindingFlags::CreateInstance);
  }
  if (activationAttributes != nullptr && activationAttributes->get_Length() != 0) {
    rt::throw_exception<PlatformNotSupportedException>(SR::get_NotSupported_ActivAttr());
  }
  RuntimeType runtimeType = rt::as<RuntimeType>(type->get_UnderlyingSystemType());
  if ((Object)runtimeType != nullptr) {
    return runtimeType->CreateInstanceImpl(bindingAttr, binder, args, culture);
  }
  rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeType(), "type");
}

ObjectHandle Activator::CreateInstance(String assemblyName, String typeName) {
  StackCrawlMark stackMark = StackCrawlMark::LookForMyCaller;
  return CreateInstanceInternal(assemblyName, typeName, false, BindingFlags::Instance | BindingFlags::Public | BindingFlags::CreateInstance, nullptr, nullptr, nullptr, nullptr, stackMark);
}

ObjectHandle Activator::CreateInstance(String assemblyName, String typeName, Boolean ignoreCase, BindingFlags bindingAttr, Binder binder, Array<Object> args, CultureInfo culture, Array<Object> activationAttributes) {
  StackCrawlMark stackMark = StackCrawlMark::LookForMyCaller;
  return CreateInstanceInternal(assemblyName, typeName, ignoreCase, bindingAttr, binder, args, culture, activationAttributes, stackMark);
}

ObjectHandle Activator::CreateInstance(String assemblyName, String typeName, Array<Object> activationAttributes) {
  StackCrawlMark stackMark = StackCrawlMark::LookForMyCaller;
  return CreateInstanceInternal(assemblyName, typeName, false, BindingFlags::Instance | BindingFlags::Public | BindingFlags::CreateInstance, nullptr, nullptr, nullptr, activationAttributes, stackMark);
}

Object Activator::CreateInstance(Type type, Boolean nonPublic) {
  return CreateInstance(type, nonPublic, true);
}

Object Activator::CreateInstance(Type type, Boolean nonPublic, Boolean wrapExceptions) {
  if ((Object)type == nullptr) {
    rt::throw_exception<ArgumentNullException>("type");
  }
  RuntimeType runtimeType = rt::as<RuntimeType>(type->get_UnderlyingSystemType());
  if ((Object)runtimeType != nullptr) {
    return runtimeType->CreateInstanceDefaultCtor(!nonPublic, false, true, wrapExceptions);
  }
  rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeType(), "type");
}

ObjectHandle Activator::CreateInstanceInternal(String assemblyString, String typeName, Boolean ignoreCase, BindingFlags bindingAttr, Binder binder, Array<Object> args, CultureInfo culture, Array<Object> activationAttributes, StackCrawlMark& stackMark) {
  Type type = nullptr;
  Assembly assembly = nullptr;
  if (assemblyString == nullptr) {
    assembly = Assembly::in::GetExecutingAssembly(stackMark);
  } else {
    AssemblyName assemblyName = rt::newobj<AssemblyName>(assemblyString);
    if (assemblyName->get_ContentType() == AssemblyContentType::WindowsRuntime) {
      type = Type::in::GetType(typeName + ", " + assemblyString, true, ignoreCase);
    } else {
      assembly = RuntimeAssembly::in::InternalLoad(assemblyName, stackMark, AssemblyLoadContext::in::get_CurrentContextualReflectionContext());
    }
  }
  if (type == nullptr) {
    type = assembly->GetType(typeName, true, ignoreCase);
  }
  Object obj = CreateInstance(type, bindingAttr, binder, args, culture, activationAttributes);
  if (obj == nullptr) {
    return nullptr;
  }
  return rt::newobj<ObjectHandle>(obj);
}

} // namespace System::Private::CoreLib::System::ActivatorNamespace
