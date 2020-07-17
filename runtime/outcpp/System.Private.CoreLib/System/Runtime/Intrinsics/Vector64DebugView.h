#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/Vector64.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
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
namespace System::Private::CoreLib::System::Runtime::Intrinsics {
namespace Vector64DebugViewNamespace {
template <class T>
struct Vector64DebugView {
  public: Array<Byte> get_ByteView();
  public: Array<Double> get_DoubleView();
  public: Array<Int16> get_Int16View();
  public: Array<Int32> get_Int32View();
  public: Array<Int64> get_Int64View();
  public: Array<SByte> get_SByteView();
  public: Array<Single> get_SingleView();
  public: Array<UInt16> get_UInt16View();
  public: Array<UInt32> get_UInt32View();
  public: Array<UInt64> get_UInt64View();
  public: void Ctor(Vector64<T> value);
  public: void Ctor();
  private: Vector64<T> _value;
};
} // namespace Vector64DebugViewNamespace
template <class T>
using Vector64DebugView = Vector64DebugViewNamespace::Vector64DebugView<T>;
} // namespace System::Private::CoreLib::System::Runtime::Intrinsics
