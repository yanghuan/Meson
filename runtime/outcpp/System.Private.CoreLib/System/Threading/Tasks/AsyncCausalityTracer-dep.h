#pragma once

#include "AsyncCausalityTracer.h"

#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/Guid-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/String-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/AsyncCausalityStatus.h>
#include <System.Private.CoreLib/System/Threading/Tasks/CausalityRelation.h>
#include <System.Private.CoreLib/System/Threading/Tasks/CausalitySynchronousWork.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Task-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>
#include <System.Private.CoreLib/Windows/Foundation/Diagnostics/IAsyncCausalityTracerStatics.h>
#include <System.Private.CoreLib/Windows/Foundation/Diagnostics/TracingStatusChangedEventArgs-dep.h>
