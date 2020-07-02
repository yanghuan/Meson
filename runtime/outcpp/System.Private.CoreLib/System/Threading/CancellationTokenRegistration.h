#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int64.h>

namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARDS_(ValueTask, T1, T2)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARDS(CancellationToken)
namespace CancellationTokenRegistrationNamespace {
using namespace ::System::Private::CoreLib::System::Threading::Tasks;
struct CancellationTokenRegistration {
  public: CancellationToken get_Token();
  public: void Dispose();
  public: ValueTask<> DisposeAsync();
  public: Boolean Unregister();
  private: void WaitForCallbackIfNecessary();
  private: ValueTask<> WaitForCallbackIfNecessaryAsync();
  public: Boolean Equals(Object obj);
  public: Boolean Equals(CancellationTokenRegistration other);
  public: Int32 GetHashCode();
  private: Int64 _id;
  private: Object/*CancellationTokenSource.CallbackNode*/ _node;
};
} // namespace CancellationTokenRegistrationNamespace
using CancellationTokenRegistration = CancellationTokenRegistrationNamespace::CancellationTokenRegistration;
} // namespace System::Private::CoreLib::System::Threading