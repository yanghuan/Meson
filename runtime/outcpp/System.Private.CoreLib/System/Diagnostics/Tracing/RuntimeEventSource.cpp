#include "RuntimeEventSource-dep.h"

#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventCommand.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/IncrementingPollingCounter-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/PollingCounter-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/RuntimeEventSource-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/RuntimeEventSourceHelper-dep.h>
#include <System.Private.CoreLib/System/Environment-dep.h>
#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/GCMemoryInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/Assembly-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/RuntimeHelpers-dep.h>
#include <System.Private.CoreLib/System/Threading/Monitor-dep.h>
#include <System.Private.CoreLib/System/Threading/ThreadPool-dep.h>
#include <System.Private.CoreLib/System/Threading/Timer-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::RuntimeEventSourceNamespace {
using namespace System::Reflection;
using namespace System::Runtime::CompilerServices;
using namespace System::Threading;

void RuntimeEventSource___::__c___::cctor() {
  __9 = rt::newobj<__c>();
}

void RuntimeEventSource___::__c___::ctor() {
}

Double RuntimeEventSource___::__c___::_OnEventCommand_b__27_0() {
  return RuntimeEventSourceHelper::GetCpuUsage();
}

Double RuntimeEventSource___::__c___::_OnEventCommand_b__27_1() {
  return Environment::get_WorkingSet() / 1000000;
}

Double RuntimeEventSource___::__c___::_OnEventCommand_b__27_2() {
  return GC::GetTotalMemory(false) / 1000000;
}

Double RuntimeEventSource___::__c___::_OnEventCommand_b__27_3() {
  return GC::CollectionCount(0);
}

Double RuntimeEventSource___::__c___::_OnEventCommand_b__27_4() {
  return GC::CollectionCount(1);
}

Double RuntimeEventSource___::__c___::_OnEventCommand_b__27_5() {
  return GC::CollectionCount(2);
}

Double RuntimeEventSource___::__c___::_OnEventCommand_b__27_6() {
  return ThreadPool::get_ThreadCount();
}

Double RuntimeEventSource___::__c___::_OnEventCommand_b__27_7() {
  return Monitor::get_LockContentionCount();
}

Double RuntimeEventSource___::__c___::_OnEventCommand_b__27_8() {
  return ThreadPool::get_PendingWorkItemCount();
}

Double RuntimeEventSource___::__c___::_OnEventCommand_b__27_9() {
  return ThreadPool::get_CompletedWorkItemCount();
}

Double RuntimeEventSource___::__c___::_OnEventCommand_b__27_10() {
  return GC::GetTotalAllocatedBytes();
}

Double RuntimeEventSource___::__c___::_OnEventCommand_b__27_11() {
  return Timer::in::get_ActiveCount();
}

Double RuntimeEventSource___::__c___::_OnEventCommand_b__27_12() {
  GCMemoryInfo gCMemoryInfo = GC::GetGCMemoryInfo();
  return (Double)gCMemoryInfo.get_FragmentedBytes() * 100 / (Double)gCMemoryInfo.get_HeapSizeBytes();
}

Double RuntimeEventSource___::__c___::_OnEventCommand_b__27_13() {
  return Exception::in::GetExceptionCount();
}

Double RuntimeEventSource___::__c___::_OnEventCommand_b__27_14() {
  return GC::GetLastGCPercentTimeInGC();
}

Double RuntimeEventSource___::__c___::_OnEventCommand_b__27_15() {
  return GC::GetGenerationSize(0);
}

Double RuntimeEventSource___::__c___::_OnEventCommand_b__27_16() {
  return GC::GetGenerationSize(1);
}

Double RuntimeEventSource___::__c___::_OnEventCommand_b__27_17() {
  return GC::GetGenerationSize(2);
}

Double RuntimeEventSource___::__c___::_OnEventCommand_b__27_18() {
  return GC::GetGenerationSize(3);
}

Double RuntimeEventSource___::__c___::_OnEventCommand_b__27_19() {
  return GC::GetGenerationSize(4);
}

Double RuntimeEventSource___::__c___::_OnEventCommand_b__27_20() {
  return Assembly::in::GetAssemblyCount();
}

Double RuntimeEventSource___::__c___::_OnEventCommand_b__27_21() {
  return RuntimeHelpers::GetILBytesJitted();
}

Double RuntimeEventSource___::__c___::_OnEventCommand_b__27_22() {
  return RuntimeHelpers::GetMethodsJittedCount();
}

