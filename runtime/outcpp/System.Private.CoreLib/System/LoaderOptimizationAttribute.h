#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Byte.h>

namespace System::Private::CoreLib::System {
enum class LoaderOptimization;
namespace LoaderOptimizationAttributeNamespace {
CLASS(LoaderOptimizationAttribute) {
  public: LoaderOptimization get_Value();
  public: void Ctor(Byte value);
  public: void Ctor(LoaderOptimization value);
  private: Byte _val;
};
} // namespace LoaderOptimizationAttributeNamespace
using LoaderOptimizationAttribute = LoaderOptimizationAttributeNamespace::LoaderOptimizationAttribute;
} // namespace System::Private::CoreLib::System
