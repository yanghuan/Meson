#pragma once

#include "AsyncValueTaskMethodBuilder.h"

#include <System.Private.CoreLib/System/Action-dep.h>
#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/Int16-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/IAsyncStateMachine.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/IAsyncStateMachineBox.h>
#include <System.Private.CoreLib/System/Threading/ContextCallback-dep.h>
#include <System.Private.CoreLib/System/Threading/ExecutionContext-dep.h>
#include <System.Private.CoreLib/System/Threading/IThreadPoolWorkItem.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Sources/IValueTaskSource.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Sources/ManualResetValueTaskSourceCore-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Sources/ValueTaskSourceOnCompletedFlags.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Sources/ValueTaskSourceStatus.h>
#include <System.Private.CoreLib/System/Threading/Tasks/ValueTask-dep.h>
#include <System.Private.CoreLib/System/ValueType-dep.h>
