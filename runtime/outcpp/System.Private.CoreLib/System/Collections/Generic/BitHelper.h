#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Span.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
namespace BitHelperNamespace {
struct BitHelper {
  public: void Ctor(Span<Int32> span, Boolean clear);
  public: void MarkBit(Int32 bitPosition);
  public: Boolean IsMarked(Int32 bitPosition);
  public: static Int32 ToIntArrayLength(Int32 n);
  public: void Ctor();
  private: Span<Int32> _span;
};
} // namespace BitHelperNamespace
using BitHelper = BitHelperNamespace::BitHelper;
} // namespace System::Private::CoreLib::System::Collections::Generic
