#pragma once

#include "ThreadPoolWorkQueue.h"

#include <System.Private.CoreLib/Internal/PaddingFor32-dep.h>
#include <System.Private.CoreLib/System/Array-dep.h>
#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/Collections/Concurrent/ConcurrentQueue-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/Threading/SpinLock-dep.h>
#include <System.Private.CoreLib/System/Threading/ThreadPoolWorkQueueThreadLocals-dep.h>
