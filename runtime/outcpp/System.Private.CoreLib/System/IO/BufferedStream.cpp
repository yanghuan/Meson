#include "BufferedStream-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Buffer-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/IO/BufferedStream-dep.h>
#include <System.Private.CoreLib/System/IO/SeekOrigin.h>
#include <System.Private.CoreLib/System/IO/StreamHelpers-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/Memory-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/ObjectDisposedException-dep.h>
#include <System.Private.CoreLib/System/ReadOnlyMemory-dep.h>
#include <System.Private.CoreLib/System/ReadOnlySpan-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/ConfiguredTaskAwaitable-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/ConfiguredValueTaskAwaitable-dep.h>
#include <System.Private.CoreLib/System/Runtime/ExceptionServices/ExceptionDispatchInfo-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Threading/LazyInitializer-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskToApm-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::IO::BufferedStreamNamespace {
using namespace System::Runtime::CompilerServices;
using namespace System::Runtime::ExceptionServices;
using namespace System::Threading;
using namespace System::Threading::Tasks;

void BufferedStream___::__c___::cctor() {
  <>9 = rt::newobj<__c>();
}

void BufferedStream___::__c___::ctor() {
}

SemaphoreSlim BufferedStream___::__c___::_LazyEnsureAsyncActiveSemaphoreInitialized_b__10_0() {
  return rt::newobj<SemaphoreSlim>(1, 1);
}

void BufferedStream___::_DisposeAsync_d__35::MoveNext() {
  Int32 num = <>1__state;
  BufferedStream bufferedStream = <>4__this;
  try {
    Int32 num2 = 1;
    try {
      if (num == 0) {
        goto IL_0036;
      }
      ConfiguredValueTaskAwaitable<>::ConfiguredValueTaskAwaiter awaiter;
      if (num == 1) {
        awaiter = <>u__2;
        <>u__2 = rt::default__;
        num = (<>1__state = -1);
        goto IL_0116;
      }
      if (bufferedStream->_stream != nullptr) {
        <>7__wrap1 = nullptr;
        <>7__wrap2 = 0;
        goto IL_0036;
      }
      goto end_IL_0013;

    IL_0116:
      awaiter.GetResult();
      Object obj = <>7__wrap1;
      if (obj != nullptr) {
        Exception ex = rt::as<Exception>(obj);
        if (ex == nullptr) {
          rt::throw_exception(obj);
        }
        ExceptionDispatchInfo::in::Capture(ex)->Throw();
      }
      <>7__wrap1 = nullptr;
      goto end_IL_0013;

    IL_0036:
      try {
        ConfiguredTaskAwaitable<>::ConfiguredTaskAwaiter awaiter2;
        if (num != 0) {
          awaiter2 = bufferedStream->FlushAsync()->ConfigureAwait(false).GetAwaiter();
          if (!awaiter2.get_IsCompleted()) {
            num = (<>1__state = 0);
            <>u__1 = awaiter2;
            <>t__builder.AwaitUnsafeOnCompleted(awaiter2, *this);
            return;
          }
        } else {
          awaiter2 = <>u__1;
          <>u__1 = rt::default__;
          num = (<>1__state = -1);
        }
        awaiter2.GetResult();
      } catch (Object obj2) {
        obj = (<>7__wrap1 = obj2);
      }
      awaiter = bufferedStream->_stream->DisposeAsync().ConfigureAwait(false).GetAwaiter();
      if (!awaiter.get_IsCompleted()) {
        num = (<>1__state = 1);
        <>u__2 = awaiter;
        <>t__builder.AwaitUnsafeOnCompleted(awaiter, *this);
        return;
      }
      goto IL_0116;

    end_IL_0013:
    } catch (...) {
    } finally: {
      if (num < 0) {
        bufferedStream->_stream = nullptr;
        bufferedStream->_buffer = nullptr;
      }
    }
  } catch (Exception exception) {
    <>1__state = -2;
    <>t__builder.SetException(exception);
    return;
  }
  <>1__state = -2;
  <>t__builder.SetResult();
}

void BufferedStream___::_DisposeAsync_d__35::SetStateMachine(IAsyncStateMachine stateMachine) {
  <>t__builder.SetStateMachine(stateMachine);
}

