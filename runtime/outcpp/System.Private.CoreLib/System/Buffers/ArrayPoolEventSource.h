#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Buffers {
namespace ArrayPoolEventSourceNamespace {
CLASS(ArrayPoolEventSource) {
  public: enum class BufferAllocatedReason {
    Pooled = 0,
    OverMaximumSize = 1,
    PoolExhausted = 2,
  };
  private: void Ctor();
  public: void BufferRented(Int32 bufferId, Int32 bufferSize, Int32 poolId, Int32 bucketId);
  public: void BufferAllocated(Int32 bufferId, Int32 bufferSize, Int32 poolId, Int32 bucketId, BufferAllocatedReason reason);
  public: void BufferReturned(Int32 bufferId, Int32 bufferSize, Int32 poolId);
  public: void BufferTrimmed(Int32 bufferId, Int32 bufferSize, Int32 poolId);
  public: void BufferTrimPoll(Int32 milliseconds, Int32 pressure);
  private: static void SCtor();
  public: static ArrayPoolEventSource Log;
};
} // namespace ArrayPoolEventSourceNamespace
using ArrayPoolEventSource = ArrayPoolEventSourceNamespace::ArrayPoolEventSource;
} // namespace System::Private::CoreLib::System::Buffers
