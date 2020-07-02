#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Byte)
FORWARDS(Double)
FORWARDS(Int16)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARDS(SByte)
FORWARDS(Single)
FORWARDS(UInt16)
FORWARDS(UInt32)
FORWARDS(UInt64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Numerics {
namespace ConstantHelperNamespace {
CLASS(ConstantHelper) {
  public: static Byte GetByteWithAllBitsSet();
  public: static SByte GetSByteWithAllBitsSet();
  public: static UInt16 GetUInt16WithAllBitsSet();
  public: static Int16 GetInt16WithAllBitsSet();
  public: static UInt32 GetUInt32WithAllBitsSet();
  public: static Int32 GetInt32WithAllBitsSet();
  public: static UInt64 GetUInt64WithAllBitsSet();
  public: static Int64 GetInt64WithAllBitsSet();
  public: static Single GetSingleWithAllBitsSet();
  public: static Double GetDoubleWithAllBitsSet();
};
} // namespace ConstantHelperNamespace
using ConstantHelper = ConstantHelperNamespace::ConstantHelper;
} // namespace System::Private::CoreLib::System::Numerics
