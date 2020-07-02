#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Exception)
namespace IObserverNamespace {
CLASS(IObserver, T) {
  public: void OnNext(T value);
  public: void OnError(Exception error);
  public: void OnCompleted();
};
} // namespace IObserverNamespace
template <class T>
using IObserver = IObserverNamespace::IObserver<T>;
} // namespace System::Private::CoreLib::System
