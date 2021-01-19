#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/MulticastDelegate.h>
#include <System.Private.CoreLib/System/ReadOnlySpan.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARDS(Char)
FORWARDS(IntPtr)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARDS(Rune)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System::Buffers {
enum class OperationStatus : int32_t;
} // namespace System::Private::CoreLib::System::Buffers
namespace System::Private::CoreLib::System::Text::Unicode {
enum class GraphemeClusterBreakType : int32_t;
namespace TextSegmentationUtilityNamespace {
using namespace System::Buffers;
class TextSegmentationUtility {
  private: CLASS(DecodeFirstRune, T) : public MulticastDelegate::in {
    public: void ctor(Object object, IntPtr method);
    public: OperationStatus Invoke(ReadOnlySpan<T> input, Rune& rune, Int32& elementsConsumed);
    public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
  };
  private: template <class T>
  struct Processor : public valueType<Processor<T>> {
    public: Int32 get_CurrentCodeUnitOffset() { return CurrentCodeUnitOffset; }
    private: void set_CurrentCodeUnitOffset(Int32 value) { CurrentCodeUnitOffset = value; }
    public: GraphemeClusterBreakType get_CurrentType() { return CurrentType; }
    private: void set_CurrentType(GraphemeClusterBreakType value) { CurrentType = value; }
    public: explicit Processor(ReadOnlySpan<T> buffer, DecodeFirstRune<T> decoder);
    public: void MoveNext();
    public: explicit Processor() {}
    private: ReadOnlySpan<T> _buffer;
    private: DecodeFirstRune<T> _decoder;
    private: Int32 _codeUnitLengthOfCurrentScalar;
    private: Int32 CurrentCodeUnitOffset;
    private: GraphemeClusterBreakType CurrentType;
  };
  private: template <class T>
  static Int32 GetLengthOfFirstExtendedGraphemeCluster(ReadOnlySpan<T> input, DecodeFirstRune<T> decoder);
  public: static Int32 GetLengthOfFirstUtf16ExtendedGraphemeCluster(ReadOnlySpan<Char> input);
  public: static void cctor();
  private: static DecodeFirstRune<Char> _utf16Decoder;
};
} // namespace TextSegmentationUtilityNamespace
using TextSegmentationUtility = TextSegmentationUtilityNamespace::TextSegmentationUtility;
} // namespace System::Private::CoreLib::System::Text::Unicode
