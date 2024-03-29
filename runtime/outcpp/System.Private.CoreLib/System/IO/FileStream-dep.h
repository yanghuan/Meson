#pragma once

#include "FileStream.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/Microsoft/Win32/SafeHandles/SafeFileHandle-dep.h>
#include <System.Private.CoreLib/System/Action-dep.h>
#include <System.Private.CoreLib/System/Array-dep.h>
#include <System.Private.CoreLib/System/AsyncCallback-dep.h>
#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/Buffers/MemoryHandle-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/IAsyncResult.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/IO/FileAccess.h>
#include <System.Private.CoreLib/System/IO/FileMode.h>
#include <System.Private.CoreLib/System/IO/FileOptions.h>
#include <System.Private.CoreLib/System/IO/FileShare.h>
#include <System.Private.CoreLib/System/IO/SeekOrigin.h>
#include <System.Private.CoreLib/System/IO/Stream-dep.h>
#include <System.Private.CoreLib/System/Memory-dep.h>
#include <System.Private.CoreLib/System/Nullable-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/ReadOnlyMemory-dep.h>
#include <System.Private.CoreLib/System/ReadOnlySpan-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/AsyncTaskMethodBuilder-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/AsyncValueTaskMethodBuilder-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/ConfiguredTaskAwaitable-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/ConfiguredValueTaskAwaitable-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/IAsyncStateMachine.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/ICriticalNotifyCompletion.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/INotifyCompletion.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/String-dep.h>
#include <System.Private.CoreLib/System/Threading/CancellationToken-dep.h>
#include <System.Private.CoreLib/System/Threading/CancellationTokenRegistration-dep.h>
#include <System.Private.CoreLib/System/Threading/IOCompletionCallback-dep.h>
#include <System.Private.CoreLib/System/Threading/NativeOverlapped-dep.h>
#include <System.Private.CoreLib/System/Threading/PreAllocatedOverlapped-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Task-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskCompletionSource-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/ValueTask-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>
#include <System.Private.CoreLib/System/ValueType-dep.h>