void BufferedStream___::_FlushAsyncInternal_d__38::MoveNext() {
  Int32 num = <>1__state;
  BufferedStream bufferedStream = <>4__this;
  try {
    ConfiguredTaskAwaitable<>::ConfiguredTaskAwaiter awaiter;
    if (num != 0) {
      if ((UInt32)(num - 1) <= 2u) {
        goto IL_0092;
      }
      <sem>5__2 = bufferedStream->LazyEnsureAsyncActiveSemaphoreInitialized();
      awaiter = <sem>5__2->WaitAsync(cancellationToken)->ConfigureAwait(false).GetAwaiter();
      if (!awaiter.get_IsCompleted()) {
        num = (<>1__state = 0);
        <>u__1 = awaiter;
        <>t__builder.AwaitUnsafeOnCompleted(awaiter, *this);
        return;
      }
    } else {
      awaiter = <>u__1;
      <>u__1 = rt::default__;
      num = (<>1__state = -1);
    }
    awaiter.GetResult();
    goto IL_0092;

  IL_0092:
    try {
      ConfiguredValueTaskAwaitable<>::ConfiguredValueTaskAwaiter awaiter4;
      ConfiguredTaskAwaitable<>::ConfiguredTaskAwaiter awaiter3;
      ConfiguredTaskAwaitable<>::ConfiguredTaskAwaiter awaiter2;
      switch (num.get()) {
        default:
          if (bufferedStream->_writePos > 0) {
            awaiter4 = bufferedStream->FlushWriteAsync(cancellationToken).ConfigureAwait(false).GetAwaiter();
            if (!awaiter4.get_IsCompleted()) {
              num = (<>1__state = 1);
              <>u__2 = awaiter4;
              <>t__builder.AwaitUnsafeOnCompleted(awaiter4, *this);
              return;
            }
            goto IL_011b;
          }
          if (bufferedStream->_readPos < bufferedStream->_readLen) {
            if (bufferedStream->_stream->get_CanSeek()) {
              bufferedStream->FlushRead();
            }
            if (bufferedStream->_stream->get_CanWrite()) {
              awaiter3 = bufferedStream->_stream->FlushAsync(cancellationToken)->ConfigureAwait(false).GetAwaiter();
              if (!awaiter3.get_IsCompleted()) {
                num = (<>1__state = 2);
                <>u__1 = awaiter3;
                <>t__builder.AwaitUnsafeOnCompleted(awaiter3, *this);
                return;
              }
              goto IL_01c3;
            }
          } else if (bufferedStream->_stream->get_CanWrite()) {
            awaiter2 = bufferedStream->_stream->FlushAsync(cancellationToken)->ConfigureAwait(false).GetAwaiter();
            if (!awaiter2.get_IsCompleted()) {
              num = (<>1__state = 3);
              <>u__1 = awaiter2;
              <>t__builder.AwaitUnsafeOnCompleted(awaiter2, *this);
              return;
            }
            break;
          }

          goto end_IL_0093;
        case 1:
          awaiter4 = <>u__2;
          <>u__2 = rt::default__;
          num = (<>1__state = -1);
          goto IL_011b;
        case 2:
          awaiter3 = <>u__1;
          <>u__1 = rt::default__;
          num = (<>1__state = -1);
          goto IL_01c3;
        case 3:
          {
            awaiter2 = <>u__1;
            <>u__1 = rt::default__;
            num = (<>1__state = -1);
            break;
          }
        IL_011b:
          awaiter4.GetResult();
          goto end_IL_0093;

        IL_01c3:
          awaiter3.GetResult();
          goto end_IL_0093;
      }
      awaiter2.GetResult();

    end_IL_0093:
    } catch (...) {
    } finally: {
      if (num < 0) {
        <sem>5__2->Release();
      }
    }
  } catch (Exception exception) {
    <>1__state = -2;
    <sem>5__2 = nullptr;
    <>t__builder.SetException(exception);
    return;
  }
  <>1__state = -2;
  <sem>5__2 = nullptr;
  <>t__builder.SetResult();
}

void BufferedStream___::_FlushAsyncInternal_d__38::SetStateMachine(IAsyncStateMachine stateMachine) {
  <>t__builder.SetStateMachine(stateMachine);
}

void BufferedStream___::_FlushWriteAsync_d__42::MoveNext() {
  Int32 num = <>1__state;
  BufferedStream bufferedStream = <>4__this;
  try {
    ConfiguredTaskAwaitable<>::ConfiguredTaskAwaiter awaiter;
    ConfiguredValueTaskAwaitable<>::ConfiguredValueTaskAwaiter awaiter2;
    if (num != 0) {
      if (num == 1) {
        awaiter = <>u__2;
        <>u__2 = rt::default__;
        num = (<>1__state = -1);
        goto IL_010d;
      }
      awaiter2 = bufferedStream->_stream->WriteAsync(ReadOnlyMemory<Byte>(bufferedStream->_buffer, 0, bufferedStream->_writePos), cancellationToken).ConfigureAwait(false).GetAwaiter();
      if (!awaiter2.get_IsCompleted()) {
        num = (<>1__state = 0);
        <>u__1 = awaiter2;
        <>t__builder.AwaitUnsafeOnCompleted(awaiter2, *this);
        return;
      }
    } else {
      awaiter2 = <>u__1;
      <>u__1 = rt::default__;
      num = (<>1__state = -1);
    }
    awaiter2.GetResult();
    bufferedStream->_writePos = 0;
    awaiter = bufferedStream->_stream->FlushAsync(cancellationToken)->ConfigureAwait(false).GetAwaiter();
    if (!awaiter.get_IsCompleted()) {
      num = (<>1__state = 1);
      <>u__2 = awaiter;
      <>t__builder.AwaitUnsafeOnCompleted(awaiter, *this);
      return;
    }
    goto IL_010d;

  IL_010d:
    awaiter.GetResult();
  } catch (Exception exception) {
    <>1__state = -2;
    <>t__builder.SetException(exception);
    return;
  }
  <>1__state = -2;
  <>t__builder.SetResult();
}

void BufferedStream___::_FlushWriteAsync_d__42::SetStateMachine(IAsyncStateMachine stateMachine) {
  <>t__builder.SetStateMachine(stateMachine);
}

