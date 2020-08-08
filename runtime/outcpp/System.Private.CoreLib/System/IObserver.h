#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD(Exception)
namespace IObserverNamespace {
CLASS(IObserver, T) : public Object::in {
  public: void OnNext(T value);
  public: void OnError(Exception error);
  public: void OnCompleted();
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IObserverNamespace
template <class T>
using IObserver = IObserverNamespace::IObserver<T>;
} // namespace System::Private::CoreLib::System
