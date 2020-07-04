#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Char)
FORWARDS(Int32)
FORWARDS(ReadOnlySpan, T)
FORWARD(String)
enum class StringComparison;
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARDS(ValueStringBuilder)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System::IO {
namespace PathInternalNamespace {
using namespace ::System::Private::CoreLib::System::Text;
class PathInternal {
  public: static Boolean StartsWithDirectorySeparator(ReadOnlySpan<Char> path);
  public: static Boolean IsRoot(ReadOnlySpan<Char> path);
  public: static Int32 GetCommonPathLength(String first, String second, Boolean ignoreCase);
  public: static Int32 EqualStartingCharacterCount(String first, String second, Boolean ignoreCase);
  public: static Boolean AreRootsEqual(String first, String second, StringComparison comparisonType);
  public: static String RemoveRelativeSegments(String path, Int32 rootLength);
  public: static Boolean RemoveRelativeSegments(ReadOnlySpan<Char> path, Int32 rootLength, ValueStringBuilder& sb);
  public: static String TrimEndingDirectorySeparator(String path);
  public: static Boolean EndsInDirectorySeparator(String path);
  public: static ReadOnlySpan<Char> TrimEndingDirectorySeparator(ReadOnlySpan<Char> path);
  public: static Boolean EndsInDirectorySeparator(ReadOnlySpan<Char> path);
  public: static Boolean IsValidDriveChar(Char value);
  public: static Boolean EndsWithPeriodOrSpace(String path);
  public: static String EnsureExtendedPrefixIfNeeded(String path);
  public: static String EnsureExtendedPrefix(String path);
  public: static Boolean IsDevice(ReadOnlySpan<Char> path);
  public: static Boolean IsDeviceUNC(ReadOnlySpan<Char> path);
  public: static Boolean IsExtended(ReadOnlySpan<Char> path);
  public: static Int32 GetRootLength(ReadOnlySpan<Char> path);
  public: static Boolean IsPartiallyQualified(ReadOnlySpan<Char> path);
  public: static Boolean IsDirectorySeparator(Char c);
  public: static String NormalizeDirectorySeparators(String path);
  public: static Boolean IsEffectivelyEmpty(ReadOnlySpan<Char> path);
};
} // namespace PathInternalNamespace
using PathInternal = PathInternalNamespace::PathInternal;
} // namespace System::Private::CoreLib::System::IO