void BufferedStream___::_ReadFromUnderlyingStreamAsync_d__51::MoveNext() {
  Int32 num = <>1__state;
  BufferedStream bufferedStream = <>4__this;
  Int32 result;
  try {
    ConfiguredTaskAwaitable<>::ConfiguredTaskAwaiter awaiter;
    if (num != 0) {
      if ((UInt32)(num - 1) <= 2u) {
        goto IL_007c;
      }
      awaiter = semaphoreLockTask->ConfigureAwait(false).GetAwaiter();
      if (!awaiter.get_IsCompleted()) {
        num = (<>1__state = 0);
        <>u__1 = awaiter;
        <>t__builder.AwaitUnsafeOnCompleted(awaiter, *this);
        return;
      }
    } else {
      awaiter = <>u__1;
      <>u__1 = rt::default__;
      num = (<>1__state = -1);
    }
    awaiter.GetResult();
    goto IL_007c;

  IL_007c:
    try {
      ConfiguredValueTaskAwaitable<>::ConfiguredValueTaskAwaiter awaiter4;
      ConfiguredValueTaskAwaitable<TResult>::ConfiguredValueTaskAwaiter awaiter3;
      ConfiguredValueTaskAwaitable<TResult>::ConfiguredValueTaskAwaiter awaiter2;
      Int32 result2;
      Int32 num2;
      switch (num.get()) {
        default:
          num2 = bufferedStream->ReadFromBuffer(buffer.get_Span());
          if (num2 != buffer.get_Length()) {
            if (num2 > 0) {
              buffer = buffer.Slice(num2);
              bytesAlreadySatisfied += num2;
            }
            bufferedStream->_readPos = (bufferedStream->_readLen = 0);
            if (bufferedStream->_writePos > 0) {
              awaiter4 = bufferedStream->FlushWriteAsync(cancellationToken).ConfigureAwait(false).GetAwaiter();
              if (!awaiter4.get_IsCompleted()) {
                num = (<>1__state = 1);
                <>u__2 = awaiter4;
                <>t__builder.AwaitUnsafeOnCompleted(awaiter4, *this);
                return;
              }
              goto IL_016f;
            }
            goto IL_0176;
          }
          result = bytesAlreadySatisfied + num2;
          goto end_IL_007d;
        case 1:
          awaiter4 = <>u__2;
          <>u__2 = rt::default__;
          num = (<>1__state = -1);
          goto IL_016f;
        case 2:
          awaiter3 = <>u__3;
          <>u__3 = rt::default__;
          num = (<>1__state = -1);
          goto IL_020e;
        case 3:
          {
            awaiter2 = <>u__3;
            <>u__3 = rt::default__;
            num = (<>1__state = -1);
            break;
          }
        IL_020e:
          result2 = awaiter3.GetResult();
          result = <>7__wrap1 + result2;
          goto end_IL_007d;

        IL_0176:
          if (buffer.get_Length() >= bufferedStream->_bufferSize) {
            <>7__wrap1 = bytesAlreadySatisfied;
            awaiter3 = bufferedStream->_stream->ReadAsync(buffer, cancellationToken).ConfigureAwait(false).GetAwaiter();
            if (!awaiter3.get_IsCompleted()) {
              num = (<>1__state = 2);
              <>u__3 = awaiter3;
              <>t__builder.AwaitUnsafeOnCompleted(awaiter3, *this);
              return;
            }
            goto IL_020e;
          }
          bufferedStream->EnsureBufferAllocated();
          awaiter2 = bufferedStream->_stream->ReadAsync(Memory<Byte>(bufferedStream->_buffer, 0, bufferedStream->_bufferSize), cancellationToken).ConfigureAwait(false).GetAwaiter();
          if (!awaiter2.get_IsCompleted()) {
            num = (<>1__state = 3);
            <>u__3 = awaiter2;
            <>t__builder.AwaitUnsafeOnCompleted(awaiter2, *this);
            return;
          }
          break;

        IL_016f:
          awaiter4.GetResult();
          goto IL_0176;
      }
      Int32 num3 = bufferedStream->_readLen = awaiter2.GetResult();
      num2 = bufferedStream->ReadFromBuffer(buffer.get_Span());
      result = bytesAlreadySatisfied + num2;

    end_IL_007d:
    } catch (...) {
    } finally: {
      if (num < 0) {
        SemaphoreSlim semaphoreSlim = bufferedStream->LazyEnsureAsyncActiveSemaphoreInitialized();
        semaphoreSlim->Release();
      }
    }
  } catch (Exception exception) {
    <>1__state = -2;
    <>t__builder.SetException(exception);
    return;
  }
  <>1__state = -2;
  <>t__builder.SetResult(result);
}

void BufferedStream___::_ReadFromUnderlyingStreamAsync_d__51::SetStateMachine(IAsyncStateMachine stateMachine) {
  <>t__builder.SetStateMachine(stateMachine);
}

