#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/ReadOnlySpan.h>

namespace System::Private::CoreLib::System::Text {
FORWARDS(Rune)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System::Buffers {
enum class OperationStatus;
} // namespace System::Private::CoreLib::System::Buffers
namespace System::Private::CoreLib::System {
FORWARD(AsyncCallback)
FORWARDS(Char)
FORWARD(IAsyncResult)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text::Unicode {
enum class GraphemeClusterBreakType;
namespace TextSegmentationUtilityNamespace {
using namespace Buffers;
class TextSegmentationUtility {
  private: CLASS(DecodeFirstRune, T) {
    public: OperationStatus Invoke(ReadOnlySpan<T> input, Rune& rune, Int32& elementsConsumed);
    public: IAsyncResult BeginInvoke(ReadOnlySpan<T> input, Rune& rune, Int32& elementsConsumed, AsyncCallback callback, Object object);
    public: OperationStatus EndInvoke(Rune& rune, Int32& elementsConsumed, IAsyncResult result);
  };
  private: template <class T>
  struct Processor {
    public: Int32 get_CurrentCodeUnitOffset() { return CurrentCodeUnitOffset; }
    private: void set_CurrentCodeUnitOffset(Int32 value) { CurrentCodeUnitOffset = value; }
    public: GraphemeClusterBreakType get_CurrentType() { return CurrentType; }
    private: void set_CurrentType(GraphemeClusterBreakType value) { CurrentType = value; }
    public: void MoveNext();
    private: ReadOnlySpan<T> _buffer;
    private: DecodeFirstRune<T> _decoder;
    private: Int32 _codeUnitLengthOfCurrentScalar;
    private: Int32 CurrentCodeUnitOffset;
    private: GraphemeClusterBreakType CurrentType;
  };
  public: static Int32 GetLengthOfFirstUtf16ExtendedGraphemeCluster(ReadOnlySpan<Char> input);
  private: static DecodeFirstRune<Char> _utf16Decoder;
};
} // namespace TextSegmentationUtilityNamespace
using TextSegmentationUtility = TextSegmentationUtilityNamespace::TextSegmentationUtility;
} // namespace System::Private::CoreLib::System::Text::Unicode
