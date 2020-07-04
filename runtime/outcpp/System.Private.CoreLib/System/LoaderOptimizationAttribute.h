#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Byte.h>

namespace System::Private::CoreLib::System {
enum class LoaderOptimization;
namespace LoaderOptimizationAttributeNamespace {
CLASS(LoaderOptimizationAttribute) {
  public: LoaderOptimization get_Value();
  private: Byte _val;
};
} // namespace LoaderOptimizationAttributeNamespace
using LoaderOptimizationAttribute = LoaderOptimizationAttributeNamespace::LoaderOptimizationAttribute;
} // namespace System::Private::CoreLib::System
