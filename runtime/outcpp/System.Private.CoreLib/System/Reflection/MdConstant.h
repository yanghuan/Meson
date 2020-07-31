#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARDS(RuntimeTypeHandle)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARDS(MetadataImport)
namespace MdConstantNamespace {
class MdConstant : public Object::in {
  public: static Object GetValue(MetadataImport scope, Int32 token, RuntimeTypeHandle fieldTypeHandle, Boolean raw);
};
} // namespace MdConstantNamespace
using MdConstant = MdConstantNamespace::MdConstant;
} // namespace System::Private::CoreLib::System::Reflection
