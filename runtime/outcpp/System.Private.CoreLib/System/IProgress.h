#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
namespace IProgressNamespace {
CLASS(IProgress, T) : public Object::in {
  public: void Report(T value);
};
} // namespace IProgressNamespace
template <class T>
using IProgress = IProgressNamespace::IProgress<T>;
} // namespace System::Private::CoreLib::System
