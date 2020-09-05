#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/SystemException.h>

namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Threading {
FORWARD(Mutex)
FORWARD(WaitHandle)
namespace AbandonedMutexExceptionNamespace {
using namespace System::Runtime::Serialization;
CLASS(AbandonedMutexException) : public SystemException::in {
  public: Mutex get_Mutex();
  public: Int32 get_MutexIndex();
  public: void ctor();
  public: void ctor(String message);
  public: void ctor(String message, Exception inner);
  public: void ctor(Int32 location, WaitHandle handle);
  public: void ctor(String message, Int32 location, WaitHandle handle);
  public: void ctor(String message, Exception inner, Int32 location, WaitHandle handle);
  public: void ctor(SerializationInfo info, StreamingContext context);
  private: void SetupException(Int32 location, WaitHandle handle);
  private: Int32 _mutexIndex;
  private: Mutex _mutex;
};
} // namespace AbandonedMutexExceptionNamespace
using AbandonedMutexException = AbandonedMutexExceptionNamespace::AbandonedMutexException;
} // namespace System::Private::CoreLib::System::Threading
