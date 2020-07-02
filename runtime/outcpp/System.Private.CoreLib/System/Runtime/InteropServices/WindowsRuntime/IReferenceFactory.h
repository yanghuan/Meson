#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARD_(Array, T1, T2)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
namespace IReferenceFactoryNamespace {
class IReferenceFactory {
  public: static Object CreateIReference(Object obj);
  public: static Object CreateIReferenceArray(Array<> obj);
  public: static Type s_pointType;
  public: static Type s_rectType;
  public: static Type s_sizeType;
};
} // namespace IReferenceFactoryNamespace
using IReferenceFactory = IReferenceFactoryNamespace::IReferenceFactory;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
