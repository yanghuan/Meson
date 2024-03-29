#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
enum class StringComparison : int32_t;
FORWARD_(Array)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
FORWARD(String)
FORWARDS_(ValueTuple)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Buffers {
FORWARD(SpanAction, T, TArg)
} // namespace System::Private::CoreLib::System::Buffers
namespace System::Private::CoreLib::System::Text {
FORWARDS(ValueStringBuilder)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System::IO {
namespace PathNamespace {
using namespace System::Buffers;
using namespace System::Text;
class Path {
  private: CLASS(__c) : public object {
    public: static void cctor();
    public: void ctor();
    public: void _GetRandomFileName_b__16_0(Span<Char> span, IntPtr key);
    public: void _JoinInternal_b__37_0(Span<Char> destination, ValueTuple<IntPtr, Int32, IntPtr, Int32, Boolean> state);
    public: void _JoinInternal_b__38_0(Span<Char> destination, ValueTuple<IntPtr, Int32, IntPtr, Int32, IntPtr, Int32, Boolean, Boolean> state);
    public: void _JoinInternal_b__39_0(Span<Char> destination, ValueTuple<IntPtr, Int32, IntPtr, Int32, IntPtr, Int32, IntPtr, ValueTuple<Int32, Boolean, Boolean, Boolean>> state);
    public: static __c __9;
    public: static SpanAction<Char, IntPtr> __9__16_0;
    public: static SpanAction<Char, ValueTuple<IntPtr, Int32, IntPtr, Int32, Boolean>> __9__37_0;
    public: static SpanAction<Char, ValueTuple<IntPtr, Int32, IntPtr, Int32, IntPtr, Int32, Boolean, Boolean>> __9__38_0;
    public: static SpanAction<Char, ValueTuple<IntPtr, Int32, IntPtr, Int32, IntPtr, Int32, IntPtr, ValueTuple<Int32, Boolean, Boolean, Boolean>>> __9__39_0;
  };
  private: static ReadOnlySpan<Byte> get_Base32Char();
  public: static StringComparison get_StringComparison();
  public: static Boolean get_IsCaseSensitive();
  public: static String ChangeExtension(String path, String extension);
  public: static String GetDirectoryName(String path);
  public: static ReadOnlySpan<Char> GetDirectoryName(ReadOnlySpan<Char> path);
  private: static Int32 GetDirectoryNameOffset(ReadOnlySpan<Char> path);
  public: static String GetExtension(String path);
  public: static ReadOnlySpan<Char> GetExtension(ReadOnlySpan<Char> path);
  public: static String GetFileName(String path);
  public: static ReadOnlySpan<Char> GetFileName(ReadOnlySpan<Char> path);
  public: static String GetFileNameWithoutExtension(String path);
  public: static ReadOnlySpan<Char> GetFileNameWithoutExtension(ReadOnlySpan<Char> path);
  public: static String GetRandomFileName();
  public: static Boolean IsPathFullyQualified(String path);
  public: static Boolean IsPathFullyQualified(ReadOnlySpan<Char> path);
  public: static Boolean HasExtension(String path);
  public: static Boolean HasExtension(ReadOnlySpan<Char> path);
  public: static String Combine(String path1, String path2);
  public: static String Combine(String path1, String path2, String path3);
  public: static String Combine(String path1, String path2, String path3, String path4);
  public: static String Combine(Array<String> paths);
  public: static String Join(ReadOnlySpan<Char> path1, ReadOnlySpan<Char> path2);
  public: static String Join(ReadOnlySpan<Char> path1, ReadOnlySpan<Char> path2, ReadOnlySpan<Char> path3);
  public: static String Join(ReadOnlySpan<Char> path1, ReadOnlySpan<Char> path2, ReadOnlySpan<Char> path3, ReadOnlySpan<Char> path4);
  public: static String Join(String path1, String path2);
  public: static String Join(String path1, String path2, String path3);
  public: static String Join(String path1, String path2, String path3, String path4);
  public: static String Join(Array<String> paths);
  public: static Boolean TryJoin(ReadOnlySpan<Char> path1, ReadOnlySpan<Char> path2, Span<Char> destination, Int32& charsWritten);
  public: static Boolean TryJoin(ReadOnlySpan<Char> path1, ReadOnlySpan<Char> path2, ReadOnlySpan<Char> path3, Span<Char> destination, Int32& charsWritten);
  private: static String CombineInternal(String first, String second);
  private: static String CombineInternal(String first, String second, String third);
  private: static String CombineInternal(String first, String second, String third, String fourth);
  private: static String JoinInternal(ReadOnlySpan<Char> first, ReadOnlySpan<Char> second);
  private: static String JoinInternal(ReadOnlySpan<Char> first, ReadOnlySpan<Char> second, ReadOnlySpan<Char> third);
  private: static String JoinInternal(ReadOnlySpan<Char> first, ReadOnlySpan<Char> second, ReadOnlySpan<Char> third, ReadOnlySpan<Char> fourth);
  private: static void Populate83FileNameFromRandomBytes(Byte* bytes, Int32 byteCount, Span<Char> chars);
  public: static String GetRelativePath(String relativeTo, String path);
  private: static String GetRelativePath(String relativeTo, String path, StringComparison comparisonType);
  public: static String TrimEndingDirectorySeparator(String path);
  public: static ReadOnlySpan<Char> TrimEndingDirectorySeparator(ReadOnlySpan<Char> path);
  public: static Boolean EndsInDirectorySeparator(ReadOnlySpan<Char> path);
  public: static Boolean EndsInDirectorySeparator(String path);
  public: static Array<Char> GetInvalidFileNameChars();
  public: static Array<Char> GetInvalidPathChars();
  public: static String GetFullPath(String path);
  public: static String GetFullPath(String path, String basePath);
  public: static String GetTempPath();
  private: static void GetTempPath(ValueStringBuilder& builder);
  public: static String GetTempFileName();
  public: static Boolean IsPathRooted(String path);
  public: static Boolean IsPathRooted(ReadOnlySpan<Char> path);
  public: static String GetPathRoot(String path);
  public: static ReadOnlySpan<Char> GetPathRoot(ReadOnlySpan<Char> path);
  public: static ReadOnlySpan<Char> GetVolumeName(ReadOnlySpan<Char> path);
  public: static Int32 GetUncRootLength(ReadOnlySpan<Char> path);
  public: static void cctor();
  public: static Char DirectorySeparatorChar;
  public: static Char AltDirectorySeparatorChar;
  public: static Char VolumeSeparatorChar;
  public: static Char PathSeparator;
  public: static Array<Char> InvalidPathChars;
};
} // namespace PathNamespace
using Path = PathNamespace::Path;
} // namespace System::Private::CoreLib::System::IO