void BufferedStream___::_WriteToUnderlyingStreamAsync_d__62::MoveNext() {
  Int32 num = <>1__state;
  BufferedStream bufferedStream = <>4__this;
  try {
    ConfiguredTaskAwaitable<>::ConfiguredTaskAwaiter awaiter;
    if (num != 0) {
      if ((UInt32)(num - 1) <= 3u) {
        goto IL_007b;
      }
      awaiter = semaphoreLockTask->ConfigureAwait(false).GetAwaiter();
      if (!awaiter.get_IsCompleted()) {
        num = (<>1__state = 0);
        <>u__1 = awaiter;
        <>t__builder.AwaitUnsafeOnCompleted(awaiter, *this);
        return;
      }
    } else {
      awaiter = <>u__1;
      <>u__1 = rt::default__;
      num = (<>1__state = -1);
    }
    awaiter.GetResult();
    goto IL_007b;

  IL_007b:
    try {
      ConfiguredValueTaskAwaitable<>::ConfiguredValueTaskAwaiter awaiter4;
      ConfiguredValueTaskAwaitable<>::ConfiguredValueTaskAwaiter awaiter3;
      ConfiguredValueTaskAwaitable<>::ConfiguredValueTaskAwaiter awaiter5;
      ConfiguredValueTaskAwaitable<>::ConfiguredValueTaskAwaiter awaiter2;
      Int32 num3;
      switch (num.get()) {
        default:
          {
            if (bufferedStream->_writePos == 0) {
              bufferedStream->ClearReadBufferBeforeWrite();
            }
            Int32 num2 = bufferedStream->_writePos + buffer.get_Length();
            if (num2 + buffer.get_Length() >= bufferedStream->_bufferSize + bufferedStream->_bufferSize) {
              if (bufferedStream->_writePos > 0) {
                if (num2 <= bufferedStream->_bufferSize + bufferedStream->_bufferSize && num2 <= 81920) {
                  bufferedStream->EnsureShadowBufferAllocated();
                  buffer.get_Span().CopyTo(Span<Byte>(bufferedStream->_buffer, bufferedStream->_writePos, buffer.get_Length()));
                  awaiter4 = bufferedStream->_stream->WriteAsync(ReadOnlyMemory<Byte>(bufferedStream->_buffer, 0, num2), cancellationToken).ConfigureAwait(false).GetAwaiter();
                  if (!awaiter4.get_IsCompleted()) {
                    num = (<>1__state = 2);
                    <>u__2 = awaiter4;
                    <>t__builder.AwaitUnsafeOnCompleted(awaiter4, *this);
                    return;
                  }
                  goto IL_0299;
                }
                awaiter3 = bufferedStream->_stream->WriteAsync(ReadOnlyMemory<Byte>(bufferedStream->_buffer, 0, bufferedStream->_writePos), cancellationToken).ConfigureAwait(false).GetAwaiter();
                if (!awaiter3.get_IsCompleted()) {
                  num = (<>1__state = 3);
                  <>u__2 = awaiter3;
                  <>t__builder.AwaitUnsafeOnCompleted(awaiter3, *this);
                  return;
                }
                goto IL_032e;
              }
              goto IL_033c;
            }
            buffer = buffer.Slice(bufferedStream->WriteToBuffer(buffer.get_Span()));
            if (bufferedStream->_writePos >= bufferedStream->_bufferSize) {
              awaiter5 = bufferedStream->_stream->WriteAsync(ReadOnlyMemory<Byte>(bufferedStream->_buffer, 0, bufferedStream->_writePos), cancellationToken).ConfigureAwait(false).GetAwaiter();
              if (!awaiter5.get_IsCompleted()) {
                num = (<>1__state = 1);
                <>u__2 = awaiter5;
                <>t__builder.AwaitUnsafeOnCompleted(awaiter5, *this);
                return;
              }
              goto IL_0193;
            }
            goto end_IL_007c;
          }case 1:
          awaiter5 = <>u__2;
          <>u__2 = rt::default__;
          num = (<>1__state = -1);
          goto IL_0193;
        case 2:
          awaiter4 = <>u__2;
          <>u__2 = rt::default__;
          num = (<>1__state = -1);
          goto IL_0299;
        case 3:
          awaiter3 = <>u__2;
          <>u__2 = rt::default__;
          num = (<>1__state = -1);
          goto IL_032e;
        case 4:
          {
            awaiter2 = <>u__2;
            <>u__2 = rt::default__;
            num = (<>1__state = -1);
            break;
          }
        IL_0193:
          awaiter5.GetResult();
          bufferedStream->_writePos = 0;
          num3 = bufferedStream->WriteToBuffer(buffer.get_Span());
          goto end_IL_007c;

        IL_033c:
          awaiter2 = bufferedStream->_stream->WriteAsync(buffer, cancellationToken).ConfigureAwait(false).GetAwaiter();
          if (!awaiter2.get_IsCompleted()) {
            num = (<>1__state = 4);
            <>u__2 = awaiter2;
            <>t__builder.AwaitUnsafeOnCompleted(awaiter2, *this);
            return;
          }
          break;

        IL_032e:
          awaiter3.GetResult();
          bufferedStream->_writePos = 0;
          goto IL_033c;

        IL_0299:
          awaiter4.GetResult();
          bufferedStream->_writePos = 0;
          goto end_IL_007c;
      }
      awaiter2.GetResult();

    end_IL_007c:
    } catch (...) {
    } finally: {
      if (num < 0) {
        SemaphoreSlim semaphoreSlim = bufferedStream->LazyEnsureAsyncActiveSemaphoreInitialized();
        semaphoreSlim->Release();
      }
    }
  } catch (Exception exception) {
    <>1__state = -2;
    <>t__builder.SetException(exception);
    return;
  }
  <>1__state = -2;
  <>t__builder.SetResult();
}

void BufferedStream___::_WriteToUnderlyingStreamAsync_d__62::SetStateMachine(IAsyncStateMachine stateMachine) {
  <>t__builder.SetStateMachine(stateMachine);
}

void BufferedStream___::_CopyToAsyncCore_d__70::MoveNext() {
  Int32 num = <>1__state;
  BufferedStream bufferedStream = <>4__this;
  try {
    ConfiguredTaskAwaitable<>::ConfiguredTaskAwaiter awaiter;
    if (num != 0) {
      if ((UInt32)(num - 1) <= 2u) {
        goto IL_0086;
      }
      awaiter = bufferedStream->LazyEnsureAsyncActiveSemaphoreInitialized()->WaitAsync(cancellationToken)->ConfigureAwait(false).GetAwaiter();
      if (!awaiter.get_IsCompleted()) {
        num = (<>1__state = 0);
        <>u__1 = awaiter;
        <>t__builder.AwaitUnsafeOnCompleted(awaiter, *this);
        return;
      }
    } else {
      awaiter = <>u__1;
      <>u__1 = rt::default__;
      num = (<>1__state = -1);
    }
    awaiter.GetResult();
    goto IL_0086;

  IL_0086:
    try {
      ConfiguredValueTaskAwaitable<>::ConfiguredValueTaskAwaiter awaiter4;
      ConfiguredValueTaskAwaitable<>::ConfiguredValueTaskAwaiter awaiter3;
      ConfiguredTaskAwaitable<>::ConfiguredTaskAwaiter awaiter2;
      switch (num.get()) {
        default:
          {
            Int32 num2 = bufferedStream->_readLen - bufferedStream->_readPos;
            if (num2 > 0) {
              awaiter4 = destination->WriteAsync(ReadOnlyMemory<Byte>(bufferedStream->_buffer, bufferedStream->_readPos, num2), cancellationToken).ConfigureAwait(false).GetAwaiter();
              if (!awaiter4.get_IsCompleted()) {
                num = (<>1__state = 1);
                <>u__2 = awaiter4;
                <>t__builder.AwaitUnsafeOnCompleted(awaiter4, *this);
                return;
              }
              goto IL_0135;
            }
            if (bufferedStream->_writePos > 0) {
              awaiter3 = bufferedStream->FlushWriteAsync(cancellationToken).ConfigureAwait(false).GetAwaiter();
              if (!awaiter3.get_IsCompleted()) {
                num = (<>1__state = 2);
                <>u__2 = awaiter3;
                <>t__builder.AwaitUnsafeOnCompleted(awaiter3, *this);
                return;
              }
              goto IL_01c4;
            }
            goto IL_01cb;
          }case 1:
          awaiter4 = <>u__2;
          <>u__2 = rt::default__;
          num = (<>1__state = -1);
          goto IL_0135;
        case 2:
          awaiter3 = <>u__2;
          <>u__2 = rt::default__;
          num = (<>1__state = -1);
          goto IL_01c4;
        case 3:
          {
            awaiter2 = <>u__1;
            <>u__1 = rt::default__;
            num = (<>1__state = -1);
            break;
          }
        IL_01c4:
          awaiter3.GetResult();
          goto IL_01cb;

        IL_01cb:
          awaiter2 = bufferedStream->_stream->CopyToAsync(destination, bufferSize, cancellationToken)->ConfigureAwait(false).GetAwaiter();
          if (!awaiter2.get_IsCompleted()) {
            num = (<>1__state = 3);
            <>u__1 = awaiter2;
            <>t__builder.AwaitUnsafeOnCompleted(awaiter2, *this);
            return;
          }
          break;

        IL_0135:
          awaiter4.GetResult();
          bufferedStream->_readPos = (bufferedStream->_readLen = 0);
          goto IL_01cb;
      }
      awaiter2.GetResult();
    } catch (...) {
    } finally: {
      if (num < 0) {
        bufferedStream->_asyncActiveSemaphore->Release();
      }
    }
  } catch (Exception exception) {
    <>1__state = -2;
    <>t__builder.SetException(exception);
    return;
  }
  <>1__state = -2;
  <>t__builder.SetResult();
}

