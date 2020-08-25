#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Threading {
namespace IThreadPoolWorkItemNamespace {
CLASS(IThreadPoolWorkItem) : public object {
  public: void Execute();
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IThreadPoolWorkItemNamespace
using IThreadPoolWorkItem = IThreadPoolWorkItemNamespace::IThreadPoolWorkItem;
} // namespace System::Private::CoreLib::System::Threading
