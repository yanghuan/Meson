#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/UIntPtr.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace CastHelpersNamespace {
class CastHelpers {
  private: enum class CastResult : int32_t {
    CannotCast = 0,
    CanCast = 1,
    MaybeCast = 2,
  };
  private: struct CastCacheEntry : public valueType<CastCacheEntry> {
    public: Int32 _version;
    public: UIntPtr _source;
    public: UIntPtr _targetAndResult;
  };
  public: struct ArrayElement : public valueType<ArrayElement> {
    public: Object Value;
  };
  private: static Int32 KeyToBucket(Int32& tableData, UIntPtr source, UIntPtr target);
  private: static Int32& TableData(Array<Int32> table);
  private: static CastCacheEntry& Element(Int32& tableData, Int32 index);
  private: static Int32 HashShift(Int32& tableData);
  private: static Int32 TableMask(Int32& tableData);
  private: static CastResult TryGet(UIntPtr source, UIntPtr target);
  private: static Object IsInstanceOfAny_NoCacheLookup(void* toTypeHnd, Object obj);
  private: static Object ChkCastAny_NoCacheLookup(void* toTypeHnd, Object obj);
  private: static Byte& Unbox_Helper(void* toTypeHnd, Object obj);
  private: static void WriteBarrier(Object& dst, Object obj);
  private: static Object IsInstanceOfAny(void* toTypeHnd, Object obj);
  private: static Object IsInstanceOfInterface(void* toTypeHnd, Object obj);
  private: static Object IsInstanceOfClass(void* toTypeHnd, Object obj);
  private: static Object IsInstance_Helper(void* toTypeHnd, Object obj);
  private: static Object ChkCastAny(void* toTypeHnd, Object obj);
  private: static Object ChkCast_Helper(void* toTypeHnd, Object obj);
  private: static Object ChkCastInterface(void* toTypeHnd, Object obj);
  private: static Object ChkCastClass(void* toTypeHnd, Object obj);
  private: static Object ChkCastClassSpecial(void* toTypeHnd, Object obj);
  private: static Byte& Unbox(void* toTypeHnd, Object obj);
  private: static Object& ThrowArrayMismatchException();
  private: static Object& LdelemaRef(Array<> array, Int32 index, void* type);
  private: static void StelemRef(Array<> array, Int32 index, Object obj);
  private: static void StelemRef_Helper(Object& element, void* elementType, Object obj);
  private: static void StelemRef_Helper_NoCacheLookup(Object& element, void* elementType, Object obj);
  private: static Array<Int32> s_table;
};
} // namespace CastHelpersNamespace
using CastHelpers = CastHelpersNamespace::CastHelpers;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
