#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System::Threading {
FORWARD(Mutex)
FORWARD(WaitHandle)
namespace AbandonedMutexExceptionNamespace {
CLASS(AbandonedMutexException) {
  public: Mutex get_Mutex();
  public: Int32 get_MutexIndex();
  private: void SetupException(Int32 location, WaitHandle handle);
  private: Int32 _mutexIndex;
  private: Mutex _mutex;
};
} // namespace AbandonedMutexExceptionNamespace
using AbandonedMutexException = AbandonedMutexExceptionNamespace::AbandonedMutexException;
} // namespace System::Private::CoreLib::System::Threading
