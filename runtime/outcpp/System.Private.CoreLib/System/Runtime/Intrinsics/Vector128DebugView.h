#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/Vector128.h>

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
namespace Vector128DebugViewNamespace {
template <class T>
struct Vector128DebugView {
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
  private: Vector128<T> _value;
};
} // namespace Vector128DebugViewNamespace
template <class T>
using Vector128DebugView = Vector128DebugViewNamespace::Vector128DebugView<T>;
} // namespace System::Private::CoreLib::System::Runtime::Intrinsics
