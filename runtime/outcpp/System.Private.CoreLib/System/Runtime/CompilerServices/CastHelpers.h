#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/UInt64.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace CastHelpersNamespace {
class CastHelpers {
  private: enum class CastResult {
    CannotCast = 0,
    CanCast = 1,
    MaybeCast = 2,
  };
  private: struct CastCacheEntry {
    public: Int32 _version;
    public: UInt64 _source;
    public: UInt64 _targetAndResult;
  };
  private: static Int32 KeyToBucket(Array<Int32> table, UInt64 source, UInt64 target);
  private: static Int32 TableMask(Array<Int32> table);
  private: static Int32 HashShift(Array<Int32> table);
  private: static CastResult TryGet(UInt64 source, UInt64 target);
  private: static Object IsInstanceOfAny_NoCacheLookup(void* toTypeHnd, Object obj);
  private: static Object ChkCastAny_NoCacheLookup(void* toTypeHnd, Object obj);
  private: static Object IsInstanceOfAny(void* toTypeHnd, Object obj);
  private: static Object IsInstanceOfInterface(void* toTypeHnd, Object obj);
  private: static Object IsInstanceOfClass(void* toTypeHnd, Object obj);
  private: static Object IsInstanceHelper(void* toTypeHnd, Object obj);
  private: static Object ChkCastAny(void* toTypeHnd, Object obj);
  private: static Object ChkCastHelper(void* toTypeHnd, Object obj);
  private: static Object ChkCastInterface(void* toTypeHnd, Object obj);
  private: static Object ChkCastClass(void* toTypeHnd, Object obj);
  private: static Object ChkCastClassSpecial(void* toTypeHnd, Object obj);
  private: static Array<Int32> s_table;
};
} // namespace CastHelpersNamespace
using CastHelpers = CastHelpersNamespace::CastHelpers;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