void BufferedStream___::_CopyToAsyncCore_d__70::SetStateMachine(IAsyncStateMachine stateMachine) {
  <>t__builder.SetStateMachine(stateMachine);
}

Stream BufferedStream___::get_UnderlyingStream() {
  return _stream;
}

Int32 BufferedStream___::get_BufferSize() {
  return _bufferSize;
}

Boolean BufferedStream___::get_CanRead() {
  if (_stream != nullptr) {
    return _stream->get_CanRead();
  }
  return false;
}

Boolean BufferedStream___::get_CanWrite() {
  if (_stream != nullptr) {
    return _stream->get_CanWrite();
  }
  return false;
}

Boolean BufferedStream___::get_CanSeek() {
  if (_stream != nullptr) {
    return _stream->get_CanSeek();
  }
  return false;
}

Int64 BufferedStream___::get_Length() {
  EnsureNotClosed();
  if (_writePos > 0) {
    FlushWrite();
  }
  return _stream->get_Length();
}

Int64 BufferedStream___::get_Position() {
  EnsureNotClosed();
  EnsureCanSeek();
  return _stream->get_Position() + (_readPos - _readLen + _writePos);
}

void BufferedStream___::set_Position(Int64 value) {
  if (value < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  EnsureNotClosed();
  EnsureCanSeek();
  if (_writePos > 0) {
    FlushWrite();
  }
  _readPos = 0;
  _readLen = 0;
  _stream->Seek(value, SeekOrigin::Begin);
}

SemaphoreSlim BufferedStream___::LazyEnsureAsyncActiveSemaphoreInitialized() {
  Func<SemaphoreSlim> as = __c::in::__9__10_0;
  return LazyInitializer::EnsureInitialized(_asyncActiveSemaphore, as != nullptr ? as : (__c::in::__9__10_0 = {__c::in::__9, &__c::in::_LazyEnsureAsyncActiveSemaphoreInitialized_b__10_0}));
}

void BufferedStream___::ctor(Stream stream) {
}

void BufferedStream___::ctor(Stream stream, Int32 bufferSize) {
  if (stream == nullptr) {
    rt::throw_exception<ArgumentNullException>("stream");
  }
  if (bufferSize <= 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("bufferSize", SR::Format(SR::get_ArgumentOutOfRange_MustBePositive(), "bufferSize"));
  }
  _stream = stream;
  _bufferSize = bufferSize;
  if (!_stream->get_CanRead() && !_stream->get_CanWrite()) {
    rt::throw_exception<ObjectDisposedException>(nullptr, SR::get_ObjectDisposed_StreamClosed());
  }
}

void BufferedStream___::EnsureNotClosed() {
  if (_stream == nullptr) {
    rt::throw_exception<ObjectDisposedException>(nullptr, SR::get_ObjectDisposed_StreamClosed());
  }
}

void BufferedStream___::EnsureCanSeek() {
  if (!_stream->get_CanSeek()) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_UnseekableStream());
  }
}

void BufferedStream___::EnsureCanRead() {
  if (!_stream->get_CanRead()) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_UnreadableStream());
  }
}

void BufferedStream___::EnsureCanWrite() {
  if (!_stream->get_CanWrite()) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_UnwritableStream());
  }
}

void BufferedStream___::EnsureShadowBufferAllocated() {
  if (_buffer->get_Length() == _bufferSize && _bufferSize < 81920) {
    Array<Byte> array = rt::newarr<Array<Byte>>(Math::Min(_bufferSize + _bufferSize, 81920));
    Buffer::BlockCopy(_buffer, 0, array, 0, _writePos);
    _buffer = array;
  }
}

void BufferedStream___::EnsureBufferAllocated() {
  if (_buffer == nullptr) {
    _buffer = rt::newarr<Array<Byte>>(_bufferSize);
  }
}

void BufferedStream___::Dispose(Boolean disposing) {
  try {
    if (disposing && _stream != nullptr) {
      try {
        Flush();
      } catch (...) {
      } finally: {
        _stream->Dispose();
      }
    }
  } catch (...) {
  } finally: {
    _stream = nullptr;
    _buffer = nullptr;
    Stream::in::Dispose(disposing);
  }
}

ValueTask<> BufferedStream___::DisposeAsync() {
  _DisposeAsync_d__35 stateMachine;
  stateMachine.__t__builder = AsyncValueTaskMethodBuilder<>::Create();
  stateMachine.__4__this = (BufferedStream)this;
  stateMachine.__1__state = -1;
  stateMachine.__t__builder.Start(stateMachine);
  return stateMachine.__t__builder.get_Task();
}

void BufferedStream___::Flush() {
  EnsureNotClosed();
  if (_writePos > 0) {
    FlushWrite();
  } else if (_readPos < _readLen) {
    if (_stream->get_CanSeek()) {
      FlushRead();
    }
    if (_stream->get_CanWrite()) {
      _stream->Flush();
    }
  } else {
    if (_stream->get_CanWrite()) {
      _stream->Flush();
    }
    _writePos = (_readPos = (_readLen = 0));
  }

}

