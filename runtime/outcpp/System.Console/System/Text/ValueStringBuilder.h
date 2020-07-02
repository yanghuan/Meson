#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Char.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Span.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARD_(Array, T1, T2)
} // namespace System::Private::CoreLib::System
namespace System::Console::System::Text {
namespace ValueStringBuilderNamespace {
using namespace ::System::Private::CoreLib::System;
struct ValueStringBuilder {
  public: void set_Length(Int32 value);
  public: Int32 get_Capacity();
  public: void EnsureCapacity(Int32 capacity);
  public: String ToString();
  private: void Grow(Int32 additionalCapacityBeyondPos);
  public: void Dispose();
  private: Array<Char> _arrayToReturnToPool;
  private: Span<Char> _chars;
  private: Int32 _pos;
};
} // namespace ValueStringBuilderNamespace
using ValueStringBuilder = ValueStringBuilderNamespace::ValueStringBuilder;
} // namespace System::Console::System::Text