void RuntimeEventSource___::Initialize() {
  s_RuntimeEventSource = rt::newobj<RuntimeEventSource>();
}

void RuntimeEventSource___::ctor() {
}

void RuntimeEventSource___::OnEventCommand(EventCommandEventArgs command) {
  if (command->get_Command() == EventCommand::Enable) {
    if (_cpuTimeCounter == nullptr) {
      Func<Double> as = __c::in::__9__27_0;
      _cpuTimeCounter = rt::newobj<PollingCounter>("cpu-usage", (RuntimeEventSource)this, as != nullptr ? as : (__c::in::__9__27_0 = {__c::in::__9, &__c::in::_OnEventCommand_b__27_0}));
    }
    if (_workingSetCounter == nullptr) {
      Func<Double> as = __c::in::__9__27_1;
      _workingSetCounter = rt::newobj<PollingCounter>("working-set", (RuntimeEventSource)this, as != nullptr ? as : (__c::in::__9__27_1 = {__c::in::__9, &__c::in::_OnEventCommand_b__27_1}));
    }
    if (_gcHeapSizeCounter == nullptr) {
      Func<Double> as = __c::in::__9__27_2;
      _gcHeapSizeCounter = rt::newobj<PollingCounter>("gc-heap-size", (RuntimeEventSource)this, as != nullptr ? as : (__c::in::__9__27_2 = {__c::in::__9, &__c::in::_OnEventCommand_b__27_2}));
    }
    if (_gen0GCCounter == nullptr) {
      Func<Double> as = __c::in::__9__27_3;
      _gen0GCCounter = rt::newobj<IncrementingPollingCounter>("gen-0-gc-count", (RuntimeEventSource)this, as != nullptr ? as : (__c::in::__9__27_3 = {__c::in::__9, &__c::in::_OnEventCommand_b__27_3}));
    }
    if (_gen1GCCounter == nullptr) {
      Func<Double> as = __c::in::__9__27_4;
      _gen1GCCounter = rt::newobj<IncrementingPollingCounter>("gen-1-gc-count", (RuntimeEventSource)this, as != nullptr ? as : (__c::in::__9__27_4 = {__c::in::__9, &__c::in::_OnEventCommand_b__27_4}));
    }
    if (_gen2GCCounter == nullptr) {
      Func<Double> as = __c::in::__9__27_5;
      _gen2GCCounter = rt::newobj<IncrementingPollingCounter>("gen-2-gc-count", (RuntimeEventSource)this, as != nullptr ? as : (__c::in::__9__27_5 = {__c::in::__9, &__c::in::_OnEventCommand_b__27_5}));
    }
    if (_threadPoolThreadCounter == nullptr) {
      Func<Double> as = __c::in::__9__27_6;
      _threadPoolThreadCounter = rt::newobj<PollingCounter>("threadpool-thread-count", (RuntimeEventSource)this, as != nullptr ? as : (__c::in::__9__27_6 = {__c::in::__9, &__c::in::_OnEventCommand_b__27_6}));
    }
    if (_monitorContentionCounter == nullptr) {
      Func<Double> as = __c::in::__9__27_7;
      _monitorContentionCounter = rt::newobj<IncrementingPollingCounter>("monitor-lock-contention-count", (RuntimeEventSource)this, as != nullptr ? as : (__c::in::__9__27_7 = {__c::in::__9, &__c::in::_OnEventCommand_b__27_7}));
    }
    if (_threadPoolQueueCounter == nullptr) {
      Func<Double> as = __c::in::__9__27_8;
      _threadPoolQueueCounter = rt::newobj<PollingCounter>("threadpool-queue-length", (RuntimeEventSource)this, as != nullptr ? as : (__c::in::__9__27_8 = {__c::in::__9, &__c::in::_OnEventCommand_b__27_8}));
    }
    if (_completedItemsCounter == nullptr) {
      Func<Double> as = __c::in::__9__27_9;
      _completedItemsCounter = rt::newobj<IncrementingPollingCounter>("threadpool-completed-items-count", (RuntimeEventSource)this, as != nullptr ? as : (__c::in::__9__27_9 = {__c::in::__9, &__c::in::_OnEventCommand_b__27_9}));
    }
    if (_allocRateCounter == nullptr) {
      Func<Double> as = __c::in::__9__27_10;
      _allocRateCounter = rt::newobj<IncrementingPollingCounter>("alloc-rate", (RuntimeEventSource)this, as != nullptr ? as : (__c::in::__9__27_10 = {__c::in::__9, &__c::in::_OnEventCommand_b__27_10}));
    }
    if (_timerCounter == nullptr) {
      Func<Double> as = __c::in::__9__27_11;
      _timerCounter = rt::newobj<PollingCounter>("active-timer-count", (RuntimeEventSource)this, as != nullptr ? as : (__c::in::__9__27_11 = {__c::in::__9, &__c::in::_OnEventCommand_b__27_11}));
    }
    if (_fragmentationCounter == nullptr) {
      Func<Double> as = __c::in::__9__27_12;
      _fragmentationCounter = rt::newobj<PollingCounter>("gc-fragmentation", (RuntimeEventSource)this, as != nullptr ? as : (__c::in::__9__27_12 = {__c::in::__9, &__c::in::_OnEventCommand_b__27_12}));
    }
    if (_exceptionCounter == nullptr) {
      Func<Double> as = __c::in::__9__27_13;
      _exceptionCounter = rt::newobj<IncrementingPollingCounter>("exception-count", (RuntimeEventSource)this, as != nullptr ? as : (__c::in::__9__27_13 = {__c::in::__9, &__c::in::_OnEventCommand_b__27_13}));
    }
    if (_gcTimeCounter == nullptr) {
      Func<Double> as = __c::in::__9__27_14;
      _gcTimeCounter = rt::newobj<PollingCounter>("time-in-gc", (RuntimeEventSource)this, as != nullptr ? as : (__c::in::__9__27_14 = {__c::in::__9, &__c::in::_OnEventCommand_b__27_14}));
    }
    if (_gen0SizeCounter == nullptr) {
      Func<Double> as = __c::in::__9__27_15;
      _gen0SizeCounter = rt::newobj<PollingCounter>("gen-0-size", (RuntimeEventSource)this, as != nullptr ? as : (__c::in::__9__27_15 = {__c::in::__9, &__c::in::_OnEventCommand_b__27_15}));
    }
    if (_gen1SizeCounter == nullptr) {
      Func<Double> as = __c::in::__9__27_16;
      _gen1SizeCounter = rt::newobj<PollingCounter>("gen-1-size", (RuntimeEventSource)this, as != nullptr ? as : (__c::in::__9__27_16 = {__c::in::__9, &__c::in::_OnEventCommand_b__27_16}));
    }
    if (_gen2SizeCounter == nullptr) {
      Func<Double> as = __c::in::__9__27_17;
      _gen2SizeCounter = rt::newobj<PollingCounter>("gen-2-size", (RuntimeEventSource)this, as != nullptr ? as : (__c::in::__9__27_17 = {__c::in::__9, &__c::in::_OnEventCommand_b__27_17}));
    }
    if (_lohSizeCounter == nullptr) {
      Func<Double> as = __c::in::__9__27_18;
      _lohSizeCounter = rt::newobj<PollingCounter>("loh-size", (RuntimeEventSource)this, as != nullptr ? as : (__c::in::__9__27_18 = {__c::in::__9, &__c::in::_OnEventCommand_b__27_18}));
    }
    if (_pohSizeCounter == nullptr) {
      Func<Double> as = __c::in::__9__27_19;
      _pohSizeCounter = rt::newobj<PollingCounter>("poh-size", (RuntimeEventSource)this, as != nullptr ? as : (__c::in::__9__27_19 = {__c::in::__9, &__c::in::_OnEventCommand_b__27_19}));
    }
    if (_assemblyCounter == nullptr) {
      Func<Double> as = __c::in::__9__27_20;
      _assemblyCounter = rt::newobj<PollingCounter>("assembly-count", (RuntimeEventSource)this, as != nullptr ? as : (__c::in::__9__27_20 = {__c::in::__9, &__c::in::_OnEventCommand_b__27_20}));
    }
    if (_ilBytesJittedCounter == nullptr) {
      Func<Double> as = __c::in::__9__27_21;
      _ilBytesJittedCounter = rt::newobj<PollingCounter>("il-bytes-jitted", (RuntimeEventSource)this, as != nullptr ? as : (__c::in::__9__27_21 = {__c::in::__9, &__c::in::_OnEventCommand_b__27_21}));
    }
    if (_methodsJittedCounter == nullptr) {
      Func<Double> as = __c::in::__9__27_22;
      _methodsJittedCounter = rt::newobj<PollingCounter>("methods-jitted-count", (RuntimeEventSource)this, as != nullptr ? as : (__c::in::__9__27_22 = {__c::in::__9, &__c::in::_OnEventCommand_b__27_22}));
    }
  }
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::RuntimeEventSourceNamespace