Task<> BufferedStream___::FlushAsync(CancellationToken cancellationToken) {
  if (cancellationToken.get_IsCancellationRequested()) {
    return Task<>::in::FromCanceled<Int32>(cancellationToken);
  }
  EnsureNotClosed();
  return FlushAsyncInternal(cancellationToken);
}

Task<> BufferedStream___::FlushAsyncInternal(CancellationToken cancellationToken) {
  _FlushAsyncInternal_d__38 stateMachine;
  stateMachine.__t__builder = AsyncTaskMethodBuilder<>::Create();
  stateMachine.__4__this = (BufferedStream)this;
  stateMachine.cancellationToken = cancellationToken;
  stateMachine.__1__state = -1;
  stateMachine.__t__builder.Start(stateMachine);
  return stateMachine.__t__builder.get_Task();
}

void BufferedStream___::FlushRead() {
  if (_readPos - _readLen != 0) {
    _stream->Seek(_readPos - _readLen, SeekOrigin::Current);
  }
  _readPos = 0;
  _readLen = 0;
}

void BufferedStream___::ClearReadBufferBeforeWrite() {
  if (_readPos == _readLen) {
    _readPos = (_readLen = 0);
    return;
  }
  if (!_stream->get_CanSeek()) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_CannotWriteToBufferedStreamIfReadBufferCannotBeFlushed());
  }
  FlushRead();
}

void BufferedStream___::FlushWrite() {
  _stream->Write(_buffer, 0, _writePos);
  _writePos = 0;
  _stream->Flush();
}

ValueTask<> BufferedStream___::FlushWriteAsync(CancellationToken cancellationToken) {
  _FlushWriteAsync_d__42 stateMachine;
  stateMachine.__t__builder = AsyncValueTaskMethodBuilder<>::Create();
  stateMachine.__4__this = (BufferedStream)this;
  stateMachine.cancellationToken = cancellationToken;
  stateMachine.__1__state = -1;
  stateMachine.__t__builder.Start(stateMachine);
  return stateMachine.__t__builder.get_Task();
}

Int32 BufferedStream___::ReadFromBuffer(Array<Byte> array, Int32 offset, Int32 count) {
  Int32 num = _readLen - _readPos;
  if (num == 0) {
    return 0;
  }
  if (num > count) {
    num = count;
  }
  Buffer::BlockCopy(_buffer, _readPos, array, offset, num);
  _readPos += num;
  return num;
}

Int32 BufferedStream___::ReadFromBuffer(Span<Byte> destination) {
  Int32 num = Math::Min(_readLen - _readPos, destination.get_Length());
  if (num > 0) {
    ReadOnlySpan<Byte>(_buffer, _readPos, num).CopyTo(destination);
    _readPos += num;
  }
  return num;
}

Int32 BufferedStream___::ReadFromBuffer(Array<Byte> array, Int32 offset, Int32 count, Exception& error) {
  try {
    error = nullptr;
    return ReadFromBuffer(array, offset, count);
  } catch (Exception ex) {
    Exception ex2 = error = ex;
    return 0;
  }
}

