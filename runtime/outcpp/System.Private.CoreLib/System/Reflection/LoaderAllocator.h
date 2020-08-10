#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/Reflection/CerHashtable.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(LoaderAllocatorScout)
FORWARD(RuntimeMethodInfo)
namespace LoaderAllocatorNamespace {
CLASS(LoaderAllocator) : public Object::in {
  private: void ctor();
  private: LoaderAllocatorScout m_scout;
  private: Array<Object> m_slots;
  public: CerHashtable<RuntimeMethodInfo, RuntimeMethodInfo> m_methodInstantiations;
  private: Int32 m_slotsUsed;
};
} // namespace LoaderAllocatorNamespace
using LoaderAllocator = LoaderAllocatorNamespace::LoaderAllocator;
} // namespace System::Private::CoreLib::System::Reflection
