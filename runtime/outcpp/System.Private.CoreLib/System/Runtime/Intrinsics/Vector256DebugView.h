#pragma once

#include <System.Private.CoreLib/System/Runtime/Intrinsics/Vector256.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
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
namespace Vector256DebugViewNamespace {
template <class T>
struct Vector256DebugView : public valueType<Vector256DebugView<T>> {
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
  public: explicit Vector256DebugView(Vector256<T> value);
  public: explicit Vector256DebugView() {}
  private: Vector256<T> _value;
};
} // namespace Vector256DebugViewNamespace
template <class T>
using Vector256DebugView = Vector256DebugViewNamespace::Vector256DebugView<T>;
} // namespace System::Private::CoreLib::System::Runtime::Intrinsics
