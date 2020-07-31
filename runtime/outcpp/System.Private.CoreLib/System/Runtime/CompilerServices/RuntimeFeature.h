#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace RuntimeFeatureNamespace {
class RuntimeFeature : public Object::in {
  public: static Boolean get_IsDynamicCodeSupported();
  public: static Boolean get_IsDynamicCodeCompiled();
  public: static Boolean IsSupported(String feature);
};
} // namespace RuntimeFeatureNamespace
using RuntimeFeature = RuntimeFeatureNamespace::RuntimeFeature;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
