#pragma once

#include "ConcurrentExclusiveSchedulerPair.h"

#include <System.Private.CoreLib/System/Action-dep.h>
#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/IEnumerable.h>
#include <System.Private.CoreLib/System/Collections/Generic/List-dep.h>
#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/Func-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/Threading/IThreadPoolWorkItem.h>
#include <System.Private.CoreLib/System/Threading/Tasks/IProducerConsumerQueue.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Task-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskCreationOptions.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskScheduler-dep.h>
#include <System.Private.CoreLib/System/Threading/ThreadLocal-dep.h>
#include <System.Private.CoreLib/System/Threading/WaitCallback-dep.h>
