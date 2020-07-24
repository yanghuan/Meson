#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(DeserializationTracker)
namespace DeserializationTokenNamespace {
struct DeserializationToken {
  public: explicit DeserializationToken(DeserializationTracker tracker);
  public: void Dispose();
  public: explicit DeserializationToken() {}
  private: DeserializationTracker _tracker;
};
} // namespace DeserializationTokenNamespace
using DeserializationToken = DeserializationTokenNamespace::DeserializationToken;
} // namespace System::Private::CoreLib::System::Runtime::Serialization