Int32 BufferedStream___::Read(Array<Byte> array, Int32 offset, Int32 count) {
  if (array == nullptr) {
    rt::throw_exception<ArgumentNullException>("array", SR::get_ArgumentNull_Buffer());
  }
  if (offset < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("offset", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (array->get_Length() - offset < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  EnsureNotClosed();
  EnsureCanRead();
  Int32 num = ReadFromBuffer(array, offset, count);
  if (num == count) {
    return num;
  }
  Int32 num2 = num;
  if (num > 0) {
    count -= num;
    offset += num;
  }
  _readPos = (_readLen = 0);
  if (_writePos > 0) {
    FlushWrite();
  }
  if (count >= _bufferSize) {
    return _stream->Read(array, offset, count) + num2;
  }
  EnsureBufferAllocated();
  _readLen = _stream->Read(_buffer, 0, _bufferSize);
  num = ReadFromBuffer(array, offset, count);
  return num + num2;
}

Int32 BufferedStream___::Read(Span<Byte> destination) {
  EnsureNotClosed();
  EnsureCanRead();
  Int32 num = ReadFromBuffer(destination);
  if (num == destination.get_Length()) {
    return num;
  }
  if (num > 0) {
    destination = destination.Slice(num);
  }
  _readPos = (_readLen = 0);
  if (_writePos > 0) {
    FlushWrite();
  }
  if (destination.get_Length() >= _bufferSize) {
    return _stream->Read(destination) + num;
  }
  EnsureBufferAllocated();
  _readLen = _stream->Read(_buffer, 0, _bufferSize);
  return ReadFromBuffer(destination) + num;
}

Task<Int32> BufferedStream___::LastSyncCompletedReadTask(Int32 val) {
  Task<Int32> lastSyncCompletedReadTask = _lastSyncCompletedReadTask;
  if (lastSyncCompletedReadTask != nullptr && lastSyncCompletedReadTask->get_Result() == val) {
    return lastSyncCompletedReadTask;
  }
  return _lastSyncCompletedReadTask = Task<>::in::FromResult(val);
}

Task<Int32> BufferedStream___::ReadAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken) {
  if (buffer == nullptr) {
    rt::throw_exception<ArgumentNullException>("buffer", SR::get_ArgumentNull_Buffer());
  }
  if (offset < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("offset", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (buffer->get_Length() - offset < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  if (cancellationToken.get_IsCancellationRequested()) {
    return Task<>::in::FromCanceled<Int32>(cancellationToken);
  }
  EnsureNotClosed();
  EnsureCanRead();
  Int32 num = 0;
  SemaphoreSlim semaphoreSlim = LazyEnsureAsyncActiveSemaphoreInitialized();
  Task<> task = semaphoreSlim->WaitAsync(cancellationToken);
  if (task->get_IsCompletedSuccessfully()) {
    Boolean flag = true;
    try {
      Exception error;
      num = ReadFromBuffer(buffer, offset, count, error);
      flag = (num == count || error != nullptr);
      if (flag) {
        return (error == nullptr) ? LastSyncCompletedReadTask(num) : Task<>::in::FromException<Int32>(error);
      }
    } catch (...) {
    } finally: {
      if (flag) {
        semaphoreSlim->Release();
      }
    }
  }
  return ReadFromUnderlyingStreamAsync(Memory<Byte>(buffer, offset + num, count - num), cancellationToken, num, task).AsTask();
}

template <>
ValueTask<Int32> BufferedStream___::ReadAsync(Memory<Byte> buffer, CancellationToken cancellationToken) {
  if (cancellationToken.get_IsCancellationRequested()) {
    return ValueTask<>::FromCanceled<Int32>(cancellationToken);
  }
  EnsureNotClosed();
  EnsureCanRead();
  Int32 num = 0;
  SemaphoreSlim semaphoreSlim = LazyEnsureAsyncActiveSemaphoreInitialized();
  Task<> task = semaphoreSlim->WaitAsync(cancellationToken);
  if (task->get_IsCompletedSuccessfully()) {
    Boolean flag = true;
    try {
      num = ReadFromBuffer(buffer.get_Span());
      flag = (num == buffer.get_Length());
      if (flag) {
        return ValueTask<Int32>(num);
      }
    } catch (...) {
    } finally: {
      if (flag) {
        semaphoreSlim->Release();
      }
    }
  }
  return ReadFromUnderlyingStreamAsync(buffer.Slice(num), cancellationToken, num, task);
}

ValueTask<Int32> BufferedStream___::ReadFromUnderlyingStreamAsync(Memory<Byte> buffer, CancellationToken cancellationToken, Int32 bytesAlreadySatisfied, Task<> semaphoreLockTask) {
  _ReadFromUnderlyingStreamAsync_d__51 stateMachine;
  stateMachine.__t__builder = AsyncValueTaskMethodBuilder<Int32>::Create();
  stateMachine.__4__this = (BufferedStream)this;
  stateMachine.buffer = buffer;
  stateMachine.cancellationToken = cancellationToken;
  stateMachine.bytesAlreadySatisfied = bytesAlreadySatisfied;
  stateMachine.semaphoreLockTask = semaphoreLockTask;
  stateMachine.__1__state = -1;
  stateMachine.__t__builder.Start(stateMachine);
  return stateMachine.__t__builder.get_Task();
}

IAsyncResult BufferedStream___::BeginRead(Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback, Object state) {
  return TaskToApm::Begin(ReadAsync(buffer, offset, count, CancellationToken::get_None()), callback, state);
}

Int32 BufferedStream___::EndRead(IAsyncResult asyncResult) {
  return TaskToApm::End<Int32>(asyncResult);
}

Int32 BufferedStream___::ReadByte() {
  if (_readPos == _readLen) {
    return ReadByteSlow();
  }
  return _buffer[_readPos++];
}

Int32 BufferedStream___::ReadByteSlow() {
  EnsureNotClosed();
  EnsureCanRead();
  if (_writePos > 0) {
    FlushWrite();
  }
  EnsureBufferAllocated();
  _readLen = _stream->Read(_buffer, 0, _bufferSize);
  _readPos = 0;
  if (_readLen == 0) {
    return -1;
  }
  return _buffer[_readPos++];
}

void BufferedStream___::WriteToBuffer(Array<Byte> array, Int32& offset, Int32& count) {
  Int32 num = Math::Min(_bufferSize - _writePos, count);
  if (num > 0) {
    EnsureBufferAllocated();
    Buffer::BlockCopy(array, offset, _buffer, _writePos, num);
    _writePos += num;
    count -= num;
    offset += num;
  }
}

Int32 BufferedStream___::WriteToBuffer(ReadOnlySpan<Byte> buffer) {
  Int32 num = Math::Min(_bufferSize - _writePos, buffer.get_Length());
  if (num > 0) {
    EnsureBufferAllocated();
    buffer.Slice(0, num).CopyTo(Span<Byte>(_buffer, _writePos, num));
    _writePos += num;
  }
  return num;
}

void BufferedStream___::Write(Array<Byte> array, Int32 offset, Int32 count) {
  if (array == nullptr) {
    rt::throw_exception<ArgumentNullException>("array", SR::get_ArgumentNull_Buffer());
  }
  if (offset < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("offset", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (array->get_Length() - offset < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  EnsureNotClosed();
  EnsureCanWrite();
  if (_writePos == 0) {
    ClearReadBufferBeforeWrite();
  }
  Int32 num;
  {
    num = _writePos + count;
    if (num + count < _bufferSize + _bufferSize) {
      WriteToBuffer(array, offset, count);
      if (_writePos >= _bufferSize) {
        _stream->Write(_buffer, 0, _writePos);
        _writePos = 0;
        WriteToBuffer(array, offset, count);
      }
      return;
    }
  }
  if (_writePos > 0) {
    if (num <= _bufferSize + _bufferSize && num <= 81920) {
      EnsureShadowBufferAllocated();
      Buffer::BlockCopy(array, offset, _buffer, _writePos, count);
      _stream->Write(_buffer, 0, num);
      _writePos = 0;
      return;
    }
    _stream->Write(_buffer, 0, _writePos);
    _writePos = 0;
  }
  _stream->Write(array, offset, count);
}

void BufferedStream___::Write(ReadOnlySpan<Byte> buffer) {
  EnsureNotClosed();
  EnsureCanWrite();
  if (_writePos == 0) {
    ClearReadBufferBeforeWrite();
  }
  Int32 num;
  {
    num = _writePos + buffer.get_Length();
    if (num + buffer.get_Length() < _bufferSize + _bufferSize) {
      Int32 start = WriteToBuffer(buffer);
      if (_writePos >= _bufferSize) {
        buffer = buffer.Slice(start);
        _stream->Write(_buffer, 0, _writePos);
        _writePos = 0;
        start = WriteToBuffer(buffer);
      }
      return;
    }
  }
  if (_writePos > 0) {
    if (num <= _bufferSize + _bufferSize && num <= 81920) {
      EnsureShadowBufferAllocated();
      buffer.CopyTo(Span<Byte>(_buffer, _writePos, buffer.get_Length()));
      _stream->Write(_buffer, 0, num);
      _writePos = 0;
      return;
    }
    _stream->Write(_buffer, 0, _writePos);
    _writePos = 0;
  }
  _stream->Write(buffer);
}

Task<> BufferedStream___::WriteAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken) {
  if (buffer == nullptr) {
    rt::throw_exception<ArgumentNullException>("buffer", SR::get_ArgumentNull_Buffer());
  }
  if (offset < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("offset", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (buffer->get_Length() - offset < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  return WriteAsync(ReadOnlyMemory<Byte>(buffer, offset, count), cancellationToken).AsTask();
}

template <>
ValueTask<> BufferedStream___::WriteAsync(ReadOnlyMemory<Byte> buffer, CancellationToken cancellationToken) {
  if (cancellationToken.get_IsCancellationRequested()) {
    return ValueTask<>::FromCanceled(cancellationToken);
  }
  EnsureNotClosed();
  EnsureCanWrite();
  SemaphoreSlim semaphoreSlim = LazyEnsureAsyncActiveSemaphoreInitialized();
  Task<> task = semaphoreSlim->WaitAsync(cancellationToken);
  if (task->get_IsCompletedSuccessfully()) {
    Boolean flag = true;
    try {
      if (_writePos == 0) {
        ClearReadBufferBeforeWrite();
      }
      flag = (buffer.get_Length() < _bufferSize - _writePos);
      if (flag) {
        Int32 num = WriteToBuffer(buffer.get_Span());
        return rt::default__;
      }
    } catch (...) {
    } finally: {
      if (flag) {
        semaphoreSlim->Release();
      }
    }
  }
  return WriteToUnderlyingStreamAsync(buffer, cancellationToken, task);
}

ValueTask<> BufferedStream___::WriteToUnderlyingStreamAsync(ReadOnlyMemory<Byte> buffer, CancellationToken cancellationToken, Task<> semaphoreLockTask) {
  _WriteToUnderlyingStreamAsync_d__62 stateMachine;
  stateMachine.__t__builder = AsyncValueTaskMethodBuilder<>::Create();
  stateMachine.__4__this = (BufferedStream)this;
  stateMachine.buffer = buffer;
  stateMachine.cancellationToken = cancellationToken;
  stateMachine.semaphoreLockTask = semaphoreLockTask;
  stateMachine.__1__state = -1;
  stateMachine.__t__builder.Start(stateMachine);
  return stateMachine.__t__builder.get_Task();
}

IAsyncResult BufferedStream___::BeginWrite(Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback, Object state) {
  return TaskToApm::Begin(WriteAsync(buffer, offset, count, CancellationToken::get_None()), callback, state);
}

void BufferedStream___::EndWrite(IAsyncResult asyncResult) {
  TaskToApm::End(asyncResult);
}

void BufferedStream___::WriteByte(Byte value) {
  EnsureNotClosed();
  if (_writePos == 0) {
    EnsureCanWrite();
    ClearReadBufferBeforeWrite();
    EnsureBufferAllocated();
  }
  if (_writePos >= _bufferSize - 1) {
    FlushWrite();
  }
  _buffer[_writePos++] = value;
}

Int64 BufferedStream___::Seek(Int64 offset, SeekOrigin origin) {
  EnsureNotClosed();
  EnsureCanSeek();
  if (_writePos > 0) {
    FlushWrite();
    return _stream->Seek(offset, origin);
  }
  if (_readLen - _readPos > 0 && origin == SeekOrigin::Current) {
    offset -= _readLen - _readPos;
  }
  Int64 position = get_Position();
  Int64 num = _stream->Seek(offset, origin);
  _readPos = (Int32)(num - (position - _readPos));
  if (0 <= _readPos && _readPos < _readLen) {
    _stream->Seek(_readLen - _readPos, SeekOrigin::Current);
  } else {
    _readPos = (_readLen = 0);
  }
  return num;
}

void BufferedStream___::SetLength(Int64 value) {
  if (value < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  EnsureNotClosed();
  EnsureCanSeek();
  EnsureCanWrite();
  Flush();
  _stream->SetLength(value);
}

void BufferedStream___::CopyTo(Stream destination, Int32 bufferSize) {
  StreamHelpers::ValidateCopyToArgs((BufferedStream)this, destination, bufferSize);
  Int32 num = _readLen - _readPos;
  if (num > 0) {
    destination->Write(_buffer, _readPos, num);
    _readPos = (_readLen = 0);
  } else if (_writePos > 0) {
    FlushWrite();
  }

  _stream->CopyTo(destination, bufferSize);
}

Task<> BufferedStream___::CopyToAsync(Stream destination, Int32 bufferSize, CancellationToken cancellationToken) {
  StreamHelpers::ValidateCopyToArgs((BufferedStream)this, destination, bufferSize);
  if (!cancellationToken.get_IsCancellationRequested()) {
    return CopyToAsyncCore(destination, bufferSize, cancellationToken);
  }
  return Task<>::in::FromCanceled<Int32>(cancellationToken);
}

Task<> BufferedStream___::CopyToAsyncCore(Stream destination, Int32 bufferSize, CancellationToken cancellationToken) {
  _CopyToAsyncCore_d__70 stateMachine;
  stateMachine.__t__builder = AsyncTaskMethodBuilder<>::Create();
  stateMachine.__4__this = (BufferedStream)this;
  stateMachine.destination = destination;
  stateMachine.bufferSize = bufferSize;
  stateMachine.cancellationToken = cancellationToken;
  stateMachine.__1__state = -1;
  stateMachine.__t__builder.Start(stateMachine);
  return stateMachine.__t__builder.get_Task();
}

} // namespace System::Private::CoreLib::System::IO::BufferedStreamNamespace
