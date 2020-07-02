#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARDS(RuntimeTypeHandle)
FORWARDS(Boolean)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARDS(MetadataImport)
namespace MdConstantNamespace {
class MdConstant {
  public: static Object GetValue(MetadataImport scope, Int32 token, RuntimeTypeHandle fieldTypeHandle, Boolean raw);
};
} // namespace MdConstantNamespace
using MdConstant = MdConstantNamespace::MdConstant;
} // namespace System::Private::CoreLib::System::Reflection
