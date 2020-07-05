#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/IntPtr.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Object)
FORWARD(RuntimeType)
FORWARDS(RuntimeTypeHandle)
FORWARDS(TypedReference)
namespace ArgIteratorNamespace {
struct ArgIterator {
  public: TypedReference GetNextArg();
  private: void FCallGetNextArg(void* result);
  public: TypedReference GetNextArg(RuntimeTypeHandle rth);
  private: void InternalGetNextArg(void* result, RuntimeType rt_);
  public: void End();
  public: Int32 GetRemainingCount();
  private: void* _GetNextArgType();
  public: RuntimeTypeHandle GetNextArgType();
  public: Int32 GetHashCode();
  public: Boolean Equals(Object o);
  private: IntPtr ArgCookie;
  private: IntPtr sigPtr;
  private: IntPtr sigPtrLen;
  private: IntPtr ArgPtr;
  private: Int32 RemainingArgs;
};
} // namespace ArgIteratorNamespace
using ArgIterator = ArgIteratorNamespace::ArgIterator;
} // namespace System::Private::CoreLib::System
